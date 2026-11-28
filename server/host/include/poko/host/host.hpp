// DEMO-01: one runnable server host over the finished server libraries.
//
// server/host wraps the four server modules into a single in-process game
// server, the way the Worker process will (spec 07):
//
//   identity   (IDN-01)     sign-in: verified Firebase uid -> PokoX account
//   matchmaker (BAK-09..14) slot registry, allocator + HMAC tickets,
//                           queue, reconnection gate
//   authority  (BAK-02/05)  one PkbAuthority per session: proposals, policy
//                           enforcement, committed snapshots, spec-05 hash
//   net        (NET-01/03)  UDP datagrams, HMAC frames (the transport loop
//                           itself lives in main.cpp; this header is the
//                           protocol state machine so the unit test can
//                           drive it without a socket)
//
// Wire protocol (demo transport; TLS termination at the VPS is DEMO-02):
//
//   Control plane — plain ASCII datagrams, one verb per datagram:
//     SIGNIN <firebase_uid>
//       -> "OK SIGNIN <user_id>" | "ERR <reason>"
//     JOIN <request_id> [version]
//       -> "OK JOIN <session> <slot> <version> <nonce> <mac_hex> <tick>"
//        | "WAKING <slot>" | "QUEUED <position> <eta>" | "ERR <reason>"
//     LEAVE             -> "OK LEAVE" | "ERR not-joined"
//     RECONNECT <session> <nonce>
//       -> "OK RECONNECT <session> <slot> <version> <nonce> <mac_hex> <resume>"
//        | "ERR reconnect"
//     PING              -> "OK PONG"
//
//   Game plane — NET-03 frames (first byte 0x15), HMAC key = the ticket MAC
//   from the JOIN/RECONNECT reply (16 bytes). Off-path injection needs the
//   MAC; an eavesdropper on the plaintext datagram sees everything, which
//   is exactly what TLS at the VPS covers in the deployed demo. Payload
//   verbs:
//     INPUT <field_id> <value>  -> "ACK <accepted|discarded> <field_id>"
//     STATE                     -> "SNAP ..."
//   Every committed tick the host broadcasts one SNAP frame per client:
//     "SNAP <tick> <hash_hex> <n> <id>=<value> ..." (ascending field id)
//
// All verbs take server-assigned time (the caller's now_tick), so the unit
// test is deterministic. Untrusted input is bounded: verbs/args are length-
// capped and parsed with overflow-checked loops, and every malformed
// datagram answers "ERR" (or silence for unauthenticated frames) — never a
// crash.
#ifndef POKO_HOST_HOST_HPP
#define POKO_HOST_HOST_HPP

#include "poko/authority/pkb_schema.hpp"
#include "poko/identity/sign_in.hpp"
#include "poko/matchmaker/allocator.hpp"
#include "poko/matchmaker/match_queue.hpp"
#include "poko/matchmaker/reconnect.hpp"
#include "poko/matchmaker/slot_registry.hpp"
#include "poko/net/frame.hpp"
#include "poko/net/udp_echo.hpp"

#include <algorithm>
#include <cstdint>
#include <cstdio>
#include <deque>
#include <limits>
#include <map>
#include <string>
#include <string_view>
#include <vector>

namespace poko::host {

// The demo scene .pkB (spec 05 text form), used when no --schema is given.
// Field ids are declaration order starting at 1.
inline constexpr std::string_view kDemoSchemaText =
    "# DEMO-01 demo scene (Dec 22 milestone)\n"
    "game poko-demo\n"
    "seed 7\n"
    "field cube_x int Validated bits=16 signed=true initial=0\n"
    "field cube_y int Validated bits=16 signed=true initial=0\n"
    "field look_yaw int Trusted bits=16 signed=true initial=0\n"
    "field score int ServerOwned bits=32 initial=0\n";

inline constexpr const char* kRealm = "demo"; // one realm for the demo host

struct HostConfig {
  std::uint32_t tick_hz = 30;       // authority ticks per second
  std::uint32_t game_version = 1;   // the one version this host serves
  std::uint32_t platform_slots = 1; // registered at start (cap: 3 per game)
  std::string ticket_secret;        // required; fail closed when empty
  authority::PkbSchema schema;
};

struct Outgoing {
  std::string peer_key; // "host:port", as passed to handle_datagram
  std::vector<std::uint8_t> bytes;
};

class HostServer {
public:
  explicit HostServer(HostConfig config, std::uint64_t first_session_id = 1)
      : cfg_(std::move(config)),
        signer_(cfg_.ticket_secret),
        reconnect_(registry_, signer_),
        allocator_(/*latency_weight=*/1.0, /*load_penalty=*/1.0, /*platform_ccu_now=*/0),
        next_session_id_(first_session_id) {}

  // Register one platform slot (Ready — this host is the slot process).
  // Numeric ids are 1-based; the registry caps platform slots at 3 per game.
  [[nodiscard]] bool add_slot(std::uint32_t numeric_id, std::uint64_t now_tick) {
    matchmaker::SlotRegistry::Slot s;
    s.slot_id = slot_key(numeric_id);
    s.game_id = cfg_.schema.game_id;
    s.source = matchmaker::SlotRegistry::Source::platform;
    s.state = matchmaker::SlotRegistry::State::ready;
    s.region = "local";
    s.last_heartbeat_tick = now_tick;
    const auto r = registry_.register_slot(s, now_tick);
    if (r != matchmaker::SlotRegistry::Register::registered) return false;
    slot_ids_.push_back(numeric_id);
    return true;
  }

  // One datagram from peer_key ("host:port"). Returns the reply datagram,
  // or an empty vector for silence (unauthenticated/rejected frames).
  [[nodiscard]] std::vector<std::uint8_t> handle_datagram(const std::string& peer_key,
                                                          const std::uint8_t* data, std::size_t len,
                                                          std::uint64_t now_tick) {
    if (peer_key.empty() || data == nullptr || len == 0 || len > net::kMaxDatagramBytes) return {};
    const auto now_sec = now_tick / std::max<std::uint32_t>(1, cfg_.tick_hz);
    registry_.expire(now_sec);
    if (static_cast<std::size_t>(data[0]) ==
        (static_cast<std::size_t>(net::kFrameVersion) << 4 | net::kFrameMagic)) {
      return handle_game_frame(peer_key, data, len);
    }
    return handle_text(peer_key, std::string_view(reinterpret_cast<const char*>(data), len), now_sec);
  }

  // Advance every live session one authority tick, heartbeat the slots,
  // promote waking slots and drain the queue. Returns the datagrams to send.
  [[nodiscard]] std::vector<Outgoing> tick(std::uint64_t now_tick) {
    std::vector<Outgoing> out;
    const auto now_sec = now_tick / std::max<std::uint32_t>(1, cfg_.tick_hz);

    // This process is the slot: it heartbeats itself, and a wake it began
    // is instantaneous (promote Waking -> Ready on the next tick).
    for (const auto id : slot_ids_) {
      registry_.heartbeat(slot_key(id), slot_players(id), now_sec);
      const auto* s = registry_.find(slot_key(id));
      if (s && s->state == matchmaker::SlotRegistry::State::waking)
        registry_.wake_ready(slot_key(id), now_sec);
    }

    drain_queue(out, now_sec);

    for (auto& [id, session] : sessions_) {
      if (session.clients.empty()) continue;
      const authority::Snapshot snap = session.game.authority().tick();
      reconnect_.advance(id, now_sec);
      const auto payload = snapshot_payload(snap);
      for (const auto& [peer_key, client_id] : session.clients) {
        (void)client_id;
        auto pit = peers_.find(peer_key);
        if (pit == peers_.end()) continue;
        out.push_back({peer_key, make_frame(pit->second, id, payload)});
      }
    }
    return out;
  }

  // Introspection for the banner, monitoring and the unit test.
  [[nodiscard]] std::size_t session_count() const { return sessions_.size(); }
  [[nodiscard]] std::size_t peer_count() const { return peers_.size(); }
  [[nodiscard]] std::uint32_t slot_players(std::uint32_t numeric_id) const {
    const auto* s = registry_.find(slot_key(numeric_id));
    return s ? s->players : 0;
  }
  [[nodiscard]] std::size_t queue_depth(std::uint64_t now_tick) {
    return queue_.depth(kRealm, now_tick / std::max<std::uint32_t>(1, cfg_.tick_hz));
  }
  [[nodiscard]] const HostConfig& config() const { return cfg_; }

private:
  struct Peer {
    std::string user_id;          // set by SIGNIN
    std::uint32_t session_id = 0; // 0 = not joined
    std::uint32_t slot_id = 0;
    std::uint32_t client_id = 0;
    std::uint32_t version = 0;
    std::uint64_t nonce = 0;      // from the issued ticket
    std::vector<std::uint8_t> frame_key;
    std::deque<std::uint32_t> seen_seqs;
    std::uint32_t out_seq = 1;
    std::string queued_request_id; // present while queued
  };

  // One session per occupied slot. PkbAuthority captures `this` in its hash
  // hook, so it must never be copied or moved: sessions_ is a std::map and
  // sessions are only ever constructed in place.
  struct HostSession {
    HostSession(std::uint32_t id, std::uint32_t slot, std::uint32_t version,
                const authority::PkbSchema& schema)
        : session_id(id), slot_id(slot), version(version),
          game(schema, static_cast<std::uint64_t>(id) * 0x9E3779B97F4A7C15ULL) {}
    std::uint32_t session_id;
    std::uint32_t slot_id;
    std::uint32_t version;
    authority::PkbAuthority game;
    std::map<std::string, std::uint32_t> clients; // peer key -> client id
  };

  // ---- text (control plane) ----------------------------------------------

  [[nodiscard]] std::vector<std::uint8_t> handle_text(const std::string& peer_key, std::string_view text,
                                                      std::uint64_t now_sec) {
    const auto tok = tokenize(text);
    if (tok.empty()) return {};
    const std::string_view verb = tok[0];

    if (verb == "PING") return bytes_of("OK PONG");

    if (verb == "SIGNIN") {
      if (tok.size() < 2 || tok[1].empty()) return bytes_of("ERR missing-uid");
      identity::FirebaseIdentity id;
      id.uid.assign(tok[1]);
      try {
        const auto record = sign_in_.sign_in(id);
        Peer& p = peers_[peer_key]; // signed-in peers get (or keep) a record
        p.user_id = record.user_id;
        return bytes_of("OK SIGNIN " + record.user_id);
      } catch (const std::exception&) {
        return bytes_of("ERR sign-in"); // generic; never echoes the claim
      }
    }

    if (verb == "JOIN") {
      auto pit = peers_.find(peer_key);
      if (pit == peers_.end() || pit->second.user_id.empty()) return bytes_of("ERR sign-in-first");
      Peer& p = pit->second;
      if (tok.size() < 2 || tok[1].empty() || tok[1].size() > 64) return bytes_of("ERR request-id");
      std::uint32_t version = cfg_.game_version;
      if (tok.size() >= 3 && (!parse_u32(tok[2], version) || version == 0)) return bytes_of("ERR version");

      // Idempotent: a JOIN from a peer already in a live session re-serves
      // its ticket, and a queued retry re-serves its position.
      if (p.session_id != 0 && sessions_.count(p.session_id) != 0) return join_reply(p);
      if (!p.queued_request_id.empty()) return queued_reply(p, now_sec);

      return join_new(p, peer_key, std::string(tok[1]), version, now_sec);
    }

    if (verb == "LEAVE") {
      auto pit = peers_.find(peer_key);
      if (pit == peers_.end() || (pit->second.session_id == 0 && pit->second.queued_request_id.empty()))
        return bytes_of("ERR not-joined");
      leave(pit->second, peer_key);
      return bytes_of("OK LEAVE");
    }

    if (verb == "RECONNECT") {
      if (tok.size() < 3) return bytes_of("ERR reconnect");
      std::uint32_t session_id = 0;
      std::uint64_t nonce = 0;
      if (!parse_u32(tok[1], session_id) || !parse_u64(tok[2], nonce)) return bytes_of("ERR reconnect");
      return reconnect(peer_key, session_id, nonce, now_sec);
    }

    return bytes_of("ERR unknown-command");
  }

  // Allocation pipeline (spec 07): rank ready slots, else wake a cold one,
  // else queue. The host owns every slot, so a wake completes on the next
  // tick.
  [[nodiscard]] std::vector<std::uint8_t> join_new(Peer& p, const std::string& peer_key,
                                                   std::string&& request_id, std::uint32_t version,
                                                   std::uint64_t now_sec) {
    allocator_.set_platform_ccu(registry_.platform_ccu(now_sec));
    std::vector<matchmaker::Slot> candidates;
    for (const auto id : slot_ids_) {
      const auto* s = registry_.find(slot_key(id));
      if (!s) continue;
      matchmaker::Slot c;
      c.id = id;
      switch (s->state) {
        case matchmaker::SlotRegistry::State::cold: c.state = matchmaker::Slot::State::cold; break;
        case matchmaker::SlotRegistry::State::waking: c.state = matchmaker::Slot::State::waking; break;
        case matchmaker::SlotRegistry::State::ready: c.state = matchmaker::Slot::State::ready; break;
        case matchmaker::SlotRegistry::State::full: c.state = matchmaker::Slot::State::full; break;
        case matchmaker::SlotRegistry::State::draining: c.state = matchmaker::Slot::State::draining; break;
        case matchmaker::SlotRegistry::State::dead: c.state = matchmaker::Slot::State::dead; break;
      }
      c.source = matchmaker::Slot::Source::platform;
      c.player_count = s->players;
      c.version = cfg_.game_version;
      c.rtt_ms = 0.0; // the demo host has no latency probe; ties break by id
      c.opted_in = true;
      candidates.push_back(c);
    }
    const auto d = allocator_.allocate(candidates, version, /*affinity_slot_ids=*/{});

    if (d.outcome == matchmaker::Matchmaker::Decision::Outcome::allocated_platform) {
      const auto a = registry_.admit(slot_key(d.slot_id), now_sec);
      if (a != matchmaker::SlotRegistry::Admit::admitted) return bytes_of("ERR busy");
      attach(p, peer_key, d.slot_id, version, now_sec);
      return join_reply(p);
    }
    if (d.outcome == matchmaker::Matchmaker::Decision::Outcome::waking) {
      registry_.begin_wake(slot_key(d.slot_id), now_sec);
      return bytes_of("WAKING " + std::to_string(d.slot_id));
    }

    // Queued (no capacity, or version mismatch — the host serves one
    // version, so a mismatched request waits and expires per BAK-10).
    matchmaker::MatchQueue::Entry e;
    e.request_id = request_id;
    e.party_size = 1;
    e.enqueue_tick = now_sec;
    const auto q = queue_.enqueue(kRealm, e);
    if (q == matchmaker::MatchQueue::Enqueue::full) return bytes_of("ERR queue-full");
    p.queued_request_id = std::move(request_id);
    p.version = version;
    return queued_reply(p, now_sec);
  }

  [[nodiscard]] std::vector<std::uint8_t> join_reply(const Peer& p) {
    std::uint64_t tick = 0;
    const auto it = sessions_.find(p.session_id);
    if (it != sessions_.end()) tick = it->second.game.authority().tick_number();
    return bytes_of("OK JOIN " + std::to_string(p.session_id) + " " + std::to_string(p.slot_id) + " " +
                    std::to_string(p.version) + " " + std::to_string(p.nonce) + " " + to_hex(p.frame_key) + " " +
                    std::to_string(tick));
  }

  [[nodiscard]] std::vector<std::uint8_t> queued_reply(const Peer& p, std::uint64_t now_sec) {
    const auto pos = queue_.position(kRealm, p.queued_request_id, now_sec);
    const auto eta = matchmaker::MatchQueue::eta_ticks(pos, 1, /*drain_per_tick=*/1.0);
    return bytes_of("QUEUED " + std::to_string(pos) + " " + std::to_string(eta));
  }

  // ---- game plane ---------------------------------------------------------

  [[nodiscard]] std::vector<std::uint8_t> handle_game_frame(const std::string& peer_key,
                                                            const std::uint8_t* data, std::size_t len) {
    auto pit = peers_.find(peer_key);
    if (pit == peers_.end() || pit->second.frame_key.empty()) return {}; // unauthenticated
    Peer& p = pit->second;
    if (p.session_id == 0) return {};
    const auto parsed =
        net::unpack_frame(std::vector<std::uint8_t>(data, data + len), p.frame_key, p.seen_seqs);
    if (!parsed.ok) return {}; // bad MAC, replay, or malformed: silence
    if (parsed.header.session_id != p.session_id) return {};
    const std::string_view cmd(reinterpret_cast<const char*>(parsed.payload.data()), parsed.payload.size());
    const auto tok = tokenize(cmd);
    if (tok.empty()) return {};

    if (tok[0] == "INPUT") {
      std::uint32_t field_id = 0;
      std::int64_t value = 0;
      if (tok.size() < 3 || !parse_u32(tok[1], field_id) || !parse_i64(tok[2], value))
        return frame_reply(p, "ERR input");
      const auto result = propose(p, field_id, value);
      if (result.code == authority::ProposalResult::Code::unknown_field ||
          result.code == authority::ProposalResult::Code::unknown_client)
        return frame_reply(p, "ACK unknown " + std::to_string(field_id));
      return frame_reply(p, std::string("ACK ") +
                                (result.code == authority::ProposalResult::Code::accepted ? "accepted "
                                                                                          : "discarded ") +
                                std::to_string(field_id));
    }
    if (tok[0] == "STATE") {
      auto sit = sessions_.find(p.session_id);
      if (sit == sessions_.end()) return {};
      return frame_reply(p, snapshot_payload(sit->second.game.authority().snapshot_for(p.client_id)));
    }
    return frame_reply(p, "ERR unknown-command");
  }

  [[nodiscard]] authority::ProposalResult propose(const Peer& p, std::uint32_t field_id, std::int64_t value) {
    auto sit = sessions_.find(p.session_id);
    if (sit == sessions_.end())
      return {authority::ProposalResult::Code::unknown_client, authority::Policy::server_owned};
    return sit->second.game.propose(p.client_id, field_id, value);
  }

  [[nodiscard]] std::vector<std::uint8_t> frame_reply(Peer& p, const std::string& text) {
    return make_frame(p, p.session_id, bytes_of(text));
  }

  [[nodiscard]] std::vector<std::uint8_t> frame_reply(Peer& p, std::vector<std::uint8_t> payload) {
    return make_frame(p, p.session_id, payload);
  }

  [[nodiscard]] std::vector<std::uint8_t> make_frame(Peer& p, std::uint32_t session_id,
                                                     const std::vector<std::uint8_t>& payload) {
    net::FrameHeader h;
    h.session_id = session_id;
    h.seq = p.out_seq++;
    if (!p.seen_seqs.empty()) h.ack = *std::max_element(p.seen_seqs.begin(), p.seen_seqs.end());
    h.ack_bits = ack_bits_of(p.seen_seqs, h.ack);
    h.priority = 1; // snapshots are priority traffic
    return net::pack_frame(h, payload, p.frame_key);
  }

  [[nodiscard]] static std::uint32_t ack_bits_of(const std::deque<std::uint32_t>& seen, std::uint32_t ack) {
    std::uint32_t bits = 0;
    for (std::uint32_t i = 0; i < 32; ++i) {
      const std::uint32_t s = ack - 1 - i; // wraps naturally; 0 is never a seq
      if (s != 0 && std::find(seen.begin(), seen.end(), s) != seen.end()) bits |= (1u << i);
    }
    return bits;
  }

  [[nodiscard]] static std::vector<std::uint8_t> snapshot_payload(const authority::Snapshot& snap) {
    std::string text = "SNAP " + std::to_string(snap.tick) + " " + to_hex_u64(snap.projected_hash) + " " +
                       std::to_string(snap.fields.size());
    char buf[48];
    for (const auto& f : snap.fields) {
      std::snprintf(buf, sizeof buf, " %u=%lld", static_cast<unsigned>(f.id), static_cast<long long>(f.value));
      text += buf;
    }
    return bytes_of(text);
  }

  // ---- session / registry plumbing ---------------------------------------

  // Join peer_key to (a new session on) slot_num and issue its ticket.
  void attach(Peer& p, const std::string& peer_key, std::uint32_t slot_num, std::uint32_t version,
              std::uint64_t now_sec) {
    HostSession* session = nullptr;
    for (auto& [id, s] : sessions_)
      if (s.slot_id == slot_num && s.version == version) { session = &s; break; }
    if (!session) {
      const auto id = static_cast<std::uint32_t>(next_session_id_++);
      session = &sessions_.try_emplace(id, id, slot_num, version, cfg_.schema).first->second;
      matchmaker::ReconnectFlow::Session rs;
      rs.session_id = id;
      rs.slot_id = slot_num;
      rs.game_id = cfg_.schema.game_id;
      rs.version = version;
      rs.last_accepted_tick = now_sec;
      rs.active = true;
      reconnect_.register_session(rs);
    }
    auto cit = session->clients.find(peer_key);
    if (cit == session->clients.end())
      cit = session->clients.emplace(peer_key, session->game.authority().add_client()).first;
    p.client_id = cit->second;
    p.session_id = session->session_id;
    p.slot_id = slot_num;
    p.version = version;
    p.queued_request_id.clear();
    p.seen_seqs.clear();
    p.out_seq = 1;
    const auto ticket = signer_.issue(session->session_id, slot_num, version, now_sec);
    p.nonce = ticket.nonce;
    // The ticket MAC is per session (same second, same slot -> same MAC),
    // so each client's frame key mixes in its own client id: two clients
    // can never share a key, and a reconnecting client gets a fresh one.
    p.frame_key = derive_frame_key(ticket.mac, session->session_id, p.client_id, ticket.nonce);
  }

  [[nodiscard]] static std::vector<std::uint8_t> derive_frame_key(const std::array<std::uint8_t, 16>& mac,
                                                                  std::uint32_t session_id,
                                                                  std::uint32_t client_id,
                                                                  std::uint64_t nonce) {
    std::array<std::uint8_t, 16> material{};
    for (int i = 0; i < 4; ++i) material[static_cast<std::size_t>(i)] = static_cast<std::uint8_t>(session_id >> (8 * i));
    for (int i = 0; i < 4; ++i) material[4 + static_cast<std::size_t>(i)] = static_cast<std::uint8_t>(client_id >> (8 * i));
    for (int i = 0; i < 8; ++i) material[8 + static_cast<std::size_t>(i)] = static_cast<std::uint8_t>(nonce >> (8 * i));
    const std::vector<std::uint8_t> key_material(material.begin(), material.end());
    auto key = net::hmac_sha256(std::vector<std::uint8_t>(mac.begin(), mac.end()), key_material.data(),
                                key_material.size());
    key.resize(16);
    return key;
  }

  void leave(Peer& p, const std::string& peer_key) {
    const std::string user_id = p.user_id;
    if (p.session_id != 0) {
      auto sit = sessions_.find(p.session_id);
      if (sit != sessions_.end()) {
        sit->second.game.authority().remove_client(p.client_id);
        sit->second.clients.erase(peer_key);
        if (sit->second.clients.empty()) {
          reconnect_.end_session(sit->first);
          sessions_.erase(sit);
        }
      }
      registry_.release(slot_key(p.slot_id)); // the freed seat pulls the queue
    }
    if (!p.queued_request_id.empty()) queue_.remove(kRealm, p.queued_request_id);
    p = Peer{};
    p.user_id = user_id; // keep the signed-in record, drop the session
  }

  // Reconnect: the ticket nonce is the credential; the flow refuses
  // unknown/inactive sessions, reused nonces and closed windows.
  [[nodiscard]] std::vector<std::uint8_t> reconnect(const std::string& peer_key, std::uint32_t session_id,
                                                    std::uint64_t nonce, std::uint64_t now_sec) {
    const auto r = reconnect_.reconnect(session_id, nonce, now_sec);
    if (r.kind != matchmaker::ReconnectFlow::Result::Kind::reconnected) return bytes_of("ERR reconnect");

    // Any other endpoint still holding this session loses it (the client
    // moved); its authority client is removed so no ghost proposals land.
    for (auto it = peers_.begin(); it != peers_.end();) {
      if (it->first != peer_key && it->second.session_id == session_id) {
        auto sit = sessions_.find(session_id);
        if (sit != sessions_.end()) {
          sit->second.game.authority().remove_client(it->second.client_id);
          sit->second.clients.erase(it->first);
        }
        it = peers_.erase(it);
      } else {
        ++it;
      }
    }

    const std::uint32_t slot_num = r.ticket.slot_id;
    const std::uint32_t version = r.ticket.version;
    if (sessions_.count(session_id) == 0) {
      // The host restarted since the drop: rebuild the session from the
      // schema at the reconnect flow's slot, keeping the same session id.
      next_session_id_ = std::max<std::uint64_t>(next_session_id_, session_id + 1);
      sessions_.try_emplace(session_id, session_id, slot_num, version, cfg_.schema);
    }
    Peer& p = peers_[peer_key];
    attach(p, peer_key, slot_num, version, now_sec);
    const auto it = sessions_.find(session_id);
    const auto resume = it == sessions_.end() ? 0 : it->second.game.authority().tick_number();
    return bytes_of("OK RECONNECT " + std::to_string(session_id) + " " + std::to_string(slot_num) + " " +
                    std::to_string(version) + " " + std::to_string(nonce) + " " + to_hex(p.frame_key) + " " +
                    std::to_string(resume));
  }

  // Capacity wake pulls the next queue entries (BAK-10): seats freed by a
  // departure (or a newly added slot) admit queued players and push their
  // JOIN reply from the tick, so the client never re-polls.
  void drain_queue(std::vector<Outgoing>& out, std::uint64_t now_sec) {
    std::uint32_t free_seats = 0;
    for (const auto id : slot_ids_) {
      const auto* s = registry_.find(slot_key(id));
      if (s && s->state == matchmaker::SlotRegistry::State::ready)
        free_seats += matchmaker::SlotRegistry::kMaxPlayersPerSlot - s->players;
    }
    if (free_seats == 0) return;
    for (const auto& e : queue_.pull(kRealm, free_seats, now_sec)) {
      Peer* p = nullptr;
      std::string key;
      for (auto& [k, peer] : peers_)
        if (peer.queued_request_id == e.request_id) { p = &peer; key = k; break; }
      if (p == nullptr || p->user_id.empty()) continue; // departed while queued

      std::uint32_t target = 0;
      for (const auto id : slot_ids_) {
        const auto* s = registry_.find(slot_key(id));
        if (s && s->state == matchmaker::SlotRegistry::State::ready &&
            s->players < matchmaker::SlotRegistry::kMaxPlayersPerSlot) { target = id; break; }
      }
      if (target == 0) continue;
      if (registry_.admit(slot_key(target), now_sec) != matchmaker::SlotRegistry::Admit::admitted) continue;
      const auto version = p->version == 0 ? cfg_.game_version : p->version;
      attach(*p, key, target, version, now_sec);
      out.push_back({key, join_reply(*p)});
    }
  }

  // ---- small helpers ------------------------------------------------------

  // Plain decimal string: ReconnectFlow looks slots up with
  // std::to_string(session.slot_id), so the key must match that form.
  [[nodiscard]] static std::string slot_key(std::uint32_t numeric_id) {
    return std::to_string(numeric_id);
  }

  static std::vector<std::string_view> tokenize(std::string_view s) {
    std::vector<std::string_view> out;
    std::size_t i = 0;
    while (i < s.size() && out.size() < 8) {
      while (i < s.size() && (s[i] == ' ' || s[i] == '\t' || s[i] == '\n' || s[i] == '\r')) ++i;
      const std::size_t start = i;
      while (i < s.size() && s[i] != ' ' && s[i] != '\t' && s[i] != '\n' && s[i] != '\r') ++i;
      if (i > start) {
        if (i - start > 128) return {}; // over-long token: treat as garbage
        out.push_back(s.substr(start, i - start));
      }
    }
    return out;
  }

  static bool parse_u32(std::string_view s, std::uint32_t& out) {
    if (s.empty() || s.size() > 10) return false;
    std::uint64_t v = 0;
    for (const char c : s) {
      if (c < '0' || c > '9') return false;
      v = v * 10 + static_cast<std::uint64_t>(c - '0');
      if (v > 0xFFFFFFFFULL) return false;
    }
    out = static_cast<std::uint32_t>(v);
    return true;
  }

  static bool parse_u64(std::string_view s, std::uint64_t& out) {
    if (s.empty() || s.size() > 20) return false;
    std::uint64_t v = 0;
    for (const char c : s) {
      if (c < '0' || c > '9') return false;
      const std::uint64_t d = static_cast<std::uint64_t>(c - '0');
      if (v > (0xFFFFFFFFFFFFFFFFULL - d) / 10) return false;
      v = v * 10 + d;
    }
    out = v;
    return true;
  }

  static bool parse_i64(std::string_view s, std::int64_t& out) {
    bool negative = false;
    if (!s.empty() && (s[0] == '-' || s[0] == '+')) {
      negative = s[0] == '-';
      s.remove_prefix(1);
    }
    std::uint64_t v = 0;
    if (!parse_u64(s, v)) return false;
    if (negative) {
      if (v > 0x8000000000000000ULL) return false;
      out = v == 0x8000000000000000ULL ? (std::numeric_limits<std::int64_t>::min)()
                                       : -static_cast<std::int64_t>(v);
    } else {
      if (v > 0x7FFFFFFFFFFFFFFFULL) return false;
      out = static_cast<std::int64_t>(v);
    }
    return true;
  }

  static std::vector<std::uint8_t> bytes_of(std::string_view s) { return {s.begin(), s.end()}; }

  static std::string to_hex(const std::vector<std::uint8_t>& bytes) {
    static const char* kHex = "0123456789abcdef";
    std::string out;
    out.reserve(bytes.size() * 2);
    for (const auto b : bytes) {
      out.push_back(kHex[b >> 4]);
      out.push_back(kHex[b & 0xF]);
    }
    return out;
  }

  static std::string to_hex_u64(std::uint64_t v) {
    static const char* kHex = "0123456789abcdef";
    std::string out(16, '0');
    for (int i = 15; i >= 0; --i) {
      out[static_cast<std::size_t>(i)] = kHex[v & 0xF];
      v >>= 4;
    }
    return out;
  }

  HostConfig cfg_;
  matchmaker::SlotRegistry registry_;
  matchmaker::MatchQueue queue_;
  matchmaker::TicketSigner signer_;
  matchmaker::ReconnectFlow reconnect_;
  matchmaker::Matchmaker allocator_;
  identity::InMemoryAccountStore accounts_;
  identity::SignInService sign_in_{accounts_};
  std::vector<std::uint32_t> slot_ids_;
  std::uint64_t next_session_id_;
  std::map<std::string, Peer> peers_;
  std::map<std::uint32_t, HostSession> sessions_;
};

} // namespace poko::host

#endif

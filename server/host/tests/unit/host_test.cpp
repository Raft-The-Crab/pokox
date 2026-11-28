// DEMO-01 acceptance: the host wraps all four server libraries into one
// protocol state machine. Driven without a socket: every call takes server
// time, so the test is deterministic. Covers sign-in gating, allocation,
// queued-then-drained admission, the tick broadcast both clients agree on,
// authority policy over framed INPUT, frame rejection (wrong key, replay,
// garbage), seat release on LEAVE, and reconnect (new endpoint, reused
// nonce refused, ended session refused).
#include "poko/host/host.hpp"

#include "poko/net/frame.hpp"

#include <iostream>
#include <memory>
#include <string>
#include <vector>

namespace {

int errors = 0;

void check(bool ok, const char* what) {
  if (!ok) {
    ++errors;
    std::cerr << "FAIL: " << what << "\n";
  }
}

void eq(const std::string& actual, const std::string& expected, const char* what) {
  if (actual != expected) {
    ++errors;
    std::cerr << "FAIL: " << what << "\n  expected: " << expected << "\n  actual:   " << actual << "\n";
  }
}

void starts_with(const std::string& actual, const std::string& prefix, const char* what) {
  if (actual.rfind(prefix, 0) != 0) {
    ++errors;
    std::cerr << "FAIL: " << what << "\n  expected prefix: " << prefix << "\n  actual: " << actual << "\n";
  }
}

using Bytes = std::vector<std::uint8_t>;

std::string text(const Bytes& b) { return {b.begin(), b.end()}; }

std::string send(poko::host::HostServer& host, const std::string& peer, const std::string& cmd, std::uint64_t now) {
  const Bytes cmd_bytes(cmd.begin(), cmd.end());
  return text(host.handle_datagram(peer, cmd_bytes.data(), cmd_bytes.size(), now));
}

std::vector<std::string> words(const std::string& s) {
  std::vector<std::string> out;
  std::size_t i = 0;
  while (i < s.size()) {
    while (i < s.size() && s[i] == ' ') ++i;
    std::size_t b = i;
    while (i < s.size() && s[i] != ' ') ++i;
    if (i > b) out.push_back(s.substr(b, i - b));
  }
  return out;
}

// A client-side frame builder/sender over the host's protocol.
struct Client {
  std::string peer;
  std::vector<std::uint8_t> key;
  std::uint32_t session_id = 0;
  std::uint32_t next_seq = 1;
  std::deque<std::uint32_t> seen;

  void adopt_ticket(const std::vector<std::string>& w) {
    // OK JOIN <session> <slot> <version> <nonce> <key_hex> <tick>
    session_id = static_cast<std::uint32_t>(std::stoul(w[2]));
    key.clear();
    for (std::size_t i = 0; i + 1 < w[6].size(); i += 2)
      key.push_back(static_cast<std::uint8_t>(std::stoul(w[6].substr(i, 2), nullptr, 16)));
  }

  Bytes frame(const std::string& payload) {
    poko::net::FrameHeader h;
    h.session_id = session_id;
    h.seq = next_seq++;
    h.priority = 0;
    return poko::net::pack_frame(h, Bytes(payload.begin(), payload.end()), key);
  }

  // Returns the reply payload text ("" for silence).
  std::string send_frame(poko::host::HostServer& host, const Bytes& bytes, std::uint64_t now) {
    const auto reply = host.handle_datagram(peer, bytes.data(), bytes.size(), now);
    if (reply.empty()) return {};
    const auto parsed = poko::net::unpack_frame(reply, key, seen);
    if (!parsed.ok) return "<unparseable>";
    return text(parsed.payload);
  }

  std::string snap(const std::vector<poko::host::Outgoing>& out) {
    for (const auto& frame : out) {
      if (frame.peer_key != peer) continue;
      const auto parsed = poko::net::unpack_frame(frame.bytes, key, seen);
      if (parsed.ok) return text(parsed.payload);
    }
    return {};
  }
};

std::unique_ptr<poko::host::HostServer> make_host(std::uint32_t slots, std::uint64_t first_session_id = 1) {
  poko::host::HostConfig cfg;
  cfg.tick_hz = 1; // seconds are ticks: easy deterministic time
  cfg.ticket_secret = "demo-secret";
  const auto err = poko::authority::load_pkb_schema(poko::host::kDemoSchemaText, cfg.schema);
  check(err.code == poko::authority::PkbLoadError::Code::none, "demo schema parses");
  auto host = std::make_unique<poko::host::HostServer>(std::move(cfg), first_session_id);
  for (std::uint32_t i = 1; i <= slots; ++i) check(host->add_slot(i, 0), "slot registered");
  return host;
}

void test_sign_in_and_gates() {
  auto host_up = make_host(1);
  auto& host = *host_up;
  eq(send(host, "a:1", "SIGNIN alice-fb", 0), "OK SIGNIN u-000000000001", "sign-in mints u-1");
  eq(send(host, "a:1", "SIGNIN alice-fb", 0), "OK SIGNIN u-000000000001", "sign-in idempotent");
  eq(send(host, "b:1", "SIGNIN bob-fb", 0), "OK SIGNIN u-000000000002", "second account u-2");
  eq(send(host, "c:1", "SIGNIN", 0), "ERR missing-uid", "empty uid refused");
  eq(send(host, "a:1", "PING", 0), "OK PONG", "ping");

  // Unauthenticated and unsigned-in peers are refused at the gate.
  eq(send(host, "d:1", "JOIN req-1", 0), "ERR sign-in-first", "join before sign-in refused");
  const Bytes junk{0x15, 0, 1, 2, 3};
  check(host.handle_datagram("d:1", junk.data(), junk.size(), 0).empty(), "game frame from unknown peer silenced");
}

void test_join_two_clients_and_tick_broadcast() {
  auto host_up = make_host(1);
  auto& host = *host_up;
  send(host, "a:1", "SIGNIN alice-fb", 0);
  send(host, "b:1", "SIGNIN bob-fb", 0);

  const auto ra = send(host, "a:1", "JOIN req-a-1", 1);
  starts_with(ra, "OK JOIN ", "alice allocated");
  auto wa = words(ra);
  check(wa.size() == 8 && wa[2] == "1" && wa[3] == "1" && wa[4] == "1",
        "join reply: session 1 slot 1 version 1");
  check(wa[5] != "0" && wa[6].size() == 32, "join reply carries a nonce and a 16-byte key");

  Client a;
  a.peer = "a:1";
  a.adopt_ticket(wa);
  const auto rb = send(host, "b:1", "JOIN req-b-1", 1);
  starts_with(rb, "OK JOIN ", "bob allocated");
  Client b;
  b.peer = "b:1";
  b.adopt_ticket(words(rb));
  check(a.session_id == b.session_id, "both clients share the session");
  check(a.key != b.key, "per-client frame keys differ");
  check(host.session_count() == 1, "one session hosts both");
  check(host.slot_players(1) == 2, "registry counts two seats");

  // Idempotent re-join re-serves the same ticket.
  eq(send(host, "a:1", "JOIN req-a-1", 1), ra, "re-join re-serves the ticket");

  // One tick: both clients receive the identical snapshot frame.
  const auto tick2 = host.tick(2);
  const auto sa = a.snap(tick2);
  const auto sb = b.snap(tick2);
  starts_with(sa, "SNAP ", "alice receives a snapshot");
  eq(sb, sa, "both clients agree on the tick broadcast");
  check(words(sa).size() == 8, "snapshot carries all four schema fields");
  eq(words(sa)[1], "2", "snapshot tick is 2 after the second commit");
}

void test_authority_policy_over_frames() {
  auto host_up = make_host(1);
  auto& host = *host_up;
  send(host, "a:1", "SIGNIN alice-fb", 0);
  Client a;
  a.peer = "a:1";
  a.adopt_ticket(words(send(host, "a:1", "JOIN req-a-1", 1)));

  eq(a.send_frame(host, a.frame("INPUT 1 42"), 1), "ACK accepted 1", "validated field accepts 42");
  eq(a.send_frame(host, a.frame("INPUT 4 99"), 1), "ACK discarded 4", "server-owned field 4 (score) is discarded");
  eq(a.send_frame(host, a.frame("INPUT 9 1"), 1), "ACK discarded 9",
     "out-of-range field 9 is discarded (spec 05 trap 0x0D)");
  eq(a.send_frame(host, a.frame("INPUT 1 notanumber"), 1), "ERR input", "malformed value refused");
  eq(a.send_frame(host, a.frame("NOTHING"), 1), "ERR unknown-command", "unknown game verb refused");

  const auto snap = a.snap(host.tick(2));
  const auto w = words(snap);
  check(w.size() == 8 && w[4] == "1=42", "committed snapshot carries the accepted proposal");
  check(w[7] == "4=0", "discarded proposal never moved the server-owned field");

  const Bytes replay = a.frame("INPUT 1 7"); // exact bytes
  eq(a.send_frame(host, replay, 2), "ACK accepted 1", "fresh frame accepted");
  eq(a.send_frame(host, replay, 2), "", "the same bytes replayed are silenced");

  Bytes forged = a.frame("INPUT 1 8");
  forged.back() = static_cast<std::uint8_t>(forged.back() ^ 0xFF); // break the MAC only
  eq(a.send_frame(host, forged, 2), "", "frame with a bad MAC is silenced");

  starts_with(a.send_frame(host, a.frame("STATE"), 2), "SNAP ", "STATE serves the current snapshot");
}

void test_leave_and_seat_release() {
  auto host_up = make_host(1);
  auto& host = *host_up;
  send(host, "a:1", "SIGNIN alice-fb", 0);
  starts_with(send(host, "a:1", "JOIN req-a-1", 1), "OK JOIN 1 ", "joined session 1");
  check(host.slot_players(1) == 1, "one seat taken");

  eq(send(host, "a:1", "LEAVE", 2), "OK LEAVE", "leave accepted");
  check(host.session_count() == 0, "last departure ends the session");
  check(host.slot_players(1) == 0, "seat released");
  eq(send(host, "a:1", "LEAVE", 2), "ERR not-joined", "double leave refused");

  // Re-join after leaving works and starts a fresh session.
  starts_with(send(host, "a:1", "JOIN req-a-2", 2), "OK JOIN 2 ", "re-join mints session 2");
}

void test_queue_then_drain() {
  auto host_up = make_host(0); // no capacity: the request must queue
  auto& host = *host_up;
  send(host, "a:1", "SIGNIN alice-fb", 0);
  starts_with(send(host, "a:1", "JOIN req-a-1", 1), "QUEUED 1 ", "no slots: queued at 1");
  starts_with(send(host, "a:1", "JOIN req-a-1", 1), "QUEUED 1 ", "queued retry is idempotent");
  check(host.queue_depth(1) == 1, "queue depth is 1");

  check(host.tick(1).empty(), "no seats: the queue does not drain");
  check(host.add_slot(1, 2), "capacity arrives");
  const auto out = host.tick(2);
  std::string pushed;
  std::string pushed_to;
  for (const auto& frame : out) {
    if (text(frame.bytes).rfind("OK JOIN ", 0) == 0) { pushed = text(frame.bytes); pushed_to = frame.peer_key; }
  }
  eq(pushed_to, "a:1", "drain pushes the ticket to the queued peer");
  starts_with(pushed, "OK JOIN ", "the pushed reply is the ticket");
  check(out.size() == 2, "drain emits the ticket plus the first snapshot");
  check(host.queue_depth(2) == 0 && host.session_count() == 1, "drained into a live session");
}

void test_reconnect() {
  auto host_up = make_host(1);
  auto& host = *host_up;
  send(host, "a:1", "SIGNIN alice-fb", 0);
  const auto w = words(send(host, "a:1", "JOIN req-a-1", 1));
  const std::string session = w[2];
  const std::string nonce = w[5];

  // The client dropped and came back on a new endpoint with sessionId+nonce.
  const auto rr = send(host, "b:1", "RECONNECT " + session + " " + nonce, 5);
  starts_with(rr, "OK RECONNECT " + session + " ", "reconnect issues a new ticket on the new endpoint");
  const auto w2 = words(rr);
  check(w2.size() == 8 && w2[3] == "1" && w2[4] == "1" && w2[6].size() == 32,
        "reconnect reply carries slot, version and key");
  check(host.peer_count() == 1, "the old endpoint was dropped");

  Client c;
  c.peer = "b:1";
  c.adopt_ticket(w2);
  const auto snap = c.snap(host.tick(6));
  starts_with(snap, "SNAP ", "resumed client receives the tick stream");
  eq(words(snap)[1], "2", "resume continues at the next commit");

  // Nonces are single-use; ended sessions refuse.
  eq(send(host, "c:1", "RECONNECT " + session + " " + nonce, 7), "ERR reconnect", "reused nonce refused");
  eq(send(host, "b:1", "LEAVE", 8), "OK LEAVE", "resumed client can leave");
  eq(send(host, "d:1", "RECONNECT " + session + " " + nonce, 9), "ERR reconnect", "ended session refuses reconnect");
}

} // namespace

int main() {
  test_sign_in_and_gates();
  test_join_two_clients_and_tick_broadcast();
  test_authority_policy_over_frames();
  test_leave_and_seat_release();
  test_queue_then_drain();
  test_reconnect();
  if (errors == 0) std::cout << "host_test: all checks passed\n";
  return errors == 0 ? 0 : 1;
}

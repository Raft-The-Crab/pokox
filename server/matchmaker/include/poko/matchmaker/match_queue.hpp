// BAK-10: the match queue (spec 07 "Queue"; queue row BAK-10 acceptance
// "FIFO under load").
//
// Spec 07: "Valkey sorted sets per realm, scored by enqueue time with
// party-size boosts. Deterministic FIFO. Position estimate and ETA derived
// from slot drain rate. Expire after 5 minutes. Capacity wake or player
// departure pulls the next entry." Capacity accounting: "Queue depth |
// Valkey | Max 500/realm". Anti-abuse: "Queue timestamps are
// server-assigned." API: "All authenticated and idempotent via requestId."
//
// This module is the in-process mirror of the Valkey sorted-set semantics
// (one ZSET per realm; the ZADD/ZCARD/ZREM/ZPOPMIN discipline) — the same
// arrangement as BAK-02's in-memory authority: the Worker process swaps
// the backing store for real Valkey, and the unit tests prove the queue
// semantics deterministically without a network. Every operation takes
// server-assigned time. A member's order key is
// `enqueue_tick - party_boost` with the enqueue sequence as the strict
// tie-break, so equal-score entries come out in enqueue order.
#pragma once

#include <algorithm>
#include <cstdint>
#include <map>
#include <string>
#include <vector>

namespace poko::matchmaker {

class MatchQueue {
public:
  static constexpr std::size_t kMaxDepthPerRealm = 500;   // capacity accounting table
  static constexpr std::uint64_t kExpiryTicks = 300;      // "Expire after 5 minutes"
  static constexpr std::uint64_t kBoostPerExtraMember = 5; // ticks of head start per party member beyond the first

  struct Entry {
    std::string request_id;   // idempotency key (spec 07 API)
    std::uint32_t session_id = 0;
    std::uint32_t party_size = 1;
    std::uint64_t enqueue_tick = 0; // server-assigned
    std::uint64_t seq = 0;          // enqueue order, tie-break
  };

  // Enqueue one request (a party enqueues as one entry, per spec 07
  // parties). Idempotent on request_id: a retry returns `duplicate` and
  // never re-scores or double-queues. Fails closed at the 500 depth —
  // the caller answers "queue full"; nothing is silently dropped.
  enum class Enqueue : std::uint8_t { enqueued, duplicate, full };
  [[nodiscard]] Enqueue enqueue(const std::string& realm, const Entry& e) {
    auto& set = realms_[realm];
    for (const auto& m : set) {
      if (m.entry.request_id == e.request_id) return Enqueue::duplicate;
    }
    if (set.size() >= kMaxDepthPerRealm) return Enqueue::full;
    Member m;
    m.entry = e;
    m.entry.seq = next_seq_++;
    set.push_back(std::move(m));
    sort(set);
    return Enqueue::enqueued;
  }

  // Explicit leave (POST /match/leave).
  [[nodiscard]] bool remove(const std::string& realm, const std::string& request_id) {
    auto& set = realms_[realm];
    for (auto it = set.begin(); it != set.end(); ++it) {
      if (it->entry.request_id == request_id) { set.erase(it); return true; }
    }
    return false;
  }

  // Expire entries older than 5 minutes of server time; returns how many.
  [[nodiscard]] std::size_t expire(const std::string& realm, std::uint64_t now_tick) {
    auto& set = realms_[realm];
    const auto before = set.size();
    set.erase(std::remove_if(set.begin(), set.end(),
                             [&](const Member& m) { return now_tick >= m.entry.enqueue_tick + kExpiryTicks; }),
              set.end());
    return before - set.size();
  }

  // "Capacity wake or player departure pulls the next entry": take the
  // next entries the offered capacity admits, in queue order. A party is
  // admitted only whole ("members are admitted only if party size fits
  // remaining capacity"); a party that does not fit is skipped, not split,
  // and later smaller parties behind it may still be pulled.
  [[nodiscard]] std::vector<Entry> pull(const std::string& realm, std::uint32_t capacity, std::uint64_t now_tick) {
    expire(realm, now_tick);
    std::vector<Entry> out;
    auto& set = realms_[realm];
    std::vector<std::size_t> taken;
    std::uint32_t room = capacity;
    for (std::size_t i = 0; i < set.size() && room > 0; ++i) {
      const auto size = set[i].entry.party_size;
      if (size > room) continue; // party does not fit whole: skipped, not split
      out.push_back(set[i].entry);
      taken.push_back(i);
      room -= size;
    }
    for (std::size_t k = taken.size(); k-- > 0;) set.erase(set.begin() + static_cast<std::ptrdiff_t>(taken[k]));
    return out;
  }

  // One-based position of a request in its realm (0 when absent), after
  // applying expiry — the estimate the client is shown.
  [[nodiscard]] std::size_t position(const std::string& realm, const std::string& request_id, std::uint64_t now_tick) {
    expire(realm, now_tick);
    const auto& set = realms_[realm];
    for (std::size_t i = 0; i < set.size(); ++i) {
      if (set[i].entry.request_id == request_id) return i + 1;
    }
    return 0;
  }

  // "Position estimate and ETA derived from slot drain rate": one drained
  // seat ahead advances the queue one position, so the wait for a party
  // of n from one-based position p is (p - 1) + n seats over the drain
  // rate, rounded up — integer-only, deterministic.
  [[nodiscard]] static std::uint64_t eta_ticks(std::size_t position, std::uint32_t party_size, double drain_per_tick) {
    if (position == 0 || drain_per_tick <= 0.0) return 0;
    const double seats = static_cast<double>(position - 1) + party_size;
    return static_cast<std::uint64_t>(seats / drain_per_tick + 0.999);
  }

  [[nodiscard]] std::size_t depth(const std::string& realm, std::uint64_t now_tick) {
    expire(realm, now_tick);
    return realms_[realm].size();
  }

private:
  struct Member {
    Entry entry;
  };
  // Party-size boost: each member beyond the first lifts the entry by
  // kBoostPerExtraMember ticks (a lower score comes first), so a party
  // formed before enqueueing keeps its place relative to later singles.
  // Signed: the boost may push the score below the first enqueue's tick,
  // and an unsigned wrap would fling the party to the back instead.
  [[nodiscard]] std::int64_t score_of(const Entry& e) const {
    const std::int64_t extras = e.party_size > 1 ? e.party_size - 1 : 0;
    return static_cast<std::int64_t>(e.enqueue_tick) - extras * static_cast<std::int64_t>(kBoostPerExtraMember);
  }
  void sort(std::vector<Member>& set) const {
    std::stable_sort(set.begin(), set.end(), [&](const Member& a, const Member& b) {
      const auto sa = score_of(a.entry), sb = score_of(b.entry);
      return sa != sb ? sa < sb : a.entry.seq < b.entry.seq;
    });
  }
  std::map<std::string, std::vector<Member>> realms_;
  std::uint64_t next_seq_ = 0;
};

} // namespace poko::matchmaker

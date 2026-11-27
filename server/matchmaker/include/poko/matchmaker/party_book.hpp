// BAK-15: party and friend joins (spec 07 "Parties and friends"; queue
// row BAK-15 acceptance "Party affinity works").
//
// Spec 07: "Party formation on the uWS control plane. Leader calls
// match.joinParty; members get affinity and are admitted only if party
// size fits remaining capacity. Parties over 20 are split with a message.
// Friends joining a live session target a specific sessionId." The
// allocation score uses it: "affinityBonus" is subtracted for members of
// the same party, so a party lands on the same slot.
//
// This module is the Worker-side party book over BAK-09's allocator,
// BAK-10's queue and BAK-11's registry (in-process mirror, same
// arrangement as BAK-02..14). Deterministic throughout: membership
// changes take server ticks; a party never exceeds the per-slot cap; an
// over-cap join is refused with the split message, never silently split.
#pragma once

#include "poko/matchmaker/slot_registry.hpp"

#include <cstddef>
#include <cstdint>
#include <map>
#include <optional>
#include <string>
#include <vector>

namespace poko::matchmaker {

class PartyBook {
public:
  static constexpr std::uint32_t kMaxPartySize = SlotRegistry::kMaxPlayersPerSlot; // over 20: split message
  static constexpr std::uint32_t kAffinityBonus = 10; // score points, spec-07 affinityBonus

  struct Party {
    std::string party_id;
    std::string leader_account;
    std::string game_id;
    std::vector<std::string> members; // account ids, leader first
    std::uint64_t created_tick = 0;
  };

  enum class Join : std::uint8_t { joined, party_full, already_member, no_party };

  explicit PartyBook(SlotRegistry& registry) : registry_(registry) {}

  // Leader calls match.joinParty: create a party. Over-cap formation is
  // refused with the split message (the client shows it; the party is
  // never silently split).
  [[nodiscard]] Join create(const std::string& party_id, const std::string& leader, const std::string& game_id,
                            std::uint32_t wanted_size, std::uint64_t now_tick) {
    if (wanted_size > kMaxPartySize) return Join::party_full; // "parties over 20 are split with a message"
    if (parties_.count(party_id)) return Join::already_member;
    Party p;
    p.party_id = party_id;
    p.leader_account = leader;
    p.game_id = game_id;
    p.members.push_back(leader);
    p.created_tick = now_tick;
    parties_[party_id] = p;
    party_of_[leader] = party_id;
    return Join::joined;
  }

  // A member joins by invitation (the leader relays it; membership is
  // bounded by the per-party cap).
  [[nodiscard]] Join join(const std::string& party_id, const std::string& account) {
    auto it = parties_.find(party_id);
    if (it == parties_.end()) return Join::no_party;
    auto& p = it->second;
    if (p.members.size() >= kMaxPartySize) return Join::party_full;
    for (const auto& m : p.members) {
      if (m == account) return Join::already_member;
    }
    p.members.push_back(account);
    party_of_[account] = party_id;
    return Join::joined;
  }

  [[nodiscard]] bool leave(const std::string& account) {
    const auto pit = party_of_.find(account);
    if (pit == party_of_.end()) return false;
    auto& p = parties_[pit->second];
    for (std::size_t i = 0; i < p.members.size(); ++i) {
      if (p.members[i] == account) { p.members.erase(p.members.begin() + static_cast<std::ptrdiff_t>(i)); break; }
    }
    party_of_.erase(pit);
    if (p.members.empty()) parties_.erase(p.party_id);
    return true;
  }

  // "Members get affinity": party members of the game being allocated
  // score the affinity bonus (subtracted in the spec-07 allocation
  // score), so the allocator ranks the party's shared slot first.
  [[nodiscard]] std::uint32_t affinity_bonus(const std::string& account, const std::string& game_id) const {
    const auto pit = party_of_.find(account);
    if (pit == party_of_.end()) return 0;
    return parties_.at(pit->second).game_id == game_id ? kAffinityBonus : 0;
  }

  // "Admitted only if party size fits remaining capacity": the whole
  // party or nobody. Registry-backed; a party that does not fit is
  // refused whole (the caller answers with the queue), never split. The
  // per-tick admission loop re-checks every cap, and a mid-loop refusal
  // is rolled back exactly.
  [[nodiscard]] bool admit_whole(const Party& p, const std::string& slot_id, std::uint64_t now_tick) {
    const auto* slot = registry_.find(slot_id);
    if (!slot || slot->state != SlotRegistry::State::ready) return false;
    if (p.members.size() > SlotRegistry::kMaxPlayersPerSlot - slot->players) return false;
    for (std::size_t i = 0; i < p.members.size(); ++i) {
      if (registry_.admit(slot_id, now_tick) != SlotRegistry::Admit::admitted) {
        for (std::size_t k = 0; k < i; ++k) static_cast<void>(registry_.release(slot_id));
        return false;
      }
    }
    return true;
  }
  [[nodiscard]] bool admit_whole(const std::string& party_id, const std::string& slot_id, std::uint64_t now_tick) {
    const auto it = parties_.find(party_id);
    return it != parties_.end() && admit_whole(it->second, slot_id, now_tick);
  }

  // "Friends joining a live session target a specific sessionId": the
  // friend takes one seat on that session's slot, only when alive.
  [[nodiscard]] bool friend_join(const std::string& session_slot_id, std::uint64_t now_tick) {
    return registry_.admit(session_slot_id, now_tick) == SlotRegistry::Admit::admitted;
  }

  [[nodiscard]] const Party* party(const std::string& party_id) const {
    auto it = parties_.find(party_id);
    return it == parties_.end() ? nullptr : &it->second;
  }
  [[nodiscard]] std::optional<std::string> party_of(const std::string& account) const {
    auto it = party_of_.find(account);
    return it == party_of_.end() ? std::nullopt : std::optional<std::string>(it->second);
  }

private:
  SlotRegistry& registry_;
  std::map<std::string, Party> parties_;
  std::map<std::string, std::string> party_of_;
};

} // namespace poko::matchmaker

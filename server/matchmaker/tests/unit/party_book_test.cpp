// BAK-15 acceptance: "Party affinity works". Party members of the same
// game score the affinity bonus; a party is admitted whole or not at all
// (never split, never over the per-slot cap); parties over 20 are refused
// with the split message; a friend targets a specific live sessionId's
// slot.
#include "poko/matchmaker/party_book.hpp"

#include <iostream>

namespace {
int errors = 0;
void check(bool ok, const char* what) {
  if (!ok) { ++errors; std::cerr << "FAIL: " << what << "\n"; }
}
using namespace poko::matchmaker;
using PB = PartyBook;
} // namespace

int main() {
  SlotRegistry reg;
  PB pb(reg);

  // Formation and membership.
  check(pb.create("p1", "alice", "g1", 3, 0) == PB::Join::joined, "leader creates the party");
  check(pb.create("p2", "bob", "g1", 25, 0) == PB::Join::party_full, "over-20 formation refused (split message)");
  check(pb.join("p1", "bob") == PB::Join::joined, "member joins");
  check(pb.join("p1", "carol") == PB::Join::joined, "second member joins");
  check(pb.join("p1", "bob") == PB::Join::already_member, "double join refused");
  check(pb.join("nope", "dan") == PB::Join::no_party, "unknown party refused");
  check(pb.party_of("bob").has_value() && *pb.party_of("bob") == "p1", "membership recorded");

  // Affinity: members of the party in its game score the bonus; a
  // non-member and a cross-game member do not.
  check(pb.affinity_bonus("bob", "g1") == PB::kAffinityBonus, "member gets affinity in the party's game");
  check(pb.affinity_bonus("dan", "g1") == 0, "non-member gets no affinity");
  check(pb.create("p2", "erin", "g2", 1, 0) == PB::Join::joined, "other party created");
  check(pb.affinity_bonus("erin", "g1") == 0, "cross-game member gets no affinity");

  // Whole-party admission: a party of 3 fits a fresh slot of 20.
  SlotRegistry::Slot s1;
  s1.slot_id = "s1";
  reg.register_slot(s1, 0);
  check(pb.admit_whole("p1", "s1", 0), "party of 3 admitted whole");
  const auto* slot = reg.find("s1");
  check(slot != nullptr && slot->players == 3, "registry counted 3 admissions");
  check(reg.admit("s1", 0) == SlotRegistry::Admit::admitted, "walk-in still admitted with room");

  // Does not fit: 19 players on the slot, party of 3 -> refused whole,
  // nothing partially admitted.
  SlotRegistry::Slot s2;
  s2.slot_id = "s2";
  s2.source = SlotRegistry::Source::donated; // donated: bypasses the global 20-CCU cap (per-slot 20 still binds)
  reg.register_slot(s2, 0);
  for (int i = 0; i < 18; ++i) reg.admit("s2", 0); // 18 of 20 seats taken
  check(!pb.admit_whole("p1", "s2", 0), "party of 3 refused at 2 remaining seats");
  check(reg.find("s2")->players == 18, "refusal left the slot untouched (whole or nobody)");

  // Exact fit: a party of 2 fills the 20-seat slot and it goes Full.
  check(pb.join("p2", "frank") == PB::Join::joined, "second member joins p2");
  SlotRegistry::Slot s3;
  s3.slot_id = "s3";
  s3.source = SlotRegistry::Source::donated;
  reg.register_slot(s3, 0);
  for (int i = 0; i < 18; ++i) reg.admit("s3", 0);
  check(pb.admit_whole("p2", "s3", 0), "party of 2 fills the last 2 seats exactly");
  check(reg.find("s3")->state == SlotRegistry::State::full, "slot is Full at the cap");

  // Rollback: a party larger than the whole slot can never partially
  // land even against an empty slot.
  SlotRegistry::Slot s4;
  s4.slot_id = "s4";
  s4.source = SlotRegistry::Source::donated;
  reg.register_slot(s4, 0);
  PB::Party huge;
  huge.party_id = "huge";
  for (int i = 0; i < 25; ++i) huge.members.push_back("m" + std::to_string(i));
  check(!pb.admit_whole(huge, "s4", 0), "over-slot party refused");
  check(reg.find("s4")->players == 0, "mid-loop rollback restored the slot exactly");

  // Friend join targets a specific live sessionId's slot and takes one
  // seat.
  check(pb.friend_join("s1", 0), "friend admitted to the targeted session's slot");
  check(reg.find("s1")->players == 5, "friend took one seat on the target slot (3 party + walk-in + friend)");

  // Leave: membership ends, a party with no members is gone.
  check(pb.leave("carol"), "member left");
  check(!pb.party_of("carol").has_value(), "membership cleared");
  check(pb.leave("alice") && pb.leave("bob") && !pb.party("p1"), "empty party dissolved");

  if (errors == 0) std::cout << "OK: all party checks passed\n";
  else std::cout << errors << " check(s) FAILED\n";
  return errors == 0 ? 0 : 1;
}

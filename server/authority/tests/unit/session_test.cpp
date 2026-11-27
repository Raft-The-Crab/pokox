// BAK-02 acceptance: two clients agree. Two registered clients propose
// values for the same session; after a tick both receive the identical
// authoritative snapshot and projected hash. Also proves the policy
// enforcement: a ServerOwned client write is discarded, a Derived write is
// refused, a Trusted write lands but stays out of the projected hash, and
// two same-tick Validated proposals for one field resolve first-wins.
#include "poko/authority/session.hpp"

#include <iostream>

using namespace poko::authority;

int main() {
  int errors = 0;
  auto check = [&](bool ok, const char* what) {
    if (!ok) { ++errors; std::cerr << "FAIL: " << what << "\n"; }
  };

  SessionAuthority auth(/*session_nonce=*/0xDEADBEEF, /*hash_seed=*/7);
  auth.define_field({1, "pokoins_a", Policy::server_owned, 100});
  auth.define_field({2, "cube_x", Policy::validated, 0});
  auth.define_field({3, "player_name", Policy::trusted, 0});
  auth.define_field({4, "distance_to_goal", Policy::derived, 0});
  auth.define_field({2, "duplicate_id", Policy::trusted, 0}); // must be ignored
  check(auth.client_count() == 0, "starts with no clients");

  const std::uint32_t a = auth.add_client();
  const std::uint32_t b = auth.add_client();
  check(auth.client_count() == 2, "two clients joined");

  // Both clients propose; the Validated cube_x field takes both.
  check(auth.propose(a, 1, 999999).code == ProposalResult::Code::discarded,
        "ServerOwned client write discarded");
  check(auth.propose(a, 2, 10).code == ProposalResult::Code::accepted, "client A Validated proposal accepted");
  check(auth.propose(b, 2, 20).code == ProposalResult::Code::accepted, "client B Validated proposal accepted");
  check(auth.propose(a, 4, 1).code == ProposalResult::Code::discarded, "Derived client write refused");
  check(auth.propose(a, 3, 77).code == ProposalResult::Code::accepted, "Trusted client write accepted");
  check(auth.propose(/*client=*/99, 2, 5).code == ProposalResult::Code::unknown_client, "unknown client refused");
  check(auth.propose(a, /*field=*/99, 5).code == ProposalResult::Code::unknown_field, "unknown field refused");
  check(auth.set_authoritative(2, 1) == false, "authority write refused on client-writable field");
  check(auth.set_authoritative(1, 42), "authority writes ServerOwned");

  const Snapshot s1 = auth.tick();
  check(auth.tick_number() == 1, "tick advanced to 1");

  // Acceptance: both clients see the identical snapshot, byte-for-byte.
  const Snapshot sa = auth.snapshot_for(a);
  const Snapshot sb = auth.snapshot_for(b);
  check(sa == sb && sa.tick == s1.tick && sa.projected_hash == s1.projected_hash,
        "both clients served the identical snapshot");

  check(auth.value_of(1) == 42, "ServerOwned value came from authority, not the client's 999999");
  check(auth.value_of(2) == 10, "same-tick Validated proposals: first wins (10, not 20)");
  check(auth.value_of(4) == 0, "Derived value unchanged by refused client write");
  check(auth.value_of(3) == 77, "Trusted value applied as-is");

  // Trusted must not enter the projected hash: same ServerOwned/Validated/
  // Derived values with a different Trusted value must hash identically.
  const std::uint64_t hash_before = auth.projected_hash(1);
  auth.propose(b, 3, 12345);
  const std::uint64_t hash_after = auth.projected_hash(1);
  check(hash_before == hash_after, "Trusted change does not move the projected hash");
  check(auth.propose(a, 2, 11).code == ProposalResult::Code::accepted, "next-tick Validated proposal accepted");
  const std::uint64_t hash_next = auth.projected_hash(2);
  check(hash_next != hash_before, "different tick and value give a different projected hash");

  // A second authority with the same nonce, seed, schema and field values
  // must produce the same projected hash (determinism across processes).
  SessionAuthority auth2(0xDEADBEEF, 7);
  auth2.define_field({1, "pokoins_a", Policy::server_owned, 100});
  auth2.define_field({2, "cube_x", Policy::validated, 0});
  auth2.define_field({3, "player_name", Policy::trusted, 0});
  auth2.define_field({4, "distance_to_goal", Policy::derived, 0});
  auth2.set_authoritative(1, 42);
  auth2.propose(auth2.add_client(), 2, 10);
  auth2.propose(auth2.add_client(), 3, 77);
  auth2.tick();
  check(auth2.projected_hash(1) == hash_before, "same state, nonce and seed reproduce the hash");

  // Leaving one client must not disturb the other's agreement path.
  auth.remove_client(a);
  check(auth.client_count() == 1, "client A left");
  const Snapshot s2 = auth.tick();
  check(auth.snapshot_for(b) == s2, "remaining client still served the committed snapshot");

  if (errors) { std::cerr << errors << " failure(s)\n"; return 1; }
  std::cout << "authority session tests passed\n";
  return 0;
}

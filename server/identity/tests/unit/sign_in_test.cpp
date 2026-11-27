// IDN-01 acceptance: sign-in creates a PokoX record; the second sign-in
// returns the same account without overwriting platform-owned state.
#include "poko/identity/sign_in.hpp"

#include <iostream>
#include <stdexcept>

using namespace poko::identity;

int main() {
  int errors = 0;
  auto check = [&](bool ok, const char* what) {
    if (!ok) { ++errors; std::cerr << "FAIL: " << what << "\n"; }
  };

  InMemoryAccountStore store;
  SignInService service(store);

  // First sign-in creates the record with Basic trust and the player role.
  auto first = service.sign_in({"fb-uid-1", "a@b.c", "Alice"});
  check(first.user_id == "u-000000000001", "first user id is u-000000000001");
  check(first.firebase_uid == "fb-uid-1", "firebase uid stored");
  check(first.email == "a@b.c", "email stored");
  check(first.display_name == "Alice", "display name stored");
  check(first.trust_level == TrustLevel::kBasic, "trust level is Basic");
  check(first.roles.size() == 1 && first.roles[0].name == "player", "player role granted");

  // Second sign-in for the same Firebase UID returns the same account.
  auto second = service.sign_in({"fb-uid-1", "a@b.c", "Alice"});
  check(second.user_id == first.user_id, "second sign-in reuses the user id");

  // Platform-owned state survives a re-sign-in (no overwrite from the claim).
  auto promoted = first;
  promoted.trust_level = TrustLevel::kModerator;
  promoted.roles.push_back({"moderator"});
  store.update(promoted);
  auto after = service.sign_in({"fb-uid-1", "a@b.c", "Alice"});
  check(after.trust_level == TrustLevel::kModerator, "moderator trust survives re-sign-in");
  check(after.roles.size() == 2, "roles survive re-sign-in");
  check(after.display_name == "Alice", "profile fields survive re-sign-in");

  // A different Firebase UID gets a distinct record.
  auto other = service.sign_in({"fb-uid-2", "", "Bob"});
  check(other.user_id == "u-000000000002", "second user gets u-000000000002");
  check(other.user_id != first.user_id, "distinct firebase uids get distinct accounts");

  // An empty Firebase UID is a malformed claim and never creates an account.
  bool threw = false;
  try { service.sign_in({"", "x@y.z", "Ghost"}); } catch (const std::invalid_argument&) { threw = true; }
  check(threw, "empty firebase uid rejected");
  check(!store.find_by_firebase_uid("").has_value(), "no record created for empty uid");

  // Anonymous Firebase account (no email) is still a valid identity claim.
  auto anon = service.sign_in({"fb-uid-3", "", ""});
  check(anon.email.empty() && anon.trust_level == TrustLevel::kBasic, "anonymous sign-in gets Basic trust");

  if (errors) { std::cerr << errors << " failure(s)\n"; return 1; }
  std::cout << "identity sign-in tests passed\n";
  return 0;
}

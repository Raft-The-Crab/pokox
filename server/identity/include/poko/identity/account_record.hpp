// IDN-01: PokoX account record and sign-in from a verified Firebase identity.
// Firebase only proves the identity claim (sign-in); the account record and
// its trust state are PokoX-owned (spec 17). Firebase token verification at
// the Worker is BAK-03 and is intentionally not part of this module.
#ifndef POKO_IDENTITY_ACCOUNT_RECORD_HPP
#define POKO_IDENTITY_ACCOUNT_RECORD_HPP

#include <cstdint>
#include <string>
#include <vector>

namespace poko::identity {

// Trust levels escalate from anonymous to staff (spec 17).
enum class TrustLevel : std::uint8_t {
  kGuest = 0,     // no verified sign-in
  kBasic = 1,     // Firebase sign-in only
  kDevice = 2,    // device keypair bound (IDN-02)
  kVerified = 3,  // verified email or recovery contact
  kDeveloper = 4, // approved developer
  kModerator = 5, // platform moderation staff
};

// Firebase's claim about the signed-in user. A real token is verified at the
// Worker (BAK-03); here it is the already-verified payload.
struct FirebaseIdentity {
  std::string uid;          // Firebase Auth UID, non-empty
  std::string email;        // may be empty for anonymous Firebase accounts
  std::string display_name; // may be empty
};

struct Role {
  std::string name; // canonical role name, e.g. "player"
};

struct AccountRecord {
  std::string user_id;    // immutable PokoX user id (never reused)
  std::string firebase_uid;
  std::string email;
  std::string display_name;
  TrustLevel trust_level = TrustLevel::kBasic;
  std::vector<Role> roles;
  // Device bindings arrive with IDN-02; the field exists so later tasks do
  // not need to change the record shape.
  std::vector<std::string> device_ids;
};

} // namespace poko::identity

#endif

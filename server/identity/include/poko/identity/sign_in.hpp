// IDN-01: sign-in service. Maps a verified Firebase identity to an idempotent
// PokoX account record. One source of truth per fact: the account record is
// created once per Firebase UID; repeated sign-ins return the same record and
// never overwrite platform-owned state such as trust level or roles.
#ifndef POKO_IDENTITY_SIGN_IN_HPP
#define POKO_IDENTITY_SIGN_IN_HPP

#include "poko/identity/account_record.hpp"

#include <map>
#include <mutex>
#include <optional>
#include <stdexcept>
#include <string>

namespace poko::identity {

// In-memory account store. The deployed store is Postgres (spec 03); the
// interface and semantics are what later waves build on.
class AccountStore {
public:
  virtual ~AccountStore() = default;
  // Returns the existing record for a Firebase UID, or nullopt.
  virtual std::optional<AccountRecord> find_by_firebase_uid(const std::string& firebase_uid) = 0;
  // Returns the existing record for a PokoX user id, or nullopt.
  virtual std::optional<AccountRecord> find_by_user_id(const std::string& user_id) = 0;
  virtual void insert(const AccountRecord& record) = 0;
  virtual void update(const AccountRecord& record) = 0;
};

class InMemoryAccountStore : public AccountStore {
public:
  std::optional<AccountRecord> find_by_firebase_uid(const std::string& firebase_uid) override {
    std::lock_guard<std::mutex> lock(mutex_);
    auto it = records_.find(firebase_uid);
    if (it == records_.end()) return std::nullopt;
    return it->second;
  }
  std::optional<AccountRecord> find_by_user_id(const std::string& user_id) override {
    std::lock_guard<std::mutex> lock(mutex_);
    auto it = by_user_id_.find(user_id);
    if (it == by_user_id_.end()) return std::nullopt;
    return it->second;
  }
  void insert(const AccountRecord& record) override {
    std::lock_guard<std::mutex> lock(mutex_);
    records_[record.firebase_uid] = record;
    by_user_id_[record.user_id] = record;
  }
  void update(const AccountRecord& record) override {
    std::lock_guard<std::mutex> lock(mutex_);
    records_[record.firebase_uid] = record;
    by_user_id_[record.user_id] = record;
  }

private:
  std::map<std::string, AccountRecord> records_;
  std::map<std::string, AccountRecord> by_user_id_;
  std::mutex mutex_;
};

// Deterministic, monotonic user ids: "u-000000000001" and so on. Ids are
// never reused, so the counter only moves forward even if sign-ins fail.
inline std::string format_user_id(std::uint64_t counter) {
  std::string digits = std::to_string(counter);
  return "u-" + std::string(12 - digits.size(), '0') + digits;
}

class SignInService {
public:
  explicit SignInService(AccountStore& store) : store_(store) {}

  // Creates the PokoX record on first sign-in; returns the unchanged existing
  // record afterwards. Throws std::invalid_argument on an empty Firebase UID:
  // an unverified or malformed claim never creates an account.
  AccountRecord sign_in(const FirebaseIdentity& identity) {
    if (identity.uid.empty()) throw std::invalid_argument("firebase uid is empty");
    if (auto existing = store_.find_by_firebase_uid(identity.uid)) return *existing;

    AccountRecord record;
    record.user_id = format_user_id(next_id_++);
    record.firebase_uid = identity.uid;
    record.email = identity.email;
    record.display_name = identity.display_name;
    record.trust_level = TrustLevel::kBasic;
    record.roles.push_back({"player"});
    store_.insert(record);
    return record;
  }

private:
  AccountStore& store_;
  std::uint64_t next_id_ = 1;
};

} // namespace poko::identity

#endif

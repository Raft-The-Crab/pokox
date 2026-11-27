// IDN-02: device keypair binding (TOFU) and revocation. First sign-in from a
// device binds its fingerprint; later sign-ins from the same device skip
// binding; a new device lands at Basic (IDN-03 grants it Device trust after
// step-up). TOFU is convenience, not security; step-up is the backstop.
// Cap of five trusted devices; revocation from any trusted device is enforced
// here so BAK-04's ticket issuance only has to honor the stored state.
#ifndef POKO_IDENTITY_DEVICE_BINDING_HPP
#define POKO_IDENTITY_DEVICE_BINDING_HPP

#include "poko/identity/account_record.hpp"
#include "poko/identity/sign_in.hpp"

#include <algorithm>
#include <map>
#include <memory>
#include <mutex>
#include <set>
#include <stdexcept>
#include <string>

namespace poko::identity {

// Shared per-process revoked-device ledger (User ID -> fingerprints). In the
// deployed service this lives in the Worker's Postgres store; every service
// instance must consult the same ledger so a revocation anywhere is seen
// everywhere.
using RevokedDeviceLedger = std::map<std::string, std::set<std::string>>;

inline constexpr std::size_t kMaxTrustedDevices = 5;

// TOFU enrollment result for one sign-in from one device. The keypair itself
// lives in the OS keystore on the client; the platform only ever sees the
// fingerprint and the signature over its challenge (kept opaque here).
struct DeviceBindingResult {
  TrustLevel trust = TrustLevel::kBasic;
  bool newly_bound = false; // this sign-in bound the device (TOFU first use)
  bool revoked = false;     // the device was trusted before and was revoked
};

class DeviceBindingService {
public:
  explicit DeviceBindingService(AccountStore& store,
      std::shared_ptr<std::pair<RevokedDeviceLedger, std::mutex>> revoked_state = std::make_shared<std::pair<RevokedDeviceLedger, std::mutex>>())
      : store_(store), revoked_(std::move(revoked_state)) {}

  // TOFU: binds a device the Worker already recognizes (IDN-02 path). With
  // trust_on_new_device=false (the IDN-03 default) a brand-new device is NOT
  // bound by a bare sign-in: it stays at Basic until OTP step-up completes.
  DeviceBindingResult bind_on_sign_in(const std::string& user_id, const std::string& fingerprint, bool trust_on_new_device = true) {
    if (fingerprint.empty()) throw std::invalid_argument("device fingerprint is empty");
    AccountRecord record = must_find(user_id);

    DeviceBindingResult result;
    result.trust = record.trust_level;

    auto& devices = record.device_ids;
    bool trusted = std::find(devices.begin(), devices.end(), fingerprint) != devices.end();
    if (trusted) {
      // A bound device pair spends at Device trust even though the account's
      // platform-wide trust stays Basic until IDN-03 step-up.
      result.trust = TrustLevel::kDevice;
      return result; // second sign-in skips binding
    }

    if (is_revoked(user_id, fingerprint)) {
      result.revoked = true;
      result.trust = record.trust_level; // revoked device falls back to account trust
      return result;
    }

    if (!trust_on_new_device) return result; // new device lands Basic; step-up decides

    if (devices.size() >= kMaxTrustedDevices) throw std::runtime_error("trusted device limit reached");

    devices.push_back(fingerprint);
    store_.update(record);
    result.trust = TrustLevel::kDevice;
    result.newly_bound = true;
    return result;
  }

  // Revocation from any trusted device or recovery (spec 17). Revoked
  // fingerprints are remembered per account so a replayed binding cannot
  // resurrect the device.
  void revoke_device(const std::string& user_id, const std::string& fingerprint) {
    if (fingerprint.empty()) throw std::invalid_argument("device fingerprint is empty");
    AccountRecord record = must_find(user_id);
    auto& devices = record.device_ids;
    devices.erase(std::remove(devices.begin(), devices.end(), fingerprint), devices.end());
    {
      std::lock_guard<std::mutex> lock(revoked_->second);
      revoked_->first[user_id].insert(fingerprint);
    }
    store_.update(record);
  }

  bool is_revoked(const std::string& user_id, const std::string& fingerprint) {
    std::lock_guard<std::mutex> lock(revoked_->second);
    auto it = revoked_->first.find(user_id);
    return it != revoked_->first.end() && it->second.count(fingerprint) != 0;
  }

  // For BAK-04: ticket issuance must fail for devices that are not trusted.
  bool device_trusted(const std::string& user_id, const std::string& fingerprint) {
    if (fingerprint.empty()) return false;
    auto record = store_.find_by_user_id(user_id);
    if (!record) return false;
    const auto& devices = record->device_ids;
    return std::find(devices.begin(), devices.end(), fingerprint) != devices.end();
  }

private:
  AccountRecord must_find(const std::string& user_id) {
    auto record = store_.find_by_user_id(user_id);
    if (!record) throw std::runtime_error("unknown account");
    return *record;
  }

  AccountStore& store_;
  std::shared_ptr<std::pair<RevokedDeviceLedger, std::mutex>> revoked_;
};

} // namespace poko::identity

#endif

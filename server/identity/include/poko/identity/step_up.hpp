// IDN-03: trust levels and step-up. A sign-in from a device that is not bound
// lands at Basic; spending and other Device-trust actions require completing
// OTP step-up, which binds the device (five-device cap still applies) and
// marks it trusted. TOFU (IDN-02) is the convenience path when the Worker
// already recognizes the fingerprint; step-up is the backstop for a new one.
#ifndef POKO_IDENTITY_STEP_UP_HPP
#define POKO_IDENTITY_STEP_UP_HPP

#include "poko/identity/device_binding.hpp"

#include <map>
#include <mutex>
#include <stdexcept>
#include <string>
#include <utility>

namespace poko::identity {

// Actions that need Device trust (spend, purchase, market orders) call
// require_device_trust and must fail closed for Basic accounts.
class StepUpService {
public:
  explicit StepUpService(AccountStore& store, DeviceBindingService& binding)
      : store_(store), binding_(binding) {}

  // Sign-in from a device the account does not recognize lands at Basic and
  // starts an OTP challenge. The OTP itself is delivered by the Worker
  // (email/phone per spec 17 recovery); here the code is compared exactly.
  void begin_step_up(const std::string& user_id, const std::string& fingerprint, const std::string& otp_code) {
    if (fingerprint.empty()) throw std::invalid_argument("device fingerprint is empty");
    if (otp_code.empty()) throw std::invalid_argument("otp code is empty");
    must_find(user_id);
    std::lock_guard<std::mutex> lock(mutex_);
    challenges_[{user_id, fingerprint}] = otp_code;
  }

  // Completes step-up: binds the device at Device trust. A wrong code never
  // binds; a revoked device stays revoked (its binding must be re-made by an
  // operator or recovery, never by knowing the OTP alone).
  DeviceBindingResult complete_step_up(const std::string& user_id, const std::string& fingerprint, const std::string& otp_code) {
    if (fingerprint.empty()) throw std::invalid_argument("device fingerprint is empty");
    must_find(user_id);
    {
      std::lock_guard<std::mutex> lock(mutex_);
      auto it = challenges_.find({user_id, fingerprint});
      if (it == challenges_.end() || it->second != otp_code) throw std::runtime_error("step-up otp invalid or not started");
      challenges_.erase(it);
    }
    if (binding_.is_revoked(user_id, fingerprint)) {
      DeviceBindingResult revoked;
      revoked.revoked = true;
      revoked.trust = store_.find_by_user_id(user_id)->trust_level;
      return revoked;
    }
    return binding_.bind_on_sign_in(user_id, fingerprint, /*trust_on_new_device=*/true);
  }

  // Fail-closed gate for Device-trust actions (spend, purchase, market).
  void require_device_trust(const std::string& user_id, const std::string& fingerprint) {
    if (!binding_.device_trusted(user_id, fingerprint)) throw std::runtime_error("device trust required");
  }

private:
  AccountRecord must_find(const std::string& user_id) {
    auto record = store_.find_by_user_id(user_id);
    if (!record) throw std::runtime_error("unknown account");
    return *record;
  }

  AccountStore& store_;
  DeviceBindingService& binding_;
  std::map<std::pair<std::string, std::string>, std::string> challenges_;
  std::mutex mutex_;
};

} // namespace poko::identity

#endif

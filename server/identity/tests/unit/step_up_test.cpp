// IDN-03 acceptance: a sign-in from a new device lands at Basic and requires
// OTP step-up before spending; step-up binds the device at Device trust; a
// wrong code never binds; a revoked device cannot step up back to trust.
#include "poko/identity/step_up.hpp"

#include <iostream>
#include <stdexcept>

using namespace poko::identity;

int main() {
  int errors = 0;
  auto check = [&](bool ok, const char* what) {
    if (!ok) { ++errors; std::cerr << "FAIL: " << what << "\n"; }
  };

  InMemoryAccountStore store;
  SignInService sign_in(store);
  DeviceBindingService devices(store);
  StepUpService step_up(store, devices);

  auto account = sign_in.sign_in({"fb-uid-1", "a@b.c", "Alice"});
  const auto& uid = account.user_id;

  // Sign-in from a brand-new device: no silent binding, lands at Basic.
  auto landing = devices.bind_on_sign_in(uid, "dev-new", /*trust_on_new_device=*/false);
  check(!landing.newly_bound, "bare sign-in does not bind a new device");
  check(landing.trust == TrustLevel::kBasic, "new device lands at Basic");
  bool denied = false;
  try { step_up.require_device_trust(uid, "dev-new"); } catch (const std::runtime_error&) { denied = true; }
  check(denied, "spend refused before step-up (fail closed)");

  // Step-up with a wrong code never binds.
  step_up.begin_step_up(uid, "dev-new", "123456");
  bool wrong_rejected = false;
  try { step_up.complete_step_up(uid, "dev-new", "000000"); } catch (const std::runtime_error&) { wrong_rejected = true; }
  check(wrong_rejected, "wrong OTP rejected");
  check(!devices.device_trusted(uid, "dev-new"), "wrong OTP does not bind the device");

  // Correct code binds the device at Device trust and unlocks spending.
  auto done = step_up.complete_step_up(uid, "dev-new", "123456");
  check(done.newly_bound && done.trust == TrustLevel::kDevice, "step-up binds at Device trust");
  bool allowed = true;
  try { step_up.require_device_trust(uid, "dev-new"); } catch (const std::runtime_error&) { allowed = false; }
  check(allowed, "spend allowed after step-up");

  // Single-use code: replaying the same OTP cannot bind again.
  bool replay_rejected = false;
  try { step_up.complete_step_up(uid, "dev-new", "123456"); } catch (const std::runtime_error&) { replay_rejected = true; }
  check(replay_rejected, "OTP is single-use");

  // A revoked device cannot recover trust by knowing an OTP.
  devices.revoke_device(uid, "dev-new");
  step_up.begin_step_up(uid, "dev-new", "654321");
  auto revoked = step_up.complete_step_up(uid, "dev-new", "654321");
  check(revoked.revoked, "revoked device reports revoked at step-up");
  check(!devices.device_trusted(uid, "dev-new"), "revoked device does not regain trust via OTP");
  denied = false;
  try { step_up.require_device_trust(uid, "dev-new"); } catch (const std::runtime_error&) { denied = true; }
  check(denied, "spend stays refused for revoked device");

  if (errors) { std::cerr << errors << " failure(s)\n"; return 1; }
  std::cout << "step-up tests passed\n";
  return 0;
}

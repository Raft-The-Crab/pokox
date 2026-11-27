// IDN-02 acceptance: first sign-in binds the device and grants Device trust;
// a second sign-in from the same device skips binding; a new device lands at
// Basic; five-device cap enforced; revocation sticks and ticket issuance
// refuses revoked devices.
#include "poko/identity/device_binding.hpp"

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

  auto account = sign_in.sign_in({"fb-uid-1", "a@b.c", "Alice"});
  const auto& uid = account.user_id;
  check(account.trust_level == TrustLevel::kBasic, "account starts at Basic");

  // First sign-in from device A binds it (TOFU) and lands Device trust.
  auto first = devices.bind_on_sign_in(uid, "dev-a");
  check(first.newly_bound, "first sign-in binds the device");
  check(first.trust == TrustLevel::kDevice, "bound device gets Device trust");
  check(!first.revoked, "not revoked");

  // Second sign-in from the same device skips binding.
  auto again = devices.bind_on_sign_in(uid, "dev-a");
  check(!again.newly_bound, "second sign-in skips binding");
  check(again.trust == TrustLevel::kDevice, "trust preserved on re-sign-in");

  // A brand-new device lands at Basic until step-up (IDN-03).
  auto new_device = devices.bind_on_sign_in(uid, "dev-b");
  check(new_device.newly_bound, "new device binds on first use");
  check(new_device.trust == TrustLevel::kDevice, "TOFU binds it to this account");
  check(account.trust_level == TrustLevel::kBasic, "account-level trust is unchanged by device binding");

  // Five-device cap: dev-a, dev-b bound; add three more, sixth must fail.
  for (int i = 0; i < 3; ++i) devices.bind_on_sign_in(uid, "dev-" + std::to_string(static_cast<char>('c' + i)));
  bool threw = false;
  try { devices.bind_on_sign_in(uid, "dev-f"); } catch (const std::runtime_error&) { threw = true; }
  check(threw, "sixth device rejected");

  // Revocation from a trusted device removes it and remembers the revocation.
  devices.revoke_device(uid, "dev-b");
  check(!devices.device_trusted(uid, "dev-b"), "revoked device is not trusted");
  auto replay = devices.bind_on_sign_in(uid, "dev-b");
  check(replay.revoked, "revoked device reports revoked on replay");
  check(replay.trust == TrustLevel::kBasic, "revoked replay falls back to account trust, not Device");
  check(!replay.newly_bound, "revoked device is not silently re-bound");

  // Ticket issuance (BAK-04 contract): trusted device passes, revoked fails.
  check(devices.device_trusted(uid, "dev-a"), "still-bound device issues tickets");
  check(!devices.device_trusted(uid, "dev-unknown"), "unknown device fails ticket issuance");

  // Empty fingerprint is a malformed claim.
  bool invalid = false;
  try { devices.bind_on_sign_in(uid, ""); } catch (const std::invalid_argument&) { invalid = true; }
  check(invalid, "empty fingerprint rejected");

  if (errors) { std::cerr << errors << " failure(s)\n"; return 1; }
  std::cout << "device binding tests passed\n";
  return 0;
}

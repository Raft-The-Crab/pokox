// IDN-04 acceptance: 5 login failures/hour per IP and per device block the
// 6th; impossible travel onto a new device triggers step-up and blocks
// sensitive actions until cleared; a known device after fast travel is fine.
#include "poko/identity/velocity.hpp"

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
  LoginVelocityService velocity(store, devices);

  auto account = sign_in.sign_in({"fb-uid-1", "a@b.c", "Alice"});
  const auto& uid = account.user_id;

  // Bind a home device so travel tests have a known baseline.
  devices.bind_on_sign_in(uid, "dev-home");
  // Seed the account's last known location (a normal sign-in from Berlin).
  auto seed = velocity.record({uid, "10.0.9.1", "dev-home", false, {52.52, 13.40}, 3000});
  check(seed.allowed && !seed.step_up_required, "baseline sign-in from a known device is unremarkable");

  // Five failures per hour per IP: the 6th attempt from that IP is blocked.
  for (int i = 0; i < 5; ++i) {
    auto v = velocity.record({"", "10.0.0.1", "dev-attacker", true, {0, 0}, 1000 + i});
    check(v.allowed, "failures 1-5 are recorded and allowed through");
  }
  auto blocked = velocity.record({"", "10.0.0.1", "dev-attacker", true, {0, 0}, 1010});
  check(!blocked.allowed, "6th failure from same IP is blocked");
  auto other_ip = velocity.record({"", "10.0.0.2", "dev-other", true, {0, 0}, 1011});
  check(other_ip.allowed, "a different IP is not blocked by the first IP's failures");

  // Failures age out after an hour: at t=4700 the IP is usable again.
  auto aged = velocity.record({"", "10.0.0.1", "dev-attacker", false, {0, 0}, 4700});
  check(aged.allowed, "failures age out after one hour");

  // Impossible travel onto a NEW device triggers step-up.
  auto berlin_to_sydney = velocity.record({uid, "10.1.0.1", "dev-new-1", false, {-33.87, 151.21}, 5000});
  check(berlin_to_sydney.allowed, "sign-in itself is allowed");
  check(berlin_to_sydney.step_up_required, "impossible travel to a new device requires step-up");
  bool refused = false;
  try { velocity.require_not_flagged("dev-new-1"); } catch (const std::runtime_error&) { refused = true; }
  check(refused, "sensitive action blocked while step-up pending");

  // Clearing the flag (after successful step-up) unblocks sensitive actions.
  velocity.clear_flag("dev-new-1");
  bool allowed_now = true;
  try { velocity.require_not_flagged("dev-new-1"); } catch (const std::runtime_error&) { allowed_now = false; }
  check(allowed_now, "sensitive action allowed after step-up clears the flag");

  // Known device after fast travel does not flag (bound devices travel).
  auto known = velocity.record({uid, "10.2.0.1", "dev-home", false, {-33.87, 151.21}, 9000});
  check(known.allowed && !known.step_up_required, "impossible travel to a known device does not trigger step-up");

  if (errors) { std::cerr << errors << " failure(s)\n"; return 1; }
  std::cout << "velocity tests passed\n";
  return 0;
}

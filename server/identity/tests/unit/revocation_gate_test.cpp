// BAK-04 acceptance: a revoked device fails within 5 minutes. Issue a
// ticket for a bound device, revoke that device, and both the next issuance
// and the validation of the already-issued ticket fail. Also covers the
// gate's fail-closed paths: unknown account, untrusted (never-bound) device,
// and a ledger view older than the 5-minute propagation bound. Revoked
// devices cannot be resurrected by replaying a binding.
#include "poko/identity/revocation_gate.hpp"
#include "poko/identity/sign_in.hpp" // InMemoryAccountStore

#include <iostream>

using namespace poko::identity;

namespace {
int errors = 0;
void check(bool ok, const char* what) {
  if (!ok) { ++errors; std::cerr << "FAIL: " << what << "\n"; }
}
} // namespace

int main() {
  InMemoryAccountStore store;
  SignInService sign_in(store);
  DeviceBindingService binding(store);
  SessionTickets tickets(1'700'000'000, [](int slot) {
    const std::string name = "key-slot-" + std::to_string(slot);
    return poko::net::hmac_sha256(std::vector<std::uint8_t>(name.begin(), name.end()),
                       reinterpret_cast<const std::uint8_t*>("session-ticket"), 14);
  });
  TicketIssuanceGate gate(binding, tickets);

  constexpr std::int64_t kT0 = 1'700'000'000;
  SessionTicket base;
  base.trust_level = TrustLevel::kDevice;
  base.roles = {{"player"}};
  base.nonce = 7;

  // Stale ledger view (never refreshed): fail closed before anything else.
  auto stale = gate.issue("nobody", "dev-A", base, kT0);
  check(!stale.issued && stale.reason == TicketIssuanceDecision::Reason::ledger_view_stale,
        "unrefreshed ledger view refuses issuance");

  gate.refresh_ledger(kT0);
  check(gate.issue("nobody", "dev-A", base, kT0).reason ==
            TicketIssuanceDecision::Reason::unknown_account,
        "unknown account refused");

  const std::string uid = sign_in.sign_in({"fb-uid-1", "a@b.c", "Alice"}).user_id;

  auto trust = binding.bind_on_sign_in(uid, "dev-A"); // TOFU bind
  check(trust.newly_bound, "device A bound at setup");

  auto ok = gate.issue(uid, "dev-A", base, kT0);
  check(ok.issued && ok.ticket.has_value(), "trusted device gets a ticket");
  check(ok.ticket && ok.ticket->user_id == uid && ok.ticket->device_id == "dev-A",
        "ticket carries user and device");
  check(ok.ticket && ok.ticket->expires_at == kT0 + SessionTickets::kTicketLifeSeconds,
        "ticket lives 30 minutes from issuance");
  const std::string token = tickets.issue(*ok.ticket);

  check(gate.validate(token, kT0 + 60), "issued ticket validates before revocation");

  // Revoke: from now on this device must fail within the 5-minute bound.
  binding.revoke_device(uid, "dev-A");
  gate.refresh_ledger(kT0 + 120); // replica sees the ledger change 2 minutes later

  auto reissue = gate.issue(uid, "dev-A", base, kT0 + 121);
  check(!reissue.issued && reissue.reason == TicketIssuanceDecision::Reason::device_revoked,
        "revoked device cannot get a new ticket");
  check(!gate.validate(token, kT0 + 121), "previously issued ticket dies at next validation");

  // Replay: a fresh binding attempt cannot resurrect the device.
  const auto replay = binding.bind_on_sign_in(uid, "dev-A");
  check(replay.revoked && !replay.newly_bound, "replayed binding reports revoked, does not bind");
  auto after_replay = gate.issue(uid, "dev-A", base, kT0 + 122);
  check(!after_replay.issued && after_replay.reason == TicketIssuanceDecision::Reason::device_revoked,
        "revoked device still refused after replay attempt");

  // A never-bound device is refused as untrusted, not revoked.
  auto stranger = gate.issue(uid, "dev-B", base, kT0 + 122);
  check(!stranger.issued && stranger.reason == TicketIssuanceDecision::Reason::device_not_trusted,
        "unbound device refused as not trusted");

  // The 5-minute bound: a ledger view 301 seconds old fails closed even
  // though nothing else changed; a fresh refresh restores issuance.
  auto old_view = gate.issue(uid, "dev-A", base, kT0 + 121 + 301);
  check(!old_view.issued && old_view.reason == TicketIssuanceDecision::Reason::ledger_view_stale,
        "ledger view older than 5 minutes refuses issuance");
  gate.refresh_ledger(kT0 + 121 + 301);
  auto revoked_now = gate.issue(uid, "dev-A", base, kT0 + 121 + 301);
  check(!revoked_now.issued && revoked_now.reason == TicketIssuanceDecision::Reason::device_revoked,
        "fresh view still refuses the revoked device itself");

  // Exactly at the bound (300 s) is still acceptable.
  gate.refresh_ledger(kT0);
  auto at_bound = gate.issue(uid, "dev-A", base, kT0 + 300);
  check(!at_bound.issued && at_bound.reason == TicketIssuanceDecision::Reason::device_revoked,
        "view at exactly 300 s is fresh enough to reach the revoked check");

  if (errors) { std::cerr << errors << " failure(s)\n"; return 1; }
  std::cout << "revocation gate tests passed\n";
  return 0;
}

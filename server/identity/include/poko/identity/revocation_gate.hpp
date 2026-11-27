// BAK-04: device revocation enforcement at ticket issuance (spec 17:
// "revoke from any device or recovery, enforced at ticket issuance within
// 5 minutes").
//
// IDN-02 stores the revocation state; BAK-04 is the gate that acts on it.
// TicketIssuanceGate::issue checks, in order: the account exists, the device
// is not revoked (hard fail — a replayed binding cannot resurrect it), the
// device is still in the account's trusted set, and the issuer's cached view
// of the revocation ledger is no older than kRevocationPropagationSeconds =
// 300 — the "within 5 minutes" bound. The cache models the real deployment,
// where each Worker instance sees ledger changes through its store replica;
// a replica that refetches the shared ledger stamps its view with
// refresh_ledger, and the gate refuses to issue on a view older than 5
// minutes rather than silently trusting a stale one.
//
// The 5-minute budget is a propagation bound, not a timer inside the gate:
// every check is on caller-supplied time, deterministic, like the rest of
// the platform.
#pragma once

#include "poko/identity/device_binding.hpp" // DeviceBindingService
#include "poko/identity/worker_auth.hpp"    // SessionTickets, SessionTicket

#include <cstdint>
#include <memory>
#include <mutex>
#include <optional>
#include <string>
#include <utility>

namespace poko::identity {

struct TicketIssuanceDecision {
  bool issued = false;
  std::optional<SessionTicket> ticket;
  enum class Reason : std::uint8_t {
    none,
    unknown_account,
    device_revoked,
    device_not_trusted,
    ledger_view_stale, // cannot prove the 5-minute bound; fail closed
  };
  Reason reason = Reason::none;
};

class TicketIssuanceGate {
public:
  // Spec 17: revocation enforced at ticket issuance within 5 minutes.
  static constexpr std::int64_t kRevocationPropagationSeconds = 300;

  TicketIssuanceGate(DeviceBindingService& binding, SessionTickets& tickets)
      : binding_(binding), tickets_(tickets) {}

  // A Worker replica calling through to the shared store so its view of
  // revocations is current; stamp the caller-supplied time it happened at.
  // The shared RevokedDeviceLedger lives in the binding service's
  // revoked-state pair, so one revoke is seen by every gate on the same
  // state (the deployed shared Postgres ledger).
  void refresh_ledger(std::int64_t now) {
    std::lock_guard<std::mutex> lock(state_->mutex);
    state_->last_refresh = now;
  }

  // Issue a session ticket for a user+device pair. Fails closed: any doubt
  // (unknown account, revoked device, untrusted device, stale ledger view)
  // means no ticket.
  [[nodiscard]] TicketIssuanceDecision issue(const std::string& user_id,
                                             const std::string& device_fingerprint,
                                             const SessionTicket& base, // trust_level/roles/nonce from here
                                             std::int64_t now) {
    TicketIssuanceDecision d;

    // Ledger freshness first: a stale view must fail closed, not pass.
    std::int64_t last_refresh;
    {
      std::lock_guard<std::mutex> lock(state_->mutex);
      last_refresh = state_->last_refresh;
    }
    if (last_refresh < 0 || now - last_refresh > kRevocationPropagationSeconds) {
      d.reason = TicketIssuanceDecision::Reason::ledger_view_stale;
      return d;
    }

    // Unknown account: no record, no ticket. bind_on_sign_in throws
    // runtime_error for an unknown account and invalid_argument for an
    // empty fingerprint — both refuse issuance, neither may escape.
    if (!binding_.device_trusted(user_id, device_fingerprint)) {
      try {
        binding_.bind_on_sign_in(user_id, device_fingerprint, /*trust_on_new_device=*/false);
      } catch (const std::exception&) {
        d.reason = TicketIssuanceDecision::Reason::unknown_account;
        return d;
      }
    }

    if (binding_.is_revoked(user_id, device_fingerprint)) {
      d.reason = TicketIssuanceDecision::Reason::device_revoked;
      return d;
    }
    if (!binding_.device_trusted(user_id, device_fingerprint)) {
      d.reason = TicketIssuanceDecision::Reason::device_not_trusted;
      return d;
    }

    SessionTicket t = base;
    t.user_id = user_id;
    t.device_id = device_fingerprint;
    t.issued_at = now;
    t.expires_at = now + SessionTickets::kTicketLifeSeconds;
    d.ticket = t;
    d.issued = true;
    return d;
  }

  // The other half of the path: verify an already-issued ticket and refuse
  // it if the device was revoked after issuance. A revoked device fails
  // within 5 minutes of the revocation landing in the shared ledger because
  // every verify consults it through the same refreshed state.
  [[nodiscard]] bool validate(const std::string& token, std::int64_t now) {
    auto v = tickets_.verify(token, now);
    if (!v.ticket) return false;
    if (binding_.is_revoked(v.ticket->user_id, v.ticket->device_id)) return false;
    if (!binding_.device_trusted(v.ticket->user_id, v.ticket->device_id)) return false;
    return true;
  }

private:
  struct LedgerView {
    std::int64_t last_refresh = -1;
    std::mutex mutex;
  };
  std::shared_ptr<LedgerView> state_ = std::make_shared<LedgerView>();
  DeviceBindingService& binding_;
  SessionTickets& tickets_;
};

} // namespace poko::identity

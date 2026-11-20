> **DRAFT — NEEDS COUNSEL REVIEW.** LEG-03 data map. See `docs/plan/20-legal-privacy.md`.

# Data map (LEG-03)

One source of truth per fact. Redis is reconstructible at any time; balances live only in Postgres.

| Data | Store | Retention | Rights |
|---|---|---|---|
| Identity, email, phone | Firebase and Postgres | Account life + 30 d | Access, correct, delete |
| Ledger entries | Postgres | Permanent, pseudonymised on deletion | Export; no erasure (conservation) |
| Device fingerprints | Postgres | 90 d after revocation | Delete on request |
| Replay rings | R2 | 30 d | Delete unless case evidence |
| Cases and audit | Postgres | Permanent | Appeal, redact PII |
| Chat | Postgres/Firestore | 30 d | Delete on request |
| Telemetry | Minimal, local to Sentry | 90 d | Opt-in, no ad profiling |
| `.pk` mirrors | GitHub | Account life | Delete on request |
| Release manifests and word registry | D1 | Permanent | Public; no PII |
| `.pkx` chunks | R2 | Life of published release | Takedown removes pointers |
| Rate limits, queues, wake locks | Valkey | Minutes to hours | Reconstructible; no rights request needed |
| Mute Library semantic index | Qdrant | Account life | Delete on request |

## Colour by plane

- **Control plane:** identity, entitlement, inventory, market, reports, chat. TCP/TLS through Workers.
- **Game plane:** input and snapshots. UDP/QUIC with uWS binary fallback. No ledger or chat content.
- **Moderation view:** Firestore live rows, D1 manifests, R2 replay blobs, Postgres cases. Read-only over existing truth.

## Privacy controls already in the architecture

Keystore-only tokens; no wall clock in sim; replay rings exclude inventory and economy fields; moderator identity hidden; no ad tracking; minimal opt-in telemetry; server-side age gates.

## Deletion behaviour

PII is scrubbed after 30 days. Ledger rows remain under a hashed user id so conservation can still be proven. The privacy policy must state this explicitly.

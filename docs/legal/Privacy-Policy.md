> **DRAFT — NEEDS COUNSEL REVIEW.** Not legal advice. See `docs/plan/20-legal-privacy.md` for the data map and pre-launch gates.

# Privacy Policy (draft)

## 1. What we collect

| Data | Store | Retention | Rights |
|---|---|---|---|
| Identity, email, phone | Firebase and Postgres | Account life + 30 days | Access, correct, delete |
| Ledger entries | Postgres | Permanent, pseudonymised on deletion | Export; no erasure (conservation) |
| Device fingerprints | Postgres | 90 days after revocation | Delete on request |
| Replay rings | R2 | 30 days | Delete unless case evidence |
| Cases and audit | Postgres | Permanent | Appeal, redact PII |
| Chat | Postgres/Firestore | 30 days | Delete on request |
| Telemetry | Minimal, local to Sentry | 90 days | Opt-in; disabled for minors and guests |

## 2. Lawful basis and regimes

GDPR/UK GDPR: lawful basis, data subject requests, 72-hour breach notice, processor DPAs and SCCs for transfers. CCPA/CPRA: notice at collection, opt-out, deletion; no sale of data. COPPA: under-13 parental consent and no profiling. PIPL: separate consent, localization and documented cross-border transfers.

## 3. Privacy by design already in the architecture

- Refresh tokens live only in the OS keystore (Windows Credential Manager, Android Keystore).
- No wall clock is reachable from Mute simulation code.
- Replay rings exclude inventory and economy fields.
- Moderator identity is hidden; notices use reason codes.
- No ad tracking. Telemetry is opt-in and contains no positional history or chat content.
- Age and other sensitive gates are enforced server-side.

## 4. Deletion

Deletion scrubs personally identifiable information after 30 days but retains ledger rows under a hashed user id. This preserves conservation and must be stated plainly so it is not a surprise.

## 5. Vendors

Every vendor requires a processor agreement with an explicit status (LEG-02). Transfers use SCCs where applicable.

## Open questions for counsel

- DPIA before launch.
- Whether hashed ledger identifiers qualify as pseudonymised under applicable law.
- Counsel sign-off is a hard gate before this policy ships.

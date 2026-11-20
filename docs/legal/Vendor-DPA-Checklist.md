> **DRAFT — NEEDS COUNSEL REVIEW.** Status tracking for LEG-02. See `docs/plan/20-legal-privacy.md`.

# Vendor DPA checklist (LEG-02)

Rule: every vendor that processes personal data has an explicit status. No vendor ships until its status is `signed` or `not-applicable` with a written reason.

| Vendor | Role in PokoX | Data involved | DPA status | Transfer mechanism | Owner |
|---|---|---|---|---|---|
| Aiven | PostgreSQL (ledger, identity, cases, audit) | Identity, ledger, PII | needs counsel | SCCs if transferred outside EEA | — |
| Cloudflare | Workers, D1, R2, edge cache | Release manifests, slot registry, replay blobs | needs counsel | SCCs | — |
| Google Firebase | Auth, Firestore | Identity tokens, live presence, reports | needs counsel | SCCs | — |
| Hugging Face | Authority and platform Spaces | Session state in memory only | needs counsel | Review terms for PII | — |
| GitHub | Source mirror, releases | `.pk` source with contributor PII | needs counsel | SCCs | — |
| Upstash | Valkey-compatible cache | Rate limits, presence, queue scores | needs counsel | SCCs | — |
| Qdrant Cloud | Vector search | Mute Library semantic index | needs counsel | SCCs | — |
| Cloudinary | Storefront image/video transforms | Public media | needs counsel | SCCs | — |
| Sentry | Release errors only, opt-in | Error events, no chat or tokens | needs counsel | SCCs | — |
| Notion | Project planning record | No end-user data | not-applicable (internal planning) | — | — |

## Required evidence per vendor

1. Signed DPA or written not-applicable reason.
2. Sub-processor list and notification terms.
3. Retention and deletion commitments.
4. Transfer mechanism (SCCs or adequacy).
5. Breach notification clock compatible with the 72-hour GDPR obligation.

## Gate

LEG-02 is incomplete until every row is `signed` or `not-applicable`. Counsel review is required before launch.

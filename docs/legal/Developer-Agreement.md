> **DRAFT — NEEDS COUNSEL REVIEW.** Not legal advice. See `docs/plan/08-publishing-and-versions.md`, `18-contributors.md` and `20-legal-privacy.md`.

# Developer Agreement (draft)

## 1. Developer role

Developer status requires a verified account, a registered developer key and a 24-hour cooldown before the first publish. The developer retains copyright in their game, source and assets.

## 2. Licence to PokoX

The developer grants PokoX a perpetual, royalty-free licence to host, store, reproduce, transmit and display the submitted package and its metadata for operating the platform. This licence ends on takedown subject to the published refund and audit rules.

## 3. Publishing obligations

- Submit only content the developer has the right to distribute.
- Declare capabilities, field policies and migrations honestly.
- Do not mark protected domains as `Trusted`; the platform forces them to `ServerOwned`.
- Pass determinism lint, capability audit, signature checks and the sandbox run.
- Declare `activityMode: "varied"` for clicker games.

## 4. Review and distribution

Review tiers run from automated Tier 0 to senior moderator Tier 3. BYO servers must run the signed validator image and accept scoped tokens. Donated nodes are untrusted hardware with no access to ledger, identity, moderation or audit data.

## 5. Economy terms

Developers receive the full play payout (5 Pokoins per 2 minutes of verified active play). Dividends come only from the 15% tax pool of that game's asset sales and share trades. Pokoins are virtual and are the developer's own tax responsibility; no employment or payroll relationship is created.

## 6. Takedown and removal

A takedown moves the live pointer, writes an audit event and preserves the ledger. Share holders are refunded according to the published rules.

## Open questions for counsel

- CLA/DCO interaction with this agreement.
- Tax treatment of developer Pokoins.
- Counsel review is required before donors or the Exchange ship.

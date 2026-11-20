> **DRAFT — NEEDS COUNSEL REVIEW. HIGH RISK.** Not legal advice. See `docs/plan/09-economy.md` and `00-decision-log.md`.

# Virtual Currency and Refund Terms (draft)

## 1. Nature of Pokoins

Pokoins are virtual units used only inside PokoX. They have no cash value, cannot be bought with money, cannot be sold for money, and are non-transferable outside PokoX. Poko Bakery uses Buns, which never become Pokoins.

## 2. Ledger authority

The double-entry ledger is the source of truth. Balances are derived and materialised balances are a rebuildable cache. Lost, erased or client-reported balances are not restored outside a published reversal process. Deletion keeps ledger rows under a hashed user id.

## 3. Grants and payouts

Weekly grant: 1,500 × R per user per week, where R is clamped to 0.5–1.5 and published every Monday with all inputs. Play payout: the full 5 Pokoins per 2 minutes of verified active play goes to the developer. Supply is capped at 100,000,000 Pokoins.

## 4. Activity proof

A 16-byte challenge is issued every 30 seconds; at least 3 of 4 must pass per 2-minute bucket. Clicker games declare `activityMode: "varied"`; raw click count is never activity proof. Stationary or bot-driven play earns zero.

## 5. Transfers and holds

There is no peer-to-peer transfer of Pokoins. Transactions have a 7-day hold where applicable and at most 1,000 transactions per user per day. Sinks and taxes go to the void account.

## 6. Refunds

Refunds occur only under the published rules: takedown with market refunds, reversed moderation decisions, or delisting refunds. A reversal is a new balanced transaction, never a mutation of history. No general cash refunds exist because no money was paid.

## 7. Developer responsibility

Developer Pokoins are the developer's own tax responsibility. No employment or payroll relationship is created.

## Open questions for counsel

- Money-transmission and securities exposure.
- Whether the refund rules are adequate for consumer-protection regimes.
- Counsel review is a hard gate before this policy ships.

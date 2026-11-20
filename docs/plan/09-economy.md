# 09 — Economy and Exchange

## Ledger invariant

Every Pokoins is in an account or the void, and every movement is a balanced pair of ledger rows. Balances are derived; materialized balances are a cache rebuildable from the ledger.

```sql
entries(id, tx_id, account, account_type, delta:int64, currency,
        idem_key, created_at, meta)
```

Account types: player, developer, system, void, escrow. For every tx_id, sum(delta)=0. `void` receives the 15% tax and sink burns, making conservation provable.

## Transaction types

| Tx | Debit | Credit |
|---|---|---|
| weekly_grant | system:mint | player, amount 1500 x R |
| play_payout | system:mint | developer, full 5 per 2 min |
| dividend | game 15% tax pool | shareholders, pro-rata |
| asset_buy | player | developer 85% + void 15% |
| share_buy | player | escrow or seller |
| share_sell | seller | player 85% + void 15% |
| share_refund | system:treasury | player |
| server_rent | player/developer | void |
| task_reward | system:mint | player |

FIX F1: dividends come only from the 15% tax pool of that game's asset sales and share trades. Play payouts stay whole with the developer.

## Idempotency

`idem_key` derived from the source event: `weekly_grant:<user>:<isoWeek>`, `play_payout:<session>:<bucket>`, `asset_buy:<orderId>`. Unique index prevents double-credit on retry. Transactions append in one Postgres commit with materialized balance updates. Redis is a read-through cache with 5 s TTL, invalidated on write. Hourly reconcile sums entries and compares to balances.

## Activity proof

1. Authority issues a 16-byte challenge every 30 s
2. Client responds within 20 s with signed input entropy: hashed movement deltas, chat, UI clicks with timestamps
3. Entropy scored by distinct input kinds, timing variance and displacement
4. Payout credited per 2 min bucket only if at least 3 of 4 challenges pass
5. `payout_bucket` row records score and challenge ids for moderation

FIX F2: clicker games declare `activityMode: "varied"`; raw click count is not proof. FIX F8: click events are `Validated` with a server-side sequence counter.

## Dynamic rate

```
velocity  = PokoinsSpent_7d / PokoinsMinted_7d        target 0.25
gini      = Gini(all player balances)                 target 0.55
sinkShare = PokoinsToVoid_7d / PokoinsMinted_7d       target 0.60

raw = 1 + 0.4*(0.25-velocity) - 0.3*(gini-0.55)
          - 0.3*max(0, 0.6-sinkShare)
R = clamp(0.5, 1.5, raw)
```

Computed Mondays 00:00 UTC, rounded to 3 decimals, written to D1 as a weekly constant, published in-game with all inputs for audit. Applies to the following week's grants and payouts. Hard supply cap 100,000,000: near cap R forced to 0.5 and sinks discounted 10%.

## Exchange

Share ledger mirrors the Pokoins ledger: `share_entries(id, tx_id, game_id, account, delta, price, idem_key, created_at)`. The Exchange moves Pokoins to escrow and credits shares in the same transaction. Client never reports share counts.

| Rule | Value |
|---|---|
| Listing | Game >= 30 days, >= 500 active users, >= 1,000 CCU-hours, clean record |
| Supply | 10,000 shares/game; developer keeps 20% locked 180 days |
| Pricing | `P(s) = 2 * (1 + s/4000)^2` Pokoins |
| Tax | 15% seller-side |
| Dividend | Weekly from 15% tax pool, pro-rata |
| Perks | 10 badge, 100 cosmetic, 500 title, 1,000 shareholder server, 2,500 quarterly vote |
| Index | Poko 20, cap-weighted |
| Delisting | Offline 90 days, refund last price minus 15% |
| Circuit breaker | +/-10% per 24 h on secondary trades |
| Position cap | 5% per game, 20 games, 10,000 Pokoins/game |
| Lock-up | 7 days user, 180 days developer |

v1 is bonding curve only; order book v2 after manipulation data exists. No leverage, shorting, real money or cash-out. The words "support a game" are used, never "invest". The Exchange is 18+ gated pending counsel review.

## Tasks

Server-defined quests with completion proof from authority-emitted event ids. Max 3 claimable/day, idem-keyed, counted as minted for R.

## Fraud detection

Identical input hash across accounts, young accounts with max payouts, shared device fingerprints, 5-sigma balance velocity, self-trading, wash trades. Each creates a case in Poko Mod; no auto-ban from a single signal.

## API

`GET /wallet/:userId`, `/wallet/:userId/export`, `/economy/r`, `/market/positions/:userId`, `POST /market/order`, `GET /ledger/verify/:txId`. Reads cached 60 s at edge; writes through Worker to Postgres with idempotency.

## Limits

100,000,000 supply, 1,500 x R weekly, 5,000 payout/day, 7-day hold, 1,000 transactions/user/day, permanent ledger, R Mondays, 30 s challenge, 5% share position.

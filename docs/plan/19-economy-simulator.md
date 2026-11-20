# 19 — Economy simulator

## Contract

An ImGui panel in Studio backed by a deterministic C++ core sharing the same ledger and rate code as production, compiled into a library both use. It never calls Firebase, Postgres or R2. A scenario is a seed plus parameters; the same seed always produces identical results, so tuning changes can be A/B compared exactly.

Why it matters: R has feedback loops. Lowering grants reduces minting, which raises R next week, which raises grants. Without simulation you cannot distinguish stability from a two-week oscillation.

## Agents

| Agent | Behavior | Knobs |
|---|---|---|
| Casual player | Weekly grant, occasional play, cheap buys | Activity, spend |
| Active player | Daily play, tasks, buys and sells | Frequency, completion |
| Developer | Payouts, asset sales, share listing | Quality, player draw |
| Trader | Bonding-curve trades, watches R | Risk appetite, momentum |
| Farmer | Bots and alts | Farm size, evasion skill |
| Whale | Concentrates Pokoins and shares | Starting balance, strategy |
| Sinker | Heavy cosmetics and server spending | Spend rate |

## Scenario

```cbor
{
  "seed": 0xC0FFEE, "weeks": 52,
  "agents": { "casual": 1000, "active": 200, "developer": 30,
              "trader": 40, "farmer": 15, "whale": 3, "sinker": 25 },
  "rules": { "weeklyGrant": 1500, "payoutPer2Min": 5, "tax": 0.15,
             "supplyCap": 100000000, "antiFarmStrength": 0.8,
             "marketCircuitBreaker": 0.10 },
  "events": [
    { "week": 12, "type": "viralGame", "magnitude": 1.5 },
    { "week": 30, "type": "farmWave", "magnitude": 2.0 }
  ]
}
```

## Simulated week

1. Agent actions in deterministic order by agent id
2. Every transaction through the ledger library with idem keys
3. Caps, holds and anti-farm checks use production code
4. Compute velocity, gini, sinkShare from the ledger
5. Run the same R formula, clamp to 0.5–1.5
6. Snapshot circulating supply, per-type balances, prices and flags

Agents act on current R — traders buy when R is low, farmers scale when grants rise — closing the feedback loop.

## Analysis output

| Metric | Healthy | Alarm |
|---|---|---|
| R over 52 weeks | 0.8–1.2 | Clamp boundary 3+ weeks |
| Circulating supply | Headroom | Within 10% of cap |
| Velocity | Near 0.25 | Below 0.15 or above 0.4 |
| Gini | Near 0.55 | Above 0.7 or below 0.35 |
| Top 1% holdings | < 20% | Above 30% |
| Farm flags per 1,000 agents | < 5 | Above 20 |
| Dividend accuracy | Exact floor(revenue x 0.5) | Any mismatch |
| Ledger conservation | Zero sum always | Any nonzero tx |
| Price swings | Within +/-10%/week | Breaker trips >3 times |

ImGui shows a line chart per metric with the healthy band shaded and a table of failed invariants. A scenario passes or lists exactly which weeks broke which rule.

## Tuning loop

Load a baseline scenario; adjust one parameter; re-run and compare; if alarms clear without new ones, stage the change; add the scenario as a CI golden test so future changes cannot reintroduce the problem. Every economy parameter change must have a before/after scenario committed.

## Tests

Same seed gives byte-identical 52-week output; conservation on every simulated tx; R bounded across 1,000 seeds; farmer agents generate flags; supply returns to band within 8 weeks after a viral game; near cap R clamps; three golden scenarios pass in CI.

## Gate

If the simulator does not use production code it is decoration (SIM-01). If golden scenarios are not in CI, tuning regressions return silently (SIM-07). Both are hard gates before any economy parameter ships.

## Honest limit

A simulator models only behavior you thought to encode. A novel exploit or cultural shift will not appear in any scenario. It reduces self-inflicted economic bugs; it cannot predict player creativity.

# 05 — pkB validation contract

## Purpose

`.pkB` is a declarative contract, not a program. The authority never executes Mute bytecode or game physics. It runs one fixed validator binary that interprets any `.pkB`. Because the authority cannot compute a full-state hash without simulating, it compares a **projected state hash** over only the fields governed by declarative rules.

## Binary layout

Canonical CBOR so the same contract yields identical bytes. Ed25519 signature covers everything except the signature field.

| Section | Contents |
|---|---|
| header | magic PKB1, format version, game id, source `.pk` CID, compiler version |
| identity | game id, word, authority hints, developer pubkey |
| types | Every replicated field: id, name, type tag, bit width, quantization range, delta policy |
| policy | Per-field authority policy |
| rules | Declarative rule expressions |
| caps | Capability mask required by game and per-function masks |
| hostcalls | Allowed hostcall ids with typed signatures |
| migrate | State migrations keyed by word pair |
| hash | Bytecode hash, projected-state field list, hash seed |
| limits | Platform ceilings |
| sig | Developer signature and registry signature |

## Field encoding

```cbor
{
  id: 42,
  name: "player.velocity",
  type: "vec3<f32>",
  encoding: {
    x: { bits: 12, min: -40.0, max: 40.0, mode: "quantized" },
    y: { bits: 12, min: -40.0, max: 40.0, mode: "quantized" },
    z: { bits: 12, min: -40.0, max: 40.0, mode: "quantized" }
  },
  delta: "against_last_ack",
  policy: "Validated",
  rate: { maxPerSecond: 30, burst: 2 }
}
```

Integers declare bits; floats declare bits, min, max with uniform quantization; enums declare ordinal width; strings declare maxBytes; arrays declare maxLen. A value outside its declared width is a compile error, never a silent clamp. BitBuffer and `.pkB` share this table.

## Authority policy

| Policy | Meaning | Use |
|---|---|---|
| `ServerOwned` | Authority only; client bits discarded | Balance, inventory, shares, rank, damage |
| `Validated` | Client proposes, authority recomputes from `previous()` | Position, velocity, aim, animation, click events |
| `Trusted` | No check | Cosmetics, camera, local effects |
| `Derived` | Computed by validator | `speed = length(velocity)` |

Protected domains are forced to `ServerOwned` and the override is recorded in `.pkB`: Pokoins, assets, shares, moderation, identity. A developer cannot mark their balance field `Trusted`.

## Rule language

Expression-only, no loops, allocation, hostcalls or function definitions. Fixed evaluation cost.

```
rule "velocity_cap" on player.velocity {
  let s = length(value)
  assert s <= 12.0 + 0.5
  assert value.y >= -40.0
}
rule "position_step" on player.position {
  let prev = previous(player.position)
  assert distance(value, prev) <= 12.0 * dt + 0.25
}
rule "cooldown" on player.fire {
  assert tick - previous(player.lastFire) >= 12
}
rule "monotonic" on player.score {
  assert value >= previous(player.score)
}
```

Operators: arithmetic, comparison, length, distance, dot, clamp, abs, min, max, previous, grantedThisTick, tick, dt. Nothing else.

## Clicker class rule (FIX F2, F8)

Clicker games declare `activityMode: "varied"` in `.pkB`. Raw click count is not activity proof; varied interaction — menu navigation, chat, purchase decisions — is required. Click events are `Validated` with a server-side sequence counter, never `Trusted`.

## Sequence and replay

Every packet carries `seq:u32`, `ack:u32`, session nonce. Reject `seq <= lastAccepted`, `seq > lastAccepted + 8`, stale `ack`, bad HMAC. Sliding window 64 ticks; Redis stores the last 64 projected hashes.

## Projected state hash

1. Collect fields with policy `ServerOwned`, `Validated` or `Derived`
2. Serialize in ascending field id order from `.pkB`
3. Pack with declared bit widths, no padding
4. Prepend tick, session nonce, ack
5. xxHash64 with seed from `.pkB`
6. Compare client hash to authority hash. Mismatch is trap `0x0D`, returns generic rejection, increments suspicion without revealing the field.

## Migration

```cbor
migrate: {
  "WobblyMango -> SecretV1?": {
    added: [ { field: "player.shield", default: 0, owned: true } ],
    removed: [ "player.oldStamina" ],
    renamed: [ { from: "player.hp", to: "player.health" } ],
    transform: "pure expression only"
  }
}
```

Field added without a default is a publish error. Removing a `ServerOwned` field requires an explicit deleted ledger entry. Migrations apply in registry order. A hotfix uses the `revision` byte and does not change the word.

## Anti-cheat coverage

| Cheat | Caught |
|---|---|
| Teleport, speed hacking, item duping, Pokoins inflation, score inflation, cooldown bypass | Yes |
| Aim assist | Partial — bounded direction changes, behavioral layer needed |
| Wallhack | No — rendering layer, needs behavioral review |
| Botting | Partial — input entropy and clustering |

## Penalty model

Hash mismatch +1, rule violation +2, sequence violation +3, capability violation +5. At 10 forced resync; at 25 suspended session and report; at 50 account review. No instant bans.

## Integration points

Mute compiler emits `.pkB` in pass 12. BitBuffer reads the same table. Studio Trust Inspector colors fields by policy. Poko Mod reads replay rings with `.pkB`. Exchange relies on forced `ServerOwned` share positions.

## Limits

2,048 fields, 512 rules, expression depth 32, 1,000 VM-equivalent instructions per rule evaluation per tick, 32 migrations in chain, 2 MB `.pkB`, 64-tick replay window.

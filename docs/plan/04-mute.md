# 04 — Mute language and VM

## Goals

Typed by default, one source for two runtimes, networking and UI as language features, deterministic or it does not ship, sandboxed by construction. No nil ambiguity, no separate client/server code paths.

## Types

| Category | Types |
|---|---|
| Scalars | `bool`, `i8/i16/i32/i64`, `u8/u16/u32/u64`, `f32`, `f64`, `string` |
| Composites | `array<T>`, `map<K,V>`, tuple, `struct`, `enum`, `option<T>`, `result<T,E>` |
| Engine | `vec2/3/4`, `mat4`, `quat`, `entity`, `asset<T>`, `ui.Node`, `body` |
| Special | `Unit`, `Never`, capability tokens (`Net`, `Physics`, `Storage`, `Ui`) |

Absence is `option<T>` with `some(x)`/`none`. Errors are `result<T,E>` with `ok`/`err` and `?` propagation. `let` immutable, `var` mutable. All generic parameters invariant. `map<K,V>` is an ordered B-tree, never a hash map. No `nil`, no subtyping except `never <: T`, no implicit numeric conversion.

## Syntax

```
package "com.poko.hub" version "SecretV1?"
allow: net, ui, storage, asset
import "pkg://poko/ui@WobblyMango" as ui

struct Item { id: u32, name: string, price: u32 }
enum ShopError { Insufficient, SoldOut, InvalidId }

@state var balance: u32 = 1500
@state var items: array<Item> = []

@on(BuyPressed) fn buy(id: u32) -> result<Unit, ShopError> {
  let item = market.lookup(id).ok_or(InvalidId)?
  guard balance >= item.price else { return err(Insufficient) }
  balance -= item.price
  items.push(item)
  ui.toast("Bought {item.name}")
  return ok(())
}

@every(0.1) fn refresh() {
  ui.bind("balance", balance)
  @replicate(balance, Target.Others)
}

async fn fetchCatalog() -> result<Unit, NetError> {
  let catalog = await net.request("catalog/list")?
  for item in catalog { ui.list.add(item) }
  return ok(())
}
```

Control flow: `if`, `for..in`, `while`, `loop`, `match` with patterns, `guard`, `break`, `continue`, `return`. No `goto`. Concurrency: `async`, `await`, `spawn`, channels, message passing, no shared-memory races.

## Standard library

| Module | Surface |
|---|---|
| math | Deterministic sin/cos/sqrt/floor/round/clamp/lerp/powf, vec and mat ops, quat, seeded RNG xorshift128+ |
| net | `replicate`, `broadcast`, `request/respond`, `sequence`, `Target`, `Channel` |
| ui | `node`, `bind`, `toast`, `animate`, `list`, decorators |
| asset | `load`, `prefetch`, `release`, `metadata` |
| physics | `raycast`, `overlap`, `body`, impulses — routed to sim or visual by field policy |
| time | `tick()`, `dt()`, `simNow()`. **No wall clock in sim code** |
| crypto | `sha256`, `hmac`, `sign`, `verify` — fixed implementations |
| log | `debug/info/warn`, `debug` compiles away in release |
| storage | `get/set/delete`, namespaced `gameId:playerId:key` |
| collections | array and ordered-map methods, sorted iteration |

## Lexical rules

UTF-8 only, BOM rejected, CRLF normalized. Identifiers are Unicode XID_Start plus XID_Continue. Keywords reserved. Integers decimal/hex/bin/oct with suffixes, default `i32`. Floats require a digit after the dot, default `f64`, no implicit int-to-float. Strings UTF-8 with escapes and `{expr}` interpolation resolved at compile time. Comments `//`, `/* */` non-nesting, `///` doc.

Attributes: `@state @on @every @replicate @rpc @clientOnly @authorityOnly @validate @deprecated @doc`.

Operator precedence: postfix `. [] () ? await`; unary `! - + move`; `* / %`; `+ -`; `<< >>`; `&`; `^`; `|`; comparisons; equality; `&&`; `||`; ranges; assignment.

## Type system rules

Bidirectional inference; all `pub` signatures and `@state` explicit. Unsuffixed ints infer to any int type, never float. Traits with `impl` and the orphan rule: impl a local trait for a local type, never both foreign. Structs are values; `entity` and `asset<T>` are unforgeable capability handles. Cyclic by-value struct references rejected.

## Bytecode ISA

32-bit words: `opcode:8 | a:8 | b:8 | c:8`, three-address form, 256 registers per frame, max depth 64. Constant pool indexed by `c`; branches pack a signed 24-bit offset into `b|c`. Hostcall uses `a` for id, `b` for arg base, `c` for return.

| Range | Opcodes |
|---|---|
| 0x00–0x0F | add sub mul div mod neg fadd fsub fmul fdiv fneg imul iadd_ovf isub_ovf bitand bitor |
| 0x10–0x1F | bitxor bitnot shl shr ushr min max abs sqrt sin cos floor ceil round powi clamp |
| 0x20–0x2F | eq ne lt le gt ge flt fle jmp br_true br_false match_dispatch test_variant switch_i is_some is_ok |
| 0x30–0x3F | loadk mov load_global store_global getfield setfield getindex setindex new_array new_map new_struct new_enum len concat copy release |
| 0x40–0x4F | call tailcall ret ret_void call_host call_async await spawn yield resume closure_new closure_call assert panic nop halt |
| 0x50–0x5F | replicate broadcast ui_bind ui_toast ui_animate net_request net_respond emit subscribe entity_create entity_destroy entity_query physics_query storage_get storage_set log |
| 0x60–0x6F | ext_prefix loadk64 loadf64 budget_add capability_check hash_state promote to_weak trap_ext |

`ext_prefix` consumes the next word as an extended opcode. Disassembler prints names and interleaves source.

## Memory model

Register is a 64-bit cell. Scalars inline; aggregates are heap objects referenced by 64-bit handles. `r0` is a read-only zero register. Tick arena is a bump allocator for short-lived values, reset in O(1) at tick end. Anything reachable from `@state` at tick end is promoted to reference-counted heap. Cycles are impossible by the type rule. Entity handles are `{index:u32, generation:u32}` in one `u64`; stale generation raises trap `0x08`.

## Determinism contract

1. No wall clock, no environment access, no addresses in state.
2. Randomness is an explicit `rng:Rng` seeded by the authority.
3. Strict IEEE-754, round-to-nearest-even, no FMA contraction, no fast-math, SSE2 baseline.
4. Transcendental functions are fixed minimax polynomials in the runtime, never libm.
5. Cooperative async in FIFO spawn order.
6. At tick end, `@state` is serialized in declaration order and hashed with xxHash64 seed 0.
7. CI replays the same 10,000-tick log on Android arm64, Windows x64 and Linux x64. One mismatch blocks release.

## Compiler passes

Lex and parse -> name and capability resolution -> type and determinism checks -> lowering to SSA IR -> optimization -> emit bytecode and debug info -> generate `.pkB` -> verify. Pass 6 optimizations must preserve IEEE-754 and the state hash.

## Capabilities

`Net, Physics, Storage, Ui, Asset, Crypto, Log, Time, Replicate, Spawn`. Package `allow:` is the ceiling; each function may declare a narrower `requires(...)`. Tokens cannot be stored in `@state`, sent over the network or serialized into `.pkB`. Importing a package with broader capabilities than the importer is a compile error. `with(net.limit(10))` attenuates a capability.

## Traps

0x01 budget, 0x02 depth, 0x03 heap, 0x04 bounds, 0x05 divide zero, 0x06 conversion, 0x07 unwrap, 0x08 stale handle, 0x09 opcode, 0x0A hostcall id, 0x0B signature, 0x0C capability, 0x0D state hash, 0x0E replicate target, 0x0F cancellation, 0x10 arena.

## Limits

1M instructions/tick, 64 MB heap/script, 256 MB/game, depth 64, 256 registers/frame, 1,000 scripts/game, 50 dependencies, 1,000 hostcalls/tick.

## Mute Library

`mute.toml` manifest with name, semver-by-word, description, author, license, `muteVersion`, capabilities, dependencies, repository. `mute.lock` pins exact words and CIDs. One version per package per build. Publishing: manifest validation, capability audit, determinism lint, opcode budget, sandboxed 1,000-tick run, human review for sensitive capabilities, Ed25519 signature, registry entry. 85/15 revenue share through the ledger.

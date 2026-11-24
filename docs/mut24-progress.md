# MUT-24 — determinism and capability analysis (foundation)

Status: static analysis pass implemented and unit-tested locally; integration
into the compiler pipeline and hosted/target gates remain open.

## What was added

- `mute/include/poko/mute/determinism.hpp` and
  `mute/src/semantic/determinism.cpp`: `analyze_determinism` scans a parsed
  `DeclarationAst` and reports typed diagnostics with source positions.
- `mute/tests/unit/determinism_test.cpp` registered as CTest
  `mute_determinism_unit` (added to `poko_mute_semantic`).

## Rules enforced

- `allow:` capability names must be in the approved v1 set
  (Net, Physics, Storage, Ui, Asset, Crypto, Log, Time, Replicate, Spawn);
  unknown → `unknown_capability`, repeats → `duplicate_capability`.
- Capability tokens may not appear in `@state` types or initializer
  expressions → `capability_in_state`.
- Nondeterministic builtins are rejected with `nondeterministic_operation`
  when used inside `@state` (always) or outside it without the required
  declared capability: `now/time/clock/timestamp` need `Time`,
  `random/rand/uuid/guid` need `Crypto`, and `env/getenv/hostname/username/
  pid/addr` are unconditionally banned (seeded replay only, per MUT-13).
- Member-path spellings are matched on their last segment (`x.time()` counts
  as `time`).

## Coverage

- `allow` declarations, `@state` types and initializer expressions
  (`DeclarationAst::values()`), and all function bodies via iterative
  `StatementAst` traversal.

## Evidence

- Debug MSVC build clean; `mute_determinism_unit` passes (14 scenario
  groups: valid allows, unknown/duplicate capabilities, capability tokens in
  `@state` type and initializer, builtin bans with/without capabilities,
  unconditional bans).
- `tools/version` integration source list updated.

## Limits

- Analysis is syntactic: it does not yet prove a capability is actually
  *needed* (no `requires(...)` narrowing exists in the grammar) and does not
  cover `.pkB`/network serialization of capability tokens — those land with
  MUT-25–27 and MUT-36.
- Hostcall whitelisting is unchanged; this pass only gates source-level
  capability/determinism policy.
- No gate is accepted by this milestone; G1/G2 and platform gates unchanged.

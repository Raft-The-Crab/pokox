# MUT-22 — aggregate VM values and lifetimes (foundation)

Status: runtime foundation implemented and unit-tested locally; compiler/VM
integration and hosted/target gates remain open.

## What was added

- `mute/include/poko/mute/values.hpp` and `mute/src/vm/values.cpp`:
  `AggregateStore` owns aggregate VM values — `string` and `array` payloads
  behind bounded 32-bit handles, plus `integer`/`boolean` scalar `Value`s.
- `mute/tests/unit/values_test.cpp` registered as CTest `mute_values_unit`.

## Lifetime model

- All objects are reference counted. `make_array`/`set_index` increment child
  refs; `release`/`free_object` decrement recursively, so shared children
  survive until the last owner dies.
- `copy` is deep for strings and (recursively) arrays; scalars copy trivially.
- `reset_tick` frees every arena-resident object — the per-tick transient
  lifetime. `promote` moves a value and its aggregate children to the
  refcounted heap so `@state`-reachable values survive the tick boundary.
- Limits are configurable per store: max string bytes, max array length,
  max nesting depth, heap object count and heap bytes (defaults mirror the
  MUT-13 64 MiB script heap scale).

## Traps

Kind mismatches (`wrong_kind`), out-of-range or negative indices (`bounds`),
dead/foreign handles (`invalid_handle`), oversized inputs (`heap_exceeded`),
and nesting beyond `max_depth` (`depth_exceeded`) return `ValueError`
variants — no UB, no exceptions across the boundary.

## Evidence

- Debug MSVC build clean; `mute_values_unit` passes (creation, access,
  bounds traps, copy isolation, nested aggregates, refcounted release,
  promote/reset_tick survival, arena reclamation, limit enforcement,
  scalar pass-through).
- `tools/version` integration source list updated for the new files.

## Limits

- Not yet wired into `run_program`/the register VM or bytecode (MUT-26
  lowering); no Mute surface syntax for aggregates exists yet.
- Stale handles are detected by slot/kind check but slot reuse means a
  poisoned handle can alias a new object — acceptable for the trusted
  compiler path; untrusted bytecode must wait for MUT-27 verification.
- No gate is accepted by this milestone; G1/G2 and platform gates unchanged.

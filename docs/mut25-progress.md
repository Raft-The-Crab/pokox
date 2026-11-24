# MUT-25 — typed SSA IR (foundation)

Status: IR model and verifier implemented and unit-tested locally; AST→SSA
lowering and hosted/target gates remain open.

## What was added

- `mute/include/poko/mute/ssa.hpp` and `mute/src/semantic/ssa.cpp`:
  `IrModule`/`IrFunction`/`IrBlock`/`IrInstr` with typed `Type` payloads
  (reusing the MUT-19 `Type`/`TypeTag` model) and `verify()` returning typed
  `IrDiagnostic`s with function/block locations.
- `mute/tests/unit/ssa_test.cpp` registered as CTest `mute_ssa_unit`
  (part of `poko_mute_semantic`).

## IR model

- Value ids: params occupy 1..N; each non-terminator instruction may carry a
  unique `def` id; operands reference value ids (`0` = no value) plus an
  immediate payload for constants.
- Ops: `constant, copy, unary, binary, compare, phi, call, load, store,
  jump, branch, return_`. Terminators are `jump`/`branch`/`return_` and must
  be the last instruction of a block.
- `phi` takes `2 × predecessor_count` operands (value pairs per pred edge).

## Verifier checks (done-when)

- `empty_function`, `duplicate_label`, `unreachable_block` (reachability
  from block 0 via terminator targets).
- `missing_terminator`, `bad_terminator` (mid-block terminator, dangling
  jump/branch targets, predecessor-set mismatch vs actual edges).
- `type_mismatch` (return type vs function result, binary operand type
  disagreement, phi input unknown type, duplicate defs).
- `undefined_value` (operand id never defined — params and defs tracked in
  a `defined_ids` set, so gap ids are caught).
- `phi_arity` (operand count must equal 2 × predecessor count).
- `bad_operand_count` reserved for future arity tables.

## Audit fixes applied during verification

- Value defs are tracked in an explicit `defined_ids` set rather than
  inferring from vector size, so never-defined gap ids report
  `undefined_value` instead of aliasing `unknown` type.
- Binary operand type comparison now requires both operands to be defined.

## Evidence

- Debug MSVC build clean; `mute_ssa_unit` passes (valid module plus
  rejection of empty/missing-terminator/mid-block-terminator/undefined
  value/return-type/binary-type/phi-arity/duplicate-label/unreachable
  cases; deterministic `dump_ir`).
- Full Debug `mute_*` CTest: 33/33 pass. ASan `build-msvc-asan` `mute_*`
  suite run after this change.
- `tools/version` integration source list updated.

## Limits

- Dominance is approximated by layout order (def-before-use in block
  order), not a real dominator tree — conservative for the foundation;
  MUT-26 lowering must emit layout-consistent SSA or the verifier needs a
  dominator pass.
- Type checking is shallow (same_type equality, unknown detection); full
  trait/subtyping checks belong to lowering/verification milestones.
- No AST→SSA lowering exists yet; `IrModule` is currently only built by
  tests.
- No gate is accepted by this milestone; G1/G2 and platform gates unchanged.

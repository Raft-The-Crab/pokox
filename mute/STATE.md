# Initial Mute state and deterministic hash

MUT-11 implements a bounded **i32-only** state subset in the existing register program VM. A program may begin with up to 256 declarations, before its functions:

```mute
@state var count:i32=0;
@state var score:i32=-2;
fn tick()->i32 { count=count+1; score=score+count; return score; }
tick()
```

A declaration requires `@state var`, a unique identifier, explicit `i32`, a signed or unsigned integer **literal** initializer, and a semicolon. Initializers are checked for i32 type/range. Expressions, aggregates, floats, bool state, attributes beyond `@state`, and full Mute syntax are not supported. The existing language subset still requires at least one function and a final i32 expression. A local or parameter shadows the state field of the same name, and existing local mutability rules remain in force.

## Host API

Include `poko/mute/program.hpp`. Keep one host-owned `ProgramState` per program/session and call `run_stateful_program(source, state)` for each tick. The first successful call initializes fields then executes the program. Subsequent calls reuse the values. A call with invalid input, a trap, exhausted budget or schema mismatch leaves the original state unchanged. Allocation failures may throw; state is built separately and committed only after success. The host must not mutate the state or source concurrently. State schema comparison checks declaration count, names and order; no automatic migration or source-code identity is implied. Changing program code with the same schema preserves state, while a schema change requires an explicit reset or a future migration mechanism.

`run_stateful_program_bytecode(bytes, state)` applies the same semantics after `MUTP` source-backed snapshot validation. `run_program` and `run_program_bytecode` each use fresh state for their one call. The existing compiler/parser run on every tick; this is not a performance-optimized long-lived VM. Initialization/compilation, state copying, hashing and allocations are outside the VM semantic step budget, so this is not a sandbox quota.

`hash_state(state)` rejects uninitialized state, duplicate/empty names and more than 256 fields. It serializes each signed i32 as four little-endian two's-complement bytes in **declaration order** and computes xxHash64 with seed zero. Names, schema identity, tick number and session are not in this initial hash. It is not cryptographic, does not authenticate a client, and is **not** the projected authority hash described in `docs/plan/05-pkb-validation.md`. A separate experimental save/load codec is described in [STATE-SNAPSHOT.md](STATE-SNAPSHOT.md); cross-platform release acceptance remains an open gate.

The optional ImGui debug console retains state between submissions beginning with `@state`; repeat the same complete program to advance another tick. It displays the current hash and offers **Reset state**. Arithmetic, print and stateless `fn` programs do not affect the retained state. The lower-level `execute_console` function remains fresh per call; `execute_console_stateful` takes an explicit context.

## Validation

The unit suite checks independently generated xxHash vectors, declaration order and byte endianness, schema mismatches, local shadowing, recursive mutation, error/budget rollback, field limits, console behavior and source/snapshot parity for 10,000 ticks. `mute/tools/state_determinism_probe.cpp` prints 10,000 successive state hashes for cross-build comparisons. Emulated ARM is not a physical Android device and no local check substitutes for the full cross-platform 10,000-tick G1 replay.

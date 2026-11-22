# MUT-12 state snapshot, experimental v1

`poko/mute/state_snapshot.hpp` provides `save_state_snapshot(source, state)` and `load_state_snapshot(expected_source, bytes)` for the existing initialized **i32-only** `ProgramState`. Both return a C++20 variant containing a value or `SnapshotError`; allocation may throw. `offset` is a byte offset for malformed snapshot errors, the field index for a save-side schema mismatch, and zero for general source/state errors; it is not a source diagnostic. Inputs and state must not be modified concurrently. The caller owns storage, I/O errors, atomic file replacement, synchronization and lifecycle. Loading returns a new value and does not mutate the existing state; assign only after success.

```cpp
#include "poko/mute/state_snapshot.hpp"
// After a successful tick:
auto saved = poko::mute::save_state_snapshot(source, state);
// Persist the vector only if saved contains it. Later read it back as `bytes`.
auto loaded = poko::mute::load_state_snapshot(source, bytes);
if (auto* next = std::get_if<poko::mute::ProgramState>(&loaded)) state = std::move(*next);
```

The source must be valid for the current compiler and exactly byte-for-byte identical at restore. The schema, including name/order and i32 type, is derived by reparsing that source and must match at save; all source, including comments and whitespace, is part of identity. The state object itself carries **no provenance**: callers must supply the source that actually produced it. Same-schema source changes can be accepted by `run_stateful_program` and can be saved under a caller-supplied new source; this API does not prove history or perform migrations. Compiler/format upgrades may reject older snapshots or change execution semantics even when the same source still loads. Pin the compiler/runtime externally for replay; there is no version migration guarantee.

## MUTS v1 wire layout

All integers are unsigned little-endian, except value bytes represent signed i32 two's-complement. The layout is exactly:

| Offset | Content |
|---|---|
| 0 | ASCII `MUTS` (4 bytes) |
| 4 | version = 1 (u16) |
| 6 | reserved = 0 (u16) |
| 8 | source byte length (u32, at most 65,536) |
| 12 | field count (u16, at most 256) |
| 14 | exact UTF-8 source bytes |
| following source | i32 values in declaration order (4 bytes each) |
| last 8 bytes | xxHash64 seed 0 over all preceding bytes, encoded u64 LE |

Total limit is 66,582 bytes; no padding or trailing data. The field names and type are determined from the embedded/expected source, not independently stored. Truncation, unknown versions, nonzero reserved bits, oversized lengths, mismatched source/schema and incorrect checksum are rejected. The checksum is **non-cryptographic**, not authentication, tamper prevention, authority validation or a signature; a malicious party can recalculate it. Source and state can be sensitive, so hosts must protect stored files. The codec is not a sandbox and compiling/allocating is outside the semantic VM budget.

This is a snapshot, **not a complete replay log**: it contains no tick number, input events, hostcall results, RNG or external world state. The caller must record/replay those separately. `.pkB` remains a separate authority contract. Tests include binary temporary-file roundtrip, independent Python/xxHash golden, value extremes, zero/256 fields, Unicode, maximum source, corruption/truncation, forged checksums, schema/source mismatch, randomized invalid data, and continuing 10,000 ticks with periodic save/load. Cross-platform replay gates G1/G2 are not closed by these tests.

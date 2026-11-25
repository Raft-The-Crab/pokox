# Mute v1 standard API — host-side core

This document records the v1 API slices delivered by MUT-51–MUT-54. They are
host C++ libraries under `poko::mute`. They do not depend on SDL, engine
services, wall clocks, files, network or entropy. VM hostcall registration is
provided where the existing integer-only boundary can carry it; byte buffers
stay host-owned until VM registers can hold `Value`s.

## MUT-51 — math, time and RNG

Include `poko/mute/stdlib_math.hpp`.

- Scalars: `det_sqrt`, `det_floor`, `det_round`, `det_clamp`, `det_lerp`,
  `det_pow`, plus pinned `deterministic_sin`/`deterministic_cos`.
- Vectors: `Vec2`, `Vec3`, `Vec4` with add/sub/scale/cross/dot/length/lerp/
  normalize. Zero-length normalization returns `std::nullopt`.
- Matrices and quaternions: row-major `Mat4` identity/multiply/transform,
  `Quat` normalize/multiply/rotate.
- RNG: `XorShift128Plus` with splitmix64 seed expansion, `next_u64`,
  `next_i32`, serializable `state()` and `from_state()` for seeded replay.
- Time: `SimClock` exposes only `tick()`, `dt_q16()` and `sim_now()`, derived
  from integer ticks. `time_hostcall_defs()` registers ids 201–203 with the
  `Time` capability and `serializable=true`.

Wall-clock builtins (`now`, `time`, `clock`, `timestamp`) are rejected by the
determinism analyzer even when `Time` is declared. `tick`, `dt` and `simNow`
are the approved simulation-time surface.

## MUT-52 — strings and collections

Include `poko/mute/stdlib_string.hpp` and `poko/mute/stdlib_collections.hpp`.

- Strings are canonical UTF-8. Invalid UTF-8 never enters a validated result.
  Operations: validation, byte/codepoint counts, codepoint slicing, concat,
  bytewise compare, substring find and explicit ASCII lowercase. No locale,
  Unicode normalization or Unicode case folding exists in v1.
- `ByteArray` is bounded and bounds-checked.
- `OrderedStringMap` stores bytewise-sorted entries. Insert duplicates are
  rejected; iteration order and canonical `dump()` are independent of insert
  order. This is the host-side model for Mute's ordered map, not a hash map.

## MUT-53 — crypto

Include `poko/mute/stdlib_crypto.hpp`.

- `sha256`, `hmac_sha256`, `to_hex` and `from_hex`.
- `sign_detached`/`verify_detached` are an HMAC-SHA256 detached tag scheme over
  host-owned bytes with constant-time comparison. Asymmetric publisher
  signatures remain a backend concern and are not part of this sandbox API.
- `crypto_hostcall_defs()` registers ids 101–104 requiring `Crypto`.
  Byte buffers are host-owned because v1 registers are i32.

## MUT-54 — lifecycle and game events

Include `poko/mute/events.hpp`.

- `EventPhase`: `startup`, `simulation`, `teardown`.
- `EventBus` accepts tick-tagged `GameEvent`s with monotonic ticks and bounded
  queues. `dispatch(phase, up_to_tick)` delivers FIFO by `(tick, emit
  sequence)` and calls subscribers in ascending subscription id.
- `unsubscribe` and `clear_phase` provide deterministic teardown. `hash()`
  covers subscriptions and queued events for replay comparison.

## Deliberate deferrals

- No Mute-specific SDL/console/AGDK event adapter in these libraries.
- No VM string/byte-buffer hostcalls until registers can carry `Value`s.
- No registry, publishing or disk settings adapter.
- No gestures beyond tap, no soft-body physics, no wall-clock simulation time.

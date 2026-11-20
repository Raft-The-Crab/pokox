# 28 — Engine diagnostics

## Profiler

One profiler serves the engine, Mute VM, net stack and app shells. It records CPU scopes, GPU timestamps where supported, counters and events into a ring buffer of 1,000 frames. ImGui in dev builds and Studio's profiler panel read the same data.

| View | Contents |
|---|---|
| Frame timeline | CPU scopes and GPU passes aligned on one axis |
| Flame graph | Aggregated call tree over a selected frame range |
| Counters | Draw calls, triangles, instructions, hostcalls, allocations, packets |
| GPU passes | Per-pass timestamp and resource usage |
| Comparison | Before and after capture with a diff |

Captures are named and saved to `user://profiler/` as CBOR. A capture can be shared with a bug report. Recording overhead is under 0.5 ms in debug and the recorder is compiled out of release.

## Debug draw

`debug.line`, `debug.sphere`, `debug.aabb`, `debug.text`, `debug.polyline`, `debug.frustum`. Calls are queued per frame and drawn in a dedicated pass with no depth write by default. Mute exposes debug calls only in `@clientOnly` code. Debug draw does not compile into shipping builds unless `POKO_DEBUG_DRAW` is set.

Each subsystem registers its own toggle: colliders, contacts, broadphase pairs, nav or zone bounds, light volumes, shadow cascades, LOD bands, culling results, audio emitters, animation joints, replicated entities and network interest regions.

## Replay recorder

The recorder captures the deterministic input stream, packed state snapshots and state hashes for 64 live ticks, then flushes to R2 as compressed CBOR. It records the same fields the authority validates; cosmetics are excluded. A replay is content-addressed and signature-sealed so it can serve as moderation evidence. Playback runs the sim forward from a snapshot and asserts a matching hash at every tick. Any divergence is reported with the first differing tick and field.

Players can export 30-second highlight clips from the replay ring (ADD item). Exported clips are signed and served by signed URL; they cannot be edited without failing verification.

## Console

Backtick opens the in-engine console in dev builds. Commands are typed with autocomplete over commands, CVars and Mute symbols. A command returns structured output that the console renders as text, table or graph. The console is reachable over a local TCP socket so tests and Studio can drive it without UI automation.

Every command execution is logged with its arguments and result. Cheat-flagged commands are disabled in shipping. `POKO_DEBUG` controls availability.

## Crash handler

On crash the handler writes a minidump on Windows or a tombstone summary on Android, flushes the log ring, records the last 60 profiler frames and the last replay snapshot, and writes a `crash.cbor` to `user://crashes/`. On next launch a recovery dialog offers to send the report through the support endpoint. Reports never contain wallet tokens, Firebase tokens or raw player chat.

A deliberate assertion failure in debug writes the same report format, so the pipeline is tested without crashing the process.

## Logging

Structured logs with level, module, message, fields and tick. Levels: trace, debug, info, warn, error. Release keeps warn and error plus a ring of the last 1,000 info lines. Logs rotate by size and are retained 7 days. Sentry receives errors only in release and only with user consent. No PII in log fields; identifiers are hashed.

## Telemetry hooks

Minimal by design. The engine exposes counters that the client may report with consent: frame time distribution, crash counts, feature usage by name, and connection quality. No positional history, no chat content, no behavioral analytics. Telemetry is opt-in, documented in the privacy policy and disabled for minors and guests.

## Assertion policy

Assertions check internal invariants only: a resource created on the wrong thread, a query mutated during iteration, a scene cycle, a job without a declared dependency. External input is never handled by assertion — it goes through `Result` and a user-facing error. In release, a failed internal invariant logs an error and degrades; it does not crash a player's session.

## Studio integration

The profiler panel, console, replay viewer and crash report viewer are the same panels used in ImGui during development. Nothing is reimplemented for Studio; it consumes the same CBOR formats through host callbacks. This keeps dev and shipped behavior aligned and is why ImGui prototypes are considered real tooling, throwaway only in skin.

## Limits

1,000 profiler frames, 64 replay ticks live, 30-day replay retention, 7-day logs, 1,000 log-line ring, 256 concurrent debug draws, 10 MB crash report cap.

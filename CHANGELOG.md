# Changelog

All notable changes to PokoX are documented here. The format follows
[Keep a Changelog](https://keepachangelog.com/en/1.1.0/) and the project
has not made a versioned release yet; entries are grouped by task until
the first release tag exists.

## [Unreleased]

### Added

- Project scaffold: `engine/`, `client/`, `server/`, `backend/`, `mod/`,
  `mute/`, `studio/`, `applications/`, `tools/`, `assets/`, `docs/`
  (INF-01).
- CMake build foundation with `vcpkg.json` manifest (SDL3, ImGui, spdlog,
  Catch2), dependency-free default target, and opt-in flags
  `POKO_WITH_DEPENDENCIES`, `POKO_WITH_SDL_PLATFORM`,
  `POKO_WITH_VULKAN_DEMO`, `POKO_IMGUI`, `POKO_D3D12`, `POKO_DEBUG`
  (INF-02/INF-03).
- GitHub Actions CI for Windows MSVC and MSYS2 MinGW toolchains
  (INF-04, pending first green run).
- Byte-exact golden-file test harness under `tools/testutils/` (INF-05).
- Git-tag build version metadata; untagged builds report `unversioned`
  (INF-06).
- Backend-independent `IPlatform` single-window contract and test double
  (ENG-01).
- SDL3 window backend, `pokox_window_demo`, and platform fault-injection
  tests (ENG-02).
- Vulkan window intent, size queries, and borrowed SDL native-window
  access as ENG-03 prerequisites.
- Opt-in Diligent/Vulkan clear-color source candidate (`POKO_WITH_VULKAN_DEMO`)
  with desktop demo, diagnostics capture, and laptop evidence runner
  (ENG-03, in progress — not yet accepted).
- Legal document drafts under `docs/legal/` (LEG-01 drafts; counsel review
  required before ship).
- Planning specs under `docs/plan/` (31 documents).
- Character asset work: BlockyR6 and BoyR6 adapted `.blend`/`.glb` sources,
  animation v2 sets, and preservation-first prototypes under `assets/`.
- Identity module under `server/identity`: sign-in from a verified Firebase
  identity to an idempotent PokoX account record (IDN-01), device keypair
  TOFU binding with five-device cap and revocation (IDN-02), OTP
  step-up gating Device-trust actions (IDN-03), and session velocity /
  impossible-travel checks (IDN-04), with unit tests.
- Real-time game plane under `server/net` (spec 06): UDP echo with the
  1200-byte datagram cap (NET-01), BitBuffer bit packing (NET-02),
  frame header + truncated HMAC + replay window (NET-03), delta encoding
  with a resend window (NET-04), the two-cube demo (NET-05), XOR-FEC
  parity over groups of four (NET-06), RFC 6455 WebSocket binary-frame
  fallback (NET-07), an adaptive jitter buffer with integer interpolation
  and a 100 ms extrapolation cap (NET-08), and ChaCha20-Poly1305 AEAD
  (NET-09), each with an RFC-vector or behavior unit test.
- Canonical Postgres schema under `backend/storage/postgres/` (BAK-01):
  users, games, assets, the Pokoins ledger with a double-credit guard,
  derived balances, shares, cases and audit log, with an idempotent
  `migrate.sh` runner verified against real Postgres 18.6.
- Matchmaker allocation and tickets (BAK-09): the spec-07 pipeline — spec
  score ranking with affinity, five filter classes, the 20-CCU platform
  cap with donated/BYO fallback and Cold-slot wake — plus 30-second
  truncated-HMAC tickets (no player identity, fail-closed checks).
- Replay ring recorder (BAK-08): a bounded 64-tick ring of per-tick state
  hashes, rejected flags, field values and moderation event markers,
  encoded as deterministic CBOR in a zlib stream with in-tree fixed-
  Huffman DEFLATE; decodes byte-exact, refuses corrupted or truncated
  streams (Adler32-checked).
- Authority module under `server/authority` (spec 05): the in-memory
  per-session field authority with proposal/tick/snapshot semantics
  (BAK-02); .pkB schema arrival with projected-hash packing, out-of-width
  refusal and ServerOwned enforcement (BAK-05); the fixed-cost assert-rule
  evaluator with parse-time node/depth/rule caps, div-by-zero safety and
  both C-like and s-expr syntax (BAK-06); and the projected-state hash +
  sequence window with generic rejection, a 64-hash ring and the penalty
  model hash +1 / rule +2 / sequence +3, resync at 10 and suspend at 25
  (BAK-07) — each with a unit test.
- Device revocation enforcement (BAK-04): ticket issuance and validation
  fail closed for revoked devices within the 5-minute propagation bound,
  with stale ledger views refusing rather than passing, and replayed
  bindings unable to resurrect a revoked device.
- Worker auth (BAK-03): Firebase ID-token claim verification with every
  rejection path testable in-repo, and 30-minute Worker session tickets
  (HMAC-SHA256, 5-minute key rotation, six live key slots) so a game slot
  never sees a Firebase token.
- In-memory session authority (BAK-02): per-.pkB-policy proposal handling
  (ServerOwned discarded, Validated first-wins, Trusted unchecked but
  excluded from hashing, Derived authority-only) and a single committed
  snapshot with an xxHash64 projected state hash served identically to
  every client, so two clients always agree.

### Fixed

- `tools/version/cmake/generate_version.cmake`: pass `ENCODING NONE` to
  `git` subprocess calls so non-ASCII tag names and checkout paths are not
  corrupted by the Windows console codepage during `execute_process`
  output capture (found by `version_integration` on Windows).

### Changed

- `vcpkg.json`: `sdl3` now enables the `vulkan` feature, required for
  `SDL_WINDOW_VULKAN` and the ENG-03 clear demo.
- `CMakeLists.txt`: configure-time patch adds a missing `<cstdint>`
  include to the pinned DiligentCore glslang `SpvBuilder.h` (GCC 16
  compatibility).
- `pokox_vulkan_clear`: new `--adapter N` option and
  `ClearConfig::adapter_id` for explicit Vulkan physical-device selection.
- `.github/workflows/ci.yml`: MinGW job passes `-DMINGW_BUILD=TRUE` so
  Diligent skips its DXC/ATL path that MinGW cannot compile.

### Added (continued)

- `LICENSE` (proprietary, contributor no-copy/no-release terms),
  `CONTRIBUTING.md`, `CHANGELOG.md`, `CODE_OF_CONDUCT.md`, `SECURITY.md`,
  pull request template, and bug/feature issue templates.
- `docs/eng03-windows-laptop-evidence.txt`: first real Windows
  verification record.

### Notes

- Windows (MSVC and MSYS2) and Android acceptance checks are still open
  for INF-02/INF-04 and ENG-01/02/03; see `docs/build.md`,
  `docs/plan/02-work-queue.md`, and `docs/eng-progress.md`.
- The Vulkan clear demo is a source candidate verified against dependency
  doubles; real SDK compilation, GPU output, and validation-layer
  acceptance remain pending.

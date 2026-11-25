# 01 — Roadmap and gates

Nine phases in dependency order. Each phase has an exit gate. A failed gate stops work; it is never waved through.

## Phases

| Phase | Name | Contents | Exit gate |
|---|---|---|---|
| 0 | Contracts | Schemas, repos, CI, quota budget, conformance harnesses | All schemas versioned; CI green on empty project |
| 1 | Deterministic core | IPlatform, SDL3, Vulkan RHI, frame graph, Mute VM, deterministic math, fixed-point sim physics | **G1/G2**: identical traces on Windows x64 and physical Android arm64 (owner decision 2026-11-25; Linux is build/CI only) |
| 2 | Trust primitives | `.pkB`, rule evaluator, BitBuffer, frame/HMAC/seq, UDP + uWS, Firebase, TOFU | **G3/G4/G5**: invalid state rejected, replay dropped, new device needs step-up |
| 3 | Authoring | Studio shell, Mute debugger, UI maker, asset importer, KTX2/Basis | **G6/G7**: bindings compile-validated; KTX2 parity on Vulkan + GL/ES |
| 4 | Delivery | Client shell, patcher, cache, offline, handshake, Android lifecycle, localization basics | **G8/G9**: chunk integrity and resume; offline grants nothing |
| 5 | Economy and play | Ledger, faucets, sinks, R job, matchmaker, slots, replay rings | **G10/G11**: ledger conservation under load; CCU cannot race past 20 |
| 6 | Safety and publishing | Publish gates, signing, review tiers, updates, rollback, takedown, Poko Mod | **G12/G13**: gates unbypassable; audit immutable; two-vote actions |
| 7 | Platforms and extras | Exchange, Mute Library, full localization and a11y, AA/AAA features | **G14/G15**: dual ledgers atomic; tier fallback clean |
| 8 | Vertical slices and launch | Poko Bakery, Poko Playground, load tests, docs, ToS | **G16/G17**: Slice A 30 fps Android; Slice B 20 CCU with FEC recovery |

## Dependency map

| Phase | Depends on | Blocks |
|---|---|---|
| 0 | — | All |
| 1 | 0 | 2, 3, 4 |
| 2 | 1 | 4, 5, 6 |
| 3 | 1, 2 | 4, 8 |
| 4 | 1, 2, 3 | 5, 8 |
| 5 | 2, 4 | 6, 7 |
| 6 | 2, 5 | 8 |
| 7 | 5, 6 | 8 |
| 8 | All | Launch |

Phases 3 and 4 may overlap after Phase 2. Phases 6 and 7 may overlap after Phase 5. Everything else is ordered.

## Gate register

| Gate | Test | Consequence |
|---|---|---|
| G1 | 10,000-tick log produces byte-identical traces on Windows x64 and physical Android arm64 | Stop all development until fixed |
| G2 | Sim physics deterministic across Windows x64 and physical Android arm64 | No Slice B until fixed |
| G3 | Crafted invalid state always rejected | No network layer above it |
| G4 | Replayed packet always dropped | No game plane |
| G5 | New device cannot reach Device trust without step-up | No economy |
| G6 | Renaming Mute `@state` breaks UI build | No shipped game UIs |
| G7 | KTX2 transcodes correctly on Vulkan and GL/ES | No texture pipeline |
| G8 | Chunk verification and 1,000-point resume reliable | No client delivery |
| G9 | Offline play grants zero Pokoins | No offline mode |
| G10 | Ledger conservation under 1M transactions | No market |
| G11 | Global CCU counter cannot race past 20 | No matchmaker |
| G12 | Publish gates cannot be bypassed | No releases |
| G13 | Audit immutable; one moderator cannot act alone | No moderation |
| G14 | Share and Pokoins ledgers atomic under 100 traders | No Exchange |
| G15 | AA/AAA features fall back cleanly to A tier | No feature flags shipped |
| G16 | Slice A holds 30 fps on Android 11 | No Android release |
| G17 | Slice B holds 20 CCU and recovers simulated 5% loss | No launch |

## Explicitly deferred

D3D12 until a Windows SDK build exists outside MSYS2; full path tracing, neural upscaling, full GI, virtualized geometry; VR UI; full SVG/HTML import; order book v2 until manipulation data exists; cross-slot state migration; third-party identity providers; professional human translation at scale.

## Pre-mortem summary

Assumed failure in 2028 and ranked the causes. Full risk analysis remains here rather than in a subsystem spec because the top risks are behavioral, not technical.

| Failure | Probability | Impact | Warning sign | Prevention exists | Real gap |
|---|---|---|---|---|---|
| Scope collapse — years planning, no game | High | Fatal | No slice by end of Phase 5 | Partly | Discipline to stop adding subsystems |
| Determinism fails on arm64 | Medium | Fatal | First hash mismatch in CI | Yes, G1/G2 | Willingness to stop |
| HF #2 quota zero or cold start too slow | Medium | High | Cannot create Spaces; wake >20 s | Partly | Verify before server code |
| Exchange treated as security | Low | Fatal | Counsel flags "investment" | Partly | Counsel review not done |
| R oscillates and trust dies | Medium | High | R at clamp 3 weeks | Yes, simulator | Run sims before tuning |
| No games, no players | High | High | Studio works but nothing ships | Partly | Finish Poko Bakery |
| Economy farmed at launch | Medium | High | Payout flags >5/1k | Yes | Clicker-specific rule |
| Donors leave | Medium | Medium | Node uptime <80% | Partly | No effort redemption |
| Moderator burnout | Medium | Medium | Case backlog grows | Yes | More moderators, not reusable keys |
| Legal enforcement | Low | Fatal | Missing vendor DPA | Partly | Counsel and DPAs |

Three behavioral rules protect against the real risks:

1. G1 and G2 are non-negotiable.
2. One game finished before any new subsystem.
3. Counsel before donors, Exchange or privacy ship.

## What exists at each checkpoint

| Checkpoint | Playable | Developer-facing |
|---|---|---|
| After Phase 1 | Nothing; a VM proving determinism | — |
| After Phase 2 | — | — |
| After Phase 3 | — | Studio can author offline |
| After Phase 4 | Single-player bundled test game | Publish preflight works |
| After Phase 5 | Online single-player with wallet | — |
| After Phase 6 | Verified, moderated multiplayer | Full publish pipeline |
| After Phase 7 | Market and Library | Localization and a11y complete |
| After Phase 8 | Poko Bakery and Poko Playground live | Launch candidate |

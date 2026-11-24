# PokoX plan index

This folder is the durable record of the PokoX planning sessions. Read `00-decision-log.md` first, then `01-roadmap-and-gates.md`, then `02-work-queue.md`. The remaining documents are the per-system specifications.

## Status

The foundational plan exists; the proposed Mute v1 completion scope is awaiting review. The folder scaffold and seven main README stubs are present. The minimal build and all five dependency link checks have passed on Linux; INF-02 remains open pending the two Windows toolchains. INF-03 flag contracts have been implemented and tested on Linux; an INF-04 Windows CI workflow has been prepared but not run. The INF-05 golden harness and INF-06 Git-tag version generator pass local tests. Work proceeded under the execution-order exception recorded in the work queue. An SDL window demo is implemented and tested on a Linux virtual display, but is unverified on the Windows/Android targets. No product-ready application is implemented. No money in, no money out. See `../structure.md` for the actual layout and `../build.md` for build status.

## Current continuation

ENG-03 has started under the owner's explicit deferral of laptop-based
Windows/Android checks. Its graphics-window prerequisite and an opt-in Diligent/Vulkan clear-color
source candidate are implemented and dependency-double tested; real-SDK build
and clear-color acceptance remain open. See `../eng-progress.md`. No phase gate is waived.

## Reading order

| Order | File | Purpose |
|---|---|---|
| 1 | `00-decision-log.md` | Every locked decision, including what was rejected |
| 2 | `01-roadmap-and-gates.md` | Nine phases, hard gates, pre-mortem |
| 3 | `02-work-queue.md` | Single ordered queue; first 20 tasks in execution order |
| 4 | `03-architecture.md` | Services, tiers, topology, quota budget |
| 5 | `04-mute.md` | Language and VM specification |
| 6 | `05-pkb-validation.md` | Authority validation contract |
| 7 | `06-network.md` | BitBuffer, frame, FEC, transports, lag reduction |
| 8 | `07-matchmaker-and-servers.md` | Slots, donated nodes, queues, BYO |
| 9 | `08-publishing-and-versions.md` | Pipeline, word versions, glyph table, GitHub releases |
| 10 | `09-economy.md` | Ledger, R, activity proof, Exchange |
| 11 | `10-moderation.md` | Poko Mod, hash keys, replay, appeals |
| 12 | `11-engine.md` | Renderer, physics, feature tiers, tiny-task waves |
| 13 | `12-app-interface.md` | egui C ABI, Kotlin JNI, 2008 skin |
| 14 | `13-ui-maker.md` | In-game UI authoring tool |
| 15 | `14-client.md` | Launcher, patcher, offline mode, lifecycle |
| 16 | `15-assets.md` | Import, runtime formats, chunks, CDN |
| 17 | `16-localization-a11y.md` | Strings, RTL, fonts, accessibility tree |
| 18 | `17-identity-security.md` | Accounts, trust, anti-cheat, threat response |
| 19 | `18-contributors.md` | Roles, onboarding, donor agreement, wordlist |
| 20 | `19-economy-simulator.md` | Simulation and tuning loop |
| 21 | `20-legal-privacy.md` | Legal documents, jurisdictions, data map |
| 22 | `21-engine-core.md` | Module graph, main loop, time, jobs, memory, ECS, filesystem, console |
| 23 | `22-engine-rhi.md` | RHI interface, resources, barriers, shader pipeline, passes |
| 24 | `23-engine-renderer.md` | Materials, camera, culling, lighting, shadows, post stack |
| 25 | `24-engine-physics.md` | Fixed-point solver, broadphase, narrowphase, joints, determinism |
| 26 | `25-engine-audio.md` | Mixer graph, codecs, spatial audio, voice chat |
| 27 | `26-engine-animation.md` | Skeletons, clips, state machines, blend trees, IK |
| 28 | `27-engine-scene.md` | Scene graph, prefabs, serialization, streaming, editor integration |
| 29 | `28-engine-diagnostics.md` | Profiler, debug draw, replay, console, crash handler |
| 30 | `29-boyr6-character-adaptation.md` | Head UV normalisation, 15 pin attachments, verification, MCP limits |
| 31 | `30-mute-v1-completion.md` | Proposed language, optimizer, game APIs and v1 completion gate |

`11-engine.md` remains the capability contract (tiers and decisions). Documents 21–28 are the implementation-level engine specs that expand it.

## Known shallow areas

These are specified at a high level but not yet at implementation depth:

- Studio editor internals beyond the UI maker: scene editor gizmos, timeline, asset browser
- Full game design documents for Poko Bakery and Poko Playground
- CI/CD release process and repository branching strategy
- Detailed wireframes for every client, Studio and Mod screen
- Community guideline taxonomy with examples
- Device support matrix and input device support
- Glossary and error-code registry

## Non-negotiable rules

1. If cross-platform state hashes differ, stop. Nothing above that gate is trustworthy.
2. One game finished (Poko Bakery) before any new subsystem.
3. Counsel review before donors, Exchange or privacy policy ship.
4. No money enters or leaves PokoX. Contribution rewards are reputation only.
5. Published `.pkx` artifacts are signed. Unsigned local imports never go online.
6. Every feature ships with its ceiling in the same commit as the feature.

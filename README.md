# PokoX — Project Root

This is the PokoX working copy. Everything needed to plan and to prepare character assets lives here.

## Current scaffold status

- The seven main directories have README stubs (INF-01 scaffold acceptance).
- INF-02 is in progress: the minimal build and all five dependency link checks pass on Linux. Windows MSYS2 and MSVC acceptance checks remain outstanding; see [build status](docs/build.md).
- INF-03 flag contracts and tests have been added. Windows and D3D12-enabled verification remain outstanding; the approved ordering exception is recorded in the [work queue](docs/plan/02-work-queue.md).
- INF-04 CI configuration is in `.github/workflows/ci.yml` and runs on GitHub (around 40 runs to date, last fully green run 2026-11-24); Actions billing must stay settled for jobs to start. See [build status](docs/build.md).
- INF-05 adds a shared [golden-file harness](tools/testutils/harness/README.md), with tests and fixtures organized under `tools/testutils/`.
- INF-06 adds [Git-tag build version metadata](tools/version/README.md); untagged source archives report `unversioned`.
- ENG-01 adds the platform interface. ENG-02 adds an optional SDL3 window backend and demo; dummy-driver, virtual X11 and real Windows MinGW checks pass. Windows MSVC/Android platform validation and infrastructure gates remain open. See [platform module](engine/platform/README.md).
- ENG-01/ENG-02 lifecycle tests have been strengthened, including dependency-free fault injection against the actual backend source. Production behavior is unchanged; MSVC/Android acceptance remains open. See [hardening evidence](docs/eng01-eng02-hardening-evidence.txt) and [Windows laptop evidence](docs/eng03-windows-laptop-evidence.txt).
- ENG-03 completed its window/platform work (Vulkan-window intent, size queries, borrowed SDL-window access, Diligent/Vulkan clear-color demo; 120 clear/present frames on a real Windows AMD GPU via MSYS2 MinGW). Engine work has continued through ENG-60–65: a deterministic fixed-point sim physics path (broadphase, GJK/EPA narrowphase, sequential-impulse solver), a character controller over it, and a visual f32 solver + soft-body path. The Mute compiler/VM (MUT-01–55) includes SSA lowering, an emitter, verifier, optimizer and stdlib. See [ENG progress](docs/eng-progress.md) and [Mute](mute/README.md).
- [Actual directory structure](docs/structure.md) records the current layout; [the original planned inventory](docs/structure-plan.md) is retained for reference. Update the structure and relevant status documents whenever implementation or layout changes.

## Where things are

| Path | Contents |
|---|---|
| `docs/plan/README.md` | **Start here** — index of all 31 planning specs |
| `docs/plan/00-decision-log.md` | Every locked decision, including rejected options |
| `docs/plan/01-roadmap-and-gates.md` | Phases, hard gates G1–G17, pre-mortem |
| `docs/plan/02-work-queue.md` | The ordered, dependency-resolved task queue (first commit: INF-01) |
| `docs/plan/03`–`28` | Full system specs: architecture, Mute, `.pkB`, network, economy, moderation, engine, shells, UI, assets, identity, legal, simulator |
| `docs/plan/29-boyr6-character-adaptation.md` | Character asset adaptation plan and validation record |
| `docs/legal/` | Legal document drafts (counsel review required before ship) |
| `docs/build.md`, `docs/structure.md`, `docs/repos.md` | Current build status, actual folder inventory, and repository proposal |
| `assets/characters/work/` | BlockyR6 and BoyR6 source + adapted `.blend`/`.glb` and reproducible scripts |

## Character assets

[**R6 file guide**](assets/characters/README.md): revised animations for both rigs are in `assets/characters/animation-v2/` with corresponding `transitions-v2/`. The earlier pass remains intact. The guide also covers the adapted bases, ten expressions and starter clothing for both models. Existing source, `_poko`, and preserved files are retained. These are Blender preparation assets; animation polish and blending still require review.

**Use the new [preservation-first prototypes](assets/characters/preserved/README.md) for further work.** They retain the original face system in separate `.blend` copies and export all three head UV sets for investigation. Their GLBs are previews, not visually verified or engine-ready. The older `_poko` files and scripts below simplify away the face UV layers and use opposite-side face pins; retain them for history, and do not regenerate them for the preservation workflow.


| File | Status |
|---|---|
| `assets/characters/work/BlockyR6_poko.blend` | Prepared source — 19 attachment motion checks passed; face attachment placement needs review |
| `assets/characters/work/BlockyR6_poko.glb` | Legacy simplified interchange — 19 pin nodes; original face layers not retained |
| `assets/characters/work/BoyR6_poko.blend` / `.glb` | Prepared source — 19 attachment motion checks passed; face attachment placement needs review |
| `assets/characters/work/adapt_blockyr6.py` / `adapt_boyr6.py` | Adaptation scripts write output beside the script |

Regeneration **overwrites** the matching `_poko.blend`, `_poko.glb` and adaptation log beside the scripts. Copy the sources and scripts to a separate working folder first if the current outputs must be preserved. To regenerate from the untouched sources:

```bash
cd assets/characters/work
blender --background BlockyR6_source.blend --python adapt_blockyr6.py
blender --background BoyR6_source.blend --python adapt_boyr6.py
```

See `docs/character-visual-review.md` and `docs/plan/29-boyr6-character-adaptation.md` for evidence, validation commands and outstanding issues. The current scripts put face attachments on the opposite side from the visible face; do not treat their positions as approved. The original Downloads files are not included in this archive.

## Important caveat

The adapted models are **prepared source assets**, not engine-runtime assets. PokoX will load PokoMesh + KTX2 chunks from a signed `.pkx`; the glTF→PokoMesh importer (task AST-04) is not implemented yet. See `docs/plan/29` and `docs/plan/15-assets.md`.

## Live Blender

The historical `mcp_client.py` + `load_live_blocky.py` scripts talk to the BlenderMCP addon on `127.0.0.1:9876` while Blender is running. The live loader scripts contain machine-specific paths and must be configured for the current machine. This is a session-local socket, not a WorkBuddy integration.

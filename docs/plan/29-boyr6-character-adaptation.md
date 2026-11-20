# 29 — R6 character asset adaptation (BoyR6 and BlockyR6)

**Preservation update:** The `_poko` work described below is a historical simplified adaptation, not the recommended model. Separate preservation-first prototypes and their test reports are in `assets/characters/preserved/README.md`. They retain the original face graph and head UVs in `.blend`; the GLB and material reconstruction remain experimental.

## Source and rights

Source: `Downloads/RobloxRigsSuite/RobloxRigsSuite/rigs/BoyR6.blend` (1.8 MB, Blender 5.2.1). Community-created R6 rig, free to use, not owned by Roblox. Working copy: `assets/characters/work/BoyR6_source.blend` — the original in Downloads was never modified.

Note: the live Blender window was showing `BlockyR6.blend`, not BoyR6. Both are in the same rig suite.

## Connection method

No Blender MCP connector is bound to WorkBuddy and no computer-control tool is available. The **BlenderMCP addon is installed inside Blender** and was already listening on `127.0.0.1:9876`. A minimal TCP client (`work/mcp_client.py`) sends newline-free JSON `{"type","params"}` and reads the JSON response. Verified with `ping`, then drove the live session through `execute_code`. This works in the current session only; it is not an account-independent WorkBuddy installation (see Limitations).

## Diagnosed problems

### 1. Head shading architecture

`H-RRS` carried three UV layers: `UVMap`, `customFaces`, `other`. Body meshes (`T-RRS`, `LA-RRS`, `RA-RRS`, `LL-RRS`, `RL-RRS`) carried only `UVMap`.

The face system is a **legitimate node-based decal system**, not broken architecture. In `RRS-Mat`, the group `customFacesTex_RRS_R6.001` takes the base `RRS-Tex` colour as input A, samples a **second image texture** through the `customFaces` UV layer, and alpha-blends it over the base (second image alpha = mix factor) into `Principled BSDF Base Color` and `Bump.Height`. That is a working "overlay face/expression over base texture" design — exactly the sort of thing a rig suite would include.

**In this specific file, however, the second Image Texture node has `image = NONE`**, and no face image exists anywhere in the `.blend` (the only packed image is `RRS-Tex`). So the decal branch contributed nothing at runtime. The visible face is **baked into `RRS-Tex` itself on `UVMap`**, in the atlas corner `U [0.88, 0.98]`, `V [0.77, 0.98]` (~1,857 head loops). The earlier simplified export retained the default visible face in a static view, but removed the ability to use the original face layer in that exported mesh.

The earlier conclusion that removing the face system was correct is withdrawn. A temporary overlay test confirmed the source face system works. The planned fixed material/single-UV path cannot represent it as-is; multi-UV and layered-material support must be designed and implemented before claiming engine compatibility. The preservation-first prototype retains all three head UV sets.

### 2. Missing pin attachments

BoyR6 contained zero attachment objects. A scan of all 25 `.blend` rigs in the suite found zero attachments in any of them — this is a suite-wide gap, not a BoyR6 defect. Attachments therefore had to be authored against the rig's actual bone layout.

## Will the `.blend` files work in the PokoX engine? No — and that is correct

A `.blend` is a **Blender authoring file**. The PokoX runtime never opens `.blend`, `.glb`, PNG, WAV or FBX directly (doc 15). It loads runtime formats from `.pkx` chunks:

| Authoring (Blender) | Runtime (PokoX) |
|---|---|
| `.blend` mesh with 12-bit-ready geometry | PokoMesh binary, quantized positions, octahedral normals, 16-bit UVs |
| `RRS-Tex` PNG | KTX2 + Basis Universal, transcodes to ASTC/ETC2/BC7 |
| Bone-parented attachment empties | Named attachment points in scene data |
| `Poko_R6_Base` material | One of the fixed material templates (Unlit or PBR opaque) |

The models are prepared authoring assets, not directly runnable; the validation issues below must be reviewed before calling them production-ready. The `.glb` exports are the interchange step into Studio, which converts to PokoMesh and KTX2 at publish. The runtime then loads those chunks. That pipeline (task AST-04) is planned but **not yet implemented** — no engine code exists yet. "It looks fine in Blender" only means the source is now clean; it does not mean the engine can load it today.

What still must happen before a game can use it: run the glTF import in Studio, quantize and pack to PokoMesh, convert the texture to KTX2, map the 32/47-bone R6 skeleton to the engine skeleton, generate simplified sim colliders (the render mesh is never physics), and publish a signed `.pkx`. Until those steps exist, these are prepared source assets.

## Earlier simplified adaptation (legacy)

| Rig | Armature | Bones | Source | Output |
|---|---|---|---|---|
| BoyR6 | `BoyRRS-Rig` | 47 | `BoyR6_source.blend` | `BoyR6_poko.blend` / `.glb` |
| BlockyR6 | `BlockyRRS-Rig` | 32 | `BlockyR6_source.blend` | `BlockyR6_poko.blend` / `.glb` |

Both had the same face architecture and zero attachments. Both were simplified with the same earlier method; `adapt_blockyr6.py` maps attachments to BlockyR6's different bone names (`Torso` instead of `LowerTorso`, shoulders on `UpperTorso`):

### Shading normalisation
- Removed `customFaces` and `other` UV layers from `H-RRS`; kept `UVMap` only.
- Built one clean material `Poko_R6_Base`: `UVMap -> Image Texture(RRS-Tex) -> Principled Base Color`, Roughness 0.5, no node group.
- Assigned it to all six character meshes.
- Removed the now-unreferenced `customFacesTex_RRS_R6` node group.
- Tagged the material with `poko_material=1`, `poko_uv_set=UVMap`.

### Pin attachments
Added 19 bone-parented empties in a `Poko Attachments` collection, each tagged `poko_attachment=1`, `poko_rig=R6`, `poko_bone=...`, `pokox_id=attachment.<snake_case_name>`, `poko_attachment_version=1`:

| Attachment | Bone | Purpose |
|---|---|---|
| HatAttachment | Head | Hat accessories |
| HairAttachment | Head | Hair accessories |
| FaceCenterAttachment | Head | Face decals at centre |
| FaceFrontAttachment | Head | Face accessories in front |
| NeckAttachment | UpperTorso | Neckwear |
| BodyFrontAttachment | UpperTorso | Front accessories |
| BodyBackAttachment | UpperTorso | Back accessories |
| WaistCenterAttachment | Torso / LowerTorso | Waist items |
| WaistFrontAttachment | Torso / LowerTorso | Front waist items |
| WaistBackAttachment | Torso / LowerTorso | Back waist items |
| Left/RightHipAttachment | UpperLeg.L/R | Hip items |
| Left/RightShoulderAttachment | UpperArm.L/R | Shoulder items |
| Left/RightGripAttachment | Hand.L/R | Held items |
| RootAttachment | Master | Character root |
| Left/RightAnkleAttachment | Foot.L/R | Foot items |

**Correction:** the visible face is on the **+Y** side in the supplied `.blend` files. The earlier assertion of -Y was incorrect. Current `FaceCenterAttachment` and `FaceFrontAttachment` positions are on the -Y side and must be reviewed and corrected; see `../character-visual-review.md`.

A Blender-specific gotcha was found and fixed: bone parenting places the child origin at the **bone tail**, so the first attempt offset every attachment by one bone length (Hat at Z=6.235 instead of 5.142). The script now subtracts `bone.length` on local Y. The positions match the script targets, but the front-facing targets use the wrong side of the head as described below.

## Validation and current status — 2026-11-20

The supplied `.blend` files and source files were checked with Blender 5.2.1's Python module. No `.blend` or `.glb` was changed during this validation. Machine-readable reports and the validator scripts are in `assets/characters/work/`.

| Check | BlockyR6 | BoyR6 |
|---|---|---|
| Meshes, UV layers | Six meshes; each has only `UVMap` | Six meshes; each has only `UVMap` |
| Attachments | 19 bone-parented; 19/19 passed motion smoke test | 19 bone-parented; 19/19 passed motion smoke test |
| Cross-mesh UV triangle overlaps | 0 | **37**, between `T-RRS` and `RL-RRS` |
| Custom-shape references | 26 bones with a custom shape | 44 bones with a custom shape |
| Helpers after reopen | 0 visible in the active view layer; 7 retained and render-hidden | 0 visible in the active view layer; 14 retained and render-hidden |

The BoyR6 source file also has 37 cross-mesh overlap pairs, so this overlap predates the adaptation. The count is pairs of triangles with positive intersection area, **not** the number of UV islands or proof of a visible defect. It may be intentional texture sharing; inspect the UVs and texture before changing them. The older 512×512 “zero collisions” result is invalid: the old validator created a new grid per mesh and could never compare different mesh names.

The corrected validator clips triangles against one another after grid-based candidate selection. It uses Blender's loop triangulation and ignores shared boundaries or intersection areas at or below `1e-12` UV-square units. It checks *between* the six meshes, not overlap within a mesh. Reports include UV triangle examples. This does not replace visual, material, or runtime-import testing.

The saved files retain custom bone shape objects; they are not deleted. The earlier warning that helpers were viewport-visible was incorrect: `hide_get()` alone does not account for collection visibility. A follow-up `visible_get()` check found all seven BlockyR6 and all 14 BoyR6 helper meshes hidden by their collections in the active view layer; all are also render-hidden. This does not establish how the controls appear in every interactive viewport or view layer. The supplied GLBs and separately regenerated GLBs each have six mesh definitions, one skin and 19 marked attachment nodes; this does not by itself establish runtime compatibility.

To reproduce validation from this folder:

```sh
cd assets/characters/work
python test_uv_overlap.py
blender --background BlockyR6_poko.blend --python-exit-code 1 --python validate_production.py
blender --background BoyR6_poko.blend --python-exit-code 1 --python validate_production.py
blender --background BlockyR6_poko.blend --python-exit-code 1 --python verify_attachment_motion.py
blender --background BoyR6_poko.blend --python-exit-code 1 --python verify_attachment_motion.py
```

The validators write separate `<file-stem>_production_validation.json` and `<file-stem>_attachment_motion.json` reports next to the scripts, replacing matching reports. Source-file reports were also saved for comparison. The motion check rotates a high ancestor around three axes and translates the armature for the root; it is a connectivity smoke test, not an exact pose or export round-trip test. The pure-Python overlap regression suite has seven cases and is registered with CTest as `character_uv_overlap`.

Both adaptation scripts now resolve output relative to their own location. Regeneration was tested in a separate folder for both source rigs using Blender 5.2.1; both produced `.blend` and `.glb` files. The original six asset files were verified unchanged against the incoming archive. Regeneration overwrites outputs beside the script: copy the script and source to a separate folder to preserve existing outputs. The Blender Python package reported unavailable optional Draco/MeshOptimizer bridges, but uncompressed GLB exports completed. BoyR6 also emitted its two known finger-driver warnings.

## Pipeline integration

Use the preservation-first prototype documented in `assets/characters/preserved/README.md`. The source `.blend` retains the original face graph; the GLB has three head UV channels and a base-only preview material. A Blender mock shader demonstrated how a temporary face texture can be composited using the separate face UV. This is not an engine implementation. The planned importer, multi-UV material representation, animation handling, morph support, reliable visual export, attachment and accessory validation, and packaging remain future work.
## Known remaining issues

- Two invalid drivers exist on the source rig: `pose.bones["Fingers.L"].hide[0]` and `Fingers.R`. They produce warnings on load; their full effect on rig behavior has not been established. Not fixed.
- The face-decal image slot in the source is empty by default. A temporary image demonstrated that the original `customFaces` overlay works. The engine still needs a multi-UV/layered material solution; do not remove the source face system.
- Attachment names follow Roblox conventions for compatibility; PokoX runtime uses its own attachment IDs mapped from these names.
- The saved `.blend` files retain rig helper meshes used as control shapes. The scripts exclude them from selected GLB export. The helper meshes are hidden in the checked view layer; bone-control usability in an interactive viewport has not been tested.
- The current face attachment points are on the opposite side of the head from the visible face. Front/back body and waist attachment semantics should also be checked before accepting the rig. The existing motion tests establish connectivity, not correct placement.

## Files

| File | Purpose |
|---|---|
| `work/BoyR6_source.blend` | Untouched working copy of original |
| `work/BoyR6_poko.blend` | Fixed blend, saved and loaded in live Blender |
| `work/BoyR6_poko.glb` | Export for asset pipeline |
| `work/adapt_boyr6.py` / `adapt_blockyr6.py` | Reproducible fix scripts for each rig |
| `work/BlockyR6_source.blend` / `BlockyR6_poko.blend` / `.glb` | Correct rig — BlockyR6 — source, fix and export |
| `work/validate_production.py` / `uv_overlap.py` / `test_uv_overlap.py` | Cross-mesh UV, mesh and rig validation and regression tests |
| `work/*_production_validation.json` | Blender validation reports for source and adapted files |
| `work/verify_attachment_motion.py` / `work/*_attachment_motion.json` | Attachment motion smoke test and reports |
| `work/verify_boyr6_file.py` | Historical verification script; its old `verify_result.json` is not included |
| `work/mcp_client.py` | BlenderMCP socket client |

## Limitations — MCP and skills request

- No Blender MCP connector is installed in WorkBuddy (`list_installed_plugins` returned none) and no computer-control tool is exposed, so I could not use a first-class MCP tool. I connected directly to the addon's local socket instead.
- The BlenderMCP addon is installed **inside Blender**, not in WorkBuddy. It can only be reached while Blender is running and the addon's server is on.
- "All MCP tools and skills working across the entire WorkBuddy app regardless of account switching" is not achievable from this environment. MCP servers are configured per workspace/user in `mcp.json` and require a trust step in the WorkBuddy UI; skills install into the current user profile. There is no account-independent global install path, and most of the referenced GitHub repositories are reference/material repos rather than installable WorkBuddy skills. No such configuration was changed.

## Next

Develop and test a faithful glTF-to-engine import and layered-face material supporting the separate face UV; validate visual detail, skinning, morphs, animations, attachment placement and real accessories. The preserved prototypes are not production-ready. BoyR6 UV overlap was present in the source and is retained; do not change it without evidence of a defect. Infrastructure gates in the work queue remain in force.

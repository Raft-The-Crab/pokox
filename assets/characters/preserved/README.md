# Preservation-first R6 prototype

These are separate copies of the original BoyR6 and BlockyR6 source rigs. The source and earlier `_poko` files remain untouched. The `_preserved.blend` files retain the source mesh and rig setup, material graph, three head UV layers and control helpers, and add 19 provisional bone-parented attachment points. Face, torso and waist front points use the +Y face-side convention in Blender source coordinates; accessory placement and orientation still need interactive tests.

## Evidence and limits

- `*_preservation_check.json` compares selected source and preserved mesh topology/positions, UVs, shape keys, material graph, weights, bones, constraints, driver expressions and control-shape references. Both matched; this is not a proof that every property or behavior matches.
- `*_preserved_attachment_motion.json`: 19/19 points followed selected bone motions per rig. This checks connectivity, not wearable fit or all poses.
- `*_roundtrip_check.json`: Blender-reimported GLBs retain three head UV coordinate sets (unique-value comparison at five decimals) and all 19 attachment positions and bone parents. BlockyR6's four limb Bend shape key names survive as morph targets. This does not prove per-corner UV equivalence or animation parity.
- `../../../docs/Preserved-face-roundtrip.png` shows a temporary pink face overlay on the originals, preserved blends and a GLB reimport. Source and preserved images matched pixels for this static render. The GLB test rebuilds the overlay material in Blender; it is not a working PokoX engine feature. The pink image is only a demo and is not saved into the models.
- `*_preserved.glb` is an **interchange prototype**, with a base-only material. Blender shader node groups do not transfer as glTF materials. Subdivision modifiers were not applied to preserve shape keys, so the GLB's rendered shape and shading can differ visibly from the Blender source. Do not use this preview as a final production asset without a verified export solution.

## Proposed engine integration — not implemented

The source `RRS-Mat` samples its optional transparent face image with `customFaces`, compositing it over the base `RRS-Tex` sampled with `UVMap`. The source face image slot is empty and a switch currently selects the base. No separate face mesh is needed for this tested effect. Keep the original graph in the authoring file; implement an equivalent material in the asset importer/engine rather than deleting it.

The current prototype head stores `other` in glTF `TEXCOORD_0`, `customFaces` in `TEXCOORD_1`, and base `UVMap` in `TEXCOORD_2` (see `*.face.json`). glTF V coordinates use the opposite origin from Blender. The engine must explicitly retain and select these UV sets, sample the optional RGBA image using the face set and alpha-composite over the base. Handle absence of a face texture and replicate the intended switch behavior. The old one-UV/fixed-material plan does not yet support this; design and implement a suitable multi-UV/layered material representation before claiming compatibility.

Import and validate the skin, bone transforms, and named attachment metadata, test animation clips baked from Blender controls, and support/test the required morph targets. Constraints and drivers are Blender behavior, not glTF runtime behavior. Neither source has animation actions in the checked files. Check influences against the planned engine limit (four), shading/tangents, axis conversion, character poses, and real accessories. Then convert to the planned PokoMesh/texture formats and `.pkx` publish pipeline when implemented. The prototype alone does not provide these features.

## Reproduce with Blender 5.2.1

The preservation script refuses to overwrite its outputs. Copy `preserve_r6.py` into an empty output folder, then run it with an absolute path to either source file:

```sh
blender --background /absolute/path/to/assets/characters/work/BoyR6_source.blend --python-exit-code 1 --python /path/to/empty/output/folder/preserve_r6.py
```

For the supplied output and project layout, from this folder:

```sh
blender --background --python-exit-code 1 --python verify_preservation.py -- BoyR6
blender --background --python-exit-code 1 --python verify_roundtrip.py -- BoyR6
blender --background --python-exit-code 1 --python preview_face_glb.py -- BoyR6_preserved.glb demo-face.png /tmp/poko-face-demo.png
```

Repeat with `BlockyR6`. Verification scripts overwrite their matching JSON reports; the preview refuses to overwrite its output image. The face preview imports a GLB into a temporary Blender process and reconstructs a mock material; it does not write back to the GLB. Optional Draco/MeshOptimizer warnings do not prevent uncompressed GLB export; the source BoyR6 also emits finger-driver warnings.

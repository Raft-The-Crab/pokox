# Character visual review — 2026-11-20

**Historical scope:** This review compares the earlier `_poko` adaptation, not the newer preservation-first prototype. See `assets/characters/preserved/README.md` and `Preserved-face-roundtrip.png` for the newer work.

## Scope and result

Blender 5.2.1's Python module rendered the original and adapted `.blend` files under matching camera, light and render settings, using the packed image textures. The comparison shows the face-facing side and the opposite side. No `.blend` or `.glb` file was changed. These still images are a limited visual check, not proof of all poses, animation, shading environments, or engine import.

- [BoyR6: original and adapted](BoyR6-visual-comparison.png)
- [BlockyR6: original and adapted](BlockyR6-visual-comparison.png)

The source and adapted versions look very similar at these two angles. There is no obvious torso/right-leg texture artifact in BoyR6 in these renders. Its 37 cross-mesh UV triangle overlap pairs are also present in the source. They may be intentional; do not move UVs based solely on the overlap count. The BoyR6 render log also reported an image-loading warning, although the packed base texture and face were visible; the images should not be considered a complete material audit.

## Face direction and attachment concern

The face is visible from the positive-Y camera, located at `(-6, 14, 6)` and aimed at `(0, 0, 2.5)`. A spot check of nine head triangles sampling dark pixels in the face texture places their centers at world Y `0.580–0.593` in both adapted files. The head's world Y bounds are approximately `-0.599` to `+0.599`.

In both adapted files `FaceCenterAttachment` is at world Y `-0.60` and `FaceFrontAttachment` at `-0.62`, the opposite side from the visible face. The previous plan's -Y claim was wrong. BodyFront/BodyBack and WaistFront/WaistBack also use -Y/+Y respectively; their intended meaning should be checked against the same convention. The 19/19 movement smoke tests show the attachments follow the rig, not that they are correctly placed. **No attachment positions were changed in this review.**

## Helper visibility

The earlier validation used `hide_get()` alone and incorrectly warned that helper meshes were visible. After reopening, `visible_get()` on the active view layer reports zero visible helper meshes for either rig. BlockyR6's seven helpers are in the viewport-hidden `BlockyShapes-RRS` collection; BoyR6's 14 are in the viewport-hidden `MeshShapes-RRS` collection. All are render-hidden. The saved rig retains 26 and 44 bones respectively with custom shape references. See the `*_poko_production_validation.json` reports in `assets/characters/work/` for each object's visibility and collection. This does not substitute for checking bone-control usability in an interactive viewport or every view layer.

## Windows build status

MSVC and MSYS2/MinGW are not available in this Linux environment; no Windows or GitHub Actions run was performed. INF-02 and INF-04 therefore remain open. Follow `build.md` on the two Windows toolchains and record the actual results.

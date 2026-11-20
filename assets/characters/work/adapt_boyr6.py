"""Adapt BoyR6 for PokoX.

Fixes:
  1. Head shading: collapse the dead customFaces node branch and remove the
     extra UV layers so H-RRS matches the body's single-UV architecture.
  2. Pin attachments: add a standard R6 attachment set as bone-parented empties
     marked with PokoX custom properties.

Run: blender --background BoyR6_source.blend --python adapt_boyr6.py
"""
import bpy
import re
from pathlib import Path
from mathutils import Matrix

WORK_DIR = Path(__file__).resolve().parent
OUT = str(WORK_DIR / "BoyR6_poko.blend")
GLB = str(WORK_DIR / "BoyR6_poko.glb")

CHARACTER = ["H-RRS", "T-RRS", "LA-RRS", "RA-RRS", "LL-RRS", "RL-RRS"]
ARM_NAME = "BoyRRS-Rig"
log = []

# ---------------------------------------------------------------- 1. shading
# The customFaces UV branch has no image assigned, so the Mix factor is 0 and
# the visible result is already the base RRS-Tex through UVMap. Remove the dead
# branch by building one clean material used by every character mesh.
base_img = bpy.data.images.get("RRS-Tex")
if base_img is None:
    for img in bpy.data.images:
        if "diff" in img.name.lower() or "RRS" in img.name:
            base_img = img
            break

mat = bpy.data.materials.new("Poko_R6_Base")
mat.use_nodes = True
nt = mat.node_tree
nt.nodes.clear()

out = nt.nodes.new("ShaderNodeOutputMaterial")
out.location = (320, 0)
bsdf = nt.nodes.new("ShaderNodeBsdfPrincipled")
bsdf.location = (40, 0)
tex = nt.nodes.new("ShaderNodeTexImage")
tex.location = (-260, 0)
tex.image = base_img
tex.interpolation = "Linear"
uv = nt.nodes.new("ShaderNodeUVMap")
uv.location = (-500, 0)
uv.uv_map = "UVMap"

nt.links.new(uv.outputs["UV"], tex.inputs["Vector"])
nt.links.new(tex.outputs["Color"], bsdf.inputs["Base Color"])
bsdf.inputs["Roughness"].default_value = 0.5
nt.links.new(bsdf.outputs["BSDF"], out.inputs["Surface"])
mat["poko_material"] = 1
mat["poko_uv_set"] = "UVMap"

for name in CHARACTER:
    ob = bpy.data.objects.get(name)
    if not ob:
        log.append(f"MISSING mesh {name}")
        continue
    # normalise UV layers: keep only UVMap
    for layer in list(ob.data.uv_layers):
        if layer.name != "UVMap":
            ob.data.uv_layers.remove(layer)
    ob.data.materials.clear()
    ob.data.materials.append(mat)
    log.append(f"NORMALISED {name}: uv={[u.name for u in ob.data.uv_layers]} mat={mat.name}")

# Remove the now-unused node group if nothing references it
for ng in list(bpy.data.node_groups):
    if ng.name.startswith("customFacesTex") and ng.users == 0:
        bpy.data.node_groups.remove(ng)
        log.append(f"REMOVED dead node group {ng.name}")

# ------------------------------------------------------------- 2. attachments
arm = bpy.data.objects.get(ARM_NAME)
if arm is None:
    raise RuntimeError("armature not found")

# desired world position = bone head/tail in world space plus a world offset.
# WARNING: These old -Y front offsets do not match the visible face (+Y).
# See docs/character-visual-review.md before regenerating production assets.
def bone_world_point(bone_name, which="head", offset=(0, 0, 0)):
    b = arm.data.bones[bone_name]
    v = b.head_local.copy() if which == "head" else b.tail_local.copy()
    world = arm.matrix_world @ v
    return world + __import__("mathutils").Vector(offset)

# name, bone, point, offset
ATTACHMENTS = [
    ("HatAttachment",          "Head",       "tail", (0.0, 0.0, 0.05)),
    ("HairAttachment",         "Head",       "tail", (0.0, -0.18, 0.02)),
    ("FaceCenterAttachment",   "Head",       "head", (0.0, -0.60, 0.55)),
    ("FaceFrontAttachment",    "Head",       "head", (0.0, -0.62, 0.30)),
    ("NeckAttachment",         "UpperTorso", "tail", (0.0, 0.0, 0.0)),
    ("BodyFrontAttachment",    "UpperTorso", "head", (0.0, -0.55, 0.60)),
    ("BodyBackAttachment",     "UpperTorso", "head", (0.0, 0.55, 0.60)),
    ("WaistCenterAttachment",  "LowerTorso", "head", (0.0, 0.0, 0.0)),
    ("WaistFrontAttachment",   "LowerTorso", "head", (0.0, -0.50, 0.0)),
    ("WaistBackAttachment",    "LowerTorso", "head", (0.0, 0.50, 0.0)),
    ("LeftHipAttachment",      "UpperLeg.L", "head", (0.0, 0.0, 0.0)),
    ("RightHipAttachment",     "UpperLeg.R", "head", (0.0, 0.0, 0.0)),
    ("LeftShoulderAttachment", "UpperArm.L", "head", (0.0, 0.0, 0.0)),
    ("RightShoulderAttachment","UpperArm.R", "head", (0.0, 0.0, 0.0)),
    ("LeftGripAttachment",     "Hand.L",     "tail", (0.0, 0.0, 0.0)),
    ("RightGripAttachment",    "Hand.R",     "tail", (0.0, 0.0, 0.0)),
    ("RootAttachment",         "Master",     "head", (0.0, 0.0, 0.0)),
    ("LeftAnkleAttachment",    "Foot.L",     "head", (0.0, 0.0, 0.0)),
    ("RightAnkleAttachment",   "Foot.R",     "head", (0.0, 0.0, 0.0)),
]

coll = bpy.data.collections.get("Poko Attachments")
if coll is None:
    coll = bpy.data.collections.new("Poko Attachments")
    bpy.context.scene.collection.children.link(coll)

for name, bone, which, offset in ATTACHMENTS:
    existing = bpy.data.objects.get(name)
    if existing:
        bpy.data.objects.remove(existing, do_unlink=True)
    empty = bpy.data.objects.new(name, None)
    coll.objects.link(empty)
    empty.empty_display_type = "PLAIN_AXES"
    empty.empty_display_size = 0.12

    target = bone_world_point(bone, which, offset)
    bone_world = arm.matrix_world @ arm.data.bones[bone].matrix_local
    local = bone_world.inverted() @ target
    # Blender's BONE parenting origin is the bone TAIL, not the head.
    # Compensate so the marker lands on the intended world point.
    local.y -= arm.data.bones[bone].length
    empty.parent = arm
    empty.parent_type = "BONE"
    empty.parent_bone = bone
    empty.matrix_parent_inverse = Matrix.Identity(4)
    empty.location = local

    empty["poko_attachment"] = 1
    empty["poko_rig"] = "R6"
    empty["poko_bone"] = bone
    empty["poko_attachment_version"] = 1
    empty["pokox_id"] = "attachment." + re.sub(r"(?<!^)(?=[A-Z])", "_", name).lower()
    log.append(f"ATTACH {name} -> {bone} local={[round(x,4) for x in local]} world={[round(x,4) for x in target]}")

# --------------------------------------------------------------------- export
# Hide rig helpers BEFORE saving so the .blend viewport is clean too.
# Helper meshes are CUSTOM BONE SHAPES - never delete them.
# Keep them in the file but exclude from render and from glTF export.
used_shapes = set()
for ob in bpy.context.scene.objects:
    if ob.type == "ARMATURE":
        for pb in ob.pose.bones:
            if pb.custom_shape:
                used_shapes.add(pb.custom_shape.name)
for ob in bpy.context.scene.objects:
    if ob.type == "MESH" and ob.name not in CHARACTER:
        ob.hide_render = True
        try: ob.hide_set(True)
        except RuntimeError: pass
        ob["poko_control_shape"] = 1 if ob.name in used_shapes else 0

bpy.ops.wm.save_as_mainfile(filepath=OUT)
log.append(f"SAVED {OUT}")

# Unlink control shapes temporarily so glTF cannot include them.
shapes = [ob for ob in bpy.context.scene.objects if ob.get("poko_control_shape")]
shape_collections = {}
for ob in shapes:
    shape_collections[ob.name] = list(ob.users_collection)
    for col in shape_collections[ob.name]:
        col.objects.unlink(ob)
for ob in bpy.context.scene.objects:
    ob.select_set(False)
for ob in bpy.context.scene.objects:
    if ob.name in CHARACTER or ob.type == "ARMATURE" or ob.get("poko_attachment"):
        ob.select_set(True)
try:
    bpy.ops.export_scene.gltf(
        filepath=GLB,
        export_format="GLB",
        use_selection=True,
        export_apply=False,
        export_yup=True,
        export_cameras=False,
        export_lights=False,
        export_extras=True,
        export_materials="EXPORT",
        export_animations=False,
    )
    log.append(f"EXPORTED {GLB}")
except Exception as e:
    log.append(f"GLB EXPORT FAILED: {e}")
    raise
finally:
    for ob in shapes:
        for col in shape_collections.get(ob.name, []):
            col.objects.link(ob)
    Path(OUT).with_name(Path(OUT).stem + "_adapt.log").write_text("\n".join(log), encoding="utf-8")
    print("\n".join(log))

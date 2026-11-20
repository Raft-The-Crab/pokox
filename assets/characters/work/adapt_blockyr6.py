"""Adapt BlockyR6 for PokoX (same two fixes as BoyR6, different bone names).

Run: blender --background BlockyR6_source.blend --python adapt_blockyr6.py
"""
import bpy
import re
from pathlib import Path
from mathutils import Matrix, Vector

WORK_DIR = Path(__file__).resolve().parent
OUT = str(WORK_DIR / "BlockyR6_poko.blend")
GLB = str(WORK_DIR / "BlockyR6_poko.glb")
CHARACTER = ["H-RRS", "T-RRS", "LA-RRS", "RA-RRS", "LL-RRS", "RL-RRS"]
ARM_NAME = "BlockyRRS-Rig"
log = []

# ------------------------------------------------------------------ shading
base_img = bpy.data.images.get("RRS-Tex")
mat = bpy.data.materials.new("Poko_R6_Base")
mat.use_nodes = True
nt = mat.node_tree
nt.nodes.clear()
out = nt.nodes.new("ShaderNodeOutputMaterial"); out.location = (320, 0)
bsdf = nt.nodes.new("ShaderNodeBsdfPrincipled"); bsdf.location = (40, 0)
tex = nt.nodes.new("ShaderNodeTexImage"); tex.location = (-260, 0); tex.image = base_img
uv = nt.nodes.new("ShaderNodeUVMap"); uv.location = (-500, 0); uv.uv_map = "UVMap"
nt.links.new(uv.outputs["UV"], tex.inputs["Vector"])
nt.links.new(tex.outputs["Color"], bsdf.inputs["Base Color"])
bsdf.inputs["Roughness"].default_value = 0.5
nt.links.new(bsdf.outputs["BSDF"], out.inputs["Surface"])
mat["poko_material"] = 1
mat["poko_uv_set"] = "UVMap"

for name in CHARACTER:
    ob = bpy.data.objects.get(name)
    if not ob:
        log.append(f"MISSING {name}"); continue
    for layer in list(ob.data.uv_layers):
        if layer.name != "UVMap":
            ob.data.uv_layers.remove(layer)
    ob.data.materials.clear()
    ob.data.materials.append(mat)
    log.append(f"NORMALISED {name} uv={[u.name for u in ob.data.uv_layers]}")

for ng in list(bpy.data.node_groups):
    if ng.name.startswith("customFacesTex") and ng.users == 0:
        bpy.data.node_groups.remove(ng)
        log.append(f"REMOVED {ng.name}")

# -------------------------------------------------------------- attachments
arm = bpy.data.objects[ARM_NAME]

def world_point(bone, which, offset):
    b = arm.data.bones[bone]
    v = b.head_local.copy() if which == "head" else b.tail_local.copy()
    return (arm.matrix_world @ v) + Vector(offset)

# WARNING: The old -Y front offsets do not match the visible face (+Y).
# See docs/character-visual-review.md before regenerating production assets.
# BlockyR6 bone layout: Torso replaces LowerTorso; shoulders hang from UpperTorso
ATTACHMENTS = [
    ("HatAttachment",           "Head",        "tail", (0.0, 0.0, 0.05)),
    ("HairAttachment",          "Head",        "tail", (0.0, -0.18, 0.02)),
    ("FaceCenterAttachment",    "Head",        "head", (0.0, -0.60, 0.50)),
    ("FaceFrontAttachment",     "Head",        "head", (0.0, -0.62, 0.25)),
    ("NeckAttachment",          "UpperTorso",  "tail", (0.0, 0.0, 0.0)),
    ("BodyFrontAttachment",     "UpperTorso",  "head", (0.0, -0.55, 0.35)),
    ("BodyBackAttachment",      "UpperTorso",  "head", (0.0, 0.55, 0.35)),
    ("WaistCenterAttachment",   "Torso",       "head", (0.0, 0.0, 0.0)),
    ("WaistFrontAttachment",    "Torso",       "head", (0.0, -0.50, 0.0)),
    ("WaistBackAttachment",     "Torso",       "head", (0.0, 0.50, 0.0)),
    ("LeftHipAttachment",       "UpperLeg.L",  "head", (0.0, 0.0, 0.0)),
    ("RightHipAttachment",      "UpperLeg.R",  "head", (0.0, 0.0, 0.0)),
    ("LeftShoulderAttachment",  "UpperArm.L",  "head", (0.0, 0.0, 0.0)),
    ("RightShoulderAttachment", "UpperArm.R",  "head", (0.0, 0.0, 0.0)),
    ("LeftGripAttachment",      "Hand.L",      "tail", (0.0, 0.0, 0.0)),
    ("RightGripAttachment",     "Hand.R",      "tail", (0.0, 0.0, 0.0)),
    ("RootAttachment",          "Master",      "head", (0.0, 0.0, 0.0)),
    ("LeftAnkleAttachment",     "Foot.L",      "head", (0.0, 0.0, 0.0)),
    ("RightAnkleAttachment",    "Foot.R",      "head", (0.0, 0.0, 0.0)),
]

coll = bpy.data.collections.get("Poko Attachments")
if coll is None:
    coll = bpy.data.collections.new("Poko Attachments")
    bpy.context.scene.collection.children.link(coll)

for name, bone, which, offset in ATTACHMENTS:
    old = bpy.data.objects.get(name)
    if old:
        bpy.data.objects.remove(old, do_unlink=True)
    e = bpy.data.objects.new(name, None)
    coll.objects.link(e)
    e.empty_display_type = "PLAIN_AXES"
    e.empty_display_size = 0.12
    target = world_point(bone, which, offset)
    bone_world = arm.matrix_world @ arm.data.bones[bone].matrix_local
    local = bone_world.inverted() @ target
    local.y -= arm.data.bones[bone].length  # bone-parent origin is the TAIL
    e.parent = arm
    e.parent_type = "BONE"
    e.parent_bone = bone
    e.matrix_parent_inverse = Matrix.Identity(4)
    e.location = local
    e["poko_attachment"] = 1
    e["poko_rig"] = "R6"
    e["poko_bone"] = bone
    e["poko_attachment_version"] = 1
    e["pokox_id"] = "attachment." + re.sub(r"(?<!^)(?=[A-Z])", "_", name).lower()
    log.append(f"ATTACH {name} -> {bone} world={[round(x,4) for x in target]}")

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

# Export only character meshes, armature and attachments - never control shapes.
# Unlink control shapes temporarily so glTF cannot include them.
shapes = [ob for ob in bpy.context.scene.objects if ob.get("poko_control_shape")]
shape_collections = {}
for ob in shapes:
    shape_collections[ob.name] = list(ob.users_collection)
    for col in shape_collections[ob.name]:
        col.objects.unlink(ob)
bpy.ops.object.select_all(action='DESELECT')
for ob in bpy.context.scene.objects:
    if ob.name in CHARACTER or ob.type == "ARMATURE" or ob.get("poko_attachment"):
        ob.select_set(True)
try:
    bpy.ops.export_scene.gltf(filepath=GLB, export_format="GLB", export_apply=False,
        export_yup=True, export_cameras=False, export_lights=False,
        use_selection=True, export_extras=True, export_materials="EXPORT", export_animations=False)
    log.append(f"EXPORTED {GLB}")
except Exception as ex:
    log.append(f"GLB FAILED {ex}")
    raise
finally:
    for ob in shapes:
        for col in shape_collections.get(ob.name, []):
            col.objects.link(ob)
    Path(OUT).with_name(Path(OUT).stem + "_adapt.log").write_text("\n".join(log), encoding="utf-8")
    print("\n".join(log))

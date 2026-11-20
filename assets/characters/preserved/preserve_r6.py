"""Preservation-first R6 export. Never overwrites source or prior outputs.

Blender CLI:
  blender --background ../work/BoyR6_source.blend --python-exit-code 1 --python preserve_r6.py
Outputs are written beside this script. They retain the source face graph, UV
layers, rig and shape keys in the .blend. The GLB is an interchange preview;
its base-only material requires an engine-side face-overlay implementation.
"""
import bpy
import json
import re
from pathlib import Path
from mathutils import Matrix, Vector

OUT_DIR = Path(__file__).resolve().parent
source = Path(bpy.data.filepath).resolve()
if not source.is_file() or source.name not in ('BoyR6_source.blend', 'BlockyR6_source.blend'):
    raise RuntimeError('Open an untouched BoyR6_source.blend or BlockyR6_source.blend first')
rig = source.stem.split('_')[0]
blend = OUT_DIR / (rig + '_preserved.blend')
glb = OUT_DIR / (rig + '_preserved.glb')
manifest = OUT_DIR / (rig + '_preserved.face.json')
for path in (blend, glb, manifest):
    if path.exists():
        raise RuntimeError(f'Refusing to overwrite: {path}')

characters = ['H-RRS', 'T-RRS', 'LA-RRS', 'RA-RRS', 'LL-RRS', 'RL-RRS']
arm = bpy.data.objects.get('BoyRRS-Rig' if rig == 'BoyR6' else 'BlockyRRS-Rig')
if not arm or arm.type != 'ARMATURE':
    raise RuntimeError('Expected armature not found')
for name in characters:
    if not bpy.data.objects.get(name) or bpy.data.objects[name].type != 'MESH':
        raise RuntimeError(f'Missing mesh {name}')
head_uv = list(bpy.data.objects['H-RRS'].data.uv_layers.keys())
if head_uv != ['other', 'customFaces', 'UVMap']:
    raise RuntimeError(f'Unexpected head UV layout: {head_uv}')
if any(o.get('poko_attachment') for o in bpy.context.scene.objects):
    raise RuntimeError('Unexpected existing Poko attachments: stop rather than replace')
if bpy.data.collections.get('Poko Attachments'):
    raise RuntimeError('Attachment collection already exists: stop rather than alter it')

# Existing prior placement scheme, corrected for actual +Y face direction.
# World-space points are provisional until checked with actual accessories.
lower = 'LowerTorso' if rig == 'BoyR6' else 'Torso'
face_center_z = .55 if rig == 'BoyR6' else .50
face_front_z = .30 if rig == 'BoyR6' else .25
body_z = .60 if rig == 'BoyR6' else .35
attachments = [
 ('HatAttachment','Head','tail',(0,0,.05)),
 ('HairAttachment','Head','tail',(0,-.18,.02)),
 ('FaceCenterAttachment','Head','head',(0,.60,face_center_z)),
 ('FaceFrontAttachment','Head','head',(0,.62,face_front_z)),
 ('NeckAttachment','UpperTorso','tail',(0,0,0)),
 ('BodyFrontAttachment','UpperTorso','head',(0,.55,body_z)),
 ('BodyBackAttachment','UpperTorso','head',(0,-.55,body_z)),
 ('WaistCenterAttachment',lower,'head',(0,0,0)),
 ('WaistFrontAttachment',lower,'head',(0,.50,0)),
 ('WaistBackAttachment',lower,'head',(0,-.50,0)),
 ('LeftHipAttachment','UpperLeg.L','head',(0,0,0)),
 ('RightHipAttachment','UpperLeg.R','head',(0,0,0)),
 ('LeftShoulderAttachment','UpperArm.L','head',(0,0,0)),
 ('RightShoulderAttachment','UpperArm.R','head',(0,0,0)),
 ('LeftGripAttachment','Hand.L','tail',(0,0,0)),
 ('RightGripAttachment','Hand.R','tail',(0,0,0)),
 ('RootAttachment','Master','head',(0,0,0)),
 ('LeftAnkleAttachment','Foot.L','head',(0,0,0)),
 ('RightAnkleAttachment','Foot.R','head',(0,0,0)),
]
for name,bone,_,_ in attachments:
    if name in bpy.data.objects or bone not in arm.data.bones:
        raise RuntimeError(f'Attachment name collision or missing bone: {name} / {bone}')
coll = bpy.data.collections.new('Poko Attachments')
bpy.context.scene.collection.children.link(coll)
for name,bone,which,offset in attachments:
    b=arm.data.bones[bone]
    target=arm.matrix_world @ (b.head_local.copy() if which=='head' else b.tail_local.copy()) + Vector(offset)
    local=(arm.matrix_world @ b.matrix_local).inverted() @ target
    local.y -= b.length
    obj=bpy.data.objects.new(name,None);coll.objects.link(obj)
    obj.empty_display_type='PLAIN_AXES';obj.empty_display_size=.12
    obj.parent=arm;obj.parent_type='BONE';obj.parent_bone=bone
    obj.matrix_parent_inverse=Matrix.Identity(4);obj.location=local
    obj['poko_attachment']=1;obj['poko_rig']='R6';obj['poko_bone']=bone
    obj['poko_attachment_version']=1
    obj['pokox_id']='attachment.'+re.sub(r'(?<!^)(?=[A-Z])','_',name).lower()

# Save untouched source face/rig graph plus added pins. Do not save again after
# the temporary export material is assigned below.
bpy.ops.wm.save_as_mainfile(filepath=str(blend))

# glTF cannot directly reproduce this Blender multi-image custom node graph.
# Use a temporary base-only preview material while retaining ALL UV layers in
# the GLB. The companion JSON describes the custom face channel for a future
# importer/material. Nothing about the source graph is removed from the .blend.
image=bpy.data.images.get('RRS-Tex')
if image is None:
    raise RuntimeError('Missing packed RRS-Tex')
mat=bpy.data.materials.new('Poko_Export_Base_Only');mat.use_nodes=True
nodes=mat.node_tree.nodes;nodes.clear()
out=nodes.new('ShaderNodeOutputMaterial');bsdf=nodes.new('ShaderNodeBsdfPrincipled')
tex=nodes.new('ShaderNodeTexImage');tex.image=image
uv=nodes.new('ShaderNodeUVMap');uv.uv_map='UVMap'
mat.node_tree.links.new(uv.outputs['UV'],tex.inputs['Vector'])
mat.node_tree.links.new(tex.outputs['Color'],bsdf.inputs['Base Color'])
bsdf.inputs['Roughness'].default_value=.5
mat.node_tree.links.new(bsdf.outputs['BSDF'],out.inputs['Surface'])
for name in characters:
    ob=bpy.data.objects[name]
    ob.data.materials.clear();ob.data.materials.append(mat)
for ob in bpy.context.view_layer.objects:
    ob.select_set(False)
for ob in bpy.context.view_layer.objects:
    if ob.name in characters or ob==arm or ob.get('poko_attachment'):
        ob.select_set(True)
result=bpy.ops.export_scene.gltf(filepath=str(glb),export_format='GLB',use_selection=True,
    export_apply=False,export_yup=True,export_texcoords=True,export_skins=True,
    export_all_influences=True,export_morph=True,export_animations=True,
    export_all_vertex_colors=True,export_extras=True,export_cameras=False,export_lights=False)
if 'FINISHED' not in result or not glb.is_file():
    raise RuntimeError(f'glTF export failed: {result}')
contract={
 'schema':'pokox-preserved-r6-prototype-v1','rig':rig,
 'status':'interchange prototype; engine support not implemented',
 'source_blend':source.name,'preserved_blend':blend.name,'glb':glb.name,
 'head_mesh':'H-RRS','head_uv_layers_in_blender_order':head_uv,
 'head_gltf_texcoords':{'other':'TEXCOORD_0','customFaces':'TEXCOORD_1','UVMap':'TEXCOORD_2'},
 'gltf_uv_origin':'glTF V = 1 - Blender V',
 'base_texture':'embedded RRS-Tex','face_overlay_texture':None,
 'source_face_group':'customFacesTex_RRS','source_overlay_uv':'customFaces',
 'face_material_requirement':'sample optional RGBA face using customFaces; alpha-composite over base sampled with UVMap',
 'glb_material_note':'base-only preview; Blender face node graph does not transfer as glTF material',
 'attachments':'19 provisional bone-parented points; +Y face side before glTF axis conversion',
 'animation_note':'Blender control constraints/drivers are not glTF runtime behavior; bake/test animation clips separately',
 'morph_note':'retain shape keys in .blend and glTF morph targets; engine support must be implemented and tested',
}
manifest.write_text(json.dumps(contract,indent=2)+'\n',encoding='utf-8')
print('PRESERVED',blend,'EXPORTED',glb,'CONTRACT',manifest)

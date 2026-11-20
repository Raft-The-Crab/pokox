"""Read-only Blender GLB round-trip check. Run in a separate background process.

blender --background --python-exit-code 1 --python verify_roundtrip.py -- BoyR6
Writes only the corresponding *_roundtrip_check.json report beside this script.
"""
import bpy,sys,json
from pathlib import Path
if not bpy.app.background:
    raise RuntimeError('Use a separate background Blender process')
rig=sys.argv[-1]
if rig not in ('BoyR6','BlockyR6'):
    raise RuntimeError('Specify BoyR6 or BlockyR6 after --')
root=Path(__file__).resolve().parent
bpy.ops.wm.open_mainfile(filepath=str(root/(rig+'_preserved.blend')))
bpy.context.view_layer.update()
head=bpy.data.objects['H-RRS']; names=list(head.data.uv_layers.keys())
source_uv=[{(round(v.uv.x,5),round(v.uv.y,5)) for v in layer.data} for layer in head.data.uv_layers]
pins={o.name:(o.parent_bone,o.matrix_world.translation.copy()) for o in bpy.context.scene.objects if o.get('poko_attachment')}
source_morphs={n:list(bpy.data.objects[n].data.shape_keys.key_blocks.keys()) if bpy.data.objects[n].data.shape_keys else [] for n in ('LA-RRS','RA-RRS','LL-RRS','RL-RRS')}
bpy.ops.wm.read_factory_settings(use_empty=True)
bpy.ops.import_scene.gltf(filepath=str(root/(rig+'_preserved.glb')))
bpy.context.view_layer.update()
head=bpy.data.objects['H-RRS']
imported_uv=[{(round(v.uv.x,5),round(v.uv.y,5)) for v in layer.data} for layer in head.data.uv_layers]
if len(imported_uv)!=3 or len(source_uv)!=3 or any(source_uv[i]!=imported_uv[i] for i in range(3)):
    raise RuntimeError('Head UV coordinate sets did not round-trip')
if len(pins)!=19: raise RuntimeError('Expected 19 source attachment points')
max_error=0.0
for name,(bone,pos) in pins.items():
    o=bpy.data.objects.get(name)
    if not o or o.parent_type!='BONE' or o.parent_bone!=bone:
        raise RuntimeError(f'Attachment parent mismatch: {name}')
    err=(o.matrix_world.translation-pos).length;max_error=max(max_error,err)
    if err>1e-4: raise RuntimeError(f'Attachment position mismatch: {name} ({err})')
for n,expected in source_morphs.items():
    ob=bpy.data.objects[n]
    actual=list(ob.data.shape_keys.key_blocks.keys()) if ob.data.shape_keys else []
    if actual!=expected: raise RuntimeError(f'Shape keys differ on {n}: {actual} versus {expected}')
report={'rig':rig,'blender_version':bpy.app.version_string,
        'head_uv_layers':names,'head_uv_unique_sets_match_at_decimal_places':5,
        'head_uv_unique_counts':list(map(len,source_uv)),
        'attachments_with_matching_bone_parent_and_position':len(pins),
        'max_attachment_position_error':max_error,
        'limb_shape_key_names_match':source_morphs,
        'caveat':'UV set equality is not a per-corner proof; animation, constraints, materials and visual parity require separate checks'}
(root/(rig+'_roundtrip_check.json')).write_text(json.dumps(report,indent=2)+'\n',encoding='utf-8')
print('PASS',json.dumps(report))

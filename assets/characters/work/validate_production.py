"""Validate the opened R6 .blend. Run with Blender background mode.

Example: blender --background BlockyR6_poko.blend --python validate_production.py
Writes a separate <blend-stem>_production_validation.json beside this script.
Only cross-mesh UV overlap is checked; a positive area greater than 1e-12 is
reported. Other production and visual checks are still required.
"""
import bpy
import hashlib
import json
import os
import sys
from pathlib import Path

WORK_DIR = Path(__file__).resolve().parent
sys.path.insert(0, str(WORK_DIR))
from uv_overlap import find_cross_mesh_overlaps

CHARACTER = ['H-RRS', 'T-RRS', 'LA-RRS', 'RA-RRS', 'LL-RRS', 'RL-RRS']
source = Path(bpy.data.filepath)
if not bpy.data.filepath or not source.is_file():
    raise RuntimeError('Open a saved .blend file before running validation')
report = {'file': source.name, 'file_sha256': hashlib.sha256(source.read_bytes()).hexdigest(),
          'blender_version': bpy.app.version_string, 'view_layer': bpy.context.view_layer.name,
          'meshes': {}, 'rig': {}, 'helper_visible': [], 'helpers': []}
triangles = []
for name in CHARACTER:
    ob = bpy.data.objects.get(name)
    if ob is None or ob.type != 'MESH':
        raise RuntimeError(f'Missing character mesh: {name}')
    me = ob.data
    uv = me.uv_layers.get('UVMap')
    if uv is None:
        raise RuntimeError(f'Missing UVMap: {name}')
    coords = [tuple(float(v) for v in loop.uv) for loop in uv.data]
    if not coords:
        raise RuntimeError(f'Empty UVMap: {name}')
    me.calc_loop_triangles()
    for tri in me.loop_triangles:
        triangles.append((name, tuple(tuple(uv.data[i].uv) for i in tri.loops)))
    report['meshes'][name] = {
        'verts': len(me.vertices), 'faces': len(me.polygons), 'triangles': len(me.loop_triangles),
        'degenerate_3d_polygons': sum(p.area < 1e-9 for p in me.polygons),
        'uv_layers': [layer.name for layer in me.uv_layers],
        'uv_range': [[min(c[i] for c in coords), max(c[i] for c in coords)] for i in range(2)],
        'materials': [m.name if m else None for m in me.materials],
    }
report['uv_overlap'] = find_cross_mesh_overlaps(triangles)
arm = bpy.data.objects.get('BlockyRRS-Rig') or bpy.data.objects.get('BoyRRS-Rig')
if arm is None or arm.type != 'ARMATURE':
    raise RuntimeError('Expected R6 armature not found')
atts = [o for o in bpy.context.scene.objects if o.get('poko_attachment')]
report['rig'] = {
    'armature': arm.name, 'bones': len(arm.data.bones), 'attachments': len(atts),
    'attachment_names': sorted(o.name for o in atts),
    'all_bone_parented_to_rig': bool(atts) and all(o.parent_type == 'BONE' and o.parent == arm for o in atts),
    'all_parent_bones_exist': bool(atts) and all(o.parent_bone in arm.data.bones for o in atts),
    'custom_shape_bones': sum(bool(pb.custom_shape) for pb in arm.pose.bones),
}
for o in bpy.context.scene.objects:
    if o.type == 'MESH' and o.name not in CHARACTER:
        visible = o.visible_get()
        report['helpers'].append({'name': o.name, 'visible_in_view_layer': visible,
                                  'object_hide_get': o.hide_get(), 'render_hidden': o.hide_render,
                                  'collections': [{'name': c.name, 'hide_viewport': c.hide_viewport} for c in o.users_collection]})
        if visible:
            report['helper_visible'].append(o.name)
output = Path(os.environ.get('POKO_VALIDATION_OUTPUT', str(WORK_DIR / (source.stem + '_production_validation.json'))))
output.write_text(json.dumps(report, indent=2, sort_keys=True) + '\n', encoding='utf-8')
print('Validation report:', output)
print('Cross-mesh overlapping triangle pairs:', report['uv_overlap']['overlapping_triangle_pairs'])

"""Headless attachment smoke test. Does not save any changes to the .blend.

Run: blender --background <asset>_poko.blend --python verify_attachment_motion.py
Rotates a high ancestor through 25 degrees on each axis; root attachment is
checked by translating the armature. This does not prove exact expected poses.
"""
import bpy
import json
import math
from pathlib import Path
from mathutils import Quaternion

arm = bpy.data.objects.get('BlockyRRS-Rig') or bpy.data.objects.get('BoyRRS-Rig')
if not arm or arm.type != 'ARMATURE':
    raise RuntimeError('Expected armature not found')
attachments = sorted((o for o in bpy.context.scene.objects if o.get('poko_attachment')), key=lambda o: o.name)
if len(attachments) != 19:
    raise RuntimeError(f'Expected 19 attachments, found {len(attachments)}')
results = []
for obj in attachments:
    if obj.parent != arm or obj.parent_type != 'BONE' or obj.parent_bone not in arm.pose.bones:
        raise RuntimeError(f'Invalid bone parent: {obj.name}')
    bpy.context.view_layer.update()
    before = obj.matrix_world.translation.copy()
    if obj.name == 'RootAttachment':
        basis = arm.matrix_world.copy()
        try:
            moved = basis.copy()
            moved.translation.x += 0.5
            arm.matrix_world = moved
            bpy.context.view_layer.update()
            distance = (obj.matrix_world.translation - before).length
        finally:
            arm.matrix_world = basis
            bpy.context.view_layer.update()
        results.append({'name': obj.name, 'method': 'translate_armature_x_0.5', 'max_move': distance, 'connected': distance > 0.01})
    else:
        anc = arm.pose.bones[obj.parent_bone]
        while anc.parent and anc.parent.parent:
            anc = anc.parent
        basis = anc.matrix_basis.copy()
        distances = []
        try:
            for axis in ((1, 0, 0), (0, 1, 0), (0, 0, 1)):
                anc.matrix_basis = basis @ Quaternion(axis, math.radians(25)).to_matrix().to_4x4()
                bpy.context.view_layer.update()
                distances.append((obj.matrix_world.translation - before).length)
        finally:
            anc.matrix_basis = basis
            bpy.context.view_layer.update()
        results.append({'name': obj.name, 'method': 'rotate_ancestor_xyz_25deg', 'ancestor': anc.name, 'max_move': max(distances), 'connected': max(distances) > 0.01})
output = Path(__file__).resolve().parent / (Path(bpy.data.filepath).stem + '_attachment_motion.json')
output.write_text(json.dumps({'file': Path(bpy.data.filepath).name, 'blender_version': bpy.app.version_string,
                              'passed': sum(r['connected'] for r in results), 'total': len(results), 'attachments': results}, indent=2) + '\n', encoding='utf-8')
print('Attachment motion:', sum(r['connected'] for r in results), '/', len(results), 'report:', output)
if not all(r['connected'] for r in results):
    raise RuntimeError('Attachment motion check failed; see report')

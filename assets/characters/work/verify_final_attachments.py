"""Definitive attachment connectivity: rotate each ancestor about X, Y and Z.
A correctly bound attachment must move under at least one rotation axis."""
import bpy, json, math
from mathutils import Vector, Quaternion
arm = bpy.data.objects["BlockyRRS-Rig"]
att = [o for o in bpy.context.scene.objects if o.get("poko_attachment")]
res=[]
for o in att:
    pb = arm.pose.bones[o["poko_bone"]]
    anc = pb
    while anc.parent and anc.parent.parent:
        anc = anc.parent
    basis = anc.matrix_basis.copy()
    before = o.matrix_world.translation.copy()
    moves = []
    for axis in [(1,0,0),(0,1,0),(0,0,1)]:
        anc.matrix_basis = basis @ Quaternion(axis, math.radians(25)).to_matrix().to_4x4()
        bpy.context.view_layer.update()
        moves.append((o.matrix_world.translation - before).length)
    anc.matrix_basis = basis
    bpy.context.view_layer.update()
    res.append({"name":o.name,"bone":o["poko_bone"],"ancestor":anc.name,
                "connected":max(moves)>0.01,"max_move":round(max(moves),4),
                "parent_type":o.parent_type,
                "parent_bone":o.parent_bone})
open("attachment_final.json","w",encoding="utf-8").write(json.dumps(res,indent=2))

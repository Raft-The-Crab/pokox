import bpy, json, math
from mathutils import Vector, Quaternion, Matrix
arm = bpy.data.objects["BlockyRRS-Rig"]
att = [o for o in bpy.context.scene.objects if o.get("poko_attachment")]
res=[]
for o in att:
    bone_name = o["poko_bone"]
    pb = arm.pose.bones[bone_name]
    # walk up to an ancestor with a parent, rotate it: every descendant attachment must move
    anc = pb
    while anc.parent and anc.parent.parent:
        anc = anc.parent
    basis = anc.matrix_basis.copy()
    before = o.matrix_world.translation.copy()
    anc.matrix_basis = basis @ Quaternion((0,0,1), math.radians(25)).to_matrix().to_4x4()
    bpy.context.view_layer.update()
    move = (o.matrix_world.translation - before).length
    anc.matrix_basis = basis
    bpy.context.view_layer.update()
    res.append({"name":o.name,"bone":bone_name,"ancestor":anc.name,
                "follows_chain":move>0.01,"move":round(move,4),
                "parent_type":o.parent_type,"parent":o.parent.name if o.parent else None})
open("attachment_validation4.json","w",encoding="utf-8").write(json.dumps(res,indent=2))

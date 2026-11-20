import bpy, json, math
from mathutils import Vector, Quaternion, Matrix
arm = bpy.data.objects["BlockyRRS-Rig"]
att = [o for o in bpy.context.scene.objects if o.get("poko_attachment")]
res=[]
for o in att:
    bone_name = o["poko_bone"]
    pb = arm.pose.bones[bone_name]
    # Use the most reliable proof: move this bone via matrix_basis (works for connected too)
    basis = pb.matrix_basis.copy()
    before = o.matrix_world.translation.copy()
    pb.matrix_basis = basis @ Matrix.Translation(Vector((0.1,0,0))) if False else basis
    # simpler: rotate this bone around Z by 25deg using matrix_basis
    pb.matrix_basis = basis @ Quaternion((0,0,1), math.radians(25)).to_matrix().to_4x4()
    bpy.context.view_layer.update()
    after = o.matrix_world.translation.copy()
    move=(after-before).length
    pb.matrix_basis = basis
    bpy.context.view_layer.update()
    res.append({"name":o.name,"bone":bone_name,"follows":move>0.01,"move":round(move,4)})
open("attachment_validation3.json","w",encoding="utf-8").write(json.dumps(res,indent=2))

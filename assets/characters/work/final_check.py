import bpy, json, math
from mathutils import Vector, Quaternion
arm = bpy.data.objects["BlockyRRS-Rig"]
CH = ["H-RRS","T-RRS","LA-RRS","RA-RRS","LL-RRS","RL-RSS","RL-RRS"]
CH = ["H-RRS","T-RRS","LA-RRS","RA-RRS","LL-RRS","RL-RRS"]
att=[o for o in bpy.context.scene.objects if o.get("poko_attachment")]
connected=0
for o in att:
    pb=arm.pose.bones[o["poko_bone"]]; anc=pb
    while anc.parent and anc.parent.parent: anc=anc.parent
    basis=anc.matrix_basis.copy(); before=o.matrix_world.translation.copy()
    ok=False
    for axis in [(1,0,0),(0,1,0),(0,0,1)]:
        anc.matrix_basis=basis @ Quaternion(axis,math.radians(25)).to_matrix().to_4x4()
        bpy.context.view_layer.update()
        if (o.matrix_world.translation-before).length>0.01: ok=True
    anc.matrix_basis=basis; bpy.context.view_layer.update()
    if ok or o.name=="RootAttachment": connected+=1
shapes_missing=[pb.name for pb in arm.pose.bones if pb.custom_shape and pb.custom_shape.name not in bpy.data.objects]
print("PINS",len(att),"CONNECTED",connected,"SHAPES_MISSING",len(shapes_missing),
      "HEAD_UV",[u.name for u in bpy.data.objects["H-RRS"].data.uv_layers])

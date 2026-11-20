import bpy
arm=bpy.data.objects["BlockyRRS-Rig"]
missing=[pb.name for pb in arm.pose.bones if pb.custom_shape and pb.custom_shape.name not in bpy.data.objects]
print("SHAPES_MISSING",missing)
print("ATTACH",sum(1 for o in bpy.context.scene.objects if o.get("poko_attachment")))
print("HEAD_UV",[u.name for u in bpy.data.objects["H-RRS"].data.uv_layers])
print("MAT",[s.material.name for s in bpy.data.objects["H-RRS"].material_slots])
print("CHAR_MESHES",sum(1 for n in ["H-RRS","T-RRS","LA-RRS","RA-RRS","LL-RRS","RL-RRS"] if n in bpy.data.objects))

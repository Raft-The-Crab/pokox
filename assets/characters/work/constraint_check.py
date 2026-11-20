import bpy
print("FILE", bpy.data.filepath)
for o in bpy.context.scene.objects:
    if o.type=='ARMATURE':
        print("ARM", o.name)
        for pb in o.pose.bones:
            for c in pb.constraints:
                tgt = getattr(c,'target',None)
                sub = getattr(c,'subtarget',None)
                print("  C",pb.name,c.type,"target=",tgt.name if tgt else None,"sub=",sub)
            cs = pb.custom_shape
            if cs: print("  CUSTOM_SHAPE",pb.name,cs.name)

import bpy, json, math
from mathutils import Vector, Quaternion
arm = bpy.data.objects["BlockyRRS-Rig"]
CH = ["H-RRS","T-RRS","LA-RRS","RA-RRS","LL-RRS","RL-RRS"]
att = [o for o in bpy.context.scene.objects if o.get("poko_attachment")]

def nearest_surface(p):
    best=(1e9,None)
    for n in CH:
        o=bpy.data.objects[n]
        for v in o.data.vertices:
            w=o.matrix_world @ v.co
            d=(w-p).length
            if d<best[0]: best=(d,n)
    return best

# baseline world positions
before = {o.name: o.matrix_world.translation.copy() for o in att}
results = []
for o in att:
    bone = arm.pose.bones[o["poko_bone"]]
    # rotate the bone 20 degrees around local X, update, measure attachment movement
    orig = bone.rotation_quaternion.copy() if bone.rotation_mode=='QUATERNION' else None
    moved = False
    if bone.rotation_mode == 'QUATERNION':
        bone.rotation_quaternion = bone.rotation_quaternion @ Quaternion((1,0,0), math.radians(20))
    else:
        bone.rotation_euler.x += math.radians(20)
    bpy.context.view_layer.update()
    after = o.matrix_world.translation.copy()
    delta = (after-before[o.name]).length
    if bone.rotation_mode == 'QUATERNION': bone.rotation_quaternion = orig
    else: bone.rotation_euler.x -= math.radians(20)
    bpy.context.view_layer.update()
    dist,part = nearest_surface(before[o.name])
    results.append({"name":o.name,"bone":o["poko_bone"],
                    "follows_bone": delta>0.001,"move":round(delta,4),
                    "nearest_part":part,"surface_dist":round(dist,4),
                    "world":[round(x,3) for x in before[o.name]]})
open("attachment_validation.json","w",encoding="utf-8").write(json.dumps(results,indent=2))
print(json.dumps(results,indent=2))

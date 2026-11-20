import bpy, json
from mathutils import Vector
arm = bpy.data.objects["BlockyRRS-Rig"]
CH = ["H-RRS","T-RRS","LA-RRS","RA-RRS","LL-RRS","RL-RRS"]
att = [o for o in bpy.context.scene.objects if o.get("poko_attachment")]

def bbox_dist(p, name):
    o=bpy.data.objects[name]
    vs=[o.matrix_world @ v.co for v in o.data.vertices]
    lo=[min(v[i] for v in vs) for i in range(3)]
    hi=[max(v[i] for v in vs) for i in range(3)]
    q=[max(lo[i],min(p[i],hi[i])) for i in range(3)]
    return (Vector(q)-p).length

res=[]
for o in att:
    bone=arm.pose.bones[o["poko_bone"]]
    before=o.matrix_world.translation.copy()
    # translate the bone by 0.1 in local X - every child must move
    orig=bone.location.copy()
    bone.location.x += 0.1
    bpy.context.view_layer.update()
    moved=(o.matrix_world.translation-before).length
    bone.location=orig
    bpy.context.view_layer.update()
    p=before
    dists={n:round(bbox_dist(p,n),4) for n in CH}
    nearest=min(dists,key=dists.get)
    res.append({"name":o.name,"bone":o["poko_bone"],
                "follows":moved>0.05,"move":round(moved,4),
                "nearest_part":nearest,"surface_dist":dists[nearest],
                "world":[round(x,3) for x in p],
                "expected_part": {"Hat":"H-RRS","Hair":"H-RRS","Face":"H-RRS",
                    "Neck":"T-RRS","Body":"T-RRS","Waist":"T-RRS",
                    "Shoulder":None,"Grip":None,"Root":None,"Ankle":None}.get(
                    o.name.split("Attachment")[0].replace("Left","").replace("Right",""),None)})
open("attachment_validation2.json","w",encoding="utf-8").write(json.dumps(res,indent=2))
print(json.dumps(res,indent=2))

import bpy, json
out = {"meshes": {}, "attachments": [], "materials": []}
for n in ["H-RRS","T-RRS","LA-RRS","RA-RRS","LL-RRS","RL-RRS"]:
    o = bpy.data.objects.get(n)
    out["meshes"][n] = {"uv":[u.name for u in o.data.uv_layers],
                        "mats":[s.material.name for s in o.material_slots]}
for o in bpy.context.scene.objects:
    if o.get("poko_attachment"):
        out["attachments"].append({"name":o.name,"bone":o.get("poko_bone"),
            "world":[round(x,4) for x in o.matrix_world.translation],
            "parent_type":o.parent_type})
for m in bpy.data.materials:
    if m.get("poko_material"):
        out["materials"].append({"name":m.name,"nodes":[n.type for n in m.node_tree.nodes]})
open("verify_result.json","w",encoding="utf-8").write(json.dumps(out,indent=2))

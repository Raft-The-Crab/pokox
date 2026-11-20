import bpy, json
out = {"file": bpy.data.filepath, "meshes": {}, "attachments": [], "materials": []}
for n in ["H-RRS","T-RRS","LA-RRS","RA-RRS","LL-RRS","RL-RRS"]:
    o = bpy.data.objects.get(n)
    out["meshes"][n] = {"uv": [u.name for u in o.data.uv_layers] if o else None,
                        "mats": [s.material.name for s in o.material_slots] if o else None}
for o in bpy.context.scene.objects:
    if o.get("poko_attachment"):
        out["attachments"].append({"name": o.name, "bone": o.get("poko_bone"),
                                   "parent": o.parent.name if o.parent else None,
                                   "world": [round(x,3) for x in o.matrix_world.translation]})
for m in bpy.data.materials:
    if m.get("poko_material"):
        out["materials"].append({"name": m.name, "nodes": [n.type for n in m.node_tree.nodes]})
print(json.dumps(out, indent=2))

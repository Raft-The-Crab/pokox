import bpy
print("ALL IMAGES IN FILE:")
for img in bpy.data.images:
    users = []
    for m in bpy.data.materials:
        if not m.use_nodes: continue
        trees=[m.node_tree]
        for ng in bpy.data.node_groups: trees.append(ng)
        for nt in trees:
            for n in nt.nodes:
                if n.type=='TEX_IMAGE' and n.image==img:
                    users.append(f"{m.name}/{n.name}")
    print(f"  {img.name!r} size={list(img.size)} packed={bool(img.packed_file)} path={img.filepath!r} users={users or 'UNASSIGNED'}")

# what does customFaces UV actually cover on the head?
h=bpy.data.objects["H-RRS"]
uc=h.data.uv_layers.get("customFaces")
if uc:
    coords=[tuple(round(x,4) for x in d.uv) for d in uc.data]
    nonzero=[c for c in coords if not (abs(c[0])<1e-5 and abs(c[1])<1e-5)]
    print(f"CUSTOMFACES UV: {len(coords)} loops, {len(nonzero)} non-zero")
    print(f"  sample non-zero: {nonzero[:6]}")

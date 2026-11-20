import bpy, json

def dump_tree(nt, prefix, seen):
    out = []
    if nt is None or id(nt) in seen:
        return out
    seen.add(id(nt))
    out.append(f"{prefix} TREE {nt.name} ({nt.bl_idname})")
    for n in nt.nodes:
        line = f"{prefix}  NODE {n.type} '{n.name}'"
        if n.type == 'TEX_IMAGE':
            img = n.image
            line += f" | image={img.name if img else 'NONE'}"
            if img:
                line += f" path={img.filepath!r} size={list(img.size)} packed={bool(img.packed_file)}"
        elif n.type == 'UVMAP':
            line += f" | uv_map={n.uv_map!r}"
        elif n.type == 'ATTRIBUTE':
            line += f" | attr={n.attribute_name!r}"
        elif n.type == 'GROUP':
            line += f" | group={n.node_tree.name if n.node_tree else 'NONE'}"
        out.append(line)
        if n.type == 'GROUP' and n.node_tree:
            out += dump_tree(n.node_tree, prefix + "    ", seen)
    for l in nt.links:
        out.append(f"{prefix}  LINK {l.from_node.name}.{l.from_socket.name} -> {l.to_node.name}.{l.to_socket.name}")
    return out

lines = []
h = bpy.data.objects.get("H-RRS")
lines.append(f"HEAD OBJECT: {h.name if h else None}")
if h:
    lines.append(f"UV LAYERS: {[u.name for u in h.data.uv_layers]}")
    for slot in h.material_slots:
        m = slot.material
        lines.append(f"MATERIAL SLOT: {m.name if m else None}")
        if m and m.use_nodes:
            lines += dump_tree(m.node_tree, "  ", set())

print("\n".join(lines))

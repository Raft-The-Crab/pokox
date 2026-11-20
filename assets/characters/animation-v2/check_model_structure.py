import bpy,json,hashlib,struct
from pathlib import Path
root=Path(__file__).resolve().parent.parent
chars=['H-RRS','T-RRS','LA-RRS','RA-RRS','LL-RRS','RL-RRS']
def floats(vals):
 h=hashlib.sha256()
 for v in vals:h.update(struct.pack('<d',float(v)))
 return h.hexdigest()
def capture(path):
 bpy.ops.wm.open_mainfile(filepath=str(path));bpy.context.view_layer.update();arm=next(o for o in bpy.context.scene.objects if o.type=='ARMATURE');snap={}
 snap['scene_mesh_armatures'] = sorted((o.name,o.type) for o in bpy.context.scene.objects if o.type in ('MESH','ARMATURE'))
 snap['armature_name']=arm.name;snap['bones']=[(b.name,b.parent.name if b.parent else None,floats([*b.head_local,*b.tail_local])) for b in arm.data.bones]
 snap['pose_constraints']=[(p.name,[(c.name,c.type) for c in p.constraints],p.custom_shape.name if p.custom_shape else None) for p in arm.pose.bones]
 snap['rig_drivers']=[(d.data_path,d.array_index,d.driver.expression) for d in arm.animation_data.drivers] if arm.animation_data else []
 snap['meshes']={}
 for n in chars:
  ob=bpy.data.objects[n];m=ob.data
  snap['meshes'][n]={'coords':floats(v for p in m.vertices for v in p.co),'topology':hashlib.sha256(str([list(p.vertices) for p in m.polygons]).encode()).hexdigest(),'uvs':[(uv.name,floats(v for l in uv.data for v in l.uv)) for uv in m.uv_layers], 'shape_keys':[(k.name,floats(v for point in k.data for v in point.co)) for k in m.shape_keys.key_blocks] if m.shape_keys else [],'materials':[x.name if x else None for x in m.materials], 'modifiers':[(x.name,x.type) for x in ob.modifiers], 'vertex_weights':floats(v for vert in m.vertices for g in vert.groups for v in (vert.index,g.group,g.weight))}
 m=bpy.data.materials.get('RRS-Mat') or bpy.data.materials.get('RSS-Mat');group=m.node_tree.nodes['customFacesTex_RRS'].node_tree
 snap['material']={'name':m.name,'nodes':sorted((n.name,n.bl_idname) for n in m.node_tree.nodes),'links':sorted((x.from_node.name,x.from_socket.name,x.to_node.name,x.to_socket.name) for x in m.node_tree.links),'group_nodes':sorted((n.name,n.bl_idname, n.image.name if n.type=='TEX_IMAGE' and n.image else None, n.uv_map if n.type=='UVMAP' else None) for n in group.nodes),'group_links':sorted((x.from_node.name,x.from_socket.name,x.to_node.name,x.to_socket.name) for x in group.links),'switch':m.node_tree.nodes['RRS-CCSwitcher'].inputs[0].default_value}
 img=bpy.data.images['RRS-Tex'];snap['packed_texture_sha256']=hashlib.sha256(img.packed_file.data).hexdigest()
 pins={o.name:{'parent':o.parent.name if o.parent else None,'bone':o.parent_bone,'type':o.parent_type,'xyz':[round(x,5) for x in o.matrix_world.translation]} for o in bpy.context.scene.objects if o.get('poko_attachment')}
 return snap,pins

results={}
for rig in ('BoyR6','BlockyR6'):
 before,pins_before=capture(root/'base'/f'{rig}_Adapted.blend')
 clean=lambda pins: {k:{x:v[x] for x in ('parent','bone','type')} for k,v in pins.items()}
 results[rig]={}
 for clip in ('Idle','Walk','Run','Jump'):
  after,pins=capture(root/'animation-v2'/f'{rig}_{clip}_v2.blend')
  differences=[k for k in before if before[k]!=after[k]]
  attachments_match=clean(pins_before)==clean(pins) and len(pins)==19
  results[rig][clip]={'structure_sections_match':not differences,'differences':differences,'attachment_parenting_matches':attachments_match,'attachment_count':len(pins)}
  assert not differences and attachments_match, (rig,clip,differences)
out={'checks':results,'sections_compared':list(before),'caveat':'This compares stored mesh, rig, material and attachment structures; animated poses and IK switch values deliberately differ. It does not establish every interactive behavior.'}
(root/'animation-v2/model_structure_check.json').write_text(json.dumps(out,indent=2)+'\n')
print(json.dumps(out))

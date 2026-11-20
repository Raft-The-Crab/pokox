import bpy,json
from pathlib import Path
P=Path(__file__).resolve().parent.parent;out=[]
for rig in ('BoyR6','BlockyR6'):
 bpy.ops.wm.open_mainfile(filepath=str(P/'face-packs'/f'{rig}_Face_Library.blend'));m=bpy.data.materials.get('RRS-Mat') or bpy.data.materials.get('RSS-Mat');g=m.node_tree.nodes['customFacesTex_RRS'].node_tree;images=sorted((i.name,bool(i.packed_file)) for i in bpy.data.images if i.name.startswith('face_'));assert len(images)==10 and all(p for _,p in images);assert g.nodes['Image Texture.001'].image.name=='face_happy';assert m.node_tree.nodes['RRS-CCSwitcher'].inputs[0].default_value==0
 out.append({'rig':rig,'file':'face library','packed_faces':images})
 for v, count in [('Shirt',3),('TShirt',3),('Pants',2),('Shirt_Pants',5),('TShirt_Pants',5)]:
  bpy.ops.wm.open_mainfile(filepath=str(P/'clothing'/rig/f'{rig}_{v}.blend'));layers=[]
  for n in ['T-RRS','LA-RRS','RA-RRS','LL-RRS','RL-RRS']:
   ob=bpy.data.objects[n];mat=ob.data.materials[0]
   for node in mat.node_tree.nodes:
    if node.name.startswith('Poko_') and node.type=='TEX_IMAGE':layers.append([n,node.name,node.image.name,bool(node.image.packed_file)])
  assert len(layers)==count and all(l[3] for l in layers),(rig,v,layers)
  assert [u.name for u in bpy.data.objects['H-RRS'].data.uv_layers]==['other','customFaces','UVMap']
  out.append({'rig':rig,'variant':v,'packed_garment_layers':layers})
(P/'clothing'/'look_validation.json').write_text(json.dumps(out,indent=2)+'\n');print('PASS: two face libraries, 20 packed face references, 10 outfit variants, head UV layers retained')

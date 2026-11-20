import bpy,json
from pathlib import Path
P=Path(__file__).resolve().parent.parent; results=[]
for rig in ['BoyR6','BlockyR6']:
 for clip in ['Walk','Jump']:
  a_path=P/'animation'/f'{rig}_{clip}.blend';look=P/'clothing'/rig/f'{rig}_Shirt_Pants.blend'
  bpy.ops.wm.open_mainfile(filepath=str(a_path));scene=bpy.context.scene;arm=next(x for x in scene.objects if x.type=='ARMATURE');f=9 if clip=='Walk' else 18;scene.frame_set(f);bpy.context.view_layer.update();ref={p.name:[v for r in p.matrix for v in r] for p in arm.pose.bones}
  bpy.ops.wm.open_mainfile(filepath=str(look));scene=bpy.context.scene;arm=next(x for x in scene.objects if x.type=='ARMATURE')
  with bpy.data.libraries.load(str(a_path)) as (src,dst):dst.actions=[f'{rig}_{clip}']
  arm.animation_data_create();arm.animation_data.action=dst.actions[0];meta=arm.pose.bones['rigmeta3'];meta['LLIK']=1.;meta['RLIK']=1.;meta['LLFF']=1.;meta['RLFF']=1.;arm.update_tag()
  scene.frame_set(f);bpy.context.view_layer.update();err=max(abs(x-y) for p in arm.pose.bones for x,y in zip(ref[p.name],[v for r in p.matrix for v in r]))
  results.append({'rig':rig,'clip':clip,'frame':f,'pose_matrix_max_error':err});print(rig,clip,'append pose error',err,flush=True);assert err<1e-4
(P/'clothing'/'append_action_check.json').write_text(json.dumps(results,indent=2)+'\n')

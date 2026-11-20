import bpy, math,json
from pathlib import Path
P=Path(__file__).resolve().parent; all=[]
for rig in ('BoyR6','BlockyR6'):
 for name in ('Idle','Walk','Run','Jump'):
  bpy.ops.wm.open_mainfile(filepath=str(P/f'{rig}_{name}.blend')); s=bpy.context.scene;a=next(o for o in s.objects if o.type=='ARMATURE'); period=int(s['poko_animation_period_frames']);loop=bool(s['poko_animation_loop']); assert a.animation_data and a.animation_data.action.name==f'{rig}_{name}'
  mats=[]; ground=[]; controls=[]
  for f in range(1,period+2):
   s.frame_set(f);bpy.context.view_layer.update();mats.append([v for p in a.pose.bones for row in p.matrix for v in row]);controls.append([tuple(a.pose.bones['LegIK.'+side].head) for side in 'LR'])
   dg=bpy.context.evaluated_depsgraph_get();mn=1e3
   for n in ('LL-RRS','RL-RRS'):
    ob=bpy.data.objects[n].evaluated_get(dg);mesh=ob.to_mesh();mn=min(mn,min((ob.matrix_world@v.co).z for v in mesh.vertices));ob.to_mesh_clear()
   ground.append(mn)
  close=max(abs(a-b) for a,b in zip(mats[0],mats[-1]));variation=max(abs(a-b) for a,b in zip(mats[0],mats[period//3]))
  row={'rig':rig,'animation':name,'fps':s.render.fps,'playback_frames':[s.frame_start,s.frame_end], 'loop':loop,'loop_endpoint_matrix_max_error':round(close,7),'sampled_pose_matrix_max_change':round(variation,6),'evaluated_leg_mesh_min_z':round(min(ground),5),'evaluated_leg_mesh_max_lowest_z':round(max(ground),5),'ik_switches':[a.pose.bones['rigmeta3'].get('LLIK'),a.pose.bones['rigmeta3'].get('RLIK')],'note':'In-place Blender evaluated pose checks; no runtime blending, foot lock, export, or subjective animation-quality proof.'}
  assert variation>0.001,(rig,name,variation)
  if loop:assert close<1e-4,(rig,name,close)
  all.append(row);print(row,flush=True)
(P/'animation_validation.json').write_text(json.dumps(all,indent=2)+'\n')

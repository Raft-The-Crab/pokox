"""Checks sampled positions after reopening each clip. Does not certify artistry."""
import bpy, json, math
from pathlib import Path
D=Path(__file__).resolve().parent;rows=[]
for rig in ('BoyR6','BlockyR6'):
 for name in ('Idle','Walk','Run','Jump'):
  bpy.ops.wm.open_mainfile(filepath=str(D/f'{rig}_{name}_v2.blend'));s=bpy.context.scene;a=next(o for o in s.objects if o.type=='ARMATURE');period=int(s['poko_animation_period_frames']);loop=bool(s['poko_animation_loop']);mats=[];limits=[];footlocs=[]
  for half in range(0,period*2+1):
   f=1+half/2;s.frame_set(int(f),subframe=f%1);bpy.context.view_layer.update();dg=bpy.context.evaluated_depsgraph_get();z=[]
   for n in ('LL-RRS','RL-RRS'):
    ob=bpy.data.objects[n].evaluated_get(dg);m=ob.to_mesh();z.append(min((ob.matrix_world@v.co).z for v in m.vertices));ob.to_mesh_clear()
   limits.append(z);footlocs.append([tuple(a.pose.bones['LegIK.'+side].head) for side in 'LR']);mats.append([v for p in a.pose.bones for row in p.matrix for v in row])
  closure=max(abs(a-b) for a,b in zip(mats[0],mats[-1]));motion=max(abs(a-b) for a,b in zip(mats[0],mats[len(mats)//3]));maxjump=max(math.dist(footlocs[i][side],footlocs[i+1][side]) for i in range(len(footlocs)-1) for side in range(2))
  row={'rig':rig,'clip':name,'fps':s.render.fps,'playback_frames':[s.frame_start,s.frame_end],'loop':loop,'loop_endpoint_matrix_max_error':closure,'sampled_pose_max_change':motion,'lowest_leg_z_sampled_every_half_frame':min(min(z) for z in limits),'highest_both_feet_lower_bound':max(min(z) for z in limits),'max_ik_target_move_per_half_frame':maxjump,'note':'Numerical smoke test, not proof of visual quality, foot locking, transitions or final export.'}
  assert a.animation_data.action.name==f'{rig}_{name}_v2';assert motion>.001
  if loop:assert closure<1e-4
  print('CHECK',row,flush=True);rows.append(row)
(D/'refined_validation.json').write_text(json.dumps(rows,indent=2)+'\n')

"""Quarter-frame ground and stance-target diagnostics for editable rigs."""
import bpy,math,json
from pathlib import Path
D=Path(__file__).resolve().parent;rows=[]
for rig in ('BoyR6','BlockyR6'):
 for clip in ('Idle','Walk','Run','Jump'):
  bpy.ops.wm.open_mainfile(filepath=str(D/f'{rig}_{clip}_v2.blend'));s=bpy.context.scene;a=next(o for o in s.objects if o.type=='ARMATURE');period=int(s['poko_animation_period_frames']);lowest=10;worst=None;max_err=0;float_n=0;stance_n=0;previous=None
  if clip=='Walk':stride,stance=.82,.60
  elif clip=='Run':stride,stance=1.05,.34
  else:stride=stance=0
  for i in range(period*4+1):
   f=1+i/4;s.frame_set(int(f),subframe=f%1);bpy.context.view_layer.update();dg=bpy.context.evaluated_depsgraph_get();heads=[];mins=[]
   for side,n in [('L','LL-RRS'),('R','RL-RRS')]:
    heads.append(tuple(a.pose.bones['LegIK.'+side].head));o=bpy.data.objects[n].evaluated_get(dg);mesh=o.to_mesh();z=min((o.matrix_world@v.co).z for v in mesh.vertices);o.to_mesh_clear();mins.append(z)
    if z<lowest:lowest=z;worst=f
   if clip in ('Walk','Run'):
    t=(f-1)/period
    for k in range(2):
     phase=(t+.5*k)%1
     if .06<phase<stance-.06:
      stance_n+=1
      if mins[k]>.06:float_n+=1
      if previous:
       expected=-(stride/stance)/(period*4);err=abs((heads[k][1]-previous[k][1])-expected);max_err=max(max_err,err)
   previous=heads
  row={'rig':rig,'clip':clip,'minimum_leg_z_quarter_frame':lowest,'worst_frame':worst,'stance_samples':stance_n,'stance_samples_sole_above_0_06':float_n,'max_stance_target_y_error_per_quarter_frame':max_err,'note':'Stance target test assumes nominal in-place treadmill speed. Sole height is a rough metric, not proof of ground lock or quality.'};rows.append(row);print('GAIT',row,flush=True)
(D/'gait_checks.json').write_text(json.dumps(rows,indent=2)+'\n')

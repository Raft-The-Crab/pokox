import bpy, math, json
from mathutils import Vector
from pathlib import Path
P=Path(__file__).resolve().parent.parent;A=P/'animation-v2';D=P/'transitions-v2';D.mkdir(exist_ok=True)
clips=[('Idle',1,'Walk',1),('Walk',1,'Run',1),('Run',1,'Walk',1),('Walk',1,'Idle',1),('Idle',1,'Jump',1),('Jump',44,'Idle',1)]
channels=[('Master','location'),('Hip','rotation_euler'),('UpperTorso','rotation_euler'),('Head','rotation_euler'),('UpperArm.L','rotation_euler'),('UpperArm.R','rotation_euler'),('LowerArm.L','rotation_euler'),('LowerArm.R','rotation_euler'),('Hand.L','rotation_euler'),('Hand.R','rotation_euler'),('LegIK.L','rotation_euler'),('LegIK.R','rotation_euler'),('LegIK.L','location'),('LegIK.R','location')]
def capture(rig,clip,f):
 bpy.ops.wm.open_mainfile(filepath=str(A/f'{rig}_{clip}_v2.blend'));bpy.context.scene.frame_set(f);bpy.context.view_layer.update();arm=next(o for o in bpy.context.scene.objects if o.type=='ARMATURE')
 return {(name,prop):tuple(getattr(arm.pose.bones[name],prop)) for name,prop in channels}, {p.name:tuple(v for r in p.matrix for v in r) for p in arm.pose.bones}
report=[]
for rig in ('BoyR6','BlockyR6'):
 for src,sf,dst,df in clips:
  path=D/f'{rig}_{src}_to_{dst}_v2.blend'
  if path.exists():raise RuntimeError('Refusing overwrite: '+str(path))
  v0,ref0=capture(rig,src,sf);v1,ref1=capture(rig,dst,df)
  bpy.ops.wm.open_mainfile(filepath=str(P/'base'/f'{rig}_Adapted.blend'));s=bpy.context.scene;arm=next(o for o in s.objects if o.type=='ARMATURE');p=arm.pose.bones
  for key in ['LLIK','RLIK','LLFF','RLFF']:p['rigmeta3'][key]=1.
  arm.update_tag();s.render.fps=24;s.frame_start=1;s.frame_end=9
  for step in range(17):
   f=1+step/2;s.frame_set(int(f),subframe=f%1);t=(f-1)/8;u=t*t*(3-2*t)
   for n,prop in channels:
    p[n].rotation_mode='XYZ';vals=[a+(b-a)*u for a,b in zip(v0[(n,prop)],v1[(n,prop)])];setattr(p[n],prop,vals);p[n].keyframe_insert(data_path=prop,frame=f,group=n)
   if f not in (1,9):
    for iteration in range(12):
     bpy.context.view_layer.update();dg=bpy.context.evaluated_depsgraph_get();changed=False
     for side,mesh_name in [('L','LL-RRS'),('R','RL-RRS')]:
      ob=bpy.data.objects[mesh_name].evaluated_get(dg);mesh=ob.to_mesh();low=min((ob.matrix_world@v.co).z for v in mesh.vertices);ob.to_mesh_clear()
      if low<-.001:
       control=p['LegIK.'+side];inv=control.rotation_euler.to_matrix() @ control.matrix.to_3x3().inverted()
       control.location+=inv @ Vector((0,0,-low+.001));control.keyframe_insert(data_path='location',frame=f,group='LegIK.'+side);changed=True
     if not changed:break
  arm.animation_data.action.name=f'{rig}_{src}_to_{dst}_v2';arm.animation_data.action.use_fake_user=True
  s['poko_transition_note']='One-shot control-space pose blend; use from indicated source frame to indicated destination frame. Review foot sliding and phase timing.'
  s.frame_set(1);bpy.context.view_layer.update();err0=max(abs(x-y) for b in p for x,y in zip(ref0[b.name],(v for r in b.matrix for v in r)))
  s.frame_set(9);bpy.context.view_layer.update();err1=max(abs(x-y) for b in p for x,y in zip(ref1[b.name],(v for r in b.matrix for v in r)))
  low=100
  for f in range(1,10):
   for sub in (0,.5):
    if f==9 and sub:continue
    s.frame_set(f,subframe=sub);dg=bpy.context.evaluated_depsgraph_get()
    for n in ('LL-RRS','RL-RRS'):
     o=bpy.data.objects[n].evaluated_get(dg);m=o.to_mesh();low=min(low,min((o.matrix_world@v.co).z for v in m.vertices));o.to_mesh_clear()
  s.frame_set(1);bpy.ops.wm.save_as_mainfile(filepath=str(path))
  row={'rig':rig,'from':src,'source_frame':sf,'to':dst,'destination_frame':df,'frames':9,'source_pose_max_error':err0,'destination_pose_max_error':err1,'lowest_leg_z_in_sampled_frames':low,'note':'Endpoint pose comparison and floor sample only; blending feel and foot sliding require review.'}
  print('TRANSITION',row,flush=True);report.append(row)
  assert err0<.0001 and err1<.0001
(D/'transition_validation.json').write_text(json.dumps(report,indent=2)+'\n')

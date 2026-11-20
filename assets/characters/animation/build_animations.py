import bpy, math, sys, json
from pathlib import Path
from mathutils import Vector
P=Path(__file__).resolve().parents[3]; base=P/'assets/characters/base'; out=P/'assets/characters/animation'; out.mkdir(exist_ok=True)
SPECS={'Idle':(96,True),'Walk':(32,True),'Run':(22,True),'Jump':(40,False)}
def smooth(a,b,t):
 t=max(0.,min(1.,t));t=t*t*(3-2*t);return a+(b-a)*t
def interp(keys,f):
 if f<=keys[0][0]:return keys[0][1]
 for (x,a),(y,b) in zip(keys,keys[1:]):
  if f<=y:return smooth(a,b,(f-x)/(y-x))
 return keys[-1][1]
def foot(t,stride,lift,stance):
 t=t%1
 if t < stance:return stride*(.5-t/stance),0.
 u=(t-stance)/(1-stance)
 return stride*(-.5+(u*u*(3-2*u))),lift*math.sin(math.pi*u)**1.3
for rig in ('BoyR6','BlockyR6'):
 for name,(period,loop) in SPECS.items():
  path=out/f'{rig}_{name}.blend'
  if path.exists():raise RuntimeError('Refusing to overwrite '+str(path))
  bpy.ops.wm.open_mainfile(filepath=str(base/f'{rig}_Adapted.blend'))
  scene=bpy.context.scene; arm=next(o for o in scene.objects if o.type=='ARMATURE');pb=arm.pose.bones
  # Preserve original constraints and use its existing, driven IK switches.
  pb['rigmeta3']['LLIK']=1.;pb['rigmeta3']['RLIK']=1.;pb['rigmeta3']['LLFF']=1.;pb['rigmeta3']['RLFF']=1.;arm.update_tag()
  # Place footsteps in the original armature-space ground plane.
  scene.render.fps=24;scene.frame_start=1;scene.frame_end=period if loop else period+1
  if arm.animation_data:arm.animation_data.action=None
  scene.frame_set(1);bpy.context.view_layer.update()
  feet={side:pb['LegIK.'+side].bone.head_local.copy() for side in 'LR'}
  for frame in range(1,period+2):
   scene.frame_set(frame)
   t=(frame-1)/period;phase=2*math.pi*t
   def rot(n,xyz):
    p=pb[n];p.rotation_mode='XYZ';p.rotation_euler=xyz;p.keyframe_insert(data_path='rotation_euler',frame=frame,group=n)
   def loc(n,xyz):
    p=pb[n];p.location=xyz;p.keyframe_insert(data_path='location',frame=frame,group=n)
   if name=='Idle':
    bounce=.018*math.sin(phase);pitch=.013*math.sin(phase); sway=.012*math.sin(phase*.0+phase)
    stride=lift=0.; stance=.6; arm_amp=.025
   elif name=='Walk':
    bounce=.045*(1-math.cos(2*phase))-.05;pitch=.035; sway=.025*math.sin(phase)
    stride=.80;lift=.18;stance=.60;arm_amp=.30
   elif name=='Run':
    bounce=-.10+.04*(1-math.cos(2*phase));pitch=.11;sway=.045*math.sin(phase)
    stride=1.0;lift=.32;stance=.40;arm_amp=.50
   else:
    bounce=interp([(1,0),(5,-.20),(10,.02),(18,1.02),(23,1.10),(30,.20),(34,-.16),(41,0)],frame)
    pitch=interp([(1,0),(5,-.09),(11,.08),(22,.03),(34,-.08),(41,0)],frame);sway=0.;stride=lift=0.;stance=.6;arm_amp=0.
   # Master is aligned with world vertical for these source rigs.
   localz=pb['Master'].bone.matrix_local.to_3x3().inverted() @ Vector((0,0,bounce))
   loc('Master',localz)
   rot('UpperTorso',(pitch,0.,sway))
   rot('Head',(-pitch*.45,0.,-sway*.6))
   if name=='Jump':
    aa=interp([(1,0),(5,-.14),(13,.30),(20,.60),(28,.40),(34,-.12),(41,0)],frame)
    rot('UpperArm.L',(aa,0.,.65*math.sin(math.pi*t)))
    rot('UpperArm.R',(aa,0.,-.65*math.sin(math.pi*t)))
    bend=interp([(1,0),(5,.18),(16,.40),(24,.48),(34,.30),(41,0)],frame)
   else:
    rot('UpperArm.L',(-arm_amp*math.sin(phase),.015*math.sin(phase),-.025))
    rot('UpperArm.R',(arm_amp*math.sin(phase),-.015*math.sin(phase),.025))
    bend=.06 if name=='Idle' else (.18 if name=='Walk' else .42)
   rot('LowerArm.L',(bend,0,0));rot('LowerArm.R',(bend,0,0))
   # First evaluate body motion, then solve for control-local translations.
   for side in 'LR':pb['LegIK.'+side].location=(0,0,0)
   bpy.context.view_layer.update()
   for i,side in enumerate('LR'):
    if name=='Jump':
     footz=interp([(1,0),(10,0),(18,.38),(23,.48),(30,.08),(34,0),(41,0)],frame) + max(0.,bounce)*.8
     forward=interp([(1,0),(10,0),(18,.15),(23,.20),(30,.08),(34,0),(41,0)],frame)*(1 if side=='L' else -.55)
    else:forward,footz=foot(t+i*.5,stride,lift,stance)
    target=feet[side]+Vector((0,forward,footz)); p=pb['LegIK.'+side]; delta=target-p.matrix.translation
    p.location=p.matrix.to_3x3().inverted() @ delta
    p.keyframe_insert(data_path='location',frame=frame,group='LegIK.'+side)
   # Correct floor penetration against each evaluated leg mesh independently.
   # This is a Blender-side guard, not a substitute for foot-lock review.
   for iteration in range(12):
    bpy.context.view_layer.update();dg=bpy.context.evaluated_depsgraph_get();changed=False
    for side,mesh_name in [('L','LL-RRS'),('R','RL-RRS')]:
     ob=bpy.data.objects[mesh_name].evaluated_get(dg);mesh=ob.to_mesh()
     low=min((ob.matrix_world@v.co).z for v in mesh.vertices);ob.to_mesh_clear()
     if low < -.001:
      p=pb['LegIK.'+side];p.location += p.matrix.to_3x3().inverted() @ Vector((0,0,-low+.001))
      p.keyframe_insert(data_path='location',frame=frame,group='LegIK.'+side);changed=True
    if not changed:break
  action=arm.animation_data.action;action.name=f'{rig}_{name}';action.use_fake_user=True
  scene.timeline_markers.new('START',frame=1)
  scene.timeline_markers.new('LOOP_END' if loop else 'LAND',frame=(period+1 if loop else 34))
  scene['poko_animation_note']='In-place, +Y forward; source rig constraints remain active. Bake evaluated deformation before non-Blender export.'
  scene['poko_animation_loop']=loop;scene['poko_animation_period_frames']=period
  scene.frame_set(1);bpy.context.view_layer.update()
  bpy.ops.wm.save_as_mainfile(filepath=str(path))
  print('CREATED',path,flush=True)

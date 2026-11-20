"""Generate separate R6 clips from untouched full adapted bases. Requires Blender 5.2.
No existing output or input is overwritten. This is an editable Blender rig pass.
"""
import bpy, math
from pathlib import Path
from mathutils import Vector
P=Path(__file__).resolve().parents[3]; base=P/'assets/characters/base'; out=Path(__file__).resolve().parent
SPECS={'Idle':(120,True),'Walk':(32,True),'Run':(22,True),'Jump':(43,False)}
def ease(t):
 t=max(0.,min(1.,t));return t*t*(3.-2.*t)
def interp(keys,f):
 if f<=keys[0][0]:return keys[0][1]
 for (x,a),(y,b) in zip(keys,keys[1:]):
  if f<=y:return a+(b-a)*ease((f-x)/(y-x))
 return keys[-1][1]
def foot(phase,stride,lift,stance):
 """Continuous velocity at footfall and toe-off; -Y movement during stance."""
 t=phase%1
 if t<stance:
  v=t/stance
  y=stride*(.5-v);z=0.
  pitch=.12*(1-ease(v/.25))-.14*ease((v-.70)/.30)
 else:
  u=(t-stance)/(1-stance);m=-stride*(1-stance)/stance
  y=(2*u**3-3*u**2+1)*(-stride/2)+(u**3-2*u**2+u)*m+(-2*u**3+3*u**2)*(stride/2)+(u**3-u**2)*m
  z=lift*math.sin(math.pi*u)**2
  pitch=-.14*(1-ease(u/.45))+.12*ease((u-.55)/.45)
 return y,z,pitch
for rig in ('BoyR6','BlockyR6'):
 for name,(period,loop) in SPECS.items():
  path=out/f'{rig}_{name}_v2.blend'
  if path.exists():raise RuntimeError('Refusing to overwrite '+str(path))
  bpy.ops.wm.open_mainfile(filepath=str(base/f'{rig}_Adapted.blend'))
  scene=bpy.context.scene;arm=next(o for o in scene.objects if o.type=='ARMATURE');pb=arm.pose.bones
  for n in ('LLIK','RLIK','LLFF','RLFF'):pb['rigmeta3'][n]=1.
  arm.update_tag();scene.render.fps=24;scene.frame_start=1;scene.frame_end=period if loop else period+1
  if arm.animation_data:arm.animation_data.action=None
  scene.frame_set(1);bpy.context.view_layer.update();feet={side:pb['LegIK.'+side].bone.head_local.copy() for side in 'LR'}
  for sample in range(period*2+1):
   frame=1+sample/2
   scene.frame_set(int(frame),subframe=frame%1);t=(frame-1)/period;phase=2*math.pi*t
   def rot(n,xyz):
    p=pb[n];p.rotation_mode='XYZ';p.rotation_euler=xyz;p.keyframe_insert(data_path='rotation_euler',frame=frame,group=n)
   def loc(n,xyz):
    p=pb[n];p.location=xyz;p.keyframe_insert(data_path='location',frame=frame,group=n)
   if name=='Idle':
    bounce=.008*math.sin(phase); shift=-.018*math.sin(phase);hiptwist=.012*math.sin(phase);hiproll=.010*math.sin(phase);pitch=-.012*math.sin(phase); chesttwist=-.013*math.sin(phase);chestroll=-.008*math.sin(phase);stride=lift=0.;stance=.60
   elif name=='Walk':
    bounce=-.075+.032*(1-math.cos(2*phase));shift=-.040*math.cos(phase);hiptwist=.045*math.cos(phase);hiproll=.018*math.cos(phase);pitch=-.025-.008*math.cos(2*phase);chesttwist=-.075*math.cos(phase-.12);chestroll=-.018*math.cos(phase);stride=.82;lift=.17;stance=.60
   elif name=='Run':
    bounce=-.14+.085*(1+math.cos(2*phase+.32*math.pi));shift=-.055*math.cos(phase);hiptwist=.055*math.cos(phase);hiproll=.025*math.cos(phase);pitch=-.12-.018*math.cos(2*phase);chesttwist=-.09*math.cos(phase-.10);chestroll=-.028*math.cos(phase);stride=1.05;lift=.42;stance=.34
   else:
    if 10<=frame<=32:
     u=(frame-10)/22; bounce=4*1.05*u*(1-u)
    else:bounce=interp([(1,0),(6,-.17),(10,0),(32,0),(36,-.15),(44,0)],frame)
    shift=0.;hiptwist=0.;hiproll=0.;chesttwist=0.;chestroll=0.
    pitch=interp([(1,0),(6,-.13),(10,.035),(17,-.05),(24,-.04),(32,-.025),(36,-.13),(44,0)],frame)
    stride=lift=0.;stance=.6
   root_local=pb['Master'].bone.matrix_local.to_3x3().inverted() @ Vector((shift,0,bounce));loc('Master',root_local)
   rot('Hip',(0,hiptwist,hiproll));rot('UpperTorso',(pitch,chesttwist,chestroll));rot('Head',(-pitch*.5,-chesttwist*.65,-chestroll*.65))
   for i,side in enumerate('LR'):
    sign=1 if side=='L' else -1
    if name=='Idle':
     x=.018*math.sin(phase+(.25 if side=='L' else -.25));z=-sign*.025;bend=.08+.015*math.sin(phase-.3)
    elif name=='Walk':
     x=-sign*.38*math.cos(phase-.07);z=-sign*(.025+.015*math.sin(phase));bend=.15+.045*(1+sign*math.cos(phase-.6));
    elif name=='Run':
     x=-sign*.68*math.cos(phase-.08);z=-sign*.06;bend=.55+.15*(1+sign*math.cos(phase-.6))
    else:
     x=interp([(1,0),(6,-.22),(10,-.08),(16,.60),(22,.78),(29,.35),(33,-.08),(37,-.18),(44,0)],frame)
     lateral=interp([(1,0),(6,.06),(10,.08),(17,.52),(22,.70),(29,.50),(33,.16),(38,.05),(44,0)],frame)
     z=sign*lateral; bend=interp([(1,.08),(6,.22),(10,.16),(17,.30),(22,.42),(29,.32),(36,.25),(44,.08)],frame)
    rot('UpperArm.'+side,(x,sign*.012*math.sin(phase),z));rot('LowerArm.'+side,(bend,0,0));rot('Hand.'+side,(.025*math.sin(phase-.4)*sign,0,0))
   # Solve target translation with zero control rotation, then apply foot roll.
   for side in 'LR':pb['LegIK.'+side].location=(0,0,0);pb['LegIK.'+side].rotation_mode='XYZ';pb['LegIK.'+side].rotation_euler=(0,0,0)
   bpy.context.view_layer.update()
   for i,side in enumerate('LR'):
    if name=='Jump':
     if 10<=frame<=32:
      u=(frame-10)/22; footz=max(0.,bounce)+.30*math.sin(math.pi*u)**2; forward=(.12 if side=='L' else -.08)*math.sin(math.pi*u); roll=.06*math.sin(math.pi*u)
     else:footz=forward=roll=0.
    elif name=='Idle':forward=footz=roll=0.
    else:forward,footz,roll=foot(t+i*.5,stride,lift,stance)
    p=pb['LegIK.'+side];target=feet[side]+Vector((0,forward,footz));delta=target-p.matrix.translation
    p.location=p.matrix.to_3x3().inverted() @ delta;p.keyframe_insert(data_path='location',frame=frame,group='LegIK.'+side)
    rot('LegIK.'+side,(roll,0,0))
   # Raise a target only when the evaluated limb crosses the ground. This is
   # a guard, not a substitute for animation, foot-lock and deformation review.
   for iteration in range(12):
    bpy.context.view_layer.update();dg=bpy.context.evaluated_depsgraph_get();changed=False
    for side,mesh_name in [('L','LL-RRS'),('R','RL-RRS')]:
     ob=bpy.data.objects[mesh_name].evaluated_get(dg);mesh=ob.to_mesh();low=min((ob.matrix_world@v.co).z for v in mesh.vertices);ob.to_mesh_clear()
     if low<-.001:
      p=pb['LegIK.'+side];inv_basis=p.rotation_euler.to_matrix() @ p.matrix.to_3x3().inverted()
      p.location += inv_basis @ Vector((0,0,-low+.001));p.keyframe_insert(data_path='location',frame=frame,group='LegIK.'+side);changed=True
    if not changed:break
  action=arm.animation_data.action;action.name=f'{rig}_{name}_v2';action.use_fake_user=True
  scene.timeline_markers.new('START',frame=1);scene.timeline_markers.new('LOOP_END' if loop else 'LAND',frame=(period+1 if loop else 32))
  scene['poko_animation_note']='Refined in-place editable rig animation, +Y forward. Uses Blender IK and foot-follow; bake evaluated deform motion for export.'
  scene['poko_animation_loop']=loop;scene['poko_animation_period_frames']=period
  scene.frame_set(1);bpy.context.view_layer.update();bpy.ops.wm.save_as_mainfile(filepath=str(path));print('CREATED',path,flush=True)

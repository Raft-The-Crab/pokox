import bpy,json
from pathlib import Path
P=Path(__file__).resolve().parent;out=[]
for rig in ('BoyR6','BlockyR6'):
 for kind in ('Idle','Walk','Run','Jump'):
  bpy.ops.wm.open_mainfile(filepath=str(P/f'{rig}_{kind}.blend'));s=bpy.context.scene;lowest=100;worst=0
  for f in range(1,s.frame_end+1):
   s.frame_set(f,subframe=.5);dg=bpy.context.evaluated_depsgraph_get()
   for n in ['LL-RRS','RL-RRS']:
    ob=bpy.data.objects[n].evaluated_get(dg);m=ob.to_mesh();z=min((ob.matrix_world@v.co).z for v in m.vertices);ob.to_mesh_clear()
    if z<lowest:lowest=z;worst=f+.5
  print(rig,kind,'min Z',round(lowest,5),'frame',worst,flush=True);out.append({'rig':rig,'clip':kind,'lowest_leg_z_at_half_frames':lowest,'worst_frame':worst})
(P/'animation_subframe_check.json').write_text(json.dumps(out,indent=2)+'\n')

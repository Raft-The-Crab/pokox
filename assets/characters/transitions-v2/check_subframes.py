import bpy,json
from pathlib import Path
D=Path(__file__).resolve().parent;out=[]
for path in sorted(D.glob('*_v2.blend')):
 bpy.ops.wm.open_mainfile(filepath=str(path));s=bpy.context.scene;lowest=100;when=0
 for i in range(33):
  f=1+i/4;s.frame_set(int(f),subframe=f%1);dg=bpy.context.evaluated_depsgraph_get()
  for n in ('LL-RRS','RL-RRS'):
   ob=bpy.data.objects[n].evaluated_get(dg);m=ob.to_mesh();z=min((ob.matrix_world@v.co).z for v in m.vertices);ob.to_mesh_clear()
   if z<lowest:lowest=z;when=f
 out.append({'file':path.name,'minimum_leg_z_quarter_frame':lowest,'frame':when});print('TRANSITION',path.name,round(lowest,5),flush=True)
(D/'quarter_frame_checks.json').write_text(json.dumps(out,indent=2)+'\n')

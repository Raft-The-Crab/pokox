import bpy,json
from pathlib import Path
P=Path(__file__).resolve().parent.parent;records=json.loads((P/'transitions/transition_validation.json').read_text());worst=0
for r in records:
 def pose(path,f):
  bpy.ops.wm.open_mainfile(filepath=str(path));bpy.context.scene.frame_set(f);bpy.context.view_layer.update();a=next(o for o in bpy.context.scene.objects if o.type=='ARMATURE');return {p.name:tuple(v for row in p.matrix for v in row) for p in a.pose.bones}
 def diff(a,b):return max(abs(v-w) for name in a for v,w in zip(a[name],b[name]))
 n=r['rig'];src=pose(P/'animation'/f"{n}_{r['from']}.blend",r['source_frame']);dst=pose(P/'animation'/f"{n}_{r['to']}.blend",r['destination_frame']);path=P/'transitions'/f"{n}_{r['from']}_to_{r['to']}.blend";e0=diff(src,pose(path,1));e1=diff(dst,pose(path,9));worst=max(worst,e0,e1);assert max(e0,e1)<1e-4
print('PASS',len(records),'transitions against final animation files; maximum pose matrix error',worst)

# Separate-process demonstration of a proposed runtime material; does not save the GLB.
# blender --background --python-exit-code 1 --python preview_face_glb.py -- <glb> <overlay.png> <new-output.png>
import bpy,sys,math,os
from mathutils import Vector
p, overlay_path, out = sys.argv[-3:]; view='back'
if not bpy.app.background: raise RuntimeError('Run only in a separate background Blender process')
if os.path.exists(out): raise RuntimeError('Refusing to overwrite output: '+out)
bpy.ops.wm.read_factory_settings(use_empty=True)
bpy.ops.import_scene.gltf(filepath=p)
scene=bpy.context.scene
# Simulate the proposed future engine material on the imported GLB: base UV
# channel 2 plus optional alpha face overlay in channel 1. In-memory only.
head=bpy.data.objects['H-RRS']; layers=head.data.uv_layers
assert len(layers)==3
oldmat=head.data.materials[0]
base_image=next(n.image for n in oldmat.node_tree.nodes if n.type=='TEX_IMAGE' and n.image)
overlay=bpy.data.images.load(os.path.abspath(overlay_path))
mat=bpy.data.materials.new('RoundTrip_FacePrototype');mat.use_nodes=True
nodes=mat.node_tree.nodes;nodes.clear();links=mat.node_tree.links
output_node=nodes.new('ShaderNodeOutputMaterial');bsdf=nodes.new('ShaderNodeBsdfPrincipled');bsdf.inputs['Roughness'].default_value=.5
base=nodes.new('ShaderNodeTexImage');base.image=base_image
face=nodes.new('ShaderNodeTexImage');face.image=overlay
uvbase=nodes.new('ShaderNodeUVMap');uvbase.uv_map=layers[2].name
uvface=nodes.new('ShaderNodeUVMap');uvface.uv_map=layers[1].name
mix=nodes.new('ShaderNodeMixRGB');mix.blend_type='MIX'
links.new(uvbase.outputs['UV'],base.inputs['Vector']);links.new(uvface.outputs['UV'],face.inputs['Vector'])
links.new(face.outputs['Alpha'],mix.inputs[0]);links.new(base.outputs['Color'],mix.inputs[1]);links.new(face.outputs['Color'],mix.inputs[2])
links.new(mix.outputs['Color'],bsdf.inputs['Base Color']);links.new(bsdf.outputs['BSDF'],output_node.inputs['Surface'])
head.data.materials.clear();head.data.materials.append(mat)

names={'H-RRS','T-RRS','LA-RRS','RA-RRS','LL-RRS','RL-RRS'}
for ob in scene.objects:
 if ob.type in {'MESH','CURVE','SURFACE','FONT','META','VOLUME','LIGHT','CAMERA'}:
  ob.hide_render=ob.name not in names
for n in names:
 ob=bpy.data.objects[n]; ob.hide_render=False
# New cameras and lights exist only in memory, never saved to the model.
def point_at(o,p): o.rotation_euler=(Vector(p)-o.location).to_track_quat('-Z','Y').to_euler()
cam_data=bpy.data.cameras.new('AuditCamera'); cam=bpy.data.objects.new('AuditCamera',cam_data);scene.collection.objects.link(cam);scene.camera=cam
cam.location=(6,-14,6) if view=='front' else (-6,14,6)
point_at(cam,(0,0,2.5));cam_data.type='ORTHO';cam_data.ortho_scale=6.7
for name,location,energy,size in [('AuditKey',(4,-6,9),1400,5),('AuditFill',(-5,-3,5),950,5),('AuditBack',(0,6,8),1300,4)]:
 data=bpy.data.lights.new(name,'AREA');data.energy=energy;data.shape='DISK';data.size=size; obj=bpy.data.objects.new(name,data);scene.collection.objects.link(obj);obj.location=location;point_at(obj,(0,0,2.3))
scene.render.engine='CYCLES'; scene.cycles.samples=16;scene.cycles.use_denoising=True;scene.cycles.device='CPU';scene.render.threads_mode='FIXED';scene.render.threads=4
scene.render.resolution_x=640;scene.render.resolution_y=640;scene.render.resolution_percentage=100
scene.render.image_settings.file_format='PNG';scene.render.film_transparent=True
scene.view_settings.view_transform='Standard';scene.render.filepath=out
bpy.ops.render.render(write_still=True)
print('RENDERED',out)

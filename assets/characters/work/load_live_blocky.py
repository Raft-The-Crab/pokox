import json
import mcp_client

code = (
    "import bpy\n"
    "bpy.ops.wm.open_mainfile(filepath="
    "'C:/Users/mysti.LAPTOP.000/Desktop/Project Poko/assets/characters/work/BlockyR6_poko.blend')\n"
    "result = {'file': bpy.data.filepath, 'objects': len(bpy.context.scene.objects)}\n"
)
print(json.dumps(mcp_client.send("execute_code", {"code": code}), indent=2))

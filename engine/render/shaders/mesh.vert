#version 450
// ENG-19/20: indexed mesh vertex — position+normal from the vertex buffer,
// transformed by the per-frame camera view*projection (std140 mat4).
layout(location = 0) in vec3 aPos;
layout(location = 1) in vec3 aNormal;
layout(location = 0) out vec3 vNormal;
layout(set = 0, binding = 0) uniform Camera { mat4 view_proj; };
void main() {
    gl_Position = view_proj * vec4(aPos, 1.0);
    vNormal = aNormal;
}

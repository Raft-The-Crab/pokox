#version 450
layout(location = 0) out vec3 color;
// Near red triangle comes first; farther green triangle comes second.
// The depth test must preserve red where they overlap.
const vec3 positions[6] = vec3[](
    vec3(-0.75, -0.60, 0.2), vec3(0.45, -0.60, 0.2), vec3(-0.15, 0.65, 0.2),
    vec3(-0.45, -0.60, 0.8), vec3(0.75, -0.60, 0.8), vec3(0.15, 0.65, 0.8));
void main() {
    gl_Position = vec4(positions[gl_VertexIndex], 1.0);
    color = gl_VertexIndex < 3 ? vec3(1.0, 0.0, 0.0) : vec3(0.0, 1.0, 0.0);
}

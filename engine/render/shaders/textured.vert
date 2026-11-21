#version 450
layout(location = 0) out vec2 uv;
// ENG-18: fullscreen quad generated without a vertex buffer, two triangles.
const vec2 positions[6] = vec2[](
    vec2(-1.0, -1.0), vec2(1.0, -1.0), vec2(-1.0, 1.0),
    vec2(-1.0, 1.0),  vec2(1.0, -1.0), vec2(1.0, 1.0));
const vec2 uvs[6] = vec2[](
    vec2(0.0, 1.0), vec2(1.0, 1.0), vec2(0.0, 0.0),
    vec2(0.0, 0.0), vec2(1.0, 1.0), vec2(1.0, 0.0));
void main() {
    const int i = gl_VertexIndex;
    gl_Position = vec4(positions[i], 0.0, 1.0);
    uv = uvs[i];
}

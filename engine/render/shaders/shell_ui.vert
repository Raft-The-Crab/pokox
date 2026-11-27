#version 450
layout(location = 0) in vec3 aPos;
layout(location = 1) in vec3 aNormal;
layout(std140, set = 0, binding = 0) uniform FrameData {
    vec2 scale;
    vec2 translate;
} frame_data;
layout(location = 0) out vec3 vNormal;
void main() {
    // UI logical space (origin top-left) to Vulkan clip space.
    gl_Position = vec4(aPos.xy * frame_data.scale + frame_data.translate, 0.0, 1.0);
    vNormal = aNormal;
}

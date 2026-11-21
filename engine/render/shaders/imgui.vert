#version 450
layout(location = 0) in vec2 aPos;
layout(location = 1) in vec2 aUV;
layout(location = 2) in vec4 aColor;
layout(std140, set = 0, binding = 0) uniform FrameData {
    vec2 scale;
    vec2 translate;
} frame_data;
layout(location = 0) out vec2 vUV;
layout(location = 1) out vec4 vColor;
void main() {
    // Display-space position to Vulkan clip space; see ImGui::GetDrawData().
    gl_Position = vec4(aPos * frame_data.scale + frame_data.translate, 0.0, 1.0);
    vUV = aUV;
    vColor = aColor;
}

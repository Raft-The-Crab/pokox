#version 450
layout(location = 0) in vec3 color;
layout(location = 0) out vec4 out_color;
layout(std140, set = 0, binding = 0) uniform FrameData {
    vec4 animated_color;
} frame_data;
void main() {
    // The red/near triangle is animated; the far triangle remains green.
    out_color = color.r > 0.5 ? frame_data.animated_color : vec4(color, 1.0);
}

#version 450
layout(location = 0) in vec2 vUV;
layout(location = 1) in vec4 vColor;
layout(location = 0) out vec4 out_color;
layout(set = 0, binding = 1) uniform sampler2D FontTexture;
void main() {
    out_color = vColor * texture(FontTexture, vUV);
}

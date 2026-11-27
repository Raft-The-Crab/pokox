#version 450
layout(location = 0) in vec3 vNormal;
layout(location = 0) out vec4 out_color;
layout(set = 0, binding = 1) uniform sampler2D FontTexture;
void main() {
    vec4 atlas = texture(FontTexture, vec2(0.5, 0.5));
    out_color = vec4(0.95, 0.96, 0.98, 0.90 + 0.0 * atlas.a);
}

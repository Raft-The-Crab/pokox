#version 450
// ENG-19: lambert-ish shading from the interpolated vertex normal so the
// cube's face orientations are visible. Fixed light until ENG-21.
layout(location = 0) in vec3 vNormal;
layout(location = 0) out vec4 out_color;
void main() {
    const vec3 light_dir = normalize(vec3(0.4, 0.7, 0.6));
    const float diffuse = max(dot(normalize(vNormal), light_dir), 0.0);
    const float shade = 0.25 + 0.75 * diffuse;
    out_color = vec4(vec3(shade), 1.0);
}

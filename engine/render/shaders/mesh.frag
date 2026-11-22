#version 450
// World-space surface normals and surface-to-light direction; no model transform yet.
layout(location = 0) in vec3 vNormal;
layout(location = 0) out vec4 out_color;
layout(std140, set = 0, binding = 1) uniform DirectionalLight {
    vec4 direction_ambient;
};
void main() {
    // Scale first to avoid overflow for very large normals; a zero normal
    // receives ambient only instead of invoking normalize(vec3(0)).
    const float scale = max(max(abs(vNormal.x), abs(vNormal.y)), abs(vNormal.z));
    const vec3 normal = scale > 0.0 ? normalize(vNormal / scale) : vec3(0.0);
    const float diffuse = max(dot(normal, direction_ambient.xyz), 0.0);
    const float shade = direction_ambient.w + (1.0 - direction_ambient.w) * diffuse;
    out_color = vec4(vec3(shade), 1.0);
}

#include "poko/resource/pokomesh.hpp"

#include <algorithm>
#include <array>
#include <cerrno>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <limits>

namespace poko::resource {
namespace {

constexpr std::size_t kHeaderSize = 20;
constexpr std::size_t kVertexBytes = 24;  // float3 pos + float3 normal
constexpr std::size_t kMaxFileBytes = 64ull * 1024 * 1024;
constexpr std::uint32_t kMaxVertices = 4u * 1024 * 1024;
constexpr std::uint32_t kMaxIndices = 16u * 1024 * 1024;

std::unique_ptr<PokoMesh> fail(std::string* error, const char* message) {
  if (error) *error = message;
  return nullptr;
}

std::uint32_t read_u32(const std::uint8_t* p) {
  std::uint32_t v;
  std::memcpy(&v, p, sizeof(v));
  return v;  // little-endian hosts are the supported target
}

float read_f32(const std::uint8_t* p) {
  float v;
  std::memcpy(&v, p, sizeof(v));
  return v;
}

bool finite_vec3(const float* v) {
  return std::isfinite(v[0]) && std::isfinite(v[1]) && std::isfinite(v[2]);
}

}  // namespace

std::unique_ptr<PokoMesh> parse_pokomesh(const std::uint8_t* data, std::size_t size,
                                         std::string* error) {
  if (error) error->clear();
  if (!data || size < kHeaderSize) return fail(error, "file too small for PMES header");
  static constexpr std::array<std::uint8_t, 4> kMagic{'P', 'M', 'E', 'S'};
  if (std::memcmp(data, kMagic.data(), kMagic.size()) != 0)
    return fail(error, "bad magic (expected PMES)");
  const std::uint32_t version = read_u32(data + 4);
  if (version != 1) return fail(error, "unsupported PMES version");
  const std::uint32_t vcount = read_u32(data + 8);
  const std::uint32_t icount = read_u32(data + 12);
  const std::uint32_t stride = read_u32(data + 16);
  if (vcount == 0 || icount == 0)
    return fail(error, "empty vertex or index list");
  if (vcount > kMaxVertices || icount > kMaxIndices)
    return fail(error, "vertex or index count exceeds limit");
  if (icount % 3 != 0) return fail(error, "index count is not a multiple of 3");
  if (stride < kVertexBytes)
    return fail(error, "vertex stride below position+normal size");

  const std::uint64_t vertex_bytes =
      static_cast<std::uint64_t>(vcount) * stride;
  const std::uint64_t index_bytes = static_cast<std::uint64_t>(icount) * 4;
  const std::uint64_t expected = kHeaderSize + vertex_bytes + index_bytes;
  if (expected > kMaxFileBytes) return fail(error, "mesh exceeds size limit");
  if (size != expected)
    return fail(error, "file size does not match declared layout");

  auto mesh = std::make_unique<PokoMesh>();
  mesh->vertices.resize(vcount);
  mesh->indices.resize(icount);
  const std::uint8_t* vp = data + kHeaderSize;
  for (std::uint32_t i = 0; i < vcount; ++i) {
    auto& v = mesh->vertices[i];
    for (int c = 0; c < 3; ++c) {
      v.position[c] = read_f32(vp + c * 4);
      v.normal[c] = read_f32(vp + kVertexBytes / 2 + c * 4);
    }
    if (!finite_vec3(v.position) || !finite_vec3(v.normal))
      return fail(error, "non-finite vertex data");
    vp += stride;
  }
  const std::uint8_t* ip = vp;
  for (std::uint32_t i = 0; i < icount; ++i) {
    const std::uint32_t index = read_u32(ip + i * 4);
    if (index >= vcount) return fail(error, "index out of range");
    mesh->indices[i] = index;
  }
  return mesh;
}

std::unique_ptr<PokoMesh> load_pokomesh(const std::string& path, std::string* error) {
  if (error) error->clear();
  std::ifstream file(path, std::ios::binary | std::ios::ate);
  if (!file) return fail(error, "cannot open file");
  const auto end = file.tellg();
  if (end <= 0 || static_cast<std::uint64_t>(end) > kMaxFileBytes)
    return fail(error, "file missing or too large");
  std::vector<std::uint8_t> data(static_cast<std::size_t>(end));
  file.seekg(0);
  if (!file.read(reinterpret_cast<char*>(data.data()), end))
    return fail(error, "failed to read file");
  return parse_pokomesh(data.data(), data.size(), error);
}

}  // namespace poko::resource

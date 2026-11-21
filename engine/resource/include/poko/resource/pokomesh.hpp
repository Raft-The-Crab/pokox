#pragma once
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

namespace poko::resource {

// ENG-19: hand-written "PMES" binary mesh — the seed format AST-04 will
// supersede with quantized/delta-compressed PokoMesh. Little-endian layout:
//
//   offset  size  field
//   0       4     magic "PMES"
//   4       4     u32 version (must be 1)
//   8       4     u32 vertex_count (>0)
//   12      4     u32 index_count  (>0, multiple of 3)
//   16      4     u32 vertex_stride (>=24; v1 reads pos+normal at fixed offsets)
//   20      ..    vertex_count * vertex_stride bytes
//                 per vertex: float3 position @0, float3 normal @12
//   ..       ..    index_count * 4 bytes of u32 indices (< vertex_count)
//
// The file size must match the declared layout exactly; every field is
// bounds-checked and index values are validated against vertex_count.
struct PokoMeshVertex {
  float position[3];
  float normal[3];
};

struct PokoMesh {
  std::vector<PokoMeshVertex> vertices;
  std::vector<std::uint32_t> indices;
};

// Loads a PMES file. Returns nullptr and fills `error` on any malformed
// input; never throws for bad data (allocation failure aside).
std::unique_ptr<PokoMesh> load_pokomesh(const std::string& path,
                                        std::string* error = nullptr);
// Same parse over an in-memory buffer (used by tests and future streaming).
std::unique_ptr<PokoMesh> parse_pokomesh(const std::uint8_t* data, std::size_t size,
                                         std::string* error = nullptr);

}  // namespace poko::resource

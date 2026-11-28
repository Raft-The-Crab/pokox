#pragma once
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "poko/resource/pokomesh.hpp"

namespace poko::resource {

// AST-01: deterministic glTF 2.0 binary (.glb) importer.
//
// Scope of this slice — the subset the demo assets need:
//   * .glb container only (JSON chunk + optional BIN chunk), version 2;
//   * one mesh (`meshes[mesh_index]`, default 0), every triangle-mode (4)
//     primitive of it, concatenated in primitive order;
//   * attributes POSITION (required) and NORMAL (optional, computed when
//     absent), indices (u8/u16/u32, or none = sequential);
//   * the local transform of the first node that references the mesh
//     (`matrix`, else composed TRS). Node hierarchy, skins, morph targets,
//     sparse accessors, .gltf+external .bin, Draco and material data are not
//     imported; a primitive using them is skipped and counted.
//
// Output is the PMES v1 vertex layout (float3 position, float3 normal, u32
// indices) so `parse_pokomesh` reads it back. Equal input bytes always
// produce byte-identical output; nothing depends on hashing order, locale or
// the clock.
struct GltfImportStats {
  std::uint32_t mesh_count = 0;
  std::uint32_t primitive_count = 0;
  std::uint32_t skipped_primitives = 0;
  std::uint32_t triangle_count = 0;
};

// Parses a .glb buffer. Returns nullptr and fills `error` (never throws for
// bad data); `stats` is optional and filled on success and on failure after
// the container parsed.
std::unique_ptr<PokoMesh> import_glb(const std::uint8_t* data, std::size_t size,
                                     std::string* error = nullptr,
                                     GltfImportStats* stats = nullptr,
                                     std::uint32_t mesh_index = 0);

// Same import from disk (64 MiB cap, like the PMES loader).
std::unique_ptr<PokoMesh> load_glb(const std::string& path, std::string* error = nullptr,
                                   GltfImportStats* stats = nullptr,
                                   std::uint32_t mesh_index = 0);

// Deterministic PMES v1 serialization of an imported mesh.
std::vector<std::uint8_t> serialize_pokomesh(const PokoMesh& mesh);

// AST-01 sidecar: `<asset>.glb.meta`, stable key order, no timestamps.
struct AssetMeta {
  std::string source_name;      // file name only, never a full path
  std::uint64_t source_bytes = 0;
  std::uint64_t source_fnv64 = 0;  // FNV-1a over the .glb bytes
  std::uint32_t mesh_index = 0;
  std::uint32_t vertex_count = 0;
  std::uint32_t index_count = 0;
  std::uint32_t triangle_count = 0;
};

std::uint64_t fnv1a64(const std::uint8_t* data, std::size_t size);

std::string serialize_meta(const AssetMeta& meta);
bool write_meta(const std::string& path, const AssetMeta& meta, std::string* error = nullptr);
bool read_meta(const std::string& path, AssetMeta* meta, std::string* error = nullptr);

}  // namespace poko::resource

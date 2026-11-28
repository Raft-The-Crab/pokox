// ENG-19: PMES binary mesh loader accept/reject coverage.
// AST-01: glTF 2.0 binary import, determinism and .meta sidecar coverage.
#include "poko/resource/gltf_import.hpp"
#include "poko/resource/pokomesh.hpp"

#include <array>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <filesystem>
#include <fstream>
#include <string>
#include <vector>

namespace {
int failures = 0;
#define CHECK(cond) do { if (!(cond)) { std::fprintf(stderr, "FAIL %s:%d: %s\n", __FILE__, __LINE__, #cond); ++failures; } } while (0)

void put32(std::vector<std::uint8_t>& v, std::uint32_t x) {
  for (int i = 0; i < 4; ++i) v.push_back(static_cast<std::uint8_t>(x >> (8 * i)));
}
void putf(std::vector<std::uint8_t>& v, float f) {
  std::uint32_t u;
  static_assert(sizeof(u) == sizeof(f));
  std::memcpy(&u, &f, 4);
  put32(v, u);
}

// One triangle: 3 verts (pos+normal), 3 indices, stride 24.
std::vector<std::uint8_t> make_pmes(std::uint32_t version = 1,
                                    std::uint32_t stride = 24,
                                    std::uint32_t bad_index = 0xffffffff) {
  std::vector<std::uint8_t> v;
  v.insert(v.end(), {'P','M','E','S'});
  put32(v, version); put32(v, 3); put32(v, 3); put32(v, stride);
  const float pos[3][3] = {{-0.5f,-0.5f,0.f},{0.5f,-0.5f,0.f},{0.f,0.5f,0.f}};
  for (int i = 0; i < 3; ++i) {
    for (float f : pos[i]) putf(v, f);
    putf(v, 0.f); putf(v, 0.f); putf(v, 1.f);  // +z normal
  }
  put32(v, 0); put32(v, 1); put32(v, bad_index == 0xffffffff ? 2 : bad_index);
  return v;
}

void write(const std::filesystem::path& p, const std::vector<std::uint8_t>& d) {
  std::ofstream f(p, std::ios::binary);
  f.write(reinterpret_cast<const char*>(d.data()), static_cast<std::streamsize>(d.size()));
}
}  // namespace

int main() {
  namespace fs = std::filesystem;
  const auto dir = fs::temp_directory_path() / "pokox_pomes_test";
  std::error_code ec;
  fs::remove_all(dir, ec);
  fs::create_directories(dir, ec);

  {
    write(dir / "tri.pmes", make_pmes());
    std::string error;
    auto mesh = poko::resource::load_pokomesh((dir / "tri.pmes").string(), &error);
    CHECK(mesh && error.empty());
    CHECK(mesh && mesh->vertices.size() == 3 && mesh->indices.size() == 3);
    CHECK(mesh && mesh->vertices[2].position[1] == 0.5f);
    CHECK(mesh && mesh->vertices[0].normal[2] == 1.f);
    CHECK(mesh && mesh->indices[2] == 2);
    // In-memory parse path.
    const auto bytes = make_pmes();
    auto parsed = poko::resource::parse_pokomesh(bytes.data(), bytes.size());
    CHECK(parsed && parsed->vertices.size() == 3);
  }
  {
    // Bad magic.
    auto bad = make_pmes(); bad[0] = 'X';
    write(dir / "bad_magic.pmes", bad);
    CHECK(!poko::resource::load_pokomesh((dir / "bad_magic.pmes").string()));
  }
  {
    // Unsupported version.
    write(dir / "bad_ver.pmes", make_pmes(2));
    CHECK(!poko::resource::load_pokomesh((dir / "bad_ver.pmes").string()));
  }
  {
    // Stride below pos+normal.
    write(dir / "bad_stride.pmes", make_pmes(1, 16));
    CHECK(!poko::resource::load_pokomesh((dir / "bad_stride.pmes").string()));
  }
  {
    // Index out of range.
    write(dir / "bad_index.pmes", make_pmes(1, 24, 7));
    CHECK(!poko::resource::load_pokomesh((dir / "bad_index.pmes").string()));
  }
  {
    // Truncated file.
    auto trunc = make_pmes(); trunc.resize(trunc.size() - 4);
    write(dir / "trunc.pmes", trunc);
    CHECK(!poko::resource::load_pokomesh((dir / "trunc.pmes").string()));
  }
  {
    // Non-finite vertex data.
    auto nan = make_pmes();
    // First vertex x position -> NaN.
    const float qnan = std::numeric_limits<float>::quiet_NaN();
    std::uint32_t u; std::memcpy(&u, &qnan, 4);
    for (int i = 0; i < 4; ++i) nan[20 + i] = static_cast<std::uint8_t>(u >> (8 * i));
    write(dir / "nan.pmes", nan);
    CHECK(!poko::resource::load_pokomesh((dir / "nan.pmes").string()));
  }
  {
    CHECK(!poko::resource::load_pokomesh((dir / "missing.pmes").string()));
    CHECK(!poko::resource::parse_pokomesh(nullptr, 0));
    const std::uint8_t tiny[8] = {};
    CHECK(!poko::resource::parse_pokomesh(tiny, sizeof(tiny)));
  }

  // AST-01: glTF 2.0 binary (.glb) import, PMES serialization and .meta.
  {
    const auto near = [](float a, float b) { return a - b < 1e-4f && b - a < 1e-4f; };
    auto make_bin = [](bool with_normals, std::uint16_t i0, std::uint16_t i1, std::uint16_t i2) {
      std::vector<std::uint8_t> bin;
      const float positions[3][3] = {
          {-0.5f, -0.5f, 0.0f}, {0.5f, -0.5f, 0.0f}, {0.0f, 0.5f, 0.0f}};
      for (const auto& p : positions)
        for (float f : p) putf(bin, f);
      if (with_normals)
        for (int i = 0; i < 3; ++i) {
          putf(bin, 0.0f);
          putf(bin, 0.0f);
          putf(bin, 1.0f);
        }
      for (std::uint16_t v : {i0, i1, i2}) {
        bin.push_back(static_cast<std::uint8_t>(v & 0xFF));
        bin.push_back(static_cast<std::uint8_t>(v >> 8));
      }
      return bin;
    };
    const auto make_glb = [](const std::string& json, const std::vector<std::uint8_t>& bin) {
      std::vector<std::uint8_t> body;
      std::string padded = json;
      while (padded.size() % 4 != 0) padded.push_back(' ');
      std::vector<std::uint8_t> padded_bin = bin;
      while (padded_bin.size() % 4 != 0) padded_bin.push_back(0);
      put32(body, static_cast<std::uint32_t>(padded.size()));
      put32(body, 0x4E4F534Au);
      body.insert(body.end(), padded.begin(), padded.end());
      if (!padded_bin.empty()) {
        put32(body, static_cast<std::uint32_t>(padded_bin.size()));
        put32(body, 0x004E4942u);
        body.insert(body.end(), padded_bin.begin(), padded_bin.end());
      }
      std::vector<std::uint8_t> glb;
      glb.insert(glb.end(), {'g', 'l', 'T', 'F'});
      put32(glb, 2);
      put32(glb, static_cast<std::uint32_t>(12 + body.size()));
      glb.insert(glb.end(), body.begin(), body.end());
      return glb;
    };
    const std::string json_normals = R"({"asset":{"version":"2.0"},"buffers":[{"byteLength":78}],"bufferViews":[{"buffer":0,"byteOffset":0,"byteLength":36},{"buffer":0,"byteOffset":36,"byteLength":36},{"buffer":0,"byteOffset":72,"byteLength":6}],"accessors":[{"bufferView":0,"componentType":5126,"count":3,"type":"VEC3"},{"bufferView":1,"componentType":5126,"count":3,"type":"VEC3"},{"bufferView":2,"componentType":5123,"count":3,"type":"SCALAR"}],"meshes":[{"primitives":[{"attributes":{"POSITION":0,"NORMAL":1},"indices":2}]}],"nodes":[{"mesh":0,"translation":[1,2,3]}]})";
    const std::string json_flat = R"({"asset":{"version":"2.0"},"buffers":[{"byteLength":48}],"bufferViews":[{"buffer":0,"byteOffset":0,"byteLength":36},{"buffer":0,"byteOffset":36,"byteLength":6}],"accessors":[{"bufferView":0,"componentType":5126,"count":3,"type":"VEC3"},{"bufferView":1,"componentType":5123,"count":3,"type":"SCALAR"}],"meshes":[{"primitives":[{"attributes":{"POSITION":0},"indices":1}]}]})";
    std::string error;
    {
      // Normals + node translation: positions move, normals stay unit length.
      const auto glb = make_glb(json_normals, make_bin(true, 0, 1, 2));
      poko::resource::GltfImportStats stats;
      auto mesh = poko::resource::import_glb(glb.data(), glb.size(), &error, &stats);
      CHECK(mesh != nullptr);
      CHECK(mesh && mesh->vertices.size() == 3 && mesh->indices.size() == 3);
      CHECK(mesh && near(mesh->vertices[0].position[0], 0.5f));
      CHECK(mesh && near(mesh->vertices[0].position[1], 1.5f));
      CHECK(mesh && near(mesh->vertices[0].position[2], 3.0f));
      CHECK(mesh && near(mesh->vertices[0].normal[2], 1.0f));
      CHECK(mesh && mesh->indices[2] == 2);
      CHECK(stats.primitive_count == 1 && stats.triangle_count == 1 && stats.mesh_count == 1);
      if (mesh) {
        const auto bytes = poko::resource::serialize_pokomesh(*mesh);
        auto reparsed = poko::resource::parse_pokomesh(bytes.data(), bytes.size(), &error);
        CHECK(reparsed && reparsed->vertices.size() == 3 && reparsed->indices[1] == 1);
        auto again = poko::resource::import_glb(glb.data(), glb.size(), &error);
        CHECK(again && poko::resource::serialize_pokomesh(*again) == bytes);
      }
      poko::resource::AssetMeta meta;
      meta.source_name = "tri.glb";
      meta.source_bytes = glb.size();
      meta.source_fnv64 = poko::resource::fnv1a64(glb.data(), glb.size());
      meta.vertex_count = 3;
      meta.index_count = 3;
      meta.triangle_count = 1;
      CHECK(poko::resource::write_meta((dir / "tri.glb.meta").string(), meta, &error));
      poko::resource::AssetMeta back;
      CHECK(poko::resource::read_meta((dir / "tri.glb.meta").string(), &back, &error));
      CHECK(back.source_name == "tri.glb" && back.source_fnv64 == meta.source_fnv64);
      CHECK(back.vertex_count == 3 && back.index_count == 3 && back.triangle_count == 1);
      CHECK(poko::resource::serialize_meta(meta) == poko::resource::serialize_meta(back));
    }
    {
      // Missing NORMAL: computed +z; load_glb reads the same data from disk.
      const auto glb = make_glb(json_flat, make_bin(false, 0, 1, 2));
      write(dir / "flat.glb", glb);
      auto mesh = poko::resource::load_glb((dir / "flat.glb").string(), &error);
      CHECK(mesh && mesh->vertices.size() == 3);
      CHECK(mesh && near(mesh->vertices[0].normal[2], 1.0f));
      CHECK(mesh && near(mesh->vertices[0].position[0], -0.5f));
    }
    {
      // Node `matrix`: uniform scale 2 is applied to positions.
      const std::string json_matrix = R"({"asset":{"version":"2.0"},"buffers":[{"byteLength":78}],"bufferViews":[{"buffer":0,"byteOffset":0,"byteLength":36},{"buffer":0,"byteOffset":36,"byteLength":36},{"buffer":0,"byteOffset":72,"byteLength":6}],"accessors":[{"bufferView":0,"componentType":5126,"count":3,"type":"VEC3"},{"bufferView":1,"componentType":5126,"count":3,"type":"VEC3"},{"bufferView":2,"componentType":5123,"count":3,"type":"SCALAR"}],"meshes":[{"primitives":[{"attributes":{"POSITION":0,"NORMAL":1},"indices":2}]}],"nodes":[{"mesh":0,"matrix":[2,0,0,0,0,2,0,0,0,0,2,0,0,0,0,1]}]})";
      const auto matrix_glb = make_glb(json_matrix, make_bin(true, 0, 1, 2));
      auto mesh = poko::resource::import_glb(matrix_glb.data(), matrix_glb.size());
      CHECK(mesh != nullptr);
      CHECK(mesh && near(mesh->vertices[1].position[0], 1.0f));
    }
    {
      // Rejections: bad index, points mode, container and schema errors.
      const auto out_of_range = make_glb(json_flat, make_bin(false, 0, 1, 7));
      CHECK(!poko::resource::import_glb(out_of_range.data(), out_of_range.size(), &error));
      CHECK(!error.empty());
      const std::string json_points = R"({"asset":{"version":"2.0"},"buffers":[{"byteLength":48}],"bufferViews":[{"buffer":0,"byteOffset":0,"byteLength":36}],"accessors":[{"bufferView":0,"componentType":5126,"count":3,"type":"VEC3"}],"meshes":[{"primitives":[{"attributes":{"POSITION":0},"mode":0}]}]})";
      poko::resource::GltfImportStats skipped;
      const auto points = make_glb(json_points, make_bin(false, 0, 1, 2));
      CHECK(!poko::resource::import_glb(points.data(), points.size(), &error, &skipped));
      CHECK(skipped.skipped_primitives == 1);
      const auto good = make_glb(json_normals, make_bin(true, 0, 1, 2));
      auto bad_magic = good;
      bad_magic[0] = 'X';
      CHECK(!poko::resource::import_glb(bad_magic.data(), bad_magic.size(), &error));
      auto bad_version = good;
      bad_version[4] = 1;
      CHECK(!poko::resource::import_glb(bad_version.data(), bad_version.size(), &error));
      auto truncated = good;
      truncated.resize(truncated.size() - 4);
      CHECK(!poko::resource::import_glb(truncated.data(), truncated.size(), &error));
      auto bad_length = good;
      bad_length[8] = 0;
      CHECK(!poko::resource::import_glb(bad_length.data(), bad_length.size(), &error));
      CHECK(!poko::resource::import_glb(nullptr, 0));
      const auto no_mesh = make_glb(R"({"asset":{"version":"2.0"},"meshes":[]})", {});
      CHECK(!poko::resource::import_glb(no_mesh.data(), no_mesh.size(), &error));
      const auto old_asset =
          make_glb(R"({"asset":{"version":"1.0"},"meshes":[{"primitives":[]}]})", {});
      CHECK(!poko::resource::import_glb(old_asset.data(), old_asset.size(), &error));
      const auto bad_accessor = make_glb(
          R"({"asset":{"version":"2.0"},"bufferViews":[{"buffer":0,"byteOffset":0,"byteLength":36}],"accessors":[],"meshes":[{"primitives":[{"attributes":{"POSITION":5}}]}]})",
          make_bin(false, 0, 1, 2));
      CHECK(!poko::resource::import_glb(bad_accessor.data(), bad_accessor.size(), &error));
      // A meta file that is not an ast-01 v1 sidecar is rejected.
      write(dir / "stale.meta", std::vector<std::uint8_t>{'{', '}'});
      poko::resource::AssetMeta stale;
      CHECK(!poko::resource::read_meta((dir / "stale.meta").string(), &stale, &error));
    }
  }

  fs::remove_all(dir, ec);
  if (failures == 0) std::puts("PASS: PMES mesh loader accept/reject paths");
  return failures ? 1 : 0;
}

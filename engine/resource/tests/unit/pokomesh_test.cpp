// ENG-19: PMES binary mesh loader accept/reject coverage.
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

  fs::remove_all(dir, ec);
  if (failures == 0) std::puts("PASS: PMES mesh loader accept/reject paths");
  return failures ? 1 : 0;
}

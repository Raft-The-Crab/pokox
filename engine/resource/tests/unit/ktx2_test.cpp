// Regression coverage for the supported uncompressed KTX2 subset.
#include "poko/resource/ktx2.hpp"
#include <cstdio>
#include <filesystem>
#include <fstream>
#include <string>
#include <vector>

namespace {
int failures = 0;
#define CHECK(cond) do { if (!(cond)) { \
  std::fprintf(stderr, "FAIL line %d: %s\n", __LINE__, #cond); ++failures; \
} } while (0)
void put32(std::vector<std::uint8_t>& v, std::uint32_t x) {
  for (int i = 0; i < 4; ++i) v.push_back(static_cast<std::uint8_t>(x >> (8 * i)));
}
void put64(std::vector<std::uint8_t>& v, std::uint64_t x) {
  for (int i = 0; i < 8; ++i) v.push_back(static_cast<std::uint8_t>(x >> (8 * i)));
}
void set32(std::vector<std::uint8_t>& v, std::size_t offset, std::uint32_t x) {
  for (int i = 0; i < 4; ++i) v[offset + i] = static_cast<std::uint8_t>(x >> (8 * i));
}
void set64(std::vector<std::uint8_t>& v, std::size_t offset, std::uint64_t x) {
  for (int i = 0; i < 8; ++i) v[offset + i] = static_cast<std::uint8_t>(x >> (8 * i));
}
// Hand-built 2D RGBA8 fixture with the KTX2 80-byte header, level index,
// basic DFD and smallest-first mip payload order. No third-party generator.
std::vector<std::uint8_t> make_ktx2(std::uint32_t format = 37, bool mip = false) {
  std::vector<std::uint8_t> v;
  const std::uint8_t id[] = {0xab,'K','T','X',' ','2','0',0xbb,'\r','\n',0x1a,'\n'};
  v.insert(v.end(), id, id + 12);
  const std::uint32_t size = mip ? 4 : 2, levels = mip ? 2 : 1;
  put32(v, format); put32(v, 1); put32(v, size); put32(v, size); put32(v, 0);
  put32(v, 0); put32(v, 1); put32(v, levels); put32(v, 0);
  const std::uint32_t dfd_offset = 80 + 24 * levels, dfd_size = 92;
  put32(v, dfd_offset); put32(v, dfd_size); put32(v, 0); put32(v, 0);
  put64(v, 0); put64(v, 0);
  const std::uint64_t image_offset = dfd_offset + dfd_size;
  const std::uint64_t base_len = size * size * 4;
  put64(v, image_offset + (mip ? 16 : 0)); put64(v, base_len); put64(v, base_len);
  if (mip) { put64(v, image_offset); put64(v, 16); put64(v, 16); }
  put32(v, dfd_size); put32(v, 0); put32(v, (88u << 16) | 2u);
  const bool srgb = format == 43 || format == 50;
  put32(v, 1u | (1u << 8) | ((srgb ? 2u : 1u) << 16));
  put32(v, 0); put32(v, 4); put32(v, 0);
  for (unsigned i = 0; i < 4; ++i) {
    const unsigned channel = i == 3 ? 15 : (format == 44 || format == 50 ? 2-i : i);
    put32(v, (i * 8) | (7u << 16) | (channel << 24));
    put32(v, 0); put32(v, 0); put32(v, 255);
  }
  if (mip) for (int i = 0; i < 16; ++i) v.push_back(static_cast<std::uint8_t>(200+i));
  for (std::uint64_t i = 0; i < base_len; ++i) v.push_back(static_cast<std::uint8_t>(i));
  return v;
}
void write(const std::filesystem::path& p, const std::vector<std::uint8_t>& d) {
  std::ofstream out(p, std::ios::binary);
  out.write(reinterpret_cast<const char*>(d.data()), static_cast<std::streamsize>(d.size()));
}
}
int main() {
  namespace fs = std::filesystem;
  const auto dir = fs::temp_directory_path() / "poko_eng18_ktx2";
  fs::create_directories(dir);
  const auto file = dir / "review.ktx2";
  std::string error = "stale";
  write(file, make_ktx2());
  auto img = poko::resource::load_ktx2(file, &error);
  CHECK(img && img->width == 2 && img->height == 2 && img->mips.size() == 1 &&
        img->mips[0].pixels.size() == 16 && img->mips[0].pixels[15] == 15);
  CHECK(error.empty());
  auto zero_levels = make_ktx2(); set32(zero_levels, 40, 0); write(file, zero_levels);
  CHECK(poko::resource::load_ktx2(file) != nullptr);
  write(file, make_ktx2(37, true));
  auto mips = poko::resource::load_ktx2(file);
  CHECK(mips && mips->mips.size() == 2 && mips->mips[0].pixels.size() == 64 &&
        mips->mips[1].width == 2 && mips->mips[1].pixels[0] == 200);
  for (const auto fmt : {37u, 43u, 44u, 50u}) {
    write(file, make_ktx2(fmt)); auto p = poko::resource::load_ktx2(file);
    CHECK(p && static_cast<std::uint32_t>(p->format) == fmt);
  }
  const auto rejected = [&](std::vector<std::uint8_t> data) {
    write(file, data); std::string why; auto result = poko::resource::load_ktx2(file, &why);
    CHECK(!result && !why.empty());
  };
  auto data = make_ktx2(); data[0] = 0; rejected(data);
  data = make_ktx2(); set32(data, 44, 1); rejected(data); // supercompressed
  data = make_ktx2(); set32(data, 12, 100); rejected(data); // unsupported format
  data = make_ktx2(); set32(data, 28, 1); rejected(data); // 3D
  data = make_ktx2(); set32(data, 32, 1); rejected(data); // array
  data = make_ktx2(); set32(data, 40, 33); rejected(data); // too many levels
  data = make_ktx2(); set32(data, 20, 0xffffffffu); set32(data, 24, 0xffffffffu); rejected(data);
  data = make_ktx2(); set32(data, 52, 0); rejected(data); // missing DFD
  data = make_ktx2(); set64(data, 80, 0xfffffffffffffff0ull); rejected(data);
  data = make_ktx2(); set64(data, 88, 15); rejected(data); // incorrect level size
  data = make_ktx2(); data.pop_back(); rejected(data);
  CHECK(!poko::resource::load_ktx2(dir / "missing.ktx2"));
  if (failures) { std::fprintf(stderr, "%d check(s) failed\n", failures); return 1; }
  std::puts("PASS: KTX2 2D header, formats, mip chain, and invalid inputs");
  return 0;
}

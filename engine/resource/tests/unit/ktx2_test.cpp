// ENG-18: KTX2 uncompressed loader — accept/reject paths on a hand-built file.
#include "poko/resource/ktx2.hpp"

#include <cstdio>
#include <cstring>
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

// Minimal valid KTX2: 2x2 RGBA8, 1 mip, uncompressed.
std::vector<std::uint8_t> make_ktx2(std::uint32_t vk_format = 37,
                                    std::uint32_t supercompression = 0,
                                    std::uint32_t w = 2, std::uint32_t h = 2) {
  std::vector<std::uint8_t> v;
  const char id[12] = {'\xAB','K','T','X',' ','2','0','\xBB','\r','\n','\x1A','\n'};
  v.insert(v.end(), id, id + 12);
  put32(v, vk_format); put32(v, 1); put32(v, w); put32(v, h); put32(v, 1);
  put32(v, 1); put32(v, 1); put32(v, 1); put32(v, supercompression);
  put64(v, 0); put64(v, 0); put64(v, 0); put64(v, 0); put64(v, 0); put64(v, 0);
  // level index: 1 level × 24 bytes {dataOffset, dataLength, rawLength}
  const auto data_off = 96 + 24;
  const auto px = static_cast<std::uint64_t>(w) * h * 4;
  put64(v, data_off); put64(v, px); put64(v, px);
  // DFD/KVD/SGD omitted (offsets are 0); level data follows index.
  for (std::uint64_t i = 0; i < px; ++i) v.push_back(static_cast<std::uint8_t>(i));
  return v;
}

// Two-level KTX2: 4x4 base + 2x2 mip, uncompressed RGBA8.
std::vector<std::uint8_t> make_ktx2_mips() {
  std::vector<std::uint8_t> v;
  const char id[12] = {'\xAB','K','T','X',' ','2','0','\xBB','\r','\n','\x1A','\n'};
  v.insert(v.end(), id, id + 12);
  put32(v, 37); put32(v, 1); put32(v, 4); put32(v, 4); put32(v, 1);
  put32(v, 1); put32(v, 1); put32(v, 2); put32(v, 0);   // 2 mip levels
  put64(v, 0); put64(v, 0); put64(v, 0); put64(v, 0); put64(v, 0); put64(v, 0);
  // Level index: 2 × 24 bytes {dataOffset, dataLength, rawLength}.
  const auto idx_end = 96 + 48;
  const auto base_off = idx_end, base_len = 4 * 4 * 4;
  const auto mip_off = base_off + base_len, mip_len = 2 * 2 * 4;
  put64(v, base_off); put64(v, base_len); put64(v, base_len);
  put64(v, mip_off); put64(v, mip_len); put64(v, mip_len);
  for (int i = 0; i < 64; ++i) v.push_back(static_cast<std::uint8_t>(i));       // base
  for (int i = 0; i < 16; ++i) v.push_back(static_cast<std::uint8_t>(200 + i)); // mip
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
  {
    const auto good = dir / "good.ktx2";
    write(good, make_ktx2());
    std::string error;
    auto img = poko::resource::load_ktx2(good, &error);
    CHECK(img && img->width == 2 && img->height == 2 &&
          img->format == poko::resource::Ktx2Format::rgba8_unorm &&
          img->mips.size() == 1 && img->mips[0].pixels.size() == 16 &&
          img->mips[0].pixels[0] == 0 && img->mips[0].pixels[15] == 15);
    CHECK(error.empty());
    // Full mip chain: base 4x4 + mip 2x2.
    write(dir / "mips.ktx2", make_ktx2_mips());
    auto mip_img = poko::resource::load_ktx2(dir / "mips.ktx2");
    CHECK(mip_img && mip_img->mips.size() == 2);
    CHECK(mip_img && mip_img->mips[0].width == 4 && mip_img->mips[0].pixels.size() == 64);
    CHECK(mip_img && mip_img->mips[1].width == 2 && mip_img->mips[1].height == 2 &&
          mip_img->mips[1].pixels.size() == 16 && mip_img->mips[1].pixels[0] == 200);
    // BGRA variant accepted.
    write(dir / "bgra.ktx2", make_ktx2(44));
    auto bgra = poko::resource::load_ktx2(dir / "bgra.ktx2");
    CHECK(bgra && bgra->format == poko::resource::Ktx2Format::bgra8_unorm);
    // sRGB variants accepted and mapped.
    write(dir / "srgb.ktx2", make_ktx2(43));
    auto srgb = poko::resource::load_ktx2(dir / "srgb.ktx2");
    CHECK(srgb && srgb->format == poko::resource::Ktx2Format::rgba8_srgb);
    write(dir / "bgsrgb.ktx2", make_ktx2(50));
    auto bs = poko::resource::load_ktx2(dir / "bgsrgb.ktx2");
    CHECK(bs && bs->format == poko::resource::Ktx2Format::bgra8_srgb);
  }
  {  // Rejections.
    std::string e;
    auto bad_id = make_ktx2(); bad_id[0] = 0;
    write(dir / "badid.ktx2", bad_id);
    CHECK(!poko::resource::load_ktx2(dir / "badid.ktx2", &e) && !e.empty());
    write(dir / "super.ktx2", make_ktx2(37, 1));
    e.clear();
    CHECK(!poko::resource::load_ktx2(dir / "super.ktx2", &e) &&
          e.find("supercompressed") != std::string::npos);
    write(dir / "fmt.ktx2", make_ktx2(100));
    CHECK(!poko::resource::load_ktx2(dir / "fmt.ktx2"));
    auto trunc = make_ktx2(); trunc.resize(120);  // cuts level data
    write(dir / "trunc.ktx2", trunc);
    CHECK(!poko::resource::load_ktx2(dir / "trunc.ktx2"));
    CHECK(!poko::resource::load_ktx2(dir / "missing.ktx2"));
    write(dir / "empty.ktx2", {});
    CHECK(!poko::resource::load_ktx2(dir / "empty.ktx2"));
  }
  if (failures) { std::fprintf(stderr, "%d check(s) failed\n", failures); return 1; }
  std::puts("PASS: KTX2 uncompressed loader accept/reject paths");
  return 0;
}

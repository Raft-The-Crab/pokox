#include "poko/resource/ktx2.hpp"

#include <cstring>
#include <fstream>

namespace poko::resource {
namespace {
constexpr std::size_t kMaxFileSize = 64u * 1024u * 1024u;
constexpr std::size_t kIdentifierSize = 12;
constexpr std::size_t kHeaderSize = 96;  // id(12) + 9*u32 + 6*u64
constexpr char kIdentifier[13] = "\xAB" "KTX 20" "\xBB" "\r\n\x1A\n";

struct Reader {
  const std::vector<std::uint8_t>& d;
  std::size_t pos = 0;
  bool u32(std::uint32_t& out) {
    if (pos + 4 > d.size()) return false;
    std::memcpy(&out, d.data() + pos, 4); pos += 4; return true;
  }
  bool u64(std::uint64_t& out) {
    if (pos + 8 > d.size()) return false;
    std::memcpy(&out, d.data() + pos, 8); pos += 8; return true;
  }
  bool skip(std::uint64_t n) {
    if (n > d.size() - pos) return false;
    pos += static_cast<std::size_t>(n); return true;
  }
};

std::unique_ptr<Ktx2Image> fail(std::string* error, const char* msg) {
  if (error) *error = msg;
  return nullptr;
}
}

std::unique_ptr<Ktx2Image> load_ktx2(const std::filesystem::path& path,
                                     std::string* error) noexcept {
  try {
    std::ifstream in(path, std::ios::binary | std::ios::ate);
    if (!in) return fail(error, "cannot open file");
    const auto len = in.tellg();
    if (len <= 0) return fail(error, "empty file");
    if (static_cast<std::uintmax_t>(len) > kMaxFileSize)
      return fail(error, "file too large");
    in.seekg(0);
    std::vector<std::uint8_t> data(static_cast<std::size_t>(len));
    if (!in.read(reinterpret_cast<char*>(data.data()), len))
      return fail(error, "read failed");
    if (data.size() < kHeaderSize ||
        std::memcmp(data.data(), kIdentifier, kIdentifierSize) != 0)
      return fail(error, "bad KTX2 identifier");

    Reader r{data, kIdentifierSize};
    std::uint32_t vk_format, type_size, width, height, depth;
    std::uint32_t layers, faces, levels, supercompression;
    std::uint64_t dfd_off, dfd_len, kvd_off, kvd_len, sgd_off, sgd_len;
    if (!r.u32(vk_format) || !r.u32(type_size) || !r.u32(width) ||
        !r.u32(height) || !r.u32(depth) || !r.u32(layers) || !r.u32(faces) ||
        !r.u32(levels) || !r.u32(supercompression))
      return fail(error, "truncated header");
    if (!r.u64(dfd_off) || !r.u64(dfd_len) || !r.u64(kvd_off) || !r.u64(kvd_len) ||
        !r.u64(sgd_off) || !r.u64(sgd_len))
      return fail(error, "truncated header");
    // Bytes 64-79 of the header are index/SGD offsets already consumed above;
    // remaining header fields are not needed for level-0 uncompressed reads.

    if (supercompression != 0)
      return fail(error, "supercompressed KTX2 not supported (Basis is AST-02)");
    if (vk_format != 37 && vk_format != 43 && vk_format != 44 && vk_format != 50)
      return fail(error, "unsupported vkFormat (need R8G8B8A8/B8G8R8A8 UNORM/SRGB)");
    if (type_size != 1 || width == 0 || height == 0 || depth == 0 ||
        layers != 1 || faces != 1 || levels == 0)
      return fail(error, "unsupported image shape");
    if (dfd_off > data.size() || dfd_len > data.size() - dfd_off)
      return fail(error, "bad DFD block bounds");

    // Level index: levels × 24 bytes {levelDataOffset, levelDataLength,
    // uncompressedByteLength} starting right after the 80-byte header.
    const std::uint64_t index_off = kHeaderSize;
    const std::uint64_t index_len = static_cast<std::uint64_t>(levels) * 24;
    if (index_len > data.size() - index_off)
      return fail(error, "truncated level index");
    Reader idx{data, static_cast<std::size_t>(index_off)};
    auto img = std::make_unique<Ktx2Image>();
    img->width = width; img->height = height;
    img->format = vk_format == 37 ? Ktx2Format::rgba8_unorm
        : vk_format == 44 ? Ktx2Format::bgra8_unorm
        : vk_format == 43 ? Ktx2Format::rgba8_srgb
        : Ktx2Format::bgra8_srgb;
    img->mips.reserve(levels);
    for (std::uint32_t i = 0; i < levels; ++i) {
      std::uint64_t level_off, level_len, level_raw;
      if (!idx.u64(level_off) || !idx.u64(level_len) || !idx.u64(level_raw))
        return fail(error, "truncated level index");
      const auto mw = std::max<std::uint32_t>(1, width >> i);
      const auto mh = std::max<std::uint32_t>(1, height >> i);
      const std::uint64_t expected =
          static_cast<std::uint64_t>(mw) * mh * depth * 4;
      if (level_off > data.size() || level_len > data.size() - level_off ||
          level_len < expected || level_raw < expected)
        return fail(error, "level data out of bounds");
      Ktx2Mip mip;
      mip.width = mw; mip.height = mh;
      mip.pixels.assign(data.begin() + static_cast<std::ptrdiff_t>(level_off),
                        data.begin() + static_cast<std::ptrdiff_t>(level_off + expected));
      img->mips.push_back(std::move(mip));
    }
    return img;
  } catch (...) {
    return fail(error, "allocation failure");
  }
}

}  // namespace poko::resource

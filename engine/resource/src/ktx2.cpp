#include "poko/resource/ktx2.hpp"

#include <algorithm>
#include <bit>
#include <cstring>
#include <fstream>
#include <utility>

namespace poko::resource {
namespace {
constexpr std::size_t kMaxFileSize = 64u * 1024u * 1024u;
constexpr std::size_t kHeaderSize = 80;
constexpr char kIdentifier[13] = "\xAB" "KTX 20" "\xBB" "\r\n\x1A\n";

struct Reader {
  const std::vector<std::uint8_t>& d;
  std::size_t pos = 0;
  bool u32(std::uint32_t& out) noexcept {
    if (pos > d.size() || d.size() - pos < 4) return false;
    out = 0;
    for (unsigned i = 0; i < 4; ++i) out |= std::uint32_t{d[pos++]} << (i * 8);
    return true;
  }
  bool u64(std::uint64_t& out) noexcept {
    if (pos > d.size() || d.size() - pos < 8) return false;
    out = 0;
    for (unsigned i = 0; i < 8; ++i) out |= std::uint64_t{d[pos++]} << (i * 8);
    return true;
  }
};

std::unique_ptr<Ktx2Image> fail(std::string* error, const char* message) noexcept {
  if (error) {
    try { *error = message; } catch (...) { error->clear(); }
  }
  return nullptr;
}
bool in_bounds(std::uint64_t offset, std::uint64_t length, std::size_t size) noexcept {
  return offset <= size && length <= size - offset;
}
}  // namespace

std::unique_ptr<Ktx2Image> load_ktx2(const std::filesystem::path& path,
                                     std::string* error) noexcept {
  if (error) error->clear();
  try {
    std::ifstream in(path, std::ios::binary | std::ios::ate);
    if (!in) return fail(error, "cannot open file");
    const auto len = in.tellg();
    if (len <= 0) return fail(error, "empty file");
    if (static_cast<std::uintmax_t>(len) > kMaxFileSize) return fail(error, "file too large");
    in.seekg(0);
    std::vector<std::uint8_t> data(static_cast<std::size_t>(len));
    if (!in.read(reinterpret_cast<char*>(data.data()), len)) return fail(error, "read failed");
    if (data.size() < kHeaderSize || std::memcmp(data.data(), kIdentifier, 12) != 0)
      return fail(error, "bad KTX2 identifier or truncated header");

    Reader r{data, 12};
    std::uint32_t format, type_size, width, height, depth, layers, faces, levels, supercompression;
    std::uint32_t dfd_off, dfd_len, kvd_off, kvd_len;
    std::uint64_t sgd_off, sgd_len;
    if (!r.u32(format) || !r.u32(type_size) || !r.u32(width) || !r.u32(height) ||
        !r.u32(depth) || !r.u32(layers) || !r.u32(faces) || !r.u32(levels) ||
        !r.u32(supercompression) || !r.u32(dfd_off) || !r.u32(dfd_len) ||
        !r.u32(kvd_off) || !r.u32(kvd_len) || !r.u64(sgd_off) || !r.u64(sgd_len))
      return fail(error, "truncated header");
    if (supercompression != 0) return fail(error, "supercompressed KTX2 not supported");
    if (format != 37 && format != 43 && format != 44 && format != 50)
      return fail(error, "unsupported vkFormat");
    if (type_size != 1 || width == 0 || height == 0 || depth != 0 || layers != 0 || faces != 1)
      return fail(error, "only non-array 2D images are supported");
    if (sgd_off != 0 || sgd_len != 0) return fail(error, "unexpected supercompression data");
    const auto count = std::max(1u, levels);
    if (count > std::bit_width(std::max(width, height))) return fail(error, "too many mip levels");
    const std::uint64_t index_end = kHeaderSize + std::uint64_t{count} * 24;
    if (index_end > data.size()) return fail(error, "truncated level index");
    if (dfd_off < index_end || dfd_len < 28 || !in_bounds(dfd_off, dfd_len, data.size()))
      return fail(error, "bad DFD block bounds");
    Reader dfd{data, dfd_off};
    std::uint32_t dfd_total = 0;
    if (!dfd.u32(dfd_total) || dfd_total != dfd_len) return fail(error, "bad DFD size");
    const std::uint64_t dfd_end = std::uint64_t{dfd_off} + dfd_len;
    if (kvd_len && (kvd_off < dfd_end || !in_bounds(kvd_off, kvd_len, data.size())))
      return fail(error, "bad key/value block bounds");
    const std::uint64_t metadata_end = kvd_len ? std::uint64_t{kvd_off} + kvd_len : dfd_end;

    Reader idx{data, kHeaderSize};
    auto img = std::make_unique<Ktx2Image>();
    img->width = width; img->height = height;
    img->format = static_cast<Ktx2Format>(format);
    img->mips.reserve(count);
    std::vector<std::pair<std::uint64_t, std::uint64_t>> ranges;
    for (std::uint32_t i = 0; i < count; ++i) {
      std::uint64_t off, length, raw;
      if (!idx.u64(off) || !idx.u64(length) || !idx.u64(raw))
        return fail(error, "truncated level index");
      const auto mw = std::max(1u, width >> i), mh = std::max(1u, height >> i);
      const std::uint64_t pixels = std::uint64_t{mw} * mh;
      if (pixels > kMaxFileSize / 4) return fail(error, "image dimensions too large");
      const auto expected = pixels * 4;
      if (off < metadata_end || off % 4 != 0 || length != expected || raw != expected ||
          !in_bounds(off, length, data.size())) return fail(error, "invalid level data");
      for (const auto& [begin, end] : ranges)
        if (off < end && begin < off + length) return fail(error, "overlapping levels");
      ranges.emplace_back(off, off + length);
      Ktx2Mip mip;
      mip.width = mw; mip.height = mh;
      mip.pixels.assign(data.begin() + static_cast<std::ptrdiff_t>(off),
                        data.begin() + static_cast<std::ptrdiff_t>(off + length));
      img->mips.push_back(std::move(mip));
    }
    return img;
  } catch (...) {
    return fail(error, "I/O or allocation failure");
  }
}
}  // namespace poko::resource

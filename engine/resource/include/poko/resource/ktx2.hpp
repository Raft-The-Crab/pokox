#pragma once

#include <cstdint>
#include <filesystem>
#include <memory>
#include <string>
#include <vector>

namespace poko::resource {

// ENG-18: minimal KTX2 reader for UNCOMPRESSED pixel formats — the placeholder
// texture path. Basis supercompression (the real AST-02 pipeline) is rejected
// explicitly; callers get a clear error, not a silent fallback.
//
// Supports non-array 2D R8G8B8A8/B8G8R8A8 UNORM and SRGB textures with
// stored mip levels. File data is capped at 64 MiB. The reader checks the
// index and DFD bounds, but does not validate DFD semantics or interpret
// key/value metadata such as orientation. Never throws.

enum class Ktx2Format : std::uint32_t {
  rgba8_unorm = 37,   // VK_FORMAT_R8G8B8A8_UNORM
  bgra8_unorm = 44,   // VK_FORMAT_B8G8R8A8_UNORM
  rgba8_srgb = 43,    // VK_FORMAT_R8G8B8A8_SRGB
  bgra8_srgb = 50,    // VK_FORMAT_B8G8R8A8_SRGB
};

struct Ktx2Mip {
  std::uint32_t width = 0;
  std::uint32_t height = 0;
  std::vector<std::uint8_t> pixels;  // tightly packed RGBA/BGRA for this level
};

struct Ktx2Image {
  std::uint32_t width = 0;    // base level dimensions
  std::uint32_t height = 0;
  Ktx2Format format = Ktx2Format::rgba8_unorm;
  std::vector<Ktx2Mip> mips;  // index 0 is the base level
};

// Loads the supported stored mips. Returns nullptr on unsupported input,
// I/O failure, or checked structural errors; error text is best effort.
[[nodiscard]] std::unique_ptr<Ktx2Image> load_ktx2(
    const std::filesystem::path& path, std::string* error = nullptr) noexcept;

}  // namespace poko::resource

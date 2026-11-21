#pragma once
// Internal SPIR-V loader shared by the Vulkan passes. Not an installed header.
#include <cstdint>
#include <fstream>
#include <stdexcept>
#include <string>
#include <vector>

namespace poko::rhi::detail {
inline std::vector<std::uint32_t> read_spirv(const std::string& path) {
  constexpr std::streamoff max_bytes = 16 * 1024 * 1024;
  std::ifstream file(path, std::ios::binary | std::ios::ate);
  if (!file) throw std::runtime_error("Cannot open shader: " + path);
  const auto length = file.tellg();
  if (length < 20 || length > max_bytes || length % 4 != 0)
    throw std::runtime_error("Invalid SPIR-V size: " + path);
  std::vector<std::uint32_t> words(static_cast<std::size_t>(length) / 4);
  file.seekg(0);
  if (!file.read(reinterpret_cast<char*>(words.data()), length) || words[0] != 0x07230203U)
    throw std::runtime_error("Invalid SPIR-V data or byte order: " + path);
  return words;
}
}  // namespace poko::rhi::detail

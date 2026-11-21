#pragma once

#include "poko/foundation/logging.hpp"

#include <cstdint>
#include <filesystem>
#include <string>
#include <system_error>
#include <vector>

namespace poko::config {

// Typed engine settings decoded from a CBOR file (ENG-14). Every section is
// optional; absent fields keep the defaults below. A present field with the
// wrong CBOR type fails the whole load — engine data never guesses.
struct EngineConfig {
  std::uint32_t window_width = 800;
  std::uint32_t window_height = 600;
  // Matches rhi::ClearConfig::adapter_id; 0xFFFFFFFF keeps automatic choice.
  std::uint32_t adapter_id = 0xFFFFFFFFU;
  bool validation = true;
  log::Level log_level = log::Level::info;
  // Empty disables file logging; when set together with echo_to_console the
  // record goes to both sinks (ENG-13 semantics).
  std::string log_file;
  bool log_echo_to_console = true;
};

struct LoadResult {
  std::error_code error;
  // Human-readable detail for logs/CLI; empty on success.
  std::string detail;
  EngineConfig config;
  // Unknown keys are skipped, not fatal (spec 21); reported as "section.key".
  std::vector<std::string> unknown_keys;
};

// Reads at most 1 MiB and decodes one top-level map. Never throws.
[[nodiscard]] LoadResult load_file(const std::filesystem::path& path) noexcept;

// Explicit command-line overrides. The *_set flags record that the user
// passed the flag so file settings do not clobber it; window size and
// logging have no CLI equivalents and always come from the file.
struct Overrides {
  bool validation_set = false;
  bool validation = true;
  bool adapter_set = false;
  std::uint32_t adapter_id = 0;
};

// Loads `path` when non-empty (an empty path keeps built-in defaults), then
// applies the overrides on top of the file's graphics settings. On a load
// error the returned config is the built-in defaults and `error` is set.
[[nodiscard]] LoadResult resolve(const std::filesystem::path& path,
                                 const Overrides& overrides = {}) noexcept;

}  // namespace poko::config

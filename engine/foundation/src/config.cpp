#include "poko/foundation/config.hpp"

#include "poko/foundation/cbor.hpp"

#include <fstream>
#include <iterator>
#include <new>
#include <system_error>

namespace poko::config {
namespace {
constexpr std::uintmax_t kMaxFileBytes = 1024 * 1024;

LoadResult fail(std::error_code code, std::string detail) {
  LoadResult result;
  result.error = code;
  result.detail = std::move(detail);
  return result;
}

const cbor::Value* find_key(const cbor::Value& map, std::string_view key) noexcept {
  if (map.type != cbor::Type::map) return nullptr;
  for (const auto& entry : map.entries) {
    if (entry.first.type == cbor::Type::text && entry.first.string &&
        std::string_view(*entry.first.string) == key)
      return &entry.second;
  }
  return nullptr;
}

// First matching text key wins; later duplicates are ignored.
bool read_u32(const cbor::Value& section, std::string_view key,
              std::uint32_t& out, std::string& detail) {
  const auto* v = find_key(section, key);
  if (!v) return true;
  if (v->type != cbor::Type::uint || v->u > 0xFFFFFFFFULL) {
    detail = "field must be a uint32: " + std::string(key);
    return false;
  }
  out = static_cast<std::uint32_t>(v->u);
  return true;
}

bool read_bool(const cbor::Value& section, std::string_view key,
               bool& out, std::string& detail) {
  const auto* v = find_key(section, key);
  if (!v) return true;
  if (v->type != cbor::Type::boolean) {
    detail = "field must be a bool: " + std::string(key);
    return false;
  }
  out = v->boolean;
  return true;
}

// Returns false and fills detail on type/parse failure.
bool read_text(const cbor::Value& section, std::string_view key,
               std::string& out, std::string& detail) {
  const auto* v = find_key(section, key);
  if (!v) return true;
  if (v->type != cbor::Type::text) {
    detail = "field must be text: " + std::string(key);
    return false;
  }
  if (v->string) out = *v->string;
  else out.clear();
  return true;
}

bool parse_level(const std::string& text, log::Level& out) noexcept {
  if (text == "trace") out = log::Level::trace;
  else if (text == "debug") out = log::Level::debug;
  else if (text == "info") out = log::Level::info;
  else if (text == "warn") out = log::Level::warn;
  else if (text == "error") out = log::Level::error;
  else if (text == "critical") out = log::Level::critical;
  else return false;
  return true;
}

// Known keys per section; anything else is reported, not fatal.
void collect_unknown(const cbor::Value& section, const char* const* known,
                     std::size_t known_count, const std::string& prefix,
                     std::vector<std::string>& unknown) {
  if (section.type != cbor::Type::map) return;
  for (const auto& entry : section.entries) {
    if (entry.first.type != cbor::Type::text) {
      unknown.push_back(prefix + "<non-text-key>");
      continue;
    }
    bool found = false;
    for (std::size_t i = 0; i < known_count; ++i)
      if (entry.first.string && std::string_view(*entry.first.string) == known[i]) { found = true; break; }
    if (!found) unknown.push_back(entry.first.string ? prefix + *entry.first.string : prefix + "<missing>");
  }
}

}  // namespace

LoadResult load_file(const std::filesystem::path& path) noexcept {
  try {
  std::ifstream in(path, std::ios::binary | std::ios::ate);
  if (!in) return fail(std::make_error_code(std::errc::no_such_file_or_directory),
                      "cannot open config file");
  const auto length = in.tellg();
  if (length < 0 || static_cast<std::uintmax_t>(length) > kMaxFileBytes)
    return fail(std::make_error_code(std::errc::file_too_large), "config file too large");
  std::string bytes(static_cast<std::size_t>(length), '\0');
  in.seekg(0);
  if (length > 0 && !in.read(bytes.data(), length))
    return fail(std::make_error_code(std::errc::io_error), "cannot read config file");

  const auto decoded = cbor::decode(bytes);
  if (decoded.error != cbor::Error::none)
    return fail(std::make_error_code(std::errc::invalid_argument),
                "CBOR decode failed at offset " + std::to_string(decoded.offset));
  const auto& root = decoded.value;
  if (root.type != cbor::Type::map)
    return fail(std::make_error_code(std::errc::invalid_argument),
                "config root must be a map");

  LoadResult result;
  EngineConfig& cfg = result.config;
  std::string detail;
  const auto bad = [&](const std::string& key) {
    result = fail(std::make_error_code(std::errc::invalid_argument), key);
    return result;
  };

  static const char* const kRootKeys[] = {"window", "graphics", "logging"};
  collect_unknown(root, kRootKeys, 3, "", result.unknown_keys);

  if (const auto* v = find_key(root, "window")) {
    if (v->type != cbor::Type::map) return bad("window must be a map");
    static const char* const kKeys[] = {"width", "height"};
    collect_unknown(*v, kKeys, 2, "window.", result.unknown_keys);
    if (!read_u32(*v, "width", cfg.window_width, detail) ||
        !read_u32(*v, "height", cfg.window_height, detail)) return bad(detail);
    if (cfg.window_width == 0 || cfg.window_height == 0)
      return bad("window dimensions must be nonzero");
  }
  if (const auto* v = find_key(root, "graphics")) {
    if (v->type != cbor::Type::map) return bad("graphics must be a map");
    static const char* const kKeys[] = {"adapter_id", "validation"};
    collect_unknown(*v, kKeys, 2, "graphics.", result.unknown_keys);
    if (!read_u32(*v, "adapter_id", cfg.adapter_id, detail) ||
        !read_bool(*v, "validation", cfg.validation, detail)) return bad(detail);
  }
  if (const auto* v = find_key(root, "logging")) {
    if (v->type != cbor::Type::map) return bad("logging must be a map");
    static const char* const kKeys[] = {"level", "file", "echo"};
    collect_unknown(*v, kKeys, 3, "logging.", result.unknown_keys);
    std::string level;
    if (!read_text(*v, "level", level, detail) ||
        !read_text(*v, "file", cfg.log_file, detail) ||
        !read_bool(*v, "echo", cfg.log_echo_to_console, detail)) return bad(detail);
    if (!level.empty() && !parse_level(level, cfg.log_level))
      return bad("logging.level must be trace|debug|info|warn|error|critical");
  }
  return result;
  } catch (const std::bad_alloc&) {
    LoadResult result;
    result.error = std::make_error_code(std::errc::not_enough_memory);
    return result;
  } catch (...) {
    LoadResult result;
    result.error = std::make_error_code(std::errc::io_error);
    return result;
  }
}

LoadResult resolve(const std::filesystem::path& path,
                   const Overrides& overrides) noexcept {
  LoadResult result = path.empty() ? LoadResult{} : load_file(path);
  if (overrides.validation_set) result.config.validation = overrides.validation;
  if (overrides.adapter_set) result.config.adapter_id = overrides.adapter_id;
  return result;
}

}  // namespace poko::config

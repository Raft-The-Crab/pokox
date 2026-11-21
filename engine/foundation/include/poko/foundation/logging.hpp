#pragma once
#include <cstdint>
#include <string>
#include <string_view>
#include <system_error>
#include <utility>
#include <vector>

namespace poko::log {

enum class Level : std::uint8_t { trace, debug, info, warn, error, critical };

struct Config {
  // UTF-8 path of the log file; parent directories must exist. The file is
  // truncated on each init() — one session per file, no cross-run append.
  std::string file_path;
  // Lines below this level are dropped before formatting.
  Level level = Level::info;
  // When true, every record also goes to stdout/stderr via the default logger.
  bool echo_to_console = true;
};

// A structured field rendered as key=value on the log line.
struct Field {
  std::string key;
  std::string value;
};

// Opens the file sink and installs the process logger. Call once before any
// log_* call; a second call returns an error instead of leaking sinks.
// Returns an error code; never throws across the boundary.
[[nodiscard]] std::error_code init(const Config& config) noexcept;
// Flushes and removes the file sink. Safe to call repeatedly.
void shutdown() noexcept;

// Category is a short subsystem tag (e.g. "rhi", "render"). Fields are
// appended as "key=value" pairs. All functions are safe before init() (the
// record is dropped) and after shutdown() (dropped).
void trace(std::string_view category, std::string_view message,
           std::vector<Field> fields = {});
void debug(std::string_view category, std::string_view message,
           std::vector<Field> fields = {});
void info(std::string_view category, std::string_view message,
          std::vector<Field> fields = {});
void warn(std::string_view category, std::string_view message,
          std::vector<Field> fields = {});
void error(std::string_view category, std::string_view message,
           std::vector<Field> fields = {});
void critical(std::string_view category, std::string_view message,
              std::vector<Field> fields = {});

}  // namespace poko::log

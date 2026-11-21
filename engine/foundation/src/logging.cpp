#include "poko/foundation/logging.hpp"
#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/spdlog.h>
#include <atomic>
#include <mutex>
#include <shared_mutex>
#include <system_error>

namespace poko::log {
namespace {
constexpr const char* kLoggerName = "poko";
std::shared_mutex g_mutex;
std::atomic<bool> g_initialized{false};
// Records emit through this pinned logger so a foreign set_default_logger()
// cannot reroute them, and shutdown can drop exactly our logger + file handle.
// atomic<shared_ptr> keeps the emit() copy race-free vs init/shutdown writes;
// the shared lock below additionally prevents a record from landing in the
// file after shutdown() returns or interleaving into a re-init's truncated
// session file.
std::atomic<std::shared_ptr<spdlog::logger>> g_logger;
spdlog::level::level_enum to_spdlog(Level level) {
  switch (level) {
    case Level::trace: return spdlog::level::trace;
    case Level::debug: return spdlog::level::debug;
    case Level::info: return spdlog::level::info;
    case Level::warn: return spdlog::level::warn;
    case Level::error: return spdlog::level::err;
    case Level::critical: return spdlog::level::critical;
  }
  return spdlog::level::info;
}
void emit(Level level, std::string_view category, std::string_view message,
          const std::vector<Field>& fields) noexcept {
  try {
    if (!g_initialized.load(std::memory_order_acquire)) return;
    // Shared with other emitters, exclusive against init/shutdown: a record
    // in flight when shutdown begins completes before the file sink is dropped.
    std::shared_lock lock{g_mutex};
    if (!g_initialized.load(std::memory_order_acquire)) return;
    auto logger = g_logger.load();
    if (!logger || logger->level() > to_spdlog(level)) return;
    std::string line{category};
    line += ": ";
    line += message;
    for (const auto& field : fields) {
      line += " ";
      line += field.key;
      line += "=";
      line += field.value;
    }
    switch (level) {
      case Level::trace: logger->trace("{}", line); break;
      case Level::debug: logger->debug("{}", line); break;
      case Level::info: logger->info("{}", line); break;
      case Level::warn: logger->warn("{}", line); break;
      case Level::error: logger->error("{}", line); break;
      case Level::critical: logger->critical("{}", line); break;
    }
  } catch (...) {
    // Logging must never propagate exceptions into engine call sites.
  }
}
}  // namespace

std::error_code init(const Config& config) noexcept {
  std::lock_guard lock{g_mutex};
  if (g_initialized.load(std::memory_order_acquire))
    return std::make_error_code(std::errc::device_or_resource_busy);
  try {
    try { spdlog::drop(kLoggerName); } catch (const spdlog::spdlog_ex&) {}
    std::vector<spdlog::sink_ptr> sinks;
    // truncate=true: each run starts a fresh session log; the file is not
    // appended across processes (documented in logging.hpp via Config).
    sinks.push_back(std::make_shared<spdlog::sinks::basic_file_sink_mt>(config.file_path, true));
    if (config.echo_to_console)
      sinks.push_back(std::make_shared<spdlog::sinks::stdout_color_sink_mt>());
    auto logger = std::make_shared<spdlog::logger>(kLoggerName, sinks.begin(), sinks.end());
    logger->set_level(to_spdlog(config.level));
    logger->set_pattern("[%Y-%m-%d %H:%M:%S.%e] [%^%l%$] [%n] %v");
    g_logger.store(logger);
    // Deliberately NOT installed as the process default logger: emit() uses
    // the pinned logger, and dropping "poko" at shutdown must not leave
    // spdlog's default_logger_ null for unrelated callers.
    g_initialized.store(true, std::memory_order_release);
    return {};
  } catch (...) {
    g_logger.store(nullptr);
    return std::make_error_code(std::errc::io_error);
  }
}
void shutdown() noexcept {
  std::lock_guard lock{g_mutex};
  if (!g_initialized.exchange(false, std::memory_order_acq_rel)) return;
  // Drop only our logger: flushes and closes the file sink without tearing
  // down unrelated spdlog loggers elsewhere in the process.
  try { spdlog::drop(kLoggerName); } catch (...) {}
  g_logger.store(nullptr);
}
void trace(std::string_view c, std::string_view m, std::vector<Field> f) { emit(Level::trace, c, m, f); }
void debug(std::string_view c, std::string_view m, std::vector<Field> f) { emit(Level::debug, c, m, f); }
void info(std::string_view c, std::string_view m, std::vector<Field> f) { emit(Level::info, c, m, f); }
void warn(std::string_view c, std::string_view m, std::vector<Field> f) { emit(Level::warn, c, m, f); }
void error(std::string_view c, std::string_view m, std::vector<Field> f) { emit(Level::error, c, m, f); }
void critical(std::string_view c, std::string_view m, std::vector<Field> f) { emit(Level::critical, c, m, f); }
}  // namespace poko::log

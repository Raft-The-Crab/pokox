#pragma once
// ENG-13/ENG-14 bridge: RAII file logging driven by EngineConfig settings.
// A no-op unless the target defines POKO_ENGINE_LOGGING=1 and links
// poko_logging (POKO_WITH_DEPENDENCIES builds).
#include "poko/foundation/config.hpp"
#if POKO_ENGINE_LOGGING
#include "poko/foundation/logging.hpp"
#include <cstdio>
#include <string>
#endif

namespace poko::config {

#if POKO_ENGINE_LOGGING
class LogGuard {
 public:
  explicit LogGuard(const EngineConfig& settings) noexcept {
    if (settings.log_file.empty()) return;
    try {
      const auto error = log::init({settings.log_file, settings.log_level,
                                    settings.log_echo_to_console});
      if (error) {
        std::fprintf(stderr, "File logging unavailable: %s\n",
                     error.message().c_str());
      } else {
        owns_logger_ = true;
        log::info("config", "settings loaded",
                  {{"adapter", std::to_string(settings.adapter_id)},
                   {"validation", settings.validation ? "on" : "off"}});
      }
    } catch (...) {
      // Logging is optional; argument construction and diagnostics may allocate.
      std::fputs("File logging setup or diagnostics unavailable.\n", stderr);
    }
  }
  ~LogGuard() { if (owns_logger_) log::shutdown(); }
  LogGuard(const LogGuard&) = delete;
  LogGuard& operator=(const LogGuard&) = delete;
 private:
  bool owns_logger_ = false;
};
#else
class LogGuard {
 public:
  explicit LogGuard(const EngineConfig&) noexcept {}
};
#endif

}  // namespace poko::config

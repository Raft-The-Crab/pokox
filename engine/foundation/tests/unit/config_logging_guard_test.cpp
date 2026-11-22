// Exercise the logging bridge with deterministic logger and allocation failures.
#define POKO_ENGINE_LOGGING 1
#include "poko/foundation/config_logging.hpp"
#include <atomic>
#include <cstdio>
#include <cstdlib>
#include <new>
#include <string_view>
#include <vector>

namespace {
std::atomic<bool> fail_next{false};
bool active = false;
bool fail_info = false;
int shutdowns = 0;
}
void* operator new(std::size_t size) {
  if (fail_next.exchange(false)) throw std::bad_alloc();
  if (void* p = std::malloc(size ? size : 1)) return p;
  throw std::bad_alloc();
}
void operator delete(void* p) noexcept { std::free(p); }
void operator delete(void* p, std::size_t) noexcept { std::free(p); }

namespace poko::log {
std::error_code init(const Config&) noexcept {
  if (active) return std::make_error_code(std::errc::device_or_resource_busy);
  active = true;
  return {};
}
void shutdown() noexcept { ++shutdowns; active = false; }
void info(std::string_view, std::string_view, std::vector<Field>) {
  if (fail_info) throw std::bad_alloc();
}
}
int main(int argc, char** argv) {
  using poko::config::EngineConfig;
  using poko::config::LogGuard;
  const std::string_view mode = argc > 1 ? argv[1] : "ownership";
  EngineConfig config;
  if (mode == "allocation") {
    config.log_file.assign(100, 'x');
    fail_next.store(true);
    { LogGuard guard(config); }
    if (fail_next.load() || shutdowns != 0 || active) return 1;
  } else if (mode == "ownership") {
    active = true;
    { LogGuard empty(config); }
    if (!active || shutdowns != 0) return 1;
    config.log_file = "log.txt";
    { LogGuard busy(config); }
    if (!active || shutdowns != 0) return 2;
    active = false;
    { LogGuard owner(config); if (!active) return 3; }
    if (active || shutdowns != 1) return 4;
  } else if (mode == "reporting") {
    config.log_file = "log.txt";
    fail_info = true;
    { LogGuard guard(config); if (!active) return 5; }
    if (active || shutdowns != 1) return 6;
  } else return 7;
  std::puts("PASS: logging guard failure and ownership behavior");
}

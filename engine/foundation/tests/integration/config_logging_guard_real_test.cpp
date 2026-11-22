// Verify LogGuard does not shut down a logger it did not acquire, with spdlog.
#define POKO_ENGINE_LOGGING 1
#include "poko/foundation/config_logging.hpp"
#include <cstdio>
#include <filesystem>
#include <fstream>
#include <iterator>
#include <string>

int main() {
  const auto path = std::filesystem::temp_directory_path() / "poko_guard_real_test.log";
  poko::config::EngineConfig config;
  config.log_file = path.string();
  config.log_echo_to_console = false;
  {
    poko::config::LogGuard owner{config};
    { poko::config::EngineConfig empty; poko::config::LogGuard no_logger{empty}; }
    poko::log::info("guard", "after empty");
    { poko::config::LogGuard busy{config}; }
    poko::log::info("guard", "after busy");
  }
  std::string text;
  {
    std::ifstream in(path);
    text.assign(std::istreambuf_iterator<char>(in), {});
  }
  // Windows cannot remove a file that is still open for reading.
  std::filesystem::remove(path);
  if (text.find("guard: after empty") == std::string::npos ||
      text.find("guard: after busy") == std::string::npos) {
    std::fputs("FAIL: an unowned guard stopped logging\n", stderr);
    return 1;
  }
  std::puts("PASS: real spdlog guard ownership");
}

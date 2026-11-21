// ENG-13: writes a timestamped structured log file and verifies contents.
// Each init() truncates the file, so sessions are verified one at a time.
#include "poko/foundation/logging.hpp"
#include <cstdio>
#include <filesystem>
#include <fstream>
#include <regex>
#include <string>

namespace {
std::string read_file(const std::filesystem::path& path) {
  std::ifstream in(path);
  return {std::istreambuf_iterator<char>(in), std::istreambuf_iterator<char>()};
}
int count_stamps(const std::string& text) {
  const std::regex stamp{R"(\[\d{4}-\d{2}-\d{2} \d{2}:\d{2}:\d{2}\.\d+\])"};
  int count = 0;
  for (std::sregex_iterator it(text.begin(), text.end(), stamp), end; it != end; ++it) ++count;
  return count;
}
}  // namespace

int main() {
  namespace fs = std::filesystem;
  const auto dir = fs::temp_directory_path() / "poko_eng13_logging";
  fs::create_directories(dir);
  const auto file = dir / "engine.log";

  // Session 1: debug level — trace is dropped, everything else is kept.
  if (fs::exists(file)) fs::remove(file);
  if (poko::log::init({file.string(), poko::log::Level::debug, false})) {
    std::fputs("init failed\n", stderr); return 1;
  }
  if (!poko::log::init({file.string(), poko::log::Level::info, false})) {
    std::fputs("double init unexpectedly succeeded\n", stderr); return 1;
  }
  poko::log::debug("rhi", "device created", {{"adapter", "0"}, {"api", "vulkan"}});
  poko::log::info("render", "frame submitted", {{"frame", "42"}});
  poko::log::warn("platform", "resize requested", {{"w", "800"}, {"h", "600"}});
  poko::log::trace("render", "trace line dropped below debug level", {});
  poko::log::shutdown();

  const std::string session1 = read_file(file);
  const bool ok1 = count_stamps(session1) == 3 &&
      session1.find("rhi: device created adapter=0 api=vulkan") != std::string::npos &&
      session1.find("render: frame submitted frame=42") != std::string::npos &&
      session1.find("platform: resize requested w=800 h=600") != std::string::npos &&
      session1.find("trace line dropped") == std::string::npos;
  if (!ok1) { std::fprintf(stderr, "session 1 verification failed:\n%s\n", session1.c_str()); return 1; }

  // Session 2: re-init at info level truncates and filters — debug dropped.
  if (poko::log::init({file.string(), poko::log::Level::info, false})) {
    std::fputs("re-init after shutdown failed\n", stderr); return 1;
  }
  poko::log::debug("filter", "this debug line must not appear", {});
  poko::log::info("filter", "this info line must appear", {});
  poko::log::shutdown();

  const std::string session2 = read_file(file);
  const bool ok2 = count_stamps(session2) == 1 &&
      session2.find("filter: this info line must appear") != std::string::npos &&
      session2.find("this debug line must not appear") == std::string::npos &&
      session2.find("device created") == std::string::npos;  // truncated
  if (!ok2) { std::fprintf(stderr, "session 2 verification failed:\n%s\n", session2.c_str()); return 1; }

  std::printf("PASS: %s (session1=%d lines, session2=%d lines)\n",
              file.string().c_str(), count_stamps(session1), count_stamps(session2));
  return 0;
}

// MUT-55 CLI: validate a local mute.toml/mute.lock project and print the
// canonical build plan. --emit-lock writes the plan lock for bootstrapping.
#include "poko/mute/build_tool.hpp"

#include <filesystem>
#include <fstream>
#include <iostream>
#include <optional>
#include <sstream>
#include <string>
#include <vector>

namespace {
bool read_file(const std::filesystem::path& path, std::string& out) {
  std::ifstream in(path, std::ios::binary);
  if (!in) return false;
  std::ostringstream ss;
  ss << in.rdbuf();
  out = ss.str();
  return true;
}
}  // namespace

int main(int argc, char** argv) {
  if (argc < 2 || argc > 3) {
    std::cerr << "usage: poko_mute_build <project-dir> [--emit-lock]\n";
    return 64;
  }
  const std::filesystem::path root{argv[1]};
  const bool emit_lock = argc == 3 && std::string_view{argv[2]} == "--emit-lock";
  if (argc == 3 && !emit_lock) {
    std::cerr << "unknown option: " << argv[2] << '\n';
    return 64;
  }
  std::string manifest_text;
  if (!read_file(root / "mute.toml", manifest_text)) {
    std::cerr << "mute build error: io missing mute.toml\n";
    return 1;
  }
  std::string diagnostic;
  auto manifest = poko::mute::parse_manifest(manifest_text, &diagnostic);
  if (!manifest) {
    std::cerr << "mute build error: invalid_manifest " << diagnostic << '\n';
    return 1;
  }
  std::vector<poko::mute::ProjectSource> sources;
  sources.reserve(manifest->sources.size());
  for (const auto& path : manifest->sources) {
    std::string text;
    if (!read_file(root / path, text)) {
      std::cerr << "mute build error: io missing source: " << path << '\n';
      return 1;
    }
    sources.push_back({path, text});
  }
  std::optional<std::string> lock_text;
  if (!emit_lock) {
    std::string text;
    if (!read_file(root / "mute.lock", text)) {
      std::cerr << "mute build error: io missing mute.lock\n";
      return 1;
    }
    lock_text = text;
  }
  const auto result = poko::mute::build_project(
    *manifest, sources, lock_text ? std::optional<std::string_view>{*lock_text} : std::nullopt);
  if (!result.ok()) {
    std::cerr << "mute build error: " << poko::mute::name(result.error) << ' '
              << result.diagnostic << '\n';
    return 1;
  }
  if (emit_lock) {
    std::ofstream out(root / "mute.lock", std::ios::binary | std::ios::trunc);
    if (!out) {
      std::cerr << "mute build error: io cannot write mute.lock\n";
      return 1;
    }
    out << result.lock_text;
  }
  std::cout << "mute build ok: " << result.packages.size() << " packages\n" << result.lock_text;
  return 0;
}

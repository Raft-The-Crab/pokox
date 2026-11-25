// MUT-55: fresh sample project builds from its canonical mute.lock.
#include "poko/mute/build_tool.hpp"

#include <filesystem>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace poko::mute;
namespace {
int failures = 0;
#define CHECK(cond) do { if (!(cond)) { \
  std::cerr << "FAIL line " << __LINE__ << ": " << #cond << '\n'; ++failures; \
} } while (0)

bool read(const std::filesystem::path& path, std::string& out) {
  std::ifstream in(path, std::ios::binary);
  if (!in) return false;
  std::ostringstream ss;
  ss << in.rdbuf();
  out = ss.str();
  return true;
}
}  // namespace

int main(int argc, char** argv) {
  if (argc != 2) { std::cerr << "usage: build_tool_test <fixture-dir>\n"; return 64; }
  const std::filesystem::path root{argv[1]};
  std::string manifest_text, lock_text, app_source, dep_source;
  CHECK(read(root / "mute.toml", manifest_text));
  CHECK(read(root / "mute.lock", lock_text));
  CHECK(read(root / "app.mute", app_source));
  CHECK(read(root / "dep.mute", dep_source));
  auto manifest = parse_manifest(manifest_text);
  CHECK(manifest.has_value());
  if (!manifest) return 1;
  const std::vector<ProjectSource> sources{{"app.mute", app_source}, {"dep.mute", dep_source}};
  const auto built = build_project(*manifest, sources, lock_text);
  CHECK(built.ok());
  CHECK(built.packages.size() == 2);
  CHECK(built.lock_text == lock_text);
  CHECK(lock_text.rfind("# mute.lock v1\n", 0) == 0);
  CHECK(lock_text.find("sample@V1? ") != std::string::npos);
  CHECK(lock_text.find("sample/dep@CalmOtter ") != std::string::npos);

  auto wrong_lock = lock_text;
  wrong_lock[wrong_lock.find("sample@V1? ") + 11] ^= 1;
  const auto mismatch = build_project(*manifest, sources, wrong_lock);
  CHECK(mismatch.error == BuildToolError::lock_mismatch);
  CHECK(name(BuildToolError::lock_mismatch) == "lock_mismatch");

  std::string bad_diagnostic;
  CHECK(!parse_manifest("name = \"x\"\nunknown = 3\n", &bad_diagnostic));
  CHECK(bad_diagnostic.find("unknown key") != std::string::npos);
  std::string no_name, no_version;
  CHECK(!declared_identity("fn f() -> i32 { return 1; }", no_name, no_version));

  if (failures) { std::cerr << failures << " MUT-55 check(s) failed\n"; return 1; }
  std::cout << "PASS: manifest, pinned lock, diagnostics, fresh sample build\n";
  return 0;
}

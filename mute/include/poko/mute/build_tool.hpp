#pragma once

#include "poko/mute/package.hpp"

#include <cstdint>
#include <optional>
#include <span>
#include <string>
#include <string_view>
#include <utility>
#include <vector>

namespace poko::mute {

// MUT-55: minimal local package build tool. It reads a tiny mute.toml, maps
// listed source files to declared package identities, resolves the set with
// MUT-21, and requires the canonical mute.lock v1 to match byte-for-byte.
// There is no registry, fetcher or publishing here (approved deferrals).
struct ProjectSource {
  std::string path;
  std::string source;
};

enum class BuildToolError {
  ok,
  io,
  invalid_manifest,
  invalid_source,
  invalid_lock,
  lock_mismatch,
  resolve_failed
};

struct BuildResult {
  BuildToolError error{BuildToolError::ok};
  std::string diagnostic;
  std::string lock_text;
  std::vector<ResolvedPackage> packages;
  [[nodiscard]] bool ok() const noexcept { return error == BuildToolError::ok; }
};

struct Manifest {
  std::string name;
  std::string version;
  std::vector<std::string> sources;
};

[[nodiscard]] std::optional<Manifest> parse_manifest(std::string_view text, std::string* diagnostic = nullptr);
[[nodiscard]] bool declared_identity(std::string_view source, std::string& name,
                                     std::string& version) noexcept;

// Builds from the manifest, an optional canonical lock, and loaded sources.
// If expected_lock is nullopt, the canonical lock is returned for --emit-lock.
[[nodiscard]] BuildResult build_project(const Manifest& manifest,
                                        std::span<const ProjectSource> sources,
                                        std::optional<std::string_view> expected_lock);

[[nodiscard]] std::string_view name(BuildToolError error) noexcept;

}  // namespace poko::mute

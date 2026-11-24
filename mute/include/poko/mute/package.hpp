#pragma once

#include "poko/mute/declaration.hpp"
#include <cstdint>
#include <span>
#include <string>
#include <string_view>
#include <vector>

namespace poko::mute {

// One package offered to the resolver: raw source plus the identity the
// caller claims for it. The source's own package/version declarations must
// match the claimed identity.
struct PackageInput {
  std::string name;
  std::string version;
  std::string_view source;
};

struct ImportRef {
  std::string name;    // package name from the pkg:// spec
  std::string version; // pinned word version, empty when unpinned
  std::string alias;
  Position position;
};

struct ResolvedPackage {
  std::string name;
  std::string version;
  std::uint64_t source_hash; // xxHash64 of the raw source bytes
  std::vector<ImportRef> imports;
};

enum class PackageErrorCode {
  parse_failed, missing_package_decl, missing_version_decl,
  identity_mismatch, duplicate_package, invalid_import_spec,
  missing_dependency, version_conflict, ambiguous_version, cyclic_import,
  input_limit
};
struct PackageDiagnostic {
  PackageErrorCode code;
  Position position;
  std::string detail; // package or import name for context
};
struct PackageResult {
  std::vector<PackageDiagnostic> diagnostics;
  std::vector<ResolvedPackage> packages; // deterministic order: name, then version
  [[nodiscard]] bool ok() const noexcept { return diagnostics.empty(); }
};

// Parses every input as a declaration module, extracts package identity and
// imports, then resolves the whole set as one build: every import must find
// exactly one compatible package, one version per name per build, and the
// dependency graph must be acyclic. Unpinned imports bind to the single
// available version of that name. Diagnostics are ordered deterministically.
[[nodiscard]] PackageResult resolve_packages(std::span<const PackageInput> inputs);

// Canonical mute.lock text: "# mute.lock v1" header then sorted
// "name@version hash" lines (16 lowercase hex digits), LF endings, trailing
// newline. Deterministic for a given resolved set.
[[nodiscard]] std::string dump_lockfile(const PackageResult& result);
[[nodiscard]] std::string_view name(PackageErrorCode code);
} // namespace poko::mute

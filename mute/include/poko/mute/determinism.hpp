#pragma once

#include "poko/mute/declaration.hpp"
#include <cstddef>
#include <cstdint>
#include <string>
#include <string_view>
#include <vector>

namespace poko::mute {

// Determinism and capability analysis (MUT-24 foundation). Scans a parsed
// declaration module for: unknown or duplicate `allow:` capability names,
// capability tokens inside `@state` declarations, and nondeterministic
// builtin calls that lack the required declared capability. Every diagnostic
// carries the original source position.
//
// Scope: declaration-level checks — `allow` ceilings, `@state` types and
// initializer expressions held in DeclarationAst::values(). Function-body
// statement scanning lands with the lowering milestones (MUT-25/26).

enum class DeterminismErrorCode {
  unknown_capability, duplicate_capability, capability_in_state,
  nondeterministic_operation
};
struct DeterminismDiagnostic {
  DeterminismErrorCode code;
  Position position;
  std::string detail;
};
struct DeterminismResult {
  std::vector<DeterminismDiagnostic> diagnostics;
  [[nodiscard]] bool ok() const noexcept { return diagnostics.empty(); }
};

[[nodiscard]] DeterminismResult analyze_determinism(const DeclarationAst& ast);
// The program's allow: ceiling as a capability mask (MUT-36). Unknown names
// contribute no bits; run analyze_determinism for those diagnostics. This is
// the ceiling a VmEnvironment's capabilities must not exceed.
[[nodiscard]] std::uint32_t program_capability_mask(const DeclarationAst& ast);
[[nodiscard]] std::string_view name(DeterminismErrorCode code);
[[nodiscard]] std::string dump_determinism(const DeterminismResult& result);
} // namespace poko::mute

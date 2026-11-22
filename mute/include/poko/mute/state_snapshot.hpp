#pragma once
#include "poko/mute/state.hpp"
#include <cstddef>
#include <cstdint>
#include <span>
#include <string_view>
#include <variant>
#include <vector>

namespace poko::mute {
// Experimental MUTS v1 state snapshot; not an authenticated replay log or .pkB.
// Exact source bytes are required both at save and restore. Allocation may throw.
inline constexpr std::size_t max_snapshot_source_bytes = 65'536;
inline constexpr std::size_t max_snapshot_bytes = 14 + max_snapshot_source_bytes + max_state_fields * 4 + 8;
enum class SnapshotErrorCode { invalid_source, source_too_large, invalid_state, invalid_format, source_mismatch, checksum_mismatch };
struct SnapshotError { SnapshotErrorCode code; std::size_t offset; };
using SaveStateResult = std::variant<std::vector<std::uint8_t>, SnapshotError>;
using LoadStateResult = std::variant<ProgramState, SnapshotError>;
[[nodiscard]] SaveStateResult save_state_snapshot(std::string_view source, const ProgramState& state);
// Returns a new state; caller decides when to replace its current state.
[[nodiscard]] LoadStateResult load_state_snapshot(std::string_view expected_source, std::span<const std::uint8_t> bytes);
} // namespace poko::mute

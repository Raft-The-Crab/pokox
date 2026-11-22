#pragma once
#include <cstddef>
#include <cstdint>
#include <span>
#include <string>
#include <variant>
#include <vector>

namespace poko::mute {
// Initial i32-only state. Fields are in source declaration order. Host-owned;
// do not access or modify concurrently with a tick. This is not a replay format.
struct StateField { std::string name; std::int32_t value=0; bool operator==(const StateField&) const = default; };
struct ProgramState { bool initialized=false; std::vector<StateField> fields; bool operator==(const ProgramState&) const = default; };
enum class StateError { uninitialized, invalid_state };
inline constexpr std::size_t max_state_fields=256;
[[nodiscard]] std::uint64_t xxhash64(std::span<const std::uint8_t> bytes,std::uint64_t seed=0) noexcept;
// Hashes i32 values in declaration order as four little-endian two's-complement bytes.
// The hash does not authenticate state or include names; tick validates the schema separately.
[[nodiscard]] std::variant<std::uint64_t,StateError> hash_state(const ProgramState& state);
} // namespace poko::mute

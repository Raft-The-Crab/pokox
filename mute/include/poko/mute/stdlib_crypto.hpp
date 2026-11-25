#pragma once

#include "poko/mute/hostcall.hpp"

#include <array>
#include <cstdint>
#include <optional>
#include <span>
#include <string>
#include <string_view>
#include <vector>

namespace poko::mute {

// MUT-53: fixed crypto implementations. v1 sign/verify is a detached
// HMAC-SHA256 tag over host-owned bytes; these APIs do not read clocks, files,
// network or entropy. Asymmetric publisher signatures remain a backend
// concern and are not part of the Mute sandbox API.
using Bytes = std::vector<std::uint8_t>;

[[nodiscard]] Bytes sha256(std::span<const std::uint8_t> input);
[[nodiscard]] Bytes hmac_sha256(std::span<const std::uint8_t> key,
                                std::span<const std::uint8_t> message);
[[nodiscard]] Bytes sign_detached(std::span<const std::uint8_t> key,
                                  std::span<const std::uint8_t> message);
[[nodiscard]] bool verify_detached(std::span<const std::uint8_t> key,
                                   std::span<const std::uint8_t> message,
                                   std::span<const std::uint8_t> signature) noexcept;
[[nodiscard]] std::string to_hex(std::span<const std::uint8_t> bytes);
[[nodiscard]] std::optional<Bytes> from_hex(std::string_view text) noexcept;

enum class CryptoHostcall : std::uint32_t {
  sha256 = 101,
  hmac_sha256 = 102,
  sign = 103,
  verify = 104
};

// Integer-only descriptors for the existing VM boundary. Byte buffers remain
// host-owned because v1 registers cannot carry strings or handles. The
// capability bits are the proof used by bind-time denial tests.
[[nodiscard]] std::vector<HostcallDef> crypto_hostcall_defs();

}  // namespace poko::mute

#pragma once

#include "poko/mute/input_snapshot.hpp"

#include <array>
#include <cstddef>
#include <cstdint>
#include <span>
#include <string_view>
#include <vector>

namespace poko::mute {

// MUT-40: deterministic device mapping. Keyboard and mouse are fixed slot-0
// sources; gamepads and touch displays receive the lowest free stable slot.
// Native device ids are host-side handles and are never written to replays:
// only the stable slot and connect/disconnect event are recorded.
enum class DeviceRouterError : std::uint8_t {
  ok = 0,
  unsupported_kind,
  invalid_slot,
  table_full,
  unknown_native,
  event_append_failed
};

struct DeviceRoute {
  DeviceId id{};
  std::uint64_t native_id{0};
  bool operator==(const DeviceRoute&) const = default;
};

class DeviceRouter {
 public:
  static constexpr std::size_t max_routes = 64;

  // Connects a native gamepad/touch handle. Duplicate connections of the same
  // handle return the existing slot without appending a second event.
  [[nodiscard]] DeviceRouterError connect(DeviceKind kind, std::uint64_t native_id,
                                          std::uint64_t tick, InputTimeline& timeline,
                                          DeviceId* out = nullptr);
  [[nodiscard]] DeviceRouterError disconnect(std::uint64_t native_id, std::uint64_t tick,
                                             InputTimeline& timeline, DeviceId* out = nullptr);

  [[nodiscard]] bool find(DeviceKind kind, std::uint64_t native_id, DeviceId& out) const noexcept;
  [[nodiscard]] bool find_native(std::uint64_t native_id, DeviceRoute& out) const noexcept;
  [[nodiscard]] std::size_t route_count() const noexcept;

  // Deterministic order: keyboard, mouse, gamepad slots, touch display slots.
  [[nodiscard]] std::vector<DeviceRoute> routes() const;
  void clear() noexcept;

 private:
  struct Mapping {
    bool used{false};
    DeviceKind kind{DeviceKind::none};
    std::uint8_t slot{0};
    std::uint64_t native_id{0};
  };

  [[nodiscard]] bool slot_in_use(DeviceKind kind, std::uint8_t slot) const noexcept;

  std::array<Mapping, max_routes> mappings_{};
};

[[nodiscard]] constexpr std::uint16_t gamepad_device_code(DeviceId id, std::uint8_t button) noexcept {
  return pack_gamepad_code(id.slot, button);
}
[[nodiscard]] constexpr std::uint16_t touch_device_code(DeviceId id, std::uint8_t touch) noexcept {
  return pack_gamepad_code(id.slot, touch);
}

[[nodiscard]] std::string_view name(DeviceRouterError error) noexcept;

}  // namespace poko::mute

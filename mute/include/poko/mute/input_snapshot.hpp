#pragma once

#include "poko/mute/state.hpp"
#include <array>
#include <cstddef>
#include <cstdint>
#include <span>
#include <string_view>
#include <utility>
#include <variant>
#include <vector>

namespace poko::mute {

// MUT-38: deterministic input snapshots. The host records input events with
// the simulation tick at which they were observed, and a replay feeds the
// same events to the same tick sequence. Nothing here touches SDL or the
// wall clock: the host adapter converts its native events into InputEvents,
// so recorded replays do not depend on device timing or driver ordering.
//
// `focus_lost` clears held keys/buttons, gamepad state and touches, and
// suspends motion accumulation until `focus_gained`; that makes focus loss
// replayable instead of leaving stuck inputs in the snapshot. Key codes are
// host-defined but must be stable across record/replay (MUT-39 binds named
// actions to them). Gamepad and touch events are minimal sources for action
// bindings. MUT-40 adds stable device slots: gamepad/touch event codes pack
// the device slot in the high byte and the control/touch id in the low byte,
// so existing slot-0 recordings remain byte-compatible.

enum class InputKind : std::uint8_t {
  none = 0, key = 1, mouse_button = 2, mouse_motion = 3, mouse_wheel = 4,
  focus_lost = 5, focus_gained = 6, quit = 7, resize = 8,
  gamepad_button = 9, gamepad_axis = 10, touch_tap = 11,
  device_connected = 12, device_disconnected = 13
};

enum class DeviceKind : std::uint8_t {
  none = 0, keyboard = 1, mouse = 2, gamepad = 3, touch = 4
};

struct DeviceId {
  DeviceKind kind{DeviceKind::none};
  std::uint8_t slot{0};
  bool operator==(const DeviceId&) const = default;
};

[[nodiscard]] constexpr std::uint16_t pack_device_code(DeviceKind kind, std::uint8_t slot) noexcept {
  return static_cast<std::uint16_t>((static_cast<std::uint16_t>(kind) << 8) | slot);
}
[[nodiscard]] constexpr DeviceId unpack_device_code(std::uint16_t code) noexcept {
  return {static_cast<DeviceKind>(code >> 8), static_cast<std::uint8_t>(code & 0xffu)};
}
[[nodiscard]] constexpr std::uint16_t pack_gamepad_code(std::uint8_t slot, std::uint8_t control) noexcept {
  return static_cast<std::uint16_t>((static_cast<std::uint16_t>(slot) << 8) | control);
}
[[nodiscard]] constexpr std::uint16_t gamepad_slot(std::uint16_t code) noexcept {
  return static_cast<std::uint8_t>(code >> 8);
}
[[nodiscard]] constexpr std::uint8_t gamepad_control(std::uint16_t code) noexcept {
  return static_cast<std::uint8_t>(code & 0xffu);
}
[[nodiscard]] constexpr std::uint8_t touch_display(std::uint16_t code) noexcept {
  return gamepad_slot(code);
}
[[nodiscard]] constexpr std::uint8_t touch_id(std::uint16_t code) noexcept {
  return gamepad_control(code);
}

struct InputEvent {
  InputKind kind{InputKind::none};
  // key: key code; mouse_button: button index (1 = left); gamepad_button:
  // packed slot/button; gamepad_axis: packed slot/axis; touch_tap: packed
  // display/touch id; device_connected/disconnected: packed DeviceId.
  std::uint16_t code{0};
  bool pressed{false};  // down for key/button/touch events
  // mouse_motion/touch_tap: x/y in fixed-point host units;
  // gamepad_axis: signed axis value; others zero.
  std::int32_t dx{0}, dy{0};
  std::int32_t wheel{0};      // signed mouse-wheel detents
  std::uint32_t width{0}, height{0};  // resize viewport, or touch viewport
  bool operator==(const InputEvent&) const = default;
};

// Deterministic input state after applying a recorded event sequence.
struct InputState {
  static constexpr std::size_t max_gamepads = 16;
  static constexpr std::size_t max_gamepad_axes = 8;
  static constexpr std::size_t max_touch_displays = 16;
  static constexpr std::size_t max_touches = 16;

  bool focused{true};
  std::array<std::uint8_t,32> held_keys{};  // bit i = key code i held
  std::uint64_t held_buttons{0};            // bit i = mouse button i held
  // Slot 0 is assumed present so slot-0 MUT-38/MUT-39 recordings remain valid.
  std::uint16_t connected_gamepads{1};
  std::uint16_t connected_touch_displays{1};
  std::array<std::uint64_t,max_gamepads> held_gamepad_buttons{};
  std::array<std::array<std::int32_t,max_gamepad_axes>,max_gamepads> gamepad_axes{};
  std::array<std::array<std::uint8_t,max_touches>,max_touch_displays> held_touches{};
  std::array<std::array<std::int32_t,max_touches>,max_touch_displays> touch_x{}, touch_y{};
  std::array<std::uint32_t,max_touch_displays> touch_width{}, touch_height{};
  std::int64_t motion_x{0}, motion_y{0}, wheel_total{0};

  void apply(const InputEvent& event) noexcept;
  // xxhash64 over the canonical little-endian state bytes.
  [[nodiscard]] std::uint64_t hash() const noexcept;
  [[nodiscard]] bool key_down(std::uint16_t code) const noexcept;
  [[nodiscard]] bool button_down(std::uint16_t code) const noexcept;

  [[nodiscard]] bool gamepad_connected(std::uint8_t slot) const noexcept;
  [[nodiscard]] bool gamepad_button_down(std::uint16_t packed_code) const noexcept;
  [[nodiscard]] bool gamepad_button_down(std::uint8_t slot, std::uint8_t button) const noexcept;
  [[nodiscard]] std::int32_t gamepad_axis_value(std::uint16_t packed_code) const noexcept;
  [[nodiscard]] std::int32_t gamepad_axis_value(std::uint8_t slot, std::uint8_t axis) const noexcept;

  [[nodiscard]] bool touch_display_connected(std::uint8_t slot) const noexcept;
  [[nodiscard]] bool touch_down(std::uint16_t packed_code) const noexcept;
  [[nodiscard]] bool touch_down(std::uint8_t display, std::uint8_t touch) const noexcept;
  [[nodiscard]] std::pair<std::int32_t,std::int32_t> touch_position(std::uint16_t packed_code) const noexcept;
  [[nodiscard]] std::pair<std::int32_t,std::int32_t> touch_position(std::uint8_t display,
                                                                    std::uint8_t touch) const noexcept;
};

enum class InputError : std::uint8_t {
  invalid_format, unsupported_version, truncated, size_limit,
  non_monotonic_tick, invalid_event, trailing_bytes
};

// Flat, tick-tagged event log. Events for one tick are stored in arrival
// order; replay preserves that order exactly (reordering changes the tick
// snapshot hash). Ticks must be non-decreasing and event count is bounded.
class InputTimeline {
 public:
  static constexpr std::size_t max_events = 65'536;
  struct Record { std::uint64_t tick{}; InputEvent event{}; };

  [[nodiscard]] bool append(std::uint64_t tick, const InputEvent& event);
  [[nodiscard]] std::size_t size() const noexcept { return ticks_.size(); }
  [[nodiscard]] Record record(std::size_t i) const noexcept { return {ticks_[i], events_[i]}; }
  [[nodiscard]] std::span<const InputEvent> at(std::uint64_t tick) const noexcept;
  [[nodiscard]] bool empty() const noexcept { return ticks_.empty(); }

  // Canonical binary form: "MUTI", version 1, u32 count, then 32-byte
  // records (u64 tick, u8 kind, u16 code, u8 pressed, i32 dx/dy/wheel,
  // u32 width/height). Little-endian; strict decode rejects trailing bytes.
  [[nodiscard]] std::vector<std::uint8_t> encode() const;
  [[nodiscard]] static std::variant<InputTimeline, InputError> decode(std::span<const std::uint8_t> bytes);

  // Hash of a tick snapshot: tick, post-event input state and the exact
  // event sequence for that tick. Identical ticks in a replay must produce
  // identical hashes.
  [[nodiscard]] std::uint64_t snapshot_hash(std::uint64_t tick, const InputState& state) const noexcept;

 private:
  std::vector<std::uint64_t> ticks_;
  std::vector<InputEvent> events_;
};

// Replays a timeline once, yielding each tick's events in record order.
class InputReplay {
 public:
  explicit InputReplay(const InputTimeline& timeline) noexcept : timeline_(timeline) {}
  [[nodiscard]] bool next(std::uint64_t& tick, std::span<const InputEvent>& events) noexcept;
  [[nodiscard]] bool done() const noexcept { return index_ >= timeline_.size(); }
  [[nodiscard]] std::size_t position() const noexcept { return index_; }
 private:
  const InputTimeline& timeline_;
  std::size_t index_{0};
};

[[nodiscard]] std::string_view name(InputError error) noexcept;

}  // namespace poko::mute

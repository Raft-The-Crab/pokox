#include "poko/mute/input_snapshot.hpp"

#include <algorithm>
#include <array>
#include <cstring>

namespace poko::mute {
namespace {
constexpr std::size_t record_bytes = 32;

void put8(std::vector<std::uint8_t>& out, std::uint8_t v) { out.push_back(v); }
void put16(std::vector<std::uint8_t>& out, std::uint16_t v) {
  for (int i = 0; i < 2; ++i) put8(out, static_cast<std::uint8_t>(v >> (8 * i)));
}
void put32(std::vector<std::uint8_t>& out, std::uint32_t v) {
  for (int i = 0; i < 4; ++i) put8(out, static_cast<std::uint8_t>(v >> (8 * i)));
}
void put64(std::vector<std::uint8_t>& out, std::uint64_t v) {
  for (int i = 0; i < 8; ++i) put8(out, static_cast<std::uint8_t>(v >> (8 * i)));
}
void put_event(std::vector<std::uint8_t>& out, const InputEvent& e) {
  put8(out, static_cast<std::uint8_t>(e.kind));
  put16(out, e.code);
  put8(out, e.pressed ? 1 : 0);
  put32(out, static_cast<std::uint32_t>(e.dx));
  put32(out, static_cast<std::uint32_t>(e.dy));
  put32(out, static_cast<std::uint32_t>(e.wheel));
  put32(out, e.width);
  put32(out, e.height);
}
bool read_bytes(std::span<const std::uint8_t> bytes, std::size_t& at, void* dst, std::size_t n) {
  if (at > bytes.size() || n > bytes.size() - at) return false;
  std::memcpy(dst, bytes.data() + at, n);
  at += n;
  return true;
}
std::uint8_t get8(std::span<const std::uint8_t> bytes, std::size_t& at) {
  std::uint8_t v{}; read_bytes(bytes, at, &v, 1); return v;
}
std::uint16_t get16(std::span<const std::uint8_t> bytes, std::size_t& at) {
  std::uint8_t b[2]{}; read_bytes(bytes, at, b, 2);
  return static_cast<std::uint16_t>(b[0] | (static_cast<std::uint16_t>(b[1]) << 8));
}
std::uint32_t get32(std::span<const std::uint8_t> bytes, std::size_t& at) {
  std::uint8_t b[4]{}; read_bytes(bytes, at, b, 4);
  std::uint32_t v = 0;
  for (int i = 0; i < 4; ++i) v |= static_cast<std::uint32_t>(b[i]) << (8 * i);
  return v;
}
std::uint64_t get64(std::span<const std::uint8_t> bytes, std::size_t& at) {
  std::uint8_t b[8]{}; read_bytes(bytes, at, b, 8);
  std::uint64_t v = 0;
  for (int i = 0; i < 8; ++i) v |= static_cast<std::uint64_t>(b[i]) << (8 * i);
  return v;
}
bool valid_event(const InputEvent& e) noexcept {
  const bool no_motion = e.dx == 0 && e.dy == 0 && e.wheel == 0;
  switch (e.kind) {
    case InputKind::key:
      return e.code <= 255 && no_motion && e.width == 0 && e.height == 0;
    case InputKind::mouse_button:
      return e.code <= 63 && no_motion && e.width == 0 && e.height == 0;
    case InputKind::mouse_motion:
      return e.code == 0 && !e.pressed && e.wheel == 0 && e.width == 0 && e.height == 0;
    case InputKind::mouse_wheel:
      return e.code == 0 && !e.pressed && e.dx == 0 && e.dy == 0 && e.width == 0 && e.height == 0;
    case InputKind::resize:
      return e.code == 0 && !e.pressed && no_motion;
    case InputKind::gamepad_button:
      return gamepad_slot(e.code) < InputState::max_gamepads &&
             gamepad_control(e.code) <= 63 && no_motion &&
             e.wheel == 0 && e.width == 0 && e.height == 0;
    case InputKind::gamepad_axis:
      return gamepad_slot(e.code) < InputState::max_gamepads &&
             gamepad_control(e.code) < InputState::max_gamepad_axes &&
             !e.pressed && e.dy == 0 && e.wheel == 0 &&
             e.width == 0 && e.height == 0;
    case InputKind::touch_tap:
      return touch_display(e.code) < InputState::max_touch_displays &&
             touch_id(e.code) < InputState::max_touches && e.wheel == 0;
    case InputKind::device_connected: case InputKind::device_disconnected: {
      const auto id = unpack_device_code(e.code);
      return (id.kind == DeviceKind::gamepad || id.kind == DeviceKind::touch) &&
             id.slot < (id.kind == DeviceKind::gamepad
                            ? InputState::max_gamepads : InputState::max_touch_displays) &&
             !e.pressed && no_motion && e.width == 0 && e.height == 0;
    }
    case InputKind::focus_lost: case InputKind::focus_gained: case InputKind::quit:
      return e.code == 0 && !e.pressed && no_motion && e.width == 0 && e.height == 0;
    default: return false;
  }
}
}  // namespace

bool InputState::key_down(std::uint16_t code) const noexcept {
  if (code > 255) return false;
  return (held_keys[code >> 3] & (1u << (code & 7))) != 0;
}
bool InputState::button_down(std::uint16_t code) const noexcept {
  if (code > 63) return false;
  return (held_buttons & (std::uint64_t{1} << code)) != 0;
}
bool InputState::gamepad_connected(std::uint8_t slot) const noexcept {
  return slot < max_gamepads && (connected_gamepads & (std::uint16_t{1} << slot)) != 0;
}
bool InputState::gamepad_button_down(std::uint16_t code) const noexcept {
  return gamepad_button_down(gamepad_slot(code), gamepad_control(code));
}
bool InputState::gamepad_button_down(std::uint8_t slot, std::uint8_t button) const noexcept {
  if (!gamepad_connected(slot) || button > 63) return false;
  return (held_gamepad_buttons[slot] & (std::uint64_t{1} << button)) != 0;
}
std::int32_t InputState::gamepad_axis_value(std::uint16_t code) const noexcept {
  return gamepad_axis_value(gamepad_slot(code), gamepad_control(code));
}
std::int32_t InputState::gamepad_axis_value(std::uint8_t slot, std::uint8_t axis) const noexcept {
  if (!gamepad_connected(slot) || axis >= max_gamepad_axes) return 0;
  return gamepad_axes[slot][axis];
}
bool InputState::touch_display_connected(std::uint8_t slot) const noexcept {
  return slot < max_touch_displays && (connected_touch_displays & (std::uint16_t{1} << slot)) != 0;
}
bool InputState::touch_down(std::uint16_t code) const noexcept {
  return touch_down(touch_display(code), touch_id(code));
}
bool InputState::touch_down(std::uint8_t display, std::uint8_t touch) const noexcept {
  if (!touch_display_connected(display) || touch >= max_touches) return false;
  return (held_touches[display][touch] & 1u) != 0;
}
std::pair<std::int32_t,std::int32_t> InputState::touch_position(std::uint16_t code) const noexcept {
  return touch_position(touch_display(code), touch_id(code));
}
std::pair<std::int32_t,std::int32_t> InputState::touch_position(std::uint8_t display,
                                                                std::uint8_t touch) const noexcept {
  if (!touch_display_connected(display) || touch >= max_touches) return {0, 0};
  return {touch_x[display][touch], touch_y[display][touch]};
}

void InputState::apply(const InputEvent& event) noexcept {
  switch (event.kind) {
    case InputKind::key:
      if (!focused || event.code > 255) break;
      if (event.pressed) held_keys[event.code >> 3] |= static_cast<std::uint8_t>(1u << (event.code & 7));
      else held_keys[event.code >> 3] &= static_cast<std::uint8_t>(~(1u << (event.code & 7)));
      break;
    case InputKind::mouse_button:
      if (!focused || event.code > 63) break;
      if (event.pressed) held_buttons |= std::uint64_t{1} << event.code;
      else held_buttons &= ~(std::uint64_t{1} << event.code);
      break;
    case InputKind::mouse_motion:
      if (focused) { motion_x += event.dx; motion_y += event.dy; }
      break;
    case InputKind::mouse_wheel:
      if (focused) wheel_total += event.wheel;
      break;
    case InputKind::gamepad_button: {
      const auto slot = gamepad_slot(event.code);
      const auto button = gamepad_control(event.code);
      if (!focused || !gamepad_connected(slot) || button > 63) break;
      if (event.pressed) held_gamepad_buttons[slot] |= std::uint64_t{1} << button;
      else held_gamepad_buttons[slot] &= ~(std::uint64_t{1} << button);
      break;
    }
    case InputKind::gamepad_axis: {
      const auto slot = gamepad_slot(event.code);
      const auto axis = gamepad_control(event.code);
      if (!focused || !gamepad_connected(slot) || axis >= max_gamepad_axes) break;
      gamepad_axes[slot][axis] = event.dx;
      break;
    }
    case InputKind::touch_tap: {
      const auto display = touch_display(event.code);
      const auto touch = touch_id(event.code);
      if (!focused || !touch_display_connected(display) || touch >= max_touches) break;
      if (event.width != 0 || event.height != 0) {
        touch_width[display] = event.width;
        touch_height[display] = event.height;
      }
      touch_x[display][touch] = event.dx;
      touch_y[display][touch] = event.dy;
      held_touches[display][touch] = event.pressed ? 1 : 0;
      break;
    }
    case InputKind::device_connected: {
      const auto id = unpack_device_code(event.code);
      if (id.kind == DeviceKind::gamepad && id.slot < max_gamepads) {
        connected_gamepads |= static_cast<std::uint16_t>(std::uint16_t{1} << id.slot);
        held_gamepad_buttons[id.slot] = 0;
        gamepad_axes[id.slot].fill(0);
      } else if (id.kind == DeviceKind::touch && id.slot < max_touch_displays) {
        connected_touch_displays |= static_cast<std::uint16_t>(std::uint16_t{1} << id.slot);
        held_touches[id.slot].fill(0);
        touch_x[id.slot].fill(0);
        touch_y[id.slot].fill(0);
        touch_width[id.slot] = 0;
        touch_height[id.slot] = 0;
      }
      break;
    }
    case InputKind::device_disconnected: {
      const auto id = unpack_device_code(event.code);
      if (id.kind == DeviceKind::gamepad && id.slot < max_gamepads) {
        connected_gamepads &= static_cast<std::uint16_t>(~(std::uint16_t{1} << id.slot));
        held_gamepad_buttons[id.slot] = 0;
        gamepad_axes[id.slot].fill(0);
      } else if (id.kind == DeviceKind::touch && id.slot < max_touch_displays) {
        connected_touch_displays &= static_cast<std::uint16_t>(~(std::uint16_t{1} << id.slot));
        held_touches[id.slot].fill(0);
        touch_x[id.slot].fill(0);
        touch_y[id.slot].fill(0);
        touch_width[id.slot] = 0;
        touch_height[id.slot] = 0;
      }
      break;
    }
    case InputKind::focus_lost:
      focused = false;
      held_keys.fill(0);
      held_buttons = 0;
      held_gamepad_buttons.fill(0);
      for (auto& axes : gamepad_axes) axes.fill(0);
      for (auto& touches : held_touches) touches.fill(0);
      for (auto& xs : touch_x) xs.fill(0);
      for (auto& ys : touch_y) ys.fill(0);
      touch_width.fill(0);
      touch_height.fill(0);
      break;
    case InputKind::focus_gained:
      focused = true;
      break;
    default: break;  // quit/resize/none do not change input state
  }
}

std::uint64_t InputState::hash() const noexcept {
  std::vector<std::uint8_t> bytes;
  bytes.reserve(1 + held_keys.size() + 8 + 2 + 2 + max_gamepads * 8 +
                max_gamepads * max_gamepad_axes * 4 +
                max_touch_displays * max_touches * 3 * 4 +
                max_touch_displays * 2 * 4 + 24);
  put8(bytes, focused ? 1 : 0);
  for (const auto byte : held_keys) put8(bytes, byte);
  put64(bytes, held_buttons);
  put16(bytes, connected_gamepads);
  put16(bytes, connected_touch_displays);
  // Cast signed values to two's-complement before little-endian encoding.
  for (const auto buttons : held_gamepad_buttons) put64(bytes, buttons);
  for (const auto& axes : gamepad_axes)
    for (const auto axis : axes) put32(bytes, static_cast<std::uint32_t>(axis));
  for (const auto& touches : held_touches)
    for (const auto touch : touches) put8(bytes, touch);
  for (const auto& xs : touch_x)
    for (const auto x : xs) put32(bytes, static_cast<std::uint32_t>(x));
  for (const auto& ys : touch_y)
    for (const auto y : ys) put32(bytes, static_cast<std::uint32_t>(y));
  for (const auto width : touch_width) put32(bytes, width);
  for (const auto height : touch_height) put32(bytes, height);
  put64(bytes, static_cast<std::uint64_t>(motion_x));
  put64(bytes, static_cast<std::uint64_t>(motion_y));
  put64(bytes, static_cast<std::uint64_t>(wheel_total));
  return xxhash64(bytes);
}

bool InputTimeline::append(std::uint64_t tick, const InputEvent& event) {
  if (ticks_.size() >= max_events || !valid_event(event)) return false;
  if (!ticks_.empty() && tick < ticks_.back()) return false;
  ticks_.push_back(tick);
  events_.push_back(event);
  return true;
}

std::span<const InputEvent> InputTimeline::at(std::uint64_t tick) const noexcept {
  auto it = std::lower_bound(ticks_.begin(), ticks_.end(), tick);
  if (it == ticks_.end() || *it != tick) return {};
  const auto first = static_cast<std::size_t>(it - ticks_.begin());
  auto last = first;
  while (last < ticks_.size() && ticks_[last] == tick) ++last;
  return {events_.data() + first, last - first};
}

std::vector<std::uint8_t> InputTimeline::encode() const {
  std::vector<std::uint8_t> out;
  out.reserve(12 + ticks_.size() * record_bytes);
  for (const char c : std::string_view("MUTI")) put8(out, static_cast<std::uint8_t>(c));
  put8(out, 1); put8(out, 0); put8(out, 0); put8(out, 0);
  put32(out, static_cast<std::uint32_t>(ticks_.size()));
  for (std::size_t i = 0; i < ticks_.size(); ++i) {
    put64(out, ticks_[i]);
    put_event(out, events_[i]);
  }
  return out;
}

std::variant<InputTimeline, InputError> InputTimeline::decode(std::span<const std::uint8_t> bytes) {
  if (bytes.size() < 12) return InputError::truncated;
  if (bytes[0] != 'M' || bytes[1] != 'U' || bytes[2] != 'T' || bytes[3] != 'I') return InputError::invalid_format;
  if (bytes[4] != 1 || bytes[5] || bytes[6] || bytes[7]) return InputError::unsupported_version;
  std::size_t at = 8;
  const std::uint32_t count = get32(bytes, at);
  if (count > max_events) return InputError::size_limit;
  if (bytes.size() != 12 + static_cast<std::size_t>(count) * record_bytes) return InputError::trailing_bytes;
  InputTimeline out;
  for (std::uint32_t i = 0; i < count; ++i) {
    const std::uint64_t tick = get64(bytes, at);
    InputEvent e;
    e.kind = static_cast<InputKind>(get8(bytes, at));
    e.code = get16(bytes, at);
    e.pressed = get8(bytes, at) != 0;
    e.dx = static_cast<std::int32_t>(get32(bytes, at));
    e.dy = static_cast<std::int32_t>(get32(bytes, at));
    e.wheel = static_cast<std::int32_t>(get32(bytes, at));
    e.width = get32(bytes, at);
    e.height = get32(bytes, at);
    if (i && tick < out.record(i - 1).tick) return InputError::non_monotonic_tick;
    if (!out.append(tick, e)) return InputError::invalid_event;
  }
  return out;
}

std::uint64_t InputTimeline::snapshot_hash(std::uint64_t tick, const InputState& state) const noexcept {
  std::vector<std::uint8_t> bytes;
  bytes.reserve(8 + 8 + 4 + max_events * 8);
  put64(bytes, tick);
  put64(bytes, state.hash());
  const auto events = at(tick);
  put32(bytes, static_cast<std::uint32_t>(events.size()));
  for (const auto& e : events) put_event(bytes, e);
  return xxhash64(bytes);
}

bool InputReplay::next(std::uint64_t& tick, std::span<const InputEvent>& events) noexcept {
  if (done()) return false;
  tick = timeline_.record(index_).tick;
  std::size_t end = index_ + 1;
  while (end < timeline_.size() && timeline_.record(end).tick == tick) ++end;
  events = timeline_.at(tick);
  index_ = end;
  return true;
}

std::string_view name(InputError error) noexcept {
  constexpr std::array<std::string_view, 7> names{
    "invalid_format", "unsupported_version", "truncated", "size_limit",
    "non_monotonic_tick", "invalid_event", "trailing_bytes"};
  const auto i = static_cast<std::size_t>(error);
  return i < names.size() ? names[i] : std::string_view{};
}

}  // namespace poko::mute

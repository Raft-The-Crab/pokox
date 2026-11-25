#include "poko/mute/device_router.hpp"

#include <algorithm>
#include <array>

namespace poko::mute {

bool DeviceRouter::slot_in_use(DeviceKind kind, std::uint8_t slot) const noexcept {
  for (const auto& m : mappings_)
    if (m.used && m.kind == kind && m.slot == slot) return true;
  return false;
}

DeviceRouterError DeviceRouter::connect(DeviceKind kind, std::uint64_t native_id,
                                        std::uint64_t tick, InputTimeline& timeline,
                                        DeviceId* out) {
  if (kind != DeviceKind::gamepad && kind != DeviceKind::touch)
    return DeviceRouterError::unsupported_kind;
  DeviceRoute existing{};
  if (find_native(native_id, existing)) {
    if (out) *out = existing.id;
    return DeviceRouterError::ok;
  }
  const auto max_slots = kind == DeviceKind::gamepad
                             ? InputState::max_gamepads : InputState::max_touch_displays;
  std::uint8_t slot = 0;
  while (slot < max_slots && slot_in_use(kind, slot)) ++slot;
  if (slot >= max_slots) return DeviceRouterError::invalid_slot;

  Mapping* free = nullptr;
  for (auto& m : mappings_)
    if (!m.used) { free = &m; break; }
  if (free == nullptr) return DeviceRouterError::table_full;

  const DeviceId id{kind, slot};
  if (!timeline.append(tick, InputEvent{InputKind::device_connected,
                                        pack_device_code(kind, slot)}))
    return DeviceRouterError::event_append_failed;
  free->used = true;
  free->kind = kind;
  free->slot = slot;
  free->native_id = native_id;
  if (out) *out = id;
  return DeviceRouterError::ok;
}

DeviceRouterError DeviceRouter::disconnect(std::uint64_t native_id, std::uint64_t tick,
                                           InputTimeline& timeline, DeviceId* out) {
  Mapping* found = nullptr;
  for (auto& m : mappings_)
    if (m.used && m.native_id == native_id) { found = &m; break; }
  if (found == nullptr) return DeviceRouterError::unknown_native;
  const DeviceId id{found->kind, found->slot};
  if (!timeline.append(tick, InputEvent{InputKind::device_disconnected,
                                        pack_device_code(id.kind, id.slot)}))
    return DeviceRouterError::event_append_failed;
  if (out) *out = id;
  *found = Mapping{};
  return DeviceRouterError::ok;
}

bool DeviceRouter::find(DeviceKind kind, std::uint64_t native_id, DeviceId& out) const noexcept {
  if (kind == DeviceKind::keyboard || kind == DeviceKind::mouse) {
    out = {kind, 0};
    return true;
  }
  for (const auto& m : mappings_)
    if (m.used && m.kind == kind && m.native_id == native_id) {
      out = {m.kind, m.slot};
      return true;
    }
  return false;
}

bool DeviceRouter::find_native(std::uint64_t native_id, DeviceRoute& out) const noexcept {
  for (const auto& m : mappings_)
    if (m.used && m.native_id == native_id) {
      out = {{m.kind, m.slot}, m.native_id};
      return true;
    }
  return false;
}

std::size_t DeviceRouter::route_count() const noexcept {
  std::size_t count = 0;
  for (const auto& m : mappings_) if (m.used) ++count;
  return count;
}

std::vector<DeviceRoute> DeviceRouter::routes() const {
  std::vector<DeviceRoute> out;
  out.reserve(route_count());
  for (const auto& m : mappings_)
    if (m.used) out.push_back({{m.kind, m.slot}, m.native_id});
  std::sort(out.begin(), out.end(), [](const DeviceRoute& a, const DeviceRoute& b) {
    if (a.id.kind != b.id.kind)
      return static_cast<std::uint8_t>(a.id.kind) < static_cast<std::uint8_t>(b.id.kind);
    return a.id.slot < b.id.slot;
  });
  return out;
}

void DeviceRouter::clear() noexcept {
  mappings_.fill(Mapping{});
}

std::string_view name(DeviceRouterError error) noexcept {
  constexpr std::array<std::string_view, 6> names{
    "ok", "unsupported_kind", "invalid_slot", "table_full",
    "unknown_native", "event_append_failed"};
  const auto i = static_cast<std::size_t>(error);
  return i < names.size() ? names[i] : std::string_view{};
}

}  // namespace poko::mute

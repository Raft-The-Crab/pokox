#include "poko/mute/action_map.hpp"

#include <algorithm>
#include <array>
#include <cstring>
#include <limits>

namespace poko::mute {
namespace {
constexpr std::size_t binding_bytes = 7;

void put8(std::vector<std::uint8_t>& out, std::uint8_t v) { out.push_back(v); }
void put16(std::vector<std::uint8_t>& out, std::uint16_t v) {
  for (int i = 0; i < 2; ++i) put8(out, static_cast<std::uint8_t>(v >> (8 * i)));
}
void put32(std::vector<std::uint8_t>& out, std::uint32_t v) {
  for (int i = 0; i < 4; ++i) put8(out, static_cast<std::uint8_t>(v >> (8 * i)));
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
bool is_axis_device(BindingDevice device) noexcept {
  return device == BindingDevice::mouse_wheel || device == BindingDevice::gamepad_axis;
}
int sign_of(std::int32_t value) noexcept { return value > 0 ? 1 : (value < 0 ? -1 : 0); }
std::int32_t clamp_i32(std::int64_t value) noexcept {
  constexpr auto lo = static_cast<std::int64_t>(std::numeric_limits<std::int32_t>::min());
  constexpr auto hi = static_cast<std::int64_t>(std::numeric_limits<std::int32_t>::max());
  return static_cast<std::int32_t>(std::clamp(value, lo, hi));
}
}  // namespace

ActionError validate_binding(const Binding& binding) noexcept {
  switch (binding.device) {
    case BindingDevice::keyboard:
      return binding.code <= 255 && binding.threshold == 0 ? ActionError::ok : ActionError::invalid_binding;
    case BindingDevice::mouse_button:
      return binding.code <= 63 && binding.threshold == 0 ? ActionError::ok : ActionError::invalid_binding;
    case BindingDevice::mouse_wheel:
      return binding.code == 0 && binding.threshold != 0 ? ActionError::ok : ActionError::invalid_binding;
    case BindingDevice::gamepad_button:
      return gamepad_slot(binding.code) < InputState::max_gamepads &&
                     gamepad_control(binding.code) <= 63 && binding.threshold == 0
                 ? ActionError::ok : ActionError::invalid_binding;
    case BindingDevice::gamepad_axis:
      return gamepad_slot(binding.code) < InputState::max_gamepads &&
                     gamepad_control(binding.code) < InputState::max_gamepad_axes &&
                     binding.threshold != 0
                 ? ActionError::ok : ActionError::invalid_binding;
    case BindingDevice::touch:
      return touch_display(binding.code) < InputState::max_touch_displays &&
                     touch_id(binding.code) < InputState::max_touches && binding.threshold == 0
                 ? ActionError::ok : ActionError::invalid_binding;
    default:
      return ActionError::invalid_binding;
  }
}

bool bindings_conflict(const Binding& a, const Binding& b) noexcept {
  if (validate_binding(a) != ActionError::ok || validate_binding(b) != ActionError::ok) return false;
  if (a.device != b.device || a.code != b.code) return false;
  if (is_axis_device(a.device) || is_axis_device(b.device))
    return sign_of(a.threshold) == sign_of(b.threshold);
  return true;
}

std::size_t ActionMap::find(std::string_view name) const noexcept {
  for (std::size_t i = 0; i < actions_.size(); ++i)
    if (actions_[i].name == name) return i;
  return actions_.size();
}

ActionError ActionMap::define_action(std::string_view name) {
  if (name.empty() || name.size() > max_name_bytes ||
      name.find('\0') != std::string_view::npos) return ActionError::invalid_name;
  if (find(name) != actions_.size()) return ActionError::duplicate_action;
  if (actions_.size() >= max_actions) return ActionError::too_many_actions;
  actions_.push_back(ActionDef{std::string(name), {}});
  return ActionError::ok;
}

ActionError ActionMap::remove_action(std::string_view name) {
  const auto i = find(name);
  if (i == actions_.size()) return ActionError::action_not_found;
  actions_.erase(actions_.begin() + static_cast<std::ptrdiff_t>(i));
  return ActionError::ok;
}

ActionError ActionMap::add_binding(std::string_view name, const Binding& binding) {
  const auto i = find(name);
  if (i == actions_.size()) return ActionError::action_not_found;
  if (validate_binding(binding) != ActionError::ok) return ActionError::invalid_binding;
  auto& bindings = actions_[i].bindings;
  if (bindings.size() >= max_bindings_per_action) return ActionError::too_many_bindings;
  for (const auto& existing : bindings)
    if (bindings_conflict(existing, binding)) return ActionError::duplicate_binding;
  bindings.push_back(binding);
  return ActionError::ok;
}

ActionError ActionMap::replace_binding(std::string_view name, std::size_t index,
                                       const Binding& binding) {
  const auto i = find(name);
  if (i == actions_.size()) return ActionError::action_not_found;
  auto& bindings = actions_[i].bindings;
  if (index >= bindings.size()) return ActionError::binding_not_found;
  if (validate_binding(binding) != ActionError::ok) return ActionError::invalid_binding;
  for (std::size_t j = 0; j < bindings.size(); ++j)
    if (j != index && bindings_conflict(bindings[j], binding)) return ActionError::duplicate_binding;
  bindings[index] = binding;
  return ActionError::ok;
}

ActionError ActionMap::set_bindings(std::string_view name, std::span<const Binding> bindings) {
  const auto i = find(name);
  if (i == actions_.size()) return ActionError::action_not_found;
  if (bindings.size() > max_bindings_per_action) return ActionError::too_many_bindings;
  for (std::size_t j = 0; j < bindings.size(); ++j) {
    if (validate_binding(bindings[j]) != ActionError::ok) return ActionError::invalid_binding;
    for (std::size_t k = 0; k < j; ++k)
      if (bindings_conflict(bindings[j], bindings[k])) return ActionError::duplicate_binding;
  }
  actions_[i].bindings.assign(bindings.begin(), bindings.end());
  return ActionError::ok;
}

ActionError ActionMap::clear_bindings(std::string_view name) {
  const auto i = find(name);
  if (i == actions_.size()) return ActionError::action_not_found;
  actions_[i].bindings.clear();
  return ActionError::ok;
}

bool ActionMap::contains(std::string_view name) const noexcept {
  return find(name) != actions_.size();
}

std::span<const Binding> ActionMap::bindings(std::string_view name) const noexcept {
  const auto i = find(name);
  if (i == actions_.size()) return {};
  return actions_[i].bindings;
}

std::vector<BindingConflict> ActionMap::conflicts() const {
  std::vector<BindingConflict> out;
  for (std::size_t i = 0; i < actions_.size(); ++i) {
    for (std::size_t j = i + 1; j < actions_.size(); ++j) {
      for (const auto& a : actions_[i].bindings) {
        for (const auto& b : actions_[j].bindings) {
          if (bindings_conflict(a, b)) out.push_back({actions_[i].name, actions_[j].name, b});
        }
      }
    }
  }
  return out;
}

std::vector<std::uint8_t> ActionMap::encode() const {
  std::vector<std::uint8_t> out;
  out.reserve(8 + actions_.size() * (1 + max_name_bytes + 1 +
                                     max_bindings_per_action * binding_bytes));
  for (const char c : std::string_view("MUTA")) put8(out, static_cast<std::uint8_t>(c));
  put8(out, 1); put8(out, 0); put8(out, 0); put8(out, 0);
  put32(out, static_cast<std::uint32_t>(actions_.size()));
  for (const auto& action : actions_) {
    put8(out, static_cast<std::uint8_t>(action.name.size()));
    for (const char c : action.name) put8(out, static_cast<std::uint8_t>(c));
    put8(out, static_cast<std::uint8_t>(action.bindings.size()));
    for (const auto& binding : action.bindings) {
      put8(out, static_cast<std::uint8_t>(binding.device));
      put16(out, binding.code);
      put32(out, static_cast<std::uint32_t>(binding.threshold));
    }
  }
  return out;
}

std::variant<ActionMap, ActionError> ActionMap::decode(std::span<const std::uint8_t> bytes) {
  if (bytes.size() < 8) return ActionError::truncated;
  if (bytes[0] != 'M' || bytes[1] != 'U' || bytes[2] != 'T' || bytes[3] != 'A')
    return ActionError::invalid_format;
  if (bytes[4] != 1 || bytes[5] || bytes[6] || bytes[7]) return ActionError::unsupported_version;
  std::size_t at = 8;
  const std::uint32_t count = get32(bytes, at);
  if (count > max_actions) return ActionError::size_limit;
  ActionMap out;
  for (std::uint32_t i = 0; i < count; ++i) {
    const std::uint8_t name_len = get8(bytes, at);
    if (name_len == 0 || name_len > max_name_bytes) return ActionError::invalid_name;
    std::string name;
    name.reserve(name_len);
    for (std::uint8_t j = 0; j < name_len; ++j) {
      const std::uint8_t c = get8(bytes, at);
      if (c == 0) return ActionError::invalid_name;
      name.push_back(static_cast<char>(c));
    }
    const std::uint8_t binding_count = get8(bytes, at);
    if (binding_count > max_bindings_per_action) return ActionError::too_many_bindings;
    std::array<Binding, ActionMap::max_bindings_per_action> parsed{};
    for (std::uint8_t j = 0; j < binding_count; ++j) {
      parsed[j].device = static_cast<BindingDevice>(get8(bytes, at));
      parsed[j].code = get16(bytes, at);
      parsed[j].threshold = static_cast<std::int32_t>(get32(bytes, at));
      if (validate_binding(parsed[j]) != ActionError::ok) return ActionError::invalid_binding;
    }
    if (const auto err = out.define_action(name); err != ActionError::ok) return err;
    if (const auto err = out.set_bindings(name,
        std::span<const Binding>(parsed.data(), binding_count)); err != ActionError::ok) return err;
  }
  if (at != bytes.size()) return ActionError::trailing_bytes;
  return out;
}

namespace {
struct BindingRead { bool held{false}; std::int32_t value{0}; };

BindingRead read_digital(bool down) noexcept {
  return {down, down ? 1 : 0};
}

BindingRead read_binding(const Binding& binding, const InputState& state,
                         std::span<const InputEvent> events) noexcept {
  switch (binding.device) {
    case BindingDevice::keyboard:
      return read_digital(state.key_down(binding.code));
    case BindingDevice::mouse_button:
      return read_digital(state.button_down(binding.code));
    case BindingDevice::gamepad_button:
      return read_digital(state.gamepad_button_down(binding.code));
    case BindingDevice::touch:
      return read_digital(state.touch_down(binding.code));
    case BindingDevice::mouse_wheel: {
      std::int64_t delta = 0;
      for (const auto& event : events)
        if (event.kind == InputKind::mouse_wheel) delta += event.wheel;
      const int dir = sign_of(binding.threshold);
      if ((dir > 0 && delta > 0) || (dir < 0 && delta < 0))
        return {true, clamp_i32(dir > 0 ? delta : -delta)};
      return {};
    }
    case BindingDevice::gamepad_axis: {
      const auto axis = static_cast<std::int64_t>(state.gamepad_axis_value(binding.code));
      const auto threshold = static_cast<std::int64_t>(binding.threshold);
      if (threshold > 0 && axis >= threshold) return {true, clamp_i32(axis)};
      if (threshold < 0 && axis <= threshold) return {true, clamp_i32(-axis)};
      return {};
    }
    default:
      return {};
  }
}
}  // namespace

const ActionSample* ActionFrame::find(std::string_view name) const noexcept {
  if (map_ == nullptr) return nullptr;
  for (std::size_t i = 0; i < samples_.size(); ++i)
    if (map_->actions()[i].name == name) return &samples_[i];
  return nullptr;
}

bool ActionFrame::held(std::string_view name) const noexcept {
  const auto* sample = find(name);
  return sample != nullptr && sample->held;
}
bool ActionFrame::pressed(std::string_view name) const noexcept {
  const auto* sample = find(name);
  return sample != nullptr && sample->pressed;
}
bool ActionFrame::released(std::string_view name) const noexcept {
  const auto* sample = find(name);
  return sample != nullptr && sample->released;
}
std::int32_t ActionFrame::value(std::string_view name) const noexcept {
  const auto* sample = find(name);
  return sample != nullptr ? sample->value : 0;
}

std::uint64_t ActionFrame::hash() const noexcept {
  if (map_ == nullptr) return 0;
  std::vector<std::uint8_t> bytes;
  bytes.reserve(4 + samples_.size() * (1 + ActionMap::max_name_bytes + 6));
  put32(bytes, static_cast<std::uint32_t>(samples_.size()));
  for (std::size_t i = 0; i < samples_.size(); ++i) {
    const auto& action = map_->actions()[i];
    put8(bytes, static_cast<std::uint8_t>(action.name.size()));
    for (const char c : action.name) put8(bytes, static_cast<std::uint8_t>(c));
    const auto& sample = samples_[i];
    put8(bytes, static_cast<std::uint8_t>((sample.held ? 1 : 0) |
                                          (sample.pressed ? 2 : 0) |
                                          (sample.released ? 4 : 0)));
    put32(bytes, static_cast<std::uint32_t>(sample.value));
  }
  return xxhash64(bytes);
}

ActionFrame ActionSampler::sample(const InputState& state,
                                  std::span<const InputEvent> events) noexcept {
  const auto count = map_.action_count();
  if (previous_.size() != count) previous_.assign(count, 0);
  ActionFrame frame;
  frame.map_ = &map_;
  frame.samples_.resize(count);
  std::vector<std::uint8_t> current(count, 0);
  for (std::size_t i = 0; i < count; ++i) {
    auto& sample = frame.samples_[i];
    for (const auto& binding : map_.actions()[i].bindings) {
      const auto reading = read_binding(binding, state, events);
      if (!reading.held) continue;
      sample.held = true;
      sample.value = reading.value;
      break;  // first matching binding in declaration order wins
    }
    sample.pressed = sample.held && previous_[i] == 0;
    sample.released = !sample.held && previous_[i] != 0;
    current[i] = sample.held ? 1 : 0;
  }
  previous_.swap(current);
  return frame;
}

std::string_view name(ActionError error) noexcept {
  constexpr std::array<std::string_view, 14> names{
    "ok", "invalid_name", "duplicate_action", "too_many_actions",
    "too_many_bindings", "invalid_binding", "duplicate_binding",
    "action_not_found", "binding_not_found", "invalid_format",
    "unsupported_version", "truncated", "size_limit", "trailing_bytes"};
  const auto i = static_cast<std::size_t>(error);
  return i < names.size() ? names[i] : std::string_view{};
}

}  // namespace poko::mute

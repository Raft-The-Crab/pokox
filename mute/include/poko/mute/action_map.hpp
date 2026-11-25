#pragma once

#include "poko/mute/input_snapshot.hpp"

#include <cstddef>
#include <cstdint>
#include <span>
#include <string>
#include <string_view>
#include <variant>
#include <vector>

namespace poko::mute {

// MUT-39: named actions over the MUT-38 input timeline. A host defines stable
// action names, binds each name to one or more device sources, and samples the
// actions once per simulation tick. The sampler keeps only the previous tick's
// held bits, so pressed/released edges are deterministic under record/replay.
//
// Bindings describe sources, not native devices: the host adapter translates
// SDL/gamepad/touch events into MUT-38 InputEvents. Full device connect/disconnect
// and touch-gesture behavior remain MUT-40; this layer covers rebindable source
// selection, conflict detection, canonical persistence and named action reads.

enum class BindingDevice : std::uint8_t {
  none = 0,
  keyboard = 1,
  mouse_button = 2,
  mouse_wheel = 3,
  gamepad_button = 4,
  gamepad_axis = 5,
  touch = 6
};

struct Binding {
  BindingDevice device{BindingDevice::none};
  // key/button id; 0 for mouse wheel; gamepad/touch codes are packed
  // slot/control ids (MUT-40), with slot 0 matching legacy codes.
  std::uint16_t code{0};
  std::int32_t threshold{0};   // 0 for digital sources; signed direction/deadzone for axes
  bool operator==(const Binding&) const = default;
};

enum class ActionError : std::uint8_t {
  ok = 0,
  invalid_name,
  duplicate_action,
  too_many_actions,
  too_many_bindings,
  invalid_binding,
  duplicate_binding,
  action_not_found,
  binding_not_found,
  invalid_format,
  unsupported_version,
  truncated,
  size_limit,
  trailing_bytes
};

struct ActionDef {
  std::string name;
  std::vector<Binding> bindings;
  bool operator==(const ActionDef&) const = default;
};

struct BindingConflict {
  std::string first_action;
  std::string second_action;
  Binding binding;
  bool operator==(const BindingConflict&) const = default;
};

[[nodiscard]] ActionError validate_binding(const Binding& binding) noexcept;
[[nodiscard]] bool bindings_conflict(const Binding& a, const Binding& b) noexcept;

class ActionMap {
 public:
  static constexpr std::size_t max_actions = 64;
  static constexpr std::size_t max_name_bytes = 63;
  static constexpr std::size_t max_bindings_per_action = 8;

  [[nodiscard]] ActionError define_action(std::string_view name);
  [[nodiscard]] ActionError remove_action(std::string_view name);
  [[nodiscard]] ActionError add_binding(std::string_view name, const Binding& binding);
  [[nodiscard]] ActionError replace_binding(std::string_view name, std::size_t index,
                                            const Binding& binding);
  [[nodiscard]] ActionError set_bindings(std::string_view name, std::span<const Binding> bindings);
  [[nodiscard]] ActionError clear_bindings(std::string_view name);

  [[nodiscard]] std::size_t action_count() const noexcept { return actions_.size(); }
  [[nodiscard]] bool empty() const noexcept { return actions_.empty(); }
  [[nodiscard]] bool contains(std::string_view name) const noexcept;
  [[nodiscard]] std::span<const Binding> bindings(std::string_view name) const noexcept;
  [[nodiscard]] std::span<const ActionDef> actions() const noexcept { return actions_; }

  // Conflicts are reported in definition/binding order. They do not mutate the
  // map: a host can persist an in-progress rebind and resolve conflicts later.
  [[nodiscard]] std::vector<BindingConflict> conflicts() const;

  // Canonical binary form: "MUTA", version 1, three reserved zero bytes,
  // u32 action count, then u8 name length + name bytes + u8 binding count +
  // 7-byte bindings (u8 device, u16 code, i32 threshold). Little-endian;
  // decode rejects trailing bytes and non-canonical encodings.
  [[nodiscard]] std::vector<std::uint8_t> encode() const;
  [[nodiscard]] static std::variant<ActionMap, ActionError> decode(
      std::span<const std::uint8_t> bytes);

 private:
  [[nodiscard]] std::size_t find(std::string_view name) const noexcept;

  std::vector<ActionDef> actions_;
};

struct ActionSample {
  bool held{false};
  bool pressed{false};
  bool released{false};
  std::int32_t value{0};
  bool operator==(const ActionSample&) const = default;
};

// One tick's named action reads. The frame borrows its ActionMap for name
// lookup, so the map must outlive the frame.
class ActionFrame {
 public:
  [[nodiscard]] const ActionSample* find(std::string_view name) const noexcept;
  [[nodiscard]] bool held(std::string_view name) const noexcept;
  [[nodiscard]] bool pressed(std::string_view name) const noexcept;
  [[nodiscard]] bool released(std::string_view name) const noexcept;
  [[nodiscard]] std::int32_t value(std::string_view name) const noexcept;
  [[nodiscard]] std::size_t size() const noexcept { return samples_.size(); }

  // Canonical hash of action names and samples. Equal hashes mean the same
  // named actions produced the same held/edge/value readings for this tick.
  [[nodiscard]] std::uint64_t hash() const noexcept;

 private:
  friend class ActionSampler;
  const ActionMap* map_{nullptr};
  std::vector<ActionSample> samples_;
};

class ActionSampler {
 public:
  explicit ActionSampler(const ActionMap& map) noexcept : map_(map) {}

  // `events` are the events applied to `state` for the current tick. Call once
  // per tick, including empty ticks, so pressed/released edges stay aligned.
  [[nodiscard]] ActionFrame sample(const InputState& state,
                                   std::span<const InputEvent> events) noexcept;
  void reset() noexcept { previous_.clear(); }

 private:
  const ActionMap& map_;
  std::vector<std::uint8_t> previous_;
};

[[nodiscard]] std::string_view name(ActionError error) noexcept;

}  // namespace poko::mute

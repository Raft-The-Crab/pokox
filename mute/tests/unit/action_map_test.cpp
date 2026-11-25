// MUT-39: named actions, rebindable sources, conflicts, persistence and
// deterministic per-tick reads over the MUT-38 timeline and ENG-30 clock.
#include "poko/mute/action_map.hpp"
#include "poko/foundation/loop.hpp"

#include <array>
#include <cstdio>
#include <span>
#include <string>
#include <vector>

using namespace poko::mute;
namespace {
int failures = 0;
#define CHECK(cond) do { if (!(cond)) { \
  std::fprintf(stderr, "FAIL line %d: %s\n", __LINE__, #cond); ++failures; \
} } while (0)

InputEvent key(std::uint16_t code, bool down) {
  InputEvent e; e.kind = InputKind::key; e.code = code; e.pressed = down; return e;
}
InputEvent mouse_button(std::uint16_t code, bool down) {
  InputEvent e; e.kind = InputKind::mouse_button; e.code = code; e.pressed = down; return e;
}
InputEvent wheel(std::int32_t n) {
  InputEvent e; e.kind = InputKind::mouse_wheel; e.wheel = n; return e;
}
InputEvent pad_button(std::uint16_t code, bool down) {
  InputEvent e; e.kind = InputKind::gamepad_button; e.code = code; e.pressed = down; return e;
}
InputEvent pad_axis(std::uint16_t code, std::int32_t value) {
  InputEvent e; e.kind = InputKind::gamepad_axis; e.code = code; e.dx = value; return e;
}
InputEvent touch(std::uint16_t id, bool down, std::int32_t x = 0, std::int32_t y = 0) {
  InputEvent e; e.kind = InputKind::touch_tap; e.code = id; e.pressed = down;
  e.dx = x; e.dy = y; e.width = 1280; e.height = 720; return e;
}
Binding kb(std::uint16_t code) { return {BindingDevice::keyboard, code, 0}; }
Binding mouse(std::uint16_t code) { return {BindingDevice::mouse_button, code, 0}; }
Binding wheel_up() { return {BindingDevice::mouse_wheel, 0, 1}; }
Binding pad(std::uint16_t code) { return {BindingDevice::gamepad_button, code, 0}; }
Binding axis(std::int32_t threshold, std::uint16_t code = 0) {
  return {BindingDevice::gamepad_axis, code, threshold};
}
Binding tap(std::uint16_t id) { return {BindingDevice::touch, id, 0}; }

void apply_events(InputState& state, std::span<const InputEvent> events) {
  for (const auto& e : events) state.apply(e);
}

ActionMap game_map() {
  ActionMap map;
  CHECK(map.define_action("jump") == ActionError::ok);
  CHECK(map.define_action("left") == ActionError::ok);
  CHECK(map.define_action("right") == ActionError::ok);
  CHECK(map.define_action("confirm") == ActionError::ok);
  CHECK(map.define_action("wheel_up") == ActionError::ok);
  CHECK(map.add_binding("jump", kb(65)) == ActionError::ok);
  CHECK(map.add_binding("jump", pad(0)) == ActionError::ok);
  CHECK(map.add_binding("left", axis(-20000)) == ActionError::ok);
  CHECK(map.add_binding("right", axis(20000)) == ActionError::ok);
  CHECK(map.add_binding("confirm", mouse(1)) == ActionError::ok);
  CHECK(map.add_binding("confirm", tap(0)) == ActionError::ok);
  CHECK(map.add_binding("wheel_up", wheel_up()) == ActionError::ok);
  return map;
}
}  // namespace

int main() {
  {  // binding validation and conflict policy
    CHECK(validate_binding(kb(65)) == ActionError::ok);
    CHECK(validate_binding(mouse(63)) == ActionError::ok);
    CHECK(validate_binding(pad(63)) == ActionError::ok);
    CHECK(validate_binding(axis(1, 7)) == ActionError::ok);
    CHECK(validate_binding(tap(15)) == ActionError::ok);
    CHECK(validate_binding(Binding{}) == ActionError::invalid_binding);
    CHECK(validate_binding({BindingDevice::keyboard, 256, 0}) == ActionError::invalid_binding);
    CHECK(validate_binding({BindingDevice::mouse_button, 64, 0}) == ActionError::invalid_binding);
    CHECK(validate_binding({BindingDevice::mouse_wheel, 0, 0}) == ActionError::invalid_binding);
    CHECK(validate_binding({BindingDevice::gamepad_axis, InputState::max_gamepad_axes, 1}) ==
          ActionError::invalid_binding);
    CHECK(validate_binding({BindingDevice::touch, InputState::max_touches, 0}) ==
          ActionError::invalid_binding);
    CHECK(bindings_conflict(kb(65), kb(65)));
    CHECK(!bindings_conflict(kb(65), kb(66)));
    CHECK(bindings_conflict(pad(2), pad(2)));
    CHECK(bindings_conflict(axis(20000), axis(10000)));  // overlapping positive window
    CHECK(!bindings_conflict(axis(20000), axis(-10000)));
    CHECK(bindings_conflict(tap(2), tap(2)));
    CHECK(!bindings_conflict(mouse(1), pad(1)));
    CHECK(!bindings_conflict(Binding{}, Binding{}));  // invalid sources never conflict
  }
  {  // named actions, rebinding and conflict reporting
    ActionMap map;
    CHECK(map.define_action("jump") == ActionError::ok);
    CHECK(map.define_action("") == ActionError::invalid_name);
    CHECK(map.define_action("jump") == ActionError::duplicate_action);
    CHECK(map.define_action(std::string(ActionMap::max_name_bytes + 1, 'x')) ==
          ActionError::invalid_name);
    CHECK(map.add_binding("jump", kb(65)) == ActionError::ok);
    CHECK(map.add_binding("jump", kb(65)) == ActionError::duplicate_binding);
    CHECK(map.add_binding("jump", pad(0)) == ActionError::ok);
    CHECK(map.replace_binding("jump", 1, kb(66)) == ActionError::ok);
    CHECK(map.bindings("jump").size() == 2 && map.bindings("jump")[1] == kb(66));
    CHECK(map.replace_binding("jump", 1, kb(65)) == ActionError::duplicate_binding);
    CHECK(map.replace_binding("jump", 9, kb(67)) == ActionError::binding_not_found);
    CHECK(map.add_binding("missing", kb(1)) == ActionError::action_not_found);
    CHECK(map.define_action("confirm") == ActionError::ok);
    CHECK(map.add_binding("confirm", kb(65)) == ActionError::ok);
    const auto conflicts = map.conflicts();
    CHECK(conflicts.size() == 1);
    if (!conflicts.empty())
      CHECK(conflicts[0].first_action == "jump" && conflicts[0].second_action == "confirm" &&
            conflicts[0].binding == kb(65));
    const std::array<Binding, 1> remap{kb(68)};
    CHECK(map.set_bindings("jump", remap) == ActionError::ok);
    CHECK(map.conflicts().empty());
    CHECK(map.clear_bindings("jump") == ActionError::ok && map.bindings("jump").empty());
    CHECK(map.remove_action("jump") == ActionError::ok);
    CHECK(!map.contains("jump") && map.bindings("jump").empty());
    CHECK(map.remove_action("jump") == ActionError::action_not_found);
    CHECK(name(ActionError::duplicate_binding) == "duplicate_binding");
  }
  {  // canonical persistence and strict corruption rejection
    const auto map = game_map();
    const auto bytes = map.encode();
    auto decoded = ActionMap::decode(bytes);
    auto* restored = std::get_if<ActionMap>(&decoded);
    CHECK(restored != nullptr);
    if (restored) {
      CHECK(restored->action_count() == map.action_count());
      bool same = true;
      for (std::size_t i = 0; i < map.action_count(); ++i) {
        same = same && restored->actions()[i] == map.actions()[i];
      }
      CHECK(same);
      CHECK(restored->encode() == bytes);
      CHECK(restored->conflicts().empty());
    }
    CHECK(std::holds_alternative<ActionError>(ActionMap::decode({})));
    auto bad_magic = bytes; bad_magic[0] = 'X';
    CHECK(std::get<ActionError>(ActionMap::decode(bad_magic)) == ActionError::invalid_format);
    auto bad_version = bytes; bad_version[4] = 2;
    CHECK(std::get<ActionError>(ActionMap::decode(bad_version)) == ActionError::unsupported_version);
    auto truncated = bytes; truncated.pop_back();
    CHECK(std::get<ActionError>(ActionMap::decode(truncated)) == ActionError::invalid_binding);
    auto trailing = bytes; trailing.push_back(0);
    CHECK(std::get<ActionError>(ActionMap::decode(trailing)) == ActionError::trailing_bytes);
    auto bad_name = bytes; bad_name[12] = 0;  // first action name length
    CHECK(std::get<ActionError>(ActionMap::decode(bad_name)) == ActionError::invalid_name);
    auto bad_binding = bytes; bad_binding[18] = 99;  // first binding device
    CHECK(std::get<ActionError>(ActionMap::decode(bad_binding)) == ActionError::invalid_binding);
  }
  {  // per-tick held/pressed/released reads, edges and analog values
    const auto map = game_map();
    InputState state;
    ActionSampler sampler(map);
    const std::vector<InputEvent> first{key(65, true), mouse_button(1, true), touch(0, true, 10, 20)};
    apply_events(state, first);
    auto frame = sampler.sample(state, first);
    CHECK(frame.size() == 5);
    CHECK(frame.held("jump") && frame.pressed("jump") && frame.value("jump") == 1);
    CHECK(frame.held("confirm") && frame.pressed("confirm"));
    CHECK(!frame.held("left") && !frame.held("right"));
    CHECK(!frame.held("wheel_up") && !frame.pressed("wheel_up"));
    CHECK(frame.find("missing") == nullptr && !frame.held("missing") && frame.value("missing") == 0);
    const auto first_hash = frame.hash();

    frame = sampler.sample(state, {});
    CHECK(frame.held("jump") && !frame.pressed("jump") && !frame.released("jump"));
    CHECK(frame.held("confirm") && !frame.pressed("confirm"));
    CHECK(frame.hash() != first_hash);  // pressed edge is part of the frame hash

    const std::vector<InputEvent> release{key(65, false), mouse_button(1, false), touch(0, false, 11, 21)};
    apply_events(state, release);
    frame = sampler.sample(state, release);
    CHECK(!frame.held("jump") && frame.released("jump"));
    CHECK(!frame.held("confirm") && frame.released("confirm"));
    CHECK(!frame.pressed("jump") && !frame.pressed("confirm"));

    const std::vector<InputEvent> negative{pad_button(0, true), pad_axis(0, -30000), wheel(-1)};
    apply_events(state, negative);
    frame = sampler.sample(state, negative);
    CHECK(frame.held("jump") && frame.pressed("jump") && frame.value("jump") == 1);
    CHECK(frame.held("left") && frame.pressed("left") && frame.value("left") == 30000);
    CHECK(!frame.held("right") && !frame.held("wheel_up"));

    frame = sampler.sample(state, {});
    CHECK(frame.held("jump") && !frame.pressed("jump"));
    CHECK(frame.held("left") && !frame.pressed("left") && frame.value("left") == 30000);

    const std::vector<InputEvent> positive{pad_axis(0, 30000), wheel(2)};
    apply_events(state, positive);
    frame = sampler.sample(state, positive);
    CHECK(frame.released("left") && !frame.held("left"));
    CHECK(frame.held("right") && frame.pressed("right") && frame.value("right") == 30000);
    CHECK(frame.held("wheel_up") && frame.pressed("wheel_up") && frame.value("wheel_up") == 2);

    const std::vector<InputEvent> wheel_down{wheel(-1)};
    apply_events(state, wheel_down);
    frame = sampler.sample(state, wheel_down);
    CHECK(!frame.held("wheel_up") && frame.released("wheel_up"));
    CHECK(frame.held("right") && !frame.pressed("right"));

    ActionMap remapped;
    CHECK(remapped.define_action("jump") == ActionError::ok);
    CHECK(remapped.add_binding("jump", kb(66)) == ActionError::ok);
    ActionSampler remapped_sampler(remapped);
    InputState fresh;
    const std::vector<InputEvent> old_key{key(65, true)};
    apply_events(fresh, old_key);
    const auto changed = remapped_sampler.sample(fresh, old_key);
    CHECK(!changed.held("jump"));
    CHECK(remapped.replace_binding("jump", 0, kb(65)) == ActionError::ok);
    ActionSampler rebound_sampler(remapped);
    CHECK(rebound_sampler.sample(fresh, old_key).held("jump"));
  }
  {  // record/replay: decoded bindings produce identical action hashes per tick
    using poko::loop::FixedStepLoop;
    const auto map = game_map();
    const auto encoded = map.encode();
    auto decoded = ActionMap::decode(encoded);
    auto* restored = std::get_if<ActionMap>(&decoded);
    CHECK(restored != nullptr);
    if (restored == nullptr) return 1;

    InputTimeline timeline;
    InputState live;
    ActionSampler live_sampler(map);
    std::vector<std::uint64_t> live_hashes;
    FixedStepLoop clock;
    std::uint64_t tick = 0;
    const std::array<double, 12> deltas{0.02, 0.03, 0.05, 0.016, 0.034, 0.05,
                                         5.0,  0.05, 0.01, 0.04,  0.05, 0.05};
    for (const double dt : deltas) {
      const auto steps = clock.advance(dt);
      for (std::uint32_t s = 0; s < steps; ++s) {
        ++tick;
        std::vector<InputEvent> events;
        if (tick == 1) events.push_back(key(65, true));
        if (tick == 2) events.push_back(pad_axis(0, 25000));
        if (tick == 3) events.push_back(wheel(1));
        if (tick == 4) events.push_back(touch(0, true, 10, 20));
        if (tick == 5) events.push_back(InputEvent{InputKind::focus_lost});
        if (tick == 7) events.push_back(InputEvent{InputKind::focus_gained});
        if (tick == 8) events.push_back(key(65, true));
        if (tick == 9) events.push_back(mouse_button(1, true));
        if (tick == 10) events.push_back(key(65, false));
        for (const auto& e : events) CHECK(timeline.append(tick, e));
        apply_events(live, events);
        live_hashes.push_back(live_sampler.sample(live, events).hash());
      }
    }
    CHECK(live_hashes.size() == 13);

    FixedStepLoop replay_clock;
    InputState replayed;
    ActionSampler replay_sampler(*restored);
    InputReplay replay(timeline);
    tick = 0;
    std::size_t index = 0;
    for (const double dt : deltas) {
      const auto steps = replay_clock.advance(dt);
      for (std::uint32_t s = 0; s < steps; ++s) {
        ++tick;
        std::span<const InputEvent> events;
        if (!timeline.at(tick).empty()) {
          std::uint64_t replay_tick = 0;
          CHECK(replay.next(replay_tick, events));
          CHECK(replay_tick == tick);
          apply_events(replayed, events);
        }
        CHECK(replay_sampler.sample(replayed, events).hash() == live_hashes[index++]);
      }
    }
    CHECK(index == live_hashes.size() && replay.done());
    CHECK(replayed.hash() == live.hash());
  }

  if (failures) { std::fprintf(stderr, "%d action map check(s) failed\n", failures); return 1; }
  std::puts("PASS: named actions, rebinding, conflicts, persistence and per-tick replay");
  return 0;
}

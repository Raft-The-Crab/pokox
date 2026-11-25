// MUT-40: stable device slots, connect/disconnect, slot-specific gamepad and
// touch state, action bindings by slot, and deterministic replay.
#include "poko/mute/device_router.hpp"
#include "poko/mute/action_map.hpp"

#include <array>
#include <cstdio>
#include <span>
#include <vector>

using namespace poko::mute;
namespace {
int failures = 0;
#define CHECK(cond) do { if (!(cond)) { \
  std::fprintf(stderr, "FAIL line %d: %s\n", __LINE__, #cond); ++failures; \
} } while (0)

InputEvent event(InputKind kind, std::uint16_t code) {
  InputEvent e; e.kind = kind; e.code = code; return e;
}
InputEvent connect(DeviceKind kind, std::uint8_t slot) {
  return event(InputKind::device_connected, pack_device_code(kind, slot));
}
InputEvent disconnect(DeviceKind kind, std::uint8_t slot) {
  return event(InputKind::device_disconnected, pack_device_code(kind, slot));
}
InputEvent pad_button(std::uint8_t slot, std::uint8_t button, bool down) {
  InputEvent e = event(InputKind::gamepad_button, pack_gamepad_code(slot, button));
  e.pressed = down; return e;
}
InputEvent pad_axis(std::uint8_t slot, std::uint8_t axis, std::int32_t value) {
  InputEvent e = event(InputKind::gamepad_axis, pack_gamepad_code(slot, axis));
  e.dx = value; return e;
}
InputEvent touch_tap(std::uint8_t display, std::uint8_t id, bool down,
                     std::int32_t x = 0, std::int32_t y = 0) {
  InputEvent e = event(InputKind::touch_tap, pack_gamepad_code(display, id));
  e.pressed = down; e.dx = x; e.dy = y; e.width = 1280; e.height = 720; return e;
}
void apply_events(InputState& state, std::span<const InputEvent> events) {
  for (const auto& e : events) state.apply(e);
}
std::pair<std::int32_t,std::int32_t> pos(std::int32_t x, std::int32_t y) { return {x, y}; }
std::vector<std::uint64_t> run_timeline(const InputTimeline& timeline, InputState& state) {
  std::vector<std::uint64_t> hashes;
  for (std::uint64_t tick = 1; tick <= 20; ++tick) {
    for (const auto& e : timeline.at(tick)) state.apply(e);
    hashes.push_back(timeline.snapshot_hash(tick, state));
  }
  return hashes;
}
}  // namespace

int main() {
  {  // packed codes are stable and backwards compatible for slot 0
    CHECK(pack_device_code(DeviceKind::gamepad, 3) == 0x0303);
    CHECK(unpack_device_code(0x0303) == (DeviceId{DeviceKind::gamepad, 3}));
    CHECK(pack_gamepad_code(2, 65) == 0x0241);
    CHECK(gamepad_slot(0x0241) == 2 && gamepad_control(0x0241) == 65);
    CHECK(touch_display(pack_gamepad_code(1, 4)) == 1);
    CHECK(touch_id(pack_gamepad_code(1, 4)) == 4);
    CHECK(validate_binding({BindingDevice::gamepad_button, pack_gamepad_code(0, 0), 0}) ==
          ActionError::ok);
    CHECK(validate_binding({BindingDevice::gamepad_axis, pack_gamepad_code(15, 7), 100}) ==
          ActionError::ok);
    CHECK(validate_binding({BindingDevice::touch, pack_gamepad_code(15, 15), 0}) ==
          ActionError::ok);
    CHECK(validate_binding({BindingDevice::gamepad_button, pack_gamepad_code(16, 0), 0}) ==
          ActionError::invalid_binding);
  }
  {
    InputState s;
    CHECK(s.gamepad_connected(0) && !s.gamepad_connected(1));
    CHECK(s.touch_display_connected(0) && !s.touch_display_connected(1));
    s.apply(pad_button(0, 5, true));
    CHECK(s.gamepad_button_down(0, 5) && s.gamepad_button_down(pack_gamepad_code(0, 5)));
    s.apply(pad_button(1, 0, true));  // ignored while disconnected
    CHECK(!s.gamepad_button_down(1, 0));
    s.apply(connect(DeviceKind::gamepad, 1));
    s.apply(pad_button(1, 0, true));
    s.apply(pad_axis(1, 3, -12345));
    CHECK(s.gamepad_connected(1) && s.gamepad_button_down(1, 0));
    CHECK(s.gamepad_axis_value(1, 3) == -12345);
    s.apply(touch_tap(1, 2, true, 44, 55));  // ignored while display disconnected
    CHECK(!s.touch_down(1, 2));
    s.apply(connect(DeviceKind::touch, 1));
    s.apply(touch_tap(1, 2, true, 44, 55));
    CHECK(s.touch_display_connected(1) && s.touch_down(1, 2));
    CHECK(s.touch_position(1, 2) == pos(44, 55));
    const auto connected_hash = s.hash();
    s.apply(disconnect(DeviceKind::gamepad, 1));
    s.apply(disconnect(DeviceKind::touch, 1));
    CHECK(!s.gamepad_connected(1) && !s.gamepad_button_down(1, 0));
    CHECK(s.gamepad_button_down(0, 5));  // slot 0 is untouched
    CHECK(!s.touch_display_connected(1) && !s.touch_down(1, 2));
    CHECK(s.touch_position(1, 2) == pos(0, 0));
    CHECK(s.hash() != connected_hash);
    s.apply(InputEvent{InputKind::focus_lost});
    CHECK(s.connected_gamepads == 1 && s.connected_touch_displays == 1);
    CHECK(!s.gamepad_button_down(0, 5) && !s.touch_down(0, 0));
  }
  {  // router allocates the lowest free slot and records deterministic events
    InputTimeline timeline;
    DeviceRouter router;
    DeviceId a{}, b{}, display{};
    CHECK(router.connect(DeviceKind::gamepad, 1000, 1, timeline, &a) == DeviceRouterError::ok);
    CHECK(a == (DeviceId{DeviceKind::gamepad, 0}));
    CHECK(router.connect(DeviceKind::gamepad, 2000, 2, timeline, &b) == DeviceRouterError::ok);
    CHECK(b == (DeviceId{DeviceKind::gamepad, 1}));
    CHECK(router.connect(DeviceKind::gamepad, 1000, 3, timeline) == DeviceRouterError::ok);
    CHECK(timeline.size() == 2);  // duplicate native id emits no event
    CHECK(router.connect(DeviceKind::touch, 3000, 4, timeline, &display) == DeviceRouterError::ok);
    CHECK(display == (DeviceId{DeviceKind::touch, 0}));
    CHECK(router.connect(DeviceKind::keyboard, 4000, 5, timeline) ==
          DeviceRouterError::unsupported_kind);
    CHECK(router.route_count() == 3 && router.routes().size() == 3);
    const auto routes = router.routes();
    CHECK(routes[0].id == (DeviceId{DeviceKind::gamepad, 0}));
    CHECK(routes[1].id == (DeviceId{DeviceKind::gamepad, 1}));
    CHECK(routes[2].id == (DeviceId{DeviceKind::touch, 0}));
    DeviceId removed{};
    CHECK(router.disconnect(2000, 6, timeline, &removed) == DeviceRouterError::ok);
    CHECK(removed == (DeviceId{DeviceKind::gamepad, 1}));
    CHECK(router.disconnect(9999, 7, timeline) == DeviceRouterError::unknown_native);
    DeviceId reused{};
    CHECK(router.connect(DeviceKind::gamepad, 5000, 8, timeline, &reused) == DeviceRouterError::ok);
    CHECK(reused.slot == 1);
    CHECK(name(DeviceRouterError::table_full) == "table_full");
    router.clear();
    CHECK(router.route_count() == 0);
  }
  {  // same control on different slots does not conflict; same slot does
    const Binding slot0{BindingDevice::gamepad_button, pack_gamepad_code(0, 0), 0};
    const Binding slot1{BindingDevice::gamepad_button, pack_gamepad_code(1, 0), 0};
    CHECK(!bindings_conflict(slot0, slot1));
    CHECK(bindings_conflict(slot1, slot1));
    CHECK(!bindings_conflict({BindingDevice::touch, pack_gamepad_code(0, 1), 0},
                             {BindingDevice::touch, pack_gamepad_code(1, 1), 0}));
  }
  {  // named actions read the bound slot only
    ActionMap map;
    CHECK(map.define_action("jump") == ActionError::ok);
    CHECK(map.define_action("look") == ActionError::ok);
    CHECK(map.define_action("tap") == ActionError::ok);
    CHECK(map.add_binding("jump", {BindingDevice::gamepad_button, pack_gamepad_code(1, 0), 0}) ==
          ActionError::ok);
    CHECK(map.add_binding("look", {BindingDevice::gamepad_axis, pack_gamepad_code(1, 0), -20000}) ==
          ActionError::ok);
    CHECK(map.add_binding("tap", {BindingDevice::touch, pack_gamepad_code(1, 2), 0}) ==
          ActionError::ok);
    InputState state;
    ActionSampler sampler(map);
    const std::vector<InputEvent> first{connect(DeviceKind::gamepad, 1),
                                         connect(DeviceKind::touch, 1)};
    apply_events(state, first);
    auto frame = sampler.sample(state, first);
    CHECK(!frame.held("jump") && !frame.held("look") && !frame.held("tap"));
    const std::vector<InputEvent> second{pad_button(0, 0, true), pad_button(1, 0, true),
                                          pad_axis(1, 0, -25000), touch_tap(1, 2, true, 10, 20)};
    apply_events(state, second);
    frame = sampler.sample(state, second);
    CHECK(frame.held("jump") && frame.pressed("jump") && frame.value("jump") == 1);
    CHECK(frame.held("look") && frame.value("look") == 25000);
    CHECK(frame.held("tap") && frame.pressed("tap"));
    const std::vector<InputEvent> third{disconnect(DeviceKind::gamepad, 1),
                                         disconnect(DeviceKind::touch, 1)};
    apply_events(state, third);
    frame = sampler.sample(state, third);
    CHECK(!frame.held("jump") && frame.released("jump"));
    CHECK(!frame.held("look") && frame.released("look"));
    CHECK(!frame.held("tap") && frame.released("tap"));
  }
  {  // connect/disconnect and slot events replay byte-for-byte
    InputTimeline timeline;
    DeviceRouter router;
    DeviceId pad{}, display{};
    std::vector<std::uint64_t> live_hashes;
    InputState live;
    for (std::uint64_t tick = 1; tick <= 20; ++tick) {
      if (tick == 1) {
        CHECK(router.connect(DeviceKind::gamepad, 7000, tick, timeline, &pad) == DeviceRouterError::ok);
        CHECK(timeline.append(tick, pad_button(0, 4, true)));
      }
      if (tick == 2) CHECK(router.connect(DeviceKind::gamepad, 8000, tick, timeline) == DeviceRouterError::ok);
      if (tick == 3) CHECK(timeline.append(tick, pad_button(1, 0, true)));
      if (tick == 4) CHECK(timeline.append(tick, pad_axis(1, 1, 30000)));
      if (tick == 5) {
        CHECK(router.connect(DeviceKind::touch, 9000, tick, timeline, &display) == DeviceRouterError::ok);
        CHECK(timeline.append(tick, touch_tap(0, 0, true, 1, 2)));
      }
      if (tick == 6) CHECK(router.disconnect(8000, tick, timeline) == DeviceRouterError::ok);
      if (tick == 7) CHECK(router.disconnect(9000, tick, timeline) == DeviceRouterError::ok);
      apply_events(live, timeline.at(tick));
      live_hashes.push_back(timeline.snapshot_hash(tick, live));
    }
    const auto bytes = timeline.encode();
    auto decoded = InputTimeline::decode(bytes);
    auto* restored = std::get_if<InputTimeline>(&decoded);
    CHECK(restored != nullptr);
    if (restored) {
      CHECK(restored->encode() == bytes);
      InputState replayed;
      const auto replay_hashes = run_timeline(*restored, replayed);
      CHECK(replay_hashes.size() == live_hashes.size());
      for (std::size_t i = 0; i < live_hashes.size(); ++i)
        CHECK(replay_hashes[i] == live_hashes[i]);
      CHECK(replayed.hash() == live.hash());
      CHECK(!replayed.gamepad_connected(1) && !replayed.touch_display_connected(0));
    }
  }

  if (failures) { std::fprintf(stderr, "%d device router check(s) failed\n", failures); return 1; }
  std::puts("PASS: device slots, connect/disconnect, touch/gamepad behavior, replay");
  return 0;
}

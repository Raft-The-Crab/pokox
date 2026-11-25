// MUT-38: deterministic input snapshots — tick-tagged recording, replay,
// focus-loss handling, event ordering, canonical encoding, ENG-30 clock.
#include "poko/mute/input_snapshot.hpp"
#include "poko/foundation/loop.hpp"

#include <array>
#include <cstdio>
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
InputEvent button(std::uint16_t code, bool down) {
  InputEvent e; e.kind = InputKind::mouse_button; e.code = code; e.pressed = down; return e;
}
InputEvent motion(std::int32_t dx, std::int32_t dy) {
  InputEvent e; e.kind = InputKind::mouse_motion; e.dx = dx; e.dy = dy; return e;
}
InputEvent wheel(std::int32_t n) {
  InputEvent e; e.kind = InputKind::mouse_wheel; e.wheel = n; return e;
}
InputEvent gamepad_button(std::uint16_t code, bool down) {
  InputEvent e; e.kind = InputKind::gamepad_button; e.code = code; e.pressed = down; return e;
}
InputEvent gamepad_axis(std::uint16_t code, std::int32_t value) {
  InputEvent e; e.kind = InputKind::gamepad_axis; e.code = code; e.dx = value; return e;
}
InputEvent touch(std::uint16_t id, bool down, std::int32_t x, std::int32_t y) {
  InputEvent e; e.kind = InputKind::touch_tap; e.code = id; e.pressed = down;
  e.dx = x; e.dy = y; e.width = 1280; e.height = 720; return e;
}
InputEvent simple(InputKind k) { InputEvent e; e.kind = k; return e; }
std::pair<std::int32_t,std::int32_t> pos(std::int32_t x, std::int32_t y) { return {x, y}; }

// Record a small scripted tick stream and return the per-tick snapshot hashes.
std::vector<std::uint64_t> record_hashes(InputTimeline& timeline, InputState& state) {
  std::vector<std::uint64_t> hashes;
  for (std::uint64_t tick = 1; tick <= 10; ++tick) {
    switch (tick) {
      case 1: CHECK(timeline.append(tick, key(65, true))); break;
      case 2: CHECK(timeline.append(tick, motion(3, -2))); CHECK(timeline.append(tick, key(66, true))); break;
      case 3: CHECK(timeline.append(tick, button(1, true))); CHECK(timeline.append(tick, wheel(2))); break;
      case 4: CHECK(timeline.append(tick, simple(InputKind::focus_lost))); break;
      case 5: CHECK(timeline.append(tick, key(65, false))); CHECK(timeline.append(tick, motion(99, 99))); break;
      case 6: CHECK(timeline.append(tick, simple(InputKind::focus_gained))); break;
      case 7: CHECK(timeline.append(tick, key(67, true))); break;
      default: break;
    }
    for (const auto& e : timeline.at(tick)) state.apply(e);
    hashes.push_back(timeline.snapshot_hash(tick, state));
  }
  return hashes;
}
}  // namespace

int main() {
  {  // input state: held tracking, focus loss clears and suspends
    InputState s;
    CHECK(s.focused && s.hash() != 0);
    s.apply(key(65, true));
    s.apply(key(255, true));
    s.apply(button(1, true));
    s.apply(motion(4, -2));
    s.apply(wheel(3));
    CHECK(s.key_down(65) && s.key_down(255) && !s.key_down(64));
    CHECK(s.button_down(1) && !s.button_down(2));
    CHECK(s.motion_x == 4 && s.motion_y == -2 && s.wheel_total == 3);
    s.apply(key(65, false));
    CHECK(!s.key_down(65) && s.key_down(255));
    const auto before_focus = s.hash();
    s.apply(simple(InputKind::focus_lost));
    CHECK(!s.focused && !s.key_down(255) && !s.button_down(1));
    CHECK(s.hash() != before_focus);
    // Inputs arriving while unfocused are ignored, including motion.
    s.apply(key(70, true));
    s.apply(motion(500, 500));
    CHECK(!s.key_down(70) && s.motion_x == 4 && s.motion_y == -2);
    s.apply(simple(InputKind::focus_gained));
    CHECK(s.focused);
    s.apply(key(70, true));
    CHECK(s.key_down(70));
    CHECK(s.key_down(70) && s.hash() != 0);
    CHECK(s.hash() == InputState{s}.hash());  // copy is identical
  }
  {  // gamepad and touch sources share the deterministic state/hash contract
    InputState s;
    s.apply(gamepad_button(0, true));
    s.apply(gamepad_button(63, true));
    s.apply(gamepad_axis(0, 20000));
    s.apply(gamepad_axis(7, -30000));
    s.apply(touch(3, true, 120, 240));
    CHECK(s.gamepad_button_down(0) && s.gamepad_button_down(63) && !s.gamepad_button_down(1));
    CHECK(s.gamepad_axis_value(0) == 20000 && s.gamepad_axis_value(7) == -30000);
    CHECK(s.gamepad_axis_value(8) == 0);
    CHECK(s.touch_down(3) && !s.touch_down(4));
    CHECK(s.touch_position(3) == pos(120, 240));
    CHECK(s.touch_width[0] == 1280 && s.touch_height[0] == 720);
    const auto before = s.hash();
    s.apply(gamepad_button(0, false));
    s.apply(gamepad_axis(0, 0));
    s.apply(touch(3, false, 130, 250));
    CHECK(!s.gamepad_button_down(0) && s.gamepad_axis_value(0) == 0 && !s.touch_down(3));
    CHECK(s.touch_position(3) == pos(130, 250));
    CHECK(s.hash() != before);
    s.apply(simple(InputKind::focus_lost));
    CHECK(!s.gamepad_button_down(63) && s.gamepad_axis_value(7) == 0);
    CHECK(!s.touch_down(4) && s.touch_position(3) == pos(0, 0));
    CHECK(s.touch_width[0] == 0 && s.touch_height[0] == 0);
    s.apply(gamepad_button(1, true));  // ignored while unfocused
    s.apply(gamepad_axis(1, 999));
    s.apply(touch(1, true, 1, 1));
    CHECK(!s.gamepad_button_down(1) && s.gamepad_axis_value(1) == 0 && !s.touch_down(1));
  }
  {  // timeline: tick grouping, monotonicity, bound, strict event validation
    InputTimeline t;
    CHECK(t.append(1, key(65, true)));
    CHECK(t.append(1, motion(2, 0)));
    CHECK(t.append(2, wheel(-1)));
    CHECK(!t.append(1, key(66, true)));  // tick went backwards
    CHECK(!t.append(3, InputEvent{}));   // none is not recordable
    CHECK(!t.append(3, key(256, true))); // key code out of range
    CHECK(!t.append(3, button(64, true)));
    CHECK(!t.append(3, gamepad_button(64, true)));
    CHECK(!t.append(3, gamepad_axis(InputState::max_gamepad_axes, 1)));
    CHECK(!t.append(3, touch(InputState::max_touches, true, 0, 0)));
    CHECK(!t.append(3, simple(static_cast<InputKind>(99))));
    CHECK(t.size() == 3);
    CHECK(t.at(1).size() == 2 && t.at(1)[0].kind == InputKind::key);
    CHECK(t.at(2).size() == 1 && t.at(3).empty());
    CHECK(t.record(2).tick == 2);
    InputTimeline big;
    for (std::size_t i = 0; i < InputTimeline::max_events; ++i)
      CHECK(big.append(i / 4, key(static_cast<std::uint16_t>(i % 256), true)));
    CHECK(!big.append(InputTimeline::max_events, key(1, true)));
  }
  {  // encode/decode: canonical roundtrip and strict corruption rejection
    InputTimeline t;
    InputState s;
    const auto hashes = record_hashes(t, s);
    const auto bytes = t.encode();
    CHECK(bytes.size() == 12 + t.size() * 32);
    auto decoded = InputTimeline::decode(bytes);
    auto* restored = std::get_if<InputTimeline>(&decoded);
    CHECK(restored != nullptr);
    if (restored) {
      CHECK(restored->size() == t.size());
      bool same = true;
      for (std::size_t i = 0; i < t.size(); ++i) {
        const auto a = t.record(i), b = restored->record(i);
        same = same && a.tick == b.tick && a.event == b.event;
      }
      CHECK(same);
      CHECK(restored->encode() == bytes);  // canonical form is stable
      InputState replay_state;
      for (std::uint64_t tick = 1; tick <= 10; ++tick)
        for (const auto& e : restored->at(tick)) replay_state.apply(e);
      CHECK(replay_state.hash() == s.hash());
    }
    CHECK(std::holds_alternative<InputError>(InputTimeline::decode({})));
    auto bad_magic = bytes; bad_magic[0] = 'X';
    CHECK(std::get<InputError>(InputTimeline::decode(bad_magic)) == InputError::invalid_format);
    auto bad_version = bytes; bad_version[4] = 2;
    CHECK(std::get<InputError>(InputTimeline::decode(bad_version)) == InputError::unsupported_version);
    auto truncated = bytes; truncated.pop_back();
    CHECK(std::get<InputError>(InputTimeline::decode(truncated)) != InputError::invalid_format);
    auto trailing = bytes; trailing.push_back(0);
    CHECK(std::get<InputError>(InputTimeline::decode(trailing)) == InputError::trailing_bytes);
    auto bad_kind = bytes; bad_kind[12 + 8] = static_cast<std::uint8_t>(InputKind::none);
    CHECK(std::get<InputError>(InputTimeline::decode(bad_kind)) == InputError::invalid_event);
    // Non-monotonic ticks: rewrite the second record's tick to 0.
    auto backward = bytes; backward[12 + 32] = 0;  // second record tick -> 0
    CHECK(std::get<InputError>(InputTimeline::decode(backward)) == InputError::non_monotonic_tick);
    (void)hashes;
  }
  {  // MUTI v1 keeps 32-byte records for the new gamepad/touch source kinds
    InputTimeline t;
    CHECK(t.append(1, gamepad_button(0, true)));
    CHECK(t.append(2, gamepad_axis(0, -12345)));
    CHECK(t.append(3, touch(2, true, 44, 55)));
    const auto bytes = t.encode();
    CHECK(bytes.size() == 12 + 3 * 32);
    auto decoded = InputTimeline::decode(bytes);
    auto* restored = std::get_if<InputTimeline>(&decoded);
    CHECK(restored != nullptr);
    if (restored) {
      CHECK(restored->encode() == bytes);
      InputState a, b;
      for (std::uint64_t tick = 1; tick <= 3; ++tick) {
        for (const auto& e : t.at(tick)) a.apply(e);
        for (const auto& e : restored->at(tick)) b.apply(e);
        CHECK(t.snapshot_hash(tick, a) == restored->snapshot_hash(tick, b));
      }
      CHECK(a.hash() == b.hash());
      CHECK(a.gamepad_axis_value(0) == -12345 && a.touch_position(2) == pos(44, 55));
    }
    auto bad_axis = bytes; bad_axis[12 + 32 + 9] = 8;  // second record axis index
    CHECK(std::get<InputError>(InputTimeline::decode(bad_axis)) == InputError::invalid_event);
  }
  {  // replay: same tick hashes, order visible in the hash, focus loss explicit
    InputTimeline t;
    InputState recorded;
    const auto hashes = record_hashes(t, recorded);
    CHECK(recorded.focused && recorded.key_down(67));   // key 65 cleared at focus loss
    CHECK(!recorded.key_down(65) && recorded.motion_x == 3);  // motion after loss ignored
    for (int attempt = 0; attempt < 2; ++attempt) {
      InputState replayed;
      InputReplay replay(t);
      std::uint64_t tick = 0;
      std::span<const InputEvent> events;
      for (std::size_t i = 0; i < hashes.size(); ++i) {
        const auto expected = static_cast<std::uint64_t>(i + 1);
        if (!t.at(expected).empty()) {  // replay yields only ticks with events
          CHECK(replay.next(tick, events));
          CHECK(tick == expected);
          for (const auto& e : events) replayed.apply(e);
        }
        CHECK(t.snapshot_hash(expected, replayed) == hashes[i]);
      }
      CHECK(replay.done() && replay.position() == t.size());
      CHECK(replayed.hash() == recorded.hash());
      CHECK(!replay.next(tick, events));
    }
    // Event order matters: tick 2 has motion + key; swapping them leaves
    // the final state identical but changes the tick's snapshot hash.
    InputTimeline reordered;
    CHECK(reordered.append(2, key(66, true)));
    CHECK(reordered.append(2, motion(3, -2)));
    CHECK(reordered.at(2).size() == 2 && t.at(2).size() == 2);
    InputState s1, s2;
    for (const auto& e : t.at(2)) s1.apply(e);
    for (const auto& e : reordered.at(2)) s2.apply(e);
    CHECK(s1.hash() == s2.hash());
    CHECK(reordered.snapshot_hash(2, s2) != t.snapshot_hash(2, s1));
  }
  {  // ENG-30 integration: drive the same tick sequence through the fixed clock
    using poko::loop::FixedStepLoop;
    InputTimeline timeline;
    InputState live;
    std::vector<std::uint64_t> live_hashes;
    FixedStepLoop clock;
    std::uint64_t tick = 0;
    const std::array<double, 12> deltas{0.02, 0.03, 0.05, 0.016, 0.034, 0.05,
                                         5.0,  0.05, 0.01, 0.04,  0.05, 0.05};
    for (const double dt : deltas) {
      const auto steps = clock.advance(dt);
      for (std::uint32_t s = 0; s < steps; ++s) {
        ++tick;
        if (tick == 1) CHECK(timeline.append(tick, key(65, true)));
        if (tick == 2) CHECK(timeline.append(tick, motion(5, 5)));
        if (tick == 3) CHECK(timeline.append(tick, simple(InputKind::focus_lost)));
        if (tick == 4) CHECK(timeline.append(tick, key(65, false)));
        if (tick == 5) CHECK(timeline.append(tick, simple(InputKind::focus_gained)));
        for (const auto& e : timeline.at(tick)) live.apply(e);
        live_hashes.push_back(timeline.snapshot_hash(tick, live));
      }
    }
    CHECK(live_hashes.size() == 13);  // 4 pre-stall + 5 clamped + 4 post-stall steps
    FixedStepLoop replay_clock;
    InputState replayed;
    InputReplay replay(timeline);
    tick = 0;
    std::size_t index = 0;
    for (const double dt : deltas) {
      const auto steps = replay_clock.advance(dt);
      for (std::uint32_t s = 0; s < steps; ++s) {
        ++tick;
        if (!timeline.at(tick).empty()) {
          std::uint64_t replay_tick = 0;
          std::span<const InputEvent> events;
          CHECK(replay.next(replay_tick, events));
          CHECK(replay_tick == tick);
          for (const auto& e : events) replayed.apply(e);
        }
        CHECK(timeline.snapshot_hash(tick, replayed) == live_hashes[index++]);
      }
    }
    CHECK(index == live_hashes.size() && replay.done());
    CHECK(replayed.hash() == live.hash());
  }

  if (failures) { std::fprintf(stderr, "%d input snapshot check(s) failed\n", failures); return 1; }
  std::puts("PASS: input snapshots record/replay, focus loss, ordering, encode, tick hashes");
  return 0;
}

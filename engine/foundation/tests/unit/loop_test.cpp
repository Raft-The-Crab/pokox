// ENG-30: fixed-step main-loop clock — 20 Hz sim, variable-rate render,
// spiral-guard clamp, backlog discard, determinism, invalid-input safety.
#include "poko/foundation/loop.hpp"

#include <cmath>
#include <cstdio>
#include <limits>

namespace {
int failures = 0;
#define CHECK(cond) do { if (!(cond)) { \
  std::fprintf(stderr, "FAIL line %d: %s\n", __LINE__, #cond); ++failures; \
} } while (0)
bool near(double a, double b, double eps = 1e-9) { return std::abs(a - b) < eps; }
}

int main() {
  using poko::loop::FixedStepLoop;

  {  // spec default: 20 Hz fixed sim, 50 ms steps, sane spiral limits
    FixedStepLoop loop;
    CHECK(loop.valid_limits());
    CHECK(near(loop.step_seconds(), 0.05));
    CHECK(loop.limits().max_frame_dt == 0.25);
    CHECK(loop.limits().max_steps_per_frame == 5);
    CHECK(loop.advance(0.05) == 1);
    CHECK(loop.total_steps() == 1 && loop.frames() == 1);
    CHECK(near(loop.alpha(), 0.0) && !loop.clamped_last_frame());
  }
  {  // variable render faster than sim: 60 Hz frames, steps only on tick
    FixedStepLoop loop;
    const double dt = 1.0 / 60.0;
    CHECK(loop.advance(dt) == 0);
    CHECK(near(loop.alpha(), dt / 0.05, 1e-6));  // ns rounding: 1/3 to ~1e-9
    CHECK(loop.advance(dt) == 0);
    CHECK(loop.advance(dt) == 1);   // 3 frames * 1/60 = 0.05
    CHECK(near(loop.alpha(), 0.0, 1e-6));
    // 3 seconds of 60 Hz frames -> exactly 60 sim steps, never two in a frame
    std::uint32_t max_burst = 0, total = 0;
    for (int i = 0; i < 180; ++i) {
      const auto steps = loop.advance(dt);
      max_burst = steps > max_burst ? steps : max_burst;
      total += steps;
      CHECK(loop.alpha() >= 0.0 && loop.alpha() < 1.0);
    }
    CHECK(total == 60 && max_burst == 1);
    CHECK(loop.total_steps() == 61);  // warm-up frames above already ticked once
  }
  {  // catch-up: one slow 0.2 s frame runs 4 steps immediately
    FixedStepLoop loop;
    CHECK(loop.advance(0.2) == 4);
    CHECK(!loop.clamped_last_frame());
    CHECK(near(loop.backlog_seconds(), 0.0));
  }
  {  // spiral guard: a 5 s stall clamps to 0.25 s, 5 steps, debt discarded
    FixedStepLoop loop;
    CHECK(loop.advance(5.0) == 5);
    CHECK(loop.clamped_last_frame());
    CHECK(loop.backlog_seconds() < 0.05);
    CHECK(near(loop.alpha(), loop.backlog_seconds() / 0.05, 1e-12));
    // Repeated stalls can never spiral: bounded steps, bounded backlog,
    // sim time stays <= wall time.
    for (int i = 0; i < 100; ++i) {
      CHECK(loop.advance(5.0) == 5);
      CHECK(loop.backlog_seconds() < 0.05);
      CHECK(loop.alpha() >= 0.0 && loop.alpha() < 1.0);
    }
    CHECK(loop.total_steps() == 5 * 101);
  }
  {  // backlog reset after focus loss: no catch-up burst
    FixedStepLoop loop;
    loop.advance(0.03);
    CHECK(loop.backlog_seconds() > 0.0);
    loop.reset_backlog();
    CHECK(loop.advance(0.02) == 0);  // would have ticked without the reset
    CHECK(loop.total_steps() == 0);
  }
  {  // invalid deltas pause the loop: no steps, no state change
    FixedStepLoop loop;
    CHECK(loop.advance(0.0) == 0);
    CHECK(loop.advance(-0.05) == 0);
    CHECK(loop.advance(std::numeric_limits<double>::quiet_NaN()) == 0);
    CHECK(loop.advance(std::numeric_limits<double>::infinity()) == 0);
    CHECK(loop.frames() == 0 && loop.total_steps() == 0 && loop.alpha() == 0.0);
    CHECK(loop.advance(0.05) == 1);  // still fully usable afterwards
  }
  {  // invalid limits pause instead of dividing by zero or stepping wild
    FixedStepLoop bad_hz(FixedStepLoop::Limits{0.0, 0.25, 5});
    CHECK(!bad_hz.valid_limits());
    CHECK(bad_hz.advance(0.25) == 0 && bad_hz.total_steps() == 0);
    FixedStepLoop bad_cap(FixedStepLoop::Limits{20.0, 0.25, 0});
    CHECK(!bad_cap.valid_limits());
    CHECK(bad_cap.advance(0.25) == 0);
    FixedStepLoop bad_clamp(FixedStepLoop::Limits{20.0, -1.0, 5});
    CHECK(!bad_clamp.valid_limits());
    CHECK(bad_clamp.advance(0.25) == 0);
    CHECK(bad_clamp.alpha() == 0.0);
  }
  {  // other rates: 60 Hz sim ticks once per 60 Hz frame
    FixedStepLoop loop(FixedStepLoop::Limits{60.0, 0.25, 15});
    for (int i = 0; i < 120; ++i) CHECK(loop.advance(1.0 / 60.0) == 1);
    CHECK(loop.total_steps() == 120);
  }
  {  // determinism: identical delta sequences give identical state
    FixedStepLoop a, b;
    const double pattern[] = {0.016, 0.016, 0.021, 0.05, 0.2, 5.0, 0.001, 0.05};
    for (const double dt : pattern) {
      CHECK(a.advance(dt) == b.advance(dt));
      CHECK(a.alpha() == b.alpha());
    }
    CHECK(a.total_steps() == b.total_steps() && a.frames() == b.frames());
    // Drift guard: long runs keep the backlog strictly below one step.
    FixedStepLoop steady;
    for (int i = 0; i < 10'000; ++i) {
      steady.advance(0.1);  // exactly two steps per frame
      CHECK(steady.backlog_seconds() < 0.05);
    }
    CHECK(steady.total_steps() == 20'000);
    FixedStepLoop odd;
    for (int i = 0; i < 10'000; ++i) odd.advance(0.049);
    CHECK(odd.total_steps() == 9'800);  // floor(490/0.05)
    CHECK(odd.backlog_seconds() < 0.05);
  }

  if (failures) { std::fprintf(stderr, "%d check(s) failed\n", failures); return 1; }
  std::puts("PASS: fixed-step loop 20 Hz sim, variable render, spiral clamp, determinism");
  return 0;
}

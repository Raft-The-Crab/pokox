#pragma once

#include <cstdint>

namespace poko::loop {

// ENG-30: fixed-step simulation clock for the engine main loop. The
// simulation advances in exact fixed steps (spec default 20 Hz = 50 ms);
// rendering runs once per frame at whatever rate the display allows. The
// loop feeds each presented frame's wall-clock delta to advance(), executes
// the returned number of sim steps, and renders with alpha() as the
// interpolation weight between the last two sim states.
//
// Spiral guard: a stalled or slow frame cannot drag the simulation into a
// catch-up spiral. The fed delta is clamped to max_frame_dt, at most
// max_steps_per_frame steps run per frame, and any backlog that still
// remains after a capped frame is discarded so debt never accumulates
// across frames. Sim time therefore always advances <= wall time.
//
// Deterministic by construction: identical delta sequences produce
// identical step counts, accumulator state and alpha. Accumulation runs on
// integer nanoseconds internally, so long runs cannot drift the way
// repeated floating-point addition would. The wall clock is only a delta
// source; MUT-38 input snapshots can drive the same sequence for replay.
// Non-finite or non-positive deltas are ignored (the loop is paused, state
// unchanged).
class FixedStepLoop {
 public:
  struct Limits {
    double sim_hz = 20.0;                    // fixed sim rate, > 0
    double max_frame_dt = 0.25;              // per-frame delta clamp, > 0
    std::uint32_t max_steps_per_frame = 5;   // catch-up cap, >= 1
  };

  FixedStepLoop();
  explicit FixedStepLoop(Limits limits);

  // Feed one presented frame's delta in seconds and report how many fixed
  // sim steps the caller must execute now (0..max_steps_per_frame). The
  // accumulator, step count, clamp flag and alpha are updated; the caller
  // executes the steps after the call.
  std::uint32_t advance(double frame_dt_seconds);

  // Fraction in [0,1) of progress toward the next sim step — the render
  // interpolation weight between the previous and current sim state.
  double alpha() const noexcept;
  double step_seconds() const noexcept;
  // Pending sim time not yet consumed (always < step_seconds() except
  // transiently inside a capped frame; 0 when paused by invalid limits).
  double backlog_seconds() const noexcept;
  std::uint64_t total_steps() const noexcept { return total_steps_; }
  std::uint64_t frames() const noexcept { return frames_; }
  // True when the last advance() clamped the fed delta and/or hit the
  // per-frame step cap (spiral guard engaged on that frame).
  bool clamped_last_frame() const noexcept { return clamped_last_; }

  // Discard any pending backlog without changing the phase of future
  // steps — call after a focus loss, debugger break or long minimize so
  // the sim does not burst to catch up.
  void reset_backlog() noexcept;

  const Limits& limits() const noexcept { return limits_; }
  // Limits are usable (finite 1e-6 <= sim_hz so a step fits in int64
  // nanoseconds, 0 < max_frame_dt <= 1e6, max_steps >= 1). Invalid or
  // absurd limits pause the loop: advance() returns 0 and leaves state
  // unchanged rather than overflowing or stepping unboundedly.
  bool valid_limits() const noexcept;

 private:
  Limits limits_{};
  std::int64_t step_ns_{};
  std::int64_t clamp_ns_{};
  std::int64_t accumulator_ns_{};
  std::uint64_t total_steps_{};
  std::uint64_t frames_{};
  bool clamped_last_{false};
};

}  // namespace poko::loop

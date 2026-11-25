#include "poko/foundation/loop.hpp"

#include <cmath>
#include <cstdint>

namespace poko::loop {
namespace {
// Nanosecond resolution keeps accumulation exact: no binary-float drift
// across long runs, identical state for identical delta sequences.
constexpr double kNsPerSecond = 1e9;
// Absurd-but-finite configurations (step or clamp beyond int64 nanoseconds)
// are treated as invalid and pause the loop instead of overflowing.
constexpr double kMinSimHz = 1e-6;      // step <= 1000 s
constexpr double kMaxFrameDt = 1e6;     // clamp <= ~11.6 days
std::int64_t to_ns(double seconds) { return std::llround(seconds * kNsPerSecond); }
}  // namespace

FixedStepLoop::FixedStepLoop() : FixedStepLoop(Limits{}) {}
FixedStepLoop::FixedStepLoop(Limits limits) : limits_(limits) {
  step_ns_ = limits_.sim_hz > 0.0 ? to_ns(1.0 / limits_.sim_hz) : 0;
  clamp_ns_ = to_ns(limits_.max_frame_dt);
}

bool FixedStepLoop::valid_limits() const noexcept {
  return limits_.sim_hz >= kMinSimHz && std::isfinite(limits_.sim_hz) &&
         limits_.max_frame_dt > 0.0 && limits_.max_frame_dt <= kMaxFrameDt &&
         limits_.max_steps_per_frame >= 1;
}

std::uint32_t FixedStepLoop::advance(double frame_dt_seconds) {
  clamped_last_ = false;
  if (!valid_limits()) return 0;  // paused; state untouched
  if (!std::isfinite(frame_dt_seconds) || frame_dt_seconds <= 0.0) return 0;
  ++frames_;
  std::int64_t dt = to_ns(frame_dt_seconds);
  if (dt > clamp_ns_) {
    dt = clamp_ns_;
    clamped_last_ = true;
  }
  accumulator_ns_ += dt;
  // Whole steps due now, capped by the spiral guard.
  std::int64_t steps = step_ns_ > 0 ? accumulator_ns_ / step_ns_ : 0;
  const bool capped = steps > limits_.max_steps_per_frame;
  if (capped) {
    steps = limits_.max_steps_per_frame;
    clamped_last_ = true;
  }
  accumulator_ns_ -= steps * step_ns_;
  if (capped && accumulator_ns_ >= step_ns_)
    accumulator_ns_ %= step_ns_;  // debt beyond one step is discarded
  total_steps_ += static_cast<std::uint64_t>(steps);
  return static_cast<std::uint32_t>(steps);
}

double FixedStepLoop::alpha() const noexcept {
  if (!valid_limits() || step_ns_ <= 0) return 0.0;
  if (accumulator_ns_ < 0 || accumulator_ns_ >= step_ns_) return 0.0;
  return static_cast<double>(accumulator_ns_) / static_cast<double>(step_ns_);
}

double FixedStepLoop::step_seconds() const noexcept {
  return static_cast<double>(step_ns_) / kNsPerSecond;
}

double FixedStepLoop::backlog_seconds() const noexcept {
  return static_cast<double>(accumulator_ns_) / kNsPerSecond;
}

void FixedStepLoop::reset_backlog() noexcept { accumulator_ns_ = 0; }

}  // namespace poko::loop

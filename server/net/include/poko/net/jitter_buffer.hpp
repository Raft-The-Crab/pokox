// NET-08: jitter buffer and interpolation per spec 06 — "Client keeps a
// 2–3 tick buffer, interpolates between snapshots, extrapolates at most
// 100 ms, and snaps to authoritative state on rejection. Buffer depth
// adapts to measured jitter." All math is integer (Q16.16 fixed-point
// coordinates) so the rendered path is deterministic across targets.
#pragma once

#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <deque>

namespace poko::net {

// 20 Hz tick rate is the spec's normal adaptive tick rate, so the 100 ms
// extrapolation cap is exactly 2 ticks.
inline constexpr std::uint32_t kTickRateHz = 20;
inline constexpr std::uint32_t kExtrapolationCapTicks = 2; // 100 ms then freeze

struct Snapshot {
  std::uint32_t tick;
  std::int64_t x; // Q16.16 fixed point
  std::int64_t y;
};

struct Sample {
  std::int64_t x;
  std::int64_t y;
  bool interpolated; // between two snapshots
  bool extrapolated; // past the newest snapshot, inside the cap
  bool frozen;       // past the extrapolation cap
  bool snapped;      // authority gap: jumped to authoritative state
};

class JitterBuffer {
public:
  explicit JitterBuffer(std::size_t max_depth = 16) : max_depth_(max_depth) {}

  // Returns false for stale snapshots (older than or equal to the newest
  // already buffered) — late arrivals under jitter are dropped, never
  // replayed, so rendered motion never moves backwards.
  bool push(const Snapshot& s) {
    if (!snaps_.empty() && s.tick <= snaps_.back().tick) {
      ++stale_dropped_;
      return false;
    }
    if (!snaps_.empty()) {
      const std::uint64_t delta = s.tick - snaps_.back().tick;
      const std::uint64_t dev =
          delta > kNominalDeltaTicks ? delta - kNominalDeltaTicks : kNominalDeltaTicks - delta;
      jitter_dev_sum_ += dev;
      ++jitter_samples_;
    }
    snaps_.push_back(s);
    while (snaps_.size() > max_depth_) snaps_.pop_front();
    return true;
  }

  // Adaptive depth: the base 2-tick buffer grows with measured inter-
  // arrival jitter, clamped to the spec's 2–3 band while jitter is small
  // and allowed to stretch further only under real network noise.
  std::uint32_t holdback_ticks() const {
    if (jitter_samples_ == 0) return kBaseHoldbackTicks;
    const std::uint64_t avg_jitter = jitter_dev_sum_ / jitter_samples_;
    const std::uint64_t holdback = kBaseHoldbackTicks + avg_jitter;
    return static_cast<std::uint32_t>(std::min<std::uint64_t>(holdback, kMaxHoldbackTicks));
  }

  // Newest buffered tick (0 before the first snapshot).
  std::uint32_t newest_tick() const { return snaps_.empty() ? 0 : snaps_.back().tick; }
  std::size_t size() const { return snaps_.size(); }
  std::uint64_t stale_dropped() const { return stale_dropped_; }

  // Render the world state at render_tick. The client keeps render_tick
  // behind the newest arrival by holdback_ticks(); this either interpolates
  // between the two snapshots around it, extrapolates the newest motion
  // within the cap, freezes at the cap, or snaps forward over an authority
  // gap it refuses to interpolate across.
  Sample sample(std::uint32_t render_tick) const {
    Sample out{};
    out.interpolated = out.extrapolated = out.frozen = out.snapped = false;
    if (snaps_.empty()) return out;

    // Behind the buffer: clamp to the oldest snapshot rather than replay.
    if (render_tick <= snaps_.front().tick) {
      out.x = snaps_.front().x;
      out.y = snaps_.front().y;
      return out;
    }

    // Find the pair around render_tick.
    for (auto it = snaps_.begin(); it + 1 != snaps_.end(); ++it) {
      const Snapshot& s0 = *it;
      const Snapshot& s1 = *(it + 1);
      if (render_tick > s1.tick) continue;

      const std::uint64_t den = s1.tick - s0.tick;
      if (den > kMaxInterpSpanTicks) {
        // A hole this wide means loss the FEC layer could not repair:
        // refuse to interpolate across it and snap to the authoritative
        // state before the gap.
        out.x = s0.x;
        out.y = s0.y;
        out.snapped = true;
        return out;
      }
      const std::uint64_t num = render_tick - s0.tick;
      out.x = s0.x + static_cast<std::int64_t>((s1.x - s0.x) * static_cast<std::int64_t>(num) /
                                               static_cast<std::int64_t>(den));
      out.y = s0.y + static_cast<std::int64_t>((s1.y - s0.y) * static_cast<std::int64_t>(num) /
                                               static_cast<std::int64_t>(den));
      out.interpolated = true;
      return out;
    }

    // Past the newest snapshot: extrapolate along the last segment's
    // velocity, at most kExtrapolationCapTicks, then freeze.
    if (snaps_.size() < 2) {
      out.x = snaps_.back().x;
      out.y = snaps_.back().y;
      return out;
    }
    const Snapshot& s0 = snaps_[snaps_.size() - 2];
    const Snapshot& s1 = snaps_.back();
    const std::uint64_t ahead = render_tick - s1.tick;
    const std::uint64_t span = s1.tick - s0.tick;
    if (ahead > kExtrapolationCapTicks) {
      out.x = s1.x;
      out.y = s1.y;
      out.frozen = true;
      return out;
    }
    out.x = s1.x + static_cast<std::int64_t>((s1.x - s0.x) * static_cast<std::int64_t>(ahead) /
                                             static_cast<std::int64_t>(span));
    out.y = s1.y + static_cast<std::int64_t>((s1.y - s0.y) * static_cast<std::int64_t>(ahead) /
                                             static_cast<std::int64_t>(span));
    out.extrapolated = true;
    return out;
  }

  static constexpr std::uint32_t kBaseHoldbackTicks = 2;  // spec: 2–3 tick buffer
  static constexpr std::uint32_t kMaxInterpSpanTicks = 4; // wider hole = snap
  static constexpr std::uint64_t kNominalDeltaTicks = 1;  // one snapshot per tick
  static constexpr std::uint64_t kMaxHoldbackTicks = 6;   // worst-case depth cap

private:
  std::deque<Snapshot> snaps_;
  std::size_t max_depth_;
  std::uint64_t jitter_dev_sum_ = 0;
  std::uint64_t jitter_samples_ = 0;
  std::uint64_t stale_dropped_ = 0;
};

} // namespace poko::net

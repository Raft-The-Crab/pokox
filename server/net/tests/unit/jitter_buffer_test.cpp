// NET-08 acceptance: "Motion smooth under injected jitter". Snapshots of a
// body in uniform motion arrive with random delays and reordering; the
// rendered path must stay monotonic with bounded per-tick deltas (no
// stutters, no jumps), track the true position within the holdback window,
// adapt buffer depth to measured jitter, extrapolate at most 100 ms and
// snap to authoritative state when it refuses to interpolate a gap.
#include "poko/net/jitter_buffer.hpp"

#include <cstdint>
#include <iostream>
#include <vector>

using namespace poko::net;

namespace {
// Deterministic LCG so the test is reproducible across targets.
std::uint32_t lcg_state = 0x12345678u;
std::uint32_t next_rand() {
  lcg_state = lcg_state * 1664525u + 1013904223u;
  return lcg_state >> 8;
}

std::int64_t true_x(std::uint32_t tick) { return static_cast<std::int64_t>(tick) * 65536; } // 1.0/tick
} // namespace

int main() {
  int errors = 0;
  auto check = [&](bool ok, const char* what) {
    if (!ok) { ++errors; std::cerr << "FAIL: " << what << "\n"; }
  };

  // Clean feed: interpolation is exact on the motion line.
  {
    JitterBuffer buf;
    for (std::uint32_t t = 0; t <= 20; ++t) buf.push({t, true_x(t), 0});
    auto mid = buf.sample(10);
    check(mid.interpolated && mid.x == true_x(10), "interpolation hits the motion line exactly");
  }

  // Extrapolation: continues motion at most 100 ms (2 ticks), then freezes.
  {
    JitterBuffer buf;
    for (std::uint32_t t = 0; t <= 20; ++t) buf.push({t, true_x(t), 0});
    auto past = buf.sample(22);
    check(past.extrapolated && past.x == true_x(22), "extrapolation follows the last segment within the cap");
    auto frozen = buf.sample(30);
    check(frozen.frozen && frozen.x == true_x(20), "extrapolation freezes at the 100 ms cap");
  }

  // Stale snapshots are rejected, never replayed.
  {
    JitterBuffer buf;
    check(buf.push({5, 5, 0}), "first snapshot accepted");
    check(buf.push({6, 6, 0}), "in-order snapshot accepted");
    check(!buf.push({6, 6, 0}), "duplicate snapshot rejected");
    check(!buf.push({4, 4, 0}), "late snapshot rejected");
    check(buf.stale_dropped() == 2, "stale drops are counted");
  }

  // Snap: an authority gap wider than kMaxInterpSpanTicks is not
  // interpolated — the sample snaps to the authoritative pre-gap state.
  {
    JitterBuffer buf;
    buf.push({10, true_x(10), 0});
    buf.push({11, true_x(11), 0});
    buf.push({20, true_x(20), 0});
    auto s = buf.sample(15);
    check(s.snapped && s.x == true_x(11), "wide gap snaps to authoritative state");
  }

  // Adaptive depth: zero jitter holds the spec's base depth; heavy jitter
  // stretches it.
  {
    JitterBuffer calm;
    for (std::uint32_t t = 1; t <= 20; ++t) calm.push({t, 0, 0});
    check(calm.holdback_ticks() >= 2 && calm.holdback_ticks() <= 3, "calm holdback stays in the 2–3 tick band");

    JitterBuffer noisy;
    for (std::uint32_t t = 1; t <= 20; ++t) noisy.push({t * 3, 0, 0}); // deltas 3, avg deviation 2
    check(noisy.holdback_ticks() > 3, "jitter stretches the holdback past the base depth");
  }

  // The acceptance itself: uniform motion, snapshots delayed and shuffled
  // by injected jitter (0–3 ticks, some reordered), rendered every tick.
  // Motion must stay smooth: monotonic, bounded per-tick step, and within
  // a few ticks of the truth.
  {
    JitterBuffer buf;
    const std::uint32_t kTicks = 400;
    // arrival[tick] = tick + random delay 0..3; deliver in arrival order.
    std::vector<std::pair<std::uint32_t, std::uint32_t>> arrivals; // (arrival, tick)
    for (std::uint32_t t = 0; t <= kTicks; ++t) arrivals.push_back({t + next_rand() % 4, t});
    std::sort(arrivals.begin(), arrivals.end());

    std::size_t next = 0;
    std::int64_t prev_x = 0;
    bool have_prev = false;
    std::uint64_t max_step = 0;
    for (std::uint32_t now = 0; now <= kTicks + 8; ++now) {
      while (next < arrivals.size() && arrivals[next].first <= now) {
        const std::uint32_t t = arrivals[next].second;
        buf.push({t, true_x(t), 0});
        ++next;
      }
      if (buf.size() < 3) continue;
      const std::uint32_t render = buf.newest_tick() - buf.holdback_ticks();
      auto s = buf.sample(render);
      if (have_prev) {
        check(s.x >= prev_x, "rendered motion never moves backwards under jitter");
        const std::uint64_t step = static_cast<std::uint64_t>(s.x - prev_x);
        max_step = std::max(max_step, step);
        // Smoothness bound: at most holdback + cap ticks of catch-up in one
        // rendered tick (a snap after loss may cover the gap, but on this
        // jitter-only run there are no gaps).
        check(step <= static_cast<std::uint64_t>(buf.holdback_ticks() + kExtrapolationCapTicks + 2) * 65536,
              "per-tick step stays inside the smoothness bound");
      }
      prev_x = s.x;
      have_prev = true;
    }
    check(max_step > 0 && max_step <= 8 * 65536, "motion progressed smoothly, largest step bounded");
    check(prev_x > true_x(kTicks) - 8 * 65536, "rendered path tracks the truth within a few ticks");
  }

  if (errors) { std::cerr << errors << " failure(s)\n"; return 1; }
  std::cout << "jitter buffer tests passed\n";
  return 0;
}

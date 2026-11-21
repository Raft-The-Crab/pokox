// ENG-15: rolling frame statistics — CPU/GPU ms means, FPS, window wrap,
// invalid-sample rejection.
#include "poko/foundation/frame_stats.hpp"

#include <cmath>
#include <cstdio>

namespace {
int failures = 0;
#define CHECK(cond) do { if (!(cond)) { \
  std::fprintf(stderr, "FAIL line %d: %s\n", __LINE__, #cond); ++failures; \
} } while (0)
bool near(double a, double b, double eps = 1e-9) { return std::abs(a - b) < eps; }
}

int main() {
  using namespace poko::stats;
  {
    FrameStats s;
    CHECK(s.frames() == 0 && s.fps() == 0.0 && s.cpu_ms() == 0.0 && s.gpu_ms() == 0.0);
    s.record_cpu(0.010);  // 10 ms → 100 fps
    CHECK(s.frames() == 1);
    CHECK(s.fps() == 0.0);          // needs 2 samples for a rate
    CHECK(near(s.cpu_ms(), 10.0));
    s.record_cpu(0.020);
    CHECK(near(s.cpu_ms(), 15.0));
    CHECK(near(s.fps(), 1000.0 / 15.0));  // mean frame 15 ms
    // GPU samples lag CPU; they feed an independent window.
    CHECK(s.gpu_ms() == 0.0);
    s.record_gpu(0.005);
    CHECK(near(s.gpu_ms(), 5.0));
    s.record_gpu(0.015);
    CHECK(near(s.gpu_ms(), 10.0));
  }
  {  // window wrap: after kWindow+ samples the mean covers only the tail
    FrameStats s;
    for (int i = 0; i < FrameStats::kWindow; ++i) s.record_cpu(0.001);
    for (int i = 0; i < 10; ++i) s.record_cpu(0.100);
    CHECK(s.frames() == FrameStats::kWindow + 10);
    // Last 120 samples: 110 of 1 ms + 10 of 100 ms → (110+1000)/120 ms
    CHECK(near(s.cpu_ms(), (110.0 + 1000.0) / 120.0, 1e-6));
    // GPU window is independent.
    for (int i = 0; i < 5; ++i) s.record_gpu(0.002);
    CHECK(near(s.gpu_ms(), 2.0));
  }
  {  // invalid samples are rejected, not averaged in
    FrameStats s;
    s.record_cpu(-1.0); s.record_cpu(0.0 / 0.0); s.record_cpu(1.0 / 0.0);
    s.record_gpu(-0.5);
    CHECK(s.frames() == 0 && s.cpu_ms() == 0.0 && s.gpu_ms() == 0.0);
    s.record_cpu(0.004);
    CHECK(s.frames() == 1 && near(s.cpu_ms(), 4.0));
  }
  if (failures) { std::fprintf(stderr, "%d check(s) failed\n", failures); return 1; }
  std::puts("PASS: frame stats rolling means, FPS, window wrap, invalid rejection");
  return 0;
}

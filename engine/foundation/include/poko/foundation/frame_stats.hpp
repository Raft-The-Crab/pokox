#pragma once

#include <cstddef>
#include <cstdint>

namespace poko::stats {

// Rolling frame statistics for the ENG-15 timing/stats surface. Dependency-free
// and single-threaded: the engine main loop records one CPU sample per
// presented frame and GPU samples as query results become available (they lag
// by a few frames). Averages cover the last `window` samples so the display
// reacts quickly without jitter.
class FrameStats {
 public:
  static constexpr std::size_t kWindow = 120;

  // CPU time spent inside the frame (event polling + graph execute + submit),
  // in seconds. Call once per executed frame, in order — including frames
  // skipped for present (not_drawable/resize), whose CPU cost is still real.
  void record_cpu(double seconds) noexcept;
  // GPU frame duration in seconds, fed whenever a duration-query result lands.
  void record_gpu(double seconds) noexcept;

  std::uint64_t frames() const noexcept { return frames_; }
  bool has_gpu_sample() const noexcept { return gpu_count_ != 0; }
  // Frames per second over the CPU-sample window (0 before the first sample).
  double fps() const noexcept;
  // Rolling mean CPU/GPU frame time in milliseconds; gpu_ms() is 0 until the
  // first GPU sample arrives.
  double cpu_ms() const noexcept;
  double gpu_ms() const noexcept;

 private:
  double cpu_window_[kWindow]{};
  double gpu_window_[kWindow]{};
  std::size_t cpu_head_ = 0, gpu_head_ = 0;
  std::size_t cpu_count_ = 0, gpu_count_ = 0;
  std::uint64_t frames_ = 0;
};

}  // namespace poko::stats

#include "poko/foundation/frame_stats.hpp"

#include <algorithm>
#include <cmath>

namespace poko::stats {
namespace {
double window_mean(const double* ring, std::size_t head, std::size_t count) noexcept {
  if (!count) return 0.0;
  double sum = 0.0;
  for (std::size_t i = 0; i < count; ++i) sum += ring[(head + i) % FrameStats::kWindow];
  return sum / static_cast<double>(count);
}
}

void FrameStats::record_cpu(double seconds) noexcept {
  if (!(seconds >= 0.0) || !std::isfinite(seconds)) return;  // reject NaN/inf
  cpu_window_[cpu_head_] = seconds;
  cpu_head_ = (cpu_head_ + 1) % kWindow;
  cpu_count_ = std::min<std::size_t>(cpu_count_ + 1, kWindow);
  ++frames_;
}

void FrameStats::record_gpu(double seconds) noexcept {
  if (!(seconds >= 0.0) || !std::isfinite(seconds)) return;
  gpu_window_[gpu_head_] = seconds;
  gpu_head_ = (gpu_head_ + 1) % kWindow;
  gpu_count_ = std::min<std::size_t>(gpu_count_ + 1, kWindow);
}

double FrameStats::fps() const noexcept {
  if (cpu_count_ < 2) return 0.0;
  const double mean = window_mean(cpu_window_,
      (cpu_head_ + kWindow - cpu_count_) % kWindow, cpu_count_);
  return mean > 0.0 ? 1.0 / mean : 0.0;
}

double FrameStats::cpu_ms() const noexcept {
  return window_mean(cpu_window_,
      (cpu_head_ + kWindow - cpu_count_) % kWindow, cpu_count_) * 1000.0;
}

double FrameStats::gpu_ms() const noexcept {
  return window_mean(gpu_window_,
      (gpu_head_ + kWindow - gpu_count_) % kWindow, gpu_count_) * 1000.0;
}

}  // namespace poko::stats

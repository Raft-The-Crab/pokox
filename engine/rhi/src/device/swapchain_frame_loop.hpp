#pragma once
// Backend-neutral acquire -> submit -> present sequencing with bounded
// swapchain recreation (review 2026-11-26 H3). The Android Vulkan clear
// renderer drives it with real vk* calls; pokox_swapchain_frame_loop_test
// drives it with a fault-injecting double, so the fence/retry rules are
// tested without a device.
//
// Rules:
//   - The frame fence is waited only while a submission is in flight and
//     reset only immediately before the submit that will signal it. An
//     acquire that fails (OUT_OF_DATE, error) therefore never leaves an
//     unsignaled fence for the next wait — the old code reset first and
//     then recursed into an infinite wait on it.
//   - OUT_OF_DATE from acquire or present recreates the swapchain and
//     retries the frame at most kMaxSwapchainRecreates times; no recursion.
//   - SUBOPTIMAL acquire is a success (image and semaphore are valid).
#include <cstdint>

namespace poko::rhi::detail {

enum class SwapchainStatus : std::uint8_t { ok, suboptimal, out_of_date, error };

enum class FrameOutcome : std::uint8_t {
  presented,          // submitted and queued for present (incl. SUBOPTIMAL)
  retries_exhausted,  // still OUT_OF_DATE after the recreate budget
  recreate_failed,
  wait_failed,
  acquire_failed,
  submit_failed,
  present_failed,
};

inline constexpr int kMaxSwapchainRecreates = 2;

// Ops contract (all calls are synchronous):
//   bool fence_pending() const;   a submit that signals the fence is in flight
//   bool wait_fence();            wait for it; clears pending on success
//   SwapchainStatus acquire(std::uint32_t& index);
//   bool recreate();              idle the device, rebuild the swapchain
//   void record(std::uint32_t index);
//   void reset_fence();
//   bool submit();                sets pending on success
//   SwapchainStatus present(std::uint32_t index);
template <class Ops>
FrameOutcome run_swapchain_frame(Ops& ops) {
  int recreates = 0;
  for (;;) {
    if (ops.fence_pending() && !ops.wait_fence()) return FrameOutcome::wait_failed;
    std::uint32_t index = 0;
    const SwapchainStatus acquired = ops.acquire(index);
    if (acquired == SwapchainStatus::out_of_date) {
      if (recreates == kMaxSwapchainRecreates) return FrameOutcome::retries_exhausted;
      ++recreates;
      if (!ops.recreate()) return FrameOutcome::recreate_failed;
      continue;
    }
    if (acquired == SwapchainStatus::error) return FrameOutcome::acquire_failed;
    ops.record(index);
    ops.reset_fence();
    if (!ops.submit()) return FrameOutcome::submit_failed;
    const SwapchainStatus presented = ops.present(index);
    if (presented == SwapchainStatus::ok || presented == SwapchainStatus::suboptimal)
      return FrameOutcome::presented;
    if (presented == SwapchainStatus::error) return FrameOutcome::present_failed;
    if (recreates == kMaxSwapchainRecreates) return FrameOutcome::retries_exhausted;
    ++recreates;
    if (!ops.recreate()) return FrameOutcome::recreate_failed;
  }
}

}  // namespace poko::rhi::detail

// Review 2026-11-26 H3: fence/retry sequencing of the Android Vulkan clear
// renderer, driven by a fault-injecting double that models a Vulkan fence
// (a wait on an unsignaled fence with nothing in flight is a deadlock).
#include "../../src/device/swapchain_frame_loop.hpp"

#include <cstdio>
#include <deque>
#include <string>

namespace {
int failures = 0;
#define CHECK(cond) do { if (!(cond)) { \
  std::fprintf(stderr, "FAIL line %d: %s\n", __LINE__, #cond); ++failures; \
} } while (0)

using poko::rhi::detail::FrameOutcome;
using poko::rhi::detail::SwapchainStatus;
using poko::rhi::detail::run_swapchain_frame;
using poko::rhi::detail::kMaxSwapchainRecreates;

struct FakeSwapchain {
  // Fence model: created signaled (VK_FENCE_CREATE_SIGNALED_BIT); submit
  // signals it on completion (immediately here).
  bool fence_signaled = true;
  bool pending = false;
  bool deadlocked = false;
  std::deque<SwapchainStatus> acquire_script, present_script;
  bool recreate_ok = true, submit_ok = true;
  int waits = 0, acquires = 0, recreates = 0, submits = 0, presents = 0, records = 0;
  std::string log;

  bool fence_pending() const { return pending; }
  bool wait_fence() {
    ++waits;
    log += 'W';
    if (!fence_signaled) { deadlocked = true; return false; }  // UINT64_MAX wait
    pending = false;
    return true;
  }
  SwapchainStatus acquire(std::uint32_t& index) {
    ++acquires;
    log += 'A';
    index = 1;
    if (acquire_script.empty()) return SwapchainStatus::ok;
    const auto s = acquire_script.front();
    acquire_script.pop_front();
    return s;
  }
  bool recreate() { ++recreates; log += 'R'; return recreate_ok; }
  void record(std::uint32_t) { ++records; }
  void reset_fence() { fence_signaled = false; log += 'r'; }
  bool submit() {
    ++submits;
    log += 'S';
    if (!submit_ok) return false;
    pending = true;
    fence_signaled = true;  // GPU finishes instantly in the double
    return true;
  }
  SwapchainStatus present(std::uint32_t) {
    ++presents;
    log += 'P';
    if (present_script.empty()) return SwapchainStatus::ok;
    const auto s = present_script.front();
    present_script.pop_front();
    return s;
  }
};
}  // namespace

int main() {
  {  // steady state: two frames, the second waits on the first's fence
    FakeSwapchain f;
    CHECK(run_swapchain_frame(f) == FrameOutcome::presented);
    CHECK(run_swapchain_frame(f) == FrameOutcome::presented);
    CHECK(f.log == "ArSPWArSP");
    CHECK(!f.deadlocked);
  }
  {  // acquire OUT_OF_DATE (rotation): recreate, retry, present; the fence
     // is never reset before the failed acquire, so nothing deadlocks.
     // Old code: W r A(ood) -> recurse -> W on the unsignaled fence = hang.
    FakeSwapchain f;
    CHECK(run_swapchain_frame(f) == FrameOutcome::presented);  // frame 1 in flight
    f.acquire_script = {SwapchainStatus::out_of_date};
    CHECK(run_swapchain_frame(f) == FrameOutcome::presented);
    CHECK(!f.deadlocked);
    CHECK(f.recreates == 1 && f.submits == 2 && f.presents == 2);
    CHECK(f.log == "ArSPWARArSP");
  }
  {  // acquire keeps failing OUT_OF_DATE: bounded, reports retries_exhausted
    FakeSwapchain f;
    f.acquire_script = {SwapchainStatus::out_of_date, SwapchainStatus::out_of_date,
                        SwapchainStatus::out_of_date, SwapchainStatus::out_of_date};
    CHECK(run_swapchain_frame(f) == FrameOutcome::retries_exhausted);
    CHECK(f.recreates == kMaxSwapchainRecreates);
    CHECK(f.acquires == kMaxSwapchainRecreates + 1);
    CHECK(f.submits == 0 && !f.deadlocked);
    // and the renderer still works on the next frame
    f.acquire_script.clear();
    CHECK(run_swapchain_frame(f) == FrameOutcome::presented);
    CHECK(!f.deadlocked);
  }
  {  // present OUT_OF_DATE: frame was submitted; recreate and redo, bounded
    FakeSwapchain f;
    f.present_script = {SwapchainStatus::out_of_date};
    CHECK(run_swapchain_frame(f) == FrameOutcome::presented);
    CHECK(f.recreates == 1 && f.submits == 2 && !f.deadlocked);
    f.present_script = {SwapchainStatus::out_of_date, SwapchainStatus::out_of_date,
                        SwapchainStatus::out_of_date};
    CHECK(run_swapchain_frame(f) == FrameOutcome::retries_exhausted);
    CHECK(!f.deadlocked);
  }
  {  // SUBOPTIMAL acquire is a valid image (old code treated it as failure)
    FakeSwapchain f;
    f.acquire_script = {SwapchainStatus::suboptimal};
    CHECK(run_swapchain_frame(f) == FrameOutcome::presented);
    f.present_script = {SwapchainStatus::suboptimal};
    CHECK(run_swapchain_frame(f) == FrameOutcome::presented);
  }
  {  // recreate failure (e.g. zero-size surface) is reported, not retried
    FakeSwapchain f;
    f.recreate_ok = false;
    f.acquire_script = {SwapchainStatus::out_of_date};
    CHECK(run_swapchain_frame(f) == FrameOutcome::recreate_failed);
    CHECK(f.recreates == 1 && f.submits == 0);
  }
  {  // failed submit after the reset: the fence is unsignaled but nothing is
     // in flight, so the next frame must not wait on it
    FakeSwapchain f;
    f.submit_ok = false;
    CHECK(run_swapchain_frame(f) == FrameOutcome::submit_failed);
    f.submit_ok = true;
    CHECK(run_swapchain_frame(f) == FrameOutcome::presented);
    CHECK(!f.deadlocked);
  }
  {  // acquire error: no submit, no reset
    FakeSwapchain f;
    f.acquire_script = {SwapchainStatus::error};
    CHECK(run_swapchain_frame(f) == FrameOutcome::acquire_failed);
    CHECK(f.fence_signaled && f.submits == 0);
  }
  if (failures != 0) {
    std::fprintf(stderr, "%d check(s) failed\n", failures);
    return 1;
  }
  std::puts("pokox_swapchain_frame_loop_test: all checks passed");
  return 0;
}

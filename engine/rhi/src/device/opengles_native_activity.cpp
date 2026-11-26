// Minimal Android NativeActivity probe for the windowed OpenGL ES clear path.
// Presents N clear frames on the real ANativeWindow surface, verifies the
// final frame's center pixel, writes the result to the app's external files
// dir and logcat, then finishes. Package as libpoko_gles.so with
// android.app.NativeActivity (see docs/eng04-progress.md for the APK steps).
#include <android/log.h>
#include <android/native_activity.h>
#include <android/native_window.h>
#include <android_native_app_glue.h>
#include <array>
#include <atomic>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <thread>
#include <chrono>
#include "poko/rhi/device/opengles_clear_renderer.hpp"
#include "poko/rhi/device/vulkan_clear_android.hpp"
#include <sys/stat.h>

#define LOG_TAG "poko_gles"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)

namespace {
constexpr std::array<float, 4> kClear{0.035f, 0.12f, 0.28f, 1.0f};
constexpr int kFrames = 120;
constexpr int kHoldMs = 800;

struct AppState {
  android_app* app = nullptr;
  ANativeWindow* window = nullptr;
  std::uint32_t width = 0, height = 0;
  bool have_size = false;
  bool renderer_ready = false;
  bool frames_done = false;
  bool done = false;
  int result = 1;
  std::string result_path;
};

void write_result(AppState& s, const char* line) {
  FILE* f = std::fopen(s.result_path.c_str(), "a");
  if (f) { std::fputs(line, f); std::fputc('\n', f); std::fclose(f); }
  LOGI("%s", line);
}

void run_frames(AppState& s) {
  using namespace poko::rhi;
  // INIT_WINDOW can fire before layout; re-query the real surface size now.
  const auto w = ANativeWindow_getWidth(s.window), h = ANativeWindow_getHeight(s.window);
  if (w > 0 && h > 0) { s.width = w; s.height = h; s.have_size = true; }
  // Real primary-first selection: Vulkan on the ANativeWindow surface; any
  // init failure falls back to OpenGL ES. A flag file forces GLES to exercise
  // the fallback path on demand.
  struct stat st{};
  const bool force_gles = stat((s.result_path.substr(0, s.result_path.find_last_of('/')) + "/force_gles").c_str(), &st) == 0;
  if (!force_gles) {
    write_result(s, "trying vulkan primary");
    // Some drivers can stall inside Vulkan init/present; run the whole Vulkan
    // attempt on a worker with a timeout so a hung driver cannot ANR the app.
    // On timeout the worker and its Vulkan objects are intentionally leaked —
    // this is a probe, not production lifecycle code.
    auto* vk = new VulkanClearAndroidRenderer();
    // The worker may outlive this frame (detached on timeout), so it shares
    // nothing by reference: it gets value copies of the window and size, its
    // own reference on the window (released when it finishes), and reports
    // through an atomic `done` flag (release/acquire orders init/presented).
    struct VkOutcome {
      RenderError init = RenderError::backend_failure;
      int presented = 0;
      std::atomic<bool> done{false};
    };
    auto* outcome = new VkOutcome();
    ANativeWindow* const window = s.window;
    const std::uint32_t width = s.width, height = s.height;
    ANativeWindow_acquire(window);
    std::thread worker([vk, outcome, window, width, height] {
      outcome->init = vk->initialize(window, width, height);
      if (outcome->init == RenderError::none) {
        for (int i = 0; i < kFrames; ++i) {
          if (vk->clear_and_present(kClear) != RenderError::none) break;
          ++outcome->presented;
        }
        vk->shutdown();
      }
      ANativeWindow_release(window);
      outcome->done.store(true, std::memory_order_release);
    });
    const auto deadline = std::chrono::steady_clock::now() + std::chrono::seconds(15);
    // Pump the event loop while waiting — blocking here without dispatching
    // events is itself an ANR on Android.
    while (!outcome->done.load(std::memory_order_acquire) &&
           std::chrono::steady_clock::now() < deadline) {
      int events = 0;
      android_poll_source* source = nullptr;
      if (ALooper_pollOnce(0, nullptr, &events, (void**)&source) >= 0 && source)
        source->process(s.app, source);
      if (s.done) break;
    }
    if (!outcome->done.load(std::memory_order_acquire)) {
      write_result(s, "vulkan attempt timed out; falling back to OpenGL ES");
      worker.detach();
    } else {
      worker.join();
      char marker[160];
      if (outcome->init == RenderError::none) {
        std::snprintf(marker, sizeof marker,
                      "vulkan primary: %d/%d frames presented on %dx%d",
                      outcome->presented, kFrames, s.width, s.height);
        write_result(s, marker);
        s.result = outcome->presented == kFrames ? 0 : 3;
        delete vk; delete outcome;
        return;
      }
      std::snprintf(marker, sizeof marker, "vulkan init -> failed (%d)",
                    static_cast<int>(outcome->init));
      write_result(s, marker);
      write_result(s, "vulkan init failed; fell back to OpenGL ES");
      delete vk; delete outcome;
    }
  }
  OpenGLClearESRenderer renderer;
  const auto init = renderer.initialize_window(s.window, s.width, s.height);
  if (init != RenderError::none) {
    char buf[128];
    std::snprintf(buf, sizeof buf, "initialize_window failed: %d", static_cast<int>(init));
    write_result(s, buf);
    s.result = 3;
    return;
  }
  s.renderer_ready = true;
  for (int i = 0; i < kFrames - 1; ++i) {
    if (renderer.clear_and_present(kClear) != RenderError::none) {
      write_result(s, "clear_and_present failed");
      s.result = 3;
      renderer.shutdown();
      return;
    }
  }
  std::array<float, 4> pixel{};
  const auto verify = renderer.clear_and_verify(kClear, pixel);
  const bool srgb = renderer.framebuffer_is_srgb();
  renderer.shutdown();
  s.renderer_ready = false;
  if (verify != RenderError::none) {
    write_result(s, "clear_and_verify failed");
    s.result = 3;
    return;
  }
  const std::array<int, 4> expected{
      srgb ? static_cast<int>(std::lround((kClear[0] <= 0.0031308f ? kClear[0] * 12.92f
                        : 1.055f * std::pow(kClear[0], 1.0f / 2.4f) - 0.055f) * 255.0f))
           : static_cast<int>(std::lround(kClear[0] * 255.0f)),
      srgb ? static_cast<int>(std::lround((kClear[1] <= 0.0031308f ? kClear[1] * 12.92f
                        : 1.055f * std::pow(kClear[1], 1.0f / 2.4f) - 0.055f) * 255.0f))
           : static_cast<int>(std::lround(kClear[1] * 255.0f)),
      srgb ? static_cast<int>(std::lround((kClear[2] <= 0.0031308f ? kClear[2] * 12.92f
                        : 1.055f * std::pow(kClear[2], 1.0f / 2.4f) - 0.055f) * 255.0f))
           : static_cast<int>(std::lround(kClear[2] * 255.0f)),
      255};
  const std::array<int, 4> actual{static_cast<int>(std::lround(pixel[0] * 255.0f)),
                                 static_cast<int>(std::lround(pixel[1] * 255.0f)),
                                 static_cast<int>(std::lround(pixel[2] * 255.0f)),
                                 static_cast<int>(std::lround(pixel[3] * 255.0f))};
  bool ok = true;
  for (int i = 0; i < 4; ++i) ok = ok && std::abs(actual[i] - expected[i]) <= 2;
  char buf[256];
  std::snprintf(buf, sizeof buf,
                "windowed %s: %d frames, %dx%d, pixel %d %d %d %d, expected %s %d %d %d %d -> %s",
                s.have_size ? "surface" : "default", kFrames, s.width, s.height,
                actual[0], actual[1], actual[2], actual[3], srgb ? "sRGB" : "linear",
                expected[0], expected[1], expected[2], expected[3], ok ? "PASS" : "FAIL");
  write_result(s, buf);
  s.result = ok ? 0 : 1;
}

void on_app_cmd(android_app* app, int32_t cmd) {
  auto* s = static_cast<AppState*>(app->userData);
  switch (cmd) {
    case APP_CMD_INIT_WINDOW:
      LOGI("INIT_WINDOW cmd");
      if (app->window) {
        s->window = app->window;
        s->width = ANativeWindow_getWidth(app->window);
        s->height = ANativeWindow_getHeight(app->window);
        s->have_size = s->width > 0 && s->height > 0;
        LOGI("window %dx%d", s->width, s->height);
      }
      break;
    case APP_CMD_TERM_WINDOW:
      s->window = nullptr;
      break;
    case APP_CMD_DESTROY:
      s->done = true;
      break;
    default:
      LOGI("app cmd %d", cmd);
      break;
  }
}
} // namespace

void android_main(android_app* app) {
  AppState state;
  state.app = app;
  app->userData = &state;
  app->onAppCmd = on_app_cmd;
  LOGI("android_main entered");
  // Internal files dir: /data/user/0/<pkg>/files — local filesystem, no FUSE.
  // /sdcard accesses can stall on some devices and ANR the app before the
  // probe even starts. Manifest sets android:debuggable for run-as access.
  const char* internal = app->activity->internalDataPath;
  state.result_path = internal ? std::string(internal) + "/gles_result.txt" : "/data/local/tmp/gles_result.txt";
  write_result(state, "android_main entered");
  // The glue can publish the first ANativeWindow before this thread starts.
  // Pick it up directly as well as through APP_CMD_INIT_WINDOW so a fast
  // surface creation is not missed by the command pump on newer Android.
  if (app->window) {
    state.window = app->window;
    state.width = ANativeWindow_getWidth(app->window);
    state.height = ANativeWindow_getHeight(app->window);
    state.have_size = state.width > 0 && state.height > 0;
  }
  int msgs = 0;
  while (!state.done) {
    int events;
    android_poll_source* source;
    while (ALooper_pollOnce(10, nullptr, &events, (void**)&source) >= 0) {
      if (source) source->process(app, source);
    }
    if (!state.done && state.window && !state.frames_done) {
      // Run the whole probe once the surface exists, then hold briefly so the
      // clear color is actually visible before finishing.
      run_frames(state);
      state.frames_done = true;
      std::this_thread::sleep_for(std::chrono::milliseconds(kHoldMs));
      state.done = true;
    }
    if (++msgs > 100000) state.done = true; // safety
  }
}

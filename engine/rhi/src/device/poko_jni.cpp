// JNI bridge for the Android clear-backend probe. Runs entirely on a worker
// thread spawned by nativeSetSurface so the UI thread never blocks on driver
// calls. Vulkan is attempted first on the real Surface; any init failure
// falls back to OpenGL ES — the ENG-04 primary/fallback contract on device.
#include <jni.h>
#include <android/native_window.h>
#include <android/native_window_jni.h>
#include <android/log.h>
#include <array>
#include <atomic>
#include <chrono>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <thread>
#include "poko/rhi/device/opengles_clear_renderer.hpp"
#include "poko/rhi/device/vulkan_clear_android.hpp"

#define LOG_TAG "poko_shell"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)

namespace {
constexpr std::array<float, 4> kClear{0.035f, 0.12f, 0.28f, 1.0f};
constexpr int kFrames = 120;
constexpr int kHoldMs = 800;

std::atomic<bool> g_stop{false};
std::thread g_worker;
std::string g_result_path;

void write_line(const char* line) {
  FILE* f = std::fopen(g_result_path.c_str(), "a");
  if (f) { std::fputs(line, f); std::fputc('\n', f); std::fclose(f); }
  LOGI("%s", line);
}

void run_probe(ANativeWindow* window, std::uint32_t w, std::uint32_t h) {
  using namespace poko::rhi;
  write_line("probe start");
  // 'force_gles' file in the app files dir skips Vulkan to exercise fallback.
  bool force_gles = false;
  if (FILE* f = std::fopen((g_result_path.substr(0, g_result_path.find_last_of('/')) + "/force_gles").c_str(), "r")) {
    force_gles = true; std::fclose(f);
  }
  // Primary: real Vulkan on the Surface.
  if (!force_gles) {
    VulkanClearAndroidRenderer vk;
    if (vk.initialize(window, w, h) == RenderError::none) {
      int presented = 0;
      for (int i = 0; i < kFrames && !g_stop.load(); ++i) {
        if (vk.clear_and_present(kClear) != RenderError::none) break;
        ++presented;
      }
      vk.shutdown();
      char buf[192];
      std::snprintf(buf, sizeof buf, "vulkan primary: %d/%d frames on %ux%u -> %s",
                    presented, kFrames, w, h, presented == kFrames ? "PASS" : "FAIL");
      write_line(buf);
      // Hold the last presented frame briefly so it can be screen-captured.
      for (int i = 0; i < kHoldMs / 50 && !g_stop.load(); ++i)
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
      return;
    }
    write_line("vulkan init failed; falling back to OpenGL ES");
  }
  // Fallback: OpenGL ES on the same Surface.
  {
    OpenGLClearESRenderer gles;
    if (gles.initialize_window(window, w, h) != RenderError::none) {
      write_line("gles init failed");
      return;
    }
    for (int i = 0; i < kFrames - 1 && !g_stop.load(); ++i) {
      if (gles.clear_and_present(kClear) != RenderError::none) break;
    }
    std::array<float, 4> pixel{};
    const auto verify = gles.clear_and_verify(kClear, pixel);
    const bool srgb = gles.framebuffer_is_srgb();
    gles.shutdown();
    if (verify != RenderError::none) { write_line("gles clear_and_verify failed"); return; }
    const auto e = [](float v, bool s) {
      const float enc = s ? (v <= 0.0031308f ? v * 12.92f : 1.055f * std::pow(v, 1.0f/2.4f) - 0.055f) : v;
      return static_cast<int>(std::lround(enc * 255.0f));
    };
    const int actual[4] = {static_cast<int>(std::lround(pixel[0]*255.f)),
                           static_cast<int>(std::lround(pixel[1]*255.f)),
                           static_cast<int>(std::lround(pixel[2]*255.f)),
                           static_cast<int>(std::lround(pixel[3]*255.f))};
    const int expected[4] = {e(kClear[0],srgb), e(kClear[1],srgb), e(kClear[2],srgb), 255};
    bool ok = true;
    for (int i = 0; i < 4; ++i) ok = ok && std::abs(actual[i]-expected[i]) <= 2;
    char buf[256];
    std::snprintf(buf, sizeof buf,
                  "gles fallback: %dx%d pixel %d %d %d %d expected %s %d %d %d %d -> %s",
                  w, h, actual[0], actual[1], actual[2], actual[3],
                  srgb ? "sRGB" : "linear", expected[0], expected[1], expected[2], expected[3],
                  ok ? "PASS" : "FAIL");
    write_line(buf);
    for (int i = 0; i < kHoldMs / 50 && !g_stop.load(); ++i)
      std::this_thread::sleep_for(std::chrono::milliseconds(50));
  }
}
} // namespace

extern "C" JNIEXPORT void JNICALL
Java_com_poko_glesclear_PokoActivity_nativeInit(JNIEnv* env, jclass, jstring filesDir) {
  const char* p = env->GetStringUTFChars(filesDir, nullptr);
  g_result_path = std::string(p ? p : "") + "/gles_result.txt";
  if (p) env->ReleaseStringUTFChars(filesDir, p);
  g_stop = false;
  write_line("nativeInit");
}

extern "C" JNIEXPORT void JNICALL
Java_com_poko_glesclear_PokoActivity_nativeSetSurface(JNIEnv* env, jclass,
                                                    jobject surface, jint w, jint h) {
  if (g_worker.joinable()) { g_stop = true; g_worker.join(); g_stop = false; }
  ANativeWindow* window = ANativeWindow_fromSurface(env, surface);
  if (!window) { write_line("ANativeWindow_fromSurface failed"); return; }
  const auto width = static_cast<std::uint32_t>(w), height = static_cast<std::uint32_t>(h);
  g_worker = std::thread([window, width, height] {
    run_probe(window, width, height);
    ANativeWindow_release(window);
    write_line("probe done");
  });
}

extern "C" JNIEXPORT void JNICALL
Java_com_poko_glesclear_PokoActivity_nativeSurfaceDestroyed(JNIEnv*, jclass) {
  g_stop = true;
  if (g_worker.joinable()) g_worker.join();
}

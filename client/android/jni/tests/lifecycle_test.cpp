// SHL-17: Android lifecycle callbacks — pause/resume/kill map correctly.
#include "poko/android/poko_jni_bridge.hpp"

#include <cstdint>
#include <cstdio>
#include <cstring>

namespace {

int failures = 0;

void check(bool ok, const char* what) {
  if (!ok) {
    std::puts(what);
    ++failures;
  }
}

void encode_config(std::uint8_t* out16,
                   std::uint32_t abi,
                   std::uint32_t w,
                   std::uint32_t h,
                   float dpi) {
  std::memcpy(out16 + 0, &abi, 4);
  std::memcpy(out16 + 4, &w, 4);
  std::memcpy(out16 + 8, &h, 4);
  std::memcpy(out16 + 12, &dpi, 4);
}

}  // namespace

int main() {
  using namespace poko::android;

  // Null/invalid handles fail closed.
  check(Java_com_poko_client_PokoNativeBridge_nativePause(nullptr, nullptr, 0) ==
            kJniErrorNull,
        "FAIL: null handle pause must return kJniErrorNull");
  check(Java_com_poko_client_PokoNativeBridge_nativeResume(nullptr, nullptr, 0) ==
            kJniErrorNull,
        "FAIL: null handle resume must return kJniErrorNull");
  check(Java_com_poko_client_PokoNativeBridge_nativeIsPaused(nullptr, nullptr, 0) ==
            JNI_FALSE,
        "FAIL: null handle isPaused must be false");

  std::uint8_t cfg[16]{};
  encode_config(cfg, kNativeAbiVersion, 1080, 2400, 3.0f);
  const jlong handle = Java_com_poko_client_PokoNativeBridge_nativeCreate(
      nullptr, nullptr, reinterpret_cast<jbyteArray>(cfg));
  check(handle != 0, "FAIL: nativeCreate");
  check(Java_com_poko_client_PokoNativeBridge_nativeIsPaused(nullptr, nullptr, handle) ==
            JNI_FALSE,
        "FAIL: newly created handle must not be paused");

  // Running frame advances frame count.
  check(Java_com_poko_client_PokoNativeBridge_nativeFrame(nullptr, nullptr, handle, 0.016) ==
            kJniOk,
        "FAIL: frame 1");
  check(Java_com_poko_client_PokoNativeBridge_nativeFrameCount(nullptr, nullptr, handle) == 1,
        "FAIL: frame count must be 1");

  // Pause: isPaused becomes true and nativeFrame skips advancing.
  check(Java_com_poko_client_PokoNativeBridge_nativePause(nullptr, nullptr, handle) ==
            kJniOk,
        "FAIL: nativePause");
  check(Java_com_poko_client_PokoNativeBridge_nativeIsPaused(nullptr, nullptr, handle) ==
            JNI_TRUE,
        "FAIL: isPaused must be true after nativePause");
  check(Java_com_poko_client_PokoNativeBridge_nativeFrame(nullptr, nullptr, handle, 0.016) ==
            kJniOk,
        "FAIL: frame while paused");
  check(Java_com_poko_client_PokoNativeBridge_nativeFrameCount(nullptr, nullptr, handle) == 1,
        "FAIL: frame count must stay 1 while paused");

  // Resume: isPaused becomes false and nativeFrame advances again.
  check(Java_com_poko_client_PokoNativeBridge_nativeResume(nullptr, nullptr, handle) ==
            kJniOk,
        "FAIL: nativeResume");
  check(Java_com_poko_client_PokoNativeBridge_nativeIsPaused(nullptr, nullptr, handle) ==
            JNI_FALSE,
        "FAIL: isPaused must be false after nativeResume");
  check(Java_com_poko_client_PokoNativeBridge_nativeFrame(nullptr, nullptr, handle, 0.016) ==
            kJniOk,
        "FAIL: frame 2 after resume");
  check(Java_com_poko_client_PokoNativeBridge_nativeFrameCount(nullptr, nullptr, handle) == 2,
        "FAIL: frame count must be 2 after resume");

  // Kill/destroy: invalidates handle and subsequent pause/resume fail closed.
  Java_com_poko_client_PokoNativeBridge_nativeDestroy(nullptr, nullptr, handle);
  check(Java_com_poko_client_PokoNativeBridge_nativeIsValidHandle(nullptr, nullptr, handle) ==
            JNI_FALSE,
        "FAIL: destroyed handle must be invalid");
  check(Java_com_poko_client_PokoNativeBridge_nativePause(nullptr, nullptr, handle) ==
            kJniErrorNull,
        "FAIL: pause on destroyed handle must return kJniErrorNull");
  check(Java_com_poko_client_PokoNativeBridge_nativeResume(nullptr, nullptr, handle) ==
            kJniErrorNull,
        "FAIL: resume on destroyed handle must return kJniErrorNull");

  if (failures > 0) {
    std::printf("FAIL: %d SHL-17 lifecycle check(s) failed\n", failures);
    return 1;
  }
  std::puts("OK: all SHL-17 Android lifecycle checks passed");
}

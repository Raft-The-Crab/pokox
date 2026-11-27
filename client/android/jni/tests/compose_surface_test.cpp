// SHL-16: Android Compose chrome over SDL/GLES surface — nativeSetSurface,
// nativeFrame, and nativeInput lifecycle checks.
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

  std::uint8_t cfg[16]{};
  encode_config(cfg, kNativeAbiVersion, 1080, 2400, 3.0f);
  const jlong handle = Java_com_poko_client_PokoNativeBridge_nativeCreate(
      nullptr, nullptr, reinterpret_cast<jbyteArray>(cfg));
  check(handle != 0, "FAIL: nativeCreate");

  int dummy_surface = 1;
  check(Java_com_poko_client_PokoNativeBridge_nativeSetSurface(
            nullptr, nullptr, handle, reinterpret_cast<jobject>(&dummy_surface)) == kJniOk,
        "FAIL: nativeSetSurface attach");
  check(from_jlong(handle)->has_surface, "FAIL: has_surface must be true");

  check(Java_com_poko_client_PokoNativeBridge_nativeFrame(nullptr, nullptr, handle, 0.016) ==
            kJniOk,
        "FAIL: nativeFrame");
  check(Java_com_poko_client_PokoNativeBridge_nativeFrameCount(nullptr, nullptr, handle) == 1,
        "FAIL: frame count must be 1");

  check(Java_com_poko_client_PokoNativeBridge_nativeInput(
            nullptr, nullptr, handle, 0, 120.0f, 340.0f, 0, 1) == kJniOk,
        "FAIL: nativeInput");
  check(Java_com_poko_client_PokoNativeBridge_nativeInputCount(nullptr, nullptr, handle) == 1,
        "FAIL: input count must be 1");

  check(Java_com_poko_client_PokoNativeBridge_nativeSetSurface(
            nullptr, nullptr, handle, nullptr) == kJniOk,
        "FAIL: nativeSetSurface detach");
  check(!from_jlong(handle)->has_surface, "FAIL: has_surface must be false after detach");

  check(Java_com_poko_client_PokoNativeBridge_nativeFrame(nullptr, nullptr, 0, 0.016) ==
            kJniErrorNull,
        "FAIL: null handle frame must return kJniErrorNull");

  Java_com_poko_client_PokoNativeBridge_nativeDestroy(nullptr, nullptr, handle);

  if (failures > 0) {
    std::printf("FAIL: %d SHL-16 Android Compose/surface check(s) failed\n", failures);
    return 1;
  }
  std::puts("OK: all SHL-16 Android Compose/surface checks passed");
}

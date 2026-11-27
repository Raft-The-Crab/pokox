// SHL-15: Android JNI handle creation, validation, error paths, and destroy.
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

  // Null config fails closed with kJniErrorNull and returns 0 handle.
  check(Java_com_poko_client_PokoNativeBridge_nativeCreate(nullptr, nullptr, nullptr) == 0,
        "FAIL: null config must return 0 handle");
  check(Java_com_poko_client_PokoNativeBridge_nativeLastError(nullptr, nullptr) ==
            kJniErrorNull,
        "FAIL: null config must record kJniErrorNull");

  // ABI mismatch fails closed.
  std::uint8_t bad_abi[16]{};
  encode_config(bad_abi, kNativeAbiVersion + 1, 1280, 720, 2.0f);
  std::int32_t err = 0;
  check(create_native_handle(bad_abi, sizeof(bad_abi), &err) == 0 &&
            err == kJniErrorAbiMismatch,
        "FAIL: ABI mismatch must return 0 and kJniErrorAbiMismatch");

  // Invalid dimensions fail closed.
  std::uint8_t bad_dims[16]{};
  encode_config(bad_dims, kNativeAbiVersion, 0, 720, 1.0f);
  check(create_native_handle(bad_dims, sizeof(bad_dims), &err) == 0 &&
            err == kJniErrorInvalidConfig,
        "FAIL: zero width must return 0 and kJniErrorInvalidConfig");

  // Valid config creates a live opaque handle.
  std::uint8_t good_cfg[16]{};
  encode_config(good_cfg, kNativeAbiVersion, 1280, 720, 2.0f);
  const jlong handle = Java_com_poko_client_PokoNativeBridge_nativeCreate(
      nullptr, nullptr, reinterpret_cast<jbyteArray>(good_cfg));
  check(handle != 0, "FAIL: valid config must create non-zero native handle");
  check(Java_com_poko_client_PokoNativeBridge_nativeLastError(nullptr, nullptr) ==
            kJniOk,
        "FAIL: valid create must clear last error");
  check(Java_com_poko_client_PokoNativeBridge_nativeIsValidHandle(nullptr, nullptr, handle) ==
            JNI_TRUE,
        "FAIL: created handle must validate as live");

  auto* ptr = from_jlong(handle);
  check(ptr != nullptr && ptr->width == 1280 && ptr->height == 720 &&
            ptr->dpi_scale == 2.0f,
        "FAIL: handle must store decoded config");

  // Destroy invalidates handle; double destroy and null destroy are safe no-ops.
  Java_com_poko_client_PokoNativeBridge_nativeDestroy(nullptr, nullptr, handle);
  check(Java_com_poko_client_PokoNativeBridge_nativeIsValidHandle(nullptr, nullptr, handle) ==
            JNI_FALSE,
        "FAIL: destroyed handle must no longer validate");
  Java_com_poko_client_PokoNativeBridge_nativeDestroy(nullptr, nullptr, handle);
  Java_com_poko_client_PokoNativeBridge_nativeDestroy(nullptr, nullptr, 0);

  if (failures > 0) {
    std::printf("FAIL: %d SHL-15 JNI handle check(s) failed\n", failures);
    return 1;
  }
  std::puts("OK: all SHL-15 Android JNI handle checks passed");
}

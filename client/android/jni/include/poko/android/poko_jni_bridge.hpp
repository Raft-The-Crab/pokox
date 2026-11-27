// SHL-15: Android JNI handle lifecycle and native bridge exports.
#pragma once

#include "poko/android/jni_compat.hpp"

#include <cstddef>
#include <cstdint>
#include <string>

namespace poko::android {

inline constexpr std::uint32_t kNativeAbiVersion = 1;

inline constexpr std::int32_t kJniOk = 0;
inline constexpr std::int32_t kJniErrorNull = -1;
inline constexpr std::int32_t kJniErrorInvalidConfig = -2;
inline constexpr std::int32_t kJniErrorException = -3;
inline constexpr std::int32_t kJniErrorAbiMismatch = -4;

struct NativeEngineConfig {
  std::uint32_t abi_version = kNativeAbiVersion;
  std::uint32_t width = 1280;
  std::uint32_t height = 720;
  float dpi_scale = 1.0f;
};

struct NativeEngineHandle {
  std::uint32_t magic = 0x504F4B4Fu;  // "POKO"
  std::uint32_t abi_version = kNativeAbiVersion;
  std::uint32_t width = 1280;
  std::uint32_t height = 720;
  float dpi_scale = 1.0f;
  bool paused = false;
  bool has_surface = false;
  void* native_window = nullptr;
  void* egl_state = nullptr;
  std::uint64_t frame_count = 0;
  std::uint64_t input_count = 0;
  std::int32_t last_input_kind = -1;
  float last_input_x = 0.0f;
  float last_input_y = 0.0f;
  std::string auth_token;
};

[[nodiscard]] jlong create_native_handle(const std::uint8_t* config_bytes,
                                         std::size_t config_len,
                                         std::int32_t* out_error = nullptr) noexcept;
void destroy_native_handle(jlong handle) noexcept;
[[nodiscard]] NativeEngineHandle* from_jlong(jlong handle) noexcept;
[[nodiscard]] std::int32_t last_jni_error() noexcept;

}  // namespace poko::android

extern "C" {

JNIEXPORT jlong JNICALL Java_com_poko_client_PokoNativeBridge_nativeCreate(
    JNIEnv* env, jclass clazz, jbyteArray config_bytes);

JNIEXPORT jint JNICALL Java_com_poko_client_PokoNativeBridge_nativeLastError(
    JNIEnv* env, jclass clazz);

JNIEXPORT void JNICALL Java_com_poko_client_PokoNativeBridge_nativeDestroy(
    JNIEnv* env, jclass clazz, jlong handle);

JNIEXPORT jboolean JNICALL Java_com_poko_client_PokoNativeBridge_nativeIsValidHandle(
    JNIEnv* env, jclass clazz, jlong handle);

JNIEXPORT jint JNICALL Java_com_poko_client_PokoNativeBridge_nativeSetSurface(
    JNIEnv* env, jclass clazz, jlong handle, jobject surface);

JNIEXPORT jint JNICALL Java_com_poko_client_PokoNativeBridge_nativeFrame(
    JNIEnv* env, jclass clazz, jlong handle, jdouble dt);

JNIEXPORT jint JNICALL Java_com_poko_client_PokoNativeBridge_nativeInput(
    JNIEnv* env,
    jclass clazz,
    jlong handle,
    jint kind,
    jfloat x,
    jfloat y,
    jint button_or_key,
    jint pressed);

JNIEXPORT jlong JNICALL Java_com_poko_client_PokoNativeBridge_nativeFrameCount(
    JNIEnv* env, jclass clazz, jlong handle);

JNIEXPORT jlong JNICALL Java_com_poko_client_PokoNativeBridge_nativeInputCount(
    JNIEnv* env, jclass clazz, jlong handle);

JNIEXPORT jint JNICALL Java_com_poko_client_PokoNativeBridge_nativePause(
    JNIEnv* env, jclass clazz, jlong handle);

JNIEXPORT jint JNICALL Java_com_poko_client_PokoNativeBridge_nativeResume(
    JNIEnv* env, jclass clazz, jlong handle);

JNIEXPORT jboolean JNICALL Java_com_poko_client_PokoNativeBridge_nativeIsPaused(
    JNIEnv* env, jclass clazz, jlong handle);

}  // extern "C"

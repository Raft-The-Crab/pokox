#include "poko/android/poko_jni_bridge.hpp"

#include <atomic>
#include <cmath>
#include <cstring>
#include <memory>
#include <mutex>
#include <unordered_set>

#if defined(__ANDROID__)
#include <EGL/egl.h>
#include <GLES3/gl3.h>
#include <android/native_window_jni.h>
#endif

namespace poko::android {

namespace {

thread_local std::int32_t g_last_error = kJniOk;

std::mutex& registry_mutex() {
  static std::mutex m;
  return m;
}

std::unordered_set<NativeEngineHandle*>& live_handles() {
  static std::unordered_set<NativeEngineHandle*> handles;
  return handles;
}

void set_error(std::int32_t err, std::int32_t* out_error) noexcept {
  g_last_error = err;
  if (out_error) *out_error = err;
}

// Minimal deterministic config decoder: 16-byte little-endian header
// [abi_version:u32, width:u32, height:u32, dpi_scale:f32].
bool decode_config(const std::uint8_t* bytes,
                   std::size_t len,
                   NativeEngineConfig& out,
                   std::int32_t& out_err) noexcept {
  if (!bytes) {
    out_err = kJniErrorNull;
    return false;
  }
  if (len != 16) {
    out_err = kJniErrorInvalidConfig;
    return false;
  }
  std::memcpy(&out.abi_version, bytes + 0, 4);
  std::memcpy(&out.width, bytes + 4, 4);
  std::memcpy(&out.height, bytes + 8, 4);
  std::memcpy(&out.dpi_scale, bytes + 12, 4);
  if (out.abi_version != kNativeAbiVersion) {
    out_err = kJniErrorAbiMismatch;
    return false;
  }
  if (out.width == 0 || out.height == 0 || !(out.dpi_scale > 0.0f)) {
    out_err = kJniErrorInvalidConfig;
    return false;
  }
  out_err = kJniOk;
  return true;
}

}  // namespace

jlong create_native_handle(const std::uint8_t* config_bytes,
                           std::size_t config_len,
                           std::int32_t* out_error) noexcept {
  try {
    NativeEngineConfig cfg{};
    std::int32_t err = kJniOk;
    if (!decode_config(config_bytes, config_len, cfg, err)) {
      set_error(err, out_error);
      return 0;
    }
    auto handle = std::make_unique<NativeEngineHandle>();
    handle->abi_version = cfg.abi_version;
    handle->width = cfg.width;
    handle->height = cfg.height;
    handle->dpi_scale = cfg.dpi_scale;
    NativeEngineHandle* raw = handle.release();
    {
      std::lock_guard<std::mutex> lock(registry_mutex());
      live_handles().insert(raw);
    }
    set_error(kJniOk, out_error);
    return reinterpret_cast<jlong>(raw);
  } catch (...) {
    set_error(kJniErrorException, out_error);
    return 0;
  }
}

void release_surface_resources(NativeEngineHandle* ptr) noexcept {
#if defined(__ANDROID__)
  if (ptr->egl_state) {
    struct EglState {
      EGLDisplay display = EGL_NO_DISPLAY;
      EGLContext context = EGL_NO_CONTEXT;
      EGLSurface surface = EGL_NO_SURFACE;
    };
    auto* egl = static_cast<EglState*>(ptr->egl_state);
    if (egl->display != EGL_NO_DISPLAY) {
      eglMakeCurrent(egl->display, EGL_NO_SURFACE, EGL_NO_SURFACE, EGL_NO_CONTEXT);
      if (egl->surface != EGL_NO_SURFACE) eglDestroySurface(egl->display, egl->surface);
      if (egl->context != EGL_NO_CONTEXT) eglDestroyContext(egl->display, egl->context);
      eglTerminate(egl->display);
    }
    delete egl;
    ptr->egl_state = nullptr;
  }
  if (ptr->native_window) {
    ANativeWindow_release(static_cast<ANativeWindow*>(ptr->native_window));
    ptr->native_window = nullptr;
  }
#else
  ptr->native_window = nullptr;
  ptr->egl_state = nullptr;
#endif
  ptr->has_surface = false;
}

void destroy_native_handle(jlong handle) noexcept {
  try {
    if (handle == 0) return;
    auto* ptr = reinterpret_cast<NativeEngineHandle*>(handle);
    bool removed = false;
    {
      std::lock_guard<std::mutex> lock(registry_mutex());
      removed = live_handles().erase(ptr) > 0;
    }
    if (removed) {
      release_surface_resources(ptr);
      ptr->magic = 0;
      delete ptr;
    }
  } catch (...) {
    g_last_error = kJniErrorException;
  }
}

NativeEngineHandle* from_jlong(jlong handle) noexcept {
  if (handle == 0) return nullptr;
  auto* ptr = reinterpret_cast<NativeEngineHandle*>(handle);
  std::lock_guard<std::mutex> lock(registry_mutex());
  if (live_handles().find(ptr) == live_handles().end()) return nullptr;
  return ptr->magic == 0x504F4B4Fu ? ptr : nullptr;
}

std::int32_t last_jni_error() noexcept { return g_last_error; }

}  // namespace poko::android

extern "C" {

JNIEXPORT jlong JNICALL Java_com_poko_client_PokoNativeBridge_nativeCreate(
    JNIEnv* env, jclass, jbyteArray config_bytes) {
  try {
    if (!config_bytes) {
      poko::android::create_native_handle(nullptr, 0, nullptr);
      return 0;
    }
#if defined(__ANDROID__) || defined(POKO_USE_REAL_JNI)
    if (!env) return 0;
    const jsize len = env->GetArrayLength(config_bytes);
    if (len <= 0) {
      return poko::android::create_native_handle(nullptr, 0, nullptr);
    }
    jbyte* elems = env->GetByteArrayElements(config_bytes, nullptr);
    if (!elems) return 0;
    const jlong out = poko::android::create_native_handle(
        reinterpret_cast<const std::uint8_t*>(elems), static_cast<std::size_t>(len));
    env->ReleaseByteArrayElements(config_bytes, elems, JNI_ABORT);
    return out;
#else
    // Unit-test path without a JVM: jbyteArray points to a 16-byte config buffer.
    (void)env;
    return poko::android::create_native_handle(
        reinterpret_cast<const std::uint8_t*>(config_bytes), 16);
#endif
  } catch (...) {
    return 0;
  }
}

JNIEXPORT jint JNICALL Java_com_poko_client_PokoNativeBridge_nativeLastError(
    JNIEnv*, jclass) {
  return poko::android::last_jni_error();
}

JNIEXPORT void JNICALL Java_com_poko_client_PokoNativeBridge_nativeDestroy(
    JNIEnv*, jclass, jlong handle) {
  poko::android::destroy_native_handle(handle);
}

JNIEXPORT jboolean JNICALL Java_com_poko_client_PokoNativeBridge_nativeIsValidHandle(
    JNIEnv*, jclass, jlong handle) {
  return poko::android::from_jlong(handle) != nullptr ? JNI_TRUE : JNI_FALSE;
}

JNIEXPORT jint JNICALL Java_com_poko_client_PokoNativeBridge_nativeSetSurface(
    JNIEnv* env, jclass, jlong handle, jobject surface) {
  try {
    auto* ptr = poko::android::from_jlong(handle);
    if (!ptr) return poko::android::kJniErrorNull;
    poko::android::release_surface_resources(ptr);
    if (!surface) return poko::android::kJniOk;
#if defined(__ANDROID__)
    ANativeWindow* win = ANativeWindow_fromSurface(env, surface);
    if (!win) return poko::android::kJniErrorInvalidConfig;
    ptr->native_window = win;
    ptr->width = static_cast<std::uint32_t>(ANativeWindow_getWidth(win));
    ptr->height = static_cast<std::uint32_t>(ANativeWindow_getHeight(win));
    struct EglState {
      EGLDisplay display = EGL_NO_DISPLAY;
      EGLContext context = EGL_NO_CONTEXT;
      EGLSurface surface = EGL_NO_SURFACE;
    };
    auto* egl = new EglState{};
    egl->display = eglGetDisplay(EGL_DEFAULT_DISPLAY);
    if (egl->display != EGL_NO_DISPLAY && eglInitialize(egl->display, nullptr, nullptr)) {
      const EGLint cfg_attrs[] = {
          EGL_RENDERABLE_TYPE, EGL_OPENGL_ES3_BIT,
          EGL_SURFACE_TYPE, EGL_WINDOW_BIT,
          EGL_RED_SIZE, 8, EGL_GREEN_SIZE, 8, EGL_BLUE_SIZE, 8, EGL_ALPHA_SIZE, 8,
          EGL_NONE};
      EGLConfig cfg = nullptr;
      EGLint num_cfg = 0;
      if (eglChooseConfig(egl->display, cfg_attrs, &cfg, 1, &num_cfg) && num_cfg > 0) {
        const EGLint ctx_attrs[] = {EGL_CONTEXT_CLIENT_VERSION, 3, EGL_NONE};
        egl->context = eglCreateContext(egl->display, cfg, EGL_NO_CONTEXT, ctx_attrs);
        egl->surface = eglCreateWindowSurface(egl->display, cfg, win, nullptr);
      }
    }
    ptr->egl_state = egl;
#else
    (void)env;
    ptr->native_window = surface;
#endif
    ptr->has_surface = true;
    return poko::android::kJniOk;
  } catch (...) {
    return poko::android::kJniErrorException;
  }
}

JNIEXPORT jint JNICALL Java_com_poko_client_PokoNativeBridge_nativeFrame(
    JNIEnv*, jclass, jlong handle, jdouble dt) {
  try {
    auto* ptr = poko::android::from_jlong(handle);
    if (!ptr) return poko::android::kJniErrorNull;
    if (ptr->paused) return poko::android::kJniOk;
    if (!(dt >= 0.0)) return poko::android::kJniErrorInvalidConfig;
    ++ptr->frame_count;
#if defined(__ANDROID__)
    if (ptr->egl_state) {
      struct EglState {
        EGLDisplay display;
        EGLContext context;
        EGLSurface surface;
      };
      auto* egl = static_cast<EglState*>(ptr->egl_state);
      if (egl->display != EGL_NO_DISPLAY && egl->surface != EGL_NO_SURFACE &&
          egl->context != EGL_NO_CONTEXT) {
        if (eglMakeCurrent(egl->display, egl->surface, egl->surface, egl->context)) {
          const float pulse = 0.12f + 0.08f * std::sin(static_cast<float>(ptr->frame_count) * 0.05f);
          glViewport(0, 0, static_cast<GLsizei>(ptr->width), static_cast<GLsizei>(ptr->height));
          glClearColor(0.07f, pulse, 0.22f, 1.0f);
          glClear(GL_COLOR_BUFFER_BIT);
          eglSwapBuffers(egl->display, egl->surface);
        }
      }
    }
#endif
    return poko::android::kJniOk;
  } catch (...) {
    return poko::android::kJniErrorException;
  }
}

JNIEXPORT jint JNICALL Java_com_poko_client_PokoNativeBridge_nativeInput(
    JNIEnv*, jclass, jlong handle, jint kind, jfloat x, jfloat y, jint, jint) {
  try {
    auto* ptr = poko::android::from_jlong(handle);
    if (!ptr) return poko::android::kJniErrorNull;
    ++ptr->input_count;
    ptr->last_input_kind = kind;
    ptr->last_input_x = x;
    ptr->last_input_y = y;
    return poko::android::kJniOk;
  } catch (...) {
    return poko::android::kJniErrorException;
  }
}

JNIEXPORT jlong JNICALL Java_com_poko_client_PokoNativeBridge_nativeFrameCount(
    JNIEnv*, jclass, jlong handle) {
  auto* ptr = poko::android::from_jlong(handle);
  return ptr ? static_cast<jlong>(ptr->frame_count) : 0;
}

JNIEXPORT jlong JNICALL Java_com_poko_client_PokoNativeBridge_nativeInputCount(
    JNIEnv*, jclass, jlong handle) {
  auto* ptr = poko::android::from_jlong(handle);
  return ptr ? static_cast<jlong>(ptr->input_count) : 0;
}

JNIEXPORT jint JNICALL Java_com_poko_client_PokoNativeBridge_nativePause(
    JNIEnv*, jclass, jlong handle) {
  try {
    auto* ptr = poko::android::from_jlong(handle);
    if (!ptr) return poko::android::kJniErrorNull;
    ptr->paused = true;
    return poko::android::kJniOk;
  } catch (...) {
    return poko::android::kJniErrorException;
  }
}

JNIEXPORT jint JNICALL Java_com_poko_client_PokoNativeBridge_nativeResume(
    JNIEnv*, jclass, jlong handle) {
  try {
    auto* ptr = poko::android::from_jlong(handle);
    if (!ptr) return poko::android::kJniErrorNull;
    ptr->paused = false;
    return poko::android::kJniOk;
  } catch (...) {
    return poko::android::kJniErrorException;
  }
}

JNIEXPORT jboolean JNICALL Java_com_poko_client_PokoNativeBridge_nativeIsPaused(
    JNIEnv*, jclass, jlong handle) {
  auto* ptr = poko::android::from_jlong(handle);
  return (ptr && ptr->paused) ? JNI_TRUE : JNI_FALSE;
}

}  // extern "C"

#pragma once

#include <cstdint>
#include <string_view>

namespace poko::platform {

// One presentation window; input, audio and timers remain future work.
// Graphics intent is explicit; device/surface creation belongs to the RHI.
enum class PlatformError : std::uint8_t {
  none,
  not_initialized,
  already_initialized,
  window_exists,
  invalid_window_config,
  platform_failure,
  window_not_created,
};

// Window intent only: this neither creates a GPU device nor selects a fallback.
enum class WindowGraphicsApi : std::uint8_t { none, vulkan, opengl };

struct WindowConfig {
  // UTF-8; create_window must copy any title it needs after the call returns.
  std::string_view title;
  std::uint32_t width;   // Initial logical width; must be nonzero.
  std::uint32_t height;  // Initial logical height; must be nonzero.
  // Existing three-field callers keep the plain-window behavior.
  WindowGraphicsApi graphics_api = WindowGraphicsApi::none;
};

struct WindowSize {
  // Logical units and drawable pixels may differ on high-DPI displays.
  // Zero dimensions may occur while minimized or without a drawable surface.
  std::uint32_t logical_width = 0;
  std::uint32_t logical_height = 0;
  std::uint32_t pixel_width = 0;
  std::uint32_t pixel_height = 0;
};

enum class EventType : std::uint8_t {
  none,
  quit_requested,
  window_close_requested,
  window_resized,
  mouse_motion,   // relative movement while a button is held (orbit/drag)
  mouse_button,   // press/release; button is SDL-style button index (1=left)
  mouse_wheel,    // vertical scroll; `wheel` is signed detents
};

struct Event {
  EventType type = EventType::none;
  // Meaningful only for window_resized; otherwise zero-initialized.
  WindowSize size{};
  // mouse_motion: relative pixel deltas. mouse_button: `button` + `pressed`.
  // mouse_wheel: signed `wheel` detents (positive = away/up).
  float dx = 0.f, dy = 0.f;
  std::uint8_t button = 0;
  bool pressed = false;
  float wheel = 0.f;
};

// Platform operations run on the owning thread (normally the main thread).
// No backend-specific or renderer types cross this boundary. Implementations
// report errors rather than allowing exceptions to cross the interface.
class IPlatform {
 public:
  virtual ~IPlatform() = default;
  IPlatform(const IPlatform&) = delete;
  IPlatform& operator=(const IPlatform&) = delete;
  IPlatform(IPlatform&&) = delete;
  IPlatform& operator=(IPlatform&&) = delete;

  // Initialize platform services; call once before window or event operations.
  [[nodiscard]] virtual PlatformError initialize() noexcept = 0;
  // Release the window and services; safe to call repeatedly or after failure.
  virtual void shutdown() noexcept = 0;
  // Create the sole window; failure leaves no newly created window.
  [[nodiscard]] virtual PlatformError create_window(const WindowConfig& config) noexcept = 0;
  // Destroy the window if present; safe to call repeatedly.
  virtual void destroy_window() noexcept = 0;
  // Query actual dimensions, including immediately after creation. On error,
  // leave output unchanged. Zero pixels mean no drawable area, not failure.
  // Release renderer/surface resources before destroy_window or shutdown.
  [[nodiscard]] virtual PlatformError get_window_size(WindowSize& size) noexcept = 0;
  // Pump OS messages and return one queued event, or false if none are pending.
  // A close request is informational: the caller decides when to destroy it.
  // Requires successful initialization; on false the output is unchanged.
  [[nodiscard]] virtual bool poll_event(Event& event) noexcept = 0;

 protected:
  IPlatform() = default;
};

}  // namespace poko::platform

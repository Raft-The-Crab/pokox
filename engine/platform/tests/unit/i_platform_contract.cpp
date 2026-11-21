#include "poko/platform/window/i_platform.hpp"

#include <array>
#include <climits>
#include <type_traits>
#include <utility>

using namespace poko::platform;
static_assert(std::is_abstract_v<IPlatform>);
static_assert(std::has_virtual_destructor_v<IPlatform>);
static_assert(!std::is_copy_constructible_v<IPlatform>);
static_assert(!std::is_copy_assignable_v<IPlatform>);
static_assert(!std::is_move_constructible_v<IPlatform>);
static_assert(!std::is_move_assignable_v<IPlatform>);
static_assert(noexcept(std::declval<IPlatform&>().get_window_size(std::declval<WindowSize&>())));
static_assert(WindowConfig{"plain", 1, 1}.graphics_api == WindowGraphicsApi::none);
static_assert(noexcept(std::declval<IPlatform&>().shutdown()));
static_assert(noexcept(std::declval<IPlatform&>().destroy_window()));
static_assert(noexcept(std::declval<IPlatform&>().create_window(std::declval<const WindowConfig&>())));
static_assert(noexcept(std::declval<IPlatform&>().initialize()));
static_assert(noexcept(std::declval<IPlatform&>().poll_event(std::declval<Event&>())));

// A test double validates interface usage, not operating-system behavior.
class TestPlatform final : public IPlatform {
 public:
  PlatformError initialize() noexcept override {
    if (initialized_) return PlatformError::already_initialized;
    initialized_ = true;
    return PlatformError::none;
  }
  void shutdown() noexcept override { destroy_window(); initialized_ = false; }
  PlatformError create_window(const WindowConfig& config) noexcept override {
    if (!initialized_) return PlatformError::not_initialized;
    if (window_) return PlatformError::window_exists;
    if (config.width == 0 || config.height == 0 || config.width > INT_MAX ||
        config.height > INT_MAX || config.title.find('\0') != std::string_view::npos ||
        (config.graphics_api != WindowGraphicsApi::none && config.graphics_api != WindowGraphicsApi::vulkan))
      return PlatformError::invalid_window_config;
    window_ = true;
    return PlatformError::none;
  }
  void destroy_window() noexcept override { window_ = false; }
  PlatformError get_window_size(WindowSize& size) noexcept override {
    if (!initialized_) return PlatformError::not_initialized;
    if (!window_) return PlatformError::window_not_created;
    size = {800, 600, 1600, 1200};
    return PlatformError::none;
  }
  bool poll_event(Event& event) noexcept override {
    if (!initialized_ || next_ == events_.size()) return false;
    event = events_[next_++];
    return true;
  }
 private:
  bool initialized_ = false;
  bool window_ = false;
  std::size_t next_ = 0;
  std::array<Event, 2> events_{{
      {EventType::window_resized, {800, 600, 1600, 1200}},
      {EventType::window_close_requested, {}},
  }};
};

int main() {
  TestPlatform fake;
  IPlatform& platform = fake;
  const WindowConfig valid{"PokoX", 800, 600};
  WindowSize size{1, 2, 3, 4};
  if (platform.get_window_size(size) != PlatformError::not_initialized || size.pixel_height != 4) return 14;
  if (platform.create_window(valid) != PlatformError::not_initialized) return 1;
  if (platform.initialize() != PlatformError::none) return 2;
  if (platform.initialize() != PlatformError::already_initialized) return 3;
  if (platform.get_window_size(size) != PlatformError::window_not_created || size.pixel_height != 4) return 15;
  if (platform.create_window({"bad", 0, 600}) != PlatformError::invalid_window_config) return 4;
  if (platform.create_window(valid) != PlatformError::none) return 5;
  if (platform.create_window(valid) != PlatformError::window_exists) return 6;
  if (platform.get_window_size(size) != PlatformError::none || size.pixel_width != 1600) return 16;
  Event event{};
  if (!platform.poll_event(event) || event.type != EventType::window_resized ||
      event.size.logical_width != 800 || event.size.pixel_width != 1600) return 7;
  if (!platform.poll_event(event) || event.type != EventType::window_close_requested ||
      event.size.pixel_width != 0) return 8;
  if (platform.poll_event(event) || event.type != EventType::window_close_requested) return 9;
  platform.destroy_window();
  platform.destroy_window();
  if (platform.create_window(valid) != PlatformError::none) return 11;
  platform.shutdown();
  platform.shutdown();
  if (platform.create_window(valid) != PlatformError::not_initialized) return 10;
  if (platform.initialize() != PlatformError::none) return 12;
  if (platform.create_window(valid) != PlatformError::none) return 13;
  platform.shutdown();
  return 0;
}

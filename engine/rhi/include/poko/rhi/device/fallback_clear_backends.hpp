#pragma once
#include "poko/rhi/device/clear_backend_selection.hpp"
#include "poko/rhi/device/opengl_clear_renderer.hpp"
#include "poko/rhi/device/vulkan_clear_renderer.hpp"
#include "poko/rhi/debug/vulkan_diagnostics.hpp"
#include "poko/platform/window/sdl_platform.hpp"
namespace poko::rhi {
// Experimental desktop demo adapters, not a general engine RHI. Main thread.
class VulkanClearBackend final : public ClearBackend {
 public:
  explicit VulkanClearBackend(bool enabled = true, bool validation = true) noexcept : enabled_(enabled), validation_(validation) {}
  [[nodiscard]] RenderError initialize() noexcept override;
  [[nodiscard]] RenderError clear_and_present(const std::array<float,4>& color) noexcept override;
  [[nodiscard]] bool shutdown() noexcept override;
  [[nodiscard]] bool poll_event(platform::Event& event) noexcept { return window_.poll_event(event); }
 private:
  bool enabled_, validation_, cleanup_error_ = false;
  platform::SdlPlatform window_;
  VulkanDiagnostics diagnostics_;
  VulkanClearRenderer renderer_;
};
class OpenGLClearBackend final : public ClearBackend {
 public:
  explicit OpenGLClearBackend(bool validation = true) noexcept : validation_(validation) {}
  [[nodiscard]] RenderError initialize() noexcept override;
  [[nodiscard]] RenderError clear_and_present(const std::array<float,4>& color) noexcept override;
  [[nodiscard]] bool shutdown() noexcept override;
  [[nodiscard]] bool poll_event(platform::Event& event) noexcept { return window_.poll_event(event); }
 private:
  bool validation_, cleanup_error_ = false;
  platform::SdlPlatform window_;
  VulkanDiagnostics diagnostics_;
  OpenGLClearRenderer renderer_;
};
}

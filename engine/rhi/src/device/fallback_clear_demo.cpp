#include "poko/rhi/device/fallback_clear_backends.hpp"
#include "poko/foundation/config.hpp"
#include "poko/foundation/config_logging.hpp"
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <array>
#include <charconv>
#include <chrono>
#include <cstdint>
#include <cstdio>
#include <string>
#include <string_view>
#include <system_error>
int main(int argc, char** argv) {
  using namespace poko;
  std::uint32_t limit=0; bool force_gl=false;
  std::string config_path;
  config::Overrides overrides;
  for (int i=1;i<argc;++i) {
    const std::string_view arg{argv[i]};
    if (arg=="--force-opengl") { force_gl=true; continue; }
    if (arg=="--no-validation") { overrides.validation=false; overrides.validation_set=true; continue; }
    if (arg=="--config" && i+1<argc) { config_path=argv[++i]; continue; }
    if (arg=="--frames" && i+1<argc) {
      const std::string_view value{argv[++i]};
      const auto parsed=std::from_chars(value.data(),value.data()+value.size(),limit);
      if (parsed.ec==std::errc{} && parsed.ptr==value.data()+value.size() && limit) continue;
    }
    std::fputs("Usage: pokox_fallback_clear [--frames positive-integer] [--force-opengl] [--no-validation] [--config file.cbor]\n",stderr); return 2;
  }
  const auto loaded=config::resolve(config_path,overrides);
  if (loaded.error) {
    std::fprintf(stderr,"Config load failed: %s (%s)\n",loaded.detail.c_str(),loaded.error.message().c_str());
    return 2;
  }
  for (const auto& key : loaded.unknown_keys)
    std::fprintf(stderr,"config: unknown key ignored: %s\n",key.c_str());
  const auto& settings=loaded.config;
  config::LogGuard log_guard{settings};
  rhi::VulkanClearBackend vulkan{!force_gl,settings.validation,settings.adapter_id,
                                settings.window_width,settings.window_height};
  rhi::OpenGLClearBackend opengl{settings.validation,
                                 settings.window_width,settings.window_height};
  rhi::ClearBackendSelection selector{vulkan,opengl};
  const auto startup=selector.start();
  if (startup.status!=rhi::StartStatus::success) {
    std::fprintf(stderr,"No backend started: status=%u Vulkan=%u OpenGL=%u fallback_attempted=%d\n",static_cast<unsigned>(startup.status),static_cast<unsigned>(startup.primary_error),static_cast<unsigned>(startup.fallback_error),startup.fallback_attempted);
    return 1;
  }
  const bool is_gl=startup.selected==rhi::SelectedBackend::fallback;
  std::printf("Selected %s; desktop resize is experimental. Device-loss recovery is not implemented.\n",is_gl ? "OpenGL" : "Vulkan");
  constexpr std::array<float,4> blue{0.035f,0.12f,0.28f,1.f};
  std::uint32_t frames=0; int code=0; bool running=true;
  while (running) {
    const auto tick=std::chrono::steady_clock::now();
    platform::Event event;
    while ((is_gl ? opengl.poll_event(event) : vulkan.poll_event(event))) {
      if (event.type==platform::EventType::quit_requested || event.type==platform::EventType::window_close_requested) running=false;
    }
    if (!running) break;
    const auto result=selector.clear_and_present(blue);
    if (result==rhi::RenderError::not_drawable) { SDL_Delay(20); continue; }
    if (result==rhi::RenderError::resize_attempted) continue;
    if (result!=rhi::RenderError::none) { std::fprintf(stderr,"Render stopped: error=%u\n",static_cast<unsigned>(result)); code=result==rhi::RenderError::resize_required ? 2 : 1; break; }
    if (frames!=UINT32_MAX) ++frames;
    if (limit && frames>=limit) break;
    // Pace to ~60 fps: unthrottled submission can outrun swapchain semaphore
    // reuse on some drivers (VUID-vkAcquireNextImageKHR-semaphore-01779).
    const auto spent=std::chrono::steady_clock::now()-tick;
    constexpr auto budget=std::chrono::milliseconds(16);
    if (spent<budget) SDL_Delay(static_cast<std::uint32_t>(
        std::chrono::duration_cast<std::chrono::milliseconds>(budget-spent).count()));
  }
  if (!selector.shutdown()) { std::fputs("Backend cleanup failed.\n",stderr); code=1; }
  if (limit && frames<limit && !code) code=2;
  std::printf("POKO_FALLBACK_RESULT backend=%s submitted=%u validation_requested=%s\n",is_gl ? "opengl" : "vulkan",frames,settings.validation ? "true" : "false");
  return code;
}

#include "poko/rhi/debug/vulkan_diagnostics_filter.hpp"
#include <string_view>
namespace poko::rhi {
bool is_environment_layer_version_warning(const std::string_view message) noexcept {
  // "Layer 'VK_LAYER_KHRONOS_validation' version (1.3.275) is less than the
  //  header version (1.3.290)." — the layer is older than the SDK headers.
  constexpr auto prefix=std::string_view("Layer 'VK_LAYER_KHRONOS_validation' version (");
  constexpr auto marker=std::string_view("is less than the header version (");
  return message.starts_with(prefix) && message.find(marker)!=std::string_view::npos;
}
}

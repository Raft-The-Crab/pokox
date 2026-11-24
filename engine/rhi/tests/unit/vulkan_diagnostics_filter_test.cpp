#include "poko/rhi/debug/vulkan_diagnostics_filter.hpp"
#include <iostream>
#include <string_view>
using poko::rhi::is_environment_layer_version_warning;
int main() {
  int failures=0;
  const auto check=[&](std::string_view text,bool expected) {
    if (is_environment_layer_version_warning(text)!=expected) {
      std::cerr << "wrong classification: " << text << '\n'; ++failures;
    }
  };
  check("Layer 'VK_LAYER_KHRONOS_validation' version (1.3.275) is less than the header version (1.3.290).",true);
  check("Layer 'VK_LAYER_KHRONOS_validation' version (1.2.1) is less than the header version (1.3.290).",true);
  check("Layer 'VK_LAYER_other' version (1.3.275) is less than the header version (1.3.290).",false);
  check("Layer 'VK_LAYER_KHRONOS_validation' version (1.3.290) is greater than the header version (1.3.275).",false);
  check("Layer 'VK_LAYER_KHRONOS_validation' version (1.3.275) is less than the header version",false);
  check("Layer 'VK_LAYER_KHRONOS_validation' version (1.3.275) is less than the header version (1.3.290)",true);
  check("validation layer warning",false);
  check("",false);
  return failures ? 1 : 0;
}

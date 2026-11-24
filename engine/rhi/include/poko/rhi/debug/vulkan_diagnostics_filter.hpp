#pragma once
#include <string_view>
namespace poko::rhi {
// Narrow allowlist for a known host-environment mismatch: Ubuntu 24.04 ships
// validation layer 1.3.275 while the pinned Diligent headers are 1.3.290.
// Diligent reports this once as a warning even though it says nothing about
// the application. Only this exact message is ignored; all other warnings,
// and every error, still count and fail the demo. The message is always logged.
[[nodiscard]] bool is_environment_layer_version_warning(std::string_view message) noexcept;
}

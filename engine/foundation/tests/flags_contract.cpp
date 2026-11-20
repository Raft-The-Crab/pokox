#include "build_flags.hpp"

static_assert(poko::build::imgui == static_cast<bool>(EXPECT_IMGUI));
static_assert(poko::build::d3d12 == static_cast<bool>(EXPECT_D3D12));
static_assert(poko::build::debug == static_cast<bool>(EXPECT_DEBUG));

int main() { return 0; }

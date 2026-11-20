#pragma once

// Values are supplied by the poko_build_options CMake target.
#if !defined(POKO_IMGUI) || !defined(POKO_D3D12) || !defined(POKO_DEBUG)
#error "PokoX build flag definitions are missing"
#endif
#if (POKO_IMGUI != 0 && POKO_IMGUI != 1) || \
    (POKO_D3D12 != 0 && POKO_D3D12 != 1) || \
    (POKO_DEBUG != 0 && POKO_DEBUG != 1)
#error "PokoX build flags must be 0 or 1"
#endif

namespace poko::build {
#if POKO_IMGUI
inline constexpr bool imgui = true;
#else
inline constexpr bool imgui = false;
#endif
#if POKO_D3D12
inline constexpr bool d3d12 = true;
#else
inline constexpr bool d3d12 = false;
#endif
#if POKO_DEBUG
inline constexpr bool debug = true;
#else
inline constexpr bool debug = false;
#endif
} // namespace poko::build

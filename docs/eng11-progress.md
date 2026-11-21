# ENG-11 — ImGui pass in the frame graph

The owner requested ENG-11 after ENG-10. This is an opt-in desktop Vulkan prototype, not a production UI system or a waiver of outstanding ENG-01–10 acceptance gates.

## Implementation

- `POKO_WITH_IMGUI_DEMO=ON` builds `pokox_imgui_demo` plus the `imgui.vert`/`imgui.frag` SPIR-V artifacts through the existing ENG-07 host-glslang path. It requires `POKO_WITH_DEPENDENCIES=ON` (the `imgui` vcpkg package), `POKO_WITH_VULKAN_DEMO=ON` and `POKO_WITH_SHADER_ARTIFACTS=ON`. Dear ImGui 1.93.0 core is used; no platform/renderer backend ships with the vcpkg port, so the demo feeds `ImGuiIO` display size, delta time and mouse state directly from SDL.
- `engine/rhi/include/poko/rhi/device/vulkan_imgui_pass.hpp` + `src/device/vulkan_imgui_pass.cpp` add `VulkanImGuiPass`, which uploads and draws the current `ImGui::GetDrawData()` through Diligent inside an already-acquired frame. It does not clear, acquire or present. Only the Dear ImGui font atlas texture is supported; commands referencing any other `ImTextureID` fail rather than binding an arbitrary texture, and draw callbacks other than `ImDrawCallback_ResetRenderState` are rejected.
- The font atlas is built on the CPU before the first `NewFrame` (ImGui asserts `TexIsBuilt` otherwise); the pass uploads the cached RGBA32 pixels once as an immutable `TEX_FORMAT_RGBA8_UNORM` texture with a linear/clamp sampler attached to the texture view for the combined image sampler. A 16-byte dynamic uniform buffer carries the display-to-clip transform, refreshed per frame. Vertex/index data is streamed into dynamic vertex/index buffers that grow on demand; `ImDrawIdx` is 16-bit (`VT_UINT16`) and `BaseVertex` is `list base + cmd.VtxOffset`, matching official backend behavior for both `RendererHasVtxOffset` modes. Scissor rects come from `ImDrawCmd::ClipRect` scaled by `FramebufferScale`; alpha blending is enabled and depth is detached for the UI subpass.
- `VulkanTrianglePass` gained non-presenting `draw(device, context, chain, target[, color])` overloads so several passes can composite inside one `draw_and_present` callback; `draw_and_present` behavior is unchanged.
- The demo's frame graph has two nodes: `ui imgui` (CPU pass: SDL-fed IO update, `NewFrame`, demo window, `Render`; writes the logical `imgui draw data` resource) and `forward frame` (reads `imgui draw data`, writes `swapchain color`; its callback runs the triangle scene draw then the ImGui draw inside one acquire/present). The graph orders the UI frame before the composite GPU frame. The demo window shows FPS, a checkbox and instructions; the window is draggable with the mouse.

## Verification — Windows laptop (MSYS2 UCRT64, AMD Radeon iGPU)

- `POKO_WITH_IMGUI_DEMO=ON` configure + `pokox_imgui_demo` build: clean, no warnings in the new translation units.
- Real run, `--frames 120 --adapter 0 --no-validation`: `POKO_IMGUI_RESULT submitted=120 validation_requested=false graphics_errors=0 graphics_warnings=0` on the AMD Radeon GPU. The triangle scene renders with the ImGui demo window composited on top.
- **Visual acceptance (owner-verified on the Windows AMD GPU):** the "PokoX ImGui demo" window renders at the top-left above the triangle, is readable, draggable and resizable. Two rendering bugs were found and fixed during bring-up: (1) the `LayoutElement` aggregate initializers omitted the leading `HLSLSemantic` field, shifting every vertex-layout field by one and producing a corrupt input layout that silently rasterized nothing; (2) the display→clip transform initially copied `imgui_impl_vulkan`'s raw Vulkan y convention, but Diligent's swapchain presents y-up, so the UI rendered vertically flipped at the bottom — the y scale/translate are now negated accordingly. The scene shaders (`triangle`/`depth`/`uniform`) were also flipped at the owner's request to match the conventional orientation, and the X11 visual-test pixel samples were mirrored to match.
- After the fixes, `--frames 60` **with validation requested**: `submitted=60 graphics_errors=0 graphics_warnings=0`, and `ctest -R "imgui|triangle"`: 9/9 pass including `pokox_imgui_demo_missing_shader`, `pokox_imgui_demo_bad_args` and `pokox_imgui_demo_inputs` (bad SPIR-V rejected before window creation).
- With validation requested (`--frames 60`), the run initially reported `VUID-vkAcquireNextImageKHR-semaphore-01779`. Root cause: Diligent's swapchain acquire-fence wait bounds pending *acquires*, not the semaphore's pending *wait* operation inside the submitted command buffer, so a fast CPU can reuse the acquire semaphore while the GPU still waits on it. `VulkanClearRenderer` now calls `ISwapChain::SetMaximumFrameLatency(1)` at init and, only when validation is enabled, `IDeviceContext::WaitForIdle()` before each acquire — validation runs are diagnostic, so the synchronized path is acceptable there while the default fast path is unchanged. After the fix, `pokox_triangle` and `pokox_imgui_demo` each complete `--frames 60` with validation requested, 0 graphics errors/warnings. This also repairs the same latent race in the ENG-03/08/09/10 demos under validation; the fakes gained the new interface methods.
- ImGui draw-data indexing was verified empirically against ImGui 1.93.0 (`VtxOffset`/`IdxOffset`/`ElemCount`, `ImTextureRef`/`SetTexID`) before implementing the upload path.

## Reproduce / open work

```sh
cmake -B build-imgui -G Ninja -DCMAKE_TOOLCHAIN_FILE=<vcpkg>/scripts/buildsystems/vcpkg.cmake \
  -DPOKO_WITH_DEPENDENCIES=ON -DPOKO_WITH_SDL_PLATFORM=ON -DPOKO_WITH_VULKAN_DEMO=ON \
  -DPOKO_WITH_FALLBACK_DEMO=ON -DPOKO_WITH_SHADER_ARTIFACTS=ON \
  -DPOKO_WITH_TRIANGLE_DEMO=ON -DPOKO_WITH_DEPTH_DEMO=ON -DPOKO_WITH_UNIFORM_DEMO=ON \
  -DPOKO_WITH_IMGUI_DEMO=ON
ninja -C build-imgui pokox_imgui_demo
./build-imgui/pokox_imgui_demo --vertex build-imgui/shaders/Debug/triangle.vert.spv \
  --fragment build-imgui/shaders/Debug/triangle.frag.spv \
  --imgui-vertex build-imgui/shaders/Debug/imgui.vert.spv \
  --imgui-fragment build-imgui/shaders/Debug/imgui.frag.spv --adapter 0
```

Keyboard/text input, gamepad, multi-texture `ImTextureData` updates, `ImGuiBackendFlags_RendererHasTextures`, multi-viewport, backend-owned platform texture management, OpenGL/ES and Android ImGui paths, device-loss recovery and the ENG-12 F1 toggle/release strip are not implemented. The frame graph remains CPU-only; `imgui draw data` is a logical ordering token, not a managed GPU resource. Target-device, validation-layer, MSVC and Android acceptance remain open, as do all prior infrastructure and phase gates. ENG-12 (ImGui F1 toggle and release strip) is the next queued task and is not included here.

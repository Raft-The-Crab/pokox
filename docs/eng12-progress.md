# ENG-12 — ImGui F1 toggle and release strip

Built on ENG-11. Acceptance from the queue: *"Debug shows UI, release has no ImGui symbols."*

## Implementation

- `POKO_DEBUG` is the switch (it already existed as "compile debug-only feature paths" and is propagated as `POKO_DEBUG=0/1`).
- **F1 toggle (debug only):** the `ui imgui` frame-graph pass polls `SDL_GetKeyboardState` for `SDL_SCANCODE_F1` each frame and toggles `ui_enabled` on the rising edge, printing `ImGui UI shown/hidden (F1).` to stdout. When hidden, the pass still runs `NewFrame`/`Render` with no windows, so `ImGui::GetDrawData()` is empty and `VulkanImGuiPass::draw` early-outs — no stale draw data is ever presented.
- **Release strip:** `imgui_demo.cpp` wraps every ImGui include, context, IO update, window builder and pass registration in `#if POKO_DEBUG`. CMake compiles `vulkan_imgui_pass.cpp` and links `imgui::imgui` only when `POKO_DEBUG=ON`. In strip mode the graph is a single `forward frame` pass (scene only), `--imgui-*` args are still accepted for interface compatibility but unused, and the demo prints "release strip" at startup. `composite` guards the `ui->draw` call with `#if POKO_DEBUG` so no `VulkanImGuiPass` symbol is referenced.
- Note: `POKO_DEBUG` is defined as `0`/`1`, so `#if` (not `#ifdef`) is required — matching `poko/foundation/build_flags.hpp`.

## Verification — Windows laptop (MSYS2 UCRT64, AMD Radeon)

- `POKO_DEBUG=ON` configure + `pokox_imgui_demo` build: clean.
- Strip proof, two levels: (a) `imgui_demo.cpp` compiled with `-DPOKO_DEBUG=0` and no ImGui/Diligent include paths succeeds and `nm` shows 0 ImGui symbols; (b) a dedicated `pokox_imgui_demo_strip` target (same sources, `POKO_DEBUG=0`, no `vulkan_imgui_pass.cpp`, no `imgui::imgui` link) builds, links — impossible if any ImGui symbol were referenced — runs `--frames 30` clean (`submitted=30, graphics_errors=0`), and `nm -C` on the exe reports **0 `ImGui::` symbols**.
- F1 toggle verified by owner on the AMD GPU during ENG-11 bring-up; the ENG-12 refactor kept the same code path (scancode edge detection inside the `ui imgui` pass) and the debug exe runs clean — interactive F1 re-press not re-tested after refactor (low risk).
- `ctest -R imgui_demo`: 6/6 pass — missing-shader, bad-args and inputs tests now run against **both** `pokox_imgui_demo` and `pokox_imgui_demo_strip`.

## Reproduce / open work

```sh
# Debug (UI + F1):
cmake -B build-imgui -DPOKO_DEBUG=ON # plus the ENG-11 option set
ninja -C build-imgui pokox_imgui_demo
./build-imgui/pokox_imgui_demo --vertex ... --fragment ... --imgui-vertex ... --imgui-fragment ... --adapter 0

# Release strip check:
g++ -std=c++20 -DPOKO_DEBUG=0 -Iengine/render/include -Iengine/rhi/include \
  -Iengine/platform/include -I<vcpkg-include> -c engine/render/src/passes/imgui_demo.cpp -o strip.o
nm -C strip.o | grep -i imgui   # expect no output
```

Keyboard/text input beyond F1, mouse wheel, gamepad, multi-texture `ImTextureData` updates, `ImGuiBackendFlags_RendererHasTextures`, multi-viewport, OpenGL/ES and Android ImGui paths, device-loss recovery, MSVC/CI and Android acceptance remain open, as do all prior infrastructure and phase gates. A full strip-configure CTest leg (POKO_DEBUG=OFF end-to-end) is not yet wired; the object-level proof above is the current evidence.

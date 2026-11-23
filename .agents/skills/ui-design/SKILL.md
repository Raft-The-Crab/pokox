---
name: ui-design
description: Design and implement game UI for Poko — HUDs, menus, debug overlays, and editor panels using Dear ImGui through the engine's imgui pass. Use when building or restyling any on-screen UI, overlays, or in-game menus.
---

# Poko UI Design

Poko renders UI through Dear ImGui (`engine/rhi/src/device/vulkan_imgui_pass.cpp`,
`pokox_flag_imgui_*` test targets). There is no retained-mode UI framework —
everything is immediate-mode ImGui drawn each frame.

## Rules

- Keep UI code inside a dedicated pass/module; never let ImGui calls leak into
  gameplay or simulation code.
- All UI must be safe under Vulkan AND D3D12 backends — no GL-specific ImGui
  backends.
- Scale all sizes by the framebuffer/DPI scale; never hardcode pixel sizes.
- HUD elements: top-left anchored, non-interactive (`ImGui::Begin` with
  `ImGuiWindowFlags_NoInputs` where appropriate). Menus: modal, keyboard-navigable.
- Debug overlays must be gated behind a flag (see `POKO_WITH_*` CMake options and
  the `pokox_flag_*` test pattern) and cost ~nothing when disabled.
- Text: use the engine's bitmap/texture font path if present; otherwise ImGui's
  default font atlas. Do not load fonts per-frame.

## Workflow

1. Check `graphify query "imgui pass"` for the current pass structure before editing.
2. Implement behind a `POKO_WITH_*` option or runtime flag.
3. Verify with the `pokox_flag_imgui_0/1` tests and a Debug MSVC build
   (`msvc-debug.bat`).

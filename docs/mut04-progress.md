# MUT-04 — debug ImGui arithmetic console (2026-11-22)

> Historical MUT-04 snapshot. The later print-log addition is described in `mut05-progress.md`.

MUT-04 adds a small expression console to the existing optional Vulkan/SDL3 ImGui debug demo. Click the field, type an arithmetic expression, and press Enter: the most recent typed numeric result or lex/parse/evaluation diagnostic appears below. F1 retains its existing whole-overlay toggle. The console is a demo integration, not a full engine console or Mute runtime.

## Scope and safety

- `mute/src/console.cpp` connects MUT-01–03 to one-line display strings, including typed numeric values, using locale-independent `to_chars`. It limits source to 4,095 bytes and AST evaluation to 4,095 nodes. The UI refuses to execute a completely full input buffer because paste/typing could have been truncated; in this UI at most 4,094 bytes are accepted for execution. These are not total memory, time or VM budgets.
- `SdlPlatform::poll_event` has a synchronous, per-call, non-owning raw-event observer. The normal event pump/translation and other callers remain unchanged; the demo filters by window ID and forwards text, editing keys, modifiers, focus and wheel to ImGui. The observer must not throw, poll recursively, retain the event, or mutate the platform. SDL text input is activated according to ImGui's request. F1 still works.
- The window currently shows only the latest output; no commands, history, autocomplete, socket, hostcalls, language locals or VM are implemented. The console exposes arithmetic only, no host bindings. Unsupported syntax and runtime errors are reported rather than silently accepted. The future `print` hostcall is MUT-05; functions/locals and VM are later tasks.
- The demo's debug variant links ImGui and Mute. The strip variant does not link or expose them. `POKO_DEBUG=ON` controls this particular existing demo; `POKO_IMGUI` is a separate build-info feature flag, not the console toggle.
- The UI bridge covers the tested keyboard/text path, not a complete platform backend: system clipboard integration, IME composition/candidate positioning, gamepad, non-US layouts, high DPI and mobile keyboard behavior are not yet verified/implemented. A full engine console, backtick shortcut, structured commands and local TCP socket described in the longer-term design remain later work.

## Build

The standard pinned-vcpkg workflow remains supported. The optional ImGui demo can now also use a separately installed `imgui` CMake package without enabling the full vcpkg dependency smoke test; this local route does **not** prove the full manifest. Set `CMAKE_PREFIX_PATH` to SDL3 and ImGui packages; provide pinned DiligentCore as described in `graphics-setup-2026-11-22.md`.

```sh
cmake -S . -B build-ui -DCMAKE_BUILD_TYPE=Release \
  -DCMAKE_PREFIX_PATH="/path/to/sdl3;/path/to/imgui" \
  -DFETCHCONTENT_SOURCE_DIR_DILIGENTCORE=/path/to/pinned/DiligentCore \
  -DPOKO_WITH_SDL_PLATFORM=ON -DPOKO_WITH_VULKAN_DEMO=ON \
  -DPOKO_WITH_SHADER_ARTIFACTS=ON -DPOKO_WITH_IMGUI_DEMO=ON -DPOKO_DEBUG=ON
cmake --build build-ui --target pokox_imgui_demo
./build-ui/pokox_imgui_demo --vertex build-ui/shaders/Release/triangle.vert.spv \
  --fragment build-ui/shaders/Release/triangle.frag.spv \
  --imgui-vertex build-ui/shaders/Release/imgui.vert.spv \
  --imgui-fragment build-ui/shaders/Release/imgui.frag.spv
```

Single-configuration generators use the configured build-type shader directory; multi-config generators need the appropriate `--config` and shader path. SDL3, Vulkan and a compatible desktop display/driver are required. The local sandbox used ImGui 1.93.0 from the vcpkg manifest baseline, with the upstream release SHA-512 matching the pinned vcpkg port, SDL 3.4.20, pinned DiligentCore and Mesa software Vulkan. These local packages are not bundled as installed libraries in the delivered archive.

## Tests and remaining gates

- Local strict Linux/GCC and ASan/UBSan suites each pass 55/55 tests. The real SDL3/Diligent/ImGui software-Vulkan suite passes 78/78. New unit tests check results, errors, caps and synchronous SDL observer behavior.
- A separate Xvfb/XTest keyboard run clicked the real field, typed `1+2*3` and `1/0`, and visibly rendered `i32: 7` and `eval error divide_by_zero at 1:2`; 600 frames reported zero graphics errors/warnings. The optional script `engine/render/tests/integration/test_mute_console_x11.py` compares rendered output-area changes, not OCR; its captured results were visually inspected. It uses synthetic X11 input, not physical devices. Existing F1 XTest passed; `nm` found no `ImGui::` or `poko::mute::` symbols in the strip binary. The UI translation unit also passed `-Wall -Wextra -Wpedantic -Werror` after fixing an existing missing-initializer warning.
- Graphics configuration still reports 21 upstream CMake deprecation warnings; Xvfb may report nonfatal keyboard-map warnings. Graphify skipped 155 unsupported files and partially extracted the demo at a preprocessor region; its graph is not complete. Windows/MSVC/MinGW, Android, physical GPU and hosted CI acceptance remain unverified. No cross-platform floating determinism gate or full sandbox is closed. See `mut01-mut03-followup-audit-2026-11-22.md` for the remaining numeric and resource findings.

The next queued task is **MUT-05**, the `print` hostcall to the ImGui log; MUT-04's single-result display is not that hostcall.

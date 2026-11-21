# ENG-10 — per-frame uniform buffer prototype

The owner requested ENG-10. The implementation is an opt-in desktop Vulkan demonstration, not a production-wide uniform system or a waiver of outstanding ENG-01–09 acceptance gates.

## Implementation

- `POKO_WITH_UNIFORM_DEMO=ON` builds `pokox_uniform` and the matching `uniform.vert.spv` and `uniform.frag.spv` artifacts. It requires the existing Vulkan and shader build options. The shader pair is specific to this demo; it requires a pixel-stage `FrameData` uniform block containing one std140 `vec4` (four 32-bit floats).
- A Diligent dynamic uniform buffer is created with CPU write access, bound through a static pipeline variable and shader-resource binding, and mapped using write/discard on each drawable frame. The pass writes a time-varying color, unmaps, binds the pipeline and commits the resource before drawing. Diligent owns backing allocation/renaming and transitions. Missing depth or uniform resources, failed mapping and captured graphics errors prevent presentation. The renderer still owns resize handling, and pipeline recreation rebuilds the associated uniform buffer and binding.
- ENG-09 depth remains enabled: the near triangle is submitted first and gradually changes red-to-blue-to-red over four seconds; the far green triangle is submitted second and must remain behind it. The frame graph still tracks only logical color/depth writes; it does not manage real GPU resources or implement a general graphics executor. ENG-08/09 demos remain separate.
- Destroy the pass before renderer shutdown; do not reuse it after a renderer restart or across devices. Current SPIR-V loading checks size and magic only, not full shader validity or interface compatibility.

## Verification — Linux development host

- Real SDL/Diligent build: **40/40 CTests passed**. The strict SDL/shader baseline passed **31/31**. The frame-graph and backend/failure-test ASan/UBSan selection passed **8/8**. Production renderer/demo translation units and the control-flow test passed `-Wall -Wextra -Wpedantic -Wshadow -Wconversion -Wsign-conversion -Werror`. The incremental project build reported no compiler warnings; third-party configuration/build warnings may still occur.
- Both produced uniform SPIR-V modules passed Vulkan 1.1 semantic validation. Test doubles cover two distinct per-frame payloads, buffer reuse, format-change recreation, explicit depth state, and injected creation/binding/map/unmap/commit failures. Double tests are not device/driver acceptance.
- Isolated X11/Xvfb with Mesa lavapipe software Vulkan: the demo submitted **2,400 frames**, resized to 640×480, 900×650 and 720×540, and reported zero captured Diligent errors/warnings. Eight displayed-window pixel samples showed red and blue channels changing over time while the near and overlap pixels matched and the far triangle stayed green. `eng10-software-vulkan-red.png` and `eng10-software-vulkan-blue.png` are selected captures. This is sampled display evidence, not exhaustive image or GPU-memory readback validation.
- The existing triangle, depth and no-depth-control visual regressions also passed after the change. Supplying valid depth shaders without the required uniform block caused the uniform demo to fail before presenting a frame.
- The visual test explicitly disables Vulkan validation layers. Linux software output is not Windows/hardware, validation-layer, OpenGL/ES or Android evidence.

## Reproduce / open work

See `engine/render/README.md` for Linux and Windows build/run commands. On the target GPU, run without `--no-validation` when validation layers are installed; observe the near triangle cycling red/blue while remaining in front of the green triangle, resize the window, and check captured warnings/errors. Confirm actual GPU and validation-layer results rather than assuming software results transfer.

No Android or OpenGL/ES uniform path, GPU device-loss recovery, shader-interface reflection, general per-frame constants allocator, reusable material system or multi-frame resource synchronization policy is claimed. These remain future production work. ENG-11, the ImGui frame-graph pass, is the next queued task and is not included here.

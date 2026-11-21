# Engine

PokoX runtime: platform abstraction, rendering, simulation, audio, animation, scenes and diagnostics. The directories are mostly a scaffold. A minimal executable, build flag contracts and build/dependency tests are present under `foundation/`. ENG-01 adds the backend-independent `platform/include/poko/platform/window/i_platform.hpp` contract. ENG-02 adds an SDL3 implementation and a blank window demo, tested on Linux/X11 and previously on Windows MinGW; current MSVC and Android verification remain open. See [platform module](platform/README.md).

See [engine capabilities](../docs/plan/11-engine.md), [engine core](../docs/plan/21-engine-core.md) and the [work queue](../docs/plan/02-work-queue.md).

ENG-06 adds a CPU-only dependency-ordering skeleton under [render](render/README.md). It is not yet connected to the GPU/RHI; prior platform and renderer acceptance checks remain open.

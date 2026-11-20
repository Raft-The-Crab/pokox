# Engine

PokoX runtime: platform abstraction, rendering, simulation, audio, animation, scenes and diagnostics. The directories are mostly a scaffold. A minimal executable, build flag contracts and build/dependency tests are present under `foundation/`. ENG-01 adds the backend-independent `platform/include/poko/platform/i_platform.hpp` contract. ENG-02 adds an SDL3 implementation and a blank window demo, verified on Linux/X11 but not Windows or Android. See [platform module](platform/README.md).

See [engine capabilities](../docs/plan/11-engine.md), [engine core](../docs/plan/21-engine-core.md) and the [work queue](../docs/plan/02-work-queue.md).

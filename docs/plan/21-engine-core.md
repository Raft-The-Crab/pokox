# 21 — Engine core

## Design principles

Determinism where it affects validated state, variable where it only affects presentation. No hidden global state. All initialization explicit and reversible. Every subsystem has a declared dependency set and a documented shutdown order. Debug builds trap early; release builds degrade gracefully.

## Module graph and dependency order

```
foundation -> platform -> rhi -> resource -> scene -> physics -> animation
          -> audio -> render -> ui -> script -> net -> tools
```

Dependency rule: a module may depend only on modules to its left. No cycles. `foundation` depends on nothing but the C++ standard library and fixed third-party math primitives.

| Module | Responsibility |
|---|---|
| foundation | Types, math, allocators, logging, assertions, error codes, CBOR serialization |
| platform | Window, input, filesystem abstraction, threading, timers, OS events |
| rhi | Diligent-backed device, queues, buffers, textures, pipelines, passes, barriers |
| resource | Handles, loading state machine, chunk reader, reference counting, hot reload |
| scene | Entities, components, queries, transforms, hierarchy, scene serialization |
| physics | Fixed-point sim solver and float visual solver |
| animation | Skeletons, clips, state machines, blend trees, IK |
| audio | Mixer graph, voices, streaming, spatialization |
| render | Frame graph, materials, culling, lighting, post stack |
| ui | Retained node tree, layout solver, state binding, in-game compositor |
| script | Mute VM, hostcalls, bytecode loader, debug interface |
| net | BitBuffer, frame, FEC, transports, session state |
| tools | Profiler, debug draw, replay recorder, console, crash handler |

## Initialization and shutdown

Init in dependency order. Each module exposes `init(config) -> Result<Unit, Error>`, `ready() -> bool`, `shutdown()`. If any init fails, already-initialized modules shut down in reverse order. Shutdown waits for all in-flight jobs and releases GPU resources before the RHI closes. Asset streaming threads are joined before resource shutdown.

## Main loop

```cpp
while (running) {
    platform.pumpEvents();
    input.beginFrame();
    console.processCommands();

    accumulator += time.delta();
    int steps = 0;
    while (accumulator >= FIXED_DT && steps < MAX_STEPS) {
        sim.beginTick(tick);
        input.snapshot();                 // one immutable snapshot per tick
        script.tick(snapshot);            // Mute VM, deterministic
        physics.simStep();                // Q16.16
        scene.applyCommandBuffer();       // structural changes only at tick boundary
        validator.checkProjectedHash();   // authority only
        sim.endTick();
        accumulator -= FIXED_DT;
        tick++;
        steps++;
    }
    if (steps == MAX_STEPS) accumulator = 0;  // spiral-of-death guard

    float alpha = accumulator / FIXED_DT;
    animation.update(dt);
    physics.visualStep(dt);
    audio.update(dt);
    ui.update(dt);
    render.buildFrameGraph(alpha);
    rhi.execute();
    input.endFrame();
    profiler.endFrame();
}
```

`FIXED_DT` is 1/20 s. `MAX_STEPS` is 4. Presentation can run at 30 or 60 fps; simulation is always 20 Hz.

## Time system

| Clock | Source | Use |
|---|---|---|
| `tick` | Monotonic counter | Sim logic, rules, state hash |
| `simTime` | tick x FIXED_DT | Mute `time.simNow()` |
| `dt` | Real frame delta, clamped to 100 ms | Visual systems |
| `wallNow` | OS clock | Logging and metrics only, never sim |

No wall-clock read is reachable from Mute sim code. The determinism lint rejects it.

## Job system

Worker threads = core count minus one, capped at 8. A fiber-based scheduler with per-priority queues: `Sim`, `Render`, `IO`, `Background`. Jobs declare dependencies; the scheduler resolves them. Physics islands and culling chunks are parallelized.

Determinism rule: any job whose output touches validated state either runs on the Sim queue in declared order or writes to a per-index buffer that is reduced in sorted order. No atomic operation may determine a simulation outcome. Job results are gathered by job index, not completion order.

Debug mode detects jobs that read mutable shared state without a dependency token and fails the frame with a clear message.

## Memory

| Allocator | Scope | Reset |
|---|---|---|
| System heap | Long-lived engine objects | On shutdown |
| Frame arena | Per-frame transient render and UI data | Each render frame |
| Tick arena | Per-tick Mute temporaries and physics contacts | Each sim tick |
| Pool allocators | ECS components by archetype | On entity destruction |
| Staging buffers | GPU uploads | After fence complete |

Debug builds use a tracking allocator with leak reports at shutdown and a watermark report per arena. Release builds use the same allocator interface with tracking compiled out. Budget: 2 GB Windows, 800 MB Android; exceeding 90% triggers texture and chunk eviction before allocation failure.

## ECS

Entities are a 32-bit index plus a 16-bit generation in one `u64`. Components are stored in packed arrays per archetype. Queries are declared as `Includes<...>` and `Excludes<...>` and cached after first use. Iteration is in ascending entity index — this is a determinism requirement, not an optimization. Structural changes are deferred through a command buffer applied only at tick boundaries, so iteration is never invalidated mid-query.

Entity destruction increments generation; stale handles trap in debug (`0x08`) and are rejected by the validator in release. Prefabs are templates that instantiate a set of components with overrides.

## Math library

`Vec2/3/4`, `Mat4`, `Quat`, `AABB`, `Sphere`, `Plane`, `Ray`, `Frustum`. Two precision paths: `f32` for presentation, `Q16.16` for sim. The fixed path provides add, sub, mul, div, sqrt and a table-based sin/cos with documented error bounds. All math is header-only, inline, and compiled with `-ffp-contract=off -fno-fast-math`. SIMD is allowed only in the float path and must be disabled for sim code at compile time.

## Strings and identifiers

UTF-8 everywhere. Short-string optimization up to 22 bytes. String interning for IDs, event names, Mute symbols and diagnostic keys. All interned strings live for the process lifetime and are compared by pointer. No locale-dependent string operation in sim code.

## Filesystem abstraction

A virtual filesystem with four roots: `app://` (installed binary data), `user://` (writable settings and saves), `cache://` (evictable chunks), `pkx://` (mounted game package). Async reads go through the IO job queue. A file watcher in dev mode triggers hot reload. Paths are canonicalized to forward slashes and cannot escape their root.

## Serialization

CBOR with canonical key ordering. Every serialized type carries a schema word from the word-version registry; loading a schema without a registered migration fails explicitly. Unknown fields are skipped with a warning; missing required fields fail. All engine data files are versioned this way, including config, scene, material and UI data.

## Console and CVars

Commands are named functions with typed arguments and autocomplete. CVars are typed variables with flags: `Archive` (persisted to config), `ReadOnly`, `Cheat` (disabled in shipping), `Replicated`. Console opens with backtick in dev builds and is reachable over a local socket for automated tests. Every CVar change is logged with its old and new value.

## Error handling

`Result<T,E>` in engine APIs; no exceptions across module boundaries. Error codes are namespaced by module. Assertions are compiled out in release but never replace validation of external input. A central crash handler writes a minidump to `user://crashes/`, flushes logs, and shows a recovery dialog on next launch. On Android it writes a tombstone summary to a text file.

## Hot reload

Assets: file watcher marks the handle dirty; the resource module reloads on next frame; the old resource is released after the GPU fence. Code: engine modules are static in v1; only Mute bytecode and UI data hot-reload. ABI mismatch rejects the patch with a clear error and keeps the running version.

## Coding standards

Two-space indent, 100-column limit, `snake_case` for functions and variables, `PascalCase` for types, `UPPER_SNAKE` for constants. Includes in groups: std, third-party, engine foundation, module-local. Every public function has a one-line contract comment. Every new system ships with a unit test and a debug visualization. No committed secrets; CI scans for them.

# ENG-06 — frame-graph skeleton

The owner requested the next task after the ENG-01–05 audit. Continuing implementation does not accept ENG-04/05, close the earlier infrastructure checks or waive project phase gates.

## Implemented

- A CPU-only, single-threaded `FrameGraph` under `engine/render/` registers logical resource reads/writes, explicit predecessors and callbacks. It derives edges and uses deterministic registration-order tie breaking. The required two dummy passes execute producer first even when registered consumer first.
- The whole graph is validated before execution: missing imports/producers, duplicate names/resources/writers, missing callbacks, unknown pass dependencies and cycles fail without running any pass. Duplicate edges are deduplicated. The prototype requires one writer per name and rejects read/write of the same name within a pass; callers must model versions with different names.
- `compile()` returns a non-executing plan. `execute()` revalidates, stops and reports the first callback exception and completed count, with no rollback of earlier callbacks. Graph mutation and re-entrant execution are rejected while callbacks run. Allocation failures may propagate; the graph and callback captures must outlive execution.
- The new default CMake library and CTest target are independent of SDL/Diligent. The version-integration fixture copies the new build inputs. See `engine/render/README.md` for API and limitations.

## Boundaries

This is a tested scheduling skeleton, not an integrated renderer or a complete resource graph. No GPU resource ownership, pass command context, GPU execution, transient allocation, resource barriers, read-write/present state tracking, multiple writes/versioning, asynchronous work or backend submission is implemented. The Vulkan/OpenGL demos do not yet use this graph. The narrow queue criterion is CPU dummy-pass ordering; it does not imply graphics correctness or production readiness.

ENG-04/05 and platform gates retain their previously documented unverified target-device checks. Real Windows/MSVC, Android and CI verification of the new C++ code are also outstanding.

## Verification

- Fresh Linux GCC 11.5 / CMake 3.31 Debug build with `-Wall -Wextra -Wpedantic -Wshadow -Wconversion -Wsign-conversion -Werror`: **27/27 CTests passed**. An SDL-enabled build passed **29/29** with no compiler warnings in that incremental build.
- Frame-graph tests also passed in an optimized `-O2 -DNDEBUG` build and with AddressSanitizer and UndefinedBehaviorSanitizer; eight deliberately injected scheduling, validation, reentrancy and callback-failure mutations were detected. GCC 11 `-fanalyzer` reported no warnings for the frame-graph translation unit.
- The graph target and existing demos built alongside real SDL and pinned Diligent. This only verifies coexistence/build integration; the graph is not used by those demos. That configuration still reports upstream Diligent/third-party configure-time warnings.

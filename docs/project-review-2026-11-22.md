# Project review and repairs — 2026-11-22

## Project map and review scope

PokoX is an early C++20 game-platform scaffold. This review inventoried every
root area and traced the implemented integration paths, rather than claiming a
line-by-line verification of every file or every future system:

- Engine: platform/window lifecycle, Vulkan/OpenGL seed and demos, frame graph,
  shaders, configuration/CBOR, stats, asset store, KTX2 and PMES; tests use
  both production components and test doubles. Many are opt-in prototypes.
- Backend: a SQLite/D1 reservation migration, not a deployed service. Client,
  server, studio and Mute are placeholders; planned architecture is not
  implemented functionality.
- Tools: CMake/vcpkg, CI, versioning, golden comparisons and Python tests.
- Assets: Blender models and adaptation scripts exist, but visual/animation
  validation and engine import remain open. Legal documents are drafts and
  were not reviewed as legal advice.

The prior archive's pre-existing uncommitted changes were preserved. This work
continues the earlier review documented in `integration-review-2026-11-22.md`.
That review's configuration-allocation and graph-tool notes are superseded by
the fixes and tooling below; its other target-device caveats still apply.

## Verified fixes

1. **KTX2 header and shape:** the old reader treated all six index fields as
   64-bit (96-byte header), rejected ordinary non-array 2D textures and used
   a matching nonconforming synthetic fixture. Khronos specifies four 32-bit
   offsets/lengths, two 64-bit fields, an 80-byte header, and zero depth and
   layer count for 2D non-arrays. The replacement reads little-endian fields,
   accepts levelCount zero, checks mip limits, exact level sizes, bounds,
   overlap and arithmetic. Tests now use spec-shaped 2D fixtures and cover
   multiple mip levels, formats, truncation and malformed inputs. The old
   fixture tests failed against the corrected layout before the fix.
   Source: https://registry.khronos.org/KTX/specs/2.0/ktxspec.v2.html
2. **Configuration allocation failure:** allocations inside helper functions
   declared `noexcept` could terminate the process. The loader now catches
   exceptions at its public boundary; a deterministic fault-injection test
   aborted before and passes after the change. CBOR may still classify an
   allocation failure as a generic decode error; an error detail is best effort.
3. **Asset handling:** constructing an asset handle could increment its
   reference count before a throwing key copy; failed retry state could mask
   a newly queued job; and async failure/installation reporting could terminate
   on allocation failure. Tests reproduce these cases and check recovery.
   Queue insertion now rolls back on failure. `last_error()` returns an
   allocating string and is no longer declared `noexcept`; callers that depend
   on its exact exception specification must be rebuilt. The typed payload cast
   is explicitly documented as unchecked. An existing async test was also
   timing-dependent: its worker could finish before assertions that it was
   loading. A gate now holds the worker until those assertions finish; the
   corrected test passed 75 consecutive runs.
4. **Camera transform and resizing:** corrected the homogeneous view transform
   and Vulkan depth range. The cube demo now initializes its aspect from drawable
   pixel dimensions and updates it on resize; zero-sized viewports preserve the
   last valid projection. Dependency-free camera tests cover the calculations.
   The modified demo also passed a syntax-only check using minimal SDL stubs;
   actual SDL/Diligent integration and visual GPU verification remain open.

## Verification

Linux x86-64, GCC 11.5.0 and CMake 3.31.10. Dependency-free Debug CTest:
**36/36 passed** with `-Wall -Wextra -Wpedantic -Werror`; a separate
AddressSanitizer + UndefinedBehaviorSanitizer build also passed 36/36. A
one-off deterministic 5,000-mutation KTX2 test passed under the sanitizers;
this is not exhaustive fuzzing. Two independent Khronos KTX2 fixtures (one
single-level and one seven-level texture) loaded with every mip byte compared
against an independently parsed level index; a 3D fixture was correctly
rejected. Fixtures were obtained from Khronos KTX-Software commit
`983695c105618462b8e96458b378222e99faec98` and checked against their Git LFS
hashes. These checks were one-off and the fixtures are not included.
Clang-tidy 20.1.0 reported no surfaced diagnostics with the selected analyzer
and bugprone checks on 17 production translation units compiled in the
default/test-double build; its output noted suppressed warnings. Historical
GPU and Windows reports are not verification of these new changes. No
production graphics SDK or GPU was used.

## Skills and graph

The project already contained its Graphify skill. Its required Graphify tool
and SQL extractor were installed in an isolated sandbox environment and used
to refresh the code graph. They are not installed on the recipient's computer.
No bundled C++20-specific skill was available; C++20 compiler diagnostics,
regression tests, RAII, ownership and exception-safety review were used.
The graph excludes unsupported files including shaders and Blender assets,
and the code-only refresh does not refresh semantic analysis of changed docs.
Graphify also reported that community labels need refreshing; generated labels
should not be treated as reviewed semantic summaries.

## Remaining work and next safe step

- Build with the actual pinned SDL3/Diligent dependencies and shader tools;
  test independent KTX2 writer output and GPU uploads, real GPU output and
  Vulkan validation after these repairs. The reader does not validate DFD
  semantics or interpret key/value metadata such as orientation, and it is
  deliberately not a general KTX2 validator.
- Run CI on MSVC and MinGW and verify Android and device-specific behavior.
  ENG-04/05 OpenGL fallback and real resize/high-DPI evidence remain open;
  the new camera resize path has not been exercised on an actual device. Do not close gates or start a gated next task solely
  because the dependency-free suite passed.
- Test the modified async interfaces under prolonged contention and broader
  allocation-failure coverage, and confirm app integration on real devices.
- Blender assets, legal drafts, planned backend/security/economy systems and
  unimplemented components need their own specialists and acceptance tests.

No finite review can establish the absence of all defects or warnings in
untested configurations. This report distinguishes tested code from prototypes
and planned work rather than marking the project complete.

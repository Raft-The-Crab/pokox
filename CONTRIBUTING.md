# Contributing to PokoX

Thanks for your interest in PokoX. This document describes how to propose
changes, what we expect, and the rules that keep the project buildable.

## License and confidentiality

PokoX is proprietary. Read `LICENSE` before contributing. By submitting a
change you confirm that:

- you have the right to contribute it;
- you grant the project the right to use it in the Software; and
- you will not copy, release, or redistribute any part of the Software
  outside this project.

Access to this repository does not grant redistribution rights. See
`LICENSE` for the full terms.

## How work is organized

Work is tracked in the ordered queue in `docs/plan/02-work-queue.md`. Each
task has one ID (for example `ENG-03`), one dependency set, and one
acceptance test. Pick up a task only after its dependencies are done, and
reference the task ID in your pull request.

Queue rules (from `docs/plan/02-work-queue.md`):

1. A task is one behavior change, one PR, one test, one focused work
   session.
2. Main builds and all tests pass at every commit.
3. A task touches at most two modules.
4. Do not split a task until it has been attempted and genuinely does not
   fit a session.
5. A gate failure stops the queue.

## Development setup

Requirements: CMake 3.28+, a C++20 compiler, Git, and Python 3.9+ for
tests. Dependency-enabled builds additionally need a bootstrapped vcpkg
checkout pinned to the baseline in `vcpkg.json`. See `docs/build.md` for
the full setup and per-toolchain commands.

Minimal local check (no external dependencies):

```sh
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug -DBUILD_TESTING=ON
cmake --build build --config Debug
ctest --test-dir build -C Debug --output-on-failure
```

Dependency-enabled and platform builds (SDL, Vulkan demo) are documented
in `docs/build.md` and `engine/platform/README.md` / `engine/rhi/README.md`.

## Coding conventions

- C++20, no compiler extensions (`CXX_EXTENSIONS OFF` is set project-wide).
- New engine-facing code goes under the owning module in `engine/` and
  links the `poko_build_options` interface target when it needs the
  `POKO_IMGUI` / `POKO_D3D12` / `POKO_DEBUG` compile definitions.
- Match the style of the surrounding code: compact, explicit error
  handling at real boundaries, no speculative abstraction.
- Do not add comments unless the surrounding code uses them for the same
  purpose; do not remove existing comments.
- Keep changes focused. Do not refactor unrelated code, upgrade
  dependencies, or redesign architecture without necessity.

## Testing expectations

- Every task ships with its acceptance test. Register C++ tests with CTest
  in the root `CMakeLists.txt` and Python checks under `tools/` or the
  owning module's `tests/`.
- Byte-exact comparisons use the shared golden harness
  (`tools/testutils/harness/golden.py`); see its README.
- Dependency-free fault-injection tests (test-owned doubles compiled
  against the real sources) are the established pattern for platform and
  RHI code — prefer them where a real SDK/GPU is unavailable, and say so
  honestly in the report.
- Never weaken, skip, or delete a test to make a change pass.

## Documentation and status updates

When implementation or layout changes, update in the same change:

- `docs/structure.md` (actual directory inventory);
- `docs/build.md` (build status and verification records);
- `docs/plan/02-work-queue.md` scaffold progress;
- task-specific progress/evidence docs (for example `docs/eng-progress.md`
  and `docs/eng*-evidence.txt`).

Record exactly what was verified, on which host/toolchain, and what
remains unverified. Do not claim a build, test, GPU, or platform result
that was not actually run.

## Commit and PR conventions

- Write commit messages that explain *why*, matching the existing history
  style.
- One PR per task. Title should name the task ID, e.g.
  `ENG-03: ...`.
- The PR description should state: task ID, summary of the change,
  verification performed (commands + results), and remaining gaps.
- Do not commit secrets, credentials, machine-specific paths, or build
  artifacts (see `.gitignore`).
- Do not push directly to the default branch; open a PR.

## Reporting issues

Use the issue templates under `.github/ISSUE_TEMPLATE`. For security
issues, follow `SECURITY.md` instead of opening a public issue.

## Questions

Ask in the project's normal channels. For licensing questions, contact a
project maintainer before assuming any rights beyond `LICENSE`.

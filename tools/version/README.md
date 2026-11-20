# Build version metadata

INF-06 embeds a Git tag in the `pokox` executable.

## Layout

- `cmake/generate_version.cmake` reads Git and generates `poko/build_version.hpp` in the **build directory**, not the source tree.
- `tests/integration/test_version.py` builds a small copy of the actual application in a temporary Git repository and verifies tag changes in the real executable.

## Version policy

- Only tags pointing exactly at `HEAD` are considered; both lightweight and annotated tags work. If several tags point at `HEAD`, the lexicographically first ref name is selected. This is a deterministic build-metadata rule, not a release selection policy.
- An untagged commit, an empty repository, or a source archive without a project-root `.git` produces `unversioned`. A checkout with a `.git` directory or file must have a working Git executable; Git errors do not silently produce a tagged build. A project nested inside a parent repository is treated as an archive unless it has its own `.git`.
- The generator runs before every executable build and rewrites the header only when its contents change, so adding, removing or moving a tag takes effect on the next build without reconfiguring. It does not check for uncommitted changes.
- This string is build metadata, not a canonical public game version, WordKey, signature or proof of authenticity. Follow the publishing plan for those.

After building, run `pokox --version` (on Windows, use the executable path under `build-msvc/Debug/` or the selected build directory). A source ZIP without Git history reports `PokoX build: unversioned`. Tag-bearing checkouts need their tags available locally; the CI workflow fetches full history and tags.

CTest runs the integration test with `BUILD_TESTING=ON`; it needs Python 3.9+, Git, CMake and a compiler. It does not modify the user's repository.

# MUT-21 — packages, imports and lockfile

Status: implemented locally; hosted CI and target-platform gates remain open.

## What was added

- `mute/include/poko/mute/package.hpp` and `mute/src/package/package.cpp`:
  `resolve_packages` parses every supplied source as a v1 declaration module,
  extracts the `package`/`version` identity and `import "pkg://name[@word]" as
  alias` declarations, then resolves the whole set as one build.
- `dump_lockfile` emits canonical `mute.lock` text: `# mute.lock v1` header
  plus sorted `name@version <xxhash64>` lines. The hash is the raw source
  content hash; ordering is by name then version, independent of input order.
- `mute/tests/unit/package_test.cpp` registered as CTest `mute_package_unit`.

## Resolution rules

- Declared `package`/`version` must match the caller-claimed input identity.
- Duplicate `name@version` inputs are rejected.
- Imports may pin `pkg://name@Word` or leave the version unpinned; unpinned
  imports bind to the already-bound version for that name, else the single
  available version, else `ambiguous_version`.
- One version per package name per build; a second distinct version is
  `version_conflict` (covers diamonds requiring divergent pins).
- Missing names are `missing_dependency`; present names lacking the pinned
  word are `version_conflict`.
- The resolved graph must be acyclic; back edges report `cyclic_import`
  (self-imports included).
- Malformed specs (`pkg://` prefix required, nonempty name, nonempty pinned
  version) are `invalid_import_spec`; parse failures pass through as
  `parse_failed`.

## Evidence

- Debug MSVC build clean; `mute_package_unit` passes (17 scenario groups:
  pinned/unpinned resolution, missing, conflict, ambiguity, diamond conflict,
  cycles, self-import, duplicates, identity mismatch, missing declarations,
  malformed spec, parse failure, lockfile determinism across input order).
- Full local CTest: 73/73 passed (version_integration verified with the full
  MSVC/SDK toolchain environment).
- `tools/version` integration source list updated for the new files.

## Limits

- The resolver works on caller-supplied sources only; there is no registry,
  fetch, or `mute.lock` reader/writer yet (MUT-55 tooling).
- Import aliases are recorded but not yet bound into semantic analysis.
- No gate is accepted by this milestone; G1/G2 and platform gates unchanged.

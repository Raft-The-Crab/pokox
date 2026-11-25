# Mute local build tool (MUT-55)

`poko_mute_build` validates a local Mute project against a pinned `mute.lock`.
It is a local build planner, not a registry client or publisher. Fetching,
publishing and signing stay deferred.

## Project layout

```text
project/
  mute.toml
  mute.lock
  app.mute
  dep.mute
```

`mute.toml` v1 supports exactly these keys:

```toml
name = "sample"
version = "V1?"
sources = ["app.mute", "dep.mute"]
```

Each source must declare a matching identity:

```mute
package "sample" version "V1?"
```

Imports use `pkg://name@word` and are resolved by MUT-21. One version per name
per build, no cycles.

## Commands

```bash
poko_mute_build <project-dir>            # validate lock and print build plan
poko_mute_build <project-dir> --emit-lock # bootstrap canonical mute.lock
```

The canonical lock is `# mute.lock v1` followed by sorted
`name@version <16-hex-xxhash64>` lines with LF endings and a trailing newline.
The tool requires an exact byte match. That means a lock mismatch is a hard
error, not an auto-update.

Diagnostics use one line:

```text
mute build error: <code> <detail>
```

Codes: `io`, `invalid_manifest`, `invalid_source`, `invalid_lock`,
`lock_mismatch`, `resolve_failed`.

On success stdout is:

```text
mute build ok: N packages
<canonical lock text>
```

## Sample

`mute/tests/fixtures/mut55_sample` is the pinned sample. `mute_build_tool_unit`
and `mute_build_cli` validate it in CTest. The fixture is a build-plan test:
it proves manifest parsing, package resolution and locked source hashes, not
execution of a full game program.

# GitHub repositories

## Decision (2026-11-21): monorepo

The project ships as a single private monorepo: `Raft-The-Crab/pokox`
(created 2026-11-21). The multi-repo split proposed below is **deferred**,
not rejected: the work queue treats repo layout as singular, cross-module
tasks (e.g. ENG-03 spanning `engine/`, root CMake and `vcpkg.json`) would
become multi-repo changes, and no component has an external consumer or
separate release cadence yet. Revisit when a component gets an external
consumer or when `pokox-release` is needed for shipped binaries; that one
is expected to stay separate. Directory boundaries (`engine/`, `mute/`,
`server/`…) provide isolation without submodule workflow costs.

The plan specifies GitHub Releases for binaries and a source mirror, but does **not** specify repo names, visibility or branching strategy (`docs/plan/README.md` lists branching as a known shallow area). The table below is retained as a reference for a possible future split.

## Proposed repositories

| Repo | Purpose | Visibility | Status |
|---|---|---|---|
| `pokox-engine` | Engine modules from `engine/` | private until policy set | proposed |
| `pokox-mute` | Language, VM, standard library | private | proposed |
| `pokox-client` | Windows and Android app shells | private | proposed |
| `pokox-studio` | Authoring tools | private | proposed |
| `pokox-mod` | Moderation dashboard | private | proposed |
| `pokox-server` | Authority, registry, APIs, SQL | private | proposed |
| `pokox-backend` | Workers, storage adapters, jobs | private | proposed |
| `pokox-tools` | Build, import, profiling utilities | private | proposed |
| `pokox-assets` | Authoring sources and licences | private | proposed |
| `pokox-docs` | Public docs, legal drafts, specs | private until counsel | proposed |
| `pokox-release` | GitHub Releases binaries and manifests | public at launch | proposed |

## Open decisions before creating anything

1. Monorepo vs split repos — the current work queue says "repo layout" (singular). Splitting is a new decision.
2. Visibility — public or private during development.
3. Default branch name and protection rules.
4. Which repo hosts GitHub Releases for the client installer and APK.

## Creation

`tools/scripts/create_github_repos.sh` is a dry-run by default. It does nothing external unless `--execute` is passed. Review `docs/repos.md` and confirm the four decisions above before running it.

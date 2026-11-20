# GitHub repositories (proposal)

The plan specifies GitHub Releases for binaries and a source mirror, but does **not** specify repo names, visibility or branching strategy (`docs/plan/README.md` lists branching as a known shallow area). This is a proposal, not a locked decision.

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

# 03 — Architecture and services

## Topology

Three client applications connect through Cloudflare Workers to the main server on HF account 1. The Workers do token checks, rate limits, static routing and `.pkx` redirects. They never carry per-tick traffic. Game traffic goes directly to a slot, which may be HF account 2 (platform) or donated hardware.

```
Clients -> Cloudflare Workers -> Main server (HF #1)
                                  -> D1 / Aiven Postgres / R2 / Valkey
Slot allocation -> HF #2 platform slots + donated community pool
Game plane -> direct UDP / QUIC / uWS fallback to the slot
```

## Service assignments

| Store | Holds | Never holds |
|---|---|---|
| Aiven PostgreSQL (1 GB) | Users, games, asset metadata, ledger, shares, cases, audit | Binary assets, game state |
| Cloudflare D1 (5 GB) | Edge config, version maps, slot registry, CCU counters, release manifests | Ledger, balances |
| R2 (10 GB) | `.pkx` chunks, `.pk` backups, replay rings, installer mirror | Hot transactional data |
| Valkey / Redis (1 GB) | Rate limits, presence, queues, wake locks, session cache | Balances, shares, inventory |
| Firestore | Mod live-view, player presence pointers | Economy state |
| Cloudinary (25 credits/mo) | Storefront image and video transforms | Raw `.pkx` |
| Qdrant (1 GB) | Mute Library semantic search, asset similarity | Authoritative data |

Rule: one source of truth per fact. Balances live only in Postgres. Redis is reconstructible at any time.

## Free-tier facts verified at planning time

| Service | Allowance | Note |
|---|---|---|
| Cloudflare Workers | 100k requests/day | Pre-launch ceiling, not architecture |
| R2 | 10 GB, zero egress | Immutable CID chunks |
| D1 | 5 GB total | Account-level row quotas |
| Firebase Spark | 1 GB Firestore, ~50k reads/~20k writes per day | No card |
| Hugging Face CPU Basic (2 Spaces) | Space #1 = platform backend/authority (accounts, Pokoins, ledger, moderation); Space #2 = official first-party game hosting only | Spaces may sleep; new accounts get no free Docker Spaces — existing account required |
| Edgegap free tier | On-demand game-session/dedicated-server containers for user-generated games, scale to zero | Free account, no card; usage-billed beyond free |
| Cloudflare Durable Objects (free) | Lobbies, presence, chat rooms, match-session state (hibernating WebSockets) | SQLite backend only on free plan |
| Bonto or enzonic free tier | Optional always-on Node.js service if edge coverage is insufficient | No card; ~75 compute hrs/mo or one 512 MB server |
| Aiven Free | Always-on PostgreSQL, Kafka (250 KiB/s, 5 topics, 3-day retention, schema registry), MySQL, OpenSearch (~20 GB), Valkey | No card |
| GitHub Releases | 1,000 assets/release, <2 GiB each, no total or bandwidth cap | REST API 60/h unauthenticated — clients never call it |
| Upstash Redis | 10k commands/day | Cache only |
| Qdrant Cloud | 1 GB vector | Search only (OpenSearch preferred for catalog) |
| Axiom | Observability: 500 GB ingest/mo, error tracking, traces | No card |
| Sentry | Client crash reporting (ENG-103) | No card free tier |
| Kinde | Auth alternative to Firebase Spark, 10.5k MAU | No card |

## Critical correction

Hugging Face CPU Basic is 2 vCPU / 16 GB / **50 GB non-persistent** disk and Spaces sleep when idle. Therefore:

- No state on disk in the Space. Disk holds binaries only.
- Durable state lives in D1, Aiven Postgres, Valkey and R2.
- A Workers Cron Trigger pings the Space every 10–15 min. A Valkey wake lock prevents races.
- The client sees a "server waking" state during boot, held in a lobby until the authority reports ready.
- HF now grants free Docker Spaces only to legacy accounts; new accounts get none. Space #1 runs the **platform backend/authority** (accounts, Pokoins, ledger, moderation). Space #2 hosts **official first-party games only** — user-generated game sessions run on Edgegap on-demand containers instead; lobbies/presence/chat run on Cloudflare Durable Objects (free SQLite backend with hibernating WebSockets). If Edgegap/DO capacity is insufficient, the fallback is Workers + D1 + KV validating economy and inventory only. Physics validation is the first thing dropped.
- Aiven free tier also provides OpenSearch (~20 GB per account; multiple Aiven accounts multiply the allowance but produce independent clusters with no cross-account queries) for catalog/search offload and Kafka (250 KiB/s, 5 topics, 3-day retention, schema registry + REST proxy per cluster) for telemetry/analytics events — supporting services that keep the authority hot path free of search and analytics work.

## Quota budget

At $0 the binding constraints are 100k Workers requests/day, 1 GB Postgres, 10 GB R2, 1 GB Firestore, two HF Spaces at 2 vCPU and 25 Cloudinary credits. Design to these numbers: 20 platform CCU, lazy chunk downloads, no per-tick edge calls. When exceeded, buy a persistent database first, not compute.

## Two-plane network summary

| Plane | Transport | Traffic |
|---|---|---|
| Control | TCP/TLS through Workers and uWS | Login, inventory, market, reports, chat |
| Game | UDP / QUIC / uWS binary fallback | Input and snapshots |

Full wire detail is in `06-network.md`.

## Naming

Applications: PokoX (client), Poko Studio (authoring), Poko Mod (moderation). Language: Mute. Currency: Pokoins. Files: `.pk` source bundle, `.pkx` client package, `.pkB` backend validation contract. Word versions are public names; WordKeys are public 128-bit identifiers; Ed25519 provides authenticity.

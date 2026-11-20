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
| Hugging Face CPU Basic | 2 vCPU, 16 GB, 50 GB non-persistent disk | Spaces may sleep; quota can be 0 on some accounts |
| Aiven Free | Always-on PostgreSQL, Kafka, MySQL, OpenSearch | No card. **Valkey not listed** — use Upstash or Layerbase for Redis |
| GitHub Releases | 1,000 assets/release, <2 GiB each, no total or bandwidth cap | REST API 60/h unauthenticated — clients never call it |
| Upstash Redis | 10k commands/day | Cache only |
| Qdrant Cloud | 1 GB vector | Search only |

## Critical correction

Hugging Face CPU Basic is 2 vCPU / 16 GB / **50 GB non-persistent** disk and Spaces sleep when idle. Therefore:

- No state on disk in either Space. Disk holds binaries only.
- Durable state lives in D1, Aiven Postgres, Valkey and R2.
- A Workers Cron Trigger pings both Spaces every 10–15 min. A Valkey wake lock prevents races.
- The client sees a "server waking" state during boot, held in a lobby until the authority reports ready.
- If HF #2 quota is 0, the fallback is Workers + D1 + KV validating economy and inventory only. Physics validation is the first thing dropped.
- Verify two Docker Spaces can be created on the account before writing server code.

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

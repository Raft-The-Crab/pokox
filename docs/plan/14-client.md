# 14 — Client shell

## Responsibilities

Boot, self-update, authentication, catalog, patching, local cache, launcher UI, session launch and platform lifecycle. The client does not own game logic, economy state or validation. Two builds from one C++ codebase plus their native shells: Windows `.exe` with Rust egui chrome, Android `.apk` with Kotlin chrome.

## Boot and self-update

1. Check a signed client manifest in R2: clientVersion, minSupportedGameVersion, changelog, binaryCid
2. Download delta patch, verify signature, stage to a sibling directory
3. Swap on next launch; never patch a running executable
4. On verification failure, fall back to last known-good binary and report
5. Enforce minimum version: a client too old for the game manifest must update
6. Update check goes to `GET /client/latest` on our Worker, never to the GitHub API
7. Binary comes from a direct GitHub Release URL; R2 mirror on failure

On Android, updates go through the normal `.apk` install flow rather than a self-patcher.

## Authentication

Firebase Auth is the only identity provider. Refresh tokens live in the OS keystore: Windows Credential Manager, Android Keystore. Offline with an expired token allows launching already-downloaded games only; no token at all gives local guest mode, single-player cached games, no Pokoins and no account saves.

## Catalog and patcher

Catalog is the list of release manifests the account can access. Patcher:

1. Compare desired manifest CID list to local cache
2. Diff into chunks to add, keep and remove
3. Download missing chunks, four connections, through Cloudflare edge
4. Verify SHA-256 against CID before writing
5. Stage then atomically swap into the version folder
6. On interruption resume from the chunk manifest; partial chunks are redownloaded

Lazy download fetches only first-scene chunks. Shared chunks dedupe by CID. Cache capped at 8 GB with LRU. A game is offline-ready only when its first-session chunk set is present.

## Offline mode

Single-player only on the same engine and Mute VM. No grants, payouts or spending. Market read-only with stale prices. Inventory last known, read-only. Saves written locally with a pending-sync marker. Reports queued locally. On reconnect, events submit with original timestamps and idem keys; anything invalid at the time is rejected. Server state always wins conflicts.

## Session launch

Client requests `POST /match/join` with game id, version and token. Worker verifies entitlement. Matchmaker allocates a slot and returns a 30-second HMAC ticket. Client verifies and connects to the slot endpoint. Handshake exchanges sessionId, nonce, version and baseline. Engine loads `.pkx` from cache, streaming missing chunks behind a real progress screen. Entitlement is checked at the Worker; a modified client cannot launch a game it does not own.

## Android lifecycle

| Event | Behavior |
|---|---|
| onPause | Freeze sim at current tick, snapshot @state to disk, disconnect game plane |
| onResume within 30 s | Reconnect with saved sessionId and nonce, resume from last accepted tick |
| onResume after 30 s | Session expired; rejoin through matchmaker or offer offline |
| process kill | Local snapshot persists; next launch offers resume |
| low memory | Evict texture cache then chunk cache, never active game chunks |
| doze | Pause periodic sync, flush on wake |
| cutouts | UI safe areas respected |

## Windows lifecycle

Single instance, staged auto-update at exit, file associations for `.pk` and `.pkx`, laptop sleep handled like Android suspend.

## Storage layout

| Directory | Contents | Eviction |
|---|---|---|
| client/ | Binary, current manifest | On update |
| games/<id>/<version>/ | `.pkx` chunks, `.pkB`, local saves | LRU by game |
| cache/ | Catalog, thumbnails, token metadata | Aggressive |
| pending/ | Offline events awaiting sync | On successful sync |

## Security boundaries

Cheat-proofing is server-side; client integrity is advisory. Tokens in keystore, short-lived, device-bound. Chunks verified by CID before load. Local saves advisory; server wins. Entitlement at Worker. Unsigned local `.pk` imports run in an offline sandbox and never connect online.

## Limits

8 GB local cache, four concurrent downloads, 50 MB chunk cap, 30 s reconnect, 1,000 pending events, current plus two previous client versions, 500 games per library.

# 07 — Matchmaker, slots and donated servers

## Vocabulary

| Term | Meaning |
|---|---|
| Game | A published `.pkx` with a developer owner |
| Realm | One game's live environment, production or staging |
| Slot | One running validator instance for a realm, up to 20 players |
| Session | One match inside a slot |
| BYO | Developer-provided server registering inbound to the matchmaker |
| Donated node | Community-provided hardware offering free capacity to developers |

Two server sources: platform slots on HF #2 and donated or BYO slots. Both appear in one slot table, differing by `source`. **20 CCU is the platform-slot cap only** (FIX F3). Donated nodes add capacity on top; global CCU is uncapped.

## Slot states

Cold, Waking, Ready, Full, Draining, Dead. Wake timeout 30 s, drain 5 min. A `Waking` slot is the honest "wait till HF #2 is available" state. If wake fails twice, the slot goes Dead and the player is offered donated/BYO servers or a queued retry.

## Allocation algorithm

1. Authenticate, verify entitlement via Firebase token at the Worker
2. Rank candidates: `score = latencyWeight*rtt + loadPenalty*playerCount - affinityBonus`, party affinity applied
3. Filter Full, Dead, Draining and version-mismatched slots
4. Choose best Ready platform slot, else donated/BYO slot if opted in, else trigger wake on the nearest Cold slot, else queue
5. Issue 30-second HMAC ticket containing sessionId, slotId, nonce, version
6. Client connects directly to the slot endpoint with the selected transport

## Queue

Valkey sorted sets per realm, scored by enqueue time with party-size boosts. Deterministic FIFO. Position estimate and ETA derived from slot drain rate. Expire after 5 minutes. Capacity wake or player departure pulls the next entry.

## BYO and donated registration

A developer server registers by POSTing a signed `register` message: gameId, version, endpoint, region, transport (tcp default or udp), maxPlayers, developerSig, nonce. Worker verifies signature against the developer pubkey, challenges the endpoint for reachability, then writes a Ready slot with a 60 s heartbeat TTL. Missing heartbeat flips to Dead.

Donated hardware follows the same registration but is constrained: it runs only the signed validator image, receives a scoped token, and is staged for 72 h before production (trusted contributors only for the first 30 days). Max ten nodes per donor entity, geo-tagged and capacity-capped.

| Boundary | Control |
|---|---|
| Donor hardware | Signed validator image, hash-checked at boot |
| Donor credentials | Scoped token: read own game's `.pkB`, write session events only |
| No secrets | Never registry keys, ledger credentials, Firebase admin or moderation data |
| No persistence | Session state in memory, encrypted in transit, no disk writes of player data |
| Withdrawal | 24 h notice, sessions drain, no penalty |

## Capacity accounting

| Counter | Store | Rule |
|---|---|---|
| Global platform CCU | D1 | Atomic, hard cap 20 |
| Per-game platform slots | D1 | Max 3 |
| Per-slot players | Slot process | Max 20, matches heartbeat |
| Queue depth | Valkey | Max 500/realm |

D1 is the source of truth; Redis is a fast mirror. When platform CCU is 20, allocation returns only donated/BYO slots or a queue.

## Platform capacity degradation (Edgegap)

Game sessions default to Edgegap on-demand containers. Verified free-tier limits (2026-11): **1 app, 2 versions, 1 concurrent deployment, up to 1.5 vCPU, unlimited deployments with a 1 h uptime cap per deployment, 3 matchmakers (3 h uptime), 3 server browsers (3 h uptime)**, limited container registry. This means the free tier effectively allows **one live session at a time** — far below the 20 platform CCU target.

When Edgegap capacity is exhausted or a deployment hits its uptime cap, allocation must degrade in order:

1. Return donated/BYO slots (existing path).
2. Return queue with "platform capacity full" status.
3. Surface the BYO self-host flow to the developer: register an external endpoint via `POST /dev/slot/register` (existing signed-registration path). Self-hosted sessions go through the same `.pkB` validator, so authority guarantees do not weaken.

The client never blocks on Edgegap availability; a full platform is a normal queue/BYO state, not an error. Revisit paid Edgegap or additional free providers (Bonto, enzonic) when free usage is measurably exceeded — do not pre-provision.

## Cold start integration

A Valkey wake lock (`wakeLock:slotId`, 30 s TTL) ensures one trigger boots a Space. On `GET /health`, the Space writes Ready and releases the lock. Every wake logs duration and outcome in D1. If median wake exceeds 20 s over a week, that is evidence to revisit the no-card constraint later — without changing the plan now.

## Reconnection

Within 30 s, a client presents sessionId and nonce. If the session and player slot still exist, a new ticket is issued and the game plane resumes from the last accepted tick. If the slot died, rejoin the queue. No cross-slot state migration in v1.

## Parties and friends

Party formation on the uWS control plane. Leader calls `match.joinParty`; members get affinity and are admitted only if party size fits remaining capacity. Parties over 20 are split with a message. Friends joining a live session target a specific sessionId.

## Moderation visibility

Every heartbeat writes a Firestore row: gameId, slotId, source, region, playerCount, sessionIds, state, timestamp. Poko Mod reads this for the exact "games online -> servers available -> reports and characters" flow. A slot with no heartbeat for 60 s disappears.

## Anti-abuse

Slot squatting requires a published `.pkx` and verified developer key. Idle realms with zero players for 24 h are reclaimed. Queue timestamps are server-assigned. Tickets expire in 30 s and are single-use. BYO endpoints are challenge-verified. CCU reports are cross-checked against admitted tickets every 10 s.

## API

`POST /match/join`, `/match/leave`, `/match/party/create`, `/match/party/join`, `/match/reconnect`, `GET /match/queue/:realm`, `POST /dev/slot/register`, `/dev/slot/heartbeat`, `GET /dev/slot/status`, `GET /mod/live`. All authenticated and idempotent via requestId.

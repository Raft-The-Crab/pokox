# 10 — Poko Mod

## Contract

Windows-only egui dashboard reading from Firestore live, D1 registry, R2 replay blobs and Postgres cases and audit. It is a view over existing truth, not a second source. No moderator can connect a report to their identity from outside, and no single moderator can execute a punitive action.

## Hash keys

`key = HMAC(serverSecret, modId | shiftId | nonce)`, single-use, 24 h, device-bound. Claiming a report consumes it and writes `modId, reportId, timestamp, keyHash` to the immutable audit log. A leaked key cannot be replayed; the token does not reveal moderator identity without the server secret. One case per moderator per shift. To handle growth, add keys per shift, never reusability.

## Dashboard panels

Live games from Firestore with 5 s listener; upload queue from D1; reports from Postgres by severity; economy flags; market alerts; audit log. Cloudflare Pages static app calling Workers APIs; Workers verify Firebase moderator token and unused hash key. No database credentials reach the browser.

## Drill-down

1. Games online with summed player counts from heartbeats
2. Slots with source, region, state, playerCount, version
3. Sessions in the selected slot
4. Characters: projected state, names, positions, inventory summary, suspicion
5. Reports attached to the session or players

Selecting a slot older than 60 s is impossible; heartbeat timeout removes it. Direct sessionId entry from a report jumps to step 4.

## Replay viewer

Rings live 64 ticks in Redis and flush to R2 as compressed CBOR every 10 s, retained 30 days. The viewer decodes the same `.pkB` table the authority uses. Controls: timeline scrub with state hash per tick and rejected ticks in red; field inspector with value, delta, policy and rule result; event markers for chat, purchases, bans, challenges and mismatches; suspect overlay; hash diff between client-reported and authority-computed state; signed evidence export. Read-only; editing a replay destroys its evidentiary value.

## Case management

`caseId, reportIds, gameId, sessionId, suspectIds, status, votes, evidenceCids, createdAt, resolvedAt`. Statuses: Open, Claimed, Reviewing, Voting, Resolved, Appealed, Closed. Claim timeout 2 h returns to Open with the key still consumed. Two distinct moderator votes are required; a claim and approval cannot come from the same key.

Actions: warning, chat mute, temporary ban 1/7/30 days, permanent ban, asset removal, game takedown, share-trade suspension, payout hold. Each writes to the audit log and notifies the player with a reason code, never a moderator identity.

## Detectors

Match mismatch, ledger fraud signals, market abuse, chat classifier, perceptual image hash, upload scan, behavior clusters, report volume. Detectors create Open cases with evidence. Precision measured weekly; mostly-dismissed detectors are retuned or removed.

## Appeals

Player gets a reason code and case reference, appeals within 30 days. Case reopens as Appealed to a moderator who did not vote, with a fresh key. Overturning requires a second distinct vote. Ledger reversal is a new balanced transaction: bans lifted, assets restored, Pokoins returned from void through system:treasury.

## Moderator safety

Identity never exposed; notices use reason codes. Single-use device-bound keys. Two distinct votes. Case assignment rotates. One case per key and a 100 reports/day ceiling. Append-only audit exported daily to separate R2 storage. Content-addressed replay and case blobs.

## Data model

Postgres: moderators, key hashes, cases, votes, actions, audit, appeals. Firestore: live slots and report status. R2: replay and signed evidence blobs, 30 days. D1: publish review queue and market alerts. Valkey: replay scratch, key-use lock, claim TTL.

## API

`POST /mod/shift/start`, `/case/claim`, `GET /mod/live/games`, `/live/slots/:gameId`, `/live/session/:id`, `/replay/:sessionId/:tick`, `POST /mod/vote`, `/mod/action`, `/mod/appeal`, `GET /mod/cases`, `/mod/audit`. Every mutating endpoint requires an unused key.

## Additional features

Bulk actions under two-vote rule, trust score per game, ban-evasion device graph, invisible spectate, case templates, shift handover, detector tuning panel, appeal hearing view, moderator analytics, jurisdiction rules, transparency report generator.

## Limits

One key equals one case, 100 reports/day, 30-day replay retention, 64-tick live ring, 2 h claim timeout, 30-day appeal window, 50 publish reviews/day, two votes per action, permanent audit.

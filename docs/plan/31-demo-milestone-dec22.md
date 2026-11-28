# Demo milestone — friends & family, 2026-12-22

Status: agreed 2026-11-27. This is a milestone doc, **not** a change to the canonical queue
(`02-work-queue.md` keeps its no-date discipline). Until Dec 22, session work prefers rows on
this critical path; everything else waits.

## What friends can do on Dec 22

1. Download a **zip of a Windows client** from the owner directly (no patcher, no PUB lane, no G8).
2. Connect to **one hosted server** and play **one hand-authored arena game** together:
   move a character, one Mute-driven rule runs (e.g. a score or hazard rule).
3. **Minimal Studio**: place objects, set one rule, export a scene that the client can load.
   ("Create games" in the smallest possible form — no UI maker, no moderation, no publishing.)

Explicitly cut for the demo: Android client (SHL-15..17), patcher/version distribution
(VER lane, PUB-02..06), moderation and review tiers, economy UI, STU-02..10, AST-02/03/05/07/08.

## Capacity math (from 2026-11-27 to 2026-12-22)

- Weekend days (16 h agent-hours): Nov 28–29, Dec 5–6, 12–13, 19–20 → 8 days.
- Weekdays (7 h agent-hours): Nov 30–Dec 4, Dec 7–11, Dec 14–18, Dec 21–22 → 17 days.
- Total ≈ **280 agent-hours** across one lead + parallel agents.
- Observed pace is ~2–4 queue rows per working day, but rows needing the owner's Windows
  laptop (G1/G2 traces, real Vulkan/llvmpipe renders, MSYS2 link) serialize on laptop sessions.
- **Realistic throughput: ~25–35 demo-relevant rows.** The must-have list below is 19 rows;
  integration sessions, review rounds and fixes found along the way add ~6 more. That fits
  with roughly one week of slack. Do not spend the slack on scope — spend it on
  the laptop-only verification steps.

## Critical path (19 must-have rows, ≈25 with integration and fixes)

| # | Rows | What it gives the demo | Depends on |
|---|------|------------------------|------------|
| 1 | SHL-02..08 (7) | Rust shell → windowed client with egui UI and RAII/panic safety. Demo can stop at SHL-07 if needed. | SHL-01 (done) |
| 2 | SHL-09 (1) | SDL3 events drive input into the client. | ENG-02 (seed, audited in `../audit-eng01-13.md`) |
| 3 | DEMO-01..02 (2, *new rows — not in the queue*) | Wrap authority + matchmaker + net into one runnable server binary (`server/host/main`), plus a deploy script for the VPS. The BAK/NET/IDN code exists as libraries; nothing wraps it in a `main()` yet. **Biggest unbuilt piece.** | BAK-01..15, NET-01..09 (done) |
| 4 | DEMO-03 (1, *new row*) | Client-side WS connect using the existing `ws_transport` wire format; join a session end-to-end. | NET-01..09 (done), #3 |
| 5 | AST-01 + AST-04 subset (2) | glTF import → PokoMesh (quantization only, no KTX2/Opus/Basis). This is what the owner's in-progress 3D models flow through. | INF-05 (verify; golden harness exists from visual-comparison runs) |
| 6 | MUT-43 + MUT-44 subset (2) | Mute hostcalls for world/entity queries and transforms — the demo game's rule needs these on top of MUT-42 physics (done). | MUT-35, ENG-33 (seed) |
| 7 | STU-min (2, *new rows*) | Minimal scene editor: place objects, set one rule, export `.pkB`-driven scene. | #5 |
| 8 | G2 re-run (1) | Determinism check on the owner's Windows laptop with the real client in the loop. | #1–#6 |

Plus in parallel, any leftover fix/audit work found by the other agents (not counted above).

Landed on this path so far: #1 and #2 (SHL-02..09), and #3 — DEMO-01 `server/host`
(2026-11-27) and DEMO-02 `server/host/deploy` — plus #4 DEMO-03 (2026-11-28): a real
client now upgrades a loopback WebSocket, signs in, joins a session, receives tick SNAPs,
sends framed INPUT and leaves (`client/windows/net/control`, `server/host/ws_host.hpp`,
`pokox_client_control_test`). The VPS systemd/TLS half of the transport stays environment-
gated and plain `ws://`: a public demo needs a TLS reverse proxy in front of `--ws-port`.
Next: #5 assets (AST-01 + AST-04 subset), then #6 Mute hostcalls, #7 Studio minimum.

## Parallel-agent plan

Run at most **one agent per module directory** to avoid edit conflicts:

- **Agent A — shell lane:** SHL-02..09 (client/windows/bridge, engine/platform).
- **Agent B — server lane:** DEMO-01..03 (server/, new server/host/), then deploy to the VPS.
- **Agent C — assets lane:** AST-01 + AST-04 subset (engine/resource, tools/).
- **Lead session:** Mute hostcalls (MUT-43/44, mute/), STU-min, integration, reviews of A/B/C.

The three lanes are independent until integration (#4 client connect). Integration and every
laptop-gated check serialize on the lead session.

## Demo "done when" (acceptance)

- Two friends on separate Windows machines join the hosted server from the zip client.
- Both see the same deterministic world state; a disconnect + reconnect resyncs (BAK-14 path).
- The one Mute rule runs identically on every client (tick hashes match — G2 evidence).
- The owner can rebuild the demo scene with the minimal editor and redeploy it.

## Risks

1. **CI billing/spend-limit failure blocks GitHub Actions** — owner action needed; CI must be
   green within days for the parallel agents to trust their own runs.
2. **Laptop-only verification** — no GPU here; G1/G2, real renders and the MSYS2 client link
   must run on the owner's Windows machine. Budget a laptop session at the end of each lane,
   not just at the end.
3. **Owner's 3D models need #5 early** — AST-01/04-subset should be one of the first lanes
   started so model work isn't blocked in mid-December.
4. **Scope creep** — the cut list above is the contract. New ideas go past Dec 22.

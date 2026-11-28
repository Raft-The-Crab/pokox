# server/host — DEMO-01, the runnable server

One process that wraps the four server libraries into a real server:

- `identity` (IDN-01) — `SIGNIN` maps a verified Firebase uid to a PokoX account.
- `matchmaker` (BAK-09..14) — slot registry, allocator + HMAC tickets, queue, reconnect gate.
- `authority` (BAK-02/05) — one `PkbAuthority` per session: proposals, policy enforcement, committed snapshots.
- `net` (NET-01/03) — UDP datagrams and, since DEMO-03, a WebSocket listener carrying the same payloads.

`poko/host/host.hpp` is the protocol state machine (unit-tested, no socket);
`poko/host/ws_host.hpp` is the WebSocket listener around it; `main.cpp` is only
the UDP loop, timing and logging.

## Run

```
pokox_host [--port N] [--ws-port N] [--tick-hz N] [--slots N] [--schema file.pkb] [--secret S]
```

`--secret` falls back to `$POKO_TICKET_SECRET` and is required (the ticket
signer fails closed on an empty secret). Without `--schema`, the built-in
demo scene (`poko-demo`: `cube_x`, `cube_y`, `look_yaw`, `score`) is served.
`--slots` registers 1–3 platform slots (the registry's per-game cap).
`--ws-port` (default 7778) is the WebSocket listener; `--ws-port 0` leaves the
process UDP-only.

## Wire protocol

Peers are keyed `host:port` (UDP) or `ws:host:port` (WebSocket). Max 1,200
bytes per datagram (NET-01). Both transports carry identical payloads.

Control plane — plain ASCII, one verb per datagram or WebSocket binary frame:

| Request | Replies |
|---|---|
| `SIGNIN <firebase_uid>` | `OK SIGNIN <user_id>` / `ERR <reason>` |
| `JOIN <request_id> [version]` | `OK JOIN <session> <slot> <version> <nonce> <mac_hex> <tick>` / `WAKING <slot>` / `QUEUED <position> <eta>` / `ERR <reason>` |
| `LEAVE` | `OK LEAVE` / `ERR not-joined` |
| `RECONNECT <session> <nonce>` | `OK RECONNECT <session> <slot> <version> <nonce> <mac_hex> <resume>` / `ERR reconnect` |
| `PING` | `OK PONG` |

Game plane — NET-03 frames (first byte `0x15`), HMAC key = the ticket MAC
from the JOIN/RECONNECT reply. This gives integrity against off-path
injection only; eavesdroppers see the plaintext, which the demo accepts on a
friends-and-family VPS until TLS lands. Payload verbs: `INPUT <field_id> <value>` →
`ACK <accepted|discarded> <field_id>`, `STATE` → `SNAP ...`. Every
committed tick the host broadcasts one frame per client:
`SNAP <tick> <hash_hex> <n> <id>=<value> ...` (ascending field id).

Field ids are declaration order in the .pkB starting at 1. Malformed input
is bounded (tokens ≤ 128 chars, overflow-checked number parsing) and never
crashes the host: it answers `ERR` or stays silent for unauthenticated
frames.

## WebSocket transport (DEMO-03)

`WsHost` listens on `--ws-port`, answers the RFC 6455 upgrade
(`Sec-WebSocket-Accept` = base64(SHA-1(key + GUID))), reassembles each
connection's byte stream into frames, hands binary payloads to the same
`handle_datagram` the UDP loop calls, and routes each tick's outgoing frame
back to its connection. Close and ping are answered per RFC; frames above the
1,200-byte cap, fragmented frames, 64-bit lengths and non-upgrade requests
drop the connection without touching the host state.

The client side lives in `client/windows/net/control`:

- `poko/client/control/session_client.hpp` — `SessionClient`: upgrade, `SIGNIN`,
  `JOIN` (adopts session id + frame key), framed `INPUT`, SNAP polling, `LEAVE`.
- `pokox_ws_client` — console demo against a running host:

```
pokox_host --secret dev-secret &
pokox_ws_client --host 127.0.0.1 --port 7778 --uid demo-fb --seconds 6
```

Tests: `pokox_net_ws_handshake_test` (SHA-1/base64/RFC vectors, hostile
handshakes, frame sizing) and `pokox_client_control_test` (a real loopback
session: upgrade → sign-in → join → SNAP → INPUT ACK → projected field →
second client joins the same session with its own frame key → refused
handshake survived → LEAVE).

## Deploy (DEMO-02)

`deploy/deploy.sh` ships a Linux build to a VPS over ssh: service account,
`/opt/pokox/pokox_host`, `/etc/pokox/pokox-host.env` (0600, holds only
`POKO_TICKET_SECRET`), the systemd unit rendered from
`deploy/pokox-host.service.in`, a ufw rule for the UDP port, restart, then a
health check (`systemctl is-active`, `ss -lunp`, recent logs).

```
cmake -S . -B build-linux -DCMAKE_BUILD_TYPE=Release
cmake --build build-linux -j --target pokox_host

openssl rand -hex 32 > ~/.poko/ticket-secret   # once; reuse it
server/host/deploy/deploy.sh --dry-run --target poko@vps --secret-file ~/.poko/ticket-secret
server/host/deploy/deploy.sh --target poko@vps --secret-file ~/.poko/ticket-secret
```

`--dry-run` prints every remote command and the rendered unit without running
anything. Other flags: `--port` (default 7777), `--tick-hz` (30), `--slots`
(3, the platform cap), `--service-user` (pokox), `--remote-dir`, `--no-firewall`.
The remote user needs passwordless sudo (`$POKOX_SUDO` overrides the prefix).

Not in this row: TLS termination — the WebSocket listener speaks plain
`ws://`, so a public demo needs a TLS reverse proxy in front of `--ws-port`
(and the firewall opened for its port) — and log rotation: the host logs one
line per datagram, so keep `journalctl` capped on the VPS until then.

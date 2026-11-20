# 06 — Network and wire protocol

## Design contract

Three transports, one payload. Raw UDP for the game plane, uWebSockets binary frames as universal fallback, QUIC/WebTransport for mobile handoff. All carry the same BitBuffer bytes read from the `.pkB` field table. Targets: sub-100 ms on good networks, graceful 250 ms on lossy mobile.

## Frame structure

Max 1,200 bytes per datagram, fitting IPv6's 1,280-byte minimum MTU.

| Section | Contents |
|---|---|
| Header | magic+version 8, sessionId 32, seq 32, ack 32, ackBits 32, nonce 32, flags 8, priority 2, payloadLen 16 — about 24 bytes |
| Delta payload | changed bitmap plus changed fields packed at `.pkB` widths |
| FEC | optional XOR parity |
| HMAC | truncated SHA-256, 8 bytes |

Header is BitBuffer-packed, not a C struct. `payloadLen` is a bit length.

## BitBuffer primitives

| Method | Encoding |
|---|---|
| putBool | 1 bit |
| putUint(v,n) | n bits, little-endian bit order |
| putInt(v,n) | zigzag then n bits |
| putEnum | ordinal width from `.pkB` |
| putQuantFloat | round((v-min)/(max-min) * (2^bits-1)) |
| putString | u16 length plus UTF-8 |
| putArray | ceil(log2(maxLen)) length plus elements |
| putDelta | 1 changed bit then new value, or 0 to use baseline |

Bit 0 is the LSB of byte 0. The cursor traps on overflow. The decoder is fuzzed with 1M random inputs nightly.

## Delta encoding

```
snapshot = header + changedBitmap[fieldCount] + changed values + projectedHash:u64
```

If the peer's ack indicates an older baseline, rebase. If the delta is larger than a full snapshot, send a full snapshot with the flag cleared.

## Quantization

Position 16 bits/axis over -512..512, velocity 12 bits/axis over -40..40, yaw 12 bits over 0..2pi, health 8 bits, score 24 bits. Widths come from `.pkB`; quantization and anti-cheat are the same mechanism seen from two sides.

## XOR-FEC

For each group of k gameplay packets, send `P = pkt1 ^ pkt2 ^ ... ^ pktK`. One parity packet recovers any single loss in the group. Two losses in one group are unrecoverable and fall back to retransmit or interpolation.

| Parameter | Value |
|---|---|
| Group size | 4 gameplay, 0 critical |
| Overhead | 25% on gameplay only |
| Interleaving | Rotated group order to spread burst loss |
| Applicable | Gameplay and cosmetic; critical uses reliable retransmit |

XOR is integrity-oblivious, so parity packets also carry HMAC. Corruption fails verification and is dropped, never entering state.

## Channels

| Channel | Transport | Behavior | Use |
|---|---|---|---|
| Critical | TCP/uWS reliable ordered | Retransmit until acked | Economy, inventory, chat, commands |
| Gameplay | UDP unreliable + FEC + resend window | Latest wins | Position, velocity, aim, animation |
| Cosmetic | UDP unreliable | Drop freely | Particles, camera, effects |
| Bulk | TCP/uWS | Chunked and rate-limited | `.pkx` downloads |

The gameplay channel keeps a 64-packet resend window for fields that changed but were not acked.

## Security

- ChaCha20-Poly1305 (libsodium secretbox) encrypts the game plane, keyed from the TLS-authenticated handshake.
- HMAC-SHA256 truncated to 8 bytes covers header and payload. Not encryption by itself.
- Session key rotates every 5 minutes.
- Nonce, seq and ackBits reject replays and out-of-window packets.
- No secrets in the glyph map or WordKey; authenticity comes from Ed25519 on manifests.

## Transports

| Condition | Transport |
|---|---|
| Desktop, UDP reachable | Raw UDP + FEC |
| Mobile with QUIC | QUIC datagrams |
| UDP blocked | uWS binary frames |
| All blocked | Control plane only, no real-time play |

Selection is probed at session start and can fall back if loss exceeds 30% for 3 seconds. The UI shows connection quality, not transport names.

## Lag reduction stack

| Technique | Where |
|---|---|
| BBR congestion control | TCP/uWS control plane |
| TCP_NODELAY | Control plane |
| Token-bucket 64 kbps / 30 packets per second | UDP sender |
| Priority dropping | Cosmetic before gameplay |
| Adaptive tick rate | 20 Hz normal, 10 Hz under thermal stress |
| Snapshot interpolation | 2–3 tick buffer |
| Extrapolation cap | 100 ms then freeze |
| Delta compression | Both sides |
| Area-of-interest | Authority sends only nearby entities |
| Anycast edge | Cloudflare |
| Region pinning | Matchmaker |

Real-time traffic never uses TCP. Control traffic uses tuned TCP. Everything adapts.

## Jitter buffer and MTU

Client keeps a 2–3 tick buffer, interpolates between snapshots, extrapolates at most 100 ms, and snaps to authoritative state on rejection. Buffer depth adapts to measured jitter. Large snapshots split at field boundaries with `fragId`, `fragIndex`, `fragCount`; reassembly timeout 500 ms.

## NAT

Client-to-authority reachability only; no full mesh. Outbound UDP to the slot is sufficient. Symmetric NAT falls back to uWS over TCP 443. No TURN infrastructure needed.

## Limits

1,200 B/datagram, 9,600 bits payload, 30 packets/s/client, 64 kbps/client, FEC group 4, resend 64, frag count 8, replay window 64.

# Server

Server-side authority, APIs, matchmaker, economy, moderation and registry.
Two areas are implemented so far:

- `server/identity` provides sign-in from a verified Firebase identity to an
  idempotent, PokoX-owned account record, device keypair TOFU binding with a
  five-device cap and revocation, OTP step-up gating Device-trust actions
  (IDN-01–03, spec 17), and session velocity / impossible-travel checks
  (IDN-04; token verification and OTP delivery are Worker-side, BAK-03/04).
- `server/net` is the real-time game plane (spec 06): UDP datagrams with a
  1200-byte cap (NET-01), BitBuffer packing (NET-02), the HMAC/replay frame
  (NET-03), delta encoding with a resend window (NET-04), the two-cube demo
  (NET-05), XOR-FEC parity over groups of four (NET-06), RFC 6455 WebSocket
  binary-frame fallback (NET-07), an adaptive jitter buffer with integer
  interpolation and a 100 ms extrapolation cap (NET-08), and ChaCha20-
  Poly1305 AEAD encryption keyed per session (NET-09). Header-only modules
  under `include/poko/net`, each with a unit test under `tests/unit`.

The identity store is in-memory until the Postgres wave; everything else in
this area is a placeholder — do not infer that a service or schema is
implemented.

See the [architecture plan](../docs/plan/03-architecture.md), [matchmaker and servers](../docs/plan/07-matchmaker-and-servers.md) and [work queue](../docs/plan/02-work-queue.md).

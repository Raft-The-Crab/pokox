# Server

Server-side authority, APIs, matchmaker, economy, moderation and registry.
The identity module is implemented: `server/identity` provides sign-in from a
verified Firebase identity to an idempotent, PokoX-owned account record,
device keypair TOFU binding with a five-device cap and revocation, and OTP
step-up gating Device-trust actions (IDN-01–03, spec 17; token verification
and OTP delivery are Worker-side, BAK-03/04). The store is in-memory until
the Postgres wave; everything else in this area is a placeholder — do not
infer that a service or schema is implemented.

See the [architecture plan](../docs/plan/03-architecture.md), [matchmaker and servers](../docs/plan/07-matchmaker-and-servers.md) and [work queue](../docs/plan/02-work-queue.md).

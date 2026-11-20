# 17 — Identity and security

## Identity

Firebase Auth is the identity provider; PokoX keeps its own account record with trust state, roles and devices. Firebase proves identity claim; PokoX decides permission. Chain: Firebase token -> PokoX account -> device binding -> session ticket -> game nonce.

| Level | Achieved by | Grants |
|---|---|---|
| Guest | Offline local mode | Cached single-player only |
| Basic | Firebase sign-in | Online play, library, chat, wallet read |
| Device | TOFU on a device | Spend, purchase, market orders |
| Verified | Email verified and age confirmed | Sell, publish, receive payouts |
| Developer | Verified plus registered developer key | Studio publish, BYO, share listing |
| Moderator | Verified plus separate elevation and hardware key | Poko Mod access |

## Trust on first use

First sign-in generates a device keypair in the OS keystore, sends `devicePubkey + fingerprint + sign(challenge)` to the Worker, and receives Device trust. Later sign-ins reuse the key. A new device lands at Basic and requires OTP step-up before spending. TOFU is convenience, not security; step-up is the backstop.

Device management: five trusted devices, key rotation every 90 days, revoke from any device or recovery, enforced at ticket issuance within 5 minutes.

## Account lifecycle

Immutable userId; display name changeable every 30 days. Verification sets age. Suspension preserves ledger and blocks the game plane. Ban preserves ledger and audit, blocks all access, appealable. Deletion scrubs PII after 30 days but keeps ledger rows under a hashed userId — conservation cannot be broken. Dormant after 24 months: assets retained, grants stop.

Minors: under 13 requires parental consent, no chat or Exchange, capped grants. 13–17: no Exchange, filtered chat, lower spend cap. All enforced server-side.

Developer role: keypair in Studio, 24 h cooldown before first publish. Moderator: separate elevation, hardware key, no identity exposure, monthly review, cannot be active with developer on the same session. Conflict-of-interest blocks reviewing own games.

## Session chain

Firebase ID token 1 h; Worker session ticket 30 min with userId, deviceId, trustLevel, roles; matchmaker game nonce per session; HMAC key rotates 5 min from the ticket. A game slot never accepts a Firebase token directly.

## Recovery

Email or phone OTP revokes all devices; 10 single-use recovery codes issued at Verified level; manual support appeal with identity proof as last resort, logged in audit. Recovery never restores a spent balance.

## Anti-cheat layers

1. Signed binaries and encrypted transport: Ed25519, HMAC, ChaCha20-Poly1305. Client integrity is advisory; assume compromised.
2. Server authority: `.pkB` rules, ServerOwned fields, projected hash, generic rejection.
3. Economic invariants: conservation, idempotency, caps, holds, activity proof.
4. Behavioral detection: perfect aim distribution, identical input hashes, 24/7 activity, young accounts with max payouts, device clusters, wash trades, donor anomalies. Every signal creates a case, never an instant ban.
5. Response: replay evidence, suspicion 10 resync / 25 suspend / 50 review, kill switch, key rotation.

## Threat model

| Attacker | Primary defense |
|---|---|
| Script kiddie | Authority discards client values |
| Cheat developer | Rules plus behavior; partial coverage accepted |
| Farmer | Activity proof, caps, clustering |
| Market manipulator | Ledger graph analysis, circuit breakers |
| Account thief | Device binding, step-up, short tickets |
| Malicious developer | Sandbox scan, capability audit, review |
| Malicious donor | Signed validator image, scoped token |
| Malicious moderator | Two-vote rule, immutable audit, hidden identity |
| Supply-chain attacker | Ed25519, pinned keys, two reviewers |

## Account hardening

Login velocity 5 failures/hour per IP and device. Impossible travel plus new device plus sensitive action triggers step-up. Password change revokes sessions. Ban evasion via device graph and shared payment path. Deletion keeps ledger under hash.

## Glyph map security note

Glyph tokens are public opaque strings, never parsed as numbers. Obfuscation is not security. Authenticity comes from Ed25519 signatures, not the glyph map or WordKey.

## Security testing

20-pattern red-team suite every release, 1M packets fuzzed nightly, quarterly penetration tests, Dependabot on all repos, secret scanning in CI, quarterly restore drill, key rotation drill, replay integrity check, donor isolation proof.

## Incident response

| Severity | Trigger | Action |
|---|---|---|
| SEV0 | Ledger conservation broken, registry key compromised, mass breach | Kill switch, read-only writes, rotate keys, status page |
| SEV1 | Active exploit, market manipulation, malicious node | Disable target, suspend accounts, preserve evidence |
| SEV2 | Targeted compromise, cheating cluster | Step-up, cases, review |
| SEV3 | Individual report | Standard flow |

SEV0 sequence: kill switch, Postgres read-only flag, cache invalidation, key rotation with 1 h overlap, evidence freeze to sealed R2 bucket, status update, staged fix, post-mortem.

## Tiny-task gates

SEC01 encryption, SEC04 fixed-cost rules, SEC10 kill switch are hard gates. Without them traffic leaks, rules can be weaponized, or incidents have no containment.

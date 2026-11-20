# 00 — Decision log

Every decision that was considered and settled. Includes rejected options so the same debate is not reopened.

## Platform

| Topic | Decision | Rejected |
|---|---|---|
| Authority server | Keep Hugging Face account 2. No credit card available. | Oracle Always Free (needs card) |
| Backend under quota pressure | Cloudflare Workers + D1 degraded authority | — |
| Client platforms | Android 11+, Windows 11+ | — |
| Mod platform | Windows 11+ only | — |
| Money | $0 target. Nothing to buy, nothing sold for real currency. | Paid tiers, Play Store ($25 fee) |
| Game distribution | GitHub Releases for exe/apk, R2 mirror, no GitHub API from clients | GitHub Packages, Git LFS |
| Client binaries | Full installer on GitHub, delta patches on R2 | 2 GB self-contained game bundles |
| Repository layout | Single private monorepo `Raft-The-Crab/pokox` | Multi-repo split, git submodules |
| Backend hosting | HF Space #1 = authority only; Edgegap = game sessions; Cloudflare Durable Objects = lobbies/presence | Second HF Space (unavailable to new accounts), card-required hosts |
| Supporting services | Aiven OpenSearch (~20 GB) for search, Aiven Kafka for telemetry/events, Axiom + Sentry observability | Card-required tiers (Google Cloud Run, Oracle, Render/Railway/Fly) |

## Language and runtime

| Topic | Decision | Rejected |
|---|---|---|
| Mute execution | Register-based bytecode VM on device, deterministic math, no fast-math | Transpile to C++ |
| Math library | Fixed-coefficient minimax polynomials, own runtime | libm |
| Mute hostcalls | Numbered whitelist, compiler-checked signatures, capability-gated | Arbitrary native calls |
| Standard library | Deterministic math, vec, net, ui, asset, physics, time, rng, crypto, log, storage | Wall clock, global randomness |

## Validation and network

| Topic | Decision | Rejected |
|---|---|---|
| Authority model | Declarative `.pkB` interpreted by one fixed validator binary | Running client Mute code on authority |
| Validation target | Projected state (ServerOwned, Validated, Derived), not full state | Full-state hash comparison |
| Physics split | Fixed-point sim physics + float visual physics | One physics system |
| Game transport | UDP primary, QUIC/WebTransport mobile, uWS binary fallback | TCP for realtime |
| Integrity | HMAC-SHA256 truncated 8 bytes + sequence + nonce + ackBits | XOR as security |
| FEC | XOR parity, group size 4, gameplay channel only | FEC on critical traffic |
| Encryption | ChaCha20-Poly1305 (libsodium secretbox) on game plane | Plaintext, deferred encryption |

## Rendering and apps

| Topic | Decision | Rejected |
|---|---|---|
| Primary RHI | Planned: D3D12 on supported Windows builds/devices; Vulkan on Android | Vulkan-only Windows preference |
| Fallback | Planned: Windows Vulkan then OpenGL 4.6; Android OpenGL ES 3.2 after Vulkan | No fallback |
| D3D12 | Planned Windows preference after support is built and verified; currently opt-in build flag OFF, unsupported by this project's MSYS2 configuration | Claiming runtime support before validation |
| RHI layer | DiligentCore permanent | Replacing Diligent |
| Windowing | SDL3 behind `IPlatform` | Custom SDL immediately |
| Windows app shell | Rust egui via C ABI | C++ retained-mode compositor for app chrome |
| Android app shell | Kotlin + Compose via JNI | Shared C++ UI for app chrome |
| In-game UI | C++ retained-mode runtime from UI maker | egui for shipped games |
| 2008 skin | App chrome only, token-driven, opt-in for games | Imposed on all games |
| Reference image | Layout anatomy only. No branding, avatar style, palette or assets copied. | Direct visual copy |

**2026-11-20 graphics direction:** The owner requested Windows 11 and Android 11 as product targets, with Windows D3D12 preferred when available, then Vulkan, then OpenGL. Android keeps Vulkan then OpenGL ES. This is a future goal, not a working runtime policy: the current build flag and CI remain unchanged, no GPU backend or automatic fallback is implemented, and device support must be verified. Linux is a development/test host, not a promised product target. D3D12 via translation on Linux is outside current scope. A Windows MSVC CI build can check SDK compilation but does not by itself validate real GPU execution.

## Versions and distribution

| Topic | Decision | Rejected |
|---|---|---|
| Version names | Words only, nonsense and memorable, e.g. `SecretV1?`, `Update!` | Hashes, numbers, semver, character codes |
| First release word | `publish`, globally reserved | `Update!` |
| Word to key | Public 128-bit WordKey = HMAC-SHA256(gameSalt, canonical glyph tokens)[0..16] | Secret key, plain hash, bitbuffer-as-key |
| Glyph tokens | Opaque strings, never parsed as numbers, public versioned table | Numeric interpretation of `822.25` |
| Authenticity | Ed25519 signature on manifest, pinned public key | HMAC secret for public identity |
| Ordering | Append-only registry position, never parse the word | Comparing word strings |
| Migration | Explicit word-to-word graph in manifest | Inferring from version numbers |
| Internal ABI | One numeric byte in bytecode header, never shown to users | Word-only ABI |
| Hotfix | `revision` byte inside manifest, max 3 per word | New word |

## Economy

| Topic | Decision | Rejected |
|---|---|---|
| Currency | Pokoins, virtual only, non-redeemable, non-transferable outside PokoX | Real-money purchase or cash-out |
| Weekly grant | 1,500 × R per user per week | Flat grant |
| Developer payout | Full 5 Pokoins per 2 min verified active play | Splitting play payout with shareholders (FIX F1) |
| Dividend source | 15% tax pool from that game's asset sales and share trades | Play payout |
| Tax | 85% to seller, 15% to economy | Other splits |
| Dynamic R | Velocity, gini and sink ratio, clamped 0.5–1.5, published Mondays | Fixed rate |
| Supply cap | 100,000,000 Pokoins | Unlimited |
| Ledger | Double-entry, idempotent, source of truth | Mutable balance integers |
| Exchange | Bonding curve v1, share ledger, order book v2 later | Real securities, leverage, shorting |
| In-game currency | Poko Bakery uses Buns, never Pokoins | Converting clicks to Pokoins |

## Community

| Topic | Decision | Rejected |
|---|---|---|
| Donated servers | Community donates own compute for developers to run games free | PokoX buying servers with donations |
| Donor reward | Badge, credit, reputation only | Pokoins, influence, payment |
| Donor rollout | Trusted contributors only for first 30 days | Public immediately |
| Donor trust | Untrusted hardware, signed validator image, scoped token | Trusted with ledger or identity |
| Contributor reward | CLA, DCO, two reviewers, badges and credits | Pokoins for contributions |
| Governance | RFC process, elected advisory council, no control over ledger/bans/releases | Contributor voting on core systems |

## Security

| Topic | Decision | Rejected |
|---|---|---|
| Anti-cheat | Five layers: transport, authority, economy, behavior, response | Client-side anti-cheat as authority |
| Client integrity | Advisory only, assume compromised | Trusting self-reported cleanliness |
| Bans | Suspicion thresholds, never instant auto-ban | Auto-ban on single signal |
| Moderator actions | Two distinct moderator votes | Single moderator action |
| Moderator identity | Hidden from players, reason codes only | Public moderator names |
| Hash key | Single-use, 24 h, device-bound HMAC capability | Reusable key |
| Key rotation | Annual/modified on incident, 1 h overlap | No rotation |
| Kill switch | Worker-level disable for game, market, node or all writes | No containment path |

## Final open items resolved

| Item | Resolution |
|---|---|
| Counsel review | Accepted as required before donor, Exchange and privacy ship |
| Glyph table v1 | Deterministic generator with two pinned overrides |
| Slice A game | Poko Bakery, 2D clicker, Buns never become Pokoins |
| Donor launch | Trusted contributors only for first 30 days |

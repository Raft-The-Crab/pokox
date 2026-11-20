# 18 — Contributors and community

## Contribution roles

| Role | Gives | Reward |
|---|---|---|
| Code contributor | PRs to engine, Mute, tools | Badge, credits |
| Asset artist | Texture and UI kits, avatar items | Attribution, featured slots |
| Translator | String corrections | Badge per language |
| Tester | Bug reports, early builds | Badge, early access |
| Moderator volunteer | Report review | Separate elevation, hidden identity |
| Server host | Own hardware and bandwidth | Community Host badge |
| Doc writer | Mute reference and guides | Credits |
| Template maker | Starter `.pk` projects | Featured in Studio |

Rewards are reputation and visibility, never Pokoins. Contribution earning Pokoins would be a faucet that farming systems would exploit.

## Donated servers

Community donates their own compute so developers can run games free. PokoX does not receive, buy or reimburse any money. A donor paying their own hosting bill is a personal expense, not a PokoX transaction. No "donate money" button, ever.

| Rule | Decision |
|---|---|
| Purpose | Free capacity for developers' games, never PokoX core services |
| Access | Any verified developer, no Pokoins cost |
| Allocation | Round-robin by request time, 2 concurrent slots per developer |
| Trust | Untrusted hardware running the signed validator image |
| Scope | Session state only; no ledger, identity, moderation, audit |
| Withdrawal | 24 h notice, graceful drain, no penalty |
| Credit | Optional badge, anonymous mode available |
| Anti-capture | Max 10 nodes per entity, geo-tagged and capacity-capped |
| Rollout | Trusted contributors only for first 30 days, then staged 72 h |

## Donor agreement clauses

1. Parties: donor and PokoX operator entity
2. Nature: voluntary, no payment or consideration
3. Permitted use: signed validator image and approved sessions only
4. Prohibited access: no ledger, identity, moderation, audit or other players' data
5. Credentials: scoped node token; misuse revokes immediately
6. Obligations: heartbeat, image updates, report compromise within 1 h
7. Withdrawal: 24 h notice, no penalty
8. Data handling: in-memory session state, encrypted in transit, deleted on end
9. No warranty and no SLA
10. No liability for game outcomes; operator not liable for hardware damage
11. Donor remains liable for intentional misuse or attacks from their node
12. Credit optional and anonymous on request; reputation only, never Pokoins
13. No influence: no voting, ranking boost or developer privilege
14. Termination on notice or abuse
15. Donor responsible for local law, permits, ISP terms and power costs
16. No employment relationship
17. Material changes require re-acceptance; old nodes stop after 30 days
18. Confidentiality and liability survive termination

## Governance

CLA: contributor keeps copyright and grants PokoX a perpetual royalty-free license. DCO sign-off on every commit. Two reviewers, no self-merge. RFC process for language and protocol changes with a public comment window. Elected community council advises on guidelines and events but has no authority over ledger, bans or releases. Conflict-of-interest prevents reviewing own code or own game takedown. Offboarding keeps badges and revokes access.

## Onboarding ladder

Verified account -> declare role -> accept agreement -> sandbox work with no production credentials -> submit change -> two reviewers and DCO -> credit and badge -> Trusted Contributor after 5 accepted changes -> maintainer nomination after 20 plus sustained quality. Hosts follow: donor agreement -> scoped token -> challenge -> 72 h staging -> production pool.

## Contributor portal

Dashboard with role, trust level, badges and history; agreements with versioned acceptance; repos with CI status; nodes with heartbeat, uptime and withdrawal; review queue for trusted contributors; credits profile with anonymous toggle.

## Wordlist

4,096 words or single nonsense tokens. Short, memorable and silly. Unicode letters, digits and `! ? - _`, 3–24 chars. Profanity, slurs, brand names and version-like strings excluded. Studio suggests three random words; developer picks or types their own. Unique per game and retired forever after use. First release word `publish` is globally reserved.

## Glyph table v1

Opaque token strings, never parsed as numbers. Table v1 stores version 1, separator 0x1F, generator constants and two overrides. Generator: `h = xxHash32(utf8(symbol), 0x504F4B4F)`, style `h mod 4`, a/b/c from shifted bits. Styles: `{a}.{b}?`, `{a}{b}{c}.{b}{a}`, `^{a}~{b}`, `{syllable(a)}{syllable(b)}?`. Syllables: ba, bi, bu, be, bo, na, ni, nu, ne, no. Overrides: `U -> 9.?`, `P -> 822.25`. The table is public, signed CBOR, bundled in clients.

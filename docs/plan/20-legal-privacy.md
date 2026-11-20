# 20 — Legal and privacy

**Not legal advice. This is an engineering checklist. Qualified counsel must review before launch, especially the Exchange.**

## Entity and documents

Even at $0 a registered entity is needed to be a ToS party, a DMCA agent and a privacy contact. Documents: Terms of Service, Privacy Policy, Community Guidelines, Developer Agreement, Marketplace and Exchange Terms, EULA, DMCA Policy, Moderator Code of Conduct, Children's Privacy Notice, Virtual Currency and Refund Terms. LEG-01 states whether each is drafted and marked "needs counsel".

## Virtual currency terms — highest risk

| Rule | Why |
|---|---|
| Pokoins have no cash value, cannot be bought with money or sold for money | Avoids money-transmission and securities exposure |
| Non-transferable outside PokoX | Prevents a secondary market |
| Ledger authoritative; lost or erased balances not restored | Matches the technical design |
| No refunds except as published | Must match takedown and refund rules |
| Developer Pokoins are the developer's tax responsibility | No employment or payroll relationship |
| Shares are virtual support units, not securities | No real-money buy-in, no cash-out, no promise of return |

The Exchange is the most likely part to attract regulatory attention. Use "support a game", never "invest". Dividends are Pokoins redeemable only inside PokoX. The Exchange is 18+ gated pending counsel.

## Jurisdictions

| Regime | Obligation | Plan |
|---|---|---|
| GDPR / UK GDPR | Lawful basis, DSR, 72 h breach notice, processor DPAs | Vendor DPAs and SCCs for transfers |
| CCPA / CPRA | Notice at collection, opt-out, deletion | No sale of data; clear notice |
| COPPA | Under-13 parental consent, no profiling | Age gate and restricted account tier |
| PIPL | Separate consent, localization, cross-border transfer | Region-pin PRC user data and document transfers |
| DMCA | Registered agent, counter-notice, repeat infringer | Takedown flow in publishing pipeline |

## Data map

| Data | Store | Retention | Rights |
|---|---|---|---|
| Identity, email, phone | Firebase and Postgres | Account life plus 30 d | Access, correct, delete |
| Ledger entries | Postgres | Permanent, pseudonymized on deletion | Export; no erasure, conservation |
| Device fingerprints | Postgres | 90 d after revocation | Delete on request |
| Replay rings | R2 | 30 d | Delete unless case evidence |
| Cases and audit | Postgres | Permanent | Appeal, redact PII |
| Chat | Postgres/Firestore | 30 d | Delete on request |
| Telemetry | Minimal, local to Sentry | 90 d | Opt-in, no ad profiling |
| `.pk` mirrors | GitHub | Account life | Delete on request |

Deletion scrubs PII but keeps the ledger under a hashed userId. State this in the policy so it is not a surprise.

## Privacy by design already in the architecture

Keystore-only tokens; no wall clock in sim; replay rings exclude inventory and economy fields; moderator identity hidden; no ad tracking; minimal telemetry; server-side age gates. Document each as a control in the privacy policy.

## Operational legal tasks

DPIA before launch; processor agreement checklist for every vendor; incident runbook with a 72 h clock; DMCA agent registration; guideline versioning with public changelog; transparency-report template; counsel review of Exchange terms.

## Donor and contributor documents

Donor agreement in `18-contributors.md` with 18 clauses covering voluntary contribution, scope, access limits, withdrawal, liability and no influence. Contributor CLA keeps copyright with the contributor and grants PokoX a perpetual royalty-free license. DCO sign-off required. No employment relationship in either.

## Pre-launch gates

LEG-01 document drafts exist; LEG-02 every vendor DPA has a status; LEG-03 data map published; LEG-04 DMCA agent registered; LEG-05 incident runbook and contacts; LEG-06 backup restore drill; LEG-07 security.txt and disclosure page. Counsel review is required before donors, Exchange or privacy policy ship.

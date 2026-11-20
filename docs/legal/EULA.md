> **DRAFT — NEEDS COUNSEL REVIEW.** Not legal advice. See `docs/plan/20-legal-privacy.md`.

# End User Licence Agreement (draft)

## 1. Licence granted

PokoX grants a personal, non-exclusive, non-transferable, revocable licence to use the client and bundled runtime for playing games and using the authoring tools, subject to this agreement and the Terms of Service.

## 2. Restrictions

Users may not reverse engineer the authority validator, circumvent the version signature check, extract or redistribute runtime assets outside the platform, or use the software to violate the Community Guidelines. Client integrity checks are advisory; the authority is the real enforcement point.

## 3. Open source components

The engine uses third-party components under their own licences: SDL3, DiligentCore, ImGui, spdlog, Catch2, Basis Universal, Opus and OFL fonts (Noto Sans, DejaVu Sans Mono). Segoe UI and Tahoma are not bundled. A full inventory with licence text ships with each release.

## 4. Updates

The client self-updates on Windows from a signed manifest and direct release URL, with an R2 mirror. Verification failure falls back to the last known-good binary. Android updates follow the normal APK install flow.

## 5. Termination

Access may be suspended or terminated under the Terms of Service. Ledger and audit rows are preserved.

## Open questions for counsel

- Licence inventory completeness.
- Enforceability of the reverse-engineering clause in relevant jurisdictions.

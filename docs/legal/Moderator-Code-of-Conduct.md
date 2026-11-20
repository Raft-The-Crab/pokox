> **DRAFT — NEEDS COUNSEL REVIEW.** Not legal advice. See `docs/plan/10-moderation.md` and `18-contributors.md`.

# Moderator Code of Conduct (draft)

## 1. Separate elevation

Moderator status requires a verified account, separate elevation and a hardware key. A moderator cannot be active with developer status in the same session and cannot review their own games.

## 2. Identity and safety

Moderator identity is never exposed to players. Notices use reason codes only. Claiming a report consumes a single-use, 24-hour, device-bound HMAC hash key. One key covers one case per shift. To handle growth, add keys per shift — never reusability.

## 3. Decision rules

Two distinct moderator votes are required for any punitive action. A claim and an approval may not come from the same key. Case assignment rotates. The ceiling is 100 reports per day per moderator. Claim timeout is two hours, after which the case returns to Open while the key stays consumed.

## 4. Evidence

Replay blobs are content-addressed and signed. The viewer is read-only; editing a replay destroys its evidentiary value. Cases and audit rows are append-only and exported daily to separate R2 storage.

## 5. Misconduct

Using a key to identify a moderator, acting on a conflict of interest, or altering evidence is grounds for removal and audit review.

## 6. Support

Moderator burnout is a named project risk. Case backlog growth triggers recruitment, not reusable keys.

## Open questions for counsel

- Employment and volunteer classification.
- Handling of evidence requests from authorities.

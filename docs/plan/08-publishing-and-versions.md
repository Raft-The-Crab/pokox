# 08 — Publishing, word versions and distribution

## Publishing pipeline

Build in Studio -> validate and scan -> review -> sign and package -> publish to R2 plus GitHub source mirror.

Three keys: developer key signs releases and BYO registrations; registry key signs reviewed releases; chunk CIDs identify bytes. Client trusts only the registry signature. Developer key loss triggers rotation in Postgres with a 24 h overlap.

## Local build

Compile all `.mute` to bytecode, generate `.pkB`, run determinism lint and capability audit, verify lockfile and dependency CIDs, hash sources into a canonical manifest, package `.pkx` and `.pk`, sign with developer key, upload to `POST /publish/submit`. Studio shows a preflight report before upload.

## Automated gates

Signature; recompile match; determinism lint; capability audit; `.pkB` protected-field policy; schema and migrations; malware scan with content-type sniffing and archive-bomb check; sandbox run for 1,000 generated ticks; size limits. Every rejection returns a machine reason and a human-readable Studio explanation.

## Review tiers

Tier 0: first publish, clean scan, no sensitive caps, automated only in 5 min. Tier 1: Net, Crypto or Storage beyond defaults, human review. Tier 2: marketplace, Exchange or user text, mandatory human. Tier 3: prior violation or report spike, senior moderator. Review queue capped at 50/day platform-wide, making Tier 0 essential.

## Signing and packaging

Release manifest in CBOR:

```cbor
{
  word, position, wordKey, pkxCid, pkbHash, sourceCid,
  developerSig, registrySig, caps, limits, publishedAt,
  previousWord, migrationChainHash
}
```

`.pkx` and `.pkB` go to R2 under `r2://poko-games/<cid>`. Chunks dedupe by CID. Every release is immutable. The manifest in D1 is the authoritative version pointer.

## Distribution

First install fetches manifest then only chunks needed for the current scene. Update fetches the new manifest and diffs chunk CIDs. Optional bytecode binary diff from old to new WordKey. Cloudflare caches chunks at the edge. Previously downloaded chunks remain for offline single-player.

## Word versions

Versions are words, never hashes, numbers or semver. Examples: `publish` (first release, globally reserved), `SecretV1?`, `Update!`, `WobblyMango`. Unique per game, 3–24 chars, Unicode letters, digits and `! ? - _`. No parsing of words for meaning. `SecretV1?` contains "V1" only as letters.

Ordering comes from an append-only registry position. Latest is the row with highest position in Published status. Rollback moves the live pointer to an earlier word without deletion. Patch, minor and major are abolished; schema changes are declared in the manifest, not inferred from a name. A hotfix uses a `revision` byte inside the manifest, max 3 per word (FIX F7).

## WordKey and glyph map

`WordKey = HMAC-SHA256(gameSalt, canonical)[0..16]`, a public 128-bit identifier. `canonical = 0x01 || token(S1) || 0x1F || token(S2) ...` for glyph table v1.

Glyph tokens are opaque strings, never parsed as numbers. `U -> 9.?`, `P -> 822.25`. Generator: `h = xxHash32(utf8(symbol), seed 0x504F4B4F)`, style `h mod 4`, a/b/c from shifted bits. Styles: `{a}.{b}?`, `{a}{b}{c}.{b}{a}`, `^{a}~{b}`, `{syllable(a)}{syllable(b)}?`. Syllables: `0=ba,1=bi,2=bu,3=be,4=bo,5=na,6=ni,7=nu,8=ne,9=no`. Two pinned overrides: U and P as above.

Glyph table is public, signed CBOR on Cloudflare Pages and bundled in clients. Adding or changing glyphs requires a new table version. WordKey is used for D1 index, `.pkB` header, lockfile pin, slot filter and chunk binding — never for encryption or access control. Authenticity is Ed25519 on the manifest.

## Registry schema

```sql
CREATE TABLE games (
  game_id TEXT PRIMARY KEY, developer_id TEXT NOT NULL,
  salt BLOB NOT NULL, live_word TEXT, live_position INTEGER NOT NULL DEFAULT 0,
  status TEXT NOT NULL, created_at INTEGER NOT NULL
);
CREATE TABLE releases (
  release_id INTEGER PRIMARY KEY AUTOINCREMENT, game_id TEXT NOT NULL,
  word TEXT NOT NULL, word_key BLOB NOT NULL, position INTEGER NOT NULL,
  manifest_cid TEXT NOT NULL, asset_url TEXT, pkb_hash TEXT NOT NULL,
  previous_word TEXT, developer_sig BLOB NOT NULL, registry_sig BLOB NOT NULL,
  status TEXT NOT NULL, published_at INTEGER NOT NULL,
  UNIQUE(game_id, word), UNIQUE(game_id, word_key), UNIQUE(game_id, position)
);
CREATE INDEX idx_live ON releases(game_id, position DESC) WHERE status='published';
CREATE TABLE migrations (
  game_id TEXT NOT NULL, from_word TEXT NOT NULL, to_word TEXT NOT NULL,
  transform_cid TEXT NOT NULL, added_fields TEXT, removed_fields TEXT,
  validated INTEGER NOT NULL DEFAULT 0,
  PRIMARY KEY(game_id, from_word, to_word)
);
CREATE TABLE client_builds (
  word TEXT PRIMARY KEY, position INTEGER NOT NULL, word_key BLOB NOT NULL,
  exe_url TEXT, apk_url TEXT, manifest_cid TEXT NOT NULL,
  signature BLOB NOT NULL, min_client_pos INTEGER NOT NULL, status TEXT NOT NULL
);
CREATE TABLE word_reservations (
  word TEXT NOT NULL, scope TEXT NOT NULL, game_id TEXT, reason TEXT NOT NULL,
  CHECK (scope <> 'global' OR game_id IS NULL),
  PRIMARY KEY(scope, word, game_id)
);
CREATE UNIQUE INDEX idx_word_reservations_global_word
  ON word_reservations(word) WHERE scope = 'global' AND game_id IS NULL;
```

FIX-05 implements only the reservation table and the global `publish` row in `backend/storage/d1/schema/0001_word_reservations.sql`. This D1 migration contains the seed rather than placing it in the generic `server/sql/seeds` directory from the original structure plan, because D1 owns the version registry. The partial index prevents duplicate global rows, since SQLite permits multiple NULLs in a composite primary key. The migration does not implement word normalization, reservation lookup or the first-release exception; these belong to the later validator and publishing work. The remaining registry tables above are still planned.

Publish validation: word rules, reservation lookup, uniqueness, HMAC derivation, developer signature, pkb hash match, previous word equals live word, migration exists if schema changed, atomic position assignment, publish plus pointer move in one D1 transaction, cache invalidation.

## GitHub distribution

Verified: GitHub Releases allow up to 1,000 assets per release, each under 2 GiB, no total size limit and no bandwidth limit. REST API is 60 requests/hour unauthenticated, so clients never call it.

| Rule | Decision |
|---|---|
| Contents | Full `.exe` installer and `.apk` only, plus manifest and detached signature |
| Tag | The word, e.g. `publish` or `SecretV1?` |
| Download | Direct `github.com/.../releases/download/<word>/<asset>` URL |
| Update check | `GET /client/latest` from our Worker, edge-cached in KV |
| Verification | Ed25519 signature and SHA-256 before install |
| Delta patches | On R2, keyed by WordKey pair |
| Fallback | R2 mirror of current installer |
| Android | `.apk` sideload; Play Store's $25 fee is out |

## Updates and rollback

Patch, minor and major distinctions are gone. Every release is the next word. Developer can pin "latest stable" with a 24 h delay. Live sessions keep the version they joined with; matchmaker filters slots by exact word. Rollback requires a reverse migration or an explicit noStateChange flag, moves the pointer in one transaction, writes an audit event and invalidates cache.

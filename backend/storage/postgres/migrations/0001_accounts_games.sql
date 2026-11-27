-- BAK-01: Poko Bakery Postgres schema, part 1 — accounts and games.
-- Spec 03: Aiven Postgres holds users, games, asset metadata, ledger,
-- shares, cases, audit. One source of truth per fact: balances are derived
-- (spec 09), so they live only as a rebuildable cache here.
CREATE TABLE users (
  id            BIGINT GENERATED ALWAYS AS IDENTITY PRIMARY KEY,
  handle        TEXT NOT NULL UNIQUE,
  email         TEXT UNIQUE,
  created_at    TIMESTAMPTZ NOT NULL DEFAULT now(),
  status        TEXT NOT NULL DEFAULT 'active'
                CHECK (status IN ('active', 'suspended', 'closed'))
);

CREATE TABLE games (
  id            BIGINT GENERATED ALWAYS AS IDENTITY PRIMARY KEY,
  slug          TEXT NOT NULL UNIQUE,          -- 'poko-bakery' first
  owner_id      BIGINT NOT NULL REFERENCES users(id),
  title         TEXT NOT NULL,
  created_at    TIMESTAMPTZ NOT NULL DEFAULT now()
);

CREATE TABLE assets (
  id            BIGINT GENERATED ALWAYS AS IDENTITY PRIMARY KEY,
  game_id       BIGINT NOT NULL REFERENCES games(id),
  kind          TEXT NOT NULL CHECK (kind IN ('mesh', 'texture', 'audio', 'script')),
  content_hash  TEXT NOT NULL,                 -- sha-256 of the .pkx payload
  size_bytes    BIGINT NOT NULL CHECK (size_bytes >= 0),
  created_at    TIMESTAMPTZ NOT NULL DEFAULT now(),
  UNIQUE (game_id, content_hash)
);

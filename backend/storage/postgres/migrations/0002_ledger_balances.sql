-- BAK-01: part 2 — the Pokoins ledger and derived balances (spec 09).
-- Invariant: for every tx_id, sum(delta) = 0 (the `void` account receives
-- taxes and sinks, making conservation provable). Balances are a cache.
CREATE TABLE ledger_entries (
  id            BIGINT GENERATED ALWAYS AS IDENTITY PRIMARY KEY,
  tx_id         TEXT NOT NULL,
  account       TEXT NOT NULL,                 -- e.g. 'user:1', 'system:mint', 'void'
  account_type  TEXT NOT NULL CHECK (account_type IN
                ('player', 'developer', 'system', 'void', 'escrow')),
  delta         BIGINT NOT NULL,
  currency      TEXT NOT NULL DEFAULT 'pokoins',
  idem_key      TEXT UNIQUE,                   -- double-credit guard (spec 09)
  meta          JSONB NOT NULL DEFAULT '{}',
  created_at    TIMESTAMPTZ NOT NULL DEFAULT now()
);

CREATE INDEX idx_ledger_tx ON ledger_entries (tx_id);
CREATE INDEX idx_ledger_account ON ledger_entries (account, created_at);

CREATE TABLE balances (
  account       TEXT PRIMARY KEY,
  balance       BIGINT NOT NULL DEFAULT 0 CHECK (balance >= 0),
  updated_at    TIMESTAMPTZ NOT NULL DEFAULT now()
);

CREATE TABLE share_entries (
  id            BIGINT GENERATED ALWAYS AS IDENTITY PRIMARY KEY,
  tx_id         TEXT NOT NULL,
  game_id       BIGINT NOT NULL REFERENCES games(id),
  account       TEXT NOT NULL,
  delta         BIGINT NOT NULL,
  price         BIGINT NOT NULL,
  idem_key      TEXT UNIQUE,
  created_at    TIMESTAMPTZ NOT NULL DEFAULT now()
);

CREATE INDEX idx_shares_game_account ON share_entries (game_id, account);

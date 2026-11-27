-- BAK-01: part 3 — moderation cases and audit trail (spec 03, 10).
CREATE TABLE cases (
  id            BIGINT GENERATED ALWAYS AS IDENTITY PRIMARY KEY,
  subject       TEXT NOT NULL,                 -- account or game reference
  signal        TEXT NOT NULL,                 -- which detector fired
  detail        JSONB NOT NULL DEFAULT '{}',
  state         TEXT NOT NULL DEFAULT 'open'
                CHECK (state IN ('open', 'reviewing', 'closed')),
  created_at    TIMESTAMPTZ NOT NULL DEFAULT now()
);

CREATE TABLE audit_log (
  id            BIGINT GENERATED ALWAYS AS IDENTITY PRIMARY KEY,
  actor         TEXT NOT NULL,
  action        TEXT NOT NULL,
  subject       TEXT NOT NULL,
  detail        JSONB NOT NULL DEFAULT '{}',
  created_at    TIMESTAMPTZ NOT NULL DEFAULT now()
);

CREATE INDEX idx_audit_actor ON audit_log (actor, created_at);

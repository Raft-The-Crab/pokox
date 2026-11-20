-- D1 registry migration: reserve the first-release word globally.
-- Apply once using the D1 migration runner; validation is a separate task.
CREATE TABLE word_reservations (
  word TEXT NOT NULL,
  scope TEXT NOT NULL,
  game_id TEXT,
  reason TEXT NOT NULL,
  CHECK (scope <> 'global' OR game_id IS NULL),
  PRIMARY KEY (scope, word, game_id)
);

-- SQLite permits multiple NULL values in composite primary keys. A partial
-- unique index prevents duplicate global reservations despite the NULL game_id.
CREATE UNIQUE INDEX idx_word_reservations_global_word
  ON word_reservations (word)
  WHERE scope = 'global' AND game_id IS NULL;

INSERT INTO word_reservations (word, scope, game_id, reason)
VALUES ('publish', 'global', NULL, 'Reserved for first releases');

#!/usr/bin/env bash
# BAK-01: apply the Postgres migrations in filename order, once each.
# The schema_migrations table makes re-runs idempotent (the acceptance is
# "migrations apply" — and keep applying cleanly).
set -euo pipefail
DB_URL="${DB_URL:-postgres://ubuntu:ubuntu@localhost:5432/app}"
DIR="$(cd "$(dirname "$0")/migrations" && pwd)"

psql "$DB_URL" -v ON_ERROR_STOP=1 -c "
  CREATE TABLE IF NOT EXISTS schema_migrations (
    name TEXT PRIMARY KEY, applied_at TIMESTAMPTZ NOT NULL DEFAULT now());"

for f in "$DIR"/*.sql; do
  name="$(basename "$f")"
  applied="$(psql "$DB_URL" -tA -c "SELECT 1 FROM schema_migrations WHERE name='$name';")"
  if [ "$applied" = "1" ]; then
    echo "skip  $name (already applied)"
  else
    psql "$DB_URL" -v ON_ERROR_STOP=1 -q -f "$f"
    psql "$DB_URL" -v ON_ERROR_STOP=1 -q -c "INSERT INTO schema_migrations (name) VALUES ('$name');"
    echo "apply $name"
  fi
done

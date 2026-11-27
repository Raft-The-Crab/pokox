# Backend

Backend integration, edge Workers, storage adapters, operational jobs and infrastructure. Most directories are placeholders and do not establish deployed services.

The D1 registry migration at `storage/d1/schema/0001_word_reservations.sql` creates the reservation table and reserves `publish` globally for first releases. Configure a future D1 binding to use this directory as its migrations directory and apply the migration using the tracked D1 migration runner; do not run the SQL twice directly. SQLite integration tests run through CTest. The migration is not a deployment or a word validator: lookup and the first-release exception remain future work.

The canonical Postgres schema (BAK-01) is at `storage/postgres/`: three migrations covering users, games, assets, the Pokoins ledger with its double-credit `idem_key` guard (spec 09), derived balances, shares, moderation cases and the audit log. `migrate.sh` applies them in filename order and is safe to re-run (the `schema_migrations` table tracks what applied); acceptance was verified against real Postgres 18.6. Not a deployment: connection wiring and the serving layer are future tasks (BAK-02+).

See the [architecture plan](../docs/plan/03-architecture.md) and [work queue](../docs/plan/02-work-queue.md).

# Backend

Backend integration, edge Workers, storage adapters, operational jobs and infrastructure. Most directories are placeholders and do not establish deployed services.

The D1 registry migration at `storage/d1/schema/0001_word_reservations.sql` creates the reservation table and reserves `publish` globally for first releases. Configure a future D1 binding to use this directory as its migrations directory and apply the migration using the tracked D1 migration runner; do not run the SQL twice directly. SQLite integration tests run through CTest. The migration is not a deployment or a word validator: lookup and the first-release exception remain future work.

See the [architecture plan](../docs/plan/03-architecture.md) and [work queue](../docs/plan/02-work-queue.md).

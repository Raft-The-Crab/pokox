"""SQLite-level tests for the D1 word-reservation migration."""

import pathlib
import sqlite3
import unittest

MIGRATION = pathlib.Path(__file__).resolve().parents[2] / "schema" / "0001_word_reservations.sql"


class ReservationMigrationTests(unittest.TestCase):
    def setUp(self):
        self.db = sqlite3.connect(":memory:")
        self.addCleanup(self.db.close)
        self.sql = MIGRATION.read_text(encoding="utf-8")
        self.db.executescript(self.sql)

    def test_first_release_word_is_globally_reserved(self):
        rows = self.db.execute(
            "SELECT word, scope, game_id, reason FROM word_reservations"
        ).fetchall()
        self.assertEqual(rows, [("publish", "global", None, "Reserved for first releases")])

    def test_global_reservation_is_unique_even_with_null_game_id(self):
        with self.assertRaises(sqlite3.IntegrityError):
            self.db.execute(
                "INSERT INTO word_reservations VALUES (?, ?, ?, ?)",
                ("publish", "global", None, "duplicate"),
            )

    def test_global_reservation_cannot_name_a_game(self):
        with self.assertRaises(sqlite3.IntegrityError):
            self.db.execute(
                "INSERT INTO word_reservations VALUES (?, ?, ?, ?)",
                ("other", "global", "game-1", "invalid global scope"),
            )

    def test_game_reservations_have_independent_scope(self):
        sql = "INSERT INTO word_reservations VALUES (?, ?, ?, ?)"
        self.db.execute(sql, ("other", "game", "game-1", "test"))
        self.db.execute(sql, ("other", "game", "game-2", "test"))
        with self.assertRaises(sqlite3.IntegrityError):
            self.db.execute(sql, ("other", "game", "game-1", "duplicate"))

    def test_direct_reapplication_fails_instead_of_masking_schema_conflict(self):
        with self.assertRaises(sqlite3.OperationalError):
            self.db.executescript(self.sql)
        self.assertEqual(
            self.db.execute("SELECT count(*) FROM word_reservations WHERE word = 'publish' AND scope = 'global' AND game_id IS NULL").fetchone()[0], 1
        )


if __name__ == "__main__":
    unittest.main()

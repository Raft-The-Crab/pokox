# Unsigned `.pkB` schema preview

`poko_mute_pkb_schema_draft` is an early aid for future `.pkB` work. It inspects declarations in a valid current-subset Mute source and emits a deterministic CBOR **preview**, not an actual `.pkB`:

```sh
poko_mute_pkb_schema_draft mute/tests/fixtures/state-demo.mute > example.schema-draft.cbor
```

The tool writes a warning to stderr, emits nothing for a rejected source, limits input to 65,536 bytes, and returns nonzero on error. `poko::mute::make_pkb_schema_draft(source)` exposes the same preview in C++. The preview is not signed, has no `PKB1` production header, and must never be published, installed, or used by an authority to accept/reject game state.

The canonical CBOR object has `kind: "poko.pkb.schema-draft"`, `draft: true`, `version: 1`, and `fields`, an array of `{name, type: "i32"}` in declaration order. These are simply state declarations: the preview does **not** assert that they are replicated. It does not assign stable field IDs, policies, rules, bit widths, limits, bytecode hashes, capabilities, game identity, signing keys or signatures. The syntax/schema inspection is not a verifier or a full compiler and does not authorize field values. The CBOR golden was checked against independent `cbor2` canonical output.

A real declarative `.pkB` remains dependent on the full compiler, explicit replication and field metadata, and the approved identity and signing workflow. The authority side has since landed: BAK-05's `PkbAuthority` rejects invalid positions and out-of-width proposals from the loaded schema, BAK-06 evaluates fixed-cost assert rules, and BAK-07 verifies the projected hash and sequence window. No security controls are silently defaulted or bypassed here.

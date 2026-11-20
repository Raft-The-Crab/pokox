# 27 — Engine scene

## Scene model

A scene is a named graph of entities with transforms, components and references to assets. It is data, serialized to CBOR and stored in `.pkx`. The runtime loads a scene into the ECS; it does not interpret the source format at runtime. A scene has a root entity and may reference prefabs by CID.

## Transform hierarchy

Every entity has an optional parent. Local transforms are translated into world transforms in parent-before-child order, sorted by entity index. The order is a determinism requirement when transforms feed validated state. A cycle is rejected at load. Detaching reparents to the scene root and increments the entity's change generation.

## Prefabs

A prefab is a template entity with components and overrides, stored as a separate CBOR asset. Instantiating a prefab creates entities with a `prefabCid` and a set of overridden properties. Shared prefab chunks dedupe by CID in R2. Updating a prefab does not automatically update instances; the developer publishes a new version and chooses which scenes rebase.

## Scene serialization

```cbor
{
  "schemaWord": "WobblyMango",
  "root": 1,
  "entities": [
    { "id": 1, "name": "Arena", "components": { "transform": ..., "mesh": ... } },
    { "id": 2, "parent": 1, "prefabCid": "...", "overrides": { "scale": 2.0 } }
  ]
}
```

Unknown fields are skipped with a warning; missing required fields fail. A scene written with an older schema word must have a registered migration to the current word. The word-version registry is the source of truth, not a numeric schema version.

## Scene streaming

Scenes are divided into zones with declared bounds and asset lists. The client loads the current zone's chunks first and prefetches adjacent zones based on player position and friends' activity. Zone transitions happen at a boundary with a short loading state; no geometry pops. The authority loads only the zone data needed for validation, not meshes or textures.

## Tags and layers

Entities carry up to eight tags and one collision layer. Tags are interned strings; layers are integers from a developer-defined table. Tags drive query filters, area-of-interest rules and audio occlusion portals. Layers drive collision masks in the sim solver.

## Queries

Scene queries are cached ECS queries with `Includes`, `Excludes` and optional tag filters. Mute `world.query(Player)` compiles to a cached query id. Iteration is always ascending entity index. A query that returns an entity the caller cannot access by capability is filtered at compile time, not runtime.

## Save state

Two kinds of persistence: scene state (which zone, which entities are alive) and gameplay state (`@state` fields with `ServerOwned` or persistent `Validated` policy). Scene state is a lightweight CBOR blob; gameplay state is serialized by the Mute VM into the projected state format. Both go to Postgres for online sessions and local disk with a pending-sync marker for offline play. The server copy always wins a conflict.

## Editor integration

Studio's scene editor edits the CBOR through a command stack: add entity, delete entity, reparent, add or remove component, edit property, instantiate prefab, rebase prefab. Every command is undoable and produces a minimal patch. Hot reload applies the patch to a running preview without resetting `@state` if the schema word is unchanged.

Gizmos: translate, rotate, scale, with snap and local or world space. Selection is by click, rect or query string. The outliner shows the entity tree with visibility, lock and prefab badges.

## Runtime lifecycle

Load scene -> resolve prefabs -> apply migrations -> build ECS archetypes -> compute world transforms -> resolve asset handles -> fire scene-ready events -> begin tick loop. Unload reverses the order, releasing assets after the GPU fence and saving pending state first.

## Determinism boundary

Entity indices, component order and query iteration are part of the determinism contract. The authority builds the same scene from the same CBOR and reaches the same indices. A developer cannot rely on creation order that differs between client and authority; scene serialization sorts entities by id before writing.

## Limits

16,384 entities per scene, 32 components per entity, 8 tags, 64 layers, 256 prefabs per game, 4 zones per scene, scene CBOR under 16 MB.

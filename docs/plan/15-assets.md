# 15 — Asset pipeline

## Contract

Studio imports developer source assets and converts them to PokoX runtime formats. The runtime never parses PNG, WAV or FBX. Conversion happens once at publish; `.pkx` carries only runtime-ready chunks. Same source plus same settings must always produce the same CID.

## Source to runtime

| Source | Runtime | Notes |
|---|---|---|
| PNG/JPEG/TGA | KTX2 with Basis Universal | Transcodes to ASTC/ETC2/BC7 on device |
| WAV/FLAC/MP3 | Opus in Ogg | Streaming for music, decoded for SFX |
| OBJ/FBX/glTF | PokoMesh binary | Quantized positions and normals |
| TTF/OTF | PokoFont, SDF atlas plus metrics | Scalable text |
| glTF animations | PokoAnim | Quantized delta-encoded tracks |
| JSON/CBOR | CBOR | Config data |

Basis Universal is key: one texture works on Vulkan, GL/ES and any future D3D12 build. One upload, universal compatibility.

## Import settings

| Setting | Options | Default |
|---|---|---|
| Texture max size | 512, 1K, 2K, 4K | 2K, mobile override 1K |
| Mipmaps | on/off | on |
| Texture streaming | on/off | on above 1K |
| Audio quality | 64/96/128 kbps | 96 |
| Audio streaming | music/SFX | by duration |
| Mesh quantization | 8/12/16 bit | 12 |
| Mesh compression | none/delta | delta |

Settings live in `.meta`; re-import of unchanged source with same settings yields the same CID.

## Texture handling

KTX2 plus Basis Universal, mipmaps generated at import, streaming loads base mip first. Memory budget 512 MB Windows, 256 MB Android with LRU eviction. UI sprites packed into atlases. Color space declared in `.meta`: sRGB for albedo, linear for normal and roughness.

## Audio handling

Opus in Ogg for music and SFX. Tracks over 10 s stream from chunk; shorter decode fully. Voice is live through the net stack, not a stored asset. Engine applies 3D positioning from Mute `audio.*` hostcalls. Master, music, SFX and voice buses. Budget 128 MB Windows, 64 MB Android decoded.

## Mesh handling

PokoMesh stores quantized positions (12-bit default), octahedral normals, 16-bit UVs and vertex colors. Indices delta-encoded. Skeleton and skin weights in a separate section. Up to four LOD levels generated at import. Collision uses separate simplified colliders authored by the developer; the render mesh is never used for deterministic physics.

## Fonts and text

SDF atlases render crisply at any size from one small texture. Glyph subsetting includes only characters used by the game's UI strings and Mute literals. A CJK game ships only needed glyphs. Missing glyph falls back through game font, platform font, system font, then a visible tofu box with a warning.

## Chunk packing

```
pkx/
  manifest.cbor
  chunks/<cid>.chunk
  debug/                # not shipped
```

Chunk table declares `cid, type, size, sceneTags, priority`. `sceneTags` enable fetching only chunks for the current scene. `priority` drives download order. Chunks dedupe globally by CID in R2; a shared UI kit or font subset is stored once.

## CDN and caching

Cloudflare fronts R2. CID-named chunks are immutable: `Cache-Control: immutable, max-age=31536000`. A game update changes only the chunks whose bytes changed. R2 zero egress; Cloudflare cache reduces origin hits. Range requests supported for streaming audio.

## Size budgets after the architecture correction

Game sizes are far smaller than once assumed because the engine, Mute VM, UI runtime and net stack are compiled into the client app. A `.pkx` ships only bytecode, schema, compiled UI and assets.

| Item | Target | Hard cap |
|---|---|---|
| Client app | 100–300 MB | — |
| `.pkx` per game | 5–50 MB typical | 500 MB |
| Chunk | 1–8 MB typical | 50 MB |
| First-launch download | <= 50 MB | — |
| Texture memory | 512 MB PC, 256 MB phone | — |
| Audio memory | 128 MB PC, 64 MB phone | — |

## Limits

10,000 assets/game, 50 MB source file, 4,096 px converted texture, 4 LOD levels, 2,000 chunks/game, 65,536 glyphs, seven audited import formats.

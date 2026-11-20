# 12 — App interface (egui and Kotlin)

## Boundary

App chrome is not rendered by the C++ UI runtime. Windows shells use Rust egui through a C ABI. Android shells use Kotlin with Jetpack Compose through JNI. The C++ retained-mode UI runtime serves only in-game UI from the UI maker. Poko Mod is Windows-only and uses egui.

## Windows egui bridge

Rust crate `poko_shell` builds as a staticlib, linked by CMake. cbindgen generates the header. Only C structs and function pointers cross the boundary.

```c
typedef struct PokoHost {
    void (*log)(uint32_t level, const char* msg, uint32_t len);
    int32_t (*request)(uint64_t id, const char* method, uint32_t mlen,
                       const char* url, uint32_t ulen,
                       const uint8_t* body, uint32_t blen);
    void (*on_response)(uint64_t id, const uint8_t* data, uint32_t len, int32_t err);
    int32_t (*action)(uint64_t id, const uint8_t* payload, uint32_t len);
} PokoHost;

int32_t poko_shell_create(const PokoConfig*, PokoShell** out);
int32_t poko_shell_push_event(PokoShell*, const PokoEvent*);
int32_t poko_shell_frame(PokoShell*, float dt, PokoFrame* out);
int32_t poko_shell_release(PokoShell*, const PokoFrame*);
void    poko_shell_destroy(PokoShell*);
```

Frame output carries `PokoMesh { vertices, indices, textureId }` with vertices `x,y,u,v,packedRGBA`, plus texture deltas for the font and icon atlases, a cursor icon and a `wantsRepaint` flag. The engine draws these in a final Vulkan UI pass — one pipeline, one vertex upload, at most 64 draw calls.

## Safety rules

Every export wraps `catch_unwind`; no Rust panic crosses into C++. Engine never frees Rust memory; exported release does it. Strings are UTF-8 with explicit length. Shell runs on the UI thread only. ABI version is checked at create. A reentrancy guard returns -5 if a host callback calls back into the shell. Release frame is wrapped in a C++ RAII guard.

Error codes: 0 success, -1 null, -2 shell error, -3 panic caught, -4 ABI mismatch, -5 reentrant.

## Input mapping

SDL3 motion, button, wheel, key, text, resize and focus events map to `PokoEvent`. Coordinates divide by DPI scale. Text input must be enabled for IME and CJK typing. Key repeat is handled by egui.

## Rendering

Texture deltas upload RGBA into Vulkan images keyed by textureId; zero length means dispose. Font atlas is texture id 1. All meshes merge into one vertex/index upload. The UI pipeline has no depth, alpha blending on, and a viewport push constant.

## Theming

`theme.rs` builds `egui::Style` from the token file: zero rounding, 1 px bevel strokes, gradient fills via custom widgets `PokoBevelButton`, `PokoGlossPanel`, `PokoTabStrip`. Classic and Flat are two Style values. Bundle OFL fonts (Noto Sans, DejaVu Sans Mono). Do not bundle Segoe UI or Tahoma — licensing.

## Android Kotlin bridge

| JNI method | Behavior |
|---|---|
| nativeCreate(config) -> jlong | Opaque engine handle, error code on failure |
| nativeFrame(handle, dt) | Advance sim; render into supplied ANativeWindow |
| nativeInput(handle, event) | Motion, key, text from Compose or surface |
| nativeAuthToken(handle, token) | Firebase ID token after sign-in |
| nativePause/Resume/Destroy | Map Activity callbacks |
| PokoHost callback interface | C++ to Kotlin events: state changed, error, replay ready |

Complex data crosses as CBOR blobs. C++ exceptions are caught at the boundary. Kotlin owns Activity, permissions, Firebase Auth and settings; C++ owns engine, Mute, net and assets. The game viewport is an SDL3 surface embedded in the layout with Compose chrome layered above.

## 2008 + modern rule

The 2008 aesthetic is the visual layer; modern is the invisible contract. Beveled panels and glossy buttons sit on constraint layout, DPI awareness, 44 dp touch targets, focus rings, WCAG contrast, dark-mode tokens and reduced motion. The skin is a token set, not hardcoded colors.

## Shell anatomy

Title bar with app icon and standard controls; classic menu bar with accelerators; toolbar icon strips with tooltips; draggable tabbable docking panes; status bar with build state, wallet summary and connection quality; taskbar game strip in the client; glossy toast notifications.

## App surfaces

PokoX client: library, store, marketplace, Exchange ticker, wallet history, social overlay, game viewport. Poko Studio: project tree, viewport, inspector, timeline, console, Trust Inspector, replay debugger. Poko Mod: live games, drill-down tree, replay viewer, case board, audit viewer, detector stats.

## Test gates

Visual regression at 1280x720 and Android viewport for both token sets; DPI matrix 100/125/150/200%; keyboard-only traversal; pseudo-localization and RTL flip; 5,000-node window composited under 16.6 ms.

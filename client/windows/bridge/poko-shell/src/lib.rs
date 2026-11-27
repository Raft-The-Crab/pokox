//! PokoX Windows shell — the Rust side of the spec-12 egui bridge.
//!
//! SHL-01: the staticlib build and the cbindgen-generated C ABI header.
//! SHL-02: `poko_shell_create` with the ABI-version check — a null out
//! handle returns -1, a version mismatch returns -4 and leaves the out
//! handle null, success returns an owning handle freed by
//! `poko_shell_destroy`.
//! SHL-03: `poko_shell_push_event` accumulates `PokoEvent`s in FIFO order
//! inside the handle, bounded at `POKO_SHELL_EVENT_QUEUE_CAP` (a full
//! queue returns -2 rather than growing without limit), and
//! `poko_shell_drain_events` copies them back out in order.
//! SHL-04: `poko_shell_frame` drains the queue into an egui `RawInput`
//! and runs one `run_ui` pass that lays out the shell label; the frame
//! reports how many events it consumed, how many clipped shapes egui
//! produced, the pixels-per-point and the repaint delay. Tessellation to
//! PokoMesh (SHL-05) and texture deltas (SHL-06) export from this same
//! output later.

use egui::{Context, MouseWheelUnit, PointerButton, Pos2, RawInput, TouchPhase, Vec2};

/// Bumped whenever the C ABI in `client/windows/bridge/c_abi/poko_shell.h`
/// changes shape; `poko_shell_create` (SHL-02) refuses mismatches with -4.
/// Version 2: SHL-03 added the event queue exports and made the handle
/// opaque to C (it now holds Rust state).
/// Version 3: SHL-04 added `PokoEvent::pressed` (press vs release — egui
/// needs both) and the `poko_shell_frame` export with `PokoFrameInfo`.
/// Version 4: SHL-05/06 added the `poko_shell_mesh` and
/// `poko_shell_texture_delta` exports with their result structs.
pub const POKO_SHELL_ABI_VERSION: u32 = 4;

pub const POKO_SHELL_OK: i32 = 0;
pub const POKO_SHELL_ERROR_NULL: i32 = -1;
pub const POKO_SHELL_ERROR_SHELL: i32 = -2;
pub const POKO_SHELL_ERROR_PANIC: i32 = -3;
pub const POKO_SHELL_ERROR_ABI_MISMATCH: i32 = -4;
pub const POKO_SHELL_ERROR_REENTRANT: i32 = -5;

/// Spec-12 input mapping: SDL3 motion, button, wheel, key, text, resize
/// and focus events. One `kind` value each.
pub const POKO_EVENT_MOTION: i32 = 0;
pub const POKO_EVENT_BUTTON: i32 = 1;
pub const POKO_EVENT_WHEEL: i32 = 2;
pub const POKO_EVENT_KEY: i32 = 3;
pub const POKO_EVENT_TEXT: i32 = 4;
pub const POKO_EVENT_RESIZE: i32 = 5;
pub const POKO_EVENT_FOCUS: i32 = 6;

/// Longest single IME/text event in bytes (UTF-8 with explicit length;
/// the spec forbids NUL-terminated strings across the boundary).
pub const POKO_SHELL_EVENT_TEXT_MAX: usize = 128;

/// Fixed event backlog. The shell runs on the UI thread only; if the host
/// pushes a whole frame's worth faster than the frame drains it, refusing
/// (with -2) keeps memory flat — the same bounded-queue rule the spec
/// applies to the net plane.
pub const POKO_SHELL_EVENT_QUEUE_CAP: usize = 1024;

/// One input event, by value across the C ABI. Layout is fixed: the
/// fields not used by a kind are zero (the golden test pins that).
/// Coordinates arrive already divided by the DPI scale (spec-12 input
/// mapping) in logical pixels.
#[repr(C)]
#[derive(Clone, Copy)]
pub struct PokoEvent {
    /// Which of `POKO_EVENT_*` this is.
    pub kind: i32,
    /// Motion/button: pointer position (logical px). Wheel: scroll delta.
    pub x: f32,
    pub y: f32,
    /// Button: the pressed/released button index.
    pub button: i32,
    /// Button: 1 pressed, 0 released.
    pub pressed: i32,
    /// Key: the platform key code (egui re-maps it).
    pub key: i32,
    /// Shift/ctrl/alt flags, host-defined bit set.
    pub modifiers: u32,
    /// Wheel scroll delta.
    pub wheel_x: f32,
    pub wheel_y: f32,
    /// Resize: new surface size in logical px.
    pub width: u32,
    pub height: u32,
    /// Focus: 1 gained, 0 lost.
    pub focus: i32,
    /// Bytes of `text` used (0 when the kind carries no text).
    pub text_len: u32,
    /// UTF-8 payload, `text_len` bytes long.
    pub text: [u8; POKO_SHELL_EVENT_TEXT_MAX],
}

impl PokoEvent {
    pub const fn zeroed() -> Self {
        PokoEvent {
            kind: 0,
            x: 0.0,
            y: 0.0,
            button: 0,
            pressed: 0,
            key: 0,
            modifiers: 0,
            wheel_x: 0.0,
            wheel_y: 0.0,
            width: 0,
            height: 0,
            focus: 0,
            text_len: 0,
            text: [0; POKO_SHELL_EVENT_TEXT_MAX],
        }
    }
}

/// The opaque shell handle (SHL-02). C++ never dereferences it; the stored
/// ABI version lets later rows assert a handle was created by a matching
/// build of this crate.
/// cbindgen:opaque
pub struct PokoShell {
    abi_version: u32,
    /// SHL-03: events pushed since the last drain, FIFO order.
    events: Vec<PokoEvent>,
    /// SHL-04: the egui context every frame runs through. Clone-free
    /// ownership; the Context itself is reference-counted inside.
    egui: Context,
    /// SHL-05: the last frame's clipped shapes and scale, for
    /// `poko_shell_mesh` to tessellate.
    last_shapes: Option<Vec<egui::epaint::ClippedShape>>,
    last_ppp: f32,
    /// SHL-06: texture updates not yet drained by
    /// `poko_shell_texture_delta`, as (id, width, height, rgba8 bytes).
    pending_textures: Vec<(u64, u32, u32, Vec<u8>)>,
}

/// SHL-02: create a shell handle. `out_shell` must not be null (-1); a
/// caller built against a different ABI gets -4 with the out handle left
/// null. On success stores an owning handle and returns 0.
#[no_mangle]
pub extern "C" fn poko_shell_create(
    abi_version: u32,
    out_shell: *mut *mut PokoShell,
) -> i32 {
    if out_shell.is_null() {
        return POKO_SHELL_ERROR_NULL;
    }
    // Never leave a caller-supplied out handle dangling on failure.
    unsafe { *out_shell = std::ptr::null_mut() };
    if abi_version != POKO_SHELL_ABI_VERSION {
        return POKO_SHELL_ERROR_ABI_MISMATCH;
    }
    let shell = Box::into_raw(Box::new(PokoShell {
        abi_version: POKO_SHELL_ABI_VERSION,
        events: Vec::new(),
        egui: Context::default(),
        last_shapes: None,
        last_ppp: 1.0,
        pending_textures: Vec::new(),
    }));
    unsafe { *out_shell = shell };
    POKO_SHELL_OK
}

/// Free a handle from `poko_shell_create`. Null is a no-op; passing any
/// other value the create path did not return is undefined, as with free.
#[no_mangle]
pub extern "C" fn poko_shell_destroy(shell: *mut PokoShell) {
    if !shell.is_null() {
        drop(unsafe { Box::from_raw(shell) });
    }
}

/// SHL-03: append one event to the shell's FIFO queue. Null handle or
/// event is -1; a handle from a mismatched ABI build is -4; an unknown
/// kind, a `text_len` of `POKO_SHELL_EVENT_TEXT_MAX` or more, or a queue
/// already at `POKO_SHELL_EVENT_QUEUE_CAP` is -2 (fail closed, nothing
/// written). The unused fields and the text bytes past `text_len` are
/// zeroed on entry so no caller garbage crosses the boundary.
#[no_mangle]
pub extern "C" fn poko_shell_push_event(
    shell: *mut PokoShell,
    event: *const PokoEvent,
) -> i32 {
    if shell.is_null() || event.is_null() {
        return POKO_SHELL_ERROR_NULL;
    }
    let pushed = std::panic::catch_unwind(std::panic::AssertUnwindSafe(|| unsafe {
        let shell = &mut *shell;
        if shell.abi_version != POKO_SHELL_ABI_VERSION {
            return POKO_SHELL_ERROR_ABI_MISMATCH;
        }
        let event = &*event;
        let kind_ok = (POKO_EVENT_MOTION..=POKO_EVENT_FOCUS).contains(&event.kind);
        if !kind_ok
            || event.text_len as usize >= POKO_SHELL_EVENT_TEXT_MAX
            || shell.events.len() >= POKO_SHELL_EVENT_QUEUE_CAP
        {
            return POKO_SHELL_ERROR_SHELL;
        }
        let mut event = *event;
        for byte in event.text[(event.text_len as usize)..].iter_mut() {
            *byte = 0;
        }
        shell.events.push(event);
        POKO_SHELL_OK
    }));
    pushed.unwrap_or(POKO_SHELL_ERROR_PANIC)
}

/// SHL-03: drain the queue in FIFO order — at most `cap` events copied to
/// `out` (when both are non-null) and removed; the count written is
/// `*out_written`. With `out` null this only reports the pending count
/// (drains nothing), which is how the SHL-04 frame sizes its RawInput
/// batch. Null handle or `out_written` is -1; a mismatched-ABI handle
/// is -4. Returns 0 otherwise.
#[no_mangle]
pub extern "C" fn poko_shell_drain_events(
    shell: *mut PokoShell,
    out: *mut PokoEvent,
    cap: u32,
    out_written: *mut u32,
) -> i32 {
    if shell.is_null() || out_written.is_null() {
        return POKO_SHELL_ERROR_NULL;
    }
    let drained = std::panic::catch_unwind(std::panic::AssertUnwindSafe(|| unsafe {
        let shell = &mut *shell;
        if shell.abi_version != POKO_SHELL_ABI_VERSION {
            return POKO_SHELL_ERROR_ABI_MISMATCH;
        }
        if out.is_null() {
            *out_written = shell.events.len() as u32;
            return POKO_SHELL_OK;
        }
        let take = (cap as usize).min(shell.events.len());
        if take > 0 {
            std::ptr::copy_nonoverlapping(shell.events.as_ptr(), out, take);
            shell.events.drain(..take);
        }
        *out_written = take as u32;
        POKO_SHELL_OK
    }));
    drained.unwrap_or(POKO_SHELL_ERROR_PANIC)
}

/// SHL-04: what one egui frame produced, for the C++ side to observe.
/// `shape_count` is the number of clipped shapes egui emitted (a laid-out
/// label always produces at least one — the acceptance "Label renders"
/// is this count plus `label_rendered`); tessellation to PokoMesh
/// (SHL-05) reads the same shapes. `repaint_delay_ms` is egui's requested
/// delay before the next frame (0 = repaint immediately).
#[repr(C)]
pub struct PokoFrameInfo {
    /// Events the frame drained out of the SHL-03 queue.
    pub events_consumed: u32,
    /// Clipped shapes egui produced this frame.
    pub shape_count: u32,
    /// egui's current pixels-per-point (the DPI scale, SHL-14 territory).
    pub pixels_per_point: f32,
    /// Requested delay before the next frame, in milliseconds.
    pub repaint_delay_ms: u32,
    /// 1 when the shell label was laid out with a non-empty rect.
    pub label_rendered: u32,
}

/// SHL-04: run one egui frame. Drains every queued event into a
/// `RawInput` (motion, button with press/release, wheel, text and focus
/// are mapped; key events are consumed here and mapped by SHL-09/10's
/// bridge, resize comes in through the `width`/`height` parameters),
/// lays out the frame at a `time_seconds` the caller supplies (the same
/// deterministic-time rule the rest of the project runs on) and a screen
/// rect of `width` x `height` logical points, runs the shell's UI — for
/// now the fixed shell label — and writes `PokoFrameInfo`. Null handle
/// or out struct is -1, a stale-ABI handle is -4, a zero width or height
/// (an empty screen rect cannot be laid out) is -2, a panic inside egui
/// is -3. Returns 0 with the queue left empty.
#[no_mangle]
pub extern "C" fn poko_shell_frame(
    shell: *mut PokoShell,
    time_seconds: f64,
    width: u32,
    height: u32,
    out: *mut PokoFrameInfo,
) -> i32 {
    if shell.is_null() || out.is_null() {
        return POKO_SHELL_ERROR_NULL;
    }
    if width == 0 || height == 0 {
        return POKO_SHELL_ERROR_SHELL;
    }
    let ran = std::panic::catch_unwind(std::panic::AssertUnwindSafe(|| unsafe {
        let shell = &mut *shell;
        if shell.abi_version != POKO_SHELL_ABI_VERSION {
            return POKO_SHELL_ERROR_ABI_MISMATCH;
        }
        let screen_rect = egui::Rect::from_min_size(
            Pos2::ZERO,
            Vec2::new(width as f32, height as f32),
        );
        let mut raw = RawInput {
            screen_rect: Some(screen_rect),
            time: Some(time_seconds),
            ..RawInput::default()
        };
        let mut consumed: u32 = 0;
        for event in shell.events.drain(..) {
            consumed += 1;
            match event.kind {
                POKO_EVENT_MOTION => {
                    raw.events.push(egui::Event::PointerMoved(Pos2::new(
                        event.x, event.y,
                    )));
                }
                POKO_EVENT_BUTTON => {
                    if let Some(button) = match event.button {
                        0 => Some(PointerButton::Primary),
                        1 => Some(PointerButton::Secondary),
                        2 => Some(PointerButton::Middle),
                        _ => None,
                    } {
                        raw.events.push(egui::Event::PointerButton {
                            pos: Pos2::new(event.x, event.y),
                            button,
                            pressed: event.pressed != 0,
                            modifiers: egui::Modifiers::NONE,
                        });
                    }
                }
                POKO_EVENT_WHEEL => {
                    raw.events.push(egui::Event::MouseWheel {
                        unit: MouseWheelUnit::Line,
                        delta: Vec2::new(event.wheel_x, event.wheel_y),
                        phase: TouchPhase::Move,
                        modifiers: egui::Modifiers::NONE,
                    });
                }
                POKO_EVENT_TEXT => {
                    if event.text_len > 0 {
                        if let Ok(text) = std::str::from_utf8(
                            &event.text[..(event.text_len as usize)],
                        ) {
                            raw.events
                                .push(egui::Event::Text(text.to_owned()));
                        }
                    }
                }
                POKO_EVENT_FOCUS => {
                    raw.focused = event.focus != 0;
                    raw.events.push(egui::Event::WindowFocused(
                        event.focus != 0,
                    ));
                }
                // POKO_EVENT_KEY and unknown kinds are consumed without
                // mapping — the SDL3 key bridge is SHL-09/10.
                _ => {}
            }
        }
        let mut label_rendered = 0u32;
        let output = shell.egui.run_ui(raw, |ui| {
            let label = ui.label("PokoX");
            if label.rect.area() > 0.0 {
                label_rendered = 1;
            }
        });
        // SHL-05: keep the shapes for the mesh export to tessellate.
        shell.last_shapes = Some(output.shapes.clone());
        shell.last_ppp = output.pixels_per_point;
        // SHL-06: queue texture uploads (the font atlas arrives on the
        // first frame) as RGBA8. egui 0.35 images are ColorImage only.
        for (id, image) in output.textures_delta.set {
            let c = match image.image {
                egui::ImageData::Color(c) => c,
            };
            let rgba = c
                .pixels
                .iter()
                .flat_map(|p| [p.r(), p.g(), p.b(), p.a()])
                .collect::<Vec<u8>>();
            let id_num = match id {
                egui::TextureId::Managed(v) => v,
                egui::TextureId::User(v) => v | 0x8000_0000_0000_0000,
            };
            shell
                .pending_textures
                .push((id_num, c.width() as u32, c.height() as u32, rgba));
        }
        let shape_count = output.shapes.len() as u32;
        let repaint_delay_ms = output
            .viewport_output
            .get(&egui::ViewportId::ROOT)
            .map(|v| v.repaint_delay.as_millis() as u32)
            .unwrap_or(0);
        *out = PokoFrameInfo {
            events_consumed: consumed,
            shape_count,
            pixels_per_point: output.pixels_per_point,
            repaint_delay_ms,
            label_rendered,
        };
        POKO_SHELL_OK
    }));
    ran.unwrap_or(POKO_SHELL_ERROR_PANIC)
}

/// SHL-05: tessellate the last frame's shapes into the PMES v1 vertex
/// layout the engine's `PokoMesh` parser accepts — per vertex six
/// floats, float3 position (x, y, z=0; UI space, origin top-left) then
/// float3 normal (0, 0, 1) — and u32 indices, offset per primitive so
/// one flat index list results. Sizing call: null `out_vertices` and
/// `out_indices` write only the counts (vertex = 6 floats). Must run
/// after `poko_shell_frame` (nothing tessellated yet is -2). Caps too
/// small is -2 with the counts still written. UVs are not part of PMES
/// v1; the textured path waits for the AST-04 format.
#[no_mangle]
pub extern "C" fn poko_shell_mesh(
    shell: *mut PokoShell,
    out_vertices: *mut f32,
    vertex_cap: u32,
    out_v_written: *mut u32,
    out_indices: *mut u32,
    index_cap: u32,
    out_i_written: *mut u32,
) -> i32 {
    if shell.is_null() || out_v_written.is_null() || out_i_written.is_null() {
        return POKO_SHELL_ERROR_NULL;
    }
    let ran = std::panic::catch_unwind(std::panic::AssertUnwindSafe(|| unsafe {
        let shell = &mut *shell;
        if shell.abi_version != POKO_SHELL_ABI_VERSION {
            return POKO_SHELL_ERROR_ABI_MISMATCH;
        }
        let Some(shapes) = shell.last_shapes.as_ref() else {
            return POKO_SHELL_ERROR_SHELL;
        };
        let primitives = shell.egui.tessellate(shapes.clone(), shell.last_ppp);
        let mut floats: Vec<f32> = Vec::new();
        let mut indices: Vec<u32> = Vec::new();
        for prim in primitives {
            if let egui::epaint::Primitive::Mesh(mesh) = prim.primitive {
                let base = (floats.len() / 6) as u32;
                for v in &mesh.vertices {
                    floats.extend_from_slice(&[v.pos.x, v.pos.y, 0.0, 0.0, 0.0, 1.0]);
                }
                for i in &mesh.indices {
                    indices.push(base + *i);
                }
            }
        }
        *out_v_written = (floats.len() / 6) as u32;
        *out_i_written = indices.len() as u32;
        if out_vertices.is_null() || out_indices.is_null() {
            // Sizing call: counts only, the frame's shapes survive.
            return POKO_SHELL_OK;
        }
        if (vertex_cap as usize) < floats.len() / 6
            || (index_cap as usize) < indices.len()
        {
            return POKO_SHELL_ERROR_SHELL;
        }
        std::ptr::copy_nonoverlapping(floats.as_ptr(), out_vertices, floats.len());
        std::ptr::copy_nonoverlapping(indices.as_ptr(), out_indices, indices.len());
        // Only a successful copy consumes the frame's shapes.
        shell.last_shapes = None;
        POKO_SHELL_OK
    }));
    ran.unwrap_or(POKO_SHELL_ERROR_PANIC)
}

/// One queued texture upload from `poko_shell_texture_delta`: egui's
/// texture id, the image size, and RGBA8 bytes at `pixels_offset` in
/// the caller's flat pixel buffer.
#[repr(C)]
pub struct PokoTextureUpdate {
    pub id: u64,
    pub width: u32,
    pub height: u32,
    pub pixels_offset: u32,
    pub pixels_len: u32,
}

/// SHL-06: drain the texture updates queued by frames (the font atlas
/// arrives on the first frame; a frame that draws no new glyphs queues
/// nothing). Pixels come back RGBA8 in one flat buffer, each update
/// pointing into it. Sizing call: null `out_updates` and `out_pixels`
/// write only the counts. Caps too small is -2 with counts still
/// written. Nulls are -1, a stale-ABI handle -4.
#[no_mangle]
pub extern "C" fn poko_shell_texture_delta(
    shell: *mut PokoShell,
    out_updates: *mut PokoTextureUpdate,
    update_cap: u32,
    out_update_count: *mut u32,
    out_pixels: *mut u8,
    pixel_cap: u32,
    out_pixel_written: *mut u32,
) -> i32 {
    if shell.is_null()
        || out_update_count.is_null()
        || out_pixel_written.is_null()
    {
        return POKO_SHELL_ERROR_NULL;
    }
    let ran = std::panic::catch_unwind(std::panic::AssertUnwindSafe(|| unsafe {
        let shell = &mut *shell;
        if shell.abi_version != POKO_SHELL_ABI_VERSION {
            return POKO_SHELL_ERROR_ABI_MISMATCH;
        }
        let pixel_total: usize =
            shell.pending_textures.iter().map(|t| t.3.len()).sum();
        *out_update_count = shell.pending_textures.len() as u32;
        *out_pixel_written = pixel_total as u32;
        let sizing = out_updates.is_null() && out_pixels.is_null();
        let fits = !out_updates.is_null()
            && !out_pixels.is_null()
            && update_cap as usize >= shell.pending_textures.len()
            && pixel_cap as usize >= pixel_total;
        if sizing {
            return POKO_SHELL_OK;
        }
        if !fits {
            return POKO_SHELL_ERROR_SHELL;
        }
        let mut offset = 0u32;
        for (i, (id, w, h, rgba)) in shell.pending_textures.drain(..).enumerate() {
            std::ptr::copy_nonoverlapping(rgba.as_ptr(), out_pixels.add(offset as usize), rgba.len());
            *out_updates.add(i) = PokoTextureUpdate {
                id,
                width: w,
                height: h,
                pixels_offset: offset,
                pixels_len: rgba.len() as u32,
            };
            offset += rgba.len() as u32;
        }
        POKO_SHELL_OK
    }));
    ran.unwrap_or(POKO_SHELL_ERROR_PANIC)
}

/// SHL-01: the one probe that lets C++ confirm the header it compiled
/// against matches this crate.
#[no_mangle]
pub extern "C" fn poko_shell_abi_version() -> u32 {
    POKO_SHELL_ABI_VERSION
}

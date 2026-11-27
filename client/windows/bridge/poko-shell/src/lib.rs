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

pub mod theme;
pub mod widgets;

use egui::{Context, MouseWheelUnit, PointerButton, Pos2, RawInput, TouchPhase, Vec2};
use theme::{ThemeKind, ThemeTokens};
use widgets::{PokoBevelButton, PokoGlossPanel, PokoTabStrip};

/// Bumped whenever the C ABI in `client/windows/bridge/c_abi/poko_shell.h`
/// changes shape; `poko_shell_create` (SHL-02) refuses mismatches with -4.
/// Version 2: SHL-03 added the event queue exports and made the handle
/// opaque to C (it now holds Rust state).
/// Version 3: SHL-04 added `PokoEvent::pressed` (press vs release — egui
/// needs both) and the `poko_shell_frame` export with `PokoFrameInfo`.
/// Version 4: SHL-05/06 added the `poko_shell_mesh` and
/// `poko_shell_texture_delta` exports with their result structs.
/// Version 5: SHL-12 added `POKO_THEME_*` and `poko_shell_set_theme`.
/// Version 6: SHL-14 added `poko_shell_set_dpi_scale`.
pub const POKO_SHELL_ABI_VERSION: u32 = 6;

pub const POKO_THEME_CLASSIC: u32 = 0;
pub const POKO_THEME_FLAT: u32 = 1;

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
    /// SHL-10: single-line text field backing IME and CJK text input.
    input_text: String,
    /// SHL-12: active theme tokens (`Classic` or `Flat`) and selected tab.
    theme: ThemeKind,
    active_tab: usize,
    /// SHL-14: active DPI scale (`pixels_per_point`), driving atlas regen.
    dpi_scale: f32,
    /// SHL-13: active-call flag preventing nested reentrant calls (-5).
    in_call: std::sync::atomic::AtomicBool,
}

struct ReentrancyGuard<'a> {
    flag: &'a std::sync::atomic::AtomicBool,
}

impl Drop for ReentrancyGuard<'_> {
    fn drop(&mut self) {
        self.flag.store(false, std::sync::atomic::Ordering::SeqCst);
    }
}

unsafe fn enter_shell<'a>(shell: *mut PokoShell) -> Result<(&'a mut PokoShell, ReentrancyGuard<'a>), i32> {
    let shared = &*shell;
    if shared.abi_version != POKO_SHELL_ABI_VERSION {
        return Err(POKO_SHELL_ERROR_ABI_MISMATCH);
    }
    if shared
        .in_call
        .compare_exchange(
            false,
            true,
            std::sync::atomic::Ordering::SeqCst,
            std::sync::atomic::Ordering::SeqCst,
        )
        .is_err()
    {
        return Err(POKO_SHELL_ERROR_REENTRANT);
    }
    let guard = ReentrancyGuard {
        flag: &(*shell).in_call,
    };
    Ok((&mut *shell, guard))
}

static FORCE_PANIC_NEXT: std::sync::atomic::AtomicBool =
    std::sync::atomic::AtomicBool::new(false);

#[inline]
fn maybe_force_panic() {
    if FORCE_PANIC_NEXT.swap(false, std::sync::atomic::Ordering::SeqCst) {
        panic!("forced panic for SHL-08");
    }
}

fn panic_boundary<F>(f: F) -> i32
where
    F: FnOnce() -> i32,
{
    std::panic::catch_unwind(std::panic::AssertUnwindSafe(|| {
        maybe_force_panic();
        f()
    }))
    .unwrap_or(POKO_SHELL_ERROR_PANIC)
}

type TestFrameCallback = extern "C" fn(*mut PokoShell, *mut std::ffi::c_void);

static TEST_FRAME_CB: std::sync::atomic::AtomicUsize =
    std::sync::atomic::AtomicUsize::new(0);
static TEST_FRAME_USER: std::sync::atomic::AtomicUsize =
    std::sync::atomic::AtomicUsize::new(0);

/// Test-only hook for SHL-13: register a callback invoked inside
/// `poko_shell_frame` while the reentrancy guard is held.
/// cbindgen:ignore
#[no_mangle]
pub extern "C" fn poko_shell_test_set_frame_callback(
    cb: Option<TestFrameCallback>,
    user: *mut std::ffi::c_void,
) {
    TEST_FRAME_CB.store(
        cb.map(|f| f as usize).unwrap_or(0),
        std::sync::atomic::Ordering::SeqCst,
    );
    TEST_FRAME_USER.store(user as usize, std::sync::atomic::Ordering::SeqCst);
}

/// Test-only hook for SHL-08: arm a forced panic on the next
/// `poko_shell_*` call that enters the panic boundary.
/// cbindgen:ignore
#[no_mangle]
pub extern "C" fn poko_shell_test_force_panic() {
    FORCE_PANIC_NEXT.store(true, std::sync::atomic::Ordering::SeqCst);
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
    panic_boundary(|| {
        if abi_version != POKO_SHELL_ABI_VERSION {
            return POKO_SHELL_ERROR_ABI_MISMATCH;
        }
        let egui_ctx = Context::default();
        egui_ctx.set_style_of(egui::Theme::Light, ThemeTokens::classic().to_egui_style());
        egui_ctx.set_style_of(egui::Theme::Dark, ThemeTokens::flat().to_egui_style());
        egui_ctx.set_theme(egui::Theme::Light);
        let shell = Box::into_raw(Box::new(PokoShell {
            abi_version: POKO_SHELL_ABI_VERSION,
            events: Vec::new(),
            egui: egui_ctx,
            last_shapes: None,
            last_ppp: 1.0,
            pending_textures: Vec::new(),
            input_text: String::new(),
            theme: ThemeKind::Classic,
            active_tab: 0,
            dpi_scale: 1.0,
            in_call: std::sync::atomic::AtomicBool::new(false),
        }));
        unsafe { *out_shell = shell };
        POKO_SHELL_OK
    })
}

/// Free a handle from `poko_shell_create`. Null is a no-op; passing any
/// other value the create path did not return is undefined, as with free.
#[no_mangle]
pub extern "C" fn poko_shell_destroy(shell: *mut PokoShell) {
    let _ = std::panic::catch_unwind(std::panic::AssertUnwindSafe(|| {
        maybe_force_panic();
        if !shell.is_null() {
            if unsafe { (*shell).in_call.load(std::sync::atomic::Ordering::SeqCst) } {
                return;
            }
            drop(unsafe { Box::from_raw(shell) });
        }
    }));
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
    panic_boundary(|| unsafe {
        let (shell, _guard) = match enter_shell(shell) {
            Ok(v) => v,
            Err(rc) => return rc,
        };
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
    })
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
    panic_boundary(|| unsafe {
        let (shell, _guard) = match enter_shell(shell) {
            Ok(v) => v,
            Err(rc) => return rc,
        };
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
    })
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

fn decode_modifiers(bits: u32) -> egui::Modifiers {
    let shift = (bits & (1 << 0)) != 0;
    let ctrl = (bits & (1 << 1)) != 0;
    let alt = (bits & (1 << 2)) != 0;
    let mac_cmd = (bits & (1 << 3)) != 0;
    egui::Modifiers {
        alt,
        ctrl,
        shift,
        mac_cmd,
        command: ctrl || mac_cmd,
    }
}

fn map_sdl_keycode(code: i32) -> Option<egui::Key> {
    use egui::Key;
    let u = code as u32;
    match u {
        0x61..=0x7A => {
            const LETTERS: [Key; 26] = [
                Key::A, Key::B, Key::C, Key::D, Key::E, Key::F, Key::G,
                Key::H, Key::I, Key::J, Key::K, Key::L, Key::M, Key::N,
                Key::O, Key::P, Key::Q, Key::R, Key::S, Key::T, Key::U,
                Key::V, Key::W, Key::X, Key::Y, Key::Z,
            ];
            Some(LETTERS[(u - 0x61) as usize])
        }
        0x41..=0x5A => {
            const LETTERS: [Key; 26] = [
                Key::A, Key::B, Key::C, Key::D, Key::E, Key::F, Key::G,
                Key::H, Key::I, Key::J, Key::K, Key::L, Key::M, Key::N,
                Key::O, Key::P, Key::Q, Key::R, Key::S, Key::T, Key::U,
                Key::V, Key::W, Key::X, Key::Y, Key::Z,
            ];
            Some(LETTERS[(u - 0x41) as usize])
        }
        0x30..=0x39 => {
            const DIGITS: [Key; 10] = [
                Key::Num0, Key::Num1, Key::Num2, Key::Num3, Key::Num4,
                Key::Num5, Key::Num6, Key::Num7, Key::Num8, Key::Num9,
            ];
            Some(DIGITS[(u - 0x30) as usize])
        }
        0x20 => Some(Key::Space),
        0x0D | 0x4000_0058 => Some(Key::Enter),
        0x09 => Some(Key::Tab),
        0x1B => Some(Key::Escape),
        0x08 => Some(Key::Backspace),
        0x7F => Some(Key::Delete),
        0x2D => Some(Key::Minus),
        0x3D => Some(Key::Equals),
        0x5B => Some(Key::OpenBracket),
        0x5D => Some(Key::CloseBracket),
        0x5C => Some(Key::Backslash),
        0x3B => Some(Key::Semicolon),
        0x27 => Some(Key::Quote),
        0x2C => Some(Key::Comma),
        0x2E => Some(Key::Period),
        0x2F => Some(Key::Slash),
        0x60 => Some(Key::Backtick),
        0x4000_0049 => Some(Key::Insert),
        0x4000_004A => Some(Key::Home),
        0x4000_004B => Some(Key::PageUp),
        0x4000_004D => Some(Key::End),
        0x4000_004E => Some(Key::PageDown),
        0x4000_004F => Some(Key::ArrowRight),
        0x4000_0050 => Some(Key::ArrowLeft),
        0x4000_0051 => Some(Key::ArrowDown),
        0x4000_0052 => Some(Key::ArrowUp),
        0x4000_003A..=0x4000_0045 => {
            const FKEYS: [Key; 12] = [
                Key::F1, Key::F2, Key::F3, Key::F4, Key::F5, Key::F6,
                Key::F7, Key::F8, Key::F9, Key::F10, Key::F11, Key::F12,
            ];
            Some(FKEYS[(u - 0x4000_003A) as usize])
        }
        _ => None,
    }
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
    panic_boundary(|| unsafe {
        let (shell, _guard) = match enter_shell(shell) {
            Ok(v) => v,
            Err(rc) => return rc,
        };
        let screen_rect = egui::Rect::from_min_size(
            Pos2::ZERO,
            Vec2::new(width as f32, height as f32),
        );
        let mut raw = RawInput {
            screen_rect: Some(screen_rect),
            time: Some(time_seconds),
            ..RawInput::default()
        };
        raw.viewports
            .entry(egui::ViewportId::ROOT)
            .or_default()
            .native_pixels_per_point = Some(shell.dpi_scale);
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
                    let mods = decode_modifiers(event.modifiers);
                    raw.modifiers = mods;
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
                            modifiers: mods,
                        });
                    }
                }
                POKO_EVENT_WHEEL => {
                    let mods = decode_modifiers(event.modifiers);
                    raw.modifiers = mods;
                    raw.events.push(egui::Event::MouseWheel {
                        unit: MouseWheelUnit::Line,
                        delta: Vec2::new(event.wheel_x, event.wheel_y),
                        phase: TouchPhase::Move,
                        modifiers: mods,
                    });
                }
                POKO_EVENT_KEY => {
                    let mods = decode_modifiers(event.modifiers);
                    raw.modifiers = mods;
                    if let Some(key) = map_sdl_keycode(event.key) {
                        raw.events.push(egui::Event::Key {
                            key,
                            physical_key: None,
                            pressed: event.pressed != 0,
                            repeat: false,
                            modifiers: mods,
                        });
                    }
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
                _ => {}
            }
        }
        let cb_addr = TEST_FRAME_CB.load(std::sync::atomic::Ordering::SeqCst);
        if cb_addr != 0 {
            let cb: TestFrameCallback = std::mem::transmute(cb_addr);
            let user = TEST_FRAME_USER.load(std::sync::atomic::Ordering::SeqCst)
                as *mut std::ffi::c_void;
            cb(shell as *mut PokoShell, user);
        }
        let tokens = ThemeTokens::for_kind(shell.theme);
        let mut label_rendered = 0u32;
        let output = shell.egui.run_ui(raw, |ui| {
            egui::Frame::NONE.inner_margin(8.0).show(ui, |ui| {
                PokoGlossPanel::new(&tokens).show(ui, |ui| {
                    PokoTabStrip::new(&["Library", "Store"], &mut shell.active_tab, &tokens)
                        .show(ui);
                    let label = ui.label("PokoX");
                    if label.rect.area() > 0.0 {
                        label_rendered = 1;
                    }
                    ui.add(
                        egui::TextEdit::singleline(&mut shell.input_text)
                            .desired_width(160.0),
                    );
                    let _ = PokoBevelButton::new("Play", &tokens).show(ui);
                });
            });
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
    })
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
    panic_boundary(|| unsafe {
        let (shell, _guard) = match enter_shell(shell) {
            Ok(v) => v,
            Err(rc) => return rc,
        };
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
        if out_vertices.is_null() && out_indices.is_null() {
            // Sizing call: counts only, the frame's shapes survive.
            return POKO_SHELL_OK;
        }
        if out_vertices.is_null()
            || out_indices.is_null()
            || (vertex_cap as usize) < floats.len() / 6
            || (index_cap as usize) < indices.len()
        {
            return POKO_SHELL_ERROR_SHELL;
        }
        std::ptr::copy_nonoverlapping(floats.as_ptr(), out_vertices, floats.len());
        std::ptr::copy_nonoverlapping(indices.as_ptr(), out_indices, indices.len());
        // Only a successful copy consumes the frame's shapes.
        shell.last_shapes = None;
        POKO_SHELL_OK
    })
}

/// One queued texture upload from `poko_shell_texture_delta`: egui's
/// texture id, the image size, and RGBA8 bytes at `pixels_offset` in
/// the caller's flat pixel buffer.
#[repr(C)]
#[derive(Clone, Copy)]
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
    panic_boundary(|| unsafe {
        let (shell, _guard) = match enter_shell(shell) {
            Ok(v) => v,
            Err(rc) => return rc,
        };
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
    })
}

/// SHL-12: select the shell theme (`POKO_THEME_CLASSIC` or `POKO_THEME_FLAT`).
#[no_mangle]
pub extern "C" fn poko_shell_set_theme(shell: *mut PokoShell, theme: u32) -> i32 {
    if shell.is_null() {
        return POKO_SHELL_ERROR_NULL;
    }
    panic_boundary(|| unsafe {
        let (shell, _guard) = match enter_shell(shell) {
            Ok(v) => v,
            Err(rc) => return rc,
        };
        let kind = match theme {
            POKO_THEME_CLASSIC => ThemeKind::Classic,
            POKO_THEME_FLAT => ThemeKind::Flat,
            _ => return POKO_SHELL_ERROR_SHELL,
        };
        shell.theme = kind;
        shell.egui.set_theme(match kind {
            ThemeKind::Classic => egui::Theme::Light,
            ThemeKind::Flat => egui::Theme::Dark,
        });
        POKO_SHELL_OK
    })
}

/// SHL-14: update the shell's DPI scale (`pixels_per_point`). Changing the
/// scale causes the next `poko_shell_frame` to regenerate the font atlas.
#[no_mangle]
pub extern "C" fn poko_shell_set_dpi_scale(
    shell: *mut PokoShell,
    dpi_scale: f32,
) -> i32 {
    if shell.is_null() {
        return POKO_SHELL_ERROR_NULL;
    }
    panic_boundary(|| unsafe {
        let (shell, _guard) = match enter_shell(shell) {
            Ok(v) => v,
            Err(rc) => return rc,
        };
        if !dpi_scale.is_finite() || dpi_scale <= 0.0 {
            return POKO_SHELL_ERROR_SHELL;
        }
        shell.dpi_scale = dpi_scale;
        POKO_SHELL_OK
    })
}

/// SHL-01: the one probe that lets C++ confirm the header it compiled
/// against matches this crate.
#[no_mangle]
pub extern "C" fn poko_shell_abi_version() -> u32 {
    POKO_SHELL_ABI_VERSION
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn mouse_and_keyboard_drive_egui_input() {
        let mut shell: *mut PokoShell = std::ptr::null_mut();
        assert_eq!(poko_shell_create(POKO_SHELL_ABI_VERSION, &mut shell), POKO_SHELL_OK);

        let mut move_ev = PokoEvent::zeroed();
        move_ev.kind = POKO_EVENT_MOTION;
        move_ev.x = 42.5;
        move_ev.y = 84.0;
        assert_eq!(poko_shell_push_event(shell, &move_ev), POKO_SHELL_OK);

        let mut btn_ev = PokoEvent::zeroed();
        btn_ev.kind = POKO_EVENT_BUTTON;
        btn_ev.x = 42.5;
        btn_ev.y = 84.0;
        btn_ev.button = 0;
        btn_ev.pressed = 1;
        btn_ev.modifiers = 1 << 0;
        assert_eq!(poko_shell_push_event(shell, &btn_ev), POKO_SHELL_OK);

        let mut key_ev = PokoEvent::zeroed();
        key_ev.kind = POKO_EVENT_KEY;
        key_ev.key = 'a' as i32;
        key_ev.pressed = 1;
        key_ev.modifiers = 1 << 1; // Ctrl
        assert_eq!(poko_shell_push_event(shell, &key_ev), POKO_SHELL_OK);

        let mut info = PokoFrameInfo {
            events_consumed: 0,
            shape_count: 0,
            pixels_per_point: 0.0,
            repaint_delay_ms: 0,
            label_rendered: 0,
        };
        assert_eq!(poko_shell_frame(shell, 0.016, 320, 240, &mut info), POKO_SHELL_OK);
        assert_eq!(info.events_consumed, 3);

        unsafe {
            let s = &*shell;
            s.egui.input(|i| {
                assert_eq!(i.pointer.hover_pos(), Some(Pos2::new(42.5, 84.0)));
                assert!(i.pointer.primary_down());
                assert!(i.key_down(egui::Key::A));
                assert!(i.modifiers.ctrl);
            });
        }

        poko_shell_destroy(shell);
    }

    #[test]
    fn cjk_text_typed_into_field() {
        let mut shell: *mut PokoShell = std::ptr::null_mut();
        assert_eq!(poko_shell_create(POKO_SHELL_ABI_VERSION, &mut shell), POKO_SHELL_OK);

        let mut info = PokoFrameInfo {
            events_consumed: 0,
            shape_count: 0,
            pixels_per_point: 0.0,
            repaint_delay_ms: 0,
            label_rendered: 0,
        };
        // Frame 1: lay out the label and TextEdit, then click inside the TextEdit
        // (positioned below the label at y ~ 30) to give it keyboard focus.
        assert_eq!(poko_shell_frame(shell, 0.0, 320, 240, &mut info), POKO_SHELL_OK);

        let mut click_down = PokoEvent::zeroed();
        click_down.kind = POKO_EVENT_BUTTON;
        click_down.x = 40.0;
        click_down.y = 66.0;
        click_down.button = 0;
        click_down.pressed = 1;
        assert_eq!(poko_shell_push_event(shell, &click_down), POKO_SHELL_OK);

        let mut click_up = click_down;
        click_up.pressed = 0;
        assert_eq!(poko_shell_push_event(shell, &click_up), POKO_SHELL_OK);
        assert_eq!(poko_shell_frame(shell, 0.016, 320, 240, &mut info), POKO_SHELL_OK);

        // Frame 3: type CJK UTF-8 text into the focused field.
        let cjk = "你好世界日本語";
        let bytes = cjk.as_bytes();
        let mut text_ev = PokoEvent::zeroed();
        text_ev.kind = POKO_EVENT_TEXT;
        text_ev.text_len = bytes.len() as u32;
        text_ev.text[..bytes.len()].copy_from_slice(bytes);
        assert_eq!(poko_shell_push_event(shell, &text_ev), POKO_SHELL_OK);
        assert_eq!(poko_shell_frame(shell, 0.032, 320, 240, &mut info), POKO_SHELL_OK);

        unsafe {
            assert_eq!((*shell).input_text, cjk);
        }

        poko_shell_destroy(shell);
    }

    #[test]
    fn mesh_vertices_stay_within_screen_rect() {
        let mut shell: *mut PokoShell = std::ptr::null_mut();
        assert_eq!(poko_shell_create(POKO_SHELL_ABI_VERSION, &mut shell), POKO_SHELL_OK);
        let mut info = PokoFrameInfo {
            events_consumed: 0,
            shape_count: 0,
            pixels_per_point: 0.0,
            repaint_delay_ms: 0,
            label_rendered: 0,
        };
        assert_eq!(poko_shell_frame(shell, 1.0, 320, 240, &mut info), POKO_SHELL_OK);
        let mut vn = 0u32;
        let mut in_ = 0u32;
        assert_eq!(
            poko_shell_mesh(shell, std::ptr::null_mut(), 0, &mut vn, std::ptr::null_mut(), 0, &mut in_),
            POKO_SHELL_OK
        );
        let mut verts = vec![0.0f32; (vn as usize) * 6];
        let mut idx = vec![0u32; in_ as usize];
        let mut vg = 0u32;
        let mut ig = 0u32;
        assert_eq!(
            poko_shell_mesh(shell, verts.as_mut_ptr(), vn, &mut vg, idx.as_mut_ptr(), in_, &mut ig),
            POKO_SHELL_OK
        );
        for v in 0..(vg as usize) {
            let x = verts[v * 6];
            let y = verts[v * 6 + 1];
            assert!(
                (0.0..=320.0).contains(&x) && (0.0..=240.0).contains(&y),
                "vertex {v} out of bounds: ({x}, {y})"
            );
        }
        poko_shell_destroy(shell);
    }

    #[test]
    fn classic_and_flat_theme_goldens() {
        let classic = ThemeTokens::classic().to_egui_style();
        let flat = ThemeTokens::flat().to_egui_style();
        assert_eq!(classic.visuals.window_corner_radius, egui::CornerRadius::ZERO);
        assert_eq!(flat.visuals.window_corner_radius, egui::CornerRadius::ZERO);
        assert_eq!(classic.visuals.widgets.inactive.corner_radius, egui::CornerRadius::ZERO);
        assert_eq!(flat.visuals.widgets.inactive.corner_radius, egui::CornerRadius::ZERO);
        assert_eq!(classic.visuals.widgets.inactive.bg_stroke.width, 1.0);
        assert_eq!(flat.visuals.widgets.inactive.bg_stroke.width, 1.0);
        assert_ne!(classic.visuals.panel_fill, flat.visuals.panel_fill);
    }

    #[test]
    fn dpi_resize_regenerates_font_atlas() {
        let mut shell: *mut PokoShell = std::ptr::null_mut();
        assert_eq!(poko_shell_create(POKO_SHELL_ABI_VERSION, &mut shell), POKO_SHELL_OK);
        let mut info = PokoFrameInfo {
            events_consumed: 0,
            shape_count: 0,
            pixels_per_point: 0.0,
            repaint_delay_ms: 0,
            label_rendered: 0,
        };
        assert_eq!(poko_shell_frame(shell, 0.0, 640, 480, &mut info), POKO_SHELL_OK);
        assert_eq!(info.pixels_per_point, 1.0);
        let mut u1 = 0u32;
        let mut p1 = 0u32;
        assert_eq!(
            poko_shell_texture_delta(shell, std::ptr::null_mut(), 0, &mut u1, std::ptr::null_mut(), 0, &mut p1),
            POKO_SHELL_OK
        );
        assert!(u1 >= 1 && p1 > 0);
        let mut ups = vec![PokoTextureUpdate { id: 0, width: 0, height: 0, pixels_offset: 0, pixels_len: 0 }; u1 as usize];
        let mut pix = vec![0u8; p1 as usize];
        assert_eq!(
            poko_shell_texture_delta(shell, ups.as_mut_ptr(), u1, &mut u1, pix.as_mut_ptr(), p1, &mut p1),
            POKO_SHELL_OK
        );

        assert_eq!(poko_shell_set_dpi_scale(shell, 2.0), POKO_SHELL_OK);
        assert_eq!(poko_shell_frame(shell, 0.016, 640, 480, &mut info), POKO_SHELL_OK);
        assert_eq!(info.pixels_per_point, 2.0);
        let mut u2 = 0u32;
        let mut p2 = 0u32;
        assert_eq!(
            poko_shell_texture_delta(shell, std::ptr::null_mut(), 0, &mut u2, std::ptr::null_mut(), 0, &mut p2),
            POKO_SHELL_OK
        );
        assert!(u2 >= 1 && p2 > 0, "expected regenerated atlas delta at 2x DPI (u2={u2}, p2={p2}, p1={p1})");
        poko_shell_destroy(shell);
    }
}

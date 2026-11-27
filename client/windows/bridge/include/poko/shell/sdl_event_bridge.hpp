// SHL-09: SDL3 event bridge — translates raw SDL_Event values (observed
// via SdlPlatform::poll_event) into spec-12 PokoEvent values and pushes
// them into a PokoShell handle. Pure header with zero SDL link calls so
// it works identically with real SDL3 and the engine's fake SDL3 header.
#pragma once

extern "C" {
#include "poko_shell.h"
}

#include <SDL3/SDL.h>

#include <algorithm>
#include <cstdint>
#include <cstring>

namespace poko::shell {

inline constexpr uint32_t kModShift = 1u << 0;
inline constexpr uint32_t kModCtrl = 1u << 1;
inline constexpr uint32_t kModAlt = 1u << 2;
inline constexpr uint32_t kModCommand = 1u << 3;

struct SdlEventBridgeContext {
    PokoShell* shell = nullptr;
    SDL_WindowID window_id = 0;
    float dpi_scale = 1.0f;
    uint32_t pushed_count = 0;
    int32_t last_error = POKO_SHELL_OK;
};

[[nodiscard]] inline uint32_t translate_sdl_modifiers(SDL_Keymod mod) noexcept {
    uint32_t bits = 0;
    if ((mod & SDL_KMOD_SHIFT) != 0) bits |= kModShift;
    if ((mod & SDL_KMOD_CTRL) != 0) bits |= kModCtrl;
    if ((mod & SDL_KMOD_ALT) != 0) bits |= kModAlt;
    if ((mod & SDL_KMOD_GUI) != 0) bits |= kModCommand;
    return bits;
}

[[nodiscard]] inline bool translate_sdl_event(const SDL_Event& ev,
                                              SDL_WindowID window_id,
                                              float dpi_scale,
                                              PokoEvent& out) noexcept {
    const float scale = dpi_scale > 0.0f ? dpi_scale : 1.0f;
    out = PokoEvent{};

    switch (ev.type) {
        case SDL_EVENT_MOUSE_MOTION: {
            if (window_id != 0 && ev.motion.windowID != window_id) return false;
            out.kind = POKO_EVENT_MOTION;
            out.x = ev.motion.x / scale;
            out.y = ev.motion.y / scale;
            return true;
        }
        case SDL_EVENT_MOUSE_BUTTON_DOWN:
        case SDL_EVENT_MOUSE_BUTTON_UP: {
            if (window_id != 0 && ev.button.windowID != window_id) return false;
            int32_t btn = -1;
            if (ev.button.button == SDL_BUTTON_LEFT) btn = 0;
            else if (ev.button.button == SDL_BUTTON_RIGHT) btn = 1;
            else if (ev.button.button == SDL_BUTTON_MIDDLE) btn = 2;
            if (btn < 0) return false;
            out.kind = POKO_EVENT_BUTTON;
            out.x = ev.button.x / scale;
            out.y = ev.button.y / scale;
            out.button = btn;
            out.pressed = (ev.type == SDL_EVENT_MOUSE_BUTTON_DOWN) ? 1 : 0;
            return true;
        }
        case SDL_EVENT_MOUSE_WHEEL: {
            if (window_id != 0 && ev.wheel.windowID != window_id) return false;
            out.kind = POKO_EVENT_WHEEL;
            out.wheel_x = ev.wheel.x;
            out.wheel_y = ev.wheel.y;
            return true;
        }
        case SDL_EVENT_KEY_DOWN:
        case SDL_EVENT_KEY_UP: {
            if (window_id != 0 && ev.key.windowID != window_id) return false;
            out.kind = POKO_EVENT_KEY;
            out.key = static_cast<int32_t>(ev.key.key);
            out.pressed = (ev.type == SDL_EVENT_KEY_DOWN) ? 1 : 0;
            out.modifiers = translate_sdl_modifiers(ev.key.mod);
            return true;
        }
        case SDL_EVENT_TEXT_INPUT: {
            if (window_id != 0 && ev.text.windowID != window_id) return false;
            if (!ev.text.text || ev.text.text[0] == '\0') return false;
            const size_t raw_len = std::strlen(ev.text.text);
            size_t copy_len =
                std::min(raw_len, static_cast<size_t>(POKO_SHELL_EVENT_TEXT_MAX - 1));
            // Never split a multi-byte UTF-8 (e.g. CJK) codepoint at the cap.
            while (copy_len > 0 &&
                   (static_cast<unsigned char>(ev.text.text[copy_len]) & 0xC0u) == 0x80u) {
                --copy_len;
            }
            if (copy_len == 0) return false;
            out.kind = POKO_EVENT_TEXT;
            out.text_len = static_cast<uint32_t>(copy_len);
            std::memcpy(out.text, ev.text.text, copy_len);
            return true;
        }
        case SDL_EVENT_WINDOW_FOCUS_GAINED:
        case SDL_EVENT_WINDOW_FOCUS_LOST: {
            if (window_id != 0 && ev.window.windowID != window_id) return false;
            out.kind = POKO_EVENT_FOCUS;
            out.focus = (ev.type == SDL_EVENT_WINDOW_FOCUS_GAINED) ? 1 : 0;
            return true;
        }
        case SDL_EVENT_WINDOW_RESIZED:
        case SDL_EVENT_WINDOW_PIXEL_SIZE_CHANGED: {
            if (window_id != 0 && ev.window.windowID != window_id) return false;
            if (ev.window.data1 <= 0 || ev.window.data2 <= 0) return false;
            out.kind = POKO_EVENT_RESIZE;
            out.width = static_cast<uint32_t>(
                static_cast<float>(ev.window.data1) / scale);
            out.height = static_cast<uint32_t>(
                static_cast<float>(ev.window.data2) / scale);
            return true;
        }
        default:
            return false;
    }
}

/// SdlPlatform::EventObserver callback: translates and pushes each matching
/// SDL_Event into `ctx->shell` without throwing or mutating the platform.
inline void sdl_event_observer(const SDL_Event& ev, void* user) noexcept {
    auto* ctx = static_cast<SdlEventBridgeContext*>(user);
    if (!ctx || !ctx->shell) return;
    PokoEvent translated{};
    if (!translate_sdl_event(ev, ctx->window_id, ctx->dpi_scale, translated)) {
        return;
    }
    const int32_t rc = poko_shell_push_event(ctx->shell, &translated);
    ctx->last_error = rc;
    if (rc == POKO_SHELL_OK) {
        ctx->pushed_count++;
    }
}

/// Enable SDL3 text input (required for IME and CJK composition on a window).
inline bool start_text_input(SDL_Window* window) noexcept {
    return window != nullptr && SDL_StartTextInput(window);
}

/// Disable SDL3 text input on a window.
inline bool stop_text_input(SDL_Window* window) noexcept {
    return window != nullptr && SDL_StopTextInput(window);
}

}  // namespace poko::shell

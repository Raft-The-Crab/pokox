// SHL-03: push_event accumulates events in FIFO order inside the handle,
// returns the spec-12 codes for null / stale-ABI / invalid input, and
// drain_events hands them back byte-exact. The golden below pins the
// on-the-wire serialization rule for the four event kinds the demo input
// path uses: per event, kind, x, y, button, key, modifiers, wheel_x,
// wheel_y, width, height, focus, text_len as little-endian 4-byte words,
// then text_len text bytes — with every field a kind does not use zero.
extern "C" {
#include "poko_shell.h"
}

#include <cstdint>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>

namespace {

int failures = 0;

void check(bool ok, const char* what) {
    if (!ok) {
        std::puts(what);
        failures++;
    }
}

PokoEvent motion(float x, float y) {
    PokoEvent e{};
    e.kind = POKO_EVENT_MOTION;
    e.x = x;
    e.y = y;
    return e;
}

PokoEvent button(float x, float y, int32_t b, int32_t pressed) {
    PokoEvent e{};
    e.kind = POKO_EVENT_BUTTON;
    e.x = x;
    e.y = y;
    e.button = b;
    e.pressed = pressed;
    return e;
}

PokoEvent key(int32_t k, uint32_t mods) {
    PokoEvent e{};
    e.kind = POKO_EVENT_KEY;
    e.key = k;
    e.modifiers = mods;
    return e;
}

PokoEvent text(const char* s, uint32_t len) {
    PokoEvent e{};
    e.kind = POKO_EVENT_TEXT;
    e.text_len = len;
    std::memcpy(e.text, s, len);
    return e;
}

void append_u32(std::string& out, uint32_t v) {
    for (int i = 0; i < 4; ++i) {
        out.push_back(static_cast<char>((v >> (8 * i)) & 0xFF));
    }
}

// The serialization rule above, applied to one drained event.
std::string serialize(const PokoEvent& e) {
    std::string out;
    append_u32(out, static_cast<uint32_t>(e.kind));
    uint32_t x = 0;
    std::memcpy(&x, &e.x, 4);
    append_u32(out, x);
    uint32_t y = 0;
    std::memcpy(&y, &e.y, 4);
    append_u32(out, y);
    append_u32(out, static_cast<uint32_t>(e.button));
    append_u32(out, static_cast<uint32_t>(e.key));
    append_u32(out, e.modifiers);
    uint32_t wx = 0;
    std::memcpy(&wx, &e.wheel_x, 4);
    append_u32(out, wx);
    uint32_t wy = 0;
    std::memcpy(&wy, &e.wheel_y, 4);
    append_u32(out, wy);
    append_u32(out, e.width);
    append_u32(out, e.height);
    append_u32(out, static_cast<uint32_t>(e.focus));
    append_u32(out, e.text_len);
    out.append(reinterpret_cast<const char*>(e.text), e.text_len);
    return out;
}

}  // namespace

int main() {
    // Nulls: -1 before anything else.
    check(poko_shell_push_event(nullptr, nullptr) == POKO_SHELL_ERROR_NULL,
          "FAIL: null shell must return -1");
    PokoShell* shell = nullptr;
    check(poko_shell_create(POKO_SHELL_ABI_VERSION, &shell) == POKO_SHELL_OK &&
              shell != nullptr,
          "FAIL: create must succeed");
    PokoEvent ev = motion(0.0f, 0.0f);
    check(poko_shell_push_event(shell, nullptr) == POKO_SHELL_ERROR_NULL,
          "FAIL: null event must return -1");
    uint32_t written = 99;
    check(poko_shell_drain_events(shell, nullptr, 0, nullptr) ==
              POKO_SHELL_ERROR_NULL,
          "FAIL: null out_written must return -1");
    check(poko_shell_drain_events(nullptr, nullptr, 0, &written) ==
              POKO_SHELL_ERROR_NULL,
          "FAIL: null shell on drain must return -1");

    // A handle block carrying a stale ABI version (what a caller compiled
    // against the version-1 header passes): -4 on both exports. The first
    // field is the version, so a one-word block is layout-identical for
    // the version check.
    uint32_t stale_block = POKO_SHELL_ABI_VERSION - 1;
    check(poko_shell_push_event(
              reinterpret_cast<PokoShell*>(&stale_block), &ev) ==
              POKO_SHELL_ERROR_ABI_MISMATCH,
          "FAIL: stale-ABI handle must return -4 on push");
    written = 99;
    check(poko_shell_drain_events(
              reinterpret_cast<PokoShell*>(&stale_block), nullptr, 0,
              &written) == POKO_SHELL_ERROR_ABI_MISMATCH &&
              written == 99,
          "FAIL: stale-ABI handle must return -4 on drain");
    check(poko_shell_push_event(shell, &ev) == POKO_SHELL_OK,
          "FAIL: valid event must return 0");
    check(poko_shell_drain_events(shell, nullptr, 0, &written) == POKO_SHELL_OK &&
              written == 1,
          "FAIL: count-only drain must report one pending event");

    // Invalid input, fail closed: unknown kind, oversized text.
    PokoEvent bad = ev;
    bad.kind = 7;
    check(poko_shell_push_event(shell, &bad) == POKO_SHELL_ERROR_SHELL,
          "FAIL: unknown kind must return -2");
    bad = ev;
    bad.kind = -1;
    check(poko_shell_push_event(shell, &bad) == POKO_SHELL_ERROR_SHELL,
          "FAIL: negative kind must return -2");
    bad = PokoEvent{};
    bad.kind = POKO_EVENT_TEXT;
    bad.text_len = POKO_SHELL_EVENT_TEXT_MAX;
    check(poko_shell_push_event(shell, &bad) == POKO_SHELL_ERROR_SHELL,
          "FAIL: text_len at the max must return -2");
    check(poko_shell_drain_events(shell, nullptr, 0, &written) == POKO_SHELL_OK &&
              written == 1,
          "FAIL: refused pushes must leave the queue untouched");

    // The golden sequence: four events covering motion, button, key and
    // text. Golden hex is hand-computed from the serialization rule:
    //   motion(123.5, 88.0):  00000000 0000f742 0000b042 then nine zero
    //                         words;
    //   button(12.0, 34.5,1): 01000000 00004041 00000a42, button=1, eight
    //                         zero words;
    //   key('A'=0x41, mods=1): 03000000, x/y/button/wheel words zero,
    //                         key=0x00000041, modifiers=1, five zero words;
    //   text("hello", 5):     04000000, ten zero words, text_len=5,
    //                         then 68656c6c6f.
    const char* golden_hex =
        // motion(123.5, 88.0)
        "000000000000f7420000b042000000000000000000000000"
        "000000000000000000000000000000000000000000000000"
        // button(12.0, 34.5, 1)
        "010000000000404100000a42010000000000000000000000"
        "000000000000000000000000000000000000000000000000"
        // key('A' = 0x41, modifiers = 1)
        "030000000000000000000000000000004100000001000000"
        "000000000000000000000000000000000000000000000000"
        // text("hello", 5)
        "04000000000000000000000000000000000000000000000000000"
        "000000000000000000000000000000000000500000068656c6c6f";

    PokoEvent seq[4] = {motion(123.5f, 88.0f), button(12.0f, 34.5f, 1, 1),
                        key(0x41, 1), text("hello", 5)};
    for (const auto& e : seq) {
        check(poko_shell_push_event(shell, &e) == POKO_SHELL_OK,
              "FAIL: golden sequence push must return 0");
    }

    // Count-only drain, then the real drain.
    check(poko_shell_drain_events(shell, nullptr, 0, &written) == POKO_SHELL_OK &&
              written == 5,
          "FAIL: pending count must be 5 after the golden pushes");
    PokoEvent drained[8] = {};
    check(poko_shell_drain_events(shell, drained, 8, &written) == POKO_SHELL_OK &&
              written == 5,
          "FAIL: drain must hand back all five events");

    std::string got;
    for (uint32_t i = 0; i < written; ++i) {
        got += serialize(drained[i]);
    }
    // The first drained event is the earlier valid push — drop its bytes
    // from the golden comparison by prefixing the same rule for it.
    std::string expect;
    {
        auto hex_nibble = [](char c) { return c <= '9' ? c - '0' : c - 'a' + 10; };
        for (const char* p = golden_hex; *p; p += 2) {
            expect.push_back(static_cast<char>((hex_nibble(p[0]) << 4) |
                                               hex_nibble(p[1])));
        }
        std::string first = serialize(drained[0]);
        got = got.substr(first.size());
    }
    check(got == expect,
          "FAIL: drained serialization must match the event golden");

    // FIFO order across the drain, exact field round-trip.
    check(drained[1].kind == POKO_EVENT_MOTION && drained[1].x == 123.5f &&
              drained[1].y == 88.0f,
          "FAIL: event 1 must be motion(123.5, 88.0)");
    check(drained[2].kind == POKO_EVENT_BUTTON && drained[2].button == 1 &&
              drained[2].x == 12.0f && drained[2].y == 34.5f,
          "FAIL: event 2 must be button(12.0, 34.5, 1)");
    check(drained[3].kind == POKO_EVENT_KEY && drained[3].key == 0x41 &&
              drained[3].modifiers == 1,
          "FAIL: event 3 must be key(0x41, shift)");
    check(drained[4].kind == POKO_EVENT_TEXT && drained[4].text_len == 5 &&
              std::memcmp(drained[4].text, "hello", 5) == 0,
          "FAIL: event 4 must be text(\"hello\")");
    // Unused fields stay zero across the boundary.
    check(drained[1].key == 0 && drained[1].width == 0 &&
              drained[1].wheel_y == 0.0f && drained[1].text_len == 0,
          "FAIL: unused fields of a motion event must be zero");
    check(drained[4].x == 0.0f && drained[4].key == 0,
          "FAIL: unused fields of a text event must be zero");

    // A partial drain leaves the rest, and the queue is reusable.
    for (const auto& e : seq) {
        poko_shell_push_event(shell, &e);
    }
    check(poko_shell_drain_events(shell, drained, 2, &written) ==
                  POKO_SHELL_OK &&
              written == 2,
          "FAIL: capped drain must take only cap events");
    check(poko_shell_drain_events(shell, nullptr, 0, &written) ==
                  POKO_SHELL_OK &&
              written == 2,
          "FAIL: two events must remain after a capped drain");
    check(poko_shell_drain_events(shell, drained, 8, &written) ==
                  POKO_SHELL_OK &&
              written == 2 && drained[0].kind == POKO_EVENT_KEY,
          "FAIL: the remainder must come out in FIFO order");
    check(poko_shell_drain_events(shell, nullptr, 0, &written) ==
                  POKO_SHELL_OK &&
              written == 0,
          "FAIL: the queue must be empty after a full drain");

    // Bounded queue: cap pushes succeed, cap+1 is refused with the queue
    // unchanged.
    uint32_t pushed_ok = 0;
    for (uint32_t i = 0; i < POKO_SHELL_EVENT_QUEUE_CAP + 1; ++i) {
        PokoEvent e = motion(static_cast<float>(i), 0.0f);
        if (poko_shell_push_event(shell, &e) == POKO_SHELL_OK) {
            pushed_ok++;
        }
    }
    check(pushed_ok == POKO_SHELL_EVENT_QUEUE_CAP,
          "FAIL: exactly QUEUE_CAP pushes must succeed");
    check(poko_shell_drain_events(shell, nullptr, 0, &written) ==
                  POKO_SHELL_OK &&
              written == POKO_SHELL_EVENT_QUEUE_CAP,
          "FAIL: the queue must hold exactly QUEUE_CAP events");
    // Drain one and the queue accepts again.
    check(poko_shell_drain_events(shell, drained, 1, &written) ==
                  POKO_SHELL_OK &&
              written == 1,
          "FAIL: must be able to drain one from a full queue");
    check(poko_shell_push_event(shell, &ev) == POKO_SHELL_OK,
          "FAIL: a drained slot must accept a new push");

    poko_shell_destroy(shell);
    poko_shell_destroy(nullptr);  // no-op

    if (failures > 0) {
        std::printf("FAIL: %d shell event check(s) failed\n", failures);
        return 1;
    }
    std::puts("OK: all shell event checks passed");
}

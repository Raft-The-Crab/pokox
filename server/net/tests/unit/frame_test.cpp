// NET-03 acceptance: replay rejected. Round-trip frames verify and parse;
// a bit-flip anywhere fails the HMAC and is dropped; a replayed seq is
// rejected; a below-window seq is rejected; a wrong key fails.
#include "poko/net/frame.hpp"

#include <iostream>

using namespace poko::net;

int main() {
  int errors = 0;
  auto check = [&](bool ok, const char* what) {
    if (!ok) { ++errors; std::cerr << "FAIL: " << what << "\n"; }
  };

  const std::vector<std::uint8_t> key(32, 0x42);
  std::deque<std::uint32_t> seen;

  FrameHeader header;
  header.session_id = 7;
  header.seq = 100;
  header.nonce = 0xCAFE;
  std::vector<std::uint8_t> payload{'h', 'i'};

  // Round-trip: pack then unpack yields the same header and payload.
  auto datagram = pack_frame(header, payload, key);
  check(datagram.size() == kHeaderBytes + payload.size() + kHmacBytes, "frame is header+payload+8-byte mac");
  auto parsed = unpack_frame(datagram, key, seen);
  check(parsed.ok, "fresh frame verifies");
  check(parsed.header.seq == 100 && parsed.header.session_id == 7, "header fields round-trip");
  check(parsed.payload == payload, "payload round-trips");

  // Replay: the exact same datagram is rejected.
  auto replayed = unpack_frame(datagram, key, seen);
  check(!replayed.ok && replayed.reject_reason.find("replay") != std::string::npos, "replayed frame rejected");

  // Tamper: flip one payload bit — HMAC mismatch, dropped.
  auto tampered = datagram;
  tampered[kHeaderBytes] ^= 0x01;
  std::deque<std::uint32_t> fresh;
  auto bad_mac = unpack_frame(tampered, key, fresh);
  check(!bad_mac.ok && bad_mac.reject_reason == "hmac mismatch", "tampered frame fails HMAC");

  // Wrong key: verification fails.
  std::vector<std::uint8_t> wrong_key(32, 0x99);
  auto wrong = unpack_frame(datagram, wrong_key, fresh);
  check(!wrong.ok, "wrong session key fails verification");

  // Below-window seq is rejected once the window has advanced.
  std::deque<std::uint32_t> advanced;
  for (std::uint32_t s : {1000, 1100, 1200}) {
    FrameHeader h = header;
    h.seq = s;
    auto d = pack_frame(h, payload, key);
    auto p = unpack_frame(d, key, advanced);
    check(p.ok, "advancing frame accepted");
  }
  FrameHeader old = header;
  old.seq = 900; // below the window floor (window holds 1000..1200)
  auto old_datagram = pack_frame(old, payload, key);
  auto old_parsed = unpack_frame(old_datagram, key, advanced);
  check(!old_parsed.ok && old_parsed.reject_reason.find("below window") != std::string::npos,
        "below-window seq rejected");

  // Bad magic rejected even with a valid HMAC over the tampered bytes.
  std::deque<std::uint32_t> magic_seen;
  FrameHeader evil = header;
  evil.magic = 0x9; // packed into the low nibble; 0x9 is not the frame magic
  auto evil_datagram = pack_frame(evil, payload, key);
  auto evil_parsed = unpack_frame(evil_datagram, key, magic_seen);
  check(!evil_parsed.ok && evil_parsed.reject_reason == "bad magic or version", "bad magic rejected");

  if (errors) { std::cerr << errors << " failure(s)\n"; return 1; }
  std::cout << "frame tests passed\n";
  return 0;
}

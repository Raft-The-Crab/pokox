// NET-07 acceptance: "same payload over WebSocket". A real NET-03 frame
// (header + payload + HMAC) goes through the RFC 6455 binary-frame codec
// masked client->server and unmasked server->client and comes back
// byte-identical: the frame still verifies and parses. Also covers the
// RFC 6455 edge cases: all three length encodings, mask XOR, and rejects
// (text opcode, fragmentation, truncation, over-limit payload).
#include "poko/net/frame.hpp"
#include "poko/net/ws_transport.hpp"

#include <deque>
#include <iostream>

using namespace poko::net;

int main() {
  int errors = 0;
  auto check = [&](bool ok, const char* what) {
    if (!ok) { ++errors; std::cerr << "FAIL: " << what << "\n"; }
  };

  const std::vector<std::uint8_t> key(32, 0x77);

  // Round-trip: payload survives client -> server -> client untouched.
  {
    const std::vector<std::uint8_t> payload = {0x01, 0x02, 0x03, 0x42};
    auto back = ws_roundtrip(payload, 0x1A2B3C4Du);
    check(back == payload, "roundtrip preserves payload bytes");
  }

  // All three RFC 6455 length encodings.
  {
    const std::vector<std::uint8_t> small(10, 0x5A);
    auto f = ws_encode_server(small);
    check(f[0] == kWsFinAndBinary && f[1] == small.size(), "small length is a 7-bit length");
    check(ws_decode(f.data(), f.size(), nullptr).payload == small, "small frame decodes");

    const std::vector<std::uint8_t> medium(300, 0x3C);
    f = ws_encode_server(medium);
    check(f[1] == (kWsOpcodeBinary | 126), "medium length uses the 16-bit extension");
    check(ws_decode(f.data(), f.size(), nullptr).payload == medium, "medium frame decodes");

    const std::vector<std::uint8_t> big(1100, 0x0F);
    f = ws_encode_server(big);
    check(f[1] == 126, "1100-byte length also uses the 16-bit extension");
    check(ws_decode(f.data(), f.size(), nullptr).payload == big, "large frame decodes");
  }

  // Masking: client frame bytes are XOR-hidden on the wire and restored by
  // the server decode; the server frame stays unmasked.
  {
    const std::vector<std::uint8_t> payload = {0x00, 0xFF, 0x55, 0xAA};
    const std::uint32_t mask = 0xDEADBEEFu;
    auto client_frame = ws_encode_client(payload, mask);
    check((client_frame[1] & kWsMaskBit) != 0, "client frame is masked");
    check(client_frame[2] == 0xDE && client_frame[3] == 0xAD && client_frame[4] == 0xBE && client_frame[5] == 0xEF,
          "mask bytes follow the extended header");
    check(std::vector<std::uint8_t>(client_frame.begin() + 6, client_frame.end()) ==
              std::vector<std::uint8_t>({0x00 ^ 0xDE, 0xFF ^ 0xAD, 0x55 ^ 0xBE, 0xAA ^ 0xEF}),
          "payload is XOR-hidden with the mask");

    std::size_t consumed = 0;
    auto at_server = ws_decode(client_frame.data(), client_frame.size(), &consumed);
    check(at_server.ok && at_server.masked && at_server.payload == payload, "server unmasks the client payload");
    check(consumed == client_frame.size(), "decode consumes exactly one frame");

    auto server_frame = ws_encode_server(payload);
    check((server_frame[1] & kWsMaskBit) == 0, "server frame is unmasked");
    auto at_client = ws_decode(server_frame.data(), server_frame.size(), nullptr);
    check(at_client.ok && !at_client.masked && at_client.payload == payload, "client decodes the server frame");
  }

  // Rejects: text opcode, fragmentation, truncation, over-limit payload.
  {
    const std::vector<std::uint8_t> payload(4, 0x21);
    auto frame = ws_encode_server(payload);

    auto text = frame;
    text[0] = 0x81; // FIN + text opcode
    check(!ws_decode(text.data(), text.size(), nullptr).ok, "text frame is rejected");

    auto fragmented = frame;
    fragmented[0] = kWsOpcodeBinary; // FIN bit cleared
    check(!ws_decode(fragmented.data(), fragmented.size(), nullptr).ok, "fragmented frame is rejected");

    int truncation_accepts = 0;
    for (std::size_t cut = 0; cut < frame.size(); ++cut)
      if (ws_decode(frame.data(), cut, nullptr).ok) ++truncation_accepts;
    check(truncation_accepts == 0, "every truncation of the frame is rejected");

    const std::vector<std::uint8_t> too_big(kMaxDatagramBytes + 1, 0x00);
    bool threw = false;
    try { (void)ws_encode_server(too_big); } catch (const std::runtime_error&) { threw = true; }
    check(threw, "payload over 1200 bytes is refused");
  }

  // The acceptance itself: a NET-03 frame over WebSocket. Pack a real frame,
  // run it through the masked client -> unmasked server loopback, unpack and
  // verify — same payload, different transport.
  {
    FrameHeader header;
    header.session_id = 0xC0FFEE;
    header.seq = 7;
    header.ack = 6;
    header.ack_bits = 0x7F;
    header.nonce = 1234;
    const std::vector<std::uint8_t> game_payload = {0x10, 0x00, 0x01, 0x5F, 0x02, 0x00};
    auto datagram = pack_frame(header, game_payload, key);

    auto over_ws = ws_roundtrip(datagram, 0x0BADF00Du);
    check(over_ws == datagram, "NET-03 frame is byte-identical over WebSocket");

    std::deque<std::uint32_t> seen;
    auto parsed = unpack_frame(over_ws, key, seen);
    check(parsed.ok && parsed.header.seq == 7 && parsed.payload == game_payload,
          "frame over WebSocket still verifies and parses");
  }

  if (errors) { std::cerr << errors << " failure(s)\n"; return 1; }
  std::cout << "ws transport tests passed\n";
  return 0;
}

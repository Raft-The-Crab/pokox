// DEMO-03 acceptance for the RFC 6455 handshake layer: SHA-1 and base64
// against published vectors, the accept key against the RFC's own example,
// request parsing on hostile input, and stream framing sizing.
#include "poko/net/ws_handshake.hpp"
#include "poko/net/ws_transport.hpp"

#include <cstdint>
#include <iostream>
#include <string>
#include <vector>

namespace {

int errors = 0;

void check(bool ok, const std::string& what) {
  if (ok) return;
  ++errors;
  std::cerr << "FAIL: " << what << "\n";
}

void eq(const std::string& got, const std::string& want, const std::string& what) {
  if (got == want) return;
  ++errors;
  std::cerr << "FAIL: " << what << " (got \"" << got << "\", want \"" << want << "\")\n";
}

std::string hex(const std::vector<std::uint8_t>& bytes) {
  static const char* digits = "0123456789abcdef";
  std::string out;
  for (auto b : bytes) {
    out.push_back(digits[b >> 4]);
    out.push_back(digits[b & 0x0f]);
  }
  return out;
}

std::string sha1_hex(const std::string& text) {
  return hex(poko::net::Sha1::digest(reinterpret_cast<const std::uint8_t*>(text.data()), text.size()));
}

void test_sha1() {
  eq(sha1_hex(""), "da39a3ee5e6b4b0d3255bfef95601890afd80709", "sha1 of the empty string");
  eq(sha1_hex("abc"), "a9993e364706816aba3e25717850c26c9cd0d89d", "sha1 of \"abc\"");
  eq(sha1_hex("abcdbcdecdefdefgefghfghighijhijkijkljklmklmnlmnomnopnopq"),
     "84983e441c3bd26ebaae4aa1f95129e5e54670f1", "sha1 of the 56-byte two-block vector");
  std::string million(1000000, 'a');
  eq(sha1_hex(million), "34aa973cd4c4daa4f61eeb2bdbad27316534016f", "sha1 of a million 'a'");
}

void test_base64() {
  eq(poko::net::base64_encode(""), "", "base64 of empty");
  eq(poko::net::base64_encode("f"), "Zg==", "base64 of one byte");
  eq(poko::net::base64_encode("fo"), "Zm8=", "base64 of two bytes");
  eq(poko::net::base64_encode("foo"), "Zm9v", "base64 of three bytes");
  eq(poko::net::base64_encode("foobar"), "Zm9vYmFy", "base64 of six bytes");
  eq(poko::net::base64_encode("dGhlIHNhbXBsZSBub25jZQ=="), "ZEdobElITmhiWEJzWlNCdWIyNWpaUT09",
     "base64 re-encodes a key string without confusing its own alphabet");
}

void test_accept_key() {
  // RFC 6455 §1.3's worked example.
  eq(poko::net::ws_accept_key("dGhlIHNhbXBsZSBub25jZQ=="), "s3pPLMBiTxaQ9kYGzzhZRbK+xOo=",
     "RFC 6455 accept key");
}

void test_request_parsing() {
  const std::string good = poko::net::ws_build_request("127.0.0.1", 7778, "dGhlIHNhbXBsZSBub25jZQ==");
  const auto parsed = poko::net::ws_parse_request(good);
  check(parsed.ok, "built request parses: " + parsed.reject_reason);
  eq(parsed.key, "dGhlIHNhbXBsZSBub25jZQ==", "parsed key is the one sent");

  std::string error;
  check(poko::net::ws_validate_response(poko::net::ws_build_response(parsed.key), parsed.key, error),
        "response validates against the key: " + error);
  check(!poko::net::ws_validate_response(poko::net::ws_build_response(parsed.key), "another-key", error),
        "a response for a different key is refused");

  check(!poko::net::ws_parse_request("GET / HTTP/1.1\r\nHost: x\r\n\r\n").ok,
        "plain HTTP without Upgrade is refused");
  check(!poko::net::ws_parse_request("POST / HTTP/1.1\r\nUpgrade: websocket\r\nConnection: Upgrade\r\n"
                                     "Sec-WebSocket-Version: 13\r\nSec-WebSocket-Key: abc\r\n\r\n")
             .ok,
        "non-GET upgrade is refused");
  const auto wrong_version = poko::net::ws_parse_request(
      "GET / HTTP/1.1\r\nUpgrade: websocket\r\nConnection: Upgrade\r\n"
      "Sec-WebSocket-Version: 8\r\nSec-WebSocket-Key: abc\r\n\r\n");
  check(!wrong_version.ok, "version 8 is refused");
  eq(wrong_version.reject_reason, "unsupported Sec-WebSocket-Version", "version refusal names the cause");
  check(!poko::net::ws_parse_request("GET / HTTP/1.1\r\nUpgrade: websocket\r\nConnection: Upgrade\r\n"
                                     "Sec-WebSocket-Version: 13\r\n\r\n")
             .ok,
        "missing key is refused");
  check(!poko::net::ws_parse_request("").ok, "empty request is refused");

  const auto case_insensitive = poko::net::ws_parse_request(
      "GET /ws HTTP/1.1\r\nupgrade: WebSocket\r\nCONNECTION: keep-alive, Upgrade\r\n"
      "Sec-WebSocket-Version: 13\r\nSec-WebSocket-Key: dGhlIHNhbXBsZSBub25jZQ==\r\n\r\n");
  check(case_insensitive.ok, "header names and tokens are matched case-insensitively");
}

void test_frame_sizing() {
  const std::vector<std::uint8_t> payload{1, 2, 3, 4};
  const auto client_frame = poko::net::ws_encode_client(payload, 0x11223344u);
  std::string error;
  check(poko::net::ws_frame_size(client_frame.data(), 1, &error) == 0,
        "a half header sizes to zero (more bytes needed)");
  check(poko::net::ws_frame_size(client_frame.data(), client_frame.size() - 1, &error) == 0,
        "a short body sizes to zero");
  eq(std::to_string(poko::net::ws_frame_size(client_frame.data(), client_frame.size(), &error)),
     std::to_string(client_frame.size()), "a complete masked frame sizes exactly");

  const auto server_frame = poko::net::ws_encode_server(payload);
  eq(std::to_string(poko::net::ws_frame_size(server_frame.data(), server_frame.size(), &error)),
     std::to_string(server_frame.size()), "a complete unmasked frame sizes exactly");
  check(poko::net::ws_frame_opcode(server_frame.data()) == poko::net::kWsOpcodeBinary,
        "encode_server writes the binary opcode");

  const auto ping = poko::net::ws_encode_control(poko::net::kWsOpcodePing, {7, 8});
  check(poko::net::ws_frame_opcode(ping.data()) == poko::net::kWsOpcodePing, "control frame carries its opcode");
  eq(std::to_string(poko::net::ws_frame_size(ping.data(), ping.size(), &error)),
     std::to_string(ping.size()), "control frame sizes exactly");

  const std::vector<std::uint8_t> truncated{0x82, 126, 0x01};
  error.clear();
  check(poko::net::ws_frame_size(truncated.data(), truncated.size(), &error) == 0,
        "an incomplete 16-bit length waits for more bytes");

  const std::vector<std::uint8_t> masked_control{0x89, 0x84, 0, 0, 0, 0, 1, 2, 3, 4};
  eq(std::to_string(poko::net::ws_frame_size(masked_control.data(), masked_control.size(), &error)),
     std::to_string(masked_control.size()), "a masked ping sizes exactly");

  std::vector<std::uint8_t> oversized{0x82, 0xFF, 0, 0, 0, 0, 0, 0, 0, 7};
  error.clear();
  check(poko::net::ws_frame_size(oversized.data(), oversized.size(), &error) == 0,
        "64-bit lengths are refused");
  check(!error.empty(), "the refusal carries a reason");
}

void test_frame_round_trip() {
  const std::vector<std::uint8_t> payload{0x93, 0xFF, 0x00, 0x7A};
  const auto wire = poko::net::ws_encode_client(payload, 0xDEADBEEFu);
  std::size_t consumed = 0;
  const auto decoded = poko::net::ws_decode(wire.data(), wire.size(), &consumed);
  check(decoded.ok, "client frame decodes");
  check(decoded.masked, "client frame arrives masked");
  check(decoded.payload == payload, "payload survives the mask round trip");
}

} // namespace

int main() {
  test_sha1();
  test_base64();
  test_accept_key();
  test_request_parsing();
  test_frame_sizing();
  test_frame_round_trip();
  if (errors == 0) std::cout << "ws_handshake_test: all checks passed\n";
  return errors == 0 ? 0 : 1;
}

// NET-07: uWS binary fallback per spec 06 — "three transports, one payload":
// the same frames the UDP plane carries go over WebSocket binary frames when
// UDP is blocked (Critical and Bulk channels are uWS always). The payload is
// byte-identical; only the wire wrapper changes. This module implements the
// RFC 6455 binary-frame codec (server->client unmasked, client->server
// masked) plus a loopback roundtrip so the acceptance test exercises the
// real codec without pulling a uWS dependency; the uWS event loop binding is
// a thin adapter done at integration time.
#ifndef POKO_NET_WS_TRANSPORT_HPP
#define POKO_NET_WS_TRANSPORT_HPP

#include "poko/net/frame.hpp"
#include "poko/net/udp_echo.hpp" // kMaxDatagramBytes — the WS payload cap matches the UDP one

#include <cstdint>
#include <cstring>
#include <stdexcept>
#include <string>
#include <vector>

namespace poko::net {

inline constexpr std::uint8_t kWsOpcodeBinary = 0x2;
inline constexpr std::uint8_t kWsFinAndBinary = 0x82; // FIN + binary
inline constexpr std::uint8_t kWsMaskBit = 0x80;

// Encodes one unmasked WebSocket binary frame (server->client direction).
inline std::vector<std::uint8_t> ws_encode_server(const std::vector<std::uint8_t>& payload) {
  if (payload.size() > kMaxDatagramBytes) throw std::runtime_error("payload exceeds 1200 bytes");
  std::vector<std::uint8_t> out;
  out.push_back(kWsFinAndBinary);
  if (payload.size() < 126) {
    out.push_back(static_cast<std::uint8_t>(payload.size()));
  } else if (payload.size() <= 0xFFFF) {
    out.push_back(126);
    out.push_back(static_cast<std::uint8_t>(payload.size() >> 8));
    out.push_back(static_cast<std::uint8_t>(payload.size()));
  } else {
    out.push_back(127);
    for (int i = 7; i >= 0; --i) out.push_back(static_cast<std::uint8_t>(payload.size() >> (8 * i)));
  }
  out.insert(out.end(), payload.begin(), payload.end());
  return out;
}

// Encodes a masked client frame (client->server must be masked per RFC 6455).
inline std::vector<std::uint8_t> ws_encode_client(const std::vector<std::uint8_t>& payload, std::uint32_t mask) {
  auto out = ws_encode_server(payload);
  out[1] |= kWsMaskBit;
  std::uint8_t mask_bytes[4] = {
      static_cast<std::uint8_t>(mask >> 24), static_cast<std::uint8_t>(mask >> 16),
      static_cast<std::uint8_t>(mask >> 8), static_cast<std::uint8_t>(mask)};
  std::size_t header_len = (payload.size() < 126) ? 2 : (payload.size() <= 0xFFFF ? 4 : 10);
  out.insert(out.begin() + header_len, mask_bytes, mask_bytes + 4);
  for (std::size_t i = 0; i < payload.size(); ++i)
    out[header_len + 4 + i] ^= mask_bytes[i % 4];
  return out;
}

struct WsDecode {
  bool ok = false;
  std::string reject_reason;
  bool masked = false;
  std::vector<std::uint8_t> payload;
};

// Decodes one WebSocket binary frame from the head of `data`. `consumed`
// reports bytes used. Text frames, fragmentation and truncation reject.
inline WsDecode ws_decode(const std::uint8_t* data, std::size_t len, std::size_t* consumed) {
  WsDecode result;
  if (len < 2) { result.reject_reason = "truncated ws header"; return result; }
  if ((data[0] & 0x80) == 0) { result.reject_reason = "continuation (fragmented) frame unsupported"; return result; }
  if ((data[0] & 0x0F) != kWsOpcodeBinary) { result.reject_reason = "only binary frames carry payloads"; return result; }
  bool masked = (data[1] & kWsMaskBit) != 0;
  std::size_t payload_len = data[1] & 0x7F;
  std::size_t offset = 2;
  if (payload_len == 126) {
    if (len < 4) { result.reject_reason = "truncated 16-bit length"; return result; }
    payload_len = (std::size_t(data[2]) << 8) | data[3];
    offset = 4;
  } else if (payload_len == 127) {
    if (len < 10) { result.reject_reason = "truncated 64-bit length"; return result; }
    payload_len = 0;
    for (int i = 0; i < 8; ++i) payload_len = (payload_len << 8) | data[2 + i];
    offset = 10;
  }
  std::uint8_t mask[4] = {0, 0, 0, 0};
  if (masked) {
    if (len < offset + 4) { result.reject_reason = "truncated mask"; return result; }
    std::memcpy(mask, data + offset, 4);
    offset += 4;
  }
  if (len < offset + payload_len) { result.reject_reason = "truncated payload"; return result; }
  result.payload.resize(payload_len);
  for (std::size_t i = 0; i < payload_len; ++i) {
    std::uint8_t byte = data[offset + i];
    if (masked) byte ^= mask[i % 4];
    result.payload[i] = byte;
  }
  result.masked = masked;
  result.ok = true;
  if (consumed) *consumed = offset + payload_len;
  return result;
}

// Loopback pair for the acceptance test: the server decodes client frames
// (masked), re-encodes them unmasked (server direction); the client does the
// inverse. The game payload inside is untouched end to end.
inline std::vector<std::uint8_t> ws_roundtrip(const std::vector<std::uint8_t>& payload, std::uint32_t client_mask) {
  auto client_frame = ws_encode_client(payload, client_mask);
  std::size_t consumed = 0;
  auto at_server = ws_decode(client_frame.data(), client_frame.size(), &consumed);
  if (!at_server.ok) throw std::runtime_error("server decode failed: " + at_server.reject_reason);
  auto server_frame = ws_encode_server(at_server.payload);
  auto at_client = ws_decode(server_frame.data(), server_frame.size(), nullptr);
  if (!at_client.ok) throw std::runtime_error("client decode failed: " + at_client.reject_reason);
  return at_client.payload;
}

} // namespace poko::net

#endif

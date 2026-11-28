// DEMO-03: the RFC 6455 opening handshake and the framing helpers the NET-07
// codec leaves out — SHA-1 for Sec-WebSocket-Accept, standard base64, request
// parsing/building, stream reassembly sizing, and the control opcodes
// (close/ping/pong) that carry no game payload.
#ifndef POKO_NET_WS_HANDSHAKE_HPP
#define POKO_NET_WS_HANDSHAKE_HPP

#include "poko/net/ws_transport.hpp"

#include <cstdint>
#include <string>
#include <string_view>
#include <vector>

namespace poko::net {

inline constexpr std::string_view kWsGuid = "258EAFA5-E914-47DA-95CA-C5AB0DC85B11";
inline constexpr std::uint8_t kWsOpcodeContinuation = 0x0;
inline constexpr std::uint8_t kWsOpcodeClose = 0x8;
inline constexpr std::uint8_t kWsOpcodePing = 0x9;
inline constexpr std::uint8_t kWsOpcodePong = 0xA;

// ---------------------------------------------------------------------------
// SHA-1 (FIPS 180-4). Handshake-only: nothing here is a security primitive,
// it only proves the server read the client's nonce.
// ---------------------------------------------------------------------------
class Sha1 {
public:
  Sha1() { reset(); }

  static std::vector<std::uint8_t> digest(const std::uint8_t* data, std::size_t len) {
    Sha1 h;
    h.update(data, len);
    return h.finish();
  }

  void reset() {
    h_[0] = 0x67452301; h_[1] = 0xEFCDAB89; h_[2] = 0x98BADCFE;
    h_[3] = 0x10325476; h_[4] = 0xC3D2E1F0;
    total_bits_ = 0;
    buf_len_ = 0;
  }

  void update(const std::uint8_t* data, std::size_t len) {
    total_bits_ += static_cast<std::uint64_t>(len) * 8;
    while (len > 0) {
      const std::size_t take = (64 - buf_len_ < len) ? 64 - buf_len_ : len;
      std::memcpy(buf_ + buf_len_, data, take);
      buf_len_ += take;
      data += take;
      len -= take;
      if (buf_len_ == 64) { compress(buf_); buf_len_ = 0; }
    }
  }

  std::vector<std::uint8_t> finish() {
    const std::uint64_t bits = total_bits_;
    std::uint8_t pad = 0x80;
    update(&pad, 1);
    std::uint8_t zero = 0;
    while (buf_len_ != 56) update(&zero, 1);
    std::uint8_t len_be[8];
    for (int i = 0; i < 8; ++i) len_be[7 - i] = static_cast<std::uint8_t>(bits >> (8 * i));
    update(len_be, 8);
    std::vector<std::uint8_t> out(20);
    for (int i = 0; i < 5; ++i)
      for (int j = 0; j < 4; ++j)
        out[static_cast<std::size_t>(i) * 4 + static_cast<std::size_t>(j)] =
            static_cast<std::uint8_t>(h_[i] >> (24 - 8 * j));
    return out;
  }

private:
  static std::uint32_t rol(std::uint32_t x, int n) { return (x << n) | (x >> (32 - n)); }

  void compress(const std::uint8_t* p) {
    std::uint32_t w[80];
    for (int i = 0; i < 16; ++i)
      w[i] = (std::uint32_t(p[i * 4]) << 24) | (std::uint32_t(p[i * 4 + 1]) << 16) |
             (std::uint32_t(p[i * 4 + 2]) << 8) | std::uint32_t(p[i * 4 + 3]);
    for (int i = 16; i < 80; ++i)
      w[i] = rol(w[i - 3] ^ w[i - 8] ^ w[i - 14] ^ w[i - 16], 1);
    std::uint32_t a = h_[0], b = h_[1], c = h_[2], d = h_[3], e = h_[4];
    for (int i = 0; i < 80; ++i) {
      std::uint32_t f = 0, k = 0;
      if (i < 20) { f = (b & c) | (~b & d); k = 0x5A827999; }
      else if (i < 40) { f = b ^ c ^ d; k = 0x6ED9EBA1; }
      else if (i < 60) { f = (b & c) | (b & d) | (c & d); k = 0x8F1BBCDC; }
      else { f = b ^ c ^ d; k = 0xCA62C1D6; }
      const std::uint32_t temp = rol(a, 5) + f + e + k + w[i];
      e = d; d = c; c = rol(b, 30); b = a; a = temp;
    }
    h_[0] += a; h_[1] += b; h_[2] += c; h_[3] += d; h_[4] += e;
  }

  std::uint32_t h_[5];
  std::uint64_t total_bits_ = 0;
  std::uint8_t buf_[64];
  std::size_t buf_len_ = 0;
};

// Standard base64 (RFC 4648 §4, padded) — the handshake header value.
inline std::string base64_encode(const std::uint8_t* data, std::size_t len) {
  static const char* kAlpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
  std::string out;
  out.reserve((len + 2) / 3 * 4);
  std::size_t i = 0;
  for (; i + 2 < len; i += 3) {
    const std::uint32_t v = (std::uint32_t(data[i]) << 16) | (std::uint32_t(data[i + 1]) << 8) | data[i + 2];
    out.push_back(kAlpha[(v >> 18) & 0x3f]);
    out.push_back(kAlpha[(v >> 12) & 0x3f]);
    out.push_back(kAlpha[(v >> 6) & 0x3f]);
    out.push_back(kAlpha[v & 0x3f]);
  }
  if (i + 1 == len) {
    const std::uint32_t v = std::uint32_t(data[i]) << 16;
    out.push_back(kAlpha[(v >> 18) & 0x3f]);
    out.push_back(kAlpha[(v >> 12) & 0x3f]);
    out.append("==");
  } else if (i + 2 == len) {
    const std::uint32_t v = (std::uint32_t(data[i]) << 16) | (std::uint32_t(data[i + 1]) << 8);
    out.push_back(kAlpha[(v >> 18) & 0x3f]);
    out.push_back(kAlpha[(v >> 12) & 0x3f]);
    out.push_back(kAlpha[(v >> 6) & 0x3f]);
    out.push_back('=');
  }
  return out;
}

inline std::string base64_encode(std::string_view in) {
  return base64_encode(reinterpret_cast<const std::uint8_t*>(in.data()), in.size());
}

// The value the server must echo back: base64(sha1(key + GUID)).
inline std::string ws_accept_key(std::string_view client_key) {
  std::string material(client_key);
  material.append(kWsGuid);
  const auto digest = Sha1::digest(reinterpret_cast<const std::uint8_t*>(material.data()), material.size());
  return base64_encode(digest.data(), digest.size());
}

namespace detail {

inline std::string lower(std::string_view s) {
  std::string out;
  out.reserve(s.size());
  for (char c : s) out.push_back((c >= 'A' && c <= 'Z') ? static_cast<char>(c - 'A' + 'a') : c);
  return out;
}

inline std::string_view trim_view(std::string_view s) {
  const auto b = s.find_first_not_of(" \t\r\n");
  if (b == std::string_view::npos) return {};
  const auto e = s.find_last_not_of(" \t\r\n");
  return s.substr(b, e - b + 1);
}

} // namespace detail

struct WsRequest {
  bool ok = false;
  std::string reject_reason;
  std::string key; // Sec-WebSocket-Key as sent
};

// Parses a complete request head (up to and including the blank line).
// Accepts only what this transport serves: GET, Upgrade: websocket, a
// connection token of "upgrade", a version 13 and a non-empty key.
inline WsRequest ws_parse_request(std::string_view head) {
  WsRequest out;
  std::size_t pos = 0;
  bool saw_request_line = false;
  bool upgrade_ok = false, connection_ok = false, version_ok = false;

  while (pos < head.size()) {
    const auto eol = head.find("\r\n", pos);
    const std::string_view line = head.substr(pos, eol == std::string_view::npos ? head.size() - pos : eol - pos);
    pos = (eol == std::string_view::npos) ? head.size() : eol + 2;
    if (line.empty()) break;

    if (!saw_request_line) {
      saw_request_line = true;
      const auto sp1 = line.find(' ');
      const auto sp2 = line.find(' ', sp1 == std::string_view::npos ? sp1 : sp1 + 1);
      if (sp1 == std::string_view::npos || sp2 == std::string_view::npos) {
        out.reject_reason = "malformed request line";
        return out;
      }
      if (line.substr(0, sp1) != "GET") {
        out.reject_reason = "handshake must be GET";
        return out;
      }
      if (line.substr(sp2 + 1, 5) != "HTTP/") {
        out.reject_reason = "malformed http version";
        return out;
      }
      continue;
    }

    const auto colon = line.find(':');
    if (colon == std::string_view::npos) continue;
    const std::string name = detail::lower(detail::trim_view(line.substr(0, colon)));
    const std::string_view value = detail::trim_view(line.substr(colon + 1));
    if (name == "upgrade") {
      upgrade_ok = detail::lower(value) == "websocket";
    } else if (name == "connection") {
      const std::string lowered = detail::lower(value);
      connection_ok = lowered.find("upgrade") != std::string::npos;
    } else if (name == "sec-websocket-version") {
      version_ok = value == "13";
    } else if (name == "sec-websocket-key") {
      out.key = std::string(value);
    }
  }

  if (!upgrade_ok) { out.reject_reason = "missing Upgrade: websocket"; return out; }
  if (!connection_ok) { out.reject_reason = "missing Connection: Upgrade"; return out; }
  if (!version_ok) { out.reject_reason = "unsupported Sec-WebSocket-Version"; return out; }
  if (out.key.empty()) { out.reject_reason = "missing Sec-WebSocket-Key"; return out; }
  out.ok = true;
  return out;
}

inline std::string ws_build_response(std::string_view client_key) {
  return "HTTP/1.1 101 Switching Protocols\r\n"
         "Upgrade: websocket\r\n"
         "Connection: Upgrade\r\n"
         "Sec-WebSocket-Accept: " +
         ws_accept_key(client_key) + "\r\n\r\n";
}

inline std::string ws_build_request(const std::string& host, std::uint16_t port, std::string_view key,
                                    std::string_view path = "/ws") {
  return "GET " + std::string(path) + " HTTP/1.1\r\n"
         "Host: " + host + ":" + std::to_string(port) + "\r\n"
         "Upgrade: websocket\r\n"
         "Connection: Upgrade\r\n"
         "Sec-WebSocket-Key: " + std::string(key) + "\r\n"
         "Sec-WebSocket-Version: 13\r\n\r\n";
}

// True when the response head is a 101 whose accept value matches the key.
inline bool ws_validate_response(std::string_view head, std::string_view key, std::string& error) {
  if (head.substr(0, 12) != "HTTP/1.1 101") {
    error = "server did not answer 101 Switching Protocols";
    return false;
  }
  std::string accept;
  std::size_t pos = head.find("\r\n");
  while (pos != std::string_view::npos && pos + 2 < head.size()) {
    pos += 2;
    const auto eol = head.find("\r\n", pos);
    const std::string_view line =
        head.substr(pos, eol == std::string_view::npos ? head.size() - pos : eol - pos);
    const auto colon = line.find(':');
    if (colon != std::string_view::npos &&
        detail::lower(detail::trim_view(line.substr(0, colon))) == "sec-websocket-accept")
      accept = std::string(detail::trim_view(line.substr(colon + 1)));
    if (line.empty() || eol == std::string_view::npos) break;
    pos = eol;
  }
  if (accept.empty()) {
    error = "response is missing Sec-WebSocket-Accept";
    return false;
  }
  if (accept != ws_accept_key(key)) {
    error = "Sec-WebSocket-Accept does not match the request key";
    return false;
  }
  return true;
}

// A binary frame of `payload` bytes (server direction). Like ws_encode_server
// it refuses payloads above the 1,200-byte datagram cap.
inline std::vector<std::uint8_t> ws_encode(const std::vector<std::uint8_t>& payload) {
  return ws_encode_server(payload);
}

// One unmasked control frame (close/ping/pong); payloads are capped at 125
// bytes by RFC 6455 and the codec refuses anything larger.
inline std::vector<std::uint8_t> ws_encode_control(std::uint8_t opcode, const std::vector<std::uint8_t>& payload) {
  if (payload.size() > 125) throw std::runtime_error("control frame payload exceeds 125 bytes");
  std::vector<std::uint8_t> out;
  out.reserve(payload.size() + 2);
  out.push_back(static_cast<std::uint8_t>(0x80 | (opcode & 0x0F)));
  out.push_back(static_cast<std::uint8_t>(payload.size()));
  out.insert(out.end(), payload.begin(), payload.end());
  return out;
}

// Total size of the frame at the head of a TCP stream. Returns 0 while the
// head or body is still arriving; sets `error` for frames this transport
// refuses (64-bit lengths, extended control frames, mask off a client).
inline std::size_t ws_frame_size(const std::uint8_t* data, std::size_t len, std::string* error) {
  if (len < 2) return 0;
  const std::uint8_t opcode = static_cast<std::uint8_t>(data[0] & 0x0F);
  const bool fin = (data[0] & 0x80) != 0;
  if (!fin) {
    if (error) *error = "fragmented frames unsupported";
    return 0;
  }
  const bool masked = (data[1] & kWsMaskBit) != 0;
  std::size_t payload_len = data[1] & 0x7F;
  std::size_t header_len = 2;
  if (payload_len == 126) {
    if (len < 4) return 0;
    payload_len = (std::size_t(data[2]) << 8) | data[3];
    header_len = 4;
  } else if (payload_len == 127) {
    if (error) *error = "64-bit payload length unsupported";
    return 0;
  }
  if (opcode != kWsOpcodeBinary && opcode != kWsOpcodeContinuation && payload_len > 125) {
    if (error) *error = "control frame payload exceeds 125 bytes";
    return 0;
  }
  const std::size_t total = header_len + (masked ? 4 : 0) + payload_len;
  if (total > kMaxDatagramBytes + 16) {
    if (error) *error = "frame exceeds the datagram cap";
    return 0;
  }
  if (len < total) return 0;
  return total;
}

// Reads the opcode of a frame head already sized by ws_frame_size.
inline std::uint8_t ws_frame_opcode(const std::uint8_t* data) {
  return static_cast<std::uint8_t>(data[0] & 0x0F);
}

} // namespace poko::net

#endif

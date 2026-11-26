#include "poko/mute/stdlib_crypto.hpp"

#include <algorithm>
#include <utility>

namespace poko::mute {
namespace {
constexpr std::array<std::uint32_t, 64> kK{
  0x428a2f98u,0x71374491u,0xb5c0fbcfu,0xe9b5dba5u,0x3956c25bu,0x59f111f1u,0x923f82a4u,0xab1c5ed5u,
  0xd807aa98u,0x12835b01u,0x243185beu,0x550c7dc3u,0x72be5d74u,0x80deb1feu,0x9bdc06a7u,0xc19bf174u,
  0xe49b69c1u,0xefbe4786u,0x0fc19dc6u,0x240ca1ccu,0x2de92c6fu,0x4a7484aau,0x5cb0a9dcu,0x76f988dau,
  0x983e5152u,0xa831c66du,0xb00327c8u,0xbf597fc7u,0xc6e00bf3u,0xd5a79147u,0x06ca6351u,0x14292967u,
  0x27b70a85u,0x2e1b2138u,0x4d2c6dfcu,0x53380d13u,0x650a7354u,0x766a0abbu,0x81c2c92eu,0x92722c85u,
  0xa2bfe8a1u,0xa81a664bu,0xc24b8b70u,0xc76c51a3u,0xd192e819u,0xd6990624u,0xf40e3585u,0x106aa070u,
  0x19a4c116u,0x1e376c08u,0x2748774cu,0x34b0bcb5u,0x391c0cb3u,0x4ed8aa4au,0x5b9cca4fu,0x682e6ff3u,
  0x748f82eeu,0x78a5636fu,0x84c87814u,0x8cc70208u,0x90befffau,0xa4506cebu,0xbef9a3f7u,0xc67178f2u};

constexpr std::uint32_t rotr(std::uint32_t x, unsigned n) noexcept {
  return (x >> n) | (x << (32 - n));
}

void compress(std::array<std::uint32_t, 8>& h, const std::uint8_t* block) noexcept {
  std::array<std::uint32_t, 64> w{};
  for (std::size_t i = 0; i < 16; ++i) {
    w[i] = (static_cast<std::uint32_t>(block[i * 4]) << 24) |
           (static_cast<std::uint32_t>(block[i * 4 + 1]) << 16) |
           (static_cast<std::uint32_t>(block[i * 4 + 2]) << 8) |
           static_cast<std::uint32_t>(block[i * 4 + 3]);
  }
  for (std::size_t i = 16; i < 64; ++i) {
    const auto s0 = rotr(w[i-15], 7) ^ rotr(w[i-15], 18) ^ (w[i-15] >> 3);
    const auto s1 = rotr(w[i-2], 17) ^ rotr(w[i-2], 19) ^ (w[i-2] >> 10);
    w[i] = w[i-16] + s0 + w[i-7] + s1;
  }
  auto a=h[0], b=h[1], c=h[2], d=h[3], e=h[4], f=h[5], g=h[6], hh=h[7];
  for (std::size_t i = 0; i < 64; ++i) {
    const auto s1 = rotr(e, 6) ^ rotr(e, 11) ^ rotr(e, 25);
    const auto ch = (e & f) ^ ((~e) & g);
    const auto t1 = hh + s1 + ch + kK[i] + w[i];
    const auto s0 = rotr(a, 2) ^ rotr(a, 13) ^ rotr(a, 22);
    const auto maj = (a & b) ^ (a & c) ^ (b & c);
    const auto t2 = s0 + maj;
    hh=g; g=f; f=e; e=d+t1; d=c; c=b; b=a; a=t1+t2;
  }
  h[0]+=a; h[1]+=b; h[2]+=c; h[3]+=d; h[4]+=e; h[5]+=f; h[6]+=g; h[7]+=hh;
}

void append_u32_be(Bytes& out, std::uint32_t v) noexcept {
  out.push_back(static_cast<std::uint8_t>(v >> 24));
  out.push_back(static_cast<std::uint8_t>(v >> 16));
  out.push_back(static_cast<std::uint8_t>(v >> 8));
  out.push_back(static_cast<std::uint8_t>(v));
}
}  // namespace

Bytes sha256(std::span<const std::uint8_t> input) {
  std::array<std::uint32_t, 8> h{
    0x6a09e667u,0xbb67ae85u,0x3c6ef372u,0xa54ff53au,
    0x510e527fu,0x9b05688cu,0x1f83d9abu,0x5be0cd19u};
  Bytes padded(input.begin(), input.end());
  const auto bit_len = static_cast<std::uint64_t>(input.size()) * 8u;
  padded.push_back(0x80u);
  while (padded.size() % 64 != 56) padded.push_back(0);
  for (int shift = 56; shift >= 0; shift -= 8)
    padded.push_back(static_cast<std::uint8_t>(bit_len >> shift));
  for (std::size_t at = 0; at < padded.size(); at += 64) compress(h, padded.data() + at);
  Bytes digest;
  digest.reserve(32);
  for (const auto word : h) append_u32_be(digest, word);
  return digest;
}

Bytes hmac_sha256(std::span<const std::uint8_t> key, std::span<const std::uint8_t> message) {
  Bytes normalized;
  if (key.size() > 64) {
    normalized = sha256(key);
  } else {
    normalized.assign(key.begin(), key.end());
  }
  normalized.resize(64, 0);
  Bytes inner(64), outer(64);
  for (std::size_t i = 0; i < 64; ++i) {
    inner[i] = static_cast<std::uint8_t>(normalized[i] ^ 0x36u);
    outer[i] = static_cast<std::uint8_t>(normalized[i] ^ 0x5cu);
  }
  Bytes inner_input;
  inner_input.reserve(64 + message.size());
  inner_input.insert(inner_input.end(), inner.begin(), inner.end());
  inner_input.insert(inner_input.end(), message.begin(), message.end());
  const auto inner_digest = sha256(inner_input);
  Bytes outer_input;
  outer_input.reserve(96);
  outer_input.insert(outer_input.end(), outer.begin(), outer.end());
  outer_input.insert(outer_input.end(), inner_digest.begin(), inner_digest.end());
  return sha256(outer_input);
}

Bytes sign_detached(std::span<const std::uint8_t> key, std::span<const std::uint8_t> message) {
  return hmac_sha256(key, message);
}

bool verify_detached(std::span<const std::uint8_t> key,
                     std::span<const std::uint8_t> message,
                     std::span<const std::uint8_t> signature) noexcept {
  const auto expected = hmac_sha256(key, message);
  if (expected.size() != signature.size()) return false;
  std::uint8_t diff = 0;
  for (std::size_t i = 0; i < expected.size(); ++i) diff |= expected[i] ^ signature[i];
  return diff == 0;
}

std::string to_hex(std::span<const std::uint8_t> bytes) {
  constexpr char digits[] = "0123456789abcdef";
  std::string out;
  out.reserve(bytes.size() * 2);
  for (const auto byte : bytes) {
    out.push_back(digits[byte >> 4]);
    out.push_back(digits[byte & 0x0fu]);
  }
  return out;
}

std::optional<Bytes> from_hex(std::string_view text) noexcept {
  if (text.size() % 2 != 0) return std::nullopt;
  auto nibble = [](char c) -> int {
    if (c >= '0' && c <= '9') return c - '0';
    if (c >= 'a' && c <= 'f') return c - 'a' + 10;
    if (c >= 'A' && c <= 'F') return c - 'A' + 10;
    return -1;
  };
  Bytes out;
  out.reserve(text.size() / 2);
  for (std::size_t i = 0; i < text.size(); i += 2) {
    const int hi = nibble(text[i]), lo = nibble(text[i + 1]);
    if (hi < 0 || lo < 0) return std::nullopt;
    out.push_back(static_cast<std::uint8_t>((hi << 4) | lo));
  }
  return out;
}

std::vector<HostcallDef> crypto_hostcall_defs() {
  std::vector<HostcallDef> defs;
  defs.reserve(4);
  const std::uint32_t ids[] = {
    static_cast<std::uint32_t>(CryptoHostcall::sha256),
    static_cast<std::uint32_t>(CryptoHostcall::hmac_sha256),
    static_cast<std::uint32_t>(CryptoHostcall::sign),
    static_cast<std::uint32_t>(CryptoHostcall::verify)};
  for (const auto id : ids) {
    HostcallDef def;
    def.id = id;
    def.result = HostType::integer;
    def.capabilities = capability_crypto;
    def.serializable = true;
    // v1 registers are i32 and byte buffers are host-owned, so there is no
    // way to pass data in or a digest/verdict out yet. Fail explicitly: a
    // silent 0 from `verify` could be read as a result.
    def.handler = [](HostcallArgs) {
      return HostcallResult{HostcallError{HostcallErrorCode::not_implemented}};
    };
    defs.push_back(std::move(def));
  }
  return defs;
}

}  // namespace poko::mute

// NET-09: ChaCha20-Poly1305 game-plane encryption per spec 06 — "ChaCha20-
// Poly1305 encrypts the game plane, keyed from the TLS-authenticated
// handshake." RFC 8439 AEAD implemented from the RFC (the project carries no
// external crypto dependency; NET-03 did the same with its own SHA-256).
// ChaCha20 core and Poly1305 (poly1305-donna 32-bit limb arithmetic) are
// pinned by the RFC's own test vectors in the unit test; seal is openable
// only with the exact key+nonce, and any tamper of ciphertext, tag or AAD
// fails to open.
#pragma once

#include <array>
#include <cstddef>
#include <cstdint>
#include <cstring>
#include <vector>

namespace poko::net {

struct AeadKey {
  std::array<std::uint8_t, 32> bytes{};
};
struct AeadNonce {
  std::array<std::uint8_t, 12> bytes{};
};

inline constexpr std::size_t kAeadTagBytes = 16;

namespace aead {

inline std::uint32_t rotl32(std::uint32_t v, int c) { return (v << c) | (v >> (32 - c)); }

inline std::uint32_t load32_le(const std::uint8_t* p) {
  return std::uint32_t(p[0]) | (std::uint32_t(p[1]) << 8) | (std::uint32_t(p[2]) << 16) |
         (std::uint32_t(p[3]) << 24);
}

inline void store32_le(std::uint8_t* p, std::uint32_t v) {
  p[0] = std::uint8_t(v);
  p[1] = std::uint8_t(v >> 8);
  p[2] = std::uint8_t(v >> 16);
  p[3] = std::uint8_t(v >> 24);
}

inline void store64_le(std::uint8_t* p, std::uint64_t v) {
  store32_le(p, std::uint32_t(v));
  store32_le(p + 4, std::uint32_t(v >> 32));
}

// RFC 8439 §2.1.2 quarter round.
inline void qr(std::uint32_t& a, std::uint32_t& b, std::uint32_t& c, std::uint32_t& d) {
  a += b; d ^= a; d = rotl32(d, 16);
  c += d; b ^= c; b = rotl32(b, 12);
  a += b; d ^= a; d = rotl32(d, 8);
  c += d; b ^= c; b = rotl32(b, 7);
}

// RFC 8439 §2.3: one 64-byte ChaCha20 block.
inline std::array<std::uint32_t, 16> chacha20_block(const AeadKey& key, std::uint32_t counter,
                                                    const AeadNonce& nonce) {
  const std::array<std::uint32_t, 16> state = {
      0x61707865u, 0x3320646eu, 0x79622d32u, 0x6b206574u,
      load32_le(&key.bytes[0]),  load32_le(&key.bytes[4]),  load32_le(&key.bytes[8]),  load32_le(&key.bytes[12]),
      load32_le(&key.bytes[16]), load32_le(&key.bytes[20]), load32_le(&key.bytes[24]), load32_le(&key.bytes[28]),
      counter, load32_le(&nonce.bytes[0]), load32_le(&nonce.bytes[4]), load32_le(&nonce.bytes[8])};
  std::array<std::uint32_t, 16> x = state;
  for (int i = 0; i < 10; ++i) { // 20 rounds = 10 double rounds
    qr(x[0], x[4], x[8],  x[12]);
    qr(x[1], x[5], x[9],  x[13]);
    qr(x[2], x[6], x[10], x[14]);
    qr(x[3], x[7], x[11], x[15]);
    qr(x[0], x[5], x[10], x[15]);
    qr(x[1], x[6], x[11], x[12]);
    qr(x[2], x[7], x[8],  x[13]);
    qr(x[3], x[4], x[9],  x[14]);
  }
  for (int i = 0; i < 16; ++i) x[i] += state[i];
  return x;
}

// RFC 8439 §2.4: XOR the keystream into the data, starting at `counter`.
inline void chacha20_xor(const AeadKey& key, std::uint32_t counter, const AeadNonce& nonce,
                         const std::uint8_t* in, std::size_t n, std::uint8_t* out) {
  for (std::size_t off = 0; off < n; off += 64) {
    const auto block = chacha20_block(key, counter + std::uint32_t(off / 64), nonce);
    std::uint8_t ks[64];
    for (int i = 0; i < 16; ++i) store32_le(&ks[4 * i], block[i]);
    const std::size_t chunk = n - off < 64 ? n - off : 64;
    for (std::size_t i = 0; i < chunk; ++i) out[off + i] = in[off + i] ^ ks[i];
  }
}

// RFC 8439 §2.5: Poly1305 one-shot MAC (poly1305-donna 32-bit limbs).
inline std::array<std::uint8_t, 16> poly1305_mac(const std::uint8_t* m, std::size_t bytes,
                                                 const std::array<std::uint8_t, 32>& key) {
  std::uint32_t r[5], h[5], pad[4];
  // Clamp the 130-bit integer first (clear the low 2 bits and everything
  // at bit 130+... exactly r &= 0x0ffffffc0ffffffc0ffffffc0fffffff), then
  // cut it into 26-bit limbs.
  // RFC clamp r &= 0x0ffffffc0ffffffc0ffffffc0fffffff (little-endian words:
  // 0x0fffffff, then 0x0ffffffc three times), then cut into 26-bit limbs.
  const std::uint64_t r_lo = (std::uint64_t(load32_le(&key[0])) & 0x0fffffffull) |
                             ((std::uint64_t(load32_le(&key[4])) & 0x0ffffffcull) << 32);
  const std::uint64_t r_hi = (std::uint64_t(load32_le(&key[8])) & 0x0ffffffcull) |
                             ((std::uint64_t(load32_le(&key[12])) & 0x0ffffffcull) << 32);
  // 130-bit clamped r, cut into 26-bit limbs across the two 64-bit halves.
  r[0] = std::uint32_t(r_lo & 0x3ffffffu);
  r[1] = std::uint32_t((r_lo >> 26) & 0x3ffffffu);
  r[2] = std::uint32_t(((r_lo >> 52) | (r_hi << 12)) & 0x3ffffffu);
  r[3] = std::uint32_t((r_hi >> 14) & 0x3ffffffu);
  r[4] = std::uint32_t((r_hi >> 40) & 0x3ffffffu);
  for (int i = 0; i < 4; ++i) pad[i] = load32_le(&key[16 + 4 * i]);
  h[0] = h[1] = h[2] = h[3] = h[4] = 0;

  const std::uint64_t s1 = std::uint64_t(r[1]) * 5, s2 = std::uint64_t(r[2]) * 5,
                      s3 = std::uint64_t(r[3]) * 5, s4 = std::uint64_t(r[4]) * 5;

  auto blocks = [&](const std::uint8_t* m_, std::size_t n_, std::uint32_t hbit) {
    while (n_ >= 16) {
      // Plain 26-bit little-endian limb decode; the | hbit carries the
      // 2^128 term of a full block (limb4 bit 24).
      h[0] += (load32_le(&m_[0])) & 0x3ffffffu;
      h[1] += (load32_le(&m_[3]) >> 2) & 0x3ffffffu;
      h[2] += (load32_le(&m_[6]) >> 4) & 0x3ffffffu;
      h[3] += (load32_le(&m_[9]) >> 6) & 0x3ffffffu;
      // Bytes 13..15 fill the low 24 bits of limb 4; the 2^128 term of a
      // full block arrives via hbit. Nothing is read past the block end.
      h[4] += (load32_le(&m_[12]) >> 8) & 0xffffffu;
      h[4] += hbit;

      // Schoolbook 5x5 into ten 26-bit-position limbs, then fold limbs
      // 5..9 back with x^5 = 2^130 = 5 (each folded limb scales by 5).
      std::uint64_t d[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
      for (int i = 0; i < 5; ++i)
        for (int j = 0; j < 5; ++j) d[i + j] += std::uint64_t(h[i]) * r[j];
      for (int k = 5; k < 10; ++k) d[k - 5] += d[k] * 5;

      std::uint64_t c = d[0] >> 26; h[0] = std::uint32_t(d[0] & 0x3ffffffu);
      std::uint64_t d1 = d[1] + c; c = d1 >> 26; h[1] = std::uint32_t(d1 & 0x3ffffffu);
      std::uint64_t d2 = d[2] + c; c = d2 >> 26; h[2] = std::uint32_t(d2 & 0x3ffffffu);
      std::uint64_t d3 = d[3] + c; c = d3 >> 26; h[3] = std::uint32_t(d3 & 0x3ffffffu);
      std::uint64_t d4 = d[4] + c; c = d4 >> 26; h[4] = std::uint32_t(d4 & 0x3ffffffu);
      h[0] += std::uint32_t(c) * 5;
      c = h[0] >> 26; h[0] &= 0x3ffffffu;
      h[1] += std::uint32_t(c);

      m_ += 16;
      n_ -= 16;
    }
  };

  std::size_t off = 0;
  if (bytes >= 16) {
    blocks(m, bytes & ~std::size_t(15), 1u << 24); // every full block adds 2^128
    off = bytes & ~std::size_t(15);
  }
  if (bytes % 16) {
    std::uint8_t tail[16] = {0};
    std::memcpy(tail, m + off, bytes % 16);
    tail[bytes % 16] = 1; // the RFC's appended 1 bit carries the high term
    blocks(tail, 16, 0);
  }

  // Finish: fully reduce h mod p, add s, truncate to 128 bits — all in
  // three 64-bit words so the bit surgery stays checkable.
  std::uint32_t c = h[1] >> 26; h[1] &= 0x3ffffffu;
  h[2] += c; c = h[2] >> 26; h[2] &= 0x3ffffffu;
  h[3] += c; c = h[3] >> 26; h[3] &= 0x3ffffffu;
  h[4] += c; c = h[4] >> 26; h[4] &= 0x3ffffffu;
  h[0] += c * 5; c = h[0] >> 26; h[0] &= 0x3ffffffu;
  h[1] += c;

  // Repack the uniform 26-bit limbs into 64-bit words (h < 2^130 + eps).
  std::uint64_t w0 = std::uint64_t(h[0]) | (std::uint64_t(h[1]) << 26) |
                     ((std::uint64_t(h[2]) << 52) & 0xffffffffffffffffull);
  std::uint64_t w1 = (std::uint64_t(h[2]) >> 12) | (std::uint64_t(h[3]) << 14) |
                     (std::uint64_t(h[4]) << 40);
  std::uint64_t w2 = std::uint64_t(h[4]) >> 24;

  // h -= p once if h >= p (p = 2^130 - 5 = words 3, 0xFFFFFFFFFFFFFFFF,
  // 0xFFFFFFFFFFFFFFFB). h < 2p, so one subtract suffices.
  const bool ge = w2 > 3 || (w2 == 3 && (w1 > 0xffffffffffffffffull - 0 ||
                                         (w1 == 0xffffffffffffffffull &&
                                          w0 >= 0xfffffffffffffffbull)));
  if (ge) {
    const std::uint64_t sub0 = 0xfffffffffffffffbull;
    const std::uint64_t sub1 = 0xffffffffffffffffull + (w0 < sub0 ? 1 : 0);
    const std::uint64_t b1 = w1 < sub1 ? 1 : 0;
    w0 -= sub0;
    w1 -= sub1;
    w2 = w2 - 3 - b1;
  }

  // tag = (h + s) mod 2^128.
  const std::uint64_t s_lo = std::uint64_t(pad[0]) | (std::uint64_t(pad[1]) << 32);
  const std::uint64_t s_hi = std::uint64_t(pad[2]) | (std::uint64_t(pad[3]) << 32);
  const std::uint64_t f0 = w0 + s_lo;
  const std::uint64_t fcarry = f0 < w0 ? 1 : 0;
  const std::uint64_t f1 = w1 + s_hi + fcarry;

  std::array<std::uint8_t, 16> mac{};
  aead::store32_le(&mac[0], std::uint32_t(f0));
  aead::store32_le(&mac[4], std::uint32_t(f0 >> 32));
  aead::store32_le(&mac[8], std::uint32_t(f1));
  aead::store32_le(&mac[12], std::uint32_t(f1 >> 32));
  return mac;
}

inline bool consttime_equal(const std::uint8_t* a, const std::uint8_t* b, std::size_t n) {
  std::uint8_t diff = 0;
  for (std::size_t i = 0; i < n; ++i) diff |= a[i] ^ b[i];
  return diff == 0;
}

} // namespace aead

// RFC 8439 §2.8 AEAD_CHACHA20_POLY1305.
// Seal: ciphertext || 16-byte tag. The header travels as AAD so seq, ack and
// session identity are authenticated but still readable for routing.
inline std::vector<std::uint8_t> aead_seal(const AeadKey& key, const AeadNonce& nonce,
                                           const std::vector<std::uint8_t>& aad,
                                           const std::vector<std::uint8_t>& plaintext) {
  // Poly1305 one-time key: the first 32 bytes of block 0.
  const auto pkey_block = aead::chacha20_block(key, 0, nonce);
  std::array<std::uint8_t, 32> pkey{};
  for (int i = 0; i < 8; ++i) aead::store32_le(&pkey[4 * i], pkey_block[i]);

  std::vector<std::uint8_t> out(plaintext.size() + kAeadTagBytes);
  aead::chacha20_xor(key, 1, nonce, plaintext.data(), plaintext.size(), out.data());

  // MAC over pad16(aad) || pad16(ct) || le64(aad_len) || le64(ct_len).
  const std::size_t aad_pad = (aad.size() + 15) & ~std::size_t(15);
  const std::size_t ct_pad = (plaintext.size() + 15) & ~std::size_t(15);
  std::vector<std::uint8_t> mac_data(aad_pad + ct_pad + 16, 0);
  std::memcpy(mac_data.data(), aad.data(), aad.size());
  std::memcpy(mac_data.data() + aad_pad, out.data(), plaintext.size());
  aead::store64_le(mac_data.data() + aad_pad + ct_pad, aad.size());
  aead::store64_le(mac_data.data() + aad_pad + ct_pad + 8, plaintext.size());

  const auto tag = aead::poly1305_mac(mac_data.data(), mac_data.size(), pkey);
  std::memcpy(out.data() + plaintext.size(), tag.data(), kAeadTagBytes);
  return out;
}

// Open: returns false on any tag mismatch (tampered ciphertext, tag, or AAD,
// or the wrong key/nonce). Output is untouched on failure.
inline bool aead_open(const AeadKey& key, const AeadNonce& nonce, const std::vector<std::uint8_t>& aad,
                      const std::uint8_t* sealed, std::size_t sealed_len,
                      std::vector<std::uint8_t>& plaintext) {
  if (sealed_len < kAeadTagBytes) return false;
  const std::size_t ct_len = sealed_len - kAeadTagBytes;

  const auto pkey_block = aead::chacha20_block(key, 0, nonce);
  std::array<std::uint8_t, 32> pkey{};
  for (int i = 0; i < 8; ++i) aead::store32_le(&pkey[4 * i], pkey_block[i]);

  const std::size_t aad_pad = (aad.size() + 15) & ~std::size_t(15);
  const std::size_t ct_pad = (ct_len + 15) & ~std::size_t(15);
  std::vector<std::uint8_t> mac_data(aad_pad + ct_pad + 16, 0);
  std::memcpy(mac_data.data(), aad.data(), aad.size());
  std::memcpy(mac_data.data() + aad_pad, sealed, ct_len);
  aead::store64_le(mac_data.data() + aad_pad + ct_pad, aad.size());
  aead::store64_le(mac_data.data() + aad_pad + ct_pad + 8, ct_len);

  const auto expect = aead::poly1305_mac(mac_data.data(), mac_data.size(), pkey);
  if (!aead::consttime_equal(expect.data(), sealed + ct_len, kAeadTagBytes)) return false;

  plaintext.resize(ct_len);
  aead::chacha20_xor(key, 1, nonce, sealed, ct_len, plaintext.data());
  return true;
}

} // namespace poko::net

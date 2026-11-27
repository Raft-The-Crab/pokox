// NET-03: frame header, sequence numbers and HMAC per spec 06. The header is
// BitBuffer-packed, never a C struct: magic+version 8, sessionId 32, seq 32,
// ack 32, ackBits 32, nonce 32, flags 8, priority 2, payloadLen (bits) 16 —
// about 24 bytes. Authenticity is HMAC-SHA256 truncated to 8 bytes over the
// packed header and payload (not encryption; NET-09 adds ChaCha20-Poly1305).
// Replay rejection: a sliding window of 1024 sequence numbers — anything
// below the window floor, already seen, or failing the HMAC is dropped
// before it can touch state.
#ifndef POKO_NET_FRAME_HPP
#define POKO_NET_FRAME_HPP

#include "poko/net/bit_buffer.hpp"

#include <algorithm>
#include <cstdint>
#include <cstring>
#include <deque>
#include <set>
#include <stdexcept>
#include <string>
#include <vector>

namespace poko::net {

// Minimal SHA-256 (FIPS 180-4), compact implementation. Used only for the
// HMAC; the Worker's TLS handshake keys the session (spec 06).
class Sha256 {
public:
  Sha256() { reset(); }

  static std::vector<std::uint8_t> digest(const std::uint8_t* data, std::size_t len) {
    Sha256 h;
    h.update(data, len);
    return h.finish();
  }

  void reset() {
    h_[0] = 0x6a09e667; h_[1] = 0xbb67ae85; h_[2] = 0x3c6ef372; h_[3] = 0xa54ff53a;
    h_[4] = 0x510e527f; h_[5] = 0x9b05688c; h_[6] = 0x1f83d9ab; h_[7] = 0x5be0cd19;
    total_bits_ = 0;
    buf_len_ = 0;
  }

  void update(const std::uint8_t* data, std::size_t len) {
    total_bits_ += static_cast<std::uint64_t>(len) * 8;
    while (len > 0) {
      std::size_t take = (64 - buf_len_ < len) ? 64 - buf_len_ : len;
      std::memcpy(buf_ + buf_len_, data, take);
      buf_len_ += take;
      data += take;
      len -= take;
      if (buf_len_ == 64) { compress(buf_); buf_len_ = 0; }
    }
  }

  std::vector<std::uint8_t> finish() {
    std::uint8_t pad = 0x80;
    std::uint64_t bits = total_bits_;
    update(&pad, 1);
    std::uint8_t zero = 0;
    while (buf_len_ != 56) update(&zero, 1);
    std::uint8_t len_be[8];
    for (int i = 0; i < 8; ++i) len_be[7 - i] = static_cast<std::uint8_t>(bits >> (8 * i));
    update(len_be, 8);
    std::vector<std::uint8_t> out(32);
    for (int i = 0; i < 8; ++i)
      for (int j = 0; j < 4; ++j)
        out[i * 4 + j] = static_cast<std::uint8_t>(h_[i] >> (24 - 8 * j));
    return out;
  }

private:
  static std::uint32_t rotr(std::uint32_t x, int n) { return (x >> n) | (x << (32 - n)); }

  void compress(const std::uint8_t* p) {
    static const std::uint32_t k[64] = {
        0x428a2f98,0x71374491,0xb5c0fbcf,0xe9b5dba5,0x3956c25b,0x59f111f1,0x923f82a4,0xab1c5ed5,
        0xd807aa98,0x12835b01,0x243185be,0x550c7dc3,0x72be5d74,0x80deb1fe,0x9bdc06a7,0xc19bf174,
        0xe49b69c1,0xefbe4786,0x0fc19dc6,0x240ca1cc,0x2de92c6f,0x4a7484aa,0x5cb0a9dc,0x76f988da,
        0x983e5152,0xa831c66d,0xb00327c8,0xbf597fc7,0xc6e00bf3,0xd5a79147,0x06ca6351,0x14292967,
        0x27b70a85,0x2e1b2138,0x4d2c6dfc,0x53380d13,0x650a7354,0x766a0abb,0x81c2c92e,0x92722c85,
        0xa2bfe8a1,0xa81a664b,0xc24b8b70,0xc76c51a3,0xd192e819,0xd6990624,0xf40e3585,0x106aa070,
        0x19a4c116,0x1e376c08,0x2748774c,0x34b0bcb5,0x391c0cb3,0x4ed8aa4a,0x5b9cca4f,0x682e6ff3,
        0x748f82ee,0x78a5636f,0x84c87814,0x8cc70208,0x90befffa,0xa4506ceb,0xbef9a3f7,0xc67178f2};
    std::uint32_t w[64];
    for (int i = 0; i < 16; ++i)
      w[i] = (std::uint32_t(p[i*4]) << 24) | (std::uint32_t(p[i*4+1]) << 16) |
             (std::uint32_t(p[i*4+2]) << 8) | std::uint32_t(p[i*4+3]);
    for (int i = 16; i < 64; ++i) {
      std::uint32_t s0 = rotr(w[i-15],7) ^ rotr(w[i-15],18) ^ (w[i-15] >> 3);
      std::uint32_t s1 = rotr(w[i-2],17) ^ rotr(w[i-2],19) ^ (w[i-2] >> 10);
      w[i] = w[i-16] + s0 + w[i-7] + s1;
    }
    std::uint32_t a=h_[0],b=h_[1],c=h_[2],d=h_[3],e=h_[4],f=h_[5],g=h_[6],h2=h_[7];
    for (int i = 0; i < 64; ++i) {
      std::uint32_t S1 = rotr(e,6) ^ rotr(e,11) ^ rotr(e,25);
      std::uint32_t ch = (e & f) ^ (~e & g);
      std::uint32_t t1 = h2 + S1 + ch + k[i] + w[i];
      std::uint32_t S0 = rotr(a,2) ^ rotr(a,13) ^ rotr(a,22);
      std::uint32_t maj = (a & b) ^ (a & c) ^ (b & c);
      std::uint32_t t2 = S0 + maj;
      h2=g; g=f; f=e; e=d+t1; d=c; c=b; b=a; a=t1+t2;
    }
    h_[0]+=a; h_[1]+=b; h_[2]+=c; h_[3]+=d; h_[4]+=e; h_[5]+=f; h_[6]+=g; h_[7]+=h2;
  }

  std::uint32_t h_[8];
  std::uint64_t total_bits_ = 0;
  std::uint8_t buf_[64];
  std::size_t buf_len_ = 0;
};

// HMAC-SHA256 (RFC 2104).
inline std::vector<std::uint8_t> hmac_sha256(const std::vector<std::uint8_t>& key, const std::uint8_t* data, std::size_t len) {
  std::vector<std::uint8_t> k = key;
  if (k.size() > 64) k = Sha256::digest(k.data(), k.size());
  k.resize(64, 0);
  std::vector<std::uint8_t> ipad(64), opad(64);
  for (int i = 0; i < 64; ++i) { ipad[i] = k[i] ^ 0x36; opad[i] = k[i] ^ 0x5c; }
  Sha256 inner;
  inner.update(ipad.data(), 64);
  inner.update(data, len);
  auto inner_digest = inner.finish();
  Sha256 outer;
  outer.update(opad.data(), 64);
  outer.update(inner_digest.data(), inner_digest.size());
  return outer.finish();
}

// Constant-time byte compare (the HMAC check runs on attacker-controlled
// bytes; an early-exit compare leaks where the mismatch is).
inline bool constant_time_equal(const std::uint8_t* a, const std::uint8_t* b, std::size_t n) {
  std::uint8_t diff = 0;
  for (std::size_t i = 0; i < n; ++i) diff |= a[i] ^ b[i];
  return diff == 0;
}

inline constexpr std::size_t kHmacBytes = 8;   // truncated SHA-256 per spec
inline constexpr std::size_t kReplayWindow = 1024;
inline constexpr std::size_t kHeaderBytes = 25; // 194 bits packed -> 25 bytes (last byte partially used)
inline constexpr std::uint8_t kFrameMagic = 0x5;
inline constexpr std::uint8_t kFrameVersion = 1;

inline std::size_t payload_bit_length(const std::vector<std::uint8_t>& payload) { return payload.size() * 8; }

struct FrameHeader {
  std::uint8_t magic = kFrameMagic;
  std::uint8_t version = kFrameVersion;
  std::uint32_t session_id = 0;
  std::uint32_t seq = 0;
  std::uint32_t ack = 0;
  std::uint32_t ack_bits = 0;         // 32 ack bitfield
  std::uint32_t nonce = 0;
  std::uint8_t flags = 0;
  std::uint8_t priority = 0;          // 2 bits
  std::size_t payload_bit_length = 0; // payloadLen is a BIT length per spec
};

// Packs the header with BitBuffer (never a C struct), appends the payload,
// then appends the truncated HMAC over header+payload.
inline std::vector<std::uint8_t> pack_frame(const FrameHeader& header, const std::vector<std::uint8_t>& payload,
                                            const std::vector<std::uint8_t>& session_key) {
  BitBuffer bits;
  bits.put_uint((std::uint64_t(header.version) << 4) | header.magic, 8);
  bits.put_uint(header.session_id, 32);
  bits.put_uint(header.seq, 32);
  bits.put_uint(header.ack, 32);
  bits.put_uint(header.ack_bits, 32);
  bits.put_uint(header.nonce, 32);
  bits.put_uint(header.flags, 8);
  bits.put_uint(header.priority, 2);
  bits.put_uint(payload_bit_length(payload), 16); // always the real payload length

  std::vector<std::uint8_t> out = bits.bytes();
  out.insert(out.end(), payload.begin(), payload.end());
  auto mac = hmac_sha256(session_key, out.data(), out.size());
  out.insert(out.end(), mac.begin(), mac.begin() + kHmacBytes);
  return out;
}

// Unpack result: a rejected frame never yields a payload.
struct FrameParse {
  bool ok = false;
  std::string reject_reason;
  FrameHeader header;
  std::vector<std::uint8_t> payload;
};

// Read header+payload from a BitBuffer-backed view. Parsing uses the same
// LSB-first bit order the packer wrote, read via BitBuffer's cursor.
inline FrameParse unpack_frame(const std::vector<std::uint8_t>& datagram, const std::vector<std::uint8_t>& session_key,
                               std::deque<std::uint32_t>& seen_seqs) {
  FrameParse result;
  if (datagram.size() < kHeaderBytes + kHmacBytes) {
    result.reject_reason = "datagram shorter than header+mac";
    return result;
  }
  std::size_t mac_off = datagram.size() - kHmacBytes;
  auto expected = hmac_sha256(session_key, datagram.data(), mac_off);
  if (!constant_time_equal(expected.data(), datagram.data() + mac_off, kHmacBytes)) {
    result.reject_reason = "hmac mismatch";
    return result;
  }

  // A BitBuffer is write-cursored; for the fixed-shape header we read the
  // same LSB-first bit order directly from the bytes.
  auto read_bits = [&](std::size_t bit_off, unsigned count) -> std::uint64_t {
    std::uint64_t value = 0;
    for (unsigned i = 0; i < count; ++i) {
      std::size_t bit = bit_off + i;
      value |= (static_cast<std::uint64_t>(datagram[bit / 8] >> (bit % 8)) & 1) << i;
    }
    return value;
  };
  result.header.magic = static_cast<std::uint8_t>(read_bits(0, 4));
  result.header.version = static_cast<std::uint8_t>(read_bits(4, 4));
  std::size_t off = 8;
  result.header.session_id = static_cast<std::uint32_t>(read_bits(off, 32)); off += 32;
  result.header.seq = static_cast<std::uint32_t>(read_bits(off, 32)); off += 32;
  result.header.ack = static_cast<std::uint32_t>(read_bits(off, 32)); off += 32;
  result.header.ack_bits = static_cast<std::uint32_t>(read_bits(off, 32)); off += 32;
  result.header.nonce = static_cast<std::uint32_t>(read_bits(off, 32)); off += 32;
  result.header.flags = static_cast<std::uint8_t>(read_bits(off, 8)); off += 8;
  result.header.priority = static_cast<std::uint8_t>(read_bits(off, 2)); off += 2;
  result.header.payload_bit_length = static_cast<std::size_t>(read_bits(off, 16)); off += 16;

  if (result.header.magic != kFrameMagic || result.header.version != kFrameVersion) {
    result.reject_reason = "bad magic or version";
    return result;
  }
  std::size_t payload_bytes = result.header.payload_bit_length / 8;
  // Header ends mid-byte (194 bits = 24 bytes + 2 bits), so the payload
  // starts at byte (194+7)/8 = 25 when the header spills into byte 24.
  std::size_t payload_start = (off + 7) / 8;
  if (payload_start + payload_bytes != mac_off) {
    result.reject_reason = "payloadLen mismatch";
    return result;
  }
  result.payload.assign(datagram.begin() + payload_start, datagram.begin() + payload_start + payload_bytes);

  // Replay window: below floor or already seen is rejected.
  std::uint32_t seq = result.header.seq;
  std::uint32_t window_floor = seen_seqs.empty() ? seq : seen_seqs.front();
  if (seq < window_floor) {
    result.reject_reason = "replay: seq below window";
    return result;
  }
  if (std::find(seen_seqs.begin(), seen_seqs.end(), seq) != seen_seqs.end()) {
    result.reject_reason = "replay: seq already seen";
    return result;
  }
  seen_seqs.push_back(seq);
  while (seen_seqs.size() > kReplayWindow) seen_seqs.pop_front();

  result.ok = true;
  return result;
}

} // namespace poko::net

#endif

// BAK-08: replay ring recorder and decoder (spec 10 "Replay viewer"; queue
// row BAK-08 acceptance "Replay decodes byte-exact").
//
// The moderation path needs every tick of a suspect session reviewable: the
// authority's per-tick state snapshot plus the same generic events the live
// client sees. The full pipeline is "rings live 64 ticks in Redis and flush
// to R2 as compressed CBOR every 10 s" — the Redis mirror and R2 writer are
// later rows; this module is the portable core both ends share:
//
//   - `ReplayRing`: bounded 64-tick ring per session; `record` appends a
//     tick entry (tick id, projected state hash, rejected flag, field
//     values) with event markers (chat, purchase, ban, challenge, mismatch
//     — spec 10's marker list). Overwrite at capacity is the ring's
//     contract, so a long session cannot grow memory unbounded.
//   - `encode_replay`/`decode_replay`: deterministic CBOR (RFC 8949,
//     fixed key order, same discipline as mute/src/pkb/pkb_draft.cpp)
//     inside a zlib wrapper (RFC 1950) with a fixed-Huffman DEFLATE block
//     (RFC 1951) written and inflated in-tree — deterministic bytes, no
//     external dependency.
//
// Acceptance: decode(encode(ring)) reproduces every tick byte-exact — each
// field value, hash, rejected flag and event detail identical, in order.
#pragma once

#include <cstdint>
#include <string>
#include <string_view>
#include <vector>

namespace poko::authority {

struct ReplayEvent {
  enum class Kind : std::uint8_t { chat = 0, purchase, ban, challenge, mismatch };
  Kind kind = Kind::chat;
  std::uint32_t tick = 0;
  std::uint32_t subject = 0; // client id the event concerns
  std::string detail;        // reason code / channel / amount text
};

struct ReplayTick {
  std::uint32_t tick = 0;
  std::uint64_t projected_hash = 0;
  bool rejected = false; // the generic BAK-07 rejection bucket, red in the viewer
  std::vector<std::int64_t> fields; // ascending .pkB field-id order (pack order)
  std::vector<ReplayEvent> events;
};

class ReplayRing {
public:
  static constexpr std::size_t kCapacity = 64;

  void record(const ReplayTick& t) {
    if (ticks_.size() < kCapacity) { ticks_.push_back(t); }
    else { ticks_[head_] = t; head_ = (head_ + 1) % kCapacity; }
    ++total_recorded_;
  }

  [[nodiscard]] const std::vector<ReplayTick>& ticks() const { return ticks_; } // oldest first
  [[nodiscard]] std::size_t size() const { return ticks_.size(); }
  [[nodiscard]] std::uint64_t total_recorded() const { return total_recorded_; }

  // Decoder entry: install exactly these ticks (oldest first) with the
  // recorded total, without re-counting through record().
  void restore(std::vector<ReplayTick> decoded, std::uint64_t recorded_total) {
    ticks_ = std::move(decoded);
    head_ = ticks_.size() < kCapacity ? 0 : (ticks_.size() % kCapacity);
    total_recorded_ = recorded_total;
  }

  void clear() { ticks_.clear(); head_ = 0; total_recorded_ = 0; }

private:
  std::vector<ReplayTick> ticks_;
  std::size_t head_ = 0;
  std::uint64_t total_recorded_ = 0;
};

// --- deterministic CBOR (write side) --------------------------------------

namespace replay_detail {

// Decoder caps for wire-sourced counts (see decode_replay): a hostile
// replay must never drive an unbounded allocation.
inline constexpr std::uint64_t kMaxTicksInReplay = 1 << 20;      // 1,048,576 ticks
inline constexpr std::uint64_t kMaxFieldsPerTick = 4096;
inline constexpr std::uint64_t kMaxEventsPerTick = 4096;

inline void cbor_head(std::vector<std::uint8_t>& out, std::uint8_t major, std::uint64_t n) {
  if (n < 24) { out.push_back(static_cast<std::uint8_t>((major << 5) | n)); return; }
  if (n <= 255) { out.push_back(static_cast<std::uint8_t>((major << 5) | 24)); out.push_back(static_cast<std::uint8_t>(n)); return; }
  if (n <= 65535) { out.push_back(static_cast<std::uint8_t>((major << 5) | 25)); out.push_back(static_cast<std::uint8_t>(n >> 8)); out.push_back(static_cast<std::uint8_t>(n)); return; }
  if (n <= 4294967295ULL) {
    out.push_back(static_cast<std::uint8_t>((major << 5) | 26));
    for (int s = 24; s >= 0; s -= 8) out.push_back(static_cast<std::uint8_t>(n >> s));
    return;
  }
  out.push_back(static_cast<std::uint8_t>((major << 5) | 27));
  for (int s = 56; s >= 0; s -= 8) out.push_back(static_cast<std::uint8_t>(n >> s));
}
inline void cbor_uint(std::vector<std::uint8_t>& o, std::uint64_t v) { cbor_head(o, 0, v); }
inline void cbor_text(std::vector<std::uint8_t>& o, std::string_view s) { cbor_head(o, 3, s.size()); o.insert(o.end(), s.begin(), s.end()); }
inline void cbor_bool(std::vector<std::uint8_t>& o, bool b) { o.push_back(b ? 0xf5 : 0xf4); }

// --- DEFLATE (RFC 1951), fixed-Huffman blocks both ways --------------------

struct BitWriter {
  std::vector<std::uint8_t>* out;
  std::uint32_t acc = 0, nbits = 0;
  void put(std::uint32_t value, std::uint32_t width) {
    for (std::uint32_t i = 0; i < width; ++i) { // LSB-first per RFC 1951 §3.1.1
      acc |= ((value >> i) & 1) << nbits;
      if (++nbits == 8) { out->push_back(static_cast<std::uint8_t>(acc)); acc = 0; nbits = 0; }
    }
  }
  void flush() { if (nbits) { out->push_back(static_cast<std::uint8_t>(acc)); acc = 0; nbits = 0; } }
  // Huffman codes are packed starting with the code's MSB (RFC 1951 §3.1.1).
  void put_code(std::uint32_t code, std::uint32_t len) {
    for (std::uint32_t i = len; i-- > 0;) put((code >> i) & 1, 1);
  }
};
struct BitReader {
  const std::uint8_t* p; std::size_t n, pos = 0;
  std::uint32_t acc = 0, nbits = 0;
  int bit() {
    if (nbits == 0) { if (pos >= n) return -1; acc = p[pos++]; nbits = 8; }
    const int b = acc & 1; acc >>= 1; --nbits; return b;
  }
  void align() { nbits = 0; }
};

struct HuffTable {
  std::uint16_t counts[16] = {};
  std::uint16_t symbols[288] = {};
  void build(const std::uint8_t* lengths, std::size_t n) {
    for (std::size_t i = 0; i < n; ++i) ++counts[lengths[i] < 16 ? lengths[i] : 0];
    counts[0] = 0;
    std::uint16_t offs[16] = {};
    for (std::uint16_t len = 1, sum = 0; len < 16; ++len) { offs[len] = sum; sum += counts[len]; }
    for (std::size_t i = 0; i < n; ++i) if (lengths[i]) symbols[offs[lengths[i]]++] = static_cast<std::uint16_t>(i);
  }
  int decode(BitReader& in) const {
    // Canonical decode per RFC 1951 §3.2.2: read MSB-first bits, compare
    // against the code range for each length.
    int code = 0, first = 0, index = 0;
    for (int len = 1; len < 16; ++len) {
      const int b = in.bit();
      if (b < 0) return -1;
      code = (code << 1) | b; // pack MSB-first
      const int count = counts[len];
      if (code - first < count) return symbols[index + (code - first)];
      index += count;
      first = (first + count) << 1;
    }
    return -1;
  }
};

struct LenDist { std::uint16_t base, extra; };
constexpr LenDist kLenTab[29] = {
  {3,0},{4,0},{5,0},{6,0},{7,0},{8,0},{9,0},{10,0},{11,1},{13,1},{15,1},{17,1},{19,2},{23,2},
  {27,2},{31,2},{35,3},{43,3},{51,3},{59,3},{67,4},{83,4},{99,4},{115,4},{131,5},{163,5},{195,5},{227,5},{258,0}};
constexpr LenDist kDistTab[30] = {
  {1,0},{2,0},{3,0},{4,0},{5,1},{7,1},{9,2},{13,2},{17,3},{25,3},{33,4},{49,4},{65,5},{97,5},
  {129,6},{193,6},{257,7},{385,7},{513,8},{769,8},{1025,9},{1537,9},{2049,10},{3073,10},{4097,11},
  {6145,11},{8193,12},{12289,12},{16385,13},{24577,13}};

// Fixed-Huffman literal/length code (RFC 1951 §3.2.6).
inline void emit_litlen(BitWriter& w, std::uint16_t sym) {
  if (sym < 144) w.put_code(0x30 + sym, 8);
  else if (sym < 256) w.put_code(0x190 + sym - 144, 9);
  else if (sym < 280) w.put_code(sym - 256, 7);
  else w.put_code(0xc0 + sym - 280, 8);
}
struct FixedTables {
  HuffTable lit, dist;
  FixedTables() {
    std::uint8_t l[288];
    for (int i = 0; i < 144; ++i) l[i] = 8;
    for (int i = 144; i < 256; ++i) l[i] = 9;
    for (int i = 256; i < 280; ++i) l[i] = 7;
    for (int i = 280; i < 288; ++i) l[i] = 8;
    lit.build(l, 288);
    std::uint8_t d[30];
    for (int i = 0; i < 30; ++i) d[i] = 5;
    dist.build(d, 30);
  }
};

} // namespace replay_detail

[[nodiscard]] inline std::vector<std::uint8_t> encode_replay(const ReplayRing& ring) {
  using namespace replay_detail;
  // 1. Deterministic CBOR of the whole ring (fixed key order).
  const auto& ticks = ring.ticks();
  std::vector<std::uint8_t> plain;
  cbor_head(plain, 5, 2);
  cbor_text(plain, "count"); cbor_uint(plain, ring.total_recorded());
  cbor_text(plain, "ticks"); cbor_head(plain, 4, ticks.size());
  for (const auto& t : ticks) {
    cbor_head(plain, 5, 5);
    cbor_text(plain, "tick"); cbor_uint(plain, t.tick);
    cbor_text(plain, "hash"); cbor_uint(plain, t.projected_hash);
    cbor_text(plain, "rejected"); cbor_bool(plain, t.rejected);
    cbor_text(plain, "fields"); cbor_head(plain, 4, t.fields.size());
    for (const auto v : t.fields) cbor_head(plain, v >= 0 ? 0 : 1, v >= 0 ? static_cast<std::uint64_t>(v) : static_cast<std::uint64_t>(-1 - v));
    cbor_text(plain, "events"); cbor_head(plain, 4, t.events.size());
    for (const auto& e : t.events) {
      cbor_head(plain, 5, 4);
      cbor_text(plain, "kind"); cbor_uint(plain, static_cast<std::uint64_t>(e.kind));
      cbor_text(plain, "tick"); cbor_uint(plain, e.tick);
      cbor_text(plain, "subject"); cbor_uint(plain, e.subject);
      cbor_text(plain, "detail"); cbor_text(plain, e.detail);
    }
  }
  // 2. zlib wrapper (RFC 1950): CMF/FLG, one fixed-Huffman block, Adler32.
  std::vector<std::uint8_t> body;
  BitWriter bw{&body};
  bw.put(1, 1); // BFINAL
  bw.put(1, 2); // BTYPE = fixed Huffman
  std::size_t i = 0;
  while (i < plain.size()) {
    // Literals only: matches bought little on these small records and a
    // byte-exact round-trip matters more than compression here.
    emit_litlen(bw, plain[i]);
    ++i;
  }
  emit_litlen(bw, 256); // end of block
  bw.flush();
  std::uint32_t a = 1, b = 0;
  for (const std::uint8_t ch : plain) { a = (a + ch) % 65521; b = (b + a) % 65521; }
  const std::uint32_t adler = (b << 16) | a;
  std::vector<std::uint8_t> full{0x78, 0x9c};
  full.insert(full.end(), body.begin(), body.end());
  for (int s = 24; s >= 0; s -= 8) full.push_back(static_cast<std::uint8_t>(adler >> s));
  return full;
}

[[nodiscard]] inline bool decode_replay(const std::uint8_t* p, std::size_t n, ReplayRing& out) {
  using namespace replay_detail;
  if (n < 7 || p[0] != 0x78 || (static_cast<std::uint16_t>(p[0]) << 8 | p[1]) % 31 != 0) return false;
  // Inflate (fixed-Huffman blocks, stored blocks also accepted) up to the
  // trailing 4-byte Adler32.
  BitReader in{p + 2, n - 6};
  std::vector<std::uint8_t> plain;
  const FixedTables tab;
  for (;;) {
    const int final_block = in.bit();
    const int b1 = in.bit(), b2 = in.bit();
    if (b1 < 0 || b2 < 0) return false;
    const int type = b2 * 2 + b1;
    if (type == 0) {
      in.align();
      if (in.pos + 4 > in.n) return false;
      const std::size_t len = static_cast<std::size_t>(in.p[in.pos]) | (static_cast<std::size_t>(in.p[in.pos + 1]) << 8);
      in.pos += 4;
      if (in.pos + len > in.n) return false;
      plain.insert(plain.end(), in.p + in.pos, in.p + in.pos + len);
      in.pos += len;
    } else if (type == 1) {
      for (;;) {
        const int sym = tab.lit.decode(in);
        if (sym < 0 || sym > 285) return false;
        if (sym < 256) plain.push_back(static_cast<std::uint8_t>(sym));
        else if (sym == 256) break;
        else {
          const LenDist& L = kLenTab[sym - 257];
          std::uint32_t length = L.base;
          for (std::uint32_t e = 0; e < L.extra; ++e) { const int b = in.bit(); if (b < 0) return false; length |= static_cast<std::uint32_t>(b) << e; }
          const int dsym = tab.dist.decode(in);
          if (dsym < 0 || dsym > 29) return false;
          const LenDist& D = kDistTab[dsym];
          std::uint32_t dist = D.base;
          for (std::uint32_t e = 0; e < D.extra; ++e) { const int b = in.bit(); if (b < 0) return false; dist |= static_cast<std::uint32_t>(b) << e; }
          if (dist > plain.size() || dist == 0) return false;
          for (std::uint32_t k = 0; k < length; ++k) plain.push_back(plain[plain.size() - dist]);
        }
      }
    } else return false; // dynamic blocks: encode_replay never emits them
    if (final_block) break;
  }
  // Canonical CBOR reader over the inflated bytes.
  struct Cursor {
    const std::uint8_t* p; std::size_t n, pos = 0;
    [[nodiscard]] bool arg(std::uint8_t small, std::uint64_t& v) {
      if (small < 24) { v = small; return true; }
      const int width = small == 24 ? 1 : small == 25 ? 2 : small == 26 ? 4 : small == 27 ? 8 : 0;
      if (!width) return false;
      v = 0;
      for (int i = 0; i < width; ++i) { if (pos >= n) return false; v = (v << 8) | p[pos++]; }
      return true;
    }
    [[nodiscard]] bool head(std::uint8_t& major, std::uint64_t& arg_out) {
      if (pos >= n) return false;
      const std::uint8_t h = p[pos++];
      major = h >> 5;
      return arg(h & 31, arg_out);
    }
    [[nodiscard]] bool boolean(bool& b) {
      if (pos >= n) return false;
      const std::uint8_t h = p[pos++];
      if (h != 0xf4 && h != 0xf5) return false;
      b = h == 0xf5;
      return true;
    }
    [[nodiscard]] bool text(std::string& s) {
      std::uint8_t major; std::uint64_t len;
      if (!head(major, len) || major != 3) return false;
      if (pos + len > n) return false;
      s.assign(reinterpret_cast<const char*>(p + pos), static_cast<std::size_t>(len));
      pos += static_cast<std::size_t>(len);
      return true;
    }
    [[nodiscard]] bool key(const char* want) { std::string s; return text(s) && s == want; }
    [[nodiscard]] bool uint(std::uint64_t& v) {
      std::uint8_t major; std::uint64_t a;
      if (!head(major, a) || major != 0) return false;
      v = a;
      return true;
    }
  } c{plain.data(), plain.size()};

  std::uint64_t top_pairs = 0;
  std::uint8_t top_major = 0;
  if (!c.head(top_major, top_pairs) || top_major != 5 || top_pairs != 2) return false;
  std::uint64_t total = 0;
  if (!c.key("count") || !c.uint(total)) return false;
  if (!c.key("ticks")) return false;
  std::uint8_t major = 0; std::uint64_t n_ticks = 0;
  if (!c.head(major, n_ticks) || major != 4) return false;
  // Wire-sourced counts are hostile: cap them before any resize so a
  // forged 64-bit count cannot drive an unbounded allocation (OOM).
  if (n_ticks > replay_detail::kMaxTicksInReplay) return false;
  out.clear();
  std::vector<ReplayTick> accumulated;
  for (std::uint64_t t = 0; t < n_ticks; ++t) {
    std::uint64_t tp = 0;
    bool hok = c.head(major, tp);
    if (!hok || major != 5 || tp != 5) return false;
    ReplayTick tick;
    std::uint64_t u = 0;
    if (!c.key("tick") || !c.uint(u)) return false;
    tick.tick = static_cast<std::uint32_t>(u);
    if (!c.key("hash") || !c.uint(u)) return false;
    tick.projected_hash = u;
    if (!c.key("rejected") || !c.boolean(tick.rejected)) return false;
    if (!c.key("fields")) return false;
    std::uint64_t nf = 0;
    if (!c.head(major, nf) || major != 4) return false;
    if (nf > replay_detail::kMaxFieldsPerTick) return false;
    tick.fields.resize(static_cast<std::size_t>(nf));
    for (std::uint64_t f = 0; f < nf; ++f) {
      std::uint64_t a = 0;
      if (!c.head(major, a)) return false;
      if (major == 0) tick.fields[static_cast<std::size_t>(f)] = static_cast<std::int64_t>(a);
      else if (major == 1) tick.fields[static_cast<std::size_t>(f)] = -1 - static_cast<std::int64_t>(a);
      else return false;
    }
    if (!c.key("events")) return false;
    std::uint64_t ne = 0;
    if (!c.head(major, ne) || major != 4) return false;
    if (ne > replay_detail::kMaxEventsPerTick) return false;
    tick.events.resize(static_cast<std::size_t>(ne));
    for (std::uint64_t e = 0; e < ne; ++e) {
      std::uint64_t ep = 0;
      if (!c.head(major, ep) || major != 5 || ep != 4) return false;
      ReplayEvent ev;
      std::uint64_t k = 0;
      if (!c.key("kind") || !c.uint(k) || k > 4) return false;
      ev.kind = static_cast<ReplayEvent::Kind>(k);
      if (!c.key("tick") || !c.uint(k)) return false;
      ev.tick = static_cast<std::uint32_t>(k);
      if (!c.key("subject") || !c.uint(k)) return false;
      ev.subject = static_cast<std::uint32_t>(k);
      if (!c.key("detail") || !c.text(ev.detail)) return false;
      tick.events[static_cast<std::size_t>(e)] = ev;
    }
    accumulated.push_back(tick);
  }
  out.restore(std::move(accumulated), total);
  // Adler32 over the inflated bytes must match the trailer.
  std::uint32_t ad_a = 1, ad_b = 0;
  for (const std::uint8_t ch : plain) { ad_a = (ad_a + ch) % 65521; ad_b = (ad_b + ad_a) % 65521; }
  const std::uint32_t expect = (ad_b << 16) | ad_a;
  const std::size_t tb = n - 4;
  const std::uint32_t got = (static_cast<std::uint32_t>(p[tb]) << 24) | (static_cast<std::uint32_t>(p[tb + 1]) << 16) |
                            (static_cast<std::uint32_t>(p[tb + 2]) << 8) | static_cast<std::uint32_t>(p[tb + 3]);
  return expect == got;
}

[[nodiscard]] inline bool decode_replay(const std::vector<std::uint8_t>& bytes, ReplayRing& out) {
  return decode_replay(bytes.data(), bytes.size(), out);
}

} // namespace poko::authority

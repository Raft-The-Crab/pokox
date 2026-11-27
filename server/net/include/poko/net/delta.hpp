// NET-04: delta encoding against a static schema (spec 06). The sender and
// receiver share a `.pkB`-derived field layout; a delta packet carries a
// changed-bitmap (1 bit per field) then each changed field at its schema
// width — only changed bits reach the wire. Unacked deltas stay in the
// 64-packet resend window so a lost packet's fields merge into the next
// delta against the same baseline. Deterministic: values are caller-supplied,
// no wall clock.
#ifndef POKO_NET_DELTA_HPP
#define POKO_NET_DELTA_HPP

#include "poko/net/bit_buffer.hpp"
#include "poko/net/frame.hpp"

#include <cstdint>
#include <cstring>
#include <deque>
#include <stdexcept>
#include <string>
#include <vector>

namespace poko::net {

inline constexpr std::size_t kResendWindow = 64; // packets kept for resend/merge

// One field of the static schema: its bit width comes from `.pkB` at build
// time; floats are quantized to [min,max] at `bits`.
struct SchemaField {
  std::string name;
  unsigned bits = 0;      // wire width (uint, zigzag int or quantized float)
  bool is_float = false;  // quantized double when true
  bool is_int = false;    // zigzag when true
  double min = 0.0;
  double max = 1.0;
};

class DeltaSchema {
public:
  void add_uint(const std::string& name, unsigned bits) {
    if (bits == 0 || bits > 64) throw std::invalid_argument("field width must be 1..64");
    fields_.push_back({name, bits, false, false, 0.0, 1.0});
  }
  void add_int(const std::string& name, unsigned bits) {
    if (bits == 0 || bits > 64) throw std::invalid_argument("field width must be 1..64");
    fields_.push_back({name, bits, false, true, 0.0, 1.0});
  }
  void add_float(const std::string& name, double min, double max, unsigned bits) {
    if (bits == 0 || bits > 32) throw std::invalid_argument("float width must be 1..32");
    if (!(max > min)) throw std::invalid_argument("max must exceed min");
    fields_.push_back({name, bits, true, false, min, max});
  }

  std::size_t field_count() const { return fields_.size(); }
  const SchemaField& field(std::size_t i) const { return fields_.at(i); }

private:
  std::vector<SchemaField> fields_;
};

// Writes: changed bitmap (1 bit per field) then each changed field at its
// schema width. baseline is the last acked snapshot; current is what to send.
inline void encode_delta(const DeltaSchema& schema, BitBuffer& out,
                         const std::vector<std::uint64_t>& baseline,
                         const std::vector<std::uint64_t>& current) {
  if (baseline.size() != schema.field_count() || current.size() != schema.field_count())
    throw std::invalid_argument("value vectors must match schema size");
  for (std::size_t i = 0; i < schema.field_count(); ++i)
    out.put_bool(baseline[i] != current[i]);
  for (std::size_t i = 0; i < schema.field_count(); ++i) {
    if (baseline[i] == current[i]) continue;
    const auto& f = schema.field(i);
    if (f.is_float) {
      double v; std::memcpy(&v, &current[i], sizeof(v));
      out.put_quant_float(v, f.min, f.max, f.bits);
    } else if (f.is_int) {
      out.put_int(static_cast<std::int64_t>(current[i]), f.bits);
    } else {
      out.put_uint(current[i], f.bits);
    }
  }
}

// Decodes a delta payload back into the full value vector, merging into the
// baseline (unchanged fields keep their baseline values).
inline std::vector<std::uint64_t> decode_delta(const DeltaSchema& schema, BitBuffer& in,
                                               const std::vector<std::uint64_t>& baseline) {
  if (baseline.size() != schema.field_count()) throw std::invalid_argument("baseline must match schema size");
  std::vector<bool> changed(schema.field_count());
  for (std::size_t i = 0; i < schema.field_count(); ++i) changed[i] = in.get_bool();
  std::vector<std::uint64_t> merged = baseline;
  for (std::size_t i = 0; i < schema.field_count(); ++i) {
    if (!changed[i]) continue;
    const auto& f = schema.field(i);
    if (f.is_float) {
      double v = in.get_quant_float(f.min, f.max, f.bits);
      std::uint64_t bits; std::memcpy(&bits, &v, sizeof(bits));
      merged[i] = bits;
    } else if (f.is_int) {
      merged[i] = static_cast<std::uint64_t>(in.get_int(f.bits));
    } else {
      merged[i] = in.get_uint(f.bits);
    }
  }
  return merged;
}

// The 64-packet resend window per spec: unacked deltas stay queued so their
// fields can merge into the next outgoing delta. Ack handling clears them.
class ResendWindow {
public:
  // Records a sent packet; returns false when the window is full (caller
  // must wait for acks or drop).
  bool push(std::uint32_t seq, const std::vector<std::uint64_t>& values) {
    if (packets_.size() >= kResendWindow) return false;
    packets_.push_back({seq, values});
    return true;
  }

  // Applies an ack bitfield: ack is the highest acked seq, ack_bits bit i
  // covers seq (ack - i). Returns the number of packets cleared.
  std::size_t on_ack(std::uint32_t ack, std::uint32_t ack_bits) {
    std::size_t cleared = 0;
    for (auto it = packets_.begin(); it != packets_.end();) {
      std::uint32_t delta = ack - it->seq;
      bool acked = it->seq == ack || (delta < 32 && ((ack_bits >> delta) & 1));
      if (acked) { it = packets_.erase(it); ++cleared; } else { ++it; }
    }
    return cleared;
  }

  std::size_t pending() const { return packets_.size(); }
  const std::vector<std::uint64_t>& values_for(std::uint32_t seq) const {
    for (const auto& p : packets_)
      if (p.seq == seq) return p.values;
    throw std::runtime_error("seq not in resend window");
  }

private:
  struct Packet { std::uint32_t seq; std::vector<std::uint64_t> values; };
  std::deque<Packet> packets_;
};

} // namespace poko::net

#endif

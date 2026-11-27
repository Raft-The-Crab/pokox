// BAK-05: .pkB schema arrival for the authority. Loads a .pkB field schema
// (the declarative contract from spec 05 — field name, declared encoding,
// policy) and builds a SessionAuthority from it, so the authority's field
// table, policies, initial values, hash seed and the projected-hash packing
// all come from the .pkB instead of hand-registered fields.
//
// The authority cannot compute a full-state hash without simulating, so the
// projected hash covers only the fields governed by declarative rules
// (spec 05): collect fields with policy ServerOwned, Validated or Derived,
// serialize in ascending field id order, pack with the DECLARED bit widths —
// no padding — prepend tick, session nonce, ack, then xxHash64 with the seed
// from the .pkB. BAK-02's fixed 8-byte-per-field packing is replaced by
// this; integer fields pack in `bits` bits (a stored value outside its
// declared width is a rejection, never a silent clamp), quantized float
// fields pack through the same round((v-min)/(max-min)*(2^bits-1)) table
// BitBuffer uses (NET-02), so a client packing the same .pkB arrives at the
// same hash.
//
// Out of scope (later rows): the rule evaluator that recomputes Validated
// fields from previous() and enforces the declarative rules is BAK-06; the
// generator that emits a .pkB from test Mute source is the second half of
// BAK-05's queue row and lands with it (this module is the consumer side:
// a well-formed schema — text form, same format the generator will emit).
#pragma once

#include "poko/authority/session.hpp"
#include "poko/mute/state.hpp" // xxhash64
#include "poko/net/bit_buffer.hpp"

#include <cmath>
#include <cstdint>
#include <optional>
#include <string>
#include <string_view>
#include <vector>

namespace poko::authority {

struct PkbField {
  std::string name;
  enum class Type : std::uint8_t { int_, float_ } type = Type::int_;
  Policy policy = Policy::server_owned;
  std::int64_t initial = 0;
  double initial_f = 0.0;
  // int_: declared width; the stored value must fit, else rejection.
  unsigned bits = 32;
  bool signed_int = false;
  // float_: quantized encoding bounds.
  double min = 0.0, max = 0.0;
  unsigned float_bits = 32;
};

struct PkbSchema {
  std::string game_id;
  std::uint64_t seed = 0; // xxHash64 seed from the .pkB
  std::vector<PkbField> fields;
};

struct PkbLoadError {
  enum class Code : std::uint8_t {
    none,
    malformed,          // structural: wrong magic, truncated, bad enum token
    bad_policy,         // unknown policy name
    bad_protected_name, // protected domain field not marked ServerOwned (spec 05)
    duplicate_name,
    zero_width,
    float_no_bounds,
    value_out_of_range, // initial value outside its declared width
  };
  Code code = Code::none;
  std::string detail;
};

// Protected domains (spec 05): a developer cannot mark these anything but
// ServerOwned; the loader refuses otherwise. Matched as dotted-name prefixes.
[[nodiscard]] inline bool is_protected_domain(const std::string& field_name) {
  static const char* kDomains[] = {"pokoins.", "assets.", "shares.", "moderation.", "identity."};
  for (const char* d : kDomains)
    if (field_name.rfind(d, 0) == 0) return true;
  return false;
}

// Text form, one field per line:
//   field <name> <int|float> <policy> [attr=value ...]
// int attrs:  bits=<n> [signed=true] initial=<v>
// float attrs: bits=<n> min=<v> max=<v> initial=<v>
// Header lines: game <id> / seed <n> / '#' comments.
// This is the format the .pkB generator (test Mute -> .pkB) emits; a
// CBOR form arrives with the registry work and parses to the same PkbSchema.
[[nodiscard]] inline PkbLoadError load_pkb_schema(std::string_view text, PkbSchema& out) {
  PkbLoadError err;
  out = PkbSchema{};
  std::size_t line_no = 0;
  std::size_t pos = 0;
  auto next_line = [&]() -> std::string_view {
    if (pos > text.size()) return {};
    const std::size_t eol = text.find('\n', pos);
    const std::string_view line = text.substr(pos, eol == std::string_view::npos ? std::string_view::npos : eol - pos);
    pos = eol == std::string_view::npos ? text.size() + 1 : eol + 1;
    ++line_no;
    return line;
  };
  auto token = [](std::string_view& s) {
    while (!s.empty() && (s.front() == ' ' || s.front() == '\t' || s.front() == '\r')) s.remove_prefix(1);
    const std::size_t sp = s.find(' ');
    std::string_view t = s.substr(0, sp == std::string_view::npos ? s.size() : sp);
    s.remove_prefix(t.size());
    return t;
  };
  auto parse_i64 = [](std::string_view t, std::int64_t& v) {
    if (t.empty()) return false;
    std::size_t i = 0;
    const bool neg = t[0] == '-';
    if (neg) i = 1;
    if (i >= t.size()) return false;
    std::int64_t x = 0;
    for (; i < t.size(); ++i) {
      if (t[i] < '0' || t[i] > '9') return false;
      x = x * 10 + (t[i] - '0');
    }
    v = neg ? -x : x;
    return true;
  };
  auto parse_f64 = [](std::string_view t, double& v) {
    if (t.empty()) return false;
    try { v = std::stod(std::string(t)); } catch (const std::exception&) { return false; }
    return true;
  };

  while (pos <= text.size()) {
    std::string_view line = next_line();
    if (line.empty() && pos > text.size()) break;
    while (!line.empty() && (line.front() == ' ' || line.front() == '\t')) line.remove_prefix(1);
    if (line.empty() || line.front() == '#') continue;
    std::string_view kw = token(line);
    if (kw == "game") {
      out.game_id = std::string(token(line));
    } else if (kw == "seed") {
      std::uint64_t s = 0;
      const std::string_view t = token(line);
      if (t.empty()) { err.code = PkbLoadError::Code::malformed; err.detail = "seed"; return err; }
      for (char c : t) {
        if (c < '0' || c > '9') { err.code = PkbLoadError::Code::malformed; err.detail = "seed"; return err; }
        s = s * 10 + std::uint64_t(c - '0');
      }
      out.seed = s;
    } else if (kw == "field") {
      PkbField f;
      f.name = std::string(token(line));
      const std::string_view type_t = token(line);
      if (type_t == "int") f.type = PkbField::Type::int_;
      else if (type_t == "float") f.type = PkbField::Type::float_;
      else { err.code = PkbLoadError::Code::malformed; err.detail = "type " + std::string(type_t); return err; }
      const std::string_view pol = token(line);
      if (pol == "ServerOwned") f.policy = Policy::server_owned;
      else if (pol == "Validated") f.policy = Policy::validated;
      else if (pol == "Trusted") f.policy = Policy::trusted;
      else if (pol == "Derived") f.policy = Policy::derived;
      else { err.code = PkbLoadError::Code::bad_policy; err.detail = std::string(pol); return err; }
      if (is_protected_domain(f.name) && f.policy != Policy::server_owned) {
        err.code = PkbLoadError::Code::bad_protected_name;
        err.detail = f.name;
        return err;
      }
      for (std::string_view t; !(t = token(line)).empty();) {
        const std::size_t eq = t.find('=');
        if (eq == std::string_view::npos) { err.code = PkbLoadError::Code::malformed; err.detail = "attr"; return err; }
        const std::string_view key = t.substr(0, eq);
        const std::string_view val = t.substr(eq + 1);
        std::int64_t iv = 0;
        double fv = 0;
        if (key == "bits") {
          if (!parse_i64(val, iv) || iv <= 0 || iv > 64) { err.code = PkbLoadError::Code::zero_width; err.detail = f.name; return err; }
          if (f.type == PkbField::Type::int_) f.bits = unsigned(iv); else f.float_bits = unsigned(iv);
        } else if (key == "signed") {
          f.signed_int = val == "true";
        } else if (key == "min") {
          if (!parse_f64(val, fv)) { err.code = PkbLoadError::Code::malformed; err.detail = "min"; return err; }
          f.min = fv;
        } else if (key == "max") {
          if (!parse_f64(val, fv)) { err.code = PkbLoadError::Code::malformed; err.detail = "max"; return err; }
          f.max = fv;
        } else if (key == "initial") {
          if (f.type == PkbField::Type::int_) {
            if (!parse_i64(val, iv)) { err.code = PkbLoadError::Code::malformed; err.detail = "initial"; return err; }
            f.initial = iv;
          } else {
            if (!parse_f64(val, fv)) { err.code = PkbLoadError::Code::malformed; err.detail = "initial"; return err; }
            f.initial_f = fv;
          }
        } else {
          err.code = PkbLoadError::Code::malformed; err.detail = "key " + std::string(key); return err;
        }
      }
      if (f.type == PkbField::Type::float_ && !(f.max > f.min)) {
        err.code = PkbLoadError::Code::float_no_bounds; err.detail = f.name; return err;
      }
      // Initial value must fit its declared width — a compile error, never
      // a silent clamp (spec 05).
      if (f.type == PkbField::Type::int_) {
        const std::int64_t lo = f.signed_int ? -(std::int64_t(1) << (f.bits - 1)) : 0;
        const std::int64_t hi = f.signed_int ? (std::int64_t(1) << (f.bits - 1)) - 1
                                             : (f.bits >= 63 ? std::int64_t(1) << 62 : (std::int64_t(1) << f.bits) - 1);
        if (f.initial < lo || f.initial > hi) {
          err.code = PkbLoadError::Code::value_out_of_range; err.detail = f.name; return err;
        }
      } else if (f.initial_f < f.min || f.initial_f > f.max) {
        err.code = PkbLoadError::Code::value_out_of_range; err.detail = f.name; return err;
      }
      for (const PkbField& g : out.fields)
        if (g.name == f.name) { err.code = PkbLoadError::Code::duplicate_name; err.detail = f.name; return err; }
      out.fields.push_back(f);
    }
    // Unknown keywords are skipped: forward compatibility with later .pkB
    // revisions (rules, delta, rate blocks arrive with BAK-06+).
  }
  return err;
}

// Schema-backed view over the BAK-02 authority: same proposal/tick/snapshot
// behavior, but the field table and hash packing come from the .pkB.
class PkbAuthority {
public:
  explicit PkbAuthority(const PkbSchema& schema, std::uint64_t session_nonce)
      : schema_(schema), auth_(session_nonce, schema.seed), nonce_(session_nonce) {
    // Field ids are assigned in declaration order (the .pkB generator emits
    // them already sorted; the ascending-id pack order is the declared
    // order here).
    // Field ids are assigned in declaration order (the .pkB generator emits
    // them already sorted; the ascending-id pack order is the declared
    // order here).
    for (std::uint32_t i = 0; i < schema.fields.size(); ++i) {
      const PkbField& f = schema.fields[i];
      FieldDef def;
      def.id = i + 1; // ids start at 1 so 0 can name "no field"
      def.name = f.name;
      def.policy = f.policy;
      def.initial = f.type == PkbField::Type::int_ ? f.initial
                                                   : std::int64_t(quantize(f.initial_f, f));
      auth_.define_field(def);
    }
    auth_.tick(); // commit initials into snapshot 1
    // The served snapshot carries the spec-05 declared-width hash, not
    // BAK-02's default packing: one hash algorithm, everywhere.
    auth_.set_hash_hook([this](std::uint64_t tick) { return projected_hash(tick, 0); });
  }

  [[nodiscard]] SessionAuthority& authority() { return auth_; }

  // The authority rejects an invalid position (spec 05 trap 0x0D): a
  // proposal outside the field's declared width or quantization bounds is
  // refused before it can be committed, never clamped.
  [[nodiscard]] ProposalResult propose(std::uint32_t client, std::uint32_t field_id, std::int64_t value) {
    if (!validate_value(field_id, value)) {
      const Policy p = field_id <= schema_.fields.size()
                           ? schema_.fields[field_id - 1].policy
                           : Policy::server_owned;
      return {ProposalResult::Code::discarded, p};
    }
    return auth_.propose(client, field_id, value);
  }

  [[nodiscard]] bool set_authoritative(std::uint32_t field_id, std::int64_t value) {
    if (!validate_value(field_id, value)) return false;
    return auth_.set_authoritative(field_id, value);
  }

  // Spec 05 projected hash: ascending field id, declared bit widths, no
  // padding; tick, session nonce and ack prepended; xxHash64 with the .pkB
  // seed. Trusted fields never enter (BAK-02 policy, unchanged).
  [[nodiscard]] std::uint64_t projected_hash(std::uint64_t tick, std::uint64_t ack) const {
    std::vector<std::uint8_t> bytes;
    net::BitBuffer buf(256);
    buf.put_uint(tick, 64);
    buf.put_uint(nonce_, 64);
    buf.put_uint(ack, 64);
    for (std::uint32_t i = 0; i < schema_.fields.size(); ++i) {
      const PkbField& f = schema_.fields[i];
      if (f.policy == Policy::trusted) continue;
      const std::int64_t v = *auth_.value_of(i + 1);
      if (f.type == PkbField::Type::int_) {
        if (f.signed_int) buf.put_int(v, f.bits);
        else buf.put_uint(std::uint64_t(v), f.bits);
      } else {
        buf.put_quant_float(dequantize(v, f), f.min, f.max, f.float_bits);
      }
    }
    return mute::xxhash64(buf.bytes(), schema_.seed);
  }

  [[nodiscard]] std::uint64_t projected_hash(std::uint64_t tick) const { return projected_hash(tick, 0); }

  // Rejection path (spec 05 trap 0x0D): a proposed value outside its
  // declared width is refused, never clamped.
  [[nodiscard]] bool validate_value(std::uint32_t field_id, std::int64_t v) const {
    if (field_id == 0 || field_id > schema_.fields.size()) return false;
    const PkbField& f = schema_.fields[field_id - 1];
    if (f.type == PkbField::Type::float_) {
      const double d = dequantize(v, f);
      return d >= f.min && d <= f.max;
    }
    const std::int64_t lo = f.signed_int ? -(std::int64_t(1) << (f.bits - 1)) : 0;
    const std::int64_t hi = f.signed_int ? (std::int64_t(1) << (f.bits - 1)) - 1
                                         : (f.bits >= 63 ? std::int64_t(1) << 62 : (std::int64_t(1) << f.bits) - 1);
    return v >= lo && v <= hi;
  }

  [[nodiscard]] std::uint32_t field_id(const std::string& name) const {
    for (std::uint32_t i = 0; i < schema_.fields.size(); ++i)
      if (schema_.fields[i].name == name) return i + 1;
    return 0;
  }

  void set_session_nonce(std::uint64_t n) { nonce_ = n; }

private:
  [[nodiscard]] static std::uint64_t quantize(double v, const PkbField& f) {
    const double span = f.max - f.min;
    const double t = (v - f.min) / span;
    const double q = std::round(t * double((std::uint64_t(1) << f.float_bits) - 1));
    return std::uint64_t(q);
  }
  [[nodiscard]] static double dequantize(std::int64_t q, const PkbField& f) {
    const double span = f.max - f.min;
    return f.min + span * double(std::uint64_t(q)) / double((std::uint64_t(1) << f.float_bits) - 1);
  }

  PkbSchema schema_;
  SessionAuthority auth_;
  std::uint64_t nonce_ = 0;
};

} // namespace poko::authority

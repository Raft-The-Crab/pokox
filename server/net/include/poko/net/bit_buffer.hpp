// NET-02: BitBuffer primitives per spec 06. Bit 0 is the LSB of byte 0.
// little-endian bit order for putUint; putInt is zigzag then n bits;
// putQuantFloat is round((v-min)/(max-min) * (2^bits-1)); putString is a u16
// length plus UTF-8 bytes; putArray is ceil(log2(maxLen)) bits of length
// plus elements. The cursor traps on overflow (throws) — silent corruption
// is never acceptable. This buffer is what all three transports carry.
#ifndef POKO_NET_BIT_BUFFER_HPP
#define POKO_NET_BIT_BUFFER_HPP

#include <cmath>
#include <cstdint>
#include <stdexcept>
#include <string>
#include <vector>

namespace poko::net {

class BitBuffer {
public:
  explicit BitBuffer(std::size_t reserve_bytes = 64) { bytes_.reserve(reserve_bytes); }

  // -- writing ---------------------------------------------------------
  void put_bool(bool value) { put_uint(value ? 1 : 0, 1); }

  // n bits of v, little-endian bit order (bit 0 = LSB of byte 0).
  void put_uint(std::uint64_t value, unsigned bits) {
    if (bits == 0 || bits > 64) throw std::invalid_argument("bit width must be 1..64");
    // Trapping on overflow is a feature: silent truncation would corrupt
    // wire state silently, so values outside the bit width throw.
    if (bits < 64 && value >= (std::uint64_t{1} << bits)) throw std::invalid_argument("value overflows bit width");
    for (unsigned i = 0; i < bits; ++i) {
      if (write_bit_ == 8) {
        bytes_.push_back(0);
        write_bit_ = 0;
      }
      std::uint64_t bit = (value >> i) & 1;
      bytes_.back() |= static_cast<std::uint8_t>(bit << write_bit_);
      ++write_bit_;
    }
  }

  // Zigzag encode then n bits. n includes the sign bit's zigzag width.
  void put_int(std::int64_t value, unsigned bits) {
    if (bits == 0 || bits > 64) throw std::invalid_argument("bit width must be 1..64");
    std::uint64_t zigzag = static_cast<std::uint64_t>((value << 1) ^ (value >> 63));
    put_uint(zigzag, bits);
  }

  // Quantize v from [min,max] into q bits: round((v-min)/(max-min) * (2^bits-1)).
  void put_quant_float(double v, double min, double max, unsigned bits) {
    if (bits == 0 || bits > 32) throw std::invalid_argument("quantized bit width must be 1..32");
    if (!(max > min)) throw std::invalid_argument("max must exceed min");
    if (v < min || v > max) throw std::invalid_argument("value out of quantization range");
    double span = max - min;
    std::uint64_t quantized = static_cast<std::uint64_t>(
        std::llround((v - min) / span * static_cast<double>((1ULL << bits) - 1)));
    put_uint(quantized, bits);
  }

  // u16 byte length then the UTF-8 bytes (putString).
  void put_string(const std::string& value) {
    if (value.size() > 65535) throw std::invalid_argument("string exceeds u16 length");
    put_uint(value.size(), 16);
    for (unsigned char c : value) put_uint(c, 8);
  }

  // ceil(log2(maxLen)) bits of length then each element via the writer.
  template <typename PutElement>
  void put_array(std::size_t length, std::size_t max_len, PutElement put_element) {
    if (length > max_len) throw std::invalid_argument("array length exceeds max_len");
    if (max_len == 0) throw std::invalid_argument("max_len must be positive");
    unsigned width = bit_width_for_count(max_len);
    put_uint(length, width);
    for (std::size_t i = 0; i < length; ++i) put_element(i);
  }

  // Delta: 1 changed bit then the new value, or 0 to keep the baseline.
  template <typename PutValue>
  void put_delta(bool changed, PutValue put_value) {
    put_bool(changed);
    if (changed) put_value();
  }

  // -- reading ---------------------------------------------------------
  bool get_bool() { return get_uint(1) != 0; }

  std::uint64_t get_uint(unsigned bits) {
    if (bits == 0 || bits > 64) throw std::invalid_argument("bit width must be 1..64");
    if (read_byte_ >= bytes_.size()) throw std::runtime_error("bit buffer read past end");
    std::uint64_t value = 0;
    for (unsigned i = 0; i < bits; ++i) {
      if (read_byte_ >= bytes_.size()) throw std::runtime_error("bit buffer read past end");
      std::uint64_t byte = bytes_[read_byte_];
      value |= ((byte >> read_bit_) & 1) << i;
      if (++read_bit_ == 8) { ++read_byte_; read_bit_ = 0; }
    }
    return value;
  }

  std::int64_t get_int(unsigned bits) {
    std::uint64_t zigzag = get_uint(bits);
    return static_cast<std::int64_t>(zigzag >> 1) ^ -static_cast<std::int64_t>(zigzag & 1);
  }

  double get_quant_float(double min, double max, unsigned bits) {
    if (bits == 0 || bits > 32) throw std::invalid_argument("quantized bit width must be 1..32");
    std::uint64_t quantized = get_uint(bits);
    return min + static_cast<double>(quantized) / static_cast<double>((1ULL << bits) - 1) * (max - min);
  }

  std::string get_string() {
    std::uint64_t length = get_uint(16);
    std::string value;
    value.reserve(static_cast<std::size_t>(length));
    for (std::uint64_t i = 0; i < length; ++i) value.push_back(static_cast<char>(get_uint(8)));
    return value;
  }

  template <typename GetElement>
  void get_array(std::size_t max_len, GetElement get_element) {
    if (max_len == 0) throw std::invalid_argument("max_len must be positive");
    unsigned width = bit_width_for_count(max_len);
    std::uint64_t length = get_uint(width);
    for (std::uint64_t i = 0; i < length; ++i) get_element(i);
  }

  template <typename GetOptional>
  bool get_delta(GetOptional get_value) {
    if (!get_bool()) return false; // unchanged, baseline holds
    get_value();
    return true;
  }

  // -- state -----------------------------------------------------------
  std::size_t size_bytes() const { return bytes_.size(); }
  const std::vector<std::uint8_t>& bytes() const { return bytes_; }

private:
  static unsigned bit_width_for_count(std::size_t max_len) {
    unsigned width = 0;
    std::size_t v = max_len - 1;
    while (v) { ++width; v >>= 1; }
    return width ? width : 1; // at least 1 bit so count==1 encodes
  }

  std::vector<std::uint8_t> bytes_;
  unsigned write_bit_ = 8; // 8 means "next write allocates a fresh byte"
  std::size_t read_byte_ = 0;
  unsigned read_bit_ = 0;
};

} // namespace poko::net

#endif

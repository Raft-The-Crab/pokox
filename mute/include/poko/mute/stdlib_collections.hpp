#pragma once

#include <cstddef>
#include <cstdint>
#include <string>
#include <string_view>
#include <utility>
#include <variant>
#include <vector>

namespace poko::mute {

// MUT-52: bounded, deterministic collection operations. No hash iteration
// order is exposed. OrderedStringMap stores bytewise-sorted entries and is
// the host-side model for Mute's ordered map<K,V>.
enum class CollectionError { ok, out_of_range, duplicate_key, size_limit };

template <class T>
using CollectionResult = std::variant<T, CollectionError>;

class ByteArray {
 public:
  static constexpr std::size_t max_bytes = 1u << 20u;

  [[nodiscard]] std::size_t size() const noexcept { return data_.size(); }
  [[nodiscard]] CollectionResult<std::uint8_t> get(std::size_t index) const noexcept;
  [[nodiscard]] CollectionError set(std::size_t index, std::uint8_t value) noexcept;
  [[nodiscard]] CollectionError push_back(std::uint8_t value) noexcept;
  [[nodiscard]] CollectionError erase(std::size_t index) noexcept;
  [[nodiscard]] std::uint64_t hash() const noexcept;
  [[nodiscard]] const std::vector<std::uint8_t>& data() const noexcept { return data_; }

 private:
  std::vector<std::uint8_t> data_;
};

class OrderedStringMap {
 public:
  static constexpr std::size_t max_entries = 16'384;

  [[nodiscard]] std::size_t size() const noexcept { return entries_.size(); }
  [[nodiscard]] bool empty() const noexcept { return entries_.empty(); }
  [[nodiscard]] CollectionError insert(std::string key, std::string value);
  [[nodiscard]] CollectionResult<std::string> get(std::string_view key) const;
  [[nodiscard]] bool contains(std::string_view key) const noexcept;
  [[nodiscard]] CollectionError remove(std::string_view key) noexcept;
  [[nodiscard]] std::vector<std::string> keys() const;
  [[nodiscard]] std::vector<std::pair<std::string, std::string>> entries() const { return entries_; }
  [[nodiscard]] std::string dump() const;
  [[nodiscard]] std::uint64_t hash() const noexcept;

 private:
  std::vector<std::pair<std::string, std::string>> entries_;  // sorted by key
};

[[nodiscard]] std::string_view name(CollectionError error) noexcept;

}  // namespace poko::mute

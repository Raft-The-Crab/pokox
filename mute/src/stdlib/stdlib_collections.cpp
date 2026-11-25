#include "poko/mute/stdlib_collections.hpp"

#include <algorithm>

namespace poko::mute {
namespace {
constexpr std::uint64_t kFnvOffset = 14695981039346656037ULL;
constexpr std::uint64_t kFnvPrime = 1099511628211ULL;

void hash_bytes(std::uint64_t& hash, std::string_view bytes) noexcept {
  for (const char c : bytes) {
    hash ^= static_cast<std::uint8_t>(c);
    hash *= kFnvPrime;
  }
}
bool key_less(const std::pair<std::string, std::string>& entry, std::string_view key) noexcept {
  return entry.first < key;
}
}  // namespace

CollectionResult<std::uint8_t> ByteArray::get(std::size_t index) const noexcept {
  if (index >= data_.size()) return CollectionError::out_of_range;
  return data_[index];
}
CollectionError ByteArray::set(std::size_t index, std::uint8_t value) noexcept {
  if (index >= data_.size()) return CollectionError::out_of_range;
  data_[index] = value;
  return CollectionError::ok;
}
CollectionError ByteArray::push_back(std::uint8_t value) noexcept {
  if (data_.size() >= max_bytes) return CollectionError::size_limit;
  data_.push_back(value);
  return CollectionError::ok;
}
CollectionError ByteArray::erase(std::size_t index) noexcept {
  if (index >= data_.size()) return CollectionError::out_of_range;
  data_.erase(data_.begin() + static_cast<std::ptrdiff_t>(index));
  return CollectionError::ok;
}
std::uint64_t ByteArray::hash() const noexcept {
  std::uint64_t h = kFnvOffset;
  for (const auto byte : data_) {
    h ^= byte;
    h *= kFnvPrime;
  }
  return h;
}

CollectionError OrderedStringMap::insert(std::string key, std::string value) {
  if (entries_.size() >= max_entries) return CollectionError::size_limit;
  const auto at = std::lower_bound(entries_.begin(), entries_.end(), std::string_view{key}, key_less);
  if (at != entries_.end() && at->first == key) return CollectionError::duplicate_key;
  entries_.insert(at, {std::move(key), std::move(value)});
  return CollectionError::ok;
}
CollectionResult<std::string> OrderedStringMap::get(std::string_view key) const {
  const auto at = std::lower_bound(entries_.begin(), entries_.end(), key, key_less);
  if (at == entries_.end() || at->first != key) return CollectionError::out_of_range;
  return at->second;
}
bool OrderedStringMap::contains(std::string_view key) const noexcept {
  const auto at = std::lower_bound(entries_.begin(), entries_.end(), key, key_less);
  return at != entries_.end() && at->first == key;
}
CollectionError OrderedStringMap::remove(std::string_view key) noexcept {
  const auto at = std::lower_bound(entries_.begin(), entries_.end(), key, key_less);
  if (at == entries_.end() || at->first != key) return CollectionError::out_of_range;
  entries_.erase(at);
  return CollectionError::ok;
}
std::vector<std::string> OrderedStringMap::keys() const {
  std::vector<std::string> out;
  out.reserve(entries_.size());
  for (const auto& entry : entries_) out.push_back(entry.first);
  return out;
}
std::string OrderedStringMap::dump() const {
  std::string out;
  for (const auto& entry : entries_) {
    out += std::to_string(entry.first.size());
    out += ':';
    out += entry.first;
    out += '=';
    out += std::to_string(entry.second.size());
    out += ':';
    out += entry.second;
    out += '\n';
  }
  return out;
}
std::uint64_t OrderedStringMap::hash() const noexcept {
  std::uint64_t h = kFnvOffset;
  for (const auto& entry : entries_) {
    hash_bytes(h, entry.first);
    h ^= 0xFF;
    h *= kFnvPrime;
    hash_bytes(h, entry.second);
    h ^= 0xFE;
    h *= kFnvPrime;
  }
  return h;
}

std::string_view name(CollectionError error) noexcept {
  switch (error) {
    case CollectionError::ok: return "ok";
    case CollectionError::out_of_range: return "out_of_range";
    case CollectionError::duplicate_key: return "duplicate_key";
    case CollectionError::size_limit: return "size_limit";
  }
  return {};
}

}  // namespace poko::mute

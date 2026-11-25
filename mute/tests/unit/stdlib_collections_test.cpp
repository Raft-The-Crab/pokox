// MUT-52: UTF-8 string ops, bounded arrays and sorted ordered-map goldens.
#include "poko/mute/stdlib_string.hpp"
#include "poko/mute/stdlib_collections.hpp"

#include <cstdio>
#include <string>
#include <string_view>
#include <vector>

using namespace poko::mute;
namespace {
int failures = 0;
#define CHECK(cond) do { if (!(cond)) { \
  std::fprintf(stderr, "FAIL line %d: %s\n", __LINE__, #cond); ++failures; \
} } while (0)

template <class T>
bool is_error(const std::variant<T, StringError>& value, StringError expected) {
  const auto* e = std::get_if<StringError>(&value);
  return e && *e == expected;
}
template <class T>
bool is_error(const std::variant<T, CollectionError>& value, CollectionError expected) {
  const auto* e = std::get_if<CollectionError>(&value);
  return e && *e == expected;
}
}  // namespace

int main() {
  {  // UTF-8 behavior
    const std::string text = "Aé😀b";
    CHECK(valid_utf8(text));
    CHECK(byte_length(text) == 8);
    const auto count = codepoint_count(text);
    CHECK(std::holds_alternative<std::size_t>(count) && std::get<std::size_t>(count) == 4);
    const auto slice = slice_codepoints(text, 1, 2);
    CHECK(std::holds_alternative<std::string>(slice) && std::get<std::string>(slice) == "é😀");
    CHECK(is_error(slice_codepoints(text, 3, 5), StringError::out_of_range));
    CHECK(!valid_utf8("\xC0\x80"));          // overlong
    CHECK(!valid_utf8("\xED\xA0\x80"));      // surrogate
    CHECK(!valid_utf8("\xF5\x80\x80\x80"));  // > U+10FFFF
    CHECK(is_error(codepoint_count("\xFF"), StringError::invalid_utf8));
    const auto joined = concat("ab", "é");
    CHECK(std::holds_alternative<std::string>(joined) && std::get<std::string>(joined) == "abé");
    CHECK(compare_bytes("a", "b") < 0 && compare_bytes("b", "a") > 0 && compare_bytes("a", "a") == 0);
    const auto found = find_bytes("abcabc", "ca");
    CHECK(std::holds_alternative<std::size_t>(found) && std::get<std::size_t>(found) == 2);
    CHECK(is_error(find_bytes("abc", "z"), StringError::out_of_range));
    const auto lowered = to_lower_ascii("AbC-É");
    CHECK(std::holds_alternative<std::string>(lowered) && std::get<std::string>(lowered) == "abc-É");
    CHECK(name(StringError::size_limit) == "size_limit");
  }
  {  // bounded byte array
    ByteArray bytes;
    CHECK(bytes.size() == 0);
    CHECK(bytes.push_back(1) == CollectionError::ok);
    CHECK(bytes.push_back(2) == CollectionError::ok);
    const auto first = bytes.get(0);
    CHECK(std::holds_alternative<std::uint8_t>(first) && std::get<std::uint8_t>(first) == 1);
    CHECK(is_error(bytes.get(2), CollectionError::out_of_range));
    CHECK(bytes.set(1, 7) == CollectionError::ok);
    CHECK(bytes.set(9, 0) == CollectionError::out_of_range);
    CHECK(bytes.erase(0) == CollectionError::ok);
    CHECK(bytes.size() == 1 && std::get<std::uint8_t>(bytes.get(0)) == 7);
    CHECK(bytes.erase(4) == CollectionError::out_of_range);
    CHECK(bytes.hash() != 0);
  }
  {  // sorted ordered-map golden
    OrderedStringMap map;
    CHECK(map.insert("b", "2") == CollectionError::ok);
    CHECK(map.insert("a", "1") == CollectionError::ok);
    CHECK(map.insert("é", "3") == CollectionError::ok);
    CHECK(map.insert("a", "dup") == CollectionError::duplicate_key);
    CHECK(map.size() == 3 && map.contains("a") && !map.contains("z"));
    const auto value = map.get("é");
    CHECK(std::holds_alternative<std::string>(value) && std::get<std::string>(value) == "3");
    CHECK(is_error(map.get("z"), CollectionError::out_of_range));
    const auto keys = map.keys();
    CHECK((keys == std::vector<std::string>{"a", "b", "é"}));
    const std::string golden =
        "1:a=1:1\n"
        "1:b=1:2\n"
        "2:é=1:3\n";
    CHECK(map.dump() == golden);
    const auto hash = map.hash();
    OrderedStringMap replay;
    CHECK(replay.insert("é", "3") == CollectionError::ok);
    CHECK(replay.insert("b", "2") == CollectionError::ok);
    CHECK(replay.insert("a", "1") == CollectionError::ok);
    CHECK(replay.dump() == golden && replay.hash() == hash);
    CHECK(map.remove("a") == CollectionError::ok);
    CHECK(map.remove("a") == CollectionError::out_of_range);
    CHECK(map.size() == 2);
    CHECK(name(CollectionError::duplicate_key) == "duplicate_key");
  }

  if (failures) { std::fprintf(stderr, "%d MUT-52 check(s) failed\n", failures); return 1; }
  std::puts("PASS: UTF-8 strings, bounded arrays, sorted ordered-map goldens");
  return 0;
}

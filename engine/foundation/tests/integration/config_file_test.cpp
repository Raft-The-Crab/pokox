// ENG-14: CBOR decoder + typed engine config loader. Writes real CBOR files
// to a temp dir; covers decoder edge cases and config accept/reject paths.
#include "poko/foundation/cbor.hpp"
#include "poko/foundation/config.hpp"

#include <cstdint>
#include <cstdio>
#include <cstring>
#include <filesystem>
#include <fstream>
#include <string>
#include <string_view>

namespace {
using poko::cbor::Error;
using poko::cbor::Type;
using poko::cbor::Value;

// --- Minimal CBOR encoder for test fixtures (canonical, definite-length). ---
void head(std::string& out, unsigned major, std::uint64_t arg) {
  if (arg < 24) out += static_cast<char>((major << 5) | arg);
  else if (arg <= 0xFF) { out += static_cast<char>((major << 5) | 24); out += static_cast<char>(arg); }
  else if (arg <= 0xFFFF) {
    out += static_cast<char>((major << 5) | 25);
    out += static_cast<char>(arg >> 8); out += static_cast<char>(arg);
  } else if (arg <= 0xFFFFFFFFULL) {
    out += static_cast<char>((major << 5) | 26);
    for (int s = 24; s >= 0; s -= 8) out += static_cast<char>(arg >> s);
  } else {
    out += static_cast<char>((major << 5) | 27);
    for (int s = 56; s >= 0; s -= 8) out += static_cast<char>(arg >> s);
  }
}
void put_u(std::string& out, std::uint64_t v) { head(out, 0, v); }
void put_n(std::string& out, std::int64_t v) { head(out, 1, static_cast<std::uint64_t>(-1 - v)); }
void put_t(std::string& out, std::string_view s) { head(out, 3, s.size()); out += s; }
void put_b(std::string& out, std::string_view s) { head(out, 2, s.size()); out += s; }
void put_bool(std::string& out, bool b) { out += static_cast<char>(b ? 0xF5 : 0xF4); }
void put_null(std::string& out) { out += static_cast<char>(0xF6); }
void put_arr(std::string& out, std::size_t n) { head(out, 4, n); }
void put_map(std::string& out, std::size_t n) { head(out, 5, n); }
void put_half(std::string& out, std::uint16_t h) {
  out += static_cast<char>(0xF9); out += static_cast<char>(h >> 8); out += static_cast<char>(h);
}
void put_float(std::string& out, float f) {
  out += static_cast<char>(0xFA);
  std::uint32_t b; std::memcpy(&b, &f, 4);
  for (int s = 24; s >= 0; s -= 8) out += static_cast<char>(b >> s);
}
void put_double(std::string& out, double d) {
  out += static_cast<char>(0xFB);
  std::uint64_t b; std::memcpy(&b, &d, 8);
  for (int s = 56; s >= 0; s -= 8) out += static_cast<char>(b >> s);
}
void put_kv(std::string& out, std::string_view k) { put_t(out, k); }
void write_file(const std::filesystem::path& p, const std::string& bytes) {
  std::ofstream f(p, std::ios::binary); f.write(bytes.data(), static_cast<std::streamsize>(bytes.size()));
}

int failures = 0;
#define CHECK(cond) do { if (!(cond)) { \
  std::fprintf(stderr, "FAIL line %d: %s\n", __LINE__, #cond); ++failures; \
} } while (0)

void test_decoder() {
  {  // unsigned ints across argument widths
    std::string cbor; put_u(cbor, 0); put_u(cbor, 23); put_u(cbor, 24);
    put_u(cbor, 1000); put_u(cbor, 0x100000000ULL);
    auto r = poko::cbor::decode(cbor);
    CHECK(r.error == Error::malformed);  // multiple top-level items rejected
  }
  {
    std::string cbor; put_u(cbor, 42);
    auto r = poko::cbor::decode(cbor);
    CHECK(r.error == Error::none && r.offset == 2 &&
          r.value.type == Type::uint && r.value.u == 42);
  }
  {
    std::string cbor; put_u(cbor, 0x100000000ULL);
    auto r = poko::cbor::decode(cbor);
    CHECK(r.error == Error::none && r.value.u == 0x100000000ULL);
  }
  {
    std::string cbor; put_n(cbor, -1000);
    auto r = poko::cbor::decode(cbor);
    CHECK(r.error == Error::none && r.value.type == Type::nint && r.value.i == -1000);
  }
  {
    std::string cbor; put_t(cbor, "h\xC3\xA9llo");  // "héllo" UTF-8
    auto r = poko::cbor::decode(cbor);
    CHECK(r.error == Error::none && r.value.type == Type::text &&
          r.value.string && *r.value.string == "h\xC3\xA9llo");
  }
  {
    std::string cbor; put_b(cbor, std::string_view("\x01\x02", 2));
    auto r = poko::cbor::decode(cbor);
    CHECK(r.error == Error::none && r.value.type == Type::bytes && r.value.string && r.value.string->size() == 2);
  }
  {
    std::string cbor; put_half(cbor, 0x3C00);  // 1.0
    auto r = poko::cbor::decode(cbor);
    CHECK(r.error == Error::none && r.value.type == Type::real && r.value.real == 1.0);
  }
  {
    std::string cbor; put_float(cbor, 1.5f);
    auto r = poko::cbor::decode(cbor);
    CHECK(r.error == Error::none && r.value.real == 1.5);
  }
  {
    std::string cbor; put_double(cbor, -2.25);
    auto r = poko::cbor::decode(cbor);
    CHECK(r.error == Error::none && r.value.real == -2.25);
  }
  {  // nested array/map
    std::string cbor;
    put_map(cbor, 2);
    put_kv(cbor, "a"); put_arr(cbor, 2); put_u(cbor, 1); put_t(cbor, "x");
    put_kv(cbor, "b"); put_map(cbor, 1); put_t(cbor, "k"); put_bool(cbor, false);
    auto r = poko::cbor::decode(cbor);
    CHECK(r.error == Error::none && r.value.type == Type::map && r.value.entries.size() == 2);
    CHECK(r.value.entries[0].second.type == Type::array &&
          r.value.entries[0].second.items.size() == 2);
    CHECK(r.value.entries[1].second.entries[0].second.type == Type::boolean &&
          !r.value.entries[1].second.entries[0].second.boolean);
  }
  // Failure modes.
  {
    std::string cbor("\x18", 1);  // u8 argument missing its payload byte
    CHECK(poko::cbor::decode(cbor).error == Error::truncated);
  }
  {
    std::string cbor; cbor += static_cast<char>(0x1C);  // reserved ai=28
    CHECK(poko::cbor::decode(cbor).error == Error::malformed);
  }
  {
    std::string cbor; cbor += static_cast<char>(0xC0);  // tag(0)
    CHECK(poko::cbor::decode(cbor).error == Error::unsupported);
  }
  {
    std::string cbor; put_t(cbor, std::string_view("\xFF", 1));  // invalid UTF-8
    CHECK(poko::cbor::decode(cbor).error == Error::invalid_utf8);
  }
  {
    std::string cbor; cbor += static_cast<char>(0x5F);  // indefinite array
    CHECK(poko::cbor::decode(cbor).error == Error::unsupported);
  }
  {
    std::string cbor; cbor += static_cast<char>(0xE0);  // undefined simple value
    CHECK(poko::cbor::decode(cbor).error == Error::unsupported);
  }
  {
    std::string cbor; put_u(cbor, 5); cbor += 'x';  // trailing byte
    CHECK(poko::cbor::decode(cbor).error == Error::malformed);
  }
  {  // depth cap: 40 nested arrays exceed the 32-level limit
    std::string cbor(40, static_cast<char>(0x81)); put_null(cbor);
    CHECK(poko::cbor::decode(cbor).error == Error::too_deep);
  }
  {  // empty input
    CHECK(poko::cbor::decode("").error == Error::truncated);
  }
}

void test_config() {
  namespace fs = std::filesystem;
  const auto dir = fs::temp_directory_path() / "poko_eng14_config";
  fs::create_directories(dir);

  // Full config: every section populated.
  {
    std::string cbor;
    put_map(cbor, 3);
    put_kv(cbor, "window");
    put_map(cbor, 2); put_kv(cbor, "width"); put_u(cbor, 1024); put_kv(cbor, "height"); put_u(cbor, 768);
    put_kv(cbor, "graphics");
    put_map(cbor, 2); put_kv(cbor, "adapter_id"); put_u(cbor, 1); put_kv(cbor, "validation"); put_bool(cbor, false);
    put_kv(cbor, "logging");
    put_map(cbor, 3); put_kv(cbor, "level"); put_t(cbor, "debug");
    put_kv(cbor, "file"); put_t(cbor, "engine.log"); put_kv(cbor, "echo"); put_bool(cbor, false);
    const auto path = dir / "full.cbor"; write_file(path, cbor);
    auto r = poko::config::load_file(path);
    CHECK(!r.error);
    CHECK(r.config.window_width == 1024 && r.config.window_height == 768);
    CHECK(r.config.adapter_id == 1 && !r.config.validation);
    CHECK(r.config.log_level == poko::log::Level::debug);
    CHECK(r.config.log_file == "engine.log" && !r.config.log_echo_to_console);
    CHECK(r.unknown_keys.empty());
  }
  // Partial config keeps defaults; unknown keys are reported, not fatal.
  {
    std::string cbor;
    put_map(cbor, 2);
    put_kv(cbor, "graphics"); put_map(cbor, 1); put_kv(cbor, "adapter_id"); put_u(cbor, 2);
    put_kv(cbor, "future_section"); put_map(cbor, 1); put_kv(cbor, "x"); put_u(cbor, 1);
    const auto path = dir / "partial.cbor"; write_file(path, cbor);
    auto r = poko::config::load_file(path);
    CHECK(!r.error);
    CHECK(r.config.adapter_id == 2);
    CHECK(r.config.window_width == 800 && r.config.validation);
    CHECK(r.config.log_level == poko::log::Level::info && r.config.log_file.empty());
    CHECK(r.unknown_keys.size() == 1 && r.unknown_keys[0] == "future_section");
  }
  // Wrong field type fails the whole load.
  {
    std::string cbor;
    put_map(cbor, 1); put_kv(cbor, "window"); put_map(cbor, 1);
    put_kv(cbor, "width"); put_t(cbor, "wide");
    const auto path = dir / "badtype.cbor"; write_file(path, cbor);
    auto r = poko::config::load_file(path);
    CHECK(r.error && r.detail.find("width") != std::string::npos);
  }
  // Zero window dimension rejected.
  {
    std::string cbor;
    put_map(cbor, 1); put_kv(cbor, "window"); put_map(cbor, 1);
    put_kv(cbor, "height"); put_u(cbor, 0);
    const auto path = dir / "zero.cbor"; write_file(path, cbor);
    CHECK(poko::config::load_file(path).error);
  }
  // Bad level name rejected.
  {
    std::string cbor;
    put_map(cbor, 1); put_kv(cbor, "logging"); put_map(cbor, 1);
    put_kv(cbor, "level"); put_t(cbor, "loud");
    const auto path = dir / "badlevel.cbor"; write_file(path, cbor);
    CHECK(poko::config::load_file(path).error);
  }
  // Non-map section rejected.
  {
    std::string cbor;
    put_map(cbor, 1); put_kv(cbor, "graphics"); put_u(cbor, 3);
    const auto path = dir / "badsection.cbor"; write_file(path, cbor);
    CHECK(poko::config::load_file(path).error);
  }
  // Non-map root and malformed CBOR rejected.
  {
    const auto path = dir / "arrayroot.cbor";
    write_file(path, "\x82\x01\x02");  // [1,2]
    CHECK(poko::config::load_file(path).error);
  }
  {
    const auto path = dir / "malformed.cbor"; write_file(path, "\x18");  // truncated u8
    CHECK(poko::config::load_file(path).error);
  }
  // Missing file is an I/O error, not a parse error.
  CHECK(poko::config::load_file(dir / "missing.cbor").error);
}

void test_resolve() {
  namespace fs = std::filesystem;
  const auto dir = fs::temp_directory_path() / "poko_eng14_config";

  // File supplies defaults; explicit CLI overrides win.
  {
    std::string cbor;
    put_map(cbor, 2);
    put_kv(cbor, "graphics"); put_map(cbor, 2);
    put_kv(cbor, "adapter_id"); put_u(cbor, 1); put_kv(cbor, "validation"); put_bool(cbor, false);
    put_kv(cbor, "window"); put_map(cbor, 1); put_kv(cbor, "width"); put_u(cbor, 320);
    const auto path = dir / "merge.cbor"; write_file(path, cbor);

    poko::config::Overrides ov;
    ov.validation = true; ov.validation_set = true;
    ov.adapter_id = 7; ov.adapter_set = true;
    auto r = poko::config::resolve(path, ov);
    CHECK(!r.error);
    CHECK(r.config.validation && r.config.adapter_id == 7);   // CLI wins
    CHECK(r.config.window_width == 320 && r.config.window_height == 600);

    auto plain = poko::config::resolve(path);
    CHECK(!plain.error && !plain.config.validation && plain.config.adapter_id == 1);
  }
  // Empty path keeps built-in defaults.
  {
    auto r = poko::config::resolve("");
    CHECK(!r.error);
    CHECK(r.config.window_width == 800 && r.config.validation &&
          r.config.adapter_id == 0xFFFFFFFFU);
  }
  // Load error propagates through resolve.
  CHECK(poko::config::resolve(dir / "missing.cbor").error);
}
}  // namespace

int main() {
  test_decoder();
  test_config();
  test_resolve();
  if (failures) { std::fprintf(stderr, "%d check(s) failed\n", failures); return 1; }
  std::puts("PASS: CBOR decoder + engine config loader (decoder edges + config accept/reject)");
  return 0;
}

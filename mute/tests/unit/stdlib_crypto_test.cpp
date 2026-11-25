// MUT-53: fixed SHA-256/HMAC/signature vectors and capability requirements.
#include "poko/mute/stdlib_crypto.hpp"

#include <algorithm>
#include <cstdio>
#include <string>
#include <string_view>

using namespace poko::mute;
namespace {
int failures = 0;
#define CHECK(cond) do { if (!(cond)) { \
  std::fprintf(stderr, "FAIL line %d: %s\n", __LINE__, #cond); ++failures; \
} } while (0)

Bytes bytes(std::string_view text) { return Bytes(text.begin(), text.end()); }
bool digest_is(std::span<const std::uint8_t> actual, std::string_view hex) {
  const auto expected = from_hex(hex);
  return expected && to_hex(actual) == hex && *expected == std::vector<std::uint8_t>(actual.begin(), actual.end());
}
}  // namespace

int main() {
  const auto empty = sha256(bytes(""));
  CHECK(digest_is(empty, "e3b0c44298fc1c149afbf4c8996fb92427ae41e4649b934ca495991b7852b855"));
  const auto abc = sha256(bytes("abc"));
  CHECK(digest_is(abc, "ba7816bf8f01cfea414140de5dae2223b00361a396177a9cb410ff61f20015ad"));
  CHECK(from_hex("0g") == std::nullopt);
  CHECK(from_hex("abc") == std::nullopt);

  const auto mac = hmac_sha256(bytes("key"), bytes("The quick brown fox jumps over the lazy dog"));
  CHECK(digest_is(mac, "f7bc83f430538424b13298e6aa6fb143ef4d59a14946175997479dbc2d1a3cd8"));
  const auto long_key = hmac_sha256(bytes(std::string(80, 'k')), bytes("message"));
  CHECK(long_key.size() == 32);

  const auto key = bytes("stable-v1-key");
  const auto message = bytes("state:12,actor:7");
  const auto signature = sign_detached(key, message);
  CHECK(verify_detached(key, message, signature));
  auto tampered = message;
  tampered[0] ^= 1;
  CHECK(!verify_detached(key, tampered, signature));
  auto bad_signature = signature;
  bad_signature[0] ^= 1;
  CHECK(!verify_detached(key, message, bad_signature));
  bad_signature.pop_back();
  CHECK(!verify_detached(key, message, bad_signature));

  const auto defs = crypto_hostcall_defs();
  CHECK(defs.size() == 4);
  HostcallTable table;
  for (const auto& def : defs) {
    CHECK(table.add(def) == HostcallTable::AddError::ok);
    CHECK(def.capabilities == capability_crypto && def.serializable);
  }
  const auto denied = unauthorized_hostcalls(table, 0);
  CHECK(denied.size() == 4);
  CHECK(unauthorized_hostcalls(table, capability_crypto).empty());

  if (failures) { std::fprintf(stderr, "%d MUT-53 check(s) failed\n", failures); return 1; }
  std::puts("PASS: sha256/hmac vectors, detached verify, crypto capability denial");
  return 0;
}

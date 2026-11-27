// NET-09 acceptance: "Two clients exchange encrypted frames". The RFC 8439
// test vectors pin the primitives (ChaCha20 block §2.3.2/§2.4.2, Poly1305
// §2.5.2, AEAD §2.8.2); the acceptance itself seals a NET-03 frame as AAD
// with a game payload, sends it from one client key/nonce to another, and
// the peer opens it back — tampered ciphertext, tag or AAD fails to open.
#include "poko/net/crypto_aead.hpp"
#include "poko/net/frame.hpp"

#include <cstring>
#include <iostream>
#include <vector>

using namespace poko::net;

namespace {
bool hex_eq(const std::uint8_t* got, const char* want, std::size_t n) {
  for (std::size_t i = 0; i < n; ++i) {
    int hi = want[2 * i] <= '9' ? want[2 * i] - '0' : want[2 * i] - 'a' + 10;
    int lo = want[2 * i + 1] <= '9' ? want[2 * i + 1] - '0' : want[2 * i + 1] - 'a' + 10;
    if (got[i] != std::uint8_t((hi << 4) | lo)) return false;
  }
  return true;
}
std::vector<std::uint8_t> hex(const char* h) {
  std::vector<std::uint8_t> out;
  for (const char* p = h; *p; p += 2)
    out.push_back(std::uint8_t((*p <= '9' ? *p - '0' : *p - 'a' + 10) * 16 +
                               (*(p + 1) <= '9' ? *(p + 1) - '0' : *(p + 1) - 'a' + 10)));
  return out;
}
} // namespace

int main() {
  int errors = 0;
  auto check = [&](bool ok, const char* what) {
    if (!ok) { ++errors; std::cerr << "FAIL: " << what << "\n"; }
  };

  // RFC 8439 §2.4.2: keystream XOR of the 114-byte string. This also pins
  // the ChaCha20 core (block generation, counter advance across blocks).
  {
    AeadKey key{};
    for (int i = 0; i < 32; ++i) key.bytes[i] = std::uint8_t(i);
    // RFC nonce 000000000000004a00000000, counter 1 → my split is
    // counter=1 and the 12-byte nonce 00 00 00 00 00 00 00 4a 00 00 00 00.
    AeadNonce nonce{};
    nonce.bytes[7] = 0x4a;
    const char* pt =
        "Ladies and Gentlemen of the class of '99: If I could offer you "
        "only one tip for the future, sunscreen would be it.";
    const char* want_ct =
        "6e2e359a2568f98041ba0728dd0d6981e97e7aec1d4360c20a27afccfd9fae0b"
        "f91b65c5524733ab8f593dabcd62b3571639d624e65152ab8f530c359f0861d8"
        "07ca0dbf500d6a6156a38e088a22b65e52bc514d16ccf806818ce91ab7793736"
        "5af90bbf74a35be6b40b8eedf2785e42874d";
    auto ct = std::vector<std::uint8_t>(std::strlen(pt));
    aead::chacha20_xor(key, 1, nonce, reinterpret_cast<const std::uint8_t*>(pt), ct.size(), ct.data());
    check(hex_eq(ct.data(), want_ct, ct.size()), "chacha20 encryption matches RFC 8439 2.4.2");
  }

  // RFC 8439 §2.5.2: Poly1305 MAC of the 33-byte string, keyed 85d6be…f51b.
  {
    std::array<std::uint8_t, 32> key = {};
    const auto k = hex("85d6be7857556d337f4452fe42d506a80103808afb0db2fd4abff6af4149f51b");
    std::memcpy(key.data(), k.data(), 32);
    const std::string msg = "Cryptographic Forum Research Group";
    auto mac = aead::poly1305_mac(reinterpret_cast<const std::uint8_t*>(msg.data()), msg.size(), key);
    check(hex_eq(mac.data(), "a8061dc1305136c6c22b8baf0c0127a9", 16),
          "poly1305 matches RFC 8439 2.5.2");
  }

  // RFC 8439 §2.8.2: full AEAD vector.
  {
    AeadKey key{std::array<std::uint8_t, 32>{0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87,
                                             0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f,
                                             0x90, 0x91, 0x92, 0x93, 0x94, 0x95, 0x96, 0x97,
                                             0x98, 0x99, 0x9a, 0x9b, 0x9c, 0x9d, 0x9e, 0x9f}};
    AeadNonce nonce{std::array<std::uint8_t, 12>{0x07, 0x00, 0x00, 0x00, 0x40, 0x41, 0x42,
                                                 0x43, 0x44, 0x45, 0x46, 0x47}};
    const char* pt =
        "Ladies and Gentlemen of the class of '99: If I could offer you "
        "only one tip for the future, sunscreen would be it.";
    const std::vector<std::uint8_t> aad = hex("50515253c0c1c2c3c4c5c6c7");
    auto sealed = aead_seal(key, nonce, aad,
                            std::vector<std::uint8_t>(reinterpret_cast<const std::uint8_t*>(pt),
                                                      reinterpret_cast<const std::uint8_t*>(pt) + std::strlen(pt)));
    check(sealed.size() == std::strlen(pt) + 16, "sealed output is ct + tag");
    check(hex_eq(sealed.data() + sealed.size() - 16, "1ae10b594f09e26a7e902ecbd0600691", 16),
          "AEAD tag matches RFC 8439 2.8.2");

    std::vector<std::uint8_t> opened;
    check(aead_open(key, nonce, aad, sealed.data(), sealed.size(), opened) &&
              std::memcmp(opened.data(), pt, std::strlen(pt)) == 0,
          "AEAD opens back to the plaintext");
  }

  // Acceptance: two clients exchange encrypted frames. Client A seals a real
  // NET-03 datagram (header as AAD, game payload encrypted); client B opens
  // it and verifies the frame. An attacker flipping one bit anywhere fails.
  {
    AeadKey key{std::array<std::uint8_t, 32>{0x01}};
    AeadNonce nonce{std::array<std::uint8_t, 12>{0x02}};
    const std::vector<std::uint8_t> mac_key(32, 0x01);

    FrameHeader header;
    header.session_id = 42;
    header.seq = 100;
    header.ack = 99;
    header.ack_bits = 0xffff;
    header.nonce = 7;
    const std::vector<std::uint8_t> game_payload = {0x10, 0x00, 0x01, 0x5F, 0x02, 0x00};
    auto datagram = pack_frame(header, game_payload, mac_key);
    // AAD is the fixed 25-byte header; the encrypted part is the payload.
    const std::vector<std::uint8_t> aad(datagram.begin(),
                                        datagram.begin() + static_cast<long>(kHeaderBytes));

    auto sealed = aead_seal(key, nonce, aad, game_payload);
    check(sealed.size() == game_payload.size() + kAeadTagBytes, "seal adds only the tag");

    std::vector<std::uint8_t> opened;
    check(aead_open(key, nonce, aad, sealed.data(), sealed.size(), opened) && opened == game_payload,
          "peer client opens the encrypted frame to the same game payload");

    // Same key with a different nonce fails: the handshake keys the session.
    AeadNonce other{std::array<std::uint8_t, 12>{0x03}};
    check(!aead_open(key, other, aad, sealed.data(), sealed.size(), opened),
          "wrong nonce fails to open");

    // Wrong key fails: two sessions cannot read each other.
    AeadKey wrong{std::array<std::uint8_t, 32>{0x09}};
    check(!aead_open(wrong, nonce, aad, sealed.data(), sealed.size(), opened),
          "wrong key fails to open");

    // Tampered ciphertext fails.
    auto tampered = sealed;
    tampered[0] ^= 1;
    check(!aead_open(key, nonce, aad, tampered.data(), tampered.size(), opened),
          "flipped ciphertext bit fails to open");

    // Tampered tag fails.
    tampered = sealed;
    tampered.back() ^= 1;
    check(!aead_open(key, nonce, aad, tampered.data(), tampered.size(), opened),
          "flipped tag bit fails to open");

    // Tampered AAD (header) fails: the header is authenticated.
    auto bad_aad = aad;
    bad_aad[1] ^= 1;
    check(!aead_open(key, nonce, bad_aad, sealed.data(), sealed.size(), opened),
          "flipped header bit fails to open");

    // Sealed output does not leak the plaintext.
    bool leaked = std::memcmp(sealed.data(), game_payload.data(), game_payload.size()) == 0;
    check(!leaked, "sealed frame does not contain the plaintext");
  }

  if (errors) { std::cerr << errors << " failure(s)\n"; return 1; }
  std::cout << "crypto aead tests passed\n";
  return 0;
}

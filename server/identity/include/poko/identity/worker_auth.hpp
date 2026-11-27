// BAK-03: Firebase token verification at the Worker, and the Worker session
// ticket (spec 17 chain: Firebase token -> PokoX account -> device binding ->
// session ticket -> game nonce).
//
// Two pieces, both deterministic on caller-supplied time (no wall clock, like
// the rest of the platform):
//
// 1. FirebaseTokenVerifier verifies a Firebase ID token (compact JWS): the
//    header must be RS256 with a kid, the claims must match the Firebase
//    project (iss `https://securetoken.google.com/<project>`, aud == project,
//    non-empty sub), the token must not be expired, and the RS256 signature
//    over the signing input must verify. The RSA-2048 verify itself is the
//    edge runtime's job (Web Crypto in the Worker); the in-repo logic takes
//    it as an injected callable so every claim and signature rejection path
//    is testable here. A game slot never sees a Firebase token directly — it
//    sees the session ticket below.
//
// 2. SessionTickets issues and verifies the 30-minute Worker session ticket
//    carrying userId, deviceId, trustLevel and roles ("Worker session ticket
//    30 min, HMAC key rotates 5 min from the ticket", spec 17). HMAC-SHA256
//    (NET-03 primitive) over a canonical byte form; the signing key rotates
//    every 5 minutes and verification accepts any key still inside the
//    ticket's 30-minute life, so a ticket outlives exactly the keys that
//    were current when it was issued and nothing older.
#pragma once

#include "poko/identity/account_record.hpp" // TrustLevel, Role
#include "poko/net/frame.hpp"               // hmac_sha256 (NET-03)

#include <cstdint>
#include <functional>
#include <optional>
#include <string>
#include <string_view>
#include <vector>

namespace poko::identity {

// ---------------------------------------------------------------------------
// base64url (RFC 4648 §5, unpadded) — JWT parts and nothing else.
// ---------------------------------------------------------------------------
[[nodiscard]] inline bool base64url_decode(std::string_view in, std::vector<std::uint8_t>& out) {
  out.clear();
  out.reserve(in.size() / 4 * 3 + 3);
  std::uint32_t acc = 0;
  int bits = 0;
  for (char c : in) {
    std::uint32_t v;
    if (c >= 'A' && c <= 'Z') v = std::uint32_t(c - 'A');
    else if (c >= 'a' && c <= 'z') v = std::uint32_t(c - 'a') + 26;
    else if (c >= '0' && c <= '9') v = std::uint32_t(c - '0') + 52;
    else if (c == '-') v = 62;
    else if (c == '_') v = 63;
    else return false; // '=', padding and any other character are rejected
    acc = (acc << 6) | v;
    bits += 6;
    if (bits >= 8) {
      bits -= 8;
      out.push_back(std::uint8_t((acc >> bits) & 0xff));
    }
  }
  return true; // leftover bits < 8 are the canonical unpadded tail
}

[[nodiscard]] inline std::string base64url_encode(std::string_view in) {
  static const char* kAlpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789-_";
  std::string out;
  out.reserve((in.size() + 2) / 3 * 4);
  std::uint32_t acc = 0;
  int bits = 0;
  for (char c : in) {
    acc = (acc << 8) | std::uint8_t(c);
    bits += 8;
    while (bits >= 6) {
      bits -= 6;
      out.push_back(kAlpha[(acc >> bits) & 0x3f]);
    }
  }
  if (bits > 0) out.push_back(kAlpha[(acc << (6 - bits)) & 0x3f]);
  return out; // unpadded
}

// ---------------------------------------------------------------------------
// Firebase ID token verification
// ---------------------------------------------------------------------------
struct VerifiedFirebaseToken {
  std::string uid;             // the `sub` claim, Firebase Auth UID
  std::string email;           // "" when the account has none
  std::string display_name;    // the `name` claim, "" when absent
  std::int64_t expires_at = 0; // exp claim, unix seconds
};

struct FirebaseTokenError {
  enum class Code : std::uint8_t {
    malformed,      // not exactly three dot-separated base64url parts
    bad_header,     // header is not alg RS256 with a kid
    bad_signature,  // RSA verify failed over the signing input
    wrong_issuer,   // iss != https://securetoken.google.com/<project>
    wrong_audience, // aud != project id
    empty_subject,  // sub missing or empty
    expired,        // exp <= now (caller-supplied)
    not_yet_valid,  // iat > now (caller-supplied)
  };
  Code code = Code::malformed;
};

class FirebaseTokenVerifier {
public:
  // RS256 verify over the signing input (header.payload); returns false on
  // any failure. The edge runtime supplies the real one against Firebase's
  // fetched public keys for the header's kid.
  using RsaVerify = std::function<bool(std::string_view signing_input, const std::vector<std::uint8_t>& signature)>;

  explicit FirebaseTokenVerifier(std::string project_id, RsaVerify rsa_verify)
      : project_id_(std::move(project_id)), rsa_verify_(std::move(rsa_verify)) {}

  struct Result {
    std::optional<VerifiedFirebaseToken> token;
    FirebaseTokenError::Code error = FirebaseTokenError::Code::malformed; // valid only if !token
  };

  [[nodiscard]] Result verify(std::string_view token, std::int64_t now) const {
    // Compact JWS: header.payload.signature, base64url, no padding.
    const std::size_t h1 = token.find('.');
    if (h1 == std::string_view::npos) return {std::nullopt, FirebaseTokenError::Code::malformed};
    const std::size_t h2 = token.find('.', h1 + 1);
    if (h2 == std::string_view::npos) return {std::nullopt, FirebaseTokenError::Code::malformed};
    if (token.find('.', h2 + 1) != std::string_view::npos) return {std::nullopt, FirebaseTokenError::Code::malformed};
    const std::string_view header_s = token.substr(0, h1);
    const std::string_view payload_s = token.substr(h1 + 1, h2 - h1 - 1);
    const std::string_view sig_s = token.substr(h2 + 1);
    if (header_s.empty() || payload_s.empty() || sig_s.empty()) return {std::nullopt, FirebaseTokenError::Code::malformed};

    // Header: alg must be RS256 (never "none", never HS256) and a kid must
    // name the signing key.
    std::vector<std::uint8_t> header_json;
    if (!base64url_decode(header_s, header_json)) return {std::nullopt, FirebaseTokenError::Code::malformed};
    const std::string header(header_json.begin(), header_json.end());
    if (header.find("\"alg\":\"RS256\"") == std::string::npos) return {std::nullopt, FirebaseTokenError::Code::bad_header};
    if (header.find("\"kid\":\"") == std::string::npos) return {std::nullopt, FirebaseTokenError::Code::bad_header};

    // Signature over the exact signing input, before any claim is trusted.
    std::vector<std::uint8_t> signature;
    if (!base64url_decode(sig_s, signature)) return {std::nullopt, FirebaseTokenError::Code::malformed};
    if (!rsa_verify_(token.substr(0, h2), signature)) return {std::nullopt, FirebaseTokenError::Code::bad_signature};

    // Claims, only after the signature holds.
    std::vector<std::uint8_t> payload_json;
    if (!base64url_decode(payload_s, payload_json)) return {std::nullopt, FirebaseTokenError::Code::malformed};
    const std::string claims(payload_json.begin(), payload_json.end());
    const std::string want_iss = "https://securetoken.google.com/" + project_id_;
    if (claims.find("\"iss\":\"" + want_iss + "\"") == std::string::npos)
      return {std::nullopt, FirebaseTokenError::Code::wrong_issuer};
    if (claims.find("\"aud\":\"" + project_id_ + "\"") == std::string::npos)
      return {std::nullopt, FirebaseTokenError::Code::wrong_audience};

    const std::optional<std::int64_t> exp = int_claim(claims, "exp");
    const std::optional<std::int64_t> iat = int_claim(claims, "iat");
    if (!exp || *exp <= now) return {std::nullopt, FirebaseTokenError::Code::expired};
    if (iat && *iat > now) return {std::nullopt, FirebaseTokenError::Code::not_yet_valid};

    const std::size_t sub = claims.find("\"sub\":\"");
    if (sub == std::string::npos) return {std::nullopt, FirebaseTokenError::Code::empty_subject};
    VerifiedFirebaseToken out;
    out.uid = json_string_at(claims, sub + 7);
    if (out.uid.empty()) return {std::nullopt, FirebaseTokenError::Code::empty_subject};
    out.expires_at = *exp;
    out.email = string_claim(claims, "email");
    out.display_name = string_claim(claims, "name");
    return {out, FirebaseTokenError::Code::malformed};
  }

private:
  // Minimal claim readers over Firebase's own JSON output (compact, sorted,
  // no escapes in these ASCII claim names). The strict iss/aud forms above
  // are exact matches; these tolerant readers only ever run on
  // signature-verified payloads.
  [[nodiscard]] static std::string json_string_at(const std::string& claims, std::size_t pos) {
    const std::size_t end = claims.find('"', pos);
    if (end == std::string::npos) return {};
    return claims.substr(pos, end - pos);
  }
  [[nodiscard]] static std::string string_claim(const std::string& claims, const std::string& name) {
    const std::size_t p = claims.find("\"" + name + "\":\"");
    if (p == std::string::npos) return {};
    return json_string_at(claims, p + name.size() + 4);
  }
  [[nodiscard]] static std::optional<std::int64_t> int_claim(const std::string& claims, const std::string& name) {
    const std::size_t p = claims.find("\"" + name + "\":");
    if (p == std::string::npos) return std::nullopt;
    std::size_t d = p + name.size() + 3;
    std::int64_t v = 0;
    bool any = false;
    while (d < claims.size() && claims[d] >= '0' && claims[d] <= '9') {
      v = v * 10 + (claims[d] - '0');
      ++d;
      any = true;
    }
    if (!any) return std::nullopt;
    return v;
  }

  std::string project_id_;
  RsaVerify rsa_verify_;
};

// ---------------------------------------------------------------------------
// Worker session ticket (30 min, HMAC key rotation every 5 min)
// ---------------------------------------------------------------------------
struct SessionTicket {
  std::string user_id;   // PokoX user id, immutable (IDN-01)
  std::string device_id; // bound device fingerprint (IDN-02), "" if none
  TrustLevel trust_level = TrustLevel::kBasic;
  std::vector<Role> roles;
  std::int64_t issued_at = 0;  // caller-supplied, unix seconds
  std::int64_t expires_at = 0; // issued_at + 30 min
  std::uint64_t nonce = 0;     // issuer-supplied uniqueness
};

struct TicketError {
  enum class Code : std::uint8_t {
    malformed,     // not two dot-separated base64url parts
    bad_signature, // no key still inside the ticket's life signs it
    expired,       // a key verified but exp <= now
  };
  Code code = Code::malformed;
};

class SessionTickets {
public:
  static constexpr std::int64_t kTicketLifeSeconds = 30 * 60;
  static constexpr std::int64_t kKeyRotationSeconds = 5 * 60;
  // Keys live kTicketLifeSeconds past their rotation: a ticket signed at the
  // end of key k's slot must still verify 30 minutes later. A verification
  // therefore accepts the kCurrent+1 .. kCurrent+6 key slots and nothing
  // older, which also bounds replay of stolen old keys.
  static constexpr int kKeySlots = int(kTicketLifeSeconds / kKeyRotationSeconds); // 6

  // key_provider maps a key-slot index (0..) to its secret; the Worker's
  // key service supplies the real rotation from its KMS.
  using KeyProvider = std::function<std::vector<std::uint8_t>(int slot)>;

  SessionTickets(std::int64_t epoch_second, KeyProvider key_provider)
      : epoch_(epoch_second), keys_(std::move(key_provider)) {}

  // Current key slot for a caller-supplied time.
  [[nodiscard]] int slot_for(std::int64_t now) const {
    return int((now - epoch_) / kKeyRotationSeconds);
  }

  [[nodiscard]] std::string issue(const SessionTicket& t) const {
    std::vector<std::uint8_t> body = pack(t);
    const std::string body_s(body.begin(), body.end());
    const std::vector<std::uint8_t> mac = net::hmac_sha256(keys_(slot_for(t.issued_at)),
                                                           body.data(), body.size());
    return base64url_encode(body_s) + "." + base64url_encode(std::string(mac.begin(), mac.end()));
  }

  struct VerifyResult {
    std::optional<SessionTicket> ticket;
    TicketError::Code error = TicketError::Code::malformed; // valid only if !ticket
  };

  // Verifies with every key slot that was current within the ticket's
  // 30-minute life (the issuing slot and up to kKeySlots-1 newer ones), then
  // checks the ticket's own expiry against the caller's now.
  [[nodiscard]] VerifyResult verify(std::string_view token, std::int64_t now) const {
    const std::size_t dot = token.find('.');
    if (dot == std::string_view::npos) return {std::nullopt, TicketError::Code::malformed};
    if (token.find('.', dot + 1) != std::string_view::npos) return {std::nullopt, TicketError::Code::malformed};
    std::vector<std::uint8_t> body, mac;
    if (!base64url_decode(token.substr(0, dot), body) || body.empty()) return {std::nullopt, TicketError::Code::malformed};
    if (!base64url_decode(token.substr(dot + 1), mac) || mac.empty()) return {std::nullopt, TicketError::Code::malformed};

    const SessionTicket t = unpack(body);
    const int issue_slot = slot_for(t.issued_at);
    bool sig_ok = false;
    for (int k = 0; k < kKeySlots; ++k) { // issuing slot .. issuing slot + 5
      const std::vector<std::uint8_t> key = keys_(issue_slot + k);
      if (key.empty()) break; // no key material that new: stop, do not accept
      const std::vector<std::uint8_t> want = net::hmac_sha256(key, body.data(), body.size());
      bool equal = mac.size() == want.size();
      for (std::size_t i = 0; equal && i < want.size(); ++i) equal = mac[i] == want[i]; // branchless-enough for tickets
      if (equal) {
        sig_ok = true;
        break;
      }
    }
    if (!sig_ok) return {std::nullopt, TicketError::Code::bad_signature};
    if (t.expires_at <= now) return {std::nullopt, TicketError::Code::expired};
    return {t, TicketError::Code::malformed};
  }

private:
  // Canonical byte form: lengths prefixed so fields can never run together,
  // all integers little-endian, roles as count + name each.
  [[nodiscard]] static std::vector<std::uint8_t> pack(const SessionTicket& t) {
    std::vector<std::uint8_t> out;
    auto put_u64 = [&out](std::uint64_t v) {
      for (int i = 0; i < 8; ++i) out.push_back(std::uint8_t((v >> (8 * i)) & 0xff));
    };
    auto put_str = [&](const std::string& s) {
      put_u64(s.size());
      out.insert(out.end(), s.begin(), s.end());
    };
    put_str(t.user_id);
    put_str(t.device_id);
    put_u64(std::uint64_t(t.trust_level));
    put_u64(t.roles.size());
    for (const Role& r : t.roles) put_str(r.name);
    put_u64(std::uint64_t(t.issued_at));
    put_u64(std::uint64_t(t.expires_at));
    put_u64(t.nonce);
    return out;
  }

  [[nodiscard]] static SessionTicket unpack(const std::vector<std::uint8_t>& b) {
    std::size_t off = 0;
    auto get_u64 = [&]() -> std::uint64_t {
      std::uint64_t v = 0;
      for (int i = 0; i < 8 && off < b.size(); ++i) v |= std::uint64_t(b[off++]) << (8 * i);
      return v;
    };
    auto get_str = [&]() -> std::string {
      const std::uint64_t n = get_u64();
      // Length-prefixed reads are bounded: any count that would run past the
      // body (including a u64 wrap of off + n) consumes the rest as zeros.
      if (off >= b.size() || n > std::uint64_t(b.size() - off)) {
        off = b.size();
        return {};
      }
      std::string s(b.begin() + int(off), b.begin() + int(off + n));
      off += n;
      return s;
    };
    SessionTicket t;
    t.user_id = get_str();
    t.device_id = get_str();
    t.trust_level = TrustLevel(get_u64());
    const std::uint64_t role_count = get_u64();
    // A claimed role count that could not fit in the body is hostile: keep
    // the reserve bounded instead of trying to allocate 2^64 entries.
    const std::uint64_t max_roles = role_count > b.size() ? 0 : role_count;
    t.roles.reserve(max_roles);
    for (std::uint64_t i = 0; i < max_roles; ++i) t.roles.push_back({get_str()});
    t.issued_at = std::int64_t(get_u64());
    t.expires_at = std::int64_t(get_u64());
    t.nonce = get_u64();
    return t;
  }

  std::int64_t epoch_ = 0;
  KeyProvider keys_;
};

} // namespace poko::identity

// BAK-03 acceptance: a valid Firebase ID token with the right project claims
// verifies, a wrong-project or expired token does not, and only a valid
// signature earns claim reading. The session ticket round-trips, a tampered
// body is refused, and a ticket signed in one 5-minute key slot still
// verifies 25 minutes later on a newer key — but not past its 30 minutes or
// from a key older than the life window.
#include "poko/identity/worker_auth.hpp"

#include <iostream>
#include <string>

using namespace poko::identity;

namespace {

int errors = 0;
void check(bool ok, const char* what) {
  if (!ok) { ++errors; std::cerr << "FAIL: " << what << "\n"; }
}

// RS256 stand-in: deterministic, injectable — "signs" with an HMAC-derived
// prefix so any body or signature tamper fails verification.
std::string g_signing_secret = "test-issuer-key";
bool fake_rsa_verify(std::string_view signing_input, const std::vector<std::uint8_t>& signature) {
  const auto mac = poko::net::hmac_sha256(std::vector<std::uint8_t>(g_signing_secret.begin(), g_signing_secret.end()),
                               reinterpret_cast<const std::uint8_t*>(signing_input.data()), signing_input.size());
  if (signature.size() != mac.size()) return false;
  for (std::size_t i = 0; i < mac.size(); ++i)
    if (signature[i] != mac[i]) return false;
  return true;
}

std::vector<std::uint8_t> sign_input(std::string_view signing_input) {
  return poko::net::hmac_sha256(std::vector<std::uint8_t>(g_signing_secret.begin(), g_signing_secret.end()),
                     reinterpret_cast<const std::uint8_t*>(signing_input.data()), signing_input.size());
}

std::string make_token(const std::string& header, const std::string& payload) {
  const std::string head = base64url_encode(header);
  const std::string body = base64url_encode(payload);
  const std::string sig = [&] {
    const auto mac = sign_input(head + "." + body);
    return base64url_encode(std::string(mac.begin(), mac.end()));
  }();
  return head + "." + body + "." + sig;
}

// Key service stand-in: slot -> deterministic 32-byte secret.
std::vector<std::uint8_t> test_key(int slot) {
  const std::string name = "key-slot-" + std::to_string(slot);
  return poko::net::hmac_sha256(std::vector<std::uint8_t>(name.begin(), name.end()),
                     reinterpret_cast<const std::uint8_t*>("session-ticket"), 14);
}

constexpr std::int64_t kEpoch = 1'700'000'000; // key-slot 0
constexpr std::int64_t kNow = kEpoch + 100;    // inside slot 0

SessionTicket sample_ticket() {
  SessionTicket t;
  t.user_id = "pokox-user-1";
  t.device_id = "dev-fp-9";
  t.trust_level = TrustLevel::kDevice;
  t.roles = {{"player"}, {"builder"}};
  t.issued_at = kNow;
  t.expires_at = kNow + SessionTickets::kTicketLifeSeconds;
  t.nonce = 42;
  return t;
}

} // namespace

int main() {
  // --- Firebase token verification ---------------------------------------
  FirebaseTokenVerifier verifier("poko-bakery", fake_rsa_verify);
  const std::string ok_header = "{\"alg\":\"RS256\",\"kid\":\"key-1\"}";
  const std::string ok_payload =
      "{\"iss\":\"https://securetoken.google.com/poko-bakery\",\"aud\":\"poko-bakery\","
      "\"sub\":\"fb-uid-77\",\"email\":\"p@x.io\",\"name\":\"Poko\","
      "\"iat\":" + std::to_string(kNow - 60) + ",\"exp\":" + std::to_string(kNow + 3600) + "}";

  const auto good = verifier.verify(make_token(ok_header, ok_payload), kNow);
  check(good.token.has_value(), "valid token verifies");
  check(good.token && good.token->uid == "fb-uid-77", "uid from sub");
  check(good.token && good.token->email == "p@x.io", "email claim read");
  check(good.token && good.token->display_name == "Poko", "name claim read");

  check(!verifier.verify("not-a-jwt", kNow).token, "malformed token refused");
  check(verifier.verify(".b.c", kNow).error == FirebaseTokenError::Code::malformed,
        "empty parts refused as malformed");

  const auto hs256 = verifier.verify(make_token("{\"alg\":\"HS256\",\"kid\":\"k\"}", ok_payload), kNow);
  check(!hs256.token && hs256.error == FirebaseTokenError::Code::bad_header, "alg != RS256 refused as bad_header");
  const auto nokid = verifier.verify(make_token("{\"alg\":\"RS256\"}", ok_payload), kNow);
  check(!nokid.token && nokid.error == FirebaseTokenError::Code::bad_header, "missing kid refused as bad_header");

  // Right structure, wrong signer: sign with a different secret, verify
  // against the trusted one.
  const auto forged_token = [&] {
    const std::string head = base64url_encode(ok_header);
    const std::string body = base64url_encode(ok_payload);
    const std::string attacker = "attacker-key";
    const auto mac = poko::net::hmac_sha256(std::vector<std::uint8_t>(attacker.begin(), attacker.end()),
                                 reinterpret_cast<const std::uint8_t*>((head + "." + body).data()),
                                 (head + "." + body).size());
    return head + "." + body + "." + base64url_encode(std::string(mac.begin(), mac.end()));
  }();
  const auto forged = verifier.verify(forged_token, kNow);
  check(!forged.token && forged.error == FirebaseTokenError::Code::bad_signature,
        "signature from another key refused before claims are read");

  const std::string iss_ok_aud_bad =
      "{\"iss\":\"https://securetoken.google.com/poko-bakery\",\"aud\":\"other-game\","
      "\"sub\":\"fb-uid-77\",\"exp\":" + std::to_string(kNow + 3600) + "}";
  const auto aud = verifier.verify(make_token(ok_header, iss_ok_aud_bad), kNow);
  check(!aud.token && aud.error == FirebaseTokenError::Code::wrong_audience, "wrong audience refused");

  const std::string iss_bad =
      "{\"iss\":\"https://securetoken.google.com/other-game\",\"aud\":\"poko-bakery\","
      "\"sub\":\"fb-uid-77\",\"exp\":" + std::to_string(kNow + 3600) + "}";
  const auto iss = verifier.verify(make_token(ok_header, iss_bad), kNow);
  check(!iss.token && iss.error == FirebaseTokenError::Code::wrong_issuer, "wrong issuer refused");

  const std::string no_sub =
      "{\"iss\":\"https://securetoken.google.com/poko-bakery\",\"aud\":\"poko-bakery\","
      "\"exp\":" + std::to_string(kNow + 3600) + "}";
  const auto sub = verifier.verify(make_token(ok_header, no_sub), kNow);
  check(!sub.token && sub.error == FirebaseTokenError::Code::empty_subject, "missing sub refused");

  const std::string expired =
      "{\"iss\":\"https://securetoken.google.com/poko-bakery\",\"aud\":\"poko-bakery\","
      "\"sub\":\"fb-uid-77\",\"exp\":" + std::to_string(kNow - 1) + "}";
  const auto exp = verifier.verify(make_token(ok_header, expired), kNow);
  check(!exp.token && exp.error == FirebaseTokenError::Code::expired, "expired token refused");

  const std::string future_iat =
      "{\"iss\":\"https://securetoken.google.com/poko-bakery\",\"aud\":\"poko-bakery\","
      "\"sub\":\"fb-uid-77\",\"iat\":" + std::to_string(kNow + 10) + ",\"exp\":" + std::to_string(kNow + 3600) + "}";
  const auto iat = verifier.verify(make_token(ok_header, future_iat), kNow);
  check(!iat.token && iat.error == FirebaseTokenError::Code::not_yet_valid, "iat in the future refused");

  // --- Session tickets ----------------------------------------------------
  SessionTickets tickets(kEpoch, test_key);
  check(tickets.slot_for(kNow) == 0, "slot 0 at epoch+100");
  check(tickets.slot_for(kEpoch + 299) == 0, "slot 0 at epoch+299");
  check(tickets.slot_for(kEpoch + 300) == 1, "slot 1 at epoch+300 (5-minute rotation)");

  const std::string tok = tickets.issue(sample_ticket());
  const auto verified = tickets.verify(tok, kNow + 60);
  check(verified.ticket.has_value(), "ticket verifies inside its life");
  check(verified.ticket && verified.ticket->user_id == "pokox-user-1", "user id round-trips");
  check(verified.ticket && verified.ticket->device_id == "dev-fp-9", "device id round-trips");
  check(verified.ticket && verified.ticket->trust_level == TrustLevel::kDevice, "trust level round-trips");
  check(verified.ticket && verified.ticket->roles.size() == 2 &&
            verified.ticket->roles[1].name == "builder", "roles round-trip");
  check(verified.ticket && verified.ticket->nonce == 42, "nonce round-trips");

  // Still valid 25 minutes in: three key slots after the issuing one.
  check(verified.ticket && tickets.verify(tok, kNow).ticket.has_value(),
        "ticket survives key rotation within its 30 minutes");

  const auto expired_result = tickets.verify(tok, kNow + SessionTickets::kTicketLifeSeconds + 1);
  check(!expired_result.ticket && expired_result.error == TicketError::Code::expired, "ticket refused past 30 minutes");

  // Tampered body: the HMAC no longer matches any live key.
  const std::size_t dot = tok.find('.');
  std::string body = tok.substr(0, dot);
  std::string tampered = body;
  tampered[tampered.size() - 2] = tampered[tampered.size() - 2] == 'A' ? 'B' : 'A';
  check(tampered != body, "tamper actually changed the body");
  const auto bad = tickets.verify(tampered + tok.substr(dot), kNow + 60);
  check(!bad.ticket && bad.error == TicketError::Code::bad_signature, "tampered body refused");

  // Hostile bodies must be refused on signature grounds without crashing or
  // allocating: a body claiming 2^63 roles, and one with a length prefix
  // that overflows the body, both end in bad_signature (unpack stays in
  // bounds before any trust decision).
  {
    const std::string evil_roles = [&] {
      SessionTicket evil = sample_ticket();
      (void)evil;
      std::vector<std::uint8_t> packed;
      auto put_u64 = [&packed](std::uint64_t v) {
        for (int i = 0; i < 8; ++i) packed.push_back(std::uint8_t((v >> (8 * i)) & 0xff));
      };
      auto put_str = [&](const std::string& s) {
        put_u64(s.size());
        packed.insert(packed.end(), s.begin(), s.end());
      };
      put_str("pokox-user-1");
      put_str("dev-fp-9");
      put_u64(std::uint64_t(TrustLevel::kDevice));
      put_u64(std::uint64_t(1) << 62); // absurd role count
      const std::string body_s(packed.begin(), packed.end());
      const auto mac = poko::net::hmac_sha256(test_key(0), packed.data(), packed.size());
      return base64url_encode(body_s) + "." + base64url_encode(std::string(mac.begin(), mac.end()));
    }();
    check(!tickets.verify(evil_roles, kNow + 60).ticket,
          "role count of 2^62 refused without allocation blowup");
    check(!tickets.verify("..", kNow + 60).ticket, "empty body and mac refused");
  }

  // A ticket verified against a verifier whose key timeline shifted forward
  // (every slot's secret moved): no live key produces that MAC.
  SessionTickets shifted_tickets(kEpoch, [](int slot) { return test_key(slot + 50); });
  check(!shifted_tickets.verify(tok, kNow).ticket, "ticket refused when no live key signs it");

  if (errors) { std::cerr << errors << " failure(s)\n"; return 1; }
  std::cout << "worker auth tests passed\n";
  return 0;
}

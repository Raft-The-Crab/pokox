// IDN-04: login velocity and impossible travel. Account hardening per spec
// 17: 5 login failures per hour per IP and per device; impossible travel
// (geo distance too large for the elapsed time) plus a new device forces
// OTP step-up before the action runs. Deterministic and wall-clock-free:
// the caller supplies the timestamp so checks are replayable, like the rest
// of the platform.
#ifndef POKO_IDENTITY_VELOCITY_HPP
#define POKO_IDENTITY_VELOCITY_HPP

#include "poko/identity/step_up.hpp"

#include <cmath>
#include <cstdint>
#include <deque>
#include <map>
#include <mutex>
#include <set>
#include <string>
#include <utility>

namespace poko::identity {

inline constexpr int kMaxLoginFailuresPerHour = 5;
// Speed in km/h above which travel between two sign-in points is impossible
// for commercial movement (the spec's "impossible travel" heuristic).
inline constexpr double kImpossibleTravelKmh = 900.0;

struct GeoPoint {
  double latitude_deg;
  double longitude_deg;
};

// Haversine distance in km between two points.
inline double haversine_km(const GeoPoint& a, const GeoPoint& b) {
  constexpr double kEarthRadiusKm = 6371.0;
  constexpr double kDegToRad = 3.14159265358979323846 / 180.0;
  double dlat = (b.latitude_deg - a.latitude_deg) * kDegToRad;
  double dlon = (b.longitude_deg - a.longitude_deg) * kDegToRad;
  double sin_lat2 = std::sin(dlat / 2);
  double sin_lon2 = std::sin(dlon / 2);
  double h = sin_lat2 * sin_lat2 +
             std::cos(a.latitude_deg * kDegToRad) * std::cos(b.latitude_deg * kDegToRad) * sin_lon2 * sin_lon2;
  return 2 * kEarthRadiusKm * std::asin(std::sqrt(h));
}

struct LoginAttempt {
  std::string user_id;
  std::string ip;
  std::string device_fingerprint;
  bool failed = false;
  GeoPoint location{0.0, 0.0};
  // Caller clock in seconds (Unix time on the Worker); never wall-clock here.
  std::int64_t at_seconds = 0;
};

// Verdict for one sign-in attempt against the hardening rules.
struct LoginVerdict {
  bool allowed = true;           // false when velocity blocks the attempt
  bool step_up_required = false; // impossible travel onto a new device
  std::string reason;
};

class LoginVelocityService {
public:
  LoginVelocityService(AccountStore& store, DeviceBindingService& binding)
      : store_(store), binding_(binding) {}

  // Records an attempt (success or failure) and returns the verdict. A
  // blocked attempt (the 6th failure within the hour for the same IP or
  // device) is refused before credential checking and is not re-counted.
  LoginVerdict record(const LoginAttempt& attempt) {
    std::lock_guard<std::mutex> lock(mutex_);
    LoginVerdict verdict;

    if (count_recent_failures_locked("ip:" + attempt.ip, attempt.at_seconds) >= kMaxLoginFailuresPerHour ||
        count_recent_failures_locked("dev:" + attempt.device_fingerprint, attempt.at_seconds) >= kMaxLoginFailuresPerHour) {
      verdict.allowed = false;
      verdict.reason = "login velocity limit reached (5 failures/hour)";
      return verdict;
    }

    if (attempt.failed) {
      failures_[attempt.ip].push_back(attempt.at_seconds);
      failures_["dev:" + attempt.device_fingerprint].push_back(attempt.at_seconds);
      return verdict;
    }

    // Successful sign-in: check impossible travel against the last location.
    auto loc_it = last_location_.find(attempt.user_id);
    if (loc_it != last_location_.end()) {
      double km = haversine_km(loc_it->second.first, attempt.location);
      double hours = static_cast<double>(attempt.at_seconds - loc_it->second.second) / 3600.0;
      bool impossible = hours > 0.0 && (km / hours) > kImpossibleTravelKmh;
      last_location_[attempt.user_id] = {attempt.location, attempt.at_seconds};
      if (impossible) {
        bool new_device = !binding_.device_trusted(attempt.user_id, attempt.device_fingerprint);
        if (new_device) {
          flagged_.insert(attempt.device_fingerprint);
          verdict.step_up_required = true;
          verdict.reason = "impossible travel onto a new device; step-up required";
        }
        return verdict;
      }
    }
    last_location_[attempt.user_id] = {attempt.location, attempt.at_seconds};
    return verdict;
  }

  // Sensitive-action gate: spends, purchases and market orders are refused
  // while the device carries an unresolved step-up flag. Fail closed.
  void require_not_flagged(const std::string& fingerprint) {
    std::lock_guard<std::mutex> lock(mutex_);
    if (flagged_.count(fingerprint) != 0) throw std::runtime_error("sensitive action blocked: step-up pending");
  }

  // The Worker calls this after step-up completes successfully.
  void clear_flag(const std::string& fingerprint) {
    std::lock_guard<std::mutex> lock(mutex_);
    flagged_.erase(fingerprint);
  }

private:
  int count_recent_failures_locked(const std::string& key, std::int64_t now_seconds) {
    auto& queue = failures_[key];
    while (!queue.empty() && now_seconds - queue.front() >= 3600) queue.pop_front();
    return static_cast<int>(queue.size());
  }

  AccountStore& store_;
  DeviceBindingService& binding_;
  std::map<std::string, std::deque<std::int64_t>> failures_;
  std::map<std::string, std::pair<GeoPoint, std::int64_t>> last_location_;
  std::set<std::string> flagged_;
  std::mutex mutex_;
};

} // namespace poko::identity

#endif

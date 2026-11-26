#pragma once

#include <cstddef>
#include <cstdint>
#include <functional>
#include <span>
#include <string_view>
#include <variant>
#include <vector>

namespace poko::mute {

// Versioned, typed hostcall boundary (MUT-35 foundation). Hostcalls are the
// only way guest code reaches the host: a call names a registered id, reads
// its arguments from a fixed register window, checks them against the declared
// signature, and enforces the required capability mask before the handler
// runs. Unknown ids, signature mismatches and denied capabilities all trap
// before dispatch; a handler failure traps after dispatch.
//
// The register VM carries i32 cells, so v1 signatures are integer, boolean
// (register values restricted to 0/1) and unit results. String/handle
// arguments arrive when registers can hold Values; registration rejects them.

enum class HostType : std::uint8_t { integer, boolean, unit };

// Capability mask bits mirror the approved v1 allow: set (04-mute.md).
// A def's mask is the requirement; the run environment's mask is the grant.
inline constexpr std::uint32_t capability_net = 1u << 0;
inline constexpr std::uint32_t capability_physics = 1u << 1;
inline constexpr std::uint32_t capability_storage = 1u << 2;
inline constexpr std::uint32_t capability_ui = 1u << 3;
inline constexpr std::uint32_t capability_asset = 1u << 4;
inline constexpr std::uint32_t capability_crypto = 1u << 5;
inline constexpr std::uint32_t capability_log = 1u << 6;
inline constexpr std::uint32_t capability_time = 1u << 7;
inline constexpr std::uint32_t capability_replicate = 1u << 8;
inline constexpr std::uint32_t capability_spawn = 1u << 9;
inline constexpr std::uint32_t capability_all = 0x3FFu;

// Canonical capability name table (spec order). This is the single source for
// allow:/requires name resolution at both compile and run time.
struct CapabilityEntry { std::string_view name; std::uint32_t bit; };
inline constexpr CapabilityEntry capability_entries[] = {
  {"Net",capability_net},{"Physics",capability_physics},{"Storage",capability_storage},
  {"Ui",capability_ui},{"Asset",capability_asset},{"Crypto",capability_crypto},
  {"Log",capability_log},{"Time",capability_time},{"Replicate",capability_replicate},
  {"Spawn",capability_spawn}};
[[nodiscard]] inline constexpr std::uint32_t capability_from_name(std::string_view name) noexcept {
  for (const auto& e : capability_entries) if (e.name == name) return e.bit;
  return 0;
}
[[nodiscard]] inline constexpr std::string_view capability_name(std::uint32_t bit) noexcept {
  for (const auto& e : capability_entries) if (e.bit == bit) return e.name;
  return {};
}

// not_implemented: the id is registered (so capability checks and denial
// work) but has no VM-callable implementation yet; the VM traps with
// hostcall_failed exactly as for `failed`.
enum class HostcallErrorCode : std::uint8_t { failed, not_implemented };
struct HostcallError { HostcallErrorCode code{}; };
using HostcallArgs = std::span<const std::int32_t>;
using HostcallResult = std::variant<std::int32_t, HostcallError>;
using HostcallHandler = std::function<HostcallResult(HostcallArgs)>;

struct HostcallDef {
  std::uint32_t id{};               // call_host.a operand; must fit in u8
  std::uint32_t version{1};         // signature version; must equal the environment ABI
  std::vector<HostType> params;     // integer | boolean only
  HostType result{HostType::unit};  // integer | boolean | unit
  std::uint32_t capabilities{};     // required mask, subset of capability_all
  bool serializable{true};          // false = must not run in serialized/replay verification
  HostcallHandler handler;
};

// The host's registered hostcall set. add() validates the signature eagerly so
// a malformed definition can never reach dispatch.
class HostcallTable {
 public:
  enum class AddError : std::uint8_t {
    ok, duplicate_id, invalid_id, invalid_signature,
    missing_handler, unknown_capability, too_many
  };
  static constexpr std::size_t max_entries = 4096;

  [[nodiscard]] AddError add(const HostcallDef& def);
  [[nodiscard]] const HostcallDef* find(std::uint32_t id) const noexcept;
  [[nodiscard]] std::size_t size() const noexcept { return defs_.size(); }

 private:
  std::vector<HostcallDef> defs_;
};

// Effective grant for a run is the program's allow: ceiling intersected with
// what the host grants; a hostcall requiring anything outside it is denied.
[[nodiscard]] inline constexpr std::uint32_t effective_capabilities(std::uint32_t ceiling, std::uint32_t host_grant) noexcept {
  return ceiling & host_grant;
}
// Ids of registered defs whose required capabilities exceed `granted`. Used at
// bind time so misconfigured hosts are rejected before any code runs.
[[nodiscard]] std::vector<std::uint32_t> unauthorized_hostcalls(const HostcallTable& table, std::uint32_t granted);

} // namespace poko::mute

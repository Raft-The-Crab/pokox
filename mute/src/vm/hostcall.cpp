#include "poko/mute/hostcall.hpp"

namespace poko::mute {
namespace {
bool host_type(std::uint8_t t) {
  return t <= static_cast<std::uint8_t>(HostType::unit);
}
}

HostcallTable::AddError HostcallTable::add(const HostcallDef& def) {
  if (def.id > 255) return AddError::invalid_id;
  if (def.version == 0 || def.params.size() > 256 ||
      !host_type(static_cast<std::uint8_t>(def.result)))
    return AddError::invalid_signature;
  for (const auto p : def.params) {
    const auto t = static_cast<std::uint8_t>(p);
    if (!host_type(t) || t == static_cast<std::uint8_t>(HostType::unit))
      return AddError::invalid_signature;
  }
  if (def.capabilities & ~capability_all) return AddError::unknown_capability;
  if (!def.handler) return AddError::missing_handler;
  if (find(def.id)) return AddError::duplicate_id;
  if (defs_.size() >= max_entries) return AddError::too_many;
  defs_.push_back(def);
  return AddError::ok;
}

const HostcallDef* HostcallTable::find(std::uint32_t id) const noexcept {
  for (const auto& def : defs_) if (def.id == id) return &def;
  return nullptr;
}

std::vector<std::uint32_t> unauthorized_hostcalls(const HostcallTable& table, std::uint32_t granted) {
  std::vector<std::uint32_t> out;
  for (std::uint32_t id = 0; id <= 255; ++id) {
    const auto* def = table.find(id);
    if (def && (def->capabilities & ~granted) != 0) out.push_back(id);
  }
  return out;
}

} // namespace poko::mute

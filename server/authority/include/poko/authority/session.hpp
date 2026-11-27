// BAK-02: in-memory authority for one session.
//
// One SessionAuthority owns the authoritative field values for a single game
// session. Registered clients propose field values per tick; the authority
// applies them per the .pkB field policy (spec 05) and serves one identical
// committed snapshot to every client, so two clients always agree on the
// same state and the same projected hash.
//
// Scope (BAK-02 only): in-memory, single session, i64 field values. The
// declarative rule evaluator that recomputes Validated fields from
// previous() arrives with BAK-05/06; until then a Validated proposal is
// accepted as the proposed value. The projected hash packs i64 fields as
// 8-byte little-endian two's complement in ascending field-id order — the
// .pkB declared-bit-width packing is wired in BAK-05.
#pragma once

#include "poko/mute/state.hpp" // xxhash64 (MUT-11)

#include <cstdint>
#include <functional>
#include <optional>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

namespace poko::authority {

// Spec 05 field policy. Protected domains (Pokoins, assets, shares,
// moderation, identity) are forced to ServerOwned before construction — that
// forcing lives with the .pkB reader, not here.
enum class Policy : std::uint8_t { server_owned, validated, trusted, derived };

struct FieldDef {
  std::uint32_t id = 0;
  std::string name;
  Policy policy = Policy::server_owned;
  std::int64_t initial = 0;
};

struct FieldValue {
  std::uint32_t id = 0;
  std::string name;
  Policy policy = Policy::server_owned;
  std::int64_t value = 0;
  bool operator==(const FieldValue&) const = default;
};

struct Snapshot {
  std::uint64_t tick = 0;
  std::uint64_t projected_hash = 0;
  std::vector<FieldValue> fields; // ascending field id
  bool operator==(const Snapshot&) const = default;
};

struct ProposalResult {
  enum class Code : std::uint8_t { accepted, discarded, unknown_field, unknown_client };
  Code code = Code::accepted;
  Policy policy = Policy::server_owned; // the policy that decided, for discarded
};

class SessionAuthority {
public:
  explicit SessionAuthority(std::uint64_t session_nonce, std::uint64_t hash_seed = 0)
      : nonce_(session_nonce), seed_(hash_seed) {}

  // Schema is fixed at session start; .pkB-driven schema arrival is BAK-05.
  // A duplicate field id is ignored (first definition wins).
  void define_field(const FieldDef& def) {
    if (fields_.emplace(def.id, Field{def, def.initial, std::nullopt}).second) order_.push_back(def.id);
  }

  std::uint32_t add_client() {
    const std::uint32_t id = next_client_id_++;
    clients_.emplace(id);
    return id;
  }

  void remove_client(std::uint32_t client) { clients_.erase(client); }

  [[nodiscard]] std::size_t client_count() const { return clients_.size(); }

  // A client proposes a new value for a field this tick. Enforced per spec 05:
  // ServerOwned client bits are discarded; Trusted is applied immediately and
  // never enters the projected hash; Derived is validator-computed and
  // refuses client writes.
  [[nodiscard]] ProposalResult propose(std::uint32_t client, std::uint32_t field_id, std::int64_t value) {
    if (!clients_.contains(client)) return {ProposalResult::Code::unknown_client, Policy::server_owned};
    auto it = fields_.find(field_id);
    if (it == fields_.end()) return {ProposalResult::Code::unknown_field, Policy::server_owned};
    switch (it->second.def.policy) {
      case Policy::validated:
        if (!it->second.pending) it->second.pending = value; // first proposal per tick wins
        return {ProposalResult::Code::accepted, Policy::validated};
      case Policy::trusted:
        it->second.value = value;
        return {ProposalResult::Code::accepted, Policy::trusted};
      case Policy::server_owned:
      case Policy::derived:
        return {ProposalResult::Code::discarded, it->second.def.policy};
    }
    return {ProposalResult::Code::discarded, it->second.def.policy};
  }

  // Authority-side write for ServerOwned and Derived fields (the economy
  // ledger and validator rules write through here, never clients).
  bool set_authoritative(std::uint32_t field_id, std::int64_t value) {
    auto it = fields_.find(field_id);
    if (it == fields_.end()) return false;
    if (it->second.def.policy != Policy::server_owned && it->second.def.policy != Policy::derived) return false;
    it->second.value = value;
    return true;
  }

  // Optional hook replacing the default 8-byte-per-field packing inside
  // tick() (BAK-05 wires the .pkB declared-width packing through this so
  // the served snapshot's projected_hash is the spec-05 hash).
  using HashHook = std::function<std::uint64_t(std::uint64_t tick)>;
  void set_hash_hook(HashHook hook) { hash_hook_ = std::move(hook); }

  // Commit pending Validated proposals, advance the tick, produce the one
  // snapshot every client is served this tick.
  Snapshot tick() {
    for (auto& [id, f] : fields_) {
      if (f.pending) {
        f.value = *f.pending;
        f.pending.reset();
      }
    }
    ++tick_;
    const std::uint64_t h = hash_hook_ ? hash_hook_(tick_) : projected_hash(tick_);
    last_ = Snapshot{tick_, h, collect()};
    return last_;
  }

  // What the authority serves a client this tick: identical for every client.
  [[nodiscard]] Snapshot snapshot_for(std::uint32_t client) const {
    (void)client; // per-client filtering (interest management) is a later task
    return last_;
  }

  // Spec 05: fields with policy ServerOwned, Validated or Derived, ascending
  // field id, packed after tick and session nonce; xxHash64 with the .pkB
  // seed. Trusted fields never enter the hash.
  [[nodiscard]] std::uint64_t projected_hash(std::uint64_t tick) const {
    std::vector<std::uint8_t> bytes;
    bytes.reserve(24 + fields_.size() * 8);
    append_u64(bytes, tick);
    append_u64(bytes, nonce_);
    for (std::uint32_t id : sorted_ids()) {
      const Field& f = fields_.at(id);
      if (f.def.policy == Policy::trusted) continue;
      append_u64(bytes, static_cast<std::uint64_t>(f.value)); // two's complement LE
    }
    return mute::xxhash64(bytes, seed_);
  }

  [[nodiscard]] std::uint64_t tick_number() const { return tick_; }

  [[nodiscard]] std::optional<std::int64_t> value_of(std::uint32_t field_id) const {
    auto it = fields_.find(field_id);
    if (it == fields_.end()) return std::nullopt;
    return it->second.value;
  }

private:
  struct Field {
    FieldDef def;
    std::int64_t value = 0;
    std::optional<std::int64_t> pending;
  };

  [[nodiscard]] std::vector<std::uint32_t> sorted_ids() const {
    std::vector<std::uint32_t> ids;
    ids.reserve(order_.size());
    for (std::uint32_t id : order_) ids.push_back(id);
    for (std::size_t i = 1; i < ids.size(); ++i) { // insertion sort: schemas are tiny
      std::uint32_t key = ids[i];
      std::size_t j = i;
      while (j > 0 && ids[j - 1] > key) { ids[j] = ids[j - 1]; --j; }
      ids[j] = key;
    }
    return ids;
  }

  [[nodiscard]] std::vector<FieldValue> collect() const {
    std::vector<FieldValue> out;
    out.reserve(fields_.size());
    for (std::uint32_t id : sorted_ids()) {
      const Field& f = fields_.at(id);
      out.push_back({id, f.def.name, f.def.policy, f.value});
    }
    return out;
  }

  static void append_u64(std::vector<std::uint8_t>& out, std::uint64_t v) {
    for (int i = 0; i < 8; ++i) out.push_back(static_cast<std::uint8_t>((v >> (8 * i)) & 0xff));
  }

  std::uint64_t nonce_ = 0;
  std::uint64_t seed_ = 0;
  std::uint64_t tick_ = 0;
  std::uint32_t next_client_id_ = 1;
  std::unordered_map<std::uint32_t, Field> fields_;
  std::vector<std::uint32_t> order_;
  std::unordered_set<std::uint32_t> clients_;
  HashHook hash_hook_;
  Snapshot last_;
};

} // namespace poko::authority

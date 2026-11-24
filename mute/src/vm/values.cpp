#include "poko/mute/values.hpp"
#include <set>
#include <utility>
namespace poko::mute {
Value make_int(std::int64_t v) noexcept { return {ValueKind::integer,v,0,true}; }
Value make_bool(bool v) noexcept { return {ValueKind::boolean,v?1:0,0,true}; }

std::uint64_t AggregateStore::handle_for(std::size_t slot) const noexcept {
  const auto& o=objects_[slot];
  return (static_cast<std::uint64_t>(o.generation)<<32) | static_cast<std::uint32_t>(slot+1);
}
AggregateStore::Object* AggregateStore::object(const Value& v) const {
  if (v.handle==0) return nullptr;
  const auto slot32=static_cast<std::uint32_t>(v.handle & 0xFFFFFFFFull);
  if (slot32==0 || slot32>objects_.size()) return nullptr;
  auto& o=objects_[slot32-1];
  if (!o.occupied || o.generation!=static_cast<std::uint32_t>(v.handle>>32) || o.kind!=v.kind)
    return nullptr;
  return const_cast<Object*>(&o);
}
// Iterative post-order free over 1-based slot indices: an explicit stack
// avoids recursion overflow on deep or cyclic aggregate graphs.
void AggregateStore::free_slot(std::uint32_t slot) {
  std::vector<std::uint32_t> stack{slot};
  while (!stack.empty()) {
    const auto s=stack.back(); stack.pop_back();
    auto& o=objects_[s-1];
    if (!o.occupied) continue;
    if (o.kind==ValueKind::array) {
      for (const auto& item:o.items) {
        if (item.kind!=ValueKind::string && item.kind!=ValueKind::array) continue;
        if (auto* child=object(item))
          if (--child->refs==0) {
            const auto cs=static_cast<std::uint32_t>(item.handle & 0xFFFFFFFFull);
            if (cs!=0) stack.push_back(cs);
          }
      }
    }
    heap_bytes_-=o.bytes; --live_;
    const auto gen=o.generation;
    o=Object{}; o.generation=gen; // keep generation so stale handles stay dead
  }
}
std::variant<std::uint32_t,ValueError> AggregateStore::alloc(ValueKind kind,std::size_t bytes) {
  std::uint32_t slot=0;
  for (std::size_t i=0;i<objects_.size();++i)
    if (!objects_[i].occupied) { slot=static_cast<std::uint32_t>(i+1); break; }
  if (!slot) {
    if (objects_.size()>=limits_.heap_objects) return ValueError{ValueErrorCode::heap_exceeded};
    objects_.emplace_back(); slot=static_cast<std::uint32_t>(objects_.size());
  }
  auto& o=objects_[slot-1];
  ++o.generation; // 0 -> 1 on first use; never reset, so stale handles die
  o.kind=kind; o.bytes=bytes; o.occupied=true; o.arena=true; o.refs=1;
  o.text.clear(); o.items.clear();
  heap_bytes_+=bytes; ++live_;
  if (heap_bytes_>limits_.heap_bytes) { free_slot(slot); return ValueError{ValueErrorCode::heap_exceeded}; }
  return slot;
}
std::variant<Value,ValueError> AggregateStore::make_string(std::string_view text) {
  if (text.size()>limits_.max_string_bytes) return ValueError{ValueErrorCode::heap_exceeded};
  auto h=alloc(ValueKind::string,text.size()+1);
  if (const auto* e=std::get_if<ValueError>(&h)) return *e;
  const auto slot=std::get<std::uint32_t>(h);
  auto& o=objects_[slot-1];
  o.text.assign(text);
  return Value{ValueKind::string,0,handle_for(slot-1),true};
}
std::variant<Value,ValueError> AggregateStore::make_array(std::size_t length,Value fill) {
  if (length>limits_.max_array_length) return ValueError{ValueErrorCode::bounds};
  auto h=alloc(ValueKind::array,length*sizeof(Value));
  if (const auto* e=std::get_if<ValueError>(&h)) return *e;
  const auto slot=std::get<std::uint32_t>(h);
  auto& o=objects_[slot-1];
  o.items.assign(length,fill);
  for (const auto& item:o.items) if (item.kind==ValueKind::string || item.kind==ValueKind::array) {
    if (auto* child=object(item)) ++child->refs;
  }
  return Value{ValueKind::array,0,handle_for(slot-1),true};
}
std::variant<Value,ValueError> AggregateStore::get_index(const Value& array,std::int64_t index) const {
  if (array.kind!=ValueKind::array) return ValueError{ValueErrorCode::wrong_kind};
  const auto* o=object(array); if (!o) return ValueError{ValueErrorCode::invalid_handle};
  if (index<0 || static_cast<std::uint64_t>(index)>=o->items.size()) return ValueError{ValueErrorCode::bounds};
  auto item=o->items[static_cast<std::size_t>(index)];
  item.owned=false; // borrowed container element: cannot be released
  return item;
}
// True when `target` is reachable from `from` through array items. Bounded by
// live object count; used to reject cycles before they can form.
bool AggregateStore::reaches(const Value& from,const Value& target) const {
  if (from.kind!=ValueKind::array || target.kind!=ValueKind::array) return false;
  std::vector<Value> stack{from};
  std::set<std::uint64_t> seen;
  while (!stack.empty()) {
    const auto cur=stack.back(); stack.pop_back();
    if (cur.handle==target.handle && cur.kind==target.kind) return true;
    if (!seen.insert(cur.handle).second) continue;
    const auto* o=object(cur); if (!o || o->kind!=ValueKind::array) continue;
    for (const auto& item:o->items)
      if (item.kind==ValueKind::string || item.kind==ValueKind::array) stack.push_back(item);
  }
  return false;
}
std::variant<Value,ValueError> AggregateStore::set_index(const Value& array,std::int64_t index,Value item) {
  if (array.kind!=ValueKind::array) return ValueError{ValueErrorCode::wrong_kind};
  auto* o=object(array); if (!o) return ValueError{ValueErrorCode::invalid_handle};
  if (index<0 || static_cast<std::uint64_t>(index)>=o->items.size()) return ValueError{ValueErrorCode::bounds};
  // Reject cycles: inserting an array that can already reach this one.
  if (item.kind==ValueKind::array && reaches(item,array))
    return ValueError{ValueErrorCode::cycle};
  auto& slot=o->items[static_cast<std::size_t>(index)];
  if (slot.kind==ValueKind::string || slot.kind==ValueKind::array) {
    if (auto* old=object(slot)) { if (--old->refs==0) free_slot(static_cast<std::uint32_t>(slot.handle & 0xFFFFFFFFull)); }
  }
  // A heap-resident parent must never reference arena children: reset_tick
  // would free them. Promote the inserted value (and its children) instead.
  if (!o->arena && (item.kind==ValueKind::string || item.kind==ValueKind::array)) {
    auto p=promote(item,0);
    if (const auto* e=std::get_if<ValueError>(&p)) return *e;
    item=std::get<Value>(p);
  }
  if (item.kind==ValueKind::string || item.kind==ValueKind::array) {
    if (auto* child=object(const_cast<Value&>(item))) ++child->refs;
  }
  slot=item; return make_int(0);
}
std::variant<std::string_view,ValueError> AggregateStore::as_string(const Value& v) const {
  if (v.kind!=ValueKind::string) return ValueError{ValueErrorCode::wrong_kind};
  const auto* o=object(v); if (!o) return ValueError{ValueErrorCode::invalid_handle};
  return std::string_view(o->text);
}
std::variant<std::size_t,ValueError> AggregateStore::length(const Value& v) const {
  const auto* o=object(v); if (!o) return ValueError{ValueErrorCode::invalid_handle};
  if (v.kind==ValueKind::string) return o->text.size();
  if (v.kind==ValueKind::array) return o->items.size();
  return ValueError{ValueErrorCode::wrong_kind};
}
std::variant<Value,ValueError> AggregateStore::copy(const Value& v) {
  return copy_impl(v,0);
}
std::variant<Value,ValueError> AggregateStore::copy_impl(const Value& v,std::size_t depth) {
  if (depth>limits_.max_depth) return ValueError{ValueErrorCode::depth_exceeded};
  if (v.kind==ValueKind::integer || v.kind==ValueKind::boolean) return v;
  const auto* o=object(v); if (!o) return ValueError{ValueErrorCode::invalid_handle};
  if (v.kind==ValueKind::string) return make_string(o->text);
  if (v.kind==ValueKind::array) {
    // Snapshot items before recursing: child copies allocate and may
    // reallocate objects_, invalidating any held Object pointer.
    const std::vector<Value> src(o->items.begin(),o->items.end());
    std::vector<Value> copied; copied.reserve(src.size());
    for (const auto& item:src) {
      auto c=copy_impl(item,depth+1);
      if (const auto* e=std::get_if<ValueError>(&c)) {
        for (const auto& done:copied) release(done);
        return *e;
      }
      copied.push_back(std::get<Value>(c));
    }
    auto result=make_array(src.size());
    if (const auto* e=std::get_if<ValueError>(&result)) {
      for (const auto& item:copied) release(item);
      return *e;
    }
    // Fresh object: no allocation between lookup and use. Each copied child
    // already owns one ref, which the slot now holds.
    auto* dst=object(std::get<Value>(result));
    dst->items=std::move(copied);
    return std::get<Value>(result);
  }
  return ValueError{ValueErrorCode::wrong_kind};
}
void AggregateStore::release(const Value& v) {
  if (!v.owned) return; // borrowed container element: not ours to release
  if (v.kind!=ValueKind::string && v.kind!=ValueKind::array) return;
  if (!object(v)) return;
  const auto slot=static_cast<std::uint32_t>(v.handle & 0xFFFFFFFFull);
  auto* o=object(const_cast<Value&>(v));
  if (o && --o->refs==0) free_slot(slot);
}
void AggregateStore::reset_tick() {
  for (std::size_t i=0;i<objects_.size();++i) {
    auto& o=objects_[i];
    if (!o.occupied || !o.arena) continue;
    // Release this arena object's references to heap children so they can
    // die; arena children are reclaimed wholesale below.
    if (o.kind==ValueKind::array) {
      for (const auto& item:o.items) {
        if (item.kind!=ValueKind::string && item.kind!=ValueKind::array) continue;
        if (auto* child=object(item); child && !child->arena)
          if (--child->refs==0) {
            const auto cs=static_cast<std::uint32_t>(item.handle & 0xFFFFFFFFull);
            if (cs!=0) free_slot(cs);
          }
      }
    }
    heap_bytes_-=o.bytes; --live_;
    const auto gen=o.generation;
    o=Object{}; o.generation=gen;
  }
  arena_bytes_=0;
}
std::variant<Value,ValueError> AggregateStore::promote(const Value& v,std::size_t depth) {
  if (depth>limits_.max_depth) return ValueError{ValueErrorCode::depth_exceeded};
  if (v.kind==ValueKind::integer || v.kind==ValueKind::boolean) return v;
  auto* o=object(const_cast<Value&>(v)); if (!o) return ValueError{ValueErrorCode::invalid_handle};
  if (!o->arena) return v;
  o->arena=false;
  if (v.kind==ValueKind::array) {
    for (auto& item:o->items) {
      auto p=promote(item,depth+1); if (const auto* e=std::get_if<ValueError>(&p)) return *e;
      item=std::get<Value>(p);
    }
  }
  return v;
}
} // namespace poko::mute

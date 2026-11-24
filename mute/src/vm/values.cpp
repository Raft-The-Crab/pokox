#include "poko/mute/values.hpp"
#include <cstring>
#include <stdexcept>
#include <utility>
namespace poko::mute {
Value make_int(std::int64_t v) noexcept { return {ValueKind::integer,v,0}; }
Value make_bool(bool v) noexcept { return {ValueKind::boolean,v?1:0,0}; }

AggregateStore::Object* AggregateStore::object(const Value& v) const {
  if (v.handle==0 || v.handle>objects_.size()) return nullptr;
  auto& o=objects_[v.handle-1];
  if (o.handle!=v.handle || o.kind!=v.kind) return nullptr;
  return const_cast<Object*>(&o);
}
// Iterative post-order free: an explicit stack avoids recursion overflow on
// deep or cyclic aggregate graphs.
void AggregateStore::free_object(std::uint32_t handle) {
  std::vector<std::uint32_t> stack{handle};
  while (!stack.empty()) {
    const auto h=stack.back(); stack.pop_back();
    auto& o=objects_[h-1];
    if (o.handle!=h) continue;
    if (o.kind==ValueKind::array) {
      for (const auto& item:o.items)
        if (item.kind==ValueKind::string || item.kind==ValueKind::array) {
          if (auto* child=object(item))
            if (--child->refs==0) stack.push_back(item.handle);
        }
    }
    heap_bytes_-=o.bytes; --live_;
    o=Object{}; o.handle=0;
  }
}
std::variant<std::uint32_t,ValueError> AggregateStore::alloc(ValueKind kind,std::size_t bytes) {
  std::uint32_t handle=0;
  for (std::size_t i=0;i<objects_.size();++i)
    if (objects_[i].handle==0) { handle=static_cast<std::uint32_t>(i+1); break; }
  if (!handle) {
    if (objects_.size()>=limits_.heap_objects) return ValueError{ValueErrorCode::heap_exceeded};
    objects_.emplace_back(); handle=static_cast<std::uint32_t>(objects_.size());
  }
  auto& o=objects_[handle-1];
  o=Object{}; o.kind=kind; o.bytes=bytes; o.handle=handle;
  heap_bytes_+=bytes; ++live_;
  if (heap_bytes_>limits_.heap_bytes) { free_object(handle); return ValueError{ValueErrorCode::heap_exceeded}; }
  return handle;
}
std::variant<Value,ValueError> AggregateStore::make_string(std::string_view text) {
  if (text.size()>limits_.max_string_bytes) return ValueError{ValueErrorCode::heap_exceeded};
  auto h=alloc(ValueKind::string,text.size()+1);
  if (const auto* e=std::get_if<ValueError>(&h)) return *e;
  auto& o=objects_[std::get<std::uint32_t>(h)-1];
  o.text.assign(text); o.items.clear();
  return Value{ValueKind::string,0,std::get<std::uint32_t>(h)};
}
std::variant<Value,ValueError> AggregateStore::make_array(std::size_t length,Value fill) {
  if (length>limits_.max_array_length) return ValueError{ValueErrorCode::bounds};
  auto h=alloc(ValueKind::array,length*sizeof(Value));
  if (const auto* e=std::get_if<ValueError>(&h)) return *e;
  auto& o=objects_[std::get<std::uint32_t>(h)-1];
  o.text.clear(); o.items.assign(length,fill);
  for (const auto& item:o.items) if (item.kind==ValueKind::string || item.kind==ValueKind::array) {
    if (auto* child=object(item)) ++child->refs;
  }
  return Value{ValueKind::array,0,std::get<std::uint32_t>(h)};
}
std::variant<Value,ValueError> AggregateStore::get_index(const Value& array,std::int64_t index) const {
  if (array.kind!=ValueKind::array) return ValueError{ValueErrorCode::wrong_kind};
  const auto* o=object(array); if (!o) return ValueError{ValueErrorCode::invalid_handle};
  if (index<0 || static_cast<std::uint64_t>(index)>=o->items.size()) return ValueError{ValueErrorCode::bounds};
  return o->items[static_cast<std::size_t>(index)];
}
std::variant<Value,ValueError> AggregateStore::set_index(const Value& array,std::int64_t index,Value item) {
  if (array.kind!=ValueKind::array) return ValueError{ValueErrorCode::wrong_kind};
  auto* o=object(array); if (!o) return ValueError{ValueErrorCode::invalid_handle};
  if (index<0 || static_cast<std::uint64_t>(index)>=o->items.size()) return ValueError{ValueErrorCode::bounds};
  auto& slot=o->items[static_cast<std::size_t>(index)];
  if (slot.kind==ValueKind::string || slot.kind==ValueKind::array) {
    if (auto* old=object(slot)) { if (--old->refs==0) free_object(slot.handle); }
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
      if (const auto* e=std::get_if<ValueError>(&c)) return *e;
      copied.push_back(std::get<Value>(c));
    }
    auto result=make_array(src.size());
    if (const auto* e=std::get_if<ValueError>(&result)) {
      for (const auto& item:copied) release(item); // drop completed siblings
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
  if (v.kind!=ValueKind::string && v.kind!=ValueKind::array) return;
  auto* o=object(const_cast<Value&>(v)); if (!o) return;
  if (--o->refs==0) free_object(v.handle);
}
void AggregateStore::reset_tick() {
  for (auto& o:objects_) if (o.handle!=0 && o.arena) {
    // Release this arena object's references to heap children so they can
    // die; arena children are reclaimed wholesale below.
    if (o.kind==ValueKind::array) {
      for (const auto& item:o.items)
        if (item.kind==ValueKind::string || item.kind==ValueKind::array) {
          if (auto* child=object(item); child && !child->arena)
            if (--child->refs==0) free_object(item.handle);
        }
    }
    heap_bytes_-=o.bytes; --live_; o=Object{}; o.handle=0;
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

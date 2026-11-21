#pragma once
// Test-only ownership smart pointer matching the operations the ImGui pass
// uses: out-params via operator&, move assignment from locals, implicit T*
// conversion for API calls, RawPtr/Release for RefCntAutoPtr semantics.
#include <memory>
namespace Diligent {
template<class T> class RefCntAutoPtr {
 public:
  RefCntAutoPtr() = default;
  ~RefCntAutoPtr() { Release(); }
  RefCntAutoPtr(const RefCntAutoPtr&) = delete;
  RefCntAutoPtr& operator=(const RefCntAutoPtr&) = delete;
  RefCntAutoPtr(RefCntAutoPtr&& other) noexcept : ptr_(other.ptr_) { other.ptr_ = nullptr; }
  RefCntAutoPtr& operator=(RefCntAutoPtr&& other) noexcept {
    // std::addressof bypasses the overloaded operator& (returns T**).
    if (this != std::addressof(other)) { Release(); ptr_ = other.ptr_; other.ptr_ = nullptr; }
    return *this;
  }
  T** operator&() noexcept { return &ptr_; }
  T* operator->() const noexcept { return ptr_; }
  operator T*() const noexcept { return ptr_; }
  explicit operator bool() const noexcept { return ptr_ != nullptr; }
  T* RawPtr() const noexcept { return ptr_; }
  void Release() noexcept { if (ptr_) { ptr_->Release(); ptr_ = nullptr; } }
 private: T* ptr_ = nullptr;
};
}

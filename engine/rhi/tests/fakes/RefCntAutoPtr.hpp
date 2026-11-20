#pragma once
// Only ownership operations used by this seed. NOT a Diligent compatibility test.
namespace Diligent {
template<class T> class RefCntAutoPtr {
 public:
  RefCntAutoPtr() = default;
  ~RefCntAutoPtr() { Release(); }
  RefCntAutoPtr(const RefCntAutoPtr&) = delete;
  RefCntAutoPtr& operator=(const RefCntAutoPtr&) = delete;
  T** operator&() noexcept { return &ptr_; }
  T* operator->() const noexcept { return ptr_; }
  explicit operator bool() const noexcept { return ptr_ != nullptr; }
  T* RawPtr() const noexcept { return ptr_; }
  void Release() noexcept { if (ptr_) { ptr_->Release(); ptr_ = nullptr; } }
 private: T* ptr_ = nullptr;
};
}

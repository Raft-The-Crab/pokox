#pragma once
#include <memory>
#include <utility>
namespace Diligent {
template<class T> class RefCntAutoPtr {
 public:
  RefCntAutoPtr()=default;
  ~RefCntAutoPtr() { if(ptr_) ptr_->Release(); }
  RefCntAutoPtr(const RefCntAutoPtr&)=delete;
  RefCntAutoPtr& operator=(const RefCntAutoPtr&)=delete;
  RefCntAutoPtr& operator=(RefCntAutoPtr&& other) noexcept { if(this!=std::addressof(other)) { if(ptr_) ptr_->Release(); ptr_=other.ptr_; other.ptr_=nullptr; } return *this; }
  T** operator&() noexcept { return &ptr_; }
  T* operator->() const noexcept { return ptr_; }
  explicit operator bool() const noexcept { return ptr_ != nullptr; }
  operator T*() const noexcept { return ptr_; }
 private: T* ptr_=nullptr;
};
}

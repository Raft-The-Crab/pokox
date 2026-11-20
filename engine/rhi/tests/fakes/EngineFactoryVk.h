#pragma once
// Test-owned declaration subset, NOT Diligent headers, ABI, or GPU validation.
#include <cstdint>
#ifndef DILIGENT_CALL_TYPE
#define DILIGENT_CALL_TYPE
#endif
namespace Diligent {
using Char = char;
enum DEBUG_MESSAGE_SEVERITY { DEBUG_MESSAGE_SEVERITY_INFO, DEBUG_MESSAGE_SEVERITY_WARNING,
  DEBUG_MESSAGE_SEVERITY_ERROR, DEBUG_MESSAGE_SEVERITY_FATAL_ERROR };
using DebugMessageCallbackType = void(DILIGENT_CALL_TYPE*)(DEBUG_MESSAGE_SEVERITY, const Char*, const Char*, const Char*, int);
extern DebugMessageCallbackType DebugMessageCallback;
using Uint32 = std::uint32_t;
enum TEXTURE_FORMAT { TEX_FORMAT_UNKNOWN, TEX_FORMAT_RGBA8_UNORM_SRGB };
enum RESOURCE_STATE_TRANSITION_MODE {
  RESOURCE_STATE_TRANSITION_MODE_NONE, RESOURCE_STATE_TRANSITION_MODE_TRANSITION
};
struct EngineVkCreateInfo { bool EnableValidation = false; Uint32 NumDeferredContexts = 0; Uint32 AdapterId = 0xFFFFFFFFU; };
struct SwapChainDesc {
  Uint32 Width = 0, Height = 0;
  TEXTURE_FORMAT DepthBufferFormat = TEX_FORMAT_RGBA8_UNORM_SRGB;
};
struct NativeWindow {
#if PLATFORM_WIN32
  void* hWnd = nullptr;
#elif PLATFORM_ANDROID
  void* pAWindow = nullptr;
#else
  Uint32 WindowId = 0; void* pDisplay = nullptr; void* pXCBConnection = nullptr;
#endif
};
struct IRenderDevice { virtual void Release() = 0; virtual ~IRenderDevice() = default; };
struct ITextureView {};
struct IDeviceContext {
  virtual void SetRenderTargets(Uint32, ITextureView*[], ITextureView*, RESOURCE_STATE_TRANSITION_MODE) = 0;
  virtual void ClearRenderTarget(ITextureView*, const void*, RESOURCE_STATE_TRANSITION_MODE) = 0;
  virtual void WaitForIdle() = 0;
  virtual void Release() = 0;
  virtual ~IDeviceContext() = default;
};
struct ISwapChain {
  virtual const SwapChainDesc& GetDesc() const = 0;
  virtual ITextureView* GetCurrentBackBufferRTV() = 0;
  virtual void Present(Uint32) = 0;
  virtual void Release() = 0;
  virtual ~ISwapChain() = default;
};
struct IEngineFactoryVk {
  virtual void SetMessageCallback(DebugMessageCallbackType) const = 0;
  virtual void CreateDeviceAndContextsVk(const EngineVkCreateInfo&, IRenderDevice**, IDeviceContext**) = 0;
  virtual void CreateSwapChainVk(IRenderDevice*, IDeviceContext*, const SwapChainDesc&, const NativeWindow&, ISwapChain**) = 0;
  virtual ~IEngineFactoryVk() = default;
};
IEngineFactoryVk* GetEngineFactoryVk();
}

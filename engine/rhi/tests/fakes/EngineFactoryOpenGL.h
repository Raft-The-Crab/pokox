#pragma once
// Test-only Diligent declaration subset; not an SDK or ABI substitute.
#include <EngineFactoryVk.h>
namespace Diligent {
struct EngineGLCreateInfo { NativeWindow Window{}; bool EnableValidation = false; Uint32 NumDeferredContexts = 0; };
struct IEngineFactoryOpenGL : IEngineFactory {
  virtual void CreateDeviceAndSwapChainGL(const EngineGLCreateInfo&, IRenderDevice**, IDeviceContext**, const SwapChainDesc&, ISwapChain**) = 0;
  virtual ~IEngineFactoryOpenGL() = default;
};
IEngineFactoryOpenGL* GetEngineFactoryOpenGL();
}

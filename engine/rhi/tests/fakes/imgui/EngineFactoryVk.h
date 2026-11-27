#pragma once
// Test-owned declaration subset for the ImGui pass fault harness, NOT Diligent
// headers, ABI, or GPU validation. Superset of fakes/EngineFactoryVk.h: keeps
// the diagnostics/factory decls and adds the full create/draw surface used by
// vulkan_imgui_pass.cpp. imgui_fake:: records calls and injects failures.
#include <cstdint>
#ifndef DILIGENT_CALL_TYPE
#define DILIGENT_CALL_TYPE
#endif
namespace Diligent {
using Char = char;
using Int32 = std::int32_t;
using Uint32 = std::uint32_t;
using Uint64 = std::uint64_t;
// ---- debug callback surface (vulkan_diagnostics.cpp) ----
enum DEBUG_MESSAGE_SEVERITY { DEBUG_MESSAGE_SEVERITY_INFO, DEBUG_MESSAGE_SEVERITY_WARNING,
  DEBUG_MESSAGE_SEVERITY_ERROR, DEBUG_MESSAGE_SEVERITY_FATAL_ERROR };
using DebugMessageCallbackType = void(DILIGENT_CALL_TYPE*)(DEBUG_MESSAGE_SEVERITY, const Char*, const Char*, const Char*, int);
extern DebugMessageCallbackType DebugMessageCallback;
// ---- enums used by the pass ----
enum TEXTURE_FORMAT { TEX_FORMAT_UNKNOWN, TEX_FORMAT_RGBA8_UNORM_SRGB, TEX_FORMAT_RGBA8_UNORM, TEX_FORMAT_D32_FLOAT };
enum RESOURCE_STATE_TRANSITION_MODE {
  RESOURCE_STATE_TRANSITION_MODE_NONE, RESOURCE_STATE_TRANSITION_MODE_TRANSITION
};
enum RESOURCE_DIMENSION { RESOURCE_DIM_TEX_2D };
enum BIND_FLAGS { BIND_NONE = 0, BIND_VERTEX_BUFFER = 1, BIND_INDEX_BUFFER = 2, BIND_UNIFORM_BUFFER = 4, BIND_SHADER_RESOURCE = 8 };
enum USAGE { USAGE_IMMUTABLE, USAGE_DYNAMIC };
enum CPU_ACCESS_FLAGS { CPU_ACCESS_NONE = 0, CPU_ACCESS_WRITE = 1 };
enum FILTER_TYPE { FILTER_TYPE_LINEAR };
enum TEXTURE_ADDRESS_MODE { TEXTURE_ADDRESS_CLAMP };
enum TEXTURE_VIEW_TYPE { TEXTURE_VIEW_SHADER_RESOURCE };
enum SHADER_TYPE { SHADER_TYPE_VERTEX, SHADER_TYPE_PIXEL };
enum VALUE_TYPE { VT_FLOAT32, VT_UINT8, VT_UINT16, VT_UINT32 };
enum INPUT_ELEMENT_FREQUENCY { INPUT_ELEMENT_FREQUENCY_PER_VERTEX };
enum BLEND_FACTOR { BLEND_FACTOR_ZERO, BLEND_FACTOR_ONE, BLEND_FACTOR_SRC_ALPHA, BLEND_FACTOR_INV_SRC_ALPHA };
enum BLEND_OPERATION { BLEND_OPERATION_ADD };
enum CULL_MODE { CULL_MODE_NONE, CULL_MODE_BACK };
enum FILL_MODE { FILL_MODE_SOLID };
enum PRIMITIVE_TOPOLOGY { PRIMITIVE_TOPOLOGY_TRIANGLE_LIST };
enum MAP_TYPE { MAP_READ = 1, MAP_WRITE = 2 };
enum MAP_FLAGS { MAP_FLAG_NONE = 0, MAP_FLAG_DISCARD = 1 };
// ---- descriptor structs (only fields the pass touches) ----
struct BufferDesc { const Char* Name = nullptr; Uint64 Size = 0; Uint32 BindFlags = 0; Uint32 Usage = 0; Uint32 CPUAccessFlags = 0; };
struct BufferData { const void* pData = nullptr; Uint64 DataSize = 0; };
struct TextureDesc { const Char* Name = nullptr; RESOURCE_DIMENSION Type = RESOURCE_DIM_TEX_2D; Uint32 Width = 0, Height = 0; TEXTURE_FORMAT Format = TEX_FORMAT_UNKNOWN; Uint32 MipLevels = 1, ArraySize = 1; Uint32 BindFlags = 0; Uint32 Usage = 0; };
struct TextureSubResData { const void* pData = nullptr; Uint64 Stride = 0; };
struct TextureData { TextureSubResData* pSubresources = nullptr; Uint32 NumSubresources = 0; };
struct TextureViewDesc { TEXTURE_VIEW_TYPE ViewType = TEXTURE_VIEW_SHADER_RESOURCE; };
struct SamplerDesc { const Char* Name = nullptr; FILTER_TYPE MinFilter = FILTER_TYPE_LINEAR, MagFilter = FILTER_TYPE_LINEAR, MipFilter = FILTER_TYPE_LINEAR; TEXTURE_ADDRESS_MODE AddressU = TEXTURE_ADDRESS_CLAMP, AddressV = TEXTURE_ADDRESS_CLAMP, AddressW = TEXTURE_ADDRESS_CLAMP; };
struct ShaderDesc { const Char* Name = nullptr; SHADER_TYPE ShaderType = SHADER_TYPE_VERTEX; };
struct ShaderCreateInfo { ShaderDesc Desc{}; const void* ByteCode = nullptr; Uint64 ByteCodeSize = 0; };
struct LayoutElement { const Char* HLSLSemantic = nullptr; Uint32 InputIndex = 0, BufferSlot = 0, NumComponents = 0; VALUE_TYPE ValueType = VT_FLOAT32; bool IsNormalized = false; Uint64 RelativeOffset = 0, Stride = 0; INPUT_ELEMENT_FREQUENCY Frequency = INPUT_ELEMENT_FREQUENCY_PER_VERTEX; };
struct InputLayoutDesc { const LayoutElement* LayoutElements = nullptr; Uint32 NumElements = 0; };
struct BlendModeRenderTargetDesc { bool BlendEnable = false; BLEND_FACTOR SrcBlend = BLEND_FACTOR_ONE, DestBlend = BLEND_FACTOR_ZERO, SrcBlendAlpha = BLEND_FACTOR_ONE, DestBlendAlpha = BLEND_FACTOR_ZERO; BLEND_OPERATION BlendOp = BLEND_OPERATION_ADD, BlendOpAlpha = BLEND_OPERATION_ADD; };
struct BlendDesc { bool IndependentBlendEnable = false; BlendModeRenderTargetDesc RenderTargets[8]; };
struct RasterizerDesc { CULL_MODE CullMode = CULL_MODE_BACK; FILL_MODE FillMode = FILL_MODE_SOLID; bool ScissorEnable = false; };
struct DepthStencilDesc { bool DepthEnable = false; bool DepthWriteEnable = false; };
struct GraphicsPipelineDesc { InputLayoutDesc InputLayout{}; Uint32 NumRenderTargets = 0; TEXTURE_FORMAT RTVFormats[8]{}; TEXTURE_FORMAT DSVFormat = TEX_FORMAT_UNKNOWN; Diligent::BlendDesc BlendDesc{}; Diligent::RasterizerDesc RasterizerDesc{}; Diligent::DepthStencilDesc DepthStencilDesc{}; PRIMITIVE_TOPOLOGY PrimitiveTopology = PRIMITIVE_TOPOLOGY_TRIANGLE_LIST; };
struct PipelineStateDesc { const Char* Name = nullptr; };
struct GraphicsPipelineStateCreateInfo { PipelineStateDesc PSODesc{}; GraphicsPipelineDesc GraphicsPipeline{}; struct IShader* pVS = nullptr; struct IShader* pPS = nullptr; };
struct Viewport { float X = 0, Y = 0, Width = 0, Height = 0, MinDepth = 0, MaxDepth = 1; };
struct Rect { Int32 Left = 0, Top = 0, Right = 0, Bottom = 0; };
enum DRAW_FLAGS { DRAW_FLAG_NONE = 0 };
// Real layout: NumIndices, IndexType, Flags, NumInstances, FirstIndexLocation,
// BaseVertex, FirstInstanceLocation — no IndexBufferOffset/StartInstanceLocation.
struct DrawIndexedAttribs { Uint32 NumIndices = 0; VALUE_TYPE IndexType = VT_UINT16; DRAW_FLAGS Flags = DRAW_FLAG_NONE; Uint32 NumInstances = 1; Uint32 FirstIndexLocation = 0; Uint32 BaseVertex = 0; Uint32 FirstInstanceLocation = 0; };
// ---- device/context/swapchain surface ----
struct Version { Uint32 Major = 4, Minor = 6; };
struct RenderDeviceInfo { Version APIVersion; };
struct EngineVkCreateInfo { bool EnableValidation = false; Uint32 NumDeferredContexts = 0; Uint32 AdapterId = 0xFFFFFFFFU; };
struct SwapChainDesc { Uint32 Width = 0, Height = 0; TEXTURE_FORMAT ColorBufferFormat = TEX_FORMAT_RGBA8_UNORM_SRGB; TEXTURE_FORMAT DepthBufferFormat = TEX_FORMAT_D32_FLOAT; };
struct NativeWindow {
#if PLATFORM_WIN32
  void* hWnd = nullptr;
#elif PLATFORM_ANDROID
  void* pAWindow = nullptr;
#else
  Uint32 WindowId = 0; void* pDisplay = nullptr; void* pXCBConnection = nullptr;
#endif
};
struct IDeviceObject { virtual ~IDeviceObject() = default; };
struct IBuffer : IDeviceObject { public: virtual void Release() = 0; virtual ~IBuffer() = default; };
struct ITexture : IDeviceObject { public: virtual void CreateView(const TextureViewDesc&, struct ITextureView**) = 0; virtual void Release() = 0; virtual ~ITexture() = default; };
struct ITextureView : IDeviceObject { public: virtual void SetSampler(struct ISampler*) = 0; virtual void Release() = 0; virtual ~ITextureView() = default; };
struct ISampler : IDeviceObject { public: virtual void Release() = 0; virtual ~ISampler() = default; };
struct IShader : IDeviceObject { public: virtual void Release() = 0; virtual ~IShader() = default; };
struct IShaderResourceVariable {
 public: virtual void Set(IDeviceObject*) = 0; virtual void Release() = 0; virtual ~IShaderResourceVariable() = default;
};
struct IShaderResourceBinding;
struct IPipelineState { public: virtual IShaderResourceVariable* GetStaticVariableByName(SHADER_TYPE, const Char*) = 0; virtual void CreateShaderResourceBinding(IShaderResourceBinding**, bool) = 0; virtual void Release() = 0; virtual ~IPipelineState() = default; };
struct IShaderResourceBinding { public: virtual void Release() = 0; virtual ~IShaderResourceBinding() = default; };
struct IRenderDevice {
 public:
  virtual const RenderDeviceInfo& GetDeviceInfo() const = 0;
  virtual void Release() = 0;
  virtual void CreateBuffer(const BufferDesc&, const BufferData*, IBuffer**) = 0;
  virtual void CreateTexture(const TextureDesc&, const TextureData*, ITexture**) = 0;
  virtual void CreateSampler(const SamplerDesc&, ISampler**) = 0;
  virtual void CreateShader(const ShaderCreateInfo&, IShader**) = 0;
  virtual void CreateGraphicsPipelineState(const GraphicsPipelineStateCreateInfo&, IPipelineState**) = 0;
  virtual ~IRenderDevice() = default;
};
struct IDeviceContext {
 public:
  virtual void SetRenderTargets(Uint32, ITextureView*[], ITextureView*, RESOURCE_STATE_TRANSITION_MODE) = 0;
  virtual void ClearRenderTarget(ITextureView*, const void*, RESOURCE_STATE_TRANSITION_MODE) = 0;
  virtual void WaitForIdle() = 0;
  virtual void Release() = 0;
  virtual void SetViewports(Uint32, const Viewport*, Uint32, Uint32) = 0;
  virtual void SetPipelineState(IPipelineState*) = 0;
  virtual void SetVertexBuffers(Uint32, Uint32, IBuffer* const*, const Uint64*, RESOURCE_STATE_TRANSITION_MODE) = 0;
  virtual void SetIndexBuffer(IBuffer*, Uint64, RESOURCE_STATE_TRANSITION_MODE) = 0;
  virtual void SetScissorRects(Uint32, const Rect*, Uint32, Uint32) = 0;
  virtual void DrawIndexed(const DrawIndexedAttribs&) = 0;
  virtual void MapBuffer(IBuffer*, MAP_TYPE, MAP_FLAGS, void*&) = 0;
  virtual void UnmapBuffer(IBuffer*, MAP_TYPE) = 0;
  virtual void CommitShaderResources(IShaderResourceBinding*, RESOURCE_STATE_TRANSITION_MODE) = 0;
  virtual ~IDeviceContext() = default;
};
struct ISwapChain {
 public: virtual const SwapChainDesc& GetDesc() const = 0; virtual void Resize(Uint32, Uint32) = 0; virtual ITextureView* GetCurrentBackBufferRTV() = 0; virtual void Present(Uint32) = 0; virtual void SetMaximumFrameLatency(Uint32) = 0; virtual void Release() = 0; virtual ~ISwapChain() = default; };
struct IEngineFactory { virtual void SetMessageCallback(DebugMessageCallbackType) const = 0; virtual ~IEngineFactory() = default; };
struct IEngineFactoryVk : IEngineFactory {
  virtual void CreateDeviceAndContextsVk(const EngineVkCreateInfo&, IRenderDevice**, IDeviceContext**) = 0;
  virtual void CreateSwapChainVk(IRenderDevice*, IDeviceContext*, const SwapChainDesc&, const NativeWindow&, ISwapChain**) = 0;
  virtual ~IEngineFactoryVk() = default;
};
IEngineFactoryVk* GetEngineFactoryVk();
}  // namespace Diligent

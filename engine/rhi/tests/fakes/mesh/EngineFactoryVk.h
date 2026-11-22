#pragma once
// Minimal test doubles for triangle-pass control flow, not a Diligent SDK.
#include <cstddef>
#include <cstdint>
namespace mesh_fake { inline int fail_buffer_number=0; inline void* last_mapped=nullptr; inline void* last_camera=nullptr; inline int errors=0, presents=0, shaders=0, pipelines=0, bindings=0, clears=0, depth_clears=0, states=0, draws=0, vertices=0, fail_at=0; inline bool depth_enabled=false, depth_write=false; inline int depth_func=0, depth_format=0; inline float depth_clear=-1.f; inline int buffers=0, variables=0, srbs=0, maps=0, unmaps=0, commits=0, texture_updates=0; inline float uploaded[4]={}; }
namespace Diligent {
using TEXTURE_FORMAT = int;
using Uint32 = std::uint32_t;
using Uint64 = std::uint64_t;
constexpr int TEX_FORMAT_UNKNOWN=0, TEX_FORMAT_RGBA8_UNORM=1, TEX_FORMAT_D32_FLOAT=2,
  TEX_FORMAT_RGBA8_UNORM_SRGB=4, TEX_FORMAT_BGRA8_UNORM_SRGB=5;
constexpr int SHADER_TYPE_VERTEX=1, SHADER_TYPE_PIXEL=2, COMPARISON_FUNC_LESS=1, CULL_MODE_NONE=0, CULL_MODE_BACK=2, PRIMITIVE_TOPOLOGY_TRIANGLE_LIST=1, RESOURCE_STATE_TRANSITION_MODE_TRANSITION=1, CLEAR_DEPTH_FLAG=1, DRAW_FLAG_VERIFY_ALL=1;
constexpr int BIND_UNIFORM_BUFFER=1, BIND_VERTEX_BUFFER=2, BIND_INDEX_BUFFER=4, USAGE_IMMUTABLE=3, USAGE_DYNAMIC=2, CPU_ACCESS_WRITE=4, MAP_WRITE=1, MAP_FLAG_DISCARD=2;
constexpr int TEXTURE_TYPE_2D=1, TEX_FORMAT_BGRA8_UNORM=3, USAGE_DEFAULT=1, BIND_SHADER_RESOURCE=8;
constexpr int FILTER_TYPE_LINEAR=1, TEXTURE_ADDRESS_CLAMP=1, TEXTURE_VIEW_SHADER_RESOURCE=1;
constexpr int RESOURCE_DIM_TEX_2D=2, RESOURCE_STATE_TRANSITION_MODE_NONE=0;
struct BufferDesc { const char* Name=nullptr; std::size_t Size=0; int BindFlags=0, Usage=0, CPUAccessFlags=0; };
constexpr int True=1, VT_FLOAT32=1, VT_UINT32=2, INPUT_ELEMENT_FREQUENCY_PER_VERTEX=1;
struct IBuffer { float values[16]{}; void Release() { delete this; } };
struct Box { std::uint32_t MinX=0, MinY=0, MinZ=0, MaxX=0, MaxY=0, MaxZ=0; };
struct TextureDesc { const char* Name=nullptr; int Type=0; TEXTURE_FORMAT Format=TEX_FORMAT_UNKNOWN; std::uint32_t Width=0, Height=0, MipLevels=0, ArraySize=0; int Usage=0, BindFlags=0; };
struct SamplerDesc { const char* Name=nullptr; int MinFilter=0, MagFilter=0, MipFilter=0, AddressU=0, AddressV=0, AddressW=0; };
struct ISampler { void Release() { delete this; } };
struct ITextureView {
 void SetSampler(ISampler*) {}
};
struct ITexture { ITextureView view; ITextureView* GetDefaultView(int) { return &view; } void Release() { delete this; } };
struct TextureSubResData { const void* pData=nullptr; Uint64 Stride=0; Uint64 DepthStride=0; };
struct IShaderResourceVariable {
 void Set(IBuffer*) { if (mesh_fake::fail_at==11) ++mesh_fake::errors; }
 void Set(ITextureView*) {}
 void SetSampler(ISampler*) {}
};
struct IShaderResourceBinding {
 IShaderResourceVariable var;
 IShaderResourceVariable* GetVariableByName(int, const char*) { return &var; }
 void Release() { delete this; }
};
struct IShader { void Release() { delete this; } };
struct IPipelineState {
 IShaderResourceVariable var;
 IShaderResourceVariable* GetStaticVariableByName(int, const char*) { ++mesh_fake::variables; return mesh_fake::fail_at==10 ? nullptr : &var; }
 void CreateShaderResourceBinding(IShaderResourceBinding** out, bool) { ++mesh_fake::srbs; if (mesh_fake::fail_at==12) { ++mesh_fake::errors; return; } *out=new IShaderResourceBinding; }
 void Release() { delete this; }
};
struct ShaderCreateInfo { struct { const char* Name=nullptr; int ShaderType=0; } Desc; const void* ByteCode=nullptr; std::size_t ByteCodeSize=0; };
struct LayoutElement { const char* Semantic; int InputIndex, BufferSlot, NumComponents, ValueType; bool IsNormalized; int RelativeOffset, Stride, Frequency, InstanceDataStepRate; };
struct InputLayoutDesc { const LayoutElement* p=nullptr; int n=0; };
struct GraphicsPipelineStateCreateInfo {
 struct { const char* Name=nullptr; } PSODesc;
 struct { int NumRenderTargets=0; TEXTURE_FORMAT RTVFormats[1]{}; struct { bool DepthEnable=false, DepthWriteEnable=false; int DepthFunc=0; } DepthStencilDesc; TEXTURE_FORMAT DSVFormat=0; struct { int CullMode=0; bool FrontCounterClockwise=false; } RasterizerDesc; InputLayoutDesc InputLayout; int PrimitiveTopology=0; } GraphicsPipeline;
 IShader* pVS=nullptr; IShader* pPS=nullptr;
};
struct BufferData { const void* pData = nullptr; std::uint64_t DataSize = 0; const void* context=nullptr; };
struct IRenderDevice {
 void CreateBuffer(const BufferDesc&, const BufferData*, IBuffer** out) { ++mesh_fake::buffers; if (mesh_fake::buffers==mesh_fake::fail_buffer_number) return; *out=new IBuffer; }
 void CreateShader(const ShaderCreateInfo&, IShader** out) { ++mesh_fake::shaders; if (mesh_fake::fail_at==1 || (mesh_fake::fail_at==8 && mesh_fake::shaders==2)) { ++mesh_fake::errors; return; } *out=new IShader; }
 void CreateTexture(const TextureDesc&, const void*, ITexture** out) { *out=new ITexture; }
 void CreateSampler(const SamplerDesc&, ISampler** out) { *out=new ISampler; }
 void CreateGraphicsPipelineState(const GraphicsPipelineStateCreateInfo& info, IPipelineState** out) {
  ++mesh_fake::pipelines; mesh_fake::depth_enabled=info.GraphicsPipeline.DepthStencilDesc.DepthEnable; mesh_fake::depth_write=info.GraphicsPipeline.DepthStencilDesc.DepthWriteEnable; mesh_fake::depth_func=info.GraphicsPipeline.DepthStencilDesc.DepthFunc; mesh_fake::depth_format=info.GraphicsPipeline.DSVFormat;
  if (mesh_fake::fail_at==2) { ++mesh_fake::errors; return; } *out=new IPipelineState;
 }
};
struct SwapChainDesc { TEXTURE_FORMAT ColorBufferFormat=TEX_FORMAT_RGBA8_UNORM, DepthBufferFormat=TEX_FORMAT_D32_FLOAT; };
struct ISwapChain { SwapChainDesc desc; ITextureView* depth=nullptr; const SwapChainDesc& GetDesc() { return desc; } ITextureView* GetDepthBufferDSV() { return depth; } };
struct DrawAttribs { int NumVertices=0, Flags=0; };
struct DrawIndexedAttribs { Uint32 NumIndices=0; int IndexType=0, Flags=0; };
struct IDeviceContext {
 void MapBuffer(IBuffer* buffer, int, int, void*& mapped) { ++mesh_fake::maps; if(mesh_fake::fail_at==13) return; mapped=buffer->values; mesh_fake::last_mapped=buffer; if (mesh_fake::maps % 2 == 1) mesh_fake::last_camera=buffer; if(mesh_fake::fail_at==14) ++mesh_fake::errors; }
 void UnmapBuffer(IBuffer* buffer, int) { ++mesh_fake::unmaps; for(int i=0;i<4;++i) mesh_fake::uploaded[i]=buffer->values[i]; if(mesh_fake::fail_at==15) ++mesh_fake::errors; }
 void UpdateTexture(ITexture*, int, int, const Box&, const TextureSubResData&, int, int) { ++mesh_fake::texture_updates; }
 void CommitShaderResources(IShaderResourceBinding*, int) { ++mesh_fake::commits; if(mesh_fake::fail_at==16) ++mesh_fake::errors; }
 void SetRenderTargets(int, ITextureView**, ITextureView*, int) { ++mesh_fake::bindings; if(mesh_fake::fail_at==3) ++mesh_fake::errors; }
 void ClearRenderTarget(ITextureView*, const float*, int) { ++mesh_fake::clears; if(mesh_fake::fail_at==4) ++mesh_fake::errors; }
 void ClearDepthStencil(ITextureView*, int, float depth, int, int) { ++mesh_fake::depth_clears; mesh_fake::depth_clear=depth; if(mesh_fake::fail_at==5) ++mesh_fake::errors; }
 void SetPipelineState(IPipelineState*) { ++mesh_fake::states; if(mesh_fake::fail_at==6) ++mesh_fake::errors; }
 void SetVertexBuffers(int, int, IBuffer**, const Uint64*, int) {}
 void SetIndexBuffer(IBuffer*, int, int) {}
 void DrawIndexed(const DrawIndexedAttribs& draw) { ++mesh_fake::draws; mesh_fake::vertices=static_cast<int>(draw.NumIndices); }
 void Draw(const DrawAttribs& draw) { ++mesh_fake::draws; mesh_fake::vertices=draw.NumVertices; if(mesh_fake::fail_at==7) ++mesh_fake::errors; }
};
}

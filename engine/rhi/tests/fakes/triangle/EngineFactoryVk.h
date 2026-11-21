#pragma once
// Minimal test doubles for triangle-pass control flow, not a Diligent SDK.
#include <cstddef>
#include <cstdint>
namespace triangle_fake { inline int errors=0, presents=0, shaders=0, pipelines=0, bindings=0, clears=0, depth_clears=0, states=0, draws=0, vertices=0, fail_at=0; inline bool depth_enabled=false, depth_write=false; inline int depth_func=0, depth_format=0; inline float depth_clear=-1.f; inline int buffers=0, variables=0, srbs=0, maps=0, unmaps=0, commits=0; inline float uploaded[4]={}; }
namespace Diligent {
using TEXTURE_FORMAT = int;
constexpr int TEX_FORMAT_UNKNOWN=0, TEX_FORMAT_RGBA8_UNORM=1, TEX_FORMAT_D32_FLOAT=2;
constexpr int SHADER_TYPE_VERTEX=1, SHADER_TYPE_PIXEL=2, COMPARISON_FUNC_LESS=1, CULL_MODE_NONE=0, PRIMITIVE_TOPOLOGY_TRIANGLE_LIST=1, RESOURCE_STATE_TRANSITION_MODE_TRANSITION=1, CLEAR_DEPTH_FLAG=1, DRAW_FLAG_VERIFY_ALL=1;
constexpr int BIND_UNIFORM_BUFFER=1, USAGE_DYNAMIC=2, CPU_ACCESS_WRITE=4, MAP_WRITE=1, MAP_FLAG_DISCARD=2;
struct BufferDesc { const char* Name=nullptr; std::size_t Size=0; int BindFlags=0, Usage=0, CPUAccessFlags=0; };
struct IBuffer { float values[4]{}; void Release() { delete this; } };
struct IShaderResourceBinding { void Release() { delete this; } };
struct IShaderResourceVariable { void Set(IBuffer*) { if (triangle_fake::fail_at==11) ++triangle_fake::errors; } };
struct IShader { void Release() { delete this; } };
struct IPipelineState {
 IShaderResourceVariable var;
 IShaderResourceVariable* GetStaticVariableByName(int, const char*) { ++triangle_fake::variables; return triangle_fake::fail_at==10 ? nullptr : &var; }
 void CreateShaderResourceBinding(IShaderResourceBinding** out, bool) { ++triangle_fake::srbs; if (triangle_fake::fail_at==12) { ++triangle_fake::errors; return; } *out=new IShaderResourceBinding; }
 void Release() { delete this; }
};
struct ShaderCreateInfo { struct { const char* Name=nullptr; int ShaderType=0; } Desc; const void* ByteCode=nullptr; std::size_t ByteCodeSize=0; };
struct GraphicsPipelineStateCreateInfo {
 struct { const char* Name=nullptr; } PSODesc;
 struct { int NumRenderTargets=0; TEXTURE_FORMAT RTVFormats[1]{}; struct { bool DepthEnable=false, DepthWriteEnable=false; int DepthFunc=0; } DepthStencilDesc; TEXTURE_FORMAT DSVFormat=0; struct { int CullMode=0; } RasterizerDesc; int PrimitiveTopology=0; } GraphicsPipeline;
 IShader* pVS=nullptr; IShader* pPS=nullptr;
};
struct BufferData { const void* pData = nullptr; std::uint64_t DataSize = 0; };
struct IRenderDevice {
 void CreateBuffer(const BufferDesc& desc, const BufferData*, IBuffer** out) { ++triangle_fake::buffers; if (triangle_fake::fail_at==9) { ++triangle_fake::errors; return; } if(desc.Size!=16 || desc.BindFlags!=BIND_UNIFORM_BUFFER || desc.Usage!=USAGE_DYNAMIC || desc.CPUAccessFlags!=CPU_ACCESS_WRITE) { ++triangle_fake::errors; return; } *out=new IBuffer; }
 void CreateShader(const ShaderCreateInfo&, IShader** out) { ++triangle_fake::shaders; if (triangle_fake::fail_at==1 || (triangle_fake::fail_at==8 && triangle_fake::shaders==2)) { ++triangle_fake::errors; return; } *out=new IShader; }
 void CreateGraphicsPipelineState(const GraphicsPipelineStateCreateInfo& info, IPipelineState** out) {
  ++triangle_fake::pipelines; triangle_fake::depth_enabled=info.GraphicsPipeline.DepthStencilDesc.DepthEnable; triangle_fake::depth_write=info.GraphicsPipeline.DepthStencilDesc.DepthWriteEnable; triangle_fake::depth_func=info.GraphicsPipeline.DepthStencilDesc.DepthFunc; triangle_fake::depth_format=info.GraphicsPipeline.DSVFormat;
  if (triangle_fake::fail_at==2) { ++triangle_fake::errors; return; } *out=new IPipelineState;
 }
};
struct ITextureView {};
struct SwapChainDesc { TEXTURE_FORMAT ColorBufferFormat=TEX_FORMAT_RGBA8_UNORM, DepthBufferFormat=TEX_FORMAT_D32_FLOAT; };
struct ISwapChain { SwapChainDesc desc; ITextureView* depth=nullptr; const SwapChainDesc& GetDesc() { return desc; } ITextureView* GetDepthBufferDSV() { return depth; } };
struct DrawAttribs { int NumVertices=0, Flags=0; };
struct IDeviceContext {
 void MapBuffer(IBuffer* buffer, int, int, void*& mapped) { ++triangle_fake::maps; if(triangle_fake::fail_at==13) return; mapped=buffer->values; if(triangle_fake::fail_at==14) ++triangle_fake::errors; }
 void UnmapBuffer(IBuffer* buffer, int) { ++triangle_fake::unmaps; for(int i=0;i<4;++i) triangle_fake::uploaded[i]=buffer->values[i]; if(triangle_fake::fail_at==15) ++triangle_fake::errors; }
 void CommitShaderResources(IShaderResourceBinding*, int) { ++triangle_fake::commits; if(triangle_fake::fail_at==16) ++triangle_fake::errors; }
 void SetRenderTargets(int, ITextureView**, ITextureView*, int) { ++triangle_fake::bindings; if(triangle_fake::fail_at==3) ++triangle_fake::errors; }
 void ClearRenderTarget(ITextureView*, const float*, int) { ++triangle_fake::clears; if(triangle_fake::fail_at==4) ++triangle_fake::errors; }
 void ClearDepthStencil(ITextureView*, int, float depth, int, int) { ++triangle_fake::depth_clears; triangle_fake::depth_clear=depth; if(triangle_fake::fail_at==5) ++triangle_fake::errors; }
 void SetPipelineState(IPipelineState*) { ++triangle_fake::states; if(triangle_fake::fail_at==6) ++triangle_fake::errors; }
 void Draw(const DrawAttribs& draw) { ++triangle_fake::draws; triangle_fake::vertices=draw.NumVertices; if(triangle_fake::fail_at==7) ++triangle_fake::errors; }
};
}

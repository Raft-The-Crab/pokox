#pragma once
// Test-only subset of SDL declarations used by sdl_platform.cpp.
// This is NOT SDL, an ABI check, or an operating-system backend.
#include <cstdint>
using SDL_InitFlags = std::uint32_t;
using SDL_WindowFlags = std::uint64_t;
using SDL_WindowID = std::uint32_t;
inline constexpr SDL_InitFlags SDL_INIT_VIDEO = 0x20;
inline constexpr SDL_WindowFlags SDL_WINDOW_OPENGL = 0x00000002;
inline constexpr SDL_WindowFlags SDL_WINDOW_VULKAN = 0x10000000;
inline constexpr SDL_WindowFlags SDL_WINDOW_RESIZABLE = 0x20;
inline constexpr SDL_WindowFlags SDL_WINDOW_MINIMIZED = 0x40;
inline constexpr SDL_WindowFlags SDL_WINDOW_HIGH_PIXEL_DENSITY = 0x2000;
inline constexpr std::uint32_t SDL_EVENT_QUIT = 0x100;
inline constexpr std::uint32_t SDL_EVENT_WINDOW_RESIZED = 0x206;
inline constexpr std::uint32_t SDL_EVENT_WINDOW_PIXEL_SIZE_CHANGED = 0x207;
inline constexpr std::uint32_t SDL_EVENT_WINDOW_CLOSE_REQUESTED = 0x210;
struct SDL_Window;
struct SDL_WindowEvent { std::uint32_t type; SDL_WindowID windowID; };
union SDL_Event { std::uint32_t type; SDL_WindowEvent window; };
bool SDL_InitSubSystem(SDL_InitFlags flags);
void SDL_QuitSubSystem(SDL_InitFlags flags);
SDL_Window* SDL_CreateWindow(const char* title, int w, int h, SDL_WindowFlags flags);
void SDL_DestroyWindow(SDL_Window* window);
bool SDL_PollEvent(SDL_Event* event);
SDL_WindowID SDL_GetWindowID(SDL_Window* window);
bool SDL_GetWindowSize(SDL_Window* window, int* w, int* h);
bool SDL_GetWindowSizeInPixels(SDL_Window* window, int* w, int* h);

using SDL_PropertiesID = std::uint32_t;
using Sint64 = std::int64_t;
inline constexpr const char* SDL_PROP_WINDOW_WIN32_HWND_POINTER = "SDL.window.win32.hwnd";
inline constexpr const char* SDL_PROP_WINDOW_ANDROID_WINDOW_POINTER = "SDL.window.android.window";
inline constexpr const char* SDL_PROP_WINDOW_X11_DISPLAY_POINTER = "SDL.window.x11.display";
inline constexpr const char* SDL_PROP_WINDOW_X11_WINDOW_NUMBER = "SDL.window.x11.window";
SDL_WindowFlags SDL_GetWindowFlags(SDL_Window* window);
const char* SDL_GetCurrentVideoDriver();
SDL_PropertiesID SDL_GetWindowProperties(SDL_Window* window);
void* SDL_GetPointerProperty(SDL_PropertiesID props, const char* name, void* fallback);
Sint64 SDL_GetNumberProperty(SDL_PropertiesID props, const char* name, Sint64 fallback);
const char* SDL_GetError();
void SDL_Delay(std::uint32_t ms);

struct SDL_GLContextState;
using SDL_GLContext = SDL_GLContextState*;
SDL_GLContext SDL_GL_CreateContext(SDL_Window* window);
bool SDL_GL_MakeCurrent(SDL_Window* window, SDL_GLContext context);
bool SDL_GL_DestroyContext(SDL_GLContext context);
using SDL_FunctionPointer = void (*)();
bool SDL_GL_LoadLibrary(const char* path);
void SDL_GL_UnloadLibrary();
SDL_FunctionPointer SDL_GL_GetProcAddress(const char* name);

using SDL_GLAttr = int;
inline constexpr SDL_GLAttr SDL_GL_CONTEXT_MAJOR_VERSION = 0;
inline constexpr SDL_GLAttr SDL_GL_CONTEXT_MINOR_VERSION = 1;
inline constexpr SDL_GLAttr SDL_GL_CONTEXT_PROFILE_MASK = 2;
inline constexpr SDL_GLAttr SDL_GL_DOUBLEBUFFER = 3;
inline constexpr SDL_GLAttr SDL_GL_FRAMEBUFFER_SRGB_CAPABLE = 4;
inline constexpr int SDL_GL_CONTEXT_PROFILE_CORE = 1;
bool SDL_GL_SetAttribute(SDL_GLAttr attr, int value);

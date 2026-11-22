#include "poko/rhi/device/vulkan_clear_android.hpp"
#if defined(__ANDROID__)
#include <vulkan/vulkan.h>
#include <vulkan/vulkan_android.h>
#include <android/log.h>
#include <android/native_window.h>
#include <array>
#include <cstdio>
#include <cstdint>
#include <new>
#include <vector>
namespace poko::rhi {
struct VulkanClearAndroidRenderer::Impl {
  VkInstance instance = VK_NULL_HANDLE;
  VkPhysicalDevice physical = VK_NULL_HANDLE;
  VkDevice device = VK_NULL_HANDLE;
  VkQueue queue = VK_NULL_HANDLE;
  uint32_t queue_family = 0;
  VkSurfaceKHR surface = VK_NULL_HANDLE;
  VkSwapchainKHR swapchain = VK_NULL_HANDLE;
  VkFormat format = VK_FORMAT_UNDEFINED;
  VkColorSpaceKHR color_space = VK_COLOR_SPACE_SRGB_NONLINEAR_KHR;
  VkExtent2D extent{0, 0};
  std::vector<VkImage> images;
  std::vector<VkFramebuffer> framebuffers;
  std::vector<VkImageView> image_views;
  VkRenderPass render_pass = VK_NULL_HANDLE;
  VkCommandPool command_pool = VK_NULL_HANDLE;
  VkCommandBuffer command_buffer = VK_NULL_HANDLE;
  VkFence fence = VK_NULL_HANDLE;
  VkSemaphore image_available = VK_NULL_HANDLE;
  VkSemaphore render_finished = VK_NULL_HANDLE;
  void* window = nullptr;
  uint32_t width = 0, height = 0;
  bool initialized = false;
};
namespace {
using Impl = VulkanClearAndroidRenderer::Impl;
bool make_instance(Impl& p) {
  VkApplicationInfo app{};
  app.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
  app.apiVersion = VK_API_VERSION_1_1;
  const char* exts[] = {VK_KHR_SURFACE_EXTENSION_NAME, VK_KHR_ANDROID_SURFACE_EXTENSION_NAME};
  VkInstanceCreateInfo ci{VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO};
  ci.pApplicationInfo = &app;
  ci.enabledExtensionCount = 2;
  ci.ppEnabledExtensionNames = exts;
  return vkCreateInstance(&ci, nullptr, &p.instance) == VK_SUCCESS;
}
bool make_surface(Impl& p) {
  VkAndroidSurfaceCreateInfoKHR sci{VK_STRUCTURE_TYPE_ANDROID_SURFACE_CREATE_INFO_KHR};
  sci.window = static_cast<ANativeWindow*>(p.window);
  return vkCreateAndroidSurfaceKHR(p.instance, &sci, nullptr, &p.surface) == VK_SUCCESS;
}
bool pick_device(Impl& p) {
  uint32_t count = 0;
  if (vkEnumeratePhysicalDevices(p.instance, &count, nullptr) != VK_SUCCESS || !count) return false;
  std::vector<VkPhysicalDevice> devices(count);
  if (vkEnumeratePhysicalDevices(p.instance, &count, devices.data()) != VK_SUCCESS) return false;
  for (auto candidate : devices) {
    uint32_t qcount = 0;
    vkGetPhysicalDeviceQueueFamilyProperties(candidate, &qcount, nullptr);
    std::vector<VkQueueFamilyProperties> queues(qcount);
    vkGetPhysicalDeviceQueueFamilyProperties(candidate, &qcount, queues.data());
    for (uint32_t i = 0; i < qcount; ++i) {
      VkBool32 present = VK_FALSE;
      vkGetPhysicalDeviceSurfaceSupportKHR(candidate, i, p.surface, &present);
      if ((queues[i].queueFlags & VK_QUEUE_GRAPHICS_BIT) && present) {
        p.physical = candidate; p.queue_family = i;
        return true;
      }
    }
  }
  return false;
}
bool pick_surface_format(Impl& p) {
  uint32_t count = 0;
  vkGetPhysicalDeviceSurfaceFormatsKHR(p.physical, p.surface, &count, nullptr);
  if (!count) return false;
  std::vector<VkSurfaceFormatKHR> formats(count);
  vkGetPhysicalDeviceSurfaceFormatsKHR(p.physical, p.surface, &count, formats.data());
  VkSurfaceFormatKHR chosen = formats[0];
  if (count == 1 && chosen.format == VK_FORMAT_UNDEFINED) chosen.format = VK_FORMAT_R8G8B8A8_UNORM;
  for (const auto& f : formats) {
    if (f.colorSpace == VK_COLOR_SPACE_SRGB_NONLINEAR_KHR &&
        (f.format == VK_FORMAT_B8G8R8A8_UNORM || f.format == VK_FORMAT_R8G8B8A8_UNORM)) {
      chosen = f; break;
    }
  }
  p.format = chosen.format;
  p.color_space = chosen.colorSpace;
  return true;
}
bool make_device_objects(Impl& p) {
  const float priority = 1.0f;
  VkDeviceQueueCreateInfo qci{VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO};
  qci.queueFamilyIndex = p.queue_family;
  qci.queueCount = 1;
  qci.pQueuePriorities = &priority;
  const char* dev_exts[] = {VK_KHR_SWAPCHAIN_EXTENSION_NAME};
  VkDeviceCreateInfo dci{VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO};
  dci.queueCreateInfoCount = 1;
  dci.pQueueCreateInfos = &qci;
  dci.enabledExtensionCount = 1;
  dci.ppEnabledExtensionNames = dev_exts;
  if (vkCreateDevice(p.physical, &dci, nullptr, &p.device) != VK_SUCCESS) return false;
  vkGetDeviceQueue(p.device, p.queue_family, 0, &p.queue);
  VkCommandPoolCreateInfo pci{VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO};
  pci.flags = VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT;
  pci.queueFamilyIndex = p.queue_family;
  if (vkCreateCommandPool(p.device, &pci, nullptr, &p.command_pool) != VK_SUCCESS) return false;
  VkCommandBufferAllocateInfo cai{VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO};
  cai.commandPool = p.command_pool;
  cai.level = VK_COMMAND_BUFFER_LEVEL_PRIMARY;
  cai.commandBufferCount = 1;
  if (vkAllocateCommandBuffers(p.device, &cai, &p.command_buffer) != VK_SUCCESS) return false;
  VkFenceCreateInfo fci{VK_STRUCTURE_TYPE_FENCE_CREATE_INFO};
  fci.flags = VK_FENCE_CREATE_SIGNALED_BIT;
  if (vkCreateFence(p.device, &fci, nullptr, &p.fence) != VK_SUCCESS) return false;
  VkSemaphoreCreateInfo sci{VK_STRUCTURE_TYPE_SEMAPHORE_CREATE_INFO};
  if (vkCreateSemaphore(p.device, &sci, nullptr, &p.image_available) != VK_SUCCESS) return false;
  if (vkCreateSemaphore(p.device, &sci, nullptr, &p.render_finished) != VK_SUCCESS) return false;
  VkAttachmentDescription attach{};
  attach.format = p.format;
  attach.samples = VK_SAMPLE_COUNT_1_BIT;
  attach.loadOp = VK_ATTACHMENT_LOAD_OP_CLEAR;
  attach.storeOp = VK_ATTACHMENT_STORE_OP_STORE;
  attach.stencilLoadOp = VK_ATTACHMENT_LOAD_OP_DONT_CARE;
  attach.stencilStoreOp = VK_ATTACHMENT_STORE_OP_DONT_CARE;
  attach.initialLayout = VK_IMAGE_LAYOUT_UNDEFINED;
  attach.finalLayout = VK_IMAGE_LAYOUT_PRESENT_SRC_KHR;
  VkAttachmentReference ref{0, VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL};
  VkSubpassDescription sub{};
  sub.pipelineBindPoint = VK_PIPELINE_BIND_POINT_GRAPHICS;
  sub.colorAttachmentCount = 1;
  sub.pColorAttachments = &ref;
  VkRenderPassCreateInfo rpci{VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO};
  rpci.attachmentCount = 1;
  rpci.pAttachments = &attach;
  rpci.subpassCount = 1;
  rpci.pSubpasses = &sub;
  return vkCreateRenderPass(p.device, &rpci, nullptr, &p.render_pass) == VK_SUCCESS;
}
void destroy_swapchain_resources(Impl& p) {
  if (!p.device) return;
  for (auto fb : p.framebuffers) if (fb) vkDestroyFramebuffer(p.device, fb, nullptr);
  for (auto v : p.image_views) if (v) vkDestroyImageView(p.device, v, nullptr);
  p.framebuffers.clear();
  p.image_views.clear();
  p.images.clear();
  if (p.swapchain) { vkDestroySwapchainKHR(p.device, p.swapchain, nullptr); p.swapchain = VK_NULL_HANDLE; }
}
bool make_swapchain(Impl& p) {
  VkSurfaceCapabilitiesKHR caps{};
  if (vkGetPhysicalDeviceSurfaceCapabilitiesKHR(p.physical, p.surface, &caps) != VK_SUCCESS) return false;
  VkExtent2D extent = caps.currentExtent;
  if (extent.width == 0xFFFFFFFFU) extent = {p.width, p.height};
  if (extent.width == 0 || extent.height == 0) return false;
  uint32_t image_count = caps.minImageCount + 1;
  if (caps.maxImageCount && image_count > caps.maxImageCount) image_count = caps.maxImageCount;
  VkSwapchainCreateInfoKHR sci{VK_STRUCTURE_TYPE_SWAPCHAIN_CREATE_INFO_KHR};
  sci.surface = p.surface;
  sci.minImageCount = image_count;
  sci.imageFormat = p.format;
  sci.imageColorSpace = p.color_space;
  sci.imageExtent = extent;
  sci.imageArrayLayers = 1;
  sci.imageUsage = VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT;
  sci.imageSharingMode = VK_SHARING_MODE_EXCLUSIVE;
  sci.preTransform = caps.currentTransform;
  sci.compositeAlpha = VK_COMPOSITE_ALPHA_OPAQUE_BIT_KHR;
  sci.presentMode = VK_PRESENT_MODE_FIFO_KHR;
  sci.clipped = VK_TRUE;
  if (vkCreateSwapchainKHR(p.device, &sci, nullptr, &p.swapchain) != VK_SUCCESS) return false;
  p.extent = extent;
  uint32_t icount = 0;
  vkGetSwapchainImagesKHR(p.device, p.swapchain, &icount, nullptr);
  p.images.resize(icount);
  if (vkGetSwapchainImagesKHR(p.device, p.swapchain, &icount, p.images.data()) != VK_SUCCESS)
    return false;
  VkImageViewCreateInfo vci{VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO};
  vci.viewType = VK_IMAGE_VIEW_TYPE_2D;
  vci.format = p.format;
  vci.subresourceRange = {VK_IMAGE_ASPECT_COLOR_BIT, 0, 1, 0, 1};
  VkFramebufferCreateInfo fbci{VK_STRUCTURE_TYPE_FRAMEBUFFER_CREATE_INFO};
  fbci.renderPass = p.render_pass;
  fbci.attachmentCount = 1;
  fbci.width = extent.width;
  fbci.height = extent.height;
  fbci.layers = 1;
  for (auto image : p.images) {
    VkImageView view = VK_NULL_HANDLE;
    vci.image = image;
    if (vkCreateImageView(p.device, &vci, nullptr, &view) != VK_SUCCESS) return false;
    fbci.pAttachments = &view;
    VkFramebuffer fb = VK_NULL_HANDLE;
    if (vkCreateFramebuffer(p.device, &fbci, nullptr, &fb) != VK_SUCCESS) {
      vkDestroyImageView(p.device, view, nullptr);
      return false;
    }
    p.framebuffers.push_back(fb);
    // view ownership transfers to the framebuffer; keep for teardown below
    p.image_views.push_back(view);
  }
  return true;
}
}
VulkanClearAndroidRenderer::VulkanClearAndroidRenderer() noexcept = default;
VulkanClearAndroidRenderer::~VulkanClearAndroidRenderer() { shutdown(); }
RenderError VulkanClearAndroidRenderer::initialize(void* window, uint32_t w, uint32_t h) noexcept {
  if (impl_) return RenderError::already_initialized;
  if (!window || !w || !h) return RenderError::invalid_window;
  impl_ = new (std::nothrow) Impl{};
  if (!impl_) return RenderError::device_creation_failed;
  impl_->window = window; impl_->width = w; impl_->height = h;
  auto* p = impl_;
  bool ok = make_instance(*p) && make_surface(*p) && pick_device(*p) &&
            pick_surface_format(*p) && make_device_objects(*p) && make_swapchain(*p);
  if (!ok) { shutdown(); return RenderError::device_creation_failed; }
  p->initialized = true;
  return RenderError::none;
}
RenderError VulkanClearAndroidRenderer::clear_and_present(const std::array<float,4>& color) noexcept {
  if (!impl_ || !impl_->initialized) return RenderError::not_initialized;
  auto* p = impl_;
  vkWaitForFences(p->device, 1, &p->fence, VK_TRUE, UINT64_MAX);
  vkResetFences(p->device, 1, &p->fence); // fence must be unsignaled before re-submit
  uint32_t index = 0;
  const auto acquired = vkAcquireNextImageKHR(p->device, p->swapchain, UINT64_MAX,
                                              p->image_available, VK_NULL_HANDLE, &index);
  if (acquired == VK_ERROR_OUT_OF_DATE_KHR) {
    __android_log_write(ANDROID_LOG_WARN, "poko_vulkan", "acquire OUT_OF_DATE; recreating swapchain");
    destroy_swapchain_resources(*p);
    if (!make_swapchain(*p)) {
      __android_log_write(ANDROID_LOG_ERROR, "poko_vulkan", "swapchain recreate failed");
      return RenderError::backend_failure;
    }
    return clear_and_present(color);
  }
  if (acquired != VK_SUCCESS) {
    char dbg[96];
    std::snprintf(dbg, sizeof dbg, "vk acquire VkResult=%d", static_cast<int>(acquired));
    __android_log_write(ANDROID_LOG_ERROR, "poko_vulkan", dbg);
    return RenderError::backend_failure;
  }
  VkClearValue clear{};
  clear.color.float32[0] = color[0]; clear.color.float32[1] = color[1];
  clear.color.float32[2] = color[2]; clear.color.float32[3] = color[3];
  VkRenderPassBeginInfo rpbi{VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO};
  rpbi.renderPass = p->render_pass;
  rpbi.framebuffer = p->framebuffers[index];
  rpbi.renderArea.extent = p->extent;
  rpbi.clearValueCount = 1;
  rpbi.pClearValues = &clear;
  vkResetCommandBuffer(p->command_buffer, 0);
  VkCommandBufferBeginInfo cbbi{VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO};
  vkBeginCommandBuffer(p->command_buffer, &cbbi);
  vkCmdBeginRenderPass(p->command_buffer, &rpbi, VK_SUBPASS_CONTENTS_INLINE);
  vkCmdEndRenderPass(p->command_buffer);
  vkEndCommandBuffer(p->command_buffer);
  VkPipelineStageFlags wait_stage = VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT;
  VkSubmitInfo si{VK_STRUCTURE_TYPE_SUBMIT_INFO};
  si.waitSemaphoreCount = 1;
  si.pWaitSemaphores = &p->image_available;
  si.pWaitDstStageMask = &wait_stage;
  si.commandBufferCount = 1;
  si.pCommandBuffers = &p->command_buffer;
  si.signalSemaphoreCount = 1;
  si.pSignalSemaphores = &p->render_finished;
  const auto submitted = vkQueueSubmit(p->queue, 1, &si, p->fence);
  if (submitted != VK_SUCCESS) {
    char dbg[96];
    std::snprintf(dbg, sizeof dbg, "vk queue submit VkResult=%d", static_cast<int>(submitted));
    __android_log_write(ANDROID_LOG_ERROR, "poko_vulkan", dbg);
    return RenderError::backend_failure;
  }
  VkPresentInfoKHR pi{VK_STRUCTURE_TYPE_PRESENT_INFO_KHR};
  pi.waitSemaphoreCount = 1;
  pi.pWaitSemaphores = &p->render_finished;
  pi.swapchainCount = 1;
  pi.pSwapchains = &p->swapchain;
  pi.pImageIndices = &index;
  const auto pres = vkQueuePresentKHR(p->queue, &pi);
  if (pres != VK_SUCCESS && pres != VK_SUBOPTIMAL_KHR) {
    char dbg[96];
    std::snprintf(dbg, sizeof dbg, "vk present VkResult=%d", static_cast<int>(pres));
    __android_log_write(ANDROID_LOG_ERROR, "poko_vulkan", dbg);
  }
  if (pres == VK_ERROR_OUT_OF_DATE_KHR) {
    __android_log_write(ANDROID_LOG_WARN, "poko_vulkan", "present OUT_OF_DATE; recreating swapchain");
    // Surface changed (rotation/resize/composition): rebuild and retry once.
    destroy_swapchain_resources(*p);
    if (!make_swapchain(*p)) {
      __android_log_write(ANDROID_LOG_ERROR, "poko_vulkan", "swapchain recreate failed");
      return RenderError::backend_failure;
    }
    return clear_and_present(color);
  }
  if (pres == VK_SUBOPTIMAL_KHR) {
    __android_log_write(ANDROID_LOG_WARN, "poko_vulkan", "present SUBOPTIMAL");
    return RenderError::none; // presented; recreate lazily next frame
  }
  if (pres != VK_SUCCESS) return RenderError::backend_failure;
  return RenderError::none;
}
void VulkanClearAndroidRenderer::shutdown() noexcept {
  if (!impl_) return;
  auto* p = impl_;
  p->initialized = false;
  if (p->device != VK_NULL_HANDLE) {
    vkDeviceWaitIdle(p->device);
    if (p->swapchain) vkDestroySwapchainKHR(p->device, p->swapchain, nullptr);
    for (auto fb : p->framebuffers) if (fb) vkDestroyFramebuffer(p->device, fb, nullptr);
    for (auto v : p->image_views) if (v) vkDestroyImageView(p->device, v, nullptr);
    if (p->render_pass) vkDestroyRenderPass(p->device, p->render_pass, nullptr);
    if (p->command_pool) vkDestroyCommandPool(p->device, p->command_pool, nullptr);
    if (p->fence) vkDestroyFence(p->device, p->fence, nullptr);
    if (p->image_available) vkDestroySemaphore(p->device, p->image_available, nullptr);
    if (p->render_finished) vkDestroySemaphore(p->device, p->render_finished, nullptr);
    vkDestroyDevice(p->device, nullptr);
  }
  if (p->surface) vkDestroySurfaceKHR(p->instance, p->surface, nullptr);
  if (p->instance) vkDestroyInstance(p->instance, nullptr);
  delete p;
  impl_ = nullptr;
}
bool VulkanClearAndroidRenderer::shutdown_checked() noexcept {
  if (cleanup_uncertain_) return false;
  shutdown();
  return true;
}
} // namespace poko::rhi
#else
#include <new>
namespace poko::rhi {
struct VulkanClearAndroidRenderer::Impl {};
VulkanClearAndroidRenderer::VulkanClearAndroidRenderer() noexcept = default;
VulkanClearAndroidRenderer::~VulkanClearAndroidRenderer() = default;
RenderError VulkanClearAndroidRenderer::initialize(void*, std::uint32_t, std::uint32_t) noexcept { return RenderError::unsupported_window_system; }
RenderError VulkanClearAndroidRenderer::clear_and_present(const std::array<float,4>&) noexcept { return RenderError::not_initialized; }
void VulkanClearAndroidRenderer::shutdown() noexcept {}
bool VulkanClearAndroidRenderer::shutdown_checked() noexcept { return true; }
}
#endif

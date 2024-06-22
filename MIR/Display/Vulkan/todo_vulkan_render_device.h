#ifndef DISPLAY_RENDER_DEVICE_H_INCLUDED
#define DISPLAY_RENDER_DEVICE_H_INCLUDED

// TODO : make abstract and create : vk_todo_vulkan_render_device / dx12_todo_vulkan_render_device

namespace mir
{
	struct todo_vulkan_render_device
	{
	public:
		todo_vulkan_render_device();
		todo_vulkan_render_device( VkPhysicalDevice _physical_device, VkDevice _logical_device, VkQueue _graphics_queue, VkQueue _present_queue );

		VkPhysicalDevice m_physical_device;
		VkQueue m_graphics_queue;
		VkQueue m_present_queue;
		VkDevice m_logical_device;
	};

	class todo_vulkan_render_device_factory
	{
	public:
		static todo_vulkan_render_device create_todo_vulkan_render_device( VkSurfaceKHR _surface );
		static void release_todo_vulkan_render_device( todo_vulkan_render_device& _device );
	};
}

#endif // DISPLAY_RENDER_DEVICE_H_INCLUDED

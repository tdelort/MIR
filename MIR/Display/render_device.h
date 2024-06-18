#ifndef DISPLAY_RENDER_DEVICE_H_INCLUDED
#define DISPLAY_RENDER_DEVICE_H_INCLUDED

// TODO : make abstract and create : vk_render_device / dx12_render_device

namespace mir
{

	// TODO Make static and behind a lock
	struct render_device
	{
	public:
		render_device();
		render_device( VkPhysicalDevice _physical_device, VkDevice _logical_device, VkQueue _graphics_queue, VkQueue _present_queue );

		VkPhysicalDevice m_physical_device;
		VkQueue m_graphics_queue;
		VkQueue m_present_queue;
		VkDevice m_logical_device;
	};

	class render_device_factory
	{
	public:
		static render_device create_render_device( VkSurfaceKHR _surface );
		static void release_render_device( render_device& _device );
	};
}

#endif // DISPLAY_RENDER_DEVICE_H_INCLUDED

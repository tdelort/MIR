#pragma once

// TODO : make abstract and create : vk_render_device / dx12_render_device

namespace mir
{

	// TODO Make static and behind a lock
	class render_device
	{
	public:
		render_device( VkPhysicalDevice _physical_device, VkDevice _logical_device, VkQueue _graphics_queue );

	private:
		VkPhysicalDevice m_physical_device;
		VkQueue m_graphics_queue;
		VkDevice m_logical_device;
	};

	class render_device_factory
	{
		static render_device create_render_device();
	};
}

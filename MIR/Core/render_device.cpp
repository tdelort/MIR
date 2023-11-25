#include "render_device.h"
#include "rendering_system.h"

namespace mir
{
	render_device::render_device( VkPhysicalDevice _physical_device, VkDevice _logical_device, VkQueue _graphics_queue )
		: m_physical_device{ _physical_device }
		, m_logical_device{ _logical_device }
		, m_graphics_queue{ _graphics_queue }
	{
	}

	// temporary struct used for render device creation

	struct queue_family_id
	{
		uint32_t m_id{ 0 };
		bool m_found{ false };
	};

	struct queue_families
	{
		queue_family_id m_graphics_queue;

		bool is_complete()
		{
			return m_graphics_queue.m_found;
		}
	};

	unsigned int get_physical_device_score(const VkPhysicalDevice _device, queue_families& _queue_families_out )
	{
		unsigned int score = 0;
		// Checking device properties
		VkPhysicalDeviceProperties device_properties;
		vkGetPhysicalDeviceProperties(_device, &device_properties);

		if (device_properties.deviceType == VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU)
			score += 10;

		// Checking device features
		VkPhysicalDeviceFeatures device_features;
		vkGetPhysicalDeviceFeatures(_device, &device_features);

		// Enumerating device queue families
		queue_families device_queues;

		uint32_t queue_family_count = 0;
		vkGetPhysicalDeviceQueueFamilyProperties(_device, &queue_family_count, nullptr);
		std::vector<VkQueueFamilyProperties> queue_families(queue_family_count);
		vkGetPhysicalDeviceQueueFamilyProperties(_device, &queue_family_count, queue_families.data());

		for (int i = 0; i < queue_families.size(); ++i)
		{
			const VkQueueFamilyProperties& queue_property = queue_families[i];
			if (queue_property.queueFlags & VK_QUEUE_GRAPHICS_BIT)
			{
				device_queues.m_graphics_queue.m_id = i;
				device_queues.m_graphics_queue.m_found = true;

				if (device_queues.is_complete())
					break;
			}
		}

		_queue_families_out = device_queues;

		if (!device_queues.is_complete())
			return 0;

		return score;
	}
	render_device render_device_factory::create_render_device()
	{
		VkPhysicalDevice chosen_physical_device = VK_NULL_HANDLE;
		queue_families chosen_queue_families;
	
		VkInstance& vulkan_instance = rendering_system::instance().get_vulkan_instance();

		{
			uint32_t device_count = 0u;
			vkEnumeratePhysicalDevices(vulkan_instance, &device_count, nullptr);

			MIR_ASSERT(device_count != 0u, "Could not find a suitable device with Vulkan support!");
			
			std::vector<VkPhysicalDevice> devices(device_count);
			vkEnumeratePhysicalDevices(vulkan_instance, &device_count, devices.data());

			unsigned int max_score = 0;
			for (const VkPhysicalDevice& device : devices)
			{
				queue_families device_queue_families;
				unsigned int device_score = get_physical_device_score(device, device_queue_families);
				if (device_score > max_score)
				{
					max_score = device_score;
					chosen_physical_device = device;
					chosen_queue_families = device_queue_families;
				}
			}
			
			MIR_ASSERT(chosen_physical_device != VK_NULL_HANDLE, "No physical render device had the wanted requirements for this application");
		}

		VkDevice logical_device;
		VkQueue graphics_queue;
		{
			VkDeviceQueueCreateInfo queueCreateInfo{};
			queueCreateInfo.sType = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
			queueCreateInfo.queueFamilyIndex = chosen_queue_families.m_graphics_queue.m_id;
			queueCreateInfo.queueCount = 1;
			float queuePriority = 1.0f;
			queueCreateInfo.pQueuePriorities = &queuePriority;

			VkPhysicalDeviceFeatures deviceFeatures{};

			VkDeviceCreateInfo createInfo{};
			createInfo.sType = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO;
			createInfo.pQueueCreateInfos = &queueCreateInfo;
			createInfo.queueCreateInfoCount = 1;
			createInfo.pEnabledFeatures = &deviceFeatures;

			createInfo.enabledExtensionCount = 0;

#if defined(MIR_RENDER_USE_VALIDATION_LAYERS)
			const std::vector<const char*>& validation_layers = rendering_system::instance().get_vulkan_validation_layers();
			createInfo.enabledLayerCount = static_cast<uint32_t>(validation_layers.size());
			createInfo.ppEnabledLayerNames = validation_layers.data();
#else // defined(MIR_RENDER_USE_VALIDATION_LAYERS)
			createInfo.enabledLayerCount = 0;
#endif // defined(MIR_RENDER_USE_VALIDATION_LAYERS)

			VkResult res = vkCreateDevice(chosen_physical_device, &createInfo, nullptr, &logical_device);
			MIR_ASSERT(res == VK_SUCCESS, "Failed to create logical device");

			vkGetDeviceQueue(logical_device, chosen_queue_families.m_graphics_queue.m_id, 0, &graphics_queue);
		}

		return render_device(chosen_physical_device, logical_device, graphics_queue);
	}

}

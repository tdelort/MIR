#include "render_device.h"
#include "rendering_system.h"

namespace mir
{
	render_device::render_device()
		: render_device( nullptr, nullptr, nullptr, nullptr )
	{ }

	render_device::render_device( VkPhysicalDevice _physical_device, VkDevice _logical_device, VkQueue _graphics_queue, VkQueue _present_queue )
		: m_physical_device{ _physical_device }
		, m_logical_device{ _logical_device }
		, m_graphics_queue{ _graphics_queue }
		, m_present_queue{ _present_queue }
	{ }

	// temporary struct used for render device creation

	struct queue_family_id
	{
		uint32_t m_id{ 0 };
		bool m_found{ false };
	};

	struct queue_families
	{
		queue_family_id m_graphics_queue;
		queue_family_id m_present_queue;

		bool is_complete()
		{
			return m_graphics_queue.m_found && m_present_queue.m_found;
		}
	};

	static constexpr std::array<const char*, 1> s_device_mandatory_extension
	{
		VK_KHR_SWAPCHAIN_EXTENSION_NAME
	};

	bool is_device_suitable(const VkPhysicalDevice _device)
	{

		uint32_t extension_count;
		vkEnumerateDeviceExtensionProperties( _device, nullptr, &extension_count, nullptr);
		std::vector<VkExtensionProperties> available_extensions(extension_count);
		vkEnumerateDeviceExtensionProperties( _device, nullptr, &extension_count, available_extensions.data() );

		std::set<std::string> requiredExtensions( s_device_mandatory_extension.cbegin(), s_device_mandatory_extension.cend() );

		for (const VkExtensionProperties& extension : available_extensions)
		{
			requiredExtensions.erase( extension.extensionName );
		}

		return requiredExtensions.empty();
	}

	unsigned int get_physical_device_score(const VkPhysicalDevice _device, const VkSurfaceKHR _surface, queue_families& _queue_families_out )
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
			}

			VkBool32 present_support = false;
			vkGetPhysicalDeviceSurfaceSupportKHR( _device, i, _surface, &present_support);
			if (present_support)
			{
				device_queues.m_present_queue.m_id = i;
				device_queues.m_present_queue.m_found = true;
			}

			if (device_queues.is_complete())
				break;
		}

		_queue_families_out = device_queues;

		if (!device_queues.is_complete())
			return 0;

		return score;
	}

	render_device render_device_factory::create_render_device( VkSurfaceKHR _surface )
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
				if (!is_device_suitable(device))
					continue;

				queue_families device_queue_families;
				unsigned int device_score = get_physical_device_score(device, _surface, device_queue_families);
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
		VkQueue present_queue;
		{
			std::set<uint32_t> unique_queue_families = { chosen_queue_families.m_graphics_queue.m_id, chosen_queue_families.m_present_queue.m_id };
			std::vector<VkDeviceQueueCreateInfo> queue_create_infos;

			float queuePriority = 1.0f;
			for (uint32_t queue_family : unique_queue_families)
			{
				VkDeviceQueueCreateInfo queue_create_info{};
				queue_create_info.sType = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
				queue_create_info.queueFamilyIndex = queue_family;
				queue_create_info.queueCount = 1;
				queue_create_info.pQueuePriorities = &queuePriority;
				queue_create_infos.push_back(queue_create_info);
			}


			VkPhysicalDeviceFeatures deviceFeatures{};

			VkDeviceCreateInfo createInfo{};
			createInfo.sType = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO;
			createInfo.pQueueCreateInfos = queue_create_infos.data();
			createInfo.queueCreateInfoCount = static_cast<uint32_t>( queue_create_infos.size() );
			createInfo.pEnabledFeatures = &deviceFeatures;

			createInfo.enabledExtensionCount = static_cast<uint32_t>( s_device_mandatory_extension.size() );
			createInfo.ppEnabledExtensionNames = s_device_mandatory_extension.data();

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
			vkGetDeviceQueue(logical_device, chosen_queue_families.m_present_queue.m_id, 0, &present_queue);
		}

		return render_device(chosen_physical_device, logical_device, graphics_queue, present_queue);
	}

	void render_device_factory::release_render_device( render_device& _device )
	{
		vkDestroyDevice(_device.m_logical_device, nullptr);
	}
}

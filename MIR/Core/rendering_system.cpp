#include "rendering_system.h"
#include "render_device.h"


// TODO : move most of rendering system in a vulkan system and abstract it here (to later support different systems)
namespace mir
{
#if defined(MIR_RENDER_USE_VALIDATION_LAYERS)
	VKAPI_ATTR VkBool32 VKAPI_CALL debug_callback(VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity, VkDebugUtilsMessageTypeFlagsEXT messageType, const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData, void* pUserData)
	{
		std::ostringstream out;
		out << "Vulkan validation layers : " << pCallbackData->pMessage << "\n";
		switch (messageSeverity)
		{
			case VK_DEBUG_UTILS_MESSAGE_SEVERITY_VERBOSE_BIT_EXT:
			{
				MIR_LOG_DEBUG(out.str());
				break;
			}
			case VK_DEBUG_UTILS_MESSAGE_SEVERITY_INFO_BIT_EXT:
			{
				MIR_LOG(out.str());
				break;
			}
			case VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT:
			{
				MIR_LOG_WARNING(out.str());
				break;
			}
			case VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT:
			{
				MIR_LOG_ERROR(out.str());
				break;
			}
		}

		return VK_FALSE;
	}
#endif // MIR_RENDER_USE_VALIDATION_LAYER

	rendering_system::rendering_system()
		: m_instance{}
	{

	}

	void rendering_system::init()
	{
		create_instance();
#if defined(MIR_RENDER_USE_VALIDATION_LAYERS)
		create_debug_messenger();
#endif // MIR_RENDER_USE_VALIDATION_LAYERS
		render_device device = render_device_factory::create_render_device();
	}

	void rendering_system::cleanup()
	{

#if defined(MIR_RENDER_USE_VALIDATION_LAYERS)
		destroy_debug_messenger();
#endif // MIR_RENDER_USE_VALIDATION_LAYERS
		destroy_instance();
	}

	void rendering_system::create_instance()
	{
#if defined(MIR_RENDER_USE_VALIDATION_LAYERS)
		MIR_ASSERT(check_validation_layer_support(), "Could not load all validation layers selected");
#endif // MIR_RENDER_USE_VALIDATION_LAYERS
		
		VkApplicationInfo app_info{};
		app_info.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
		app_info.pApplicationName = "Hello Triangle";
		app_info.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
		app_info.pEngineName = "No Engine";
		app_info.engineVersion = VK_MAKE_VERSION(1, 0, 0);
		app_info.apiVersion = VK_API_VERSION_1_0;

		std::vector<const char*> extensions = list_required_extensions();
		VkInstanceCreateInfo create_info{};
		create_info.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
		create_info.pApplicationInfo = &app_info;
		create_info.enabledExtensionCount = static_cast<uint32_t>(extensions.size());
		create_info.ppEnabledExtensionNames = extensions.data();
#if defined(MIR_RENDER_USE_VALIDATION_LAYERS)
		create_info.enabledLayerCount = static_cast<uint32_t>(m_validation_layers.size());
		create_info.ppEnabledLayerNames = m_validation_layers.data();

		VkDebugUtilsMessengerCreateInfoEXT messenger_create_info{};
		messenger_create_info.sType = VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT;
		messenger_create_info.messageSeverity = VK_DEBUG_UTILS_MESSAGE_SEVERITY_VERBOSE_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_SEVERITY_INFO_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT;
		messenger_create_info.messageType = VK_DEBUG_UTILS_MESSAGE_TYPE_GENERAL_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_TYPE_PERFORMANCE_BIT_EXT;
		messenger_create_info.pfnUserCallback = debug_callback;
		messenger_create_info.pUserData = nullptr;
		create_info.pNext = (VkDebugUtilsMessengerCreateInfoEXT*)&messenger_create_info;
#else // MIR_RENDER_USE_VALIDATION_LAYERS
		createInfo.enabledLayerCount = 0u;
		createInfo.pNext = nullptr;
#endif // MIR_RENDER_USE_VALIDATION_LAYERS

		VkResult res = vkCreateInstance(&create_info, nullptr, &m_instance);
		MIR_ASSERT(res == VK_SUCCESS, "Could not create vulkan instance");
	}

	void rendering_system::destroy_instance()
	{
		vkDestroyInstance(m_instance, nullptr);
	}


	std::vector<const char*> rendering_system::list_required_extensions()
	{
		// TODO put this into the windowing_system
		uint32_t glfw_extension_count = 0u;
		const char** glfw_extensions = glfwGetRequiredInstanceExtensions(&glfw_extension_count);

		std::vector<const char*> extensions(glfw_extensions, glfw_extensions + glfw_extension_count);

#if defined(MIR_RENDER_USE_VALIDATION_LAYERS)
		extensions.push_back(VK_EXT_DEBUG_UTILS_EXTENSION_NAME);
#endif // MIR_RENDER_USE_VALIDATION_LAYERS

		return extensions;
	}


#if defined(MIR_RENDER_USE_VALIDATION_LAYERS)
	bool rendering_system::check_validation_layer_support()
	{
		uint32_t layer_count;
		vkEnumerateInstanceLayerProperties(&layer_count, nullptr);
		
		std::vector<VkLayerProperties> available_layers(layer_count);
		vkEnumerateInstanceLayerProperties(&layer_count, available_layers.data());

		// TODO : meh
		for (const char* layer_name_to_find : m_validation_layers)
		{
			bool found = false;

			for (const VkLayerProperties layer_props : available_layers)
			{
				if (strcmp(layer_name_to_find, layer_props.layerName) == 0)
				{
					found = true;
					break;
				}
			}

			if (!found)
				return false;
		}

		return true;
	}

	// TODO : move in a VULKAN EXTENSION file
	VkResult create_debug_utils_messenger_ext(VkInstance instance, const VkDebugUtilsMessengerCreateInfoEXT * pCreateInfo, const VkAllocationCallbacks * pAllocator, VkDebugUtilsMessengerEXT * pDebugMessenger)
	{
		PFN_vkCreateDebugUtilsMessengerEXT func = (PFN_vkCreateDebugUtilsMessengerEXT)vkGetInstanceProcAddr(instance, "vkCreateDebugUtilsMessengerEXT");
		if (func)
			return func(instance, pCreateInfo, pAllocator, pDebugMessenger);
		else
			return VK_ERROR_EXTENSION_NOT_PRESENT;
	}

	void destroy_debug_utils_messenger_ext(VkInstance instance, VkDebugUtilsMessengerEXT pDebugMessenger, const VkAllocationCallbacks * pAllocator)
	{
		PFN_vkDestroyDebugUtilsMessengerEXT func = (PFN_vkDestroyDebugUtilsMessengerEXT)vkGetInstanceProcAddr(instance, "vkDestroyDebugUtilsMessengerEXT");
		if (func)
			func(instance, pDebugMessenger, pAllocator);
	}

	void rendering_system::create_debug_messenger()
	{
		VkDebugUtilsMessengerCreateInfoEXT create_info{};
		create_info.sType = VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT;
		create_info.messageSeverity = VK_DEBUG_UTILS_MESSAGE_SEVERITY_VERBOSE_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_SEVERITY_INFO_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT;
		create_info.messageType = VK_DEBUG_UTILS_MESSAGE_TYPE_GENERAL_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_TYPE_PERFORMANCE_BIT_EXT;
		create_info.pfnUserCallback = debug_callback;
		create_info.pUserData = nullptr;
		
		VkResult res = create_debug_utils_messenger_ext(m_instance, &create_info, nullptr, &m_debug_messenger);
		MIR_ASSERT(res == VK_SUCCESS, "Could not set the debug callback for the validation layers");
	}

	void rendering_system::destroy_debug_messenger()
	{
		destroy_debug_utils_messenger_ext(m_instance, m_debug_messenger, nullptr);
	}
#endif // MIR_RENDER_USE_VALIDATION_LAYERS


	void rendering_system::destroy_logical_device()
	{
		vkDestroyDevice(m_logical_device, nullptr);
	}
}

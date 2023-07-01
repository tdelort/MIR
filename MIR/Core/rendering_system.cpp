#include "rendering_system.h"

#include "debug.h"

namespace mir
{
	rendering_system::rendering_system()
		: m_instance{}
	{

	}

	void rendering_system::init()
	{
		create_instance();
	}

	void rendering_system::cleanup()
	{
		destroy_instance();
	}

	void rendering_system::create_instance()
	{
		VkApplicationInfo appInfo{};
		appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
		appInfo.pApplicationName = "Hello Triangle";
		appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
		appInfo.pEngineName = "No Engine";
		appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
		appInfo.apiVersion = VK_API_VERSION_1_0;


		// TODO put this into the windowing_system
		uint32_t glfwExtensionCount = 0u;
		const char** glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

		VkInstanceCreateInfo createInfo{};
		createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
		createInfo.pApplicationInfo = &appInfo;
		createInfo.enabledExtensionCount = glfwExtensionCount;
		createInfo.ppEnabledExtensionNames = glfwExtensions;
		createInfo.enabledLayerCount = 0;

		MIR_ASSERT(vkCreateInstance(&createInfo, nullptr, &m_instance) == VK_SUCCESS, "Could not create vulkan instance");
	}

	void rendering_system::destroy_instance()
	{
		vkDestroyInstance(m_instance, nullptr);
	}
}

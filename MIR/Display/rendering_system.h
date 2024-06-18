#ifndef DISPLAY_RENDERING_SYSTEM_H_INCLUDED
#define DISPLAY_RENDERING_SYSTEM_H_INCLUDED

#include <Display/render_device.h>

#ifdef _DEBUG
#define MIR_RENDER_USE_VALIDATION_LAYERS
#endif

namespace mir
{
	class rendering_system
	{
	private:
		rendering_system();

	public:
		rendering_system(const rendering_system&) = delete;
		rendering_system(rendering_system&&) = delete;
		rendering_system& operator=(const rendering_system&) = delete;
		rendering_system& operator=(rendering_system&&) = delete;

		static auto& instance()
		{
			static rendering_system instance;
			return instance;
		}

		void init( GLFWwindow* _window );
		void cleanup();

		VkInstance& get_vulkan_instance() { return m_instance; }

		const std::vector<const char*>& get_vulkan_validation_layers() { return m_validation_layers; }

	private:
		void create_instance();
		void destroy_instance();

		std::vector<const char*> list_required_extensions();

#if defined(MIR_RENDER_USE_VALIDATION_LAYERS)
		void create_debug_messenger();
		void destroy_debug_messenger();
		bool check_validation_layer_support();

		const std::vector<const char*> m_validation_layers =
		{
			"VK_LAYER_KHRONOS_validation"
		};
#endif // MIR_RENDER_USE_VALIDATION_LAYERS
		
		render_device m_device;

		VkInstance m_instance;
		VkSurfaceKHR m_surface;
		VkDebugUtilsMessengerEXT m_debug_messenger;
	};

}

#endif // DISPLAY_RENDERING_SYSTEM_H_INCLUDED

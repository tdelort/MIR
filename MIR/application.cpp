#include "application.h"

#include "Display/windowing_system.h"
//#include "Core/windowing_system.h"
//#include "Core/rendering_system.h"

namespace mir
{
	application::application()
	{
		window_factory::s_initialize_window_system();
		//windowing_system::instance().init();

		//rendering_system::instance().init( windowing_system::instance().get_window_handle() );

		//uint32_t extensionCount = 0;
		//vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);

		//std::cout << extensionCount << " extensions supported\n";

	}

	application::~application()
	{
		window_factory::s_terminate_window_system();
		//rendering_system::instance().cleanup();

		//windowing_system::instance().cleanup();
	}

	void on_window_dimensions_changed( vec2u _dims )
	{
		MIR_LOG( "Window dimensions : ( " << _dims[0] << ", " << _dims[1] << ")" );
	}

	int application::run()
	{
		callback_set<vec2u> on_framebuffer_resize;

		//windowing_system& ws = windowing_system::instance();

		window* window = window_factory::s_create_window(vec2u(640, 480));

		window->get_on_resize_event() += on_window_dimensions_changed;

		//glm::mat4 matrix;
		//glm::vec4 vec;
		//auto test = matrix * vec;

		while(window->is_open()) 
		{
			window->poll_events();
		}
		return 0;
	}
}

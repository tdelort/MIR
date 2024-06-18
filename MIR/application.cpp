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

	int application::run()
	{
		//windowing_system& ws = windowing_system::instance();

		window* window = window_factory::s_create_window(vec2u(640, 480));

		//glm::mat4 matrix;
		//glm::vec4 vec;
		//auto test = matrix * vec;

		//while(ws.is_open()) 
		//{
		//	ws.poll_events();
		//}
		return 0;
	}
}

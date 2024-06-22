#include "application.h"

#include "Display/windowing_service.h"
//#include "Core/windowing_service.h"
//#include "Core/todo_vulkan_rendering_service.h"

namespace mir
{
	application::application()
	{
		
		//todo_vulkan_rendering_service::instance().init( windowing_service::instance().get_window_handle() );

		//uint32_t extensionCount = 0;
		//vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);

		//std::cout << extensionCount << " extensions supported\n";

	}

	application::~application()
	{
		get_windowing_service().terminate();
	}


	windowing_service& application::get_windowing_service()
	{
		return m_windowing_service;
	}


	void on_window_dimensions_changed( vec2u _dims )
	{
		MIR_LOG( "Window dimensions : ( " << _dims[0] << ", " << _dims[1] << ")" );
	}

	int application::run()
	{
		//windowing_service& ws = windowing_service::instance();

		window* window = get_windowing_service().create_window( vec2u(640, 480) );

		window->get_on_resize_event() += on_window_dimensions_changed;

		while(window->is_open()) 
		{
			window->poll_events();
		}
		return 0;
	}
}

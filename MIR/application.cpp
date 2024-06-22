#include "application.h"

#include "Display/windowing_service.h"
#include "Display/glfw/glfw_windowing_service.h"

namespace mir
{
	application::application() {}

	void application::init( const application_config& _config )
	{
		switch (_config.m_windowing_service_choice)
		{
			case application_config::windowing_service_type::glfw:
				m_application_services.initialize<glfw_windowing_service>();
				break;
			default:
			{
				MIR_LOG_ERROR("Windowing service backend not set in application_config");
				return;
			}
		}
	}

	void application::destroy()
	{
		m_application_services.destroy<windowing_service>();
	}

	const service_locator& application::get_service_locator()
	{
		return m_application_services;
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

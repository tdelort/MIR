#pragma once

#include "windowing_system.h"
#include "Core/callback_set.h"

#if defined( MIR_WINDOW_USE_GLFW )
#include <Display/glfw/glfw_windowing_system.h>
#endif // defined( MIR_WINDOW_USE_GLFW )


namespace mir
{
	window::on_resize_callback_set_type& window::get_on_resize_event()
	{
		return m_on_resize;
	}

	void window_factory::s_initialize_window_system()
	{
#if defined( MIR_WINDOW_USE_GLFW )
		s_glfw_initialize_window_system();
#endif // defined( MIR_WINDOW_USE_GLFW )
	}

	window* window_factory::s_create_window( vec2u _dims )
	{
#if defined( MIR_WINDOW_USE_GLFW )
		return s_glfw_create_window( _dims);
#endif // defined( MIR_WINDOW_USE_GLFW )
	}

	void window_factory::s_terminate_window_system()
	{
#if defined( MIR_WINDOW_USE_GLFW )
		s_glfw_terminate_window_system();
#endif // defined( MIR_WINDOW_USE_GLFW )
	}
}

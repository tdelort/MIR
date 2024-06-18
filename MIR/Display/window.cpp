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
}

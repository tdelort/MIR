#pragma once

#include "windowing_service.h"
#include "Core/callback_set.h"

#if defined( MIR_WINDOW_USE_GLFW )
#include <Display/glfw/glfw_windowing_service.h>
#endif // defined( MIR_WINDOW_USE_GLFW )


namespace mir
{
	window::on_resize_callback_set_type& window::get_on_resize_event()
	{
		return m_on_resize;
	}
}

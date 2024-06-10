#pragma once

#include "windowing_system.h"

namespace mir
{
	callback_set& window::get_on_resize_event()
	{
		return m_on_resize;
	}
}

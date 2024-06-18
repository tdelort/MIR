#pragma once

#include "windowing_system.h"
#include "Core/callback_set.h"

#if defined( MIR_WINDOW_USE_GLFW )
#include <Display/glfw/glfw_windowing_system.h>
#endif // defined( MIR_WINDOW_USE_GLFW )


namespace mir
{
	windowing_system::windowing_system()
		: m_impl{}
	{ }

	windowing_system::~windowing_system()
	{ }

	window& windowing_system::create_window( vec2u _dims )
	{
		return m_impl->create_window( _dims );
	}

	window& windowing_system::get_window( size_t _index );
	{
		return m_impl->get_window( _index );
	}
	size_t windowing_system::get_window_count();
	{
		return m_impl->get_window_count();
	}

	void windowing_system::destroy_window( size_t _index );
	{
		m_impl->destroy_window( _index );
	}
}

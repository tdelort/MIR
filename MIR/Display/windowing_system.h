#pragma once

#include "singleton.h"

namespace mir
{
	class window
	{
	public:
		virtual ~window() = 0;

		virtual bool is_open() const = 0;
		virtual void poll_events() = 0;
		callback_set& get_on_resize_event();
	private:

		// on_resize_callback( _pixel_coords )
		callback_set<vec2u> m_on_resize;
	};

	class windowing_system
	{
	public:
		virtual void init() = 0;
		virtual void cleanup() = 0;

		virtual window* get_window() = 0;
	};

}

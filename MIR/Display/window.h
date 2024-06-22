#ifndef DISPLAY_WINDOW_H_INCLUDED
#define DISPLAY_WINDOW_H_INCLUDED

#include "Core/core.h"
#include "Core/callback_set.h"
#include "Core/Math/vec2.h"

namespace mir
{
	class window
	{
	public:
		using on_resize_callback_set_type = callback_set<vec2u>;

		virtual ~window() = 0 {};

		virtual bool is_open() const = 0;
		virtual void poll_events() = 0;

		on_resize_callback_set_type& get_on_resize_event();

	protected:

		on_resize_callback_set_type m_on_resize;
	};
}

#endif // DISPLAY_WINDOWING_SYSTEM_H_INCLUDED

#ifndef DISPLAY_WINDOWING_SYSTEM_H_INCLUDED
#define DISPLAY_WINDOWING_SYSTEM_H_INCLUDED

#include "Core/singleton.h"
#include "Core/callback_set.h"
#include "Core/Math/vec2.h"

#define MIR_WINDOW_USE_GLFW

namespace mir
{
	class window
	{
	public:
		using on_resize_callback_set_type = callback_set<vec2u>;

		virtual ~window() = 0;

		virtual bool is_open() const = 0;
		virtual void poll_events() = 0;

		on_resize_callback_set_type& get_on_resize_event();

	protected:

		on_resize_callback_set_type m_on_resize;
	};

	class window_factory
	{
	public:
		static void s_initialize_window_system();

		static window* s_create_window( vec2u _dims );

		static void s_terminate_window_system();
	};

}

#endif // DISPLAY_WINDOWING_SYSTEM_H_INCLUDED

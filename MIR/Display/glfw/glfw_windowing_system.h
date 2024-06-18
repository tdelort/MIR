#ifndef DISPLAY_GLFW_GLFW_WINDOWING_SYSTEM_H_INCLUDED
#define DISPLAY_GLFW_GLFW_WINDOWING_SYSTEM_H_INCLUDED

#include "Core/singleton.h"
#include "Display/windowing_system.h"

struct GLFWwindow;

namespace mir
{
	class glfw_windowing_system : public windowing_system
	{
		void s_glfw_initialize_window_system();
		window* s_glfw_create_window( vec2u _dims );
		void s_glfw_terminate_window_system();
		virtual window& create_window( vec2u _dims ) = 0;

		virtual window& get_window( size_t _index ) = 0;
		virtual size_t get_window_count() = 0;

		virtual void destroy_window( size_t _index ) = 0;
	}
}

#endif // DISPLAY_GLFW_GLFW_WINDOWING_SYSTEM_H_INCLUDED

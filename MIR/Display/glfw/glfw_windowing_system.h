#ifndef DISPLAY_GLFW_GLFW_WINDOWING_SYSTEM_H_INCLUDED
#define DISPLAY_GLFW_GLFW_WINDOWING_SYSTEM_H_INCLUDED

#include "Core/singleton.h"
#include "Display/windowing_system.h"

struct GLFWwindow;

namespace mir
{
	class glfw_window : public window
	{
	public:
		glfw_window( vec2u _size );
		virtual ~glfw_window();

		virtual bool is_open() const override;
		virtual void poll_events() override;

	private:

		// here since it will handle finding the window from the api handle
		static void s_glfw_on_frame_buffer_size_changed_callback(GLFWwindow* _window, int _w, int _h);

		GLFWwindow* m_api_handle;
	};

	void s_glfw_initialize_window_system();
	window* s_glfw_create_window( vec2u _dims );
	void s_glfw_terminate_window_system();
}

#endif // DISPLAY_GLFW_GLFW_WINDOWING_SYSTEM_H_INCLUDED

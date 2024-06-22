#ifndef DISPLAY_GLFW_GLFW_WINDOW_H_INCLUDED
#define DISPLAY_GLFW_GLFW_WINDOW_H_INCLUDED

#include "Core/singleton.h"
#include "Display/windowing_service.h"
#include "Display/window.h"

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
}

#endif // DISPLAY_GLFW_GLFW_WINDOW_H_INCLUDED

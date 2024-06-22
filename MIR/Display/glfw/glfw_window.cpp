#include "glfw_window.h"

#include <application.h>

namespace mir
{
	void glfw_window::s_glfw_on_frame_buffer_size_changed_callback(GLFWwindow* _window, int _w, int _h)
	{
		windowing_service* sys = application::instance().get_service_locator().get<windowing_service>();

		for (size_t i = 0; i < sys->get_window_count(); ++i )
		{
			window* win = sys->get_window( i );
			glfw_window* glfw_win = static_cast<glfw_window*>(win);

			if (_window == glfw_win->m_api_handle )
			{
				glfw_win->get_on_resize_event().call( vec2u(_w, _h) );
			}
		}
	}

	// Window
	glfw_window::glfw_window( vec2u _size )
	{
		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
		// TODO : handle resizable window
		glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);
		GLFWwindow* api_handle = glfwCreateWindow( _size[0], _size[1], "MIR window", nullptr, nullptr);
		m_api_handle = api_handle;

		glfwSetFramebufferSizeCallback( m_api_handle, s_glfw_on_frame_buffer_size_changed_callback );
	}

	bool glfw_window::is_open() const
	{
		return !glfwWindowShouldClose( m_api_handle );
	}

	void glfw_window::poll_events()
	{
		glfwPollEvents();
	}

	glfw_window::~glfw_window()
	{
		glfwDestroyWindow( m_api_handle );
		m_api_handle = nullptr;
	}
}

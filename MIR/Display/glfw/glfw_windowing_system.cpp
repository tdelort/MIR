#include "glfw_windowing_system.h"

namespace mir
{
	// TODO store in window factory
	std::vector<glfw_window*> g_windows;

	void glfw_window::s_glfw_on_frame_buffer_size_changed_callback(GLFWwindow* _window, int _w, int _h)
	{
		for ( glfw_window* window : g_windows )
		{
			// meh, not eleganto
			if (_window == window->m_api_handle )
			{
				window->get_on_resize_event().call( vec2u(_w, _h) );
			}
		}
	}

	void s_glfw_initialize_window_system()
	{
		glfwInit();
	}

	window* s_glfw_create_window( vec2u _dims )
	{
		glfw_window* win = new glfw_window(_dims);
		g_windows.push_back( win );
		return win;
	}

	void s_glfw_terminate_window_system()
	{
		g_windows.clear();
		glfwTerminate();	
	}

}

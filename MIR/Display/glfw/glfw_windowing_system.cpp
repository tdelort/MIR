#include "glfw_windowing_system.h"

namespace mir
{
	//void glfw_window::s_glfw_on_frame_buffer_size_changed_callback(GLFWwindow* _window, int _w, int _h)
	//{
	//	for ( auto& window : g_windowing_system.get_windows() )
	//	{
	//		// meh, not eleganto
	//		if (_window == static_cast<glfw_window*>( window.get() )->m_api_handle )
	//		{
	//			window->get_on_resize_event().call( vec2u(_w, _h) );
	//		}
	//	}
	//}

	// Window
	glfw_window::glfw_window( vec2u _size )
	{
		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
		// TODO : handle resizable window
		glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
		GLFWwindow* api_handle = glfwCreateWindow( _size[0], _size[1], "MIR window", nullptr, nullptr);
		m_api_handle = api_handle;

		//glfwSetFramebufferSizeCallback( m_api_handle, s_glfw_on_frame_buffer_size_changed_callback );
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


	void s_glfw_initialize_window_system()
	{
		glfwInit();
	}

	window* s_glfw_create_window( vec2u _dims )
	{
		return new glfw_window(_dims);
	}

	void s_glfw_terminate_window_system()
	{
		glfwTerminate();	
	}

}

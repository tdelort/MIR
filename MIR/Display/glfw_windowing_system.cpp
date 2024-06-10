#include "glfw_windowing_system.h"

namespace mir
{
	// Window
	glfw_window::glfw_window(GLFWwindow* _api_handle)
	{
		m_api_handle = _api_handle;

		glfwSetFramebufferSizeCallback( m_api_handle, on_glfw_window_resize_callback );
	}

	bool glfw_window::is_open()
	{
		return !glfwWindowShouldClose( m_api_handle );
	}

	void glfw_window::poll_events()
	{
		glfwPollEvents();
	}

	void glfw_window::on_glfw_window_resize_callback( GLFWwindow* /*_window*/, int _w, int h)
	{
		m_on_resize( vec2u( _w, _h ) );
	}


	// window system
	glfw_windowing_system::glfw_windowing_system()
	{

	}

	void glfw_windowing_system::init()
	{
		glfwInit();
		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
		// TODO : handle resizable window
		glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
		GLFWwindow* api_handle = glfwCreateWindow(s_default_window_width, s_default_window_height, "Vulkan window", nullptr, nullptr);

	}

	void glfw_windowing_system::cleanup()
	{
		glfwDestroyWindow(m_window.get_api_handle());
		glfwTerminate();	
	}

	window* glfw_windowing_system::get_window()
	{
		return static_cast<window*>( m_window );
	}


}

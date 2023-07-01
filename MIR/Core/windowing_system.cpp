#include "windowing_system.h"

windowing_system::windowing_system()
{

}

void windowing_system::init()
{
	glfwInit();
	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
	// TODO : handle resizable window
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
	m_window = glfwCreateWindow(default_window_width, default_window_height, "Vulkan window", nullptr, nullptr);
}

void windowing_system::cleanup()
{
	glfwDestroyWindow(m_window);
	glfwTerminate();	
}

bool windowing_system::is_open()
{
	return !glfwWindowShouldClose(m_window);
}

void windowing_system::poll_events()
{
	glfwPollEvents();
}

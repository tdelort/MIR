#pragma once

#include "windowing_system.h"

struct GLFWwindow;

namespace mir
{
	class glfw_window : window
	{
		event<void> m_on_resize;

	public:
		glfw_window(GLFWwindow* _api_handle);
		~glfw_window();

		virtual bool is_open();
		virtual void poll_events();

		GLFWwindow* get_api_handle();
	private:
		GLFWwindow* m_api_handle;
	};

	class glfw_windowing_system : windowing_system
	{
	public:
		virtual void init();
		virtual void cleanup();

		virtual window* get_window();

		static constexpr unsigned int s_default_window_width = 800;
		static constexpr unsigned int s_default_window_height = 600;
		
	private:
		std::vector<std::unique_ptr<glfw_window>> m_windows;
	};

}

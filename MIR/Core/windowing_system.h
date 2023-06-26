#pragma once

struct GLFWwindow;

class windowing_system
{
	windowing_system();
public:
	windowing_system(const windowing_system&) = delete;
	windowing_system(windowing_system&&) = delete;
	windowing_system& operator=(const windowing_system&) = delete;
	windowing_system& operator=(windowing_system&&) = delete;

	static auto& instance()
	{
		static windowing_system instance;
		return instance;
	}

	void init();
	void cleanup();

	bool is_open();
	void poll_events();

	static constexpr unsigned int default_window_width = 800;
	static constexpr unsigned int default_window_height = 600;
	
private:
	GLFWwindow* m_window;
};


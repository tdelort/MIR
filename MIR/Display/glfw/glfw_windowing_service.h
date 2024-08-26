#ifndef DISPLAY_GLFW_GLFW_WINDOWING_SYSTEM_H_INCLUDED
#define DISPLAY_GLFW_GLFW_WINDOWING_SYSTEM_H_INCLUDED

#include "Core/core.h"
#include "Display/windowing_service.h"
#include "Display/window.h"

struct GLFWwindow;

namespace mir
{
	class glfw_windowing_service : public service_generic<windowing_service>
	{
	public:
		glfw_windowing_service();
		virtual ~glfw_windowing_service() override;

		window* create_window(vec2u _dims) override;

		window* get_window(size_t _index) const override;
		size_t get_window_count() override;

		void destroy_window(size_t _index) override;
	};
}

#endif // DISPLAY_GLFW_GLFW_WINDOWING_SYSTEM_H_INCLUDED

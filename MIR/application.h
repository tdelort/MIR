#pragma once

#include "Core/core.h"

struct GLFWwindow;

namespace mir
{
	class MIR_DLLEXPORT application
	{
	public:
		application();
		~application();

		int run();
	private:
		GLFWwindow* m_window;
	};
}


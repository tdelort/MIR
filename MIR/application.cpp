#include "application.h"

#include "Core/windowing_system.h"
#include "Core/rendering_system.h"

namespace mir
{
	application::application()
	{
		windowing_system::instance().init();

		rendering_system::instance().init();

		uint32_t extensionCount = 0;
		vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);

		std::cout << extensionCount << " extensions supported\n";

	}

	application::~application()
	{
		windowing_system::instance().cleanup();
	}

	int application::run()
	{
		windowing_system& ws = windowing_system::instance();

		glm::mat4 matrix;
		glm::vec4 vec;
		auto test = matrix * vec;

		while(ws.is_open()) 
		{
			ws.poll_events();
		}
		return 0;
	}
}

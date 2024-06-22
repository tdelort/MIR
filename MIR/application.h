#ifndef CORE_APPLICATION_H_INCLUDED
#define CORE_APPLICATION_H_INCLUDED


// Configure backends

// Window backend
#define MIR_USE_GLFW

// Rendering backend
#define MIR_USE_DX12
//#define MIR_USE_VULKAN


#include "application_config.h"

#include "Core/core.h"
#include "Core/service_locator.h"

namespace mir
{
	class MIR_DLLEXPORT application
	{
		application(const application&) = delete;
		application(application&&) = delete;
		application& operator=(const application&) = delete;
		application& operator=(application&&) = delete;

	public:
		static auto& instance()
		{
			static application instance;
			return instance;
		}

		application();

		void init( const application_config& _config );
		void destroy();
		int run();

		const service_locator& get_service_locator();

	private:
		service_locator m_application_services;
	};
}

#endif // !CORE_APPLICATION_H_INCLUDED

#include "pch.h"
#include "application.h"

int main()
{
	mir::application_config config;
	config.m_rendering_service_choice = mir::application_config::rendering_service_type::dx12;
	config.m_windowing_service_choice = mir::application_config::windowing_service_type::glfw;

	mir::application app(config);
	return app.run();
}

#pragma once

namespace mir
{
	class rendering_system
	{
		rendering_system();
	public:
		rendering_system(const rendering_system&) = delete;
		rendering_system(rendering_system&&) = delete;
		rendering_system& operator=(const rendering_system&) = delete;
		rendering_system& operator=(rendering_system&&) = delete;

		static auto& instance()
		{
			static rendering_system instance;
			return instance;
		}

		void init();
		void cleanup();

	private:
		void create_instance();
		void destroy_instance();
		VkInstance m_instance;
	};

}

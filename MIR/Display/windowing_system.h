#ifndef DISPLAY_WINDOWING_SYSTEM_H_INCLUDED
#define DISPLAY_WINDOWING_SYSTEM_H_INCLUDED

#include "Core/Math/vec2.h"

namespace mir
{
	struct windowing_system_impl;

	class windowing_system
	{
	public:
		windowing_system();
		~windowing_system();

		window& create_window( vec2u _dims );

		window& get_window( size_t _index );
		size_t get_window_count();

		void destroy_window( size_t _index );

	private:
		std::unique_ptr<windowing_system_impl> m_impl;
	};
}

#endif // DISPLAY_WINDOWING_SYSTEM_H_INCLUDED

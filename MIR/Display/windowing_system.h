#pragma once

#include "singleton.h"

namespace mir
{
	class window
	{
	public:
		virtual ~window() = 0;

		virtual bool is_open() = 0;
		virtual void poll_events() = 0;
		virtual void is_open() = 0;
	private:
	};

	class windowing_system
	{
	public:
		virtual void init() = 0;
		virtual void cleanup() = 0;

		virtual window* get_window() = 0;
	};

}

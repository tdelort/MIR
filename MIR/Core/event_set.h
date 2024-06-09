#pragma once

#include <functional>

namespace mir
{
	template<typename ...Args>
	class event_set
	{
		using callback_type = std::function<void(Args...)>;
	public:
		void operator+=(callback_type _callback);
		void operator-=(callback_type _callback);
		void operator()();

		void add(callback_type _callback);
		bool remove(callback_type _callback);
		void call();

		void clear();

		size_t size();

	private:
		std::vector<callback_type> m_callbacks;
	};
}

#include "event_set.hpp"

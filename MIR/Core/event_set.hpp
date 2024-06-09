#pragma once

#include "event_set.h"

#include <functional>

namespace mir
{
	template<typename ...Args>
	void event_set<Args...>::operator+=(callback_type _callback)
	{
		add(_callback);
	}

	template<typename ...Args>
	void event_set<Args...>::operator-=(callback_type _callback)
	{
		remove(_callback);
	}

	template<typename ...Args>
	void event_set<Args...>::operator()()
	{
		call();
	}

	template<typename ...Args>
	void event_set<Args...>::add(callback_type _callback)
	{
		m_callbacks.push_back( _callback );
	}

	template<typename ...Args>
	bool event_set<Args...>::remove(callback_type _callback)
	{
		// TODO
	}

	template<typename ...Args>
	bool event_set<Args...>::call()
	{

	}

	template<typename ...Args>
	void event_set<Args...>::clear()
	{
		m_callbacks.clear();
	}

	template<typename ...Args>
	size_t event_set<Args...>::size()
	{
		return m_callbacks.size();
	}
}

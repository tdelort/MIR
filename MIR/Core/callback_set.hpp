#pragma once

#include "callback_set.h"

#include <functional>

namespace mir
{
	template<typename ...Args>
	void callback_set<Args...>::operator+=(callback_type _callback)
	{
		add(_callback);
	}

	template<typename ...Args>
	void callback_set<Args...>::operator-=(callback_type _callback)
	{
		remove(_callback);
	}

	template<typename ...Args>
	void callback_set<Args...>::operator()()
	{
		call();
	}

	template<typename ...Args>
	void callback_set<Args...>::add(callback_type _callback)
	{
		m_callbacks.push_back( _callback );
	}

	template<typename ...Args>
	bool callback_set<Args...>::remove(callback_type _callback)
	{
		// TODO
	}

	template<typename ...Args>
	bool callback_set<Args...>::call( Args... _args )
	{
		for( callback_type& callback : m_callbacks )
		{
			callback( _args );
		}
		clear();
	}

	template<typename ...Args>
	void callback_set<Args...>::clear()
	{
		m_callbacks.clear();
	}

	template<typename ...Args>
	size_t callback_set<Args...>::size()
	{
		return m_callbacks.size();
	}
}

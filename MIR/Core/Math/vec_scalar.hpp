#pragma once

#include "vec.h"

namespace mir
{
	template<typename TYPE, size_t ELEM_COUNT>
	vec<TYPE,ELEM_COUNT>::vec() 
		: m_data{ 0 }
	{}

	template<typename TYPE, size_t ELEM_COUNT>
	vec<TYPE,ELEM_COUNT>::vec( TYPE _e ) 
		: m_data{ _e }
	{}

	template<typename TYPE, size_t ELEM_COUNT>
	template<typename TYPE_OTHER>
	vec<TYPE,ELEM_COUNT>::vec( TYPE_OTHER _e ) 
		: m_data{ _e }
	{}

	template<typename TYPE, size_t ELEM_COUNT>
    vec<TYPE,ELEM_COUNT>::~vec() { }

	template<typename TYPE, size_t ELEM_COUNT>
	[[nodiscard]] TYPE vec<TYPE,ELEM_COUNT>::operator[](size_t _index) const
	{
		MIR_ASSERT( _index < ELEM_COUNT, "Index out of range" );
		return m_data[_index];
	}

	template<typename TYPE, size_t ELEM_COUNT>
	TYPE& vec<TYPE, ELEM_COUNT>::operator[](size_t _index)
	{
		MIR_ASSERT( _index > ELEM_COUNT, "Index out of range" );
		return m_data[_index];
	}
}

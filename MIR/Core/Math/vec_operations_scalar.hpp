#ifndef CORE_MATH_VEC_OPERATIONS_HPP_INCLUDED
#define CORE_MATH_VEC_OPERATIONS_HPP_INCLUDED

#include "vec.h"

namespace mir
{
	// dot 

	template<typename TYPE, size_t ELEM_COUNT>
	TYPE dot(const vec<TYPE, ELEM_COUNT>& _lhs, const vec<TYPE, ELEM_COUNT>& _rhs)
	{
		TYPE accum = 0.f;
		for (size_t i = 0; i < ELEM_COUNT; ++i)
			accum += _lhs[i] * _rhs[i];
		return accum;
	}

	// sq_length 

	template<typename TYPE, size_t ELEM_COUNT>
	float sq_length(const vec<TYPE, ELEM_COUNT>& _v)
	{
		float size_accum = 0.f;
		for (size_t i = 0; i < ELEM_COUNT; ++i)
		{
			const float val = static_cast<float>(_v[i]);
			size_accum += val * val;
		}
		return size_accum;
	}

	template<typename TYPE, size_t ELEM_COUNT>
	float length(const vec<TYPE, ELEM_COUNT>& _v)
	{
		return std::sqrt(sq_length(_v));
	}

	template<typename TYPE, size_t ELEM_COUNT>
	vec<TYPE, ELEM_COUNT> normalize(const vec<TYPE, ELEM_COUNT>& _v)
	{
		const float len = length(_v);
		return _v / len;
	}

	template<typename TYPE, size_t ELEM_COUNT>
	vec<TYPE, ELEM_COUNT> normalize_safe(const vec<TYPE, ELEM_COUNT>& _v, float _epsilon)
	{
		const float len = length(_v);
		if ( len < _epsilon )
			return 0.f;
		return _v / len;
	}
}

#endif // CORE_MATH_VEC_OPERATIONS_HPP_INCLUDED

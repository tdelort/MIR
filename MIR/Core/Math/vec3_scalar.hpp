﻿#ifndef CORE_MATH_VEC3_SCALAR_HPP_INCLUDED
#define CORE_MATH_VEC3_SCALAR_HPP_INCLUDED


#include "vec.h"
#include "vec3.h"

namespace mir
{
	template<typename TYPE>
	vec<TYPE, 3u>::vec()
		: type{ 0 }
	{
	}

	template<typename TYPE>
	vec<TYPE, 3u>::vec(TYPE e)
		: type{ e, e, e }
	{
	}

    template<typename TYPE>
	vec<TYPE, 3u>::vec( TYPE _e0, TYPE _e1, TYPE _e2)
		: m_data{ _e0, _e1, _e2 }
	{
	}

    template<typename TYPE>
	vec<TYPE, 3u>::vec( const vec<TYPE, 3u>& _v0 )
		: type{ _v0[0], _v0[1], _v0[2] }
	{
	}

    template<typename TYPE>
	vec<TYPE, 3u>::vec( const vec<TYPE, 2u>& _v0, TYPE _e1 )
		: type{ _v0[0], _v0[1], _e1 }
	{
	}


    template<typename TYPE>
	template<typename E0, typename E1, typename E2>
	vec<TYPE, 3u>::vec( E0 _e0, E1 _e1, E2 _e2)
		: type{ static_cast<TYPE>(_e0), static_cast<TYPE>(_e1), static_cast<TYPE>(_e2) }
	{
	}

    template<typename TYPE>
	template<typename E0>
	vec<TYPE, 3u>::vec( const vec<E0, 3u>& _v0 )
		: type{ _v0[0], _v0[1], _v0[2] }
	{
	}

    template<typename TYPE>
	template<typename E0, typename E1>
	vec<TYPE, 3u>::vec( const vec<E0, 2u>& _v0, E1 _e1 )
		: type{ _v0[0], _v0[1], _e1 }
	{
	}
	

    template<typename TYPE>
	[[nodiscard]] TYPE vec<TYPE, 3u>::operator[]( size_t _index ) const
	{
		MIR_ASSERT(_index < 3u, "vec3 out of bound acces (_index = " << _index << ")" );
		return m_data[_index];
	}

    template<typename TYPE>
	TYPE& vec<TYPE, 3u>::operator[]( size_t _index )
	{
		MIR_ASSERT(_index < 3u, "vec3 out of bound acces (_index = " << _index << ")" );
		return m_data[_index];
	}

	template<typename TYPE>
	template<typename E0>
	[[nodiscard]] vec<TYPE, 3u>& vec<TYPE, 3u>::operator+=(E0 _other)
	{
		m_data[0] += _other;
		m_data[1] += _other;
		m_data[2] += _other;
		return *this;
	}

    template<typename TYPE>
	template<typename E0>
	[[nodiscard]] vec<TYPE, 3u>& vec<TYPE, 3u>::operator+=(const vec<E0, 3u>& _other)
	{
		m_data[0] += static_cast<TYPE>(_other.m_data[0]);
		m_data[1] += static_cast<TYPE>(_other.m_data[1]);
		m_data[2] += static_cast<TYPE>(_other.m_data[2]);
		return *this;
	}

    template<typename TYPE>
	template<typename E0>
	[[nodiscard]] vec<TYPE, 3u>& vec<TYPE, 3u>::operator-=(E0 _other)
	{
		m_data[0] -= _other;
		m_data[1] -= _other;
		m_data[2] -= _other;
		return *this;
	}

    template<typename TYPE>
	template<typename E0>
	[[nodiscard]] vec<TYPE, 3u>& vec<TYPE, 3u>::operator-=(const vec<E0, 3u>& _other)
	{
		m_data[0] -= static_cast<TYPE>(_other.m_data[0]);
		m_data[1] -= static_cast<TYPE>(_other.m_data[1]);
		m_data[2] -= static_cast<TYPE>(_other.m_data[2]);
	}

	template<typename TYPE>
	vec<TYPE, 3u> operator-(const vec<TYPE, 3u>& _vec)
	{
		return vec<TYPE, 3u>( _vec.m_data[0], _vec.m_data[1], _vec.m_data[2] );
	}


    template<typename TYPE>
	vec<TYPE, 3u> operator+(const vec<TYPE, 3u>& _lhs, TYPE _rhs)
	{
		return vec<TYPE, 3u>( _lhs ) += _rhs;
	}

    template<typename TYPE>
	vec<TYPE, 3u> operator+(TYPE _lhs, const vec<TYPE, 3u>& _rhs)
	{
		return vec<TYPE, 3u>( _rhs ) += _lhs;
	}

    template<typename TYPE>
	vec<TYPE, 3u> operator+(const vec<TYPE, 3u>& _lhs, const vec<TYPE, 3u>& _rhs)
	{
		return vec<TYPE, 3u>( _lhs ) += _rhs;
	}


    template<typename TYPE>
	vec<TYPE, 3u> operator-(const vec<TYPE, 3u>& _lhs, TYPE _rhs)
	{
		return vec<TYPE, 3u>( _lhs ) -= _rhs;
	}

    template<typename TYPE>
	vec<TYPE, 3u> operator-(TYPE _lhs, const vec<TYPE, 3u>& _rhs)
	{
		return vec<TYPE, 3u>( _rhs ) -= _lhs;
	}

    template<typename TYPE>
	vec<TYPE, 3u> operator-(const vec<TYPE, 3u>& _lhs, const vec<TYPE, 3u>& _rhs)
	{
		return vec<TYPE, 3u>( _lhs ) -= _rhs;
	}

	template<typename TYPE>
	vec<TYPE,3u> cross(const vec<TYPE, 3u>& _lhs, const vec<TYPE, 3u>& _rhs)
	{
		return vec<TYPE, 3u>(
			_lhs.y() * _rhs.z() - _lhs.z() * _rhs.y(),
			_lhs.z() * _rhs.x() - _lhs.x() * _rhs.z(),
			_lhs.x() * _rhs.y() - _lhs.y() * _rhs.x()
		);
	}


} // namespace mir

#endif // CORE_MATH_VEC3_SCALAR_HPP_INCLUDED

#ifndef CORE_MATH_VEC4_SCALAR_HPP_INCLUDED
#define CORE_MATH_VEC4_SCALAR_HPP_INCLUDED


#include "vec.h"
#include "vec4.h"

namespace mir
{
    template<typename TYPE>
	vec<TYPE, 4u>::vec( TYPE _e0, TYPE _e1, TYPE _e2, TYPE _e3)
		: m_data{ _e0, _e1, _e2, _e3 }
	{
	}

    template<typename TYPE>
	vec<TYPE, 4u>::vec( const vec<TYPE, 4u>& _v0 )
		: type{ _v0[0], _v0[1], _v0[2], _v0[3] }
	{
	}

    template<typename TYPE>
	vec<TYPE, 4u>::vec( const vec<TYPE, 2u>& _v0, TYPE _e1, TYPE _e2 )
		: type{ _v0[0], _v0[1], _e1, _e2 }
	{
	}

    template<typename TYPE>
	vec<TYPE, 4u>::vec( const vec<TYPE, 3u>& _v0, TYPE _e1 )
		: type{ _v0[0], _v0[1], _v0[2], _e1 }
	{
	}


    template<typename TYPE>
	template<typename E0, typename E1, typename E2, typename E3>
	vec<TYPE, 4u>::vec( E0 _e0, E1 _e1, E2 _e2, E3 _e3)
		: type{ static_cast<TYPE>(_e0), static_cast<TYPE>(_e1), static_cast<TYPE>(_e2), static_cast<TYPE>(_e3) }
	{
	}

    template<typename TYPE>
	template<typename E0>
	vec<TYPE, 4u>::vec( const vec<E0, 4u>& _v0 )
		: type{ _v0[0], _v0[1], _v0[2], _v0[3] }
	{
	}

    template<typename TYPE>
	template<typename E0, typename E1, typename E2>
	vec<TYPE, 4u>::vec( const vec<E0, 2u>& _v0, E1 _e1, E2 _e2 )
		: type{ _v0[0], _v0[1], _e1, _e2 }
	{
	}

    template<typename TYPE>
	template<typename E0, typename E1>
	vec<TYPE, 4u>::vec( const vec<E0, 3u>& _v0, E1 _e1 )
		: type{ _v0[0], _v0[1], _v0[2], _e1 }
	{
	}

    template<typename TYPE>
	[[nodiscard]] TYPE vec<TYPE, 4u>::operator[]( size_t _index ) const
	{
		// TODO : Debug assert
		MIR_ASSERT(_index < 4u, "vec4 out of bound acces (_index = " << _index << ")" );
		return m_data[_index];
	}

    template<typename TYPE>
	TYPE& vec<TYPE, 4u>::operator[]( size_t _index )
	{
		MIR_ASSERT(_index < 4u, "vec4 out of bound acces (_index = " << _index << ")" );
		return m_data[_index];
	}

	template<typename TYPE>
	template<typename E0>
	[[nodiscard]] vec<TYPE, 4u>& vec<TYPE, 4u>::operator+=(E0 _other)
	{
		m_data[0] += _other;
		m_data[1] += _other;
		m_data[2] += _other;
		m_data[3] += _other;
		return *this;
	}

    template<typename TYPE>
	template<typename E0>
	[[nodiscard]] vec<TYPE, 4u>& vec<TYPE, 4u>::operator+=(const vec<E0, 4u>& _other)
	{
		m_data[0] += static_cast<TYPE>(_other.m_data[0]);
		m_data[1] += static_cast<TYPE>(_other.m_data[1]);
		m_data[2] += static_cast<TYPE>(_other.m_data[2]);
		m_data[3] += static_cast<TYPE>(_other.m_data[3]);
		return *this;
	}

    template<typename TYPE>
	template<typename E0>
	[[nodiscard]] vec<TYPE, 4u>& vec<TYPE, 4u>::operator-=(E0 _other)
	{
		m_data[0] -= _other;
		m_data[1] -= _other;
		m_data[2] -= _other;
		m_data[3] -= _other;
		return *this;
	}

    template<typename TYPE>
	template<typename E0>
	[[nodiscard]] vec<TYPE, 4u>& vec<TYPE, 4u>::operator-=(const vec<E0, 4u>& _other)
	{
		m_data[0] -= static_cast<TYPE>(_other.m_data[0]);
		m_data[1] -= static_cast<TYPE>(_other.m_data[1]);
		m_data[2] -= static_cast<TYPE>(_other.m_data[2]);
		m_data[3] -= static_cast<TYPE>(_other.m_data[3]);
	}

	template<typename TYPE>
	vec<TYPE, 4u> operator-(const vec<TYPE, 4u>& _vec)
	{
		return vec<TYPE, 4u>( _vec.m_data[0], _vec.m_data[1], _vec.m_data[2], _vec.m_data[3] );
	}


    template<typename TYPE>
	vec<TYPE, 4u> operator+(const vec<TYPE, 4u>& _lhs, TYPE _rhs)
	{
		return vec<TYPE, 4u>( _lhs ) += _rhs;
	}

    template<typename TYPE>
	vec<TYPE, 4u> operator+(TYPE _lhs, const vec<TYPE, 4u>& _rhs)
	{
		return vec<TYPE, 4u>( _rhs ) += _lhs;
	}

    template<typename TYPE>
	vec<TYPE, 4u> operator+(const vec<TYPE, 4u>& _lhs, const vec<TYPE, 4u>& _rhs)
	{
		return vec<TYPE, 4u>( _lhs ) += _rhs;
	}


    template<typename TYPE>
	vec<TYPE, 4u> operator-(const vec<TYPE, 4u>& _lhs, TYPE _rhs)
	{
		return vec<TYPE, 4u>( _lhs ) -= _rhs;
	}

    template<typename TYPE>
	vec<TYPE, 4u> operator-(TYPE _lhs, const vec<TYPE, 4u>& _rhs)
	{
		return vec<TYPE, 4u>( _rhs ) -= _lhs;
	}

    template<typename TYPE>
	vec<TYPE, 4u> operator-(const vec<TYPE, 4u>& _lhs, const vec<TYPE, 4u>& _rhs)
	{
		return vec<TYPE, 4u>( _lhs ) -= _rhs;
	}

} // namespace mir

#endif // CORE_MATH_VEC4_SCALAR_HPP_INCLUDED

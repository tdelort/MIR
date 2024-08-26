#ifndef CORE_MATH_VEC2_SCALAR_HPP_INCLUDED
#define CORE_MATH_VEC2_SCALAR_HPP_INCLUDED

#include "vec.h"
#include "vec2.h"

namespace mir
{    
	template<typename TYPE>
	vec<TYPE, 2u>::vec()
		: type{ 0 }
	{
	}

	template<typename TYPE>
	vec<TYPE, 2u>::vec(TYPE e)
		: type{ e, e }
	{
	}

    template<typename TYPE>
	vec<TYPE, 2u>::vec( TYPE _e0, TYPE _e1)
		: m_data{ _e0, _e1 }
	{
	}

    template<typename TYPE>
	vec<TYPE, 2u>::vec( const vec<TYPE, 2u>& _v0 )
		: type{ _v0[0], _v0[1] }
	{
	}


    template<typename TYPE>
	template<typename E0, typename E1>
	vec<TYPE, 2u>::vec( E0 _e0, E1 _e1)
		: type{ static_cast<TYPE>(_e0), static_cast<TYPE>(_e1) }
	{
	}

    template<typename TYPE>
	template<typename TYPE_OTHER>
	vec<TYPE, 2u>::vec(const vec<TYPE_OTHER, 2u>& _v0)
		: type{ _v0[0], _v0[1] }
	{
	}

    template<typename TYPE>
	[[nodiscard]] TYPE vec<TYPE, 2u>::operator[]( size_t _index ) const
	{
		MIR_ASSERT(_index < 2u, "vec2 out of bound acces (_index = " << _index << ")" );
		return m_data[_index];
	}

    template<typename TYPE>
	TYPE& vec<TYPE, 2u>::operator[]( size_t _index )
	{
		MIR_ASSERT(_index < 2u, "vec2 out of bound acces (_index = " << _index << ")" );
		return m_data[_index];
	}

    template<typename TYPE>
	template<typename E0>
	[[nodiscard]] vec<TYPE, 2u>& vec<TYPE, 2u>::operator+=(E0 _other)
	{
		m_data[0] += _other;
		m_data[1] += _other;
		return *this;
	}

    template<typename TYPE>
	template<typename E0>
	[[nodiscard]] vec<TYPE, 2u>& vec<TYPE, 2u>::operator+=(const vec<E0, 2u>& _other)
	{
		m_data[0] += static_cast<TYPE>(_other.m_data[0]);
		m_data[1] += static_cast<TYPE>(_other.m_data[1]);
		return *this;
	}

    template<typename TYPE>
	template<typename E0>
	[[nodiscard]] vec<TYPE, 2u>& vec<TYPE, 2u>::operator-=(E0 _other)
	{
		m_data[0] -= _other;
		m_data[1] -= _other;
		return *this;
	}

    template<typename TYPE>
	template<typename E0>
	[[nodiscard]] vec<TYPE, 2u>& vec<TYPE, 2u>::operator-=(const vec<E0, 2u>& _other)
	{
		m_data[0] -= static_cast<TYPE>(_other.m_data[0]);
		m_data[1] -= static_cast<TYPE>(_other.m_data[1]);
	}
	

	template<typename TYPE>
	vec<TYPE, 2u> operator-(const vec<TYPE, 2u>& _vec)
	{
		return vec<TYPE, 2u>( _vec.m_data[0], _vec.m_data[1] );
	}


    template<typename TYPE>
	vec<TYPE, 2u> operator+(const vec<TYPE, 2u>& _lhs, TYPE _rhs)
	{
		return vec<TYPE, 2u>( _lhs ) += _rhs;
	}

    template<typename TYPE>
	vec<TYPE, 2u> operator+(TYPE _lhs, const vec<TYPE, 2u>& _rhs)
	{
		return vec<TYPE, 2u>( _rhs ) += _lhs;
	}

    template<typename TYPE>
	vec<TYPE, 2u> operator+(const vec<TYPE, 2u>& _lhs, const vec<TYPE, 2u>& _rhs)
	{
		return vec<TYPE, 2u>( _lhs ) += _rhs;
	}


    template<typename TYPE>
	vec<TYPE, 2u> operator-(const vec<TYPE, 2u>& _lhs, TYPE _rhs)
	{
		return vec<TYPE, 2u>( _lhs ) -= _rhs;
	}

    template<typename TYPE>
	vec<TYPE, 2u> operator-(TYPE _lhs, const vec<TYPE, 2u>& _rhs)
	{
		return vec<TYPE, 2u>( _rhs ) -= _lhs;
	}

    template<typename TYPE>
	vec<TYPE, 2u> operator-(const vec<TYPE, 2u>& _lhs, const vec<TYPE, 2u>& _rhs)
	{
		return vec<TYPE, 2u>( _lhs ) -= _rhs;
	}

} // namespace mir

#endif // CORE_MATH_VEC2_SCALAR_HPP_INCLUDED

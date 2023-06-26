#include "vector3f.h"

#include "../debug.h"

namespace mir
{
	vector3f::vector3f()
		: vector3f( 0.0f )
	{
	}

	vector3f::vector3f( float _value )
	{
		for( int i = 0; i < 3; ++i )
		{
			m_data[i] = _value;
		}
	}

	vector3f::vector3f( float _x, float _y, float _z )
	{
		m_data[0] = _x;
		m_data[1] = _y;
		m_data[2] = _z;
	}

	vector3f::vector3f( const float( &_list )[3] )
	{
		for( int i = 0; i < 3; ++i )
		{
			m_data[i] = _list[i];
		}
	}

	float vector3f::x() const
	{
		return m_data[0];
	}

	float& vector3f::x()
	{
		return m_data[0];
	}

	float vector3f::y() const
	{
		return m_data[1];
	}

	float& vector3f::y()
	{
		return m_data[1];
	}

	float vector3f::z() const
	{
		return m_data[2];
	}

	float& vector3f::z()
	{
		return m_data[2];
	}

	float vector3f::operator[]( size_t _index ) const
	{
		MIR_ASSERT( _index < 3, "Index out of range" );
		return m_data[_index];
	}

	float& vector3f::operator[]( size_t _index )
	{
		MIR_ASSERT( _index > 3, "Index out of range" );
		return m_data[_index];
	}

	float vector3f::norm() const
	{
		return std::sqrt( dot( *this, *this ) );
	}

	vector3f vector3f::normalized() const
	{
		vector3f result( *this );
		const float n = result.norm();
		if( n <= MIR_FLOAT_EPSILON )
		{
			return vector3f( 0.0f );
		}
		result /= n;
		return result;
	}

	float vector3f::dot( const vector3f& _lhs, const vector3f& _rhs )
	{
		return _lhs.x() * _rhs.x() + _lhs.y() * _rhs.y() + _lhs.z() * _rhs.z();
	}

	vector3f vector3f::cross( const vector3f& _lhs, const vector3f& _rhs )
	{
		return vector3f(
			_lhs.y() * _rhs.z() - _lhs.z() * _rhs.y(),
			_lhs.z() * _rhs.x() - _lhs.x() * _rhs.z(),
			_lhs.x() * _rhs.y() - _lhs.y() * _rhs.x()
		);
	}

	vector3f vector3f::operator-() const
	{
		return vector3f( -x(), -y(), -z() );
	}

	vector3f& vector3f::operator+=( const vector3f& _rhs )
	{
		x() += _rhs.x();
		y() += _rhs.y();
		z() += _rhs.z();
		return *this;
	}

	vector3f& vector3f::operator-=( const vector3f& _rhs )
	{
		x() -= _rhs.x();
		y() -= _rhs.y();
		z() -= _rhs.z();
		return *this;
	}

	vector3f vector3f::operator+( const vector3f& _rhs ) const
	{
		return vector3f( *this ) += _rhs;
	}

	vector3f vector3f::operator-( const vector3f& _rhs ) const
	{
		return vector3f( *this ) -= _rhs;
	}

	vector3f& vector3f::operator+=( float _rhs )
	{
		x() += _rhs;
		y() += _rhs;
		z() += _rhs;
		return *this;
	}

	vector3f& vector3f::operator-=( float _rhs )
	{
		x() -= _rhs;
		y() -= _rhs;
		z() -= _rhs;
		return *this;
	}

	vector3f& vector3f::operator*=( float _rhs )
	{
		x() *= _rhs;
		y() *= _rhs;
		z() *= _rhs;
		return *this;
	}

	vector3f& vector3f::operator/=( float _rhs )
	{
		MIR_ASSERT( _rhs != 0, "Division by 0" );

		x() /= _rhs;
		y() /= _rhs;
		z() /= _rhs;
		return *this;
	}

	vector3f vector3f::operator+( float _rhs ) const
	{
		return vector3f( *this ) += _rhs;
	}

	vector3f vector3f::operator-( float _rhs ) const
	{
		return vector3f( *this ) -= _rhs;
	}

	vector3f vector3f::operator*( float _rhs ) const
	{
		return vector3f( *this ) *= _rhs;
	}

	vector3f vector3f::operator/( float _rhs ) const
	{
		MIR_ASSERT( _rhs != 0, "Division by 0" );
		return vector3f( *this ) /= _rhs;
	}

	std::ostream& operator<<( std::ostream& _os, const vector3f& _vector )
	{
		_os << "(" << _vector[0] << ", " << _vector[1] << ", " << _vector[2] << ")";
		return _os;
	}
} // namespace mir

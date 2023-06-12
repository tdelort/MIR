#include "quaternion.h"

#include "../core.h"
#include "../debug.h"
#include "vector3f.h"

namespace mir
{
	quaternion::quaternion()
		: m_data{ 0.f, 0.f, 0.f, 1.f }
	{
	}


	quaternion::quaternion( const float _x, const float _y, const float _z, const float _w )
		: m_data{ _x, _y, _z, _w }
	{
	}

	quaternion::quaternion( const float( &_list )[4] )
	{
		for( int i = 0; i < 4; ++i )
		{
			m_data[i] = _list[i];
		}
	}

	quaternion::quaternion( const vector3f& _euler )
	{
		// TODO
	}


	float quaternion::x() const
	{
		return m_data[0];
	}

	float& quaternion::x()
	{
		return m_data[0];
	}

	float quaternion::y() const
	{
		return m_data[1];
	}

	float& quaternion::y()
	{
		return m_data[1];
	}

	float quaternion::z() const
	{
		return m_data[2];
	}

	float& quaternion::z()
	{
		return m_data[2];
	}

	float quaternion::w() const
	{
		return m_data[3];
	}

	float& quaternion::w()
	{
		return m_data[3];
	}


	vector3f quaternion::euler() const
	{
		// TODO : optimize ?
		const float x = m_data[0];
		const float y = m_data[1];
		const float z = m_data[2];
		const float w = m_data[3];
		const float two_x2 = 2.0f * x * x;
		const float two_y2 = 2.0f * y * y;
		const float two_z2 = 2.0f * z * z;
		vector3f result(
			atan2( 2.0f * ( w * x + y * z ), 1.0f - two_x2 + two_y2 ),
			asin( 2.0f * ( w * y - z * x ) ),
			atan2( 2.0f * ( w * z + x * y ), 1.0f - two_y2 + two_z2 )
		);
		return result;
	}

	quaternion quaternion::inverse()
	{
		// TODO
		const float x = m_data[0];
		const float y = m_data[1];
		const float z = m_data[2];
		const float w = m_data[3];
		const float sum_of_squares = x * x + y * y + z * z + w * w;
		return quaternion(
			-x / ( sum_of_squares ),
			-y / ( sum_of_squares ),
			-z / ( sum_of_squares ),
			w / ( sum_of_squares )
		);
	}

	quaternion quaternion::normalize()
	{
		const float length = std::sqrt( m_data[0] * m_data[0] + m_data[1] * m_data[1] + m_data[2] * m_data[2] + m_data[3] * m_data[3] );
		if( length <= MIR_FLOAT_EPSILON )
		{
			MIR_LOG_ERROR( "Quaternion length is zero" );
			return quaternion();
		}

		const float inv_length = 1.0f / length;
		return quaternion(
			m_data[0] *= inv_length,
			m_data[1] *= inv_length,
			m_data[2] *= inv_length,
			m_data[3] *= inv_length
		);
	}

	quaternion& quaternion::operator*=( const quaternion& _rhs )
	{
		const float x = m_data[0];
		const float y = m_data[1];
		const float z = m_data[2];
		const float w = m_data[3];
		const float rhs_x = m_data[0];
		const float rhs_y = m_data[1];
		const float rhs_z = m_data[2];
		const float rhs_w = m_data[3];
		m_data[0] = w * rhs_x + x * rhs_w + y * rhs_z - z * rhs_y;
		m_data[1] = w * rhs_y + y * rhs_w + z * rhs_x - x * rhs_z;
		m_data[2] = w * rhs_z + z * rhs_w + x * rhs_y - y * rhs_x;
		m_data[3] = w * rhs_w - x * rhs_x - y * rhs_y - z * rhs_z;
		return *this;
	}

	quaternion quaternion::operator*( const quaternion& _rhs ) const
	{
		return quaternion( *this ) *= _rhs;
	}
} // namespace mir

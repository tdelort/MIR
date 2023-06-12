#pragma once

namespace mir
{
	struct vector3f;

	/*
	 * w : real part
	 * x : i axis
	 * y : j axis
	 * z : k axis
	 */
	class quaternion
	{
	public:
        quaternion();
        explicit quaternion(const float _x, const float _y, const float _z, const float _w);
        explicit quaternion(const float(&_list)[4]);
        explicit quaternion(const vector3f& _euler);

		[[nodiscard]] float x() const;
		float& x();
		[[nodiscard]] float y() const;
		float& y();
		[[nodiscard]] float z() const;
		float& z();
		[[nodiscard]] float w() const;
		float& w();

		[[nodiscard]] vector3f euler() const;
		quaternion inverse();
		quaternion normalize();

		quaternion& operator*=(const quaternion& _rhs);
		quaternion operator*(const quaternion& _rhs) const;
	private:
		float m_data[4];
	};
}


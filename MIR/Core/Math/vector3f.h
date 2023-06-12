#pragma once

#include <ostream>

namespace mir
{
    struct vector3f
    {
        vector3f();
        explicit vector3f(float _value);
        explicit vector3f(float _x, float _y, float _z);
        explicit vector3f(const float(&_list)[3]);
        
        [[nodiscard]] float x() const;
        float& x();
        [[nodiscard]] float y() const;
        float& y();
        [[nodiscard]] float z() const;
        float& z();

        [[nodiscard]] float operator[](size_t _index) const;
        float& operator[](size_t _index);

        [[nodiscard]] float norm() const;
        [[nodiscard]] vector3f normalized() const;

        float dot(const vector3f& _other);
        static float dot(const vector3f& _lhs, const vector3f& _rhs);
        vector3f& cross(const vector3f& _other);
        static vector3f cross(const vector3f& _lhs, const vector3f& _rhs);

        // operators
        vector3f operator-() const;
        vector3f& operator+=(const vector3f& _rhs);
        vector3f& operator-=(const vector3f& _rhs);
        vector3f operator+(const vector3f& _rhs) const;
        vector3f operator-(const vector3f& _rhs) const;
        vector3f& operator+=(float _rhs);
        vector3f& operator-=(float _rhs);
        vector3f& operator*=(float _rhs);
        vector3f& operator/=(float _rhs);
        vector3f operator+(float _rhs) const;
        vector3f operator-(float _rhs) const;
        vector3f operator*(float _rhs) const;
        vector3f operator/(float _rhs) const;

		friend std::ostream& operator<<(std::ostream& _os, const vector3f& _vector);
    private:
        float m_data[3];
    };
}

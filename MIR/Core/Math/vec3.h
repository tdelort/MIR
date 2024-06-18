#ifndef CORE_MATH_VEC3_H_INCLUDED
#define CORE_MATH_VEC3_H_INCLUDED

#include "vec.h"

namespace mir
{
	using vec3u = vec<unsigned int, 3u>;
	using vec3i = vec<int, 3u>;
    using vec3f = vec<float, 3u>;

    template<typename TYPE>
    struct vec<TYPE, 3u>
    {
    public:
        using value_type = TYPE;
        using type = vec<TYPE, 3u>;
        size_t m_size = 3u;

    protected:
        TYPE m_data[3u];

    public:

        vec();

        vec( TYPE _e );

        template<typename TYPE_OTHER>
        vec( TYPE_OTHER _e );

        vec( TYPE _e0, TYPE _e1, TYPE _e2 );

        vec( const vec<TYPE, 3u>& _v0 );

        vec( const vec<TYPE, 2u>& _v0, TYPE _e1 );

        template<typename E0, typename E1, typename E2>
        vec( E0 _e0, E1 _e1, E2 _e2 );

        template<typename E0>
        vec( const vec<E0, 3u>& _v0 );

        template<typename E0, typename E1>
        vec( const vec<E0, 2u>& _v0, E1 _e1 );


        [[nodiscard]] TYPE operator[](size_t _index) const;
        TYPE& operator[](size_t _index);


        template<typename E0>
		[[nodiscard]] vec<TYPE, 3u>& operator+=(E0 _other);
		template<typename E0>
		[[nodiscard]] vec<TYPE, 3u>& operator+=(const vec<E0, 3u>& _other);

        template<typename E0>
		[[nodiscard]] vec<TYPE, 3u>& operator-=(E0 _other);
		template<typename E0>
		[[nodiscard]] vec<TYPE, 3u>& operator-=(const vec<E0, 3u>& _other);
    };

    template<typename TYPE>
	vec<TYPE, 3u> operator-( const vec<TYPE, 3u>& _vec);


    template<typename TYPE>
	vec<TYPE, 3u> operator+( const vec<TYPE, 3u>& _lhs, TYPE _rhs);

    template<typename TYPE>
	vec<TYPE, 3u> operator+(TYPE _lhs, const vec<TYPE, 3u>& _rhs);

    template<typename TYPE>
	vec<TYPE, 3u> operator+(const vec<TYPE, 3u>& _lhs, const vec<TYPE, 3u>& _rhs);


    template<typename TYPE>
	vec<TYPE, 3u> operator-( const vec<TYPE, 3u>& _lhs, TYPE _rhs);

    template<typename TYPE>
	vec<TYPE, 3u> operator-(TYPE _lhs, const vec<TYPE, 3u>& _rhs);

    template<typename TYPE>
	vec<TYPE, 3u> operator-(const vec<TYPE, 3u>& _lhs, const vec<TYPE, 3u>& _rhs);

    // only defined on R3 (and R7 but we don't care about that)
    template<typename TYPE>
    vec<TYPE, 3u> cross(const vec<TYPE, 3u>& _lhs, const vec<TYPE, 3u>& _rhs);
}

#include "vec3_scalar.hpp"

#endif // CORE_MATH_VEC3_H_INCLUDED

#pragma once

#include "vec.h"

namespace mir
{
	using vec4u = vec<unsigned int, 4u>;
	using vec4i = vec<int, 4u>;
    using vec4f = vec<float, 4u>;

    template<typename TYPE>
    struct vec<TYPE, 4u>
    {
    public:
        using value_type = TYPE;
        using type = vec<TYPE, 4u>;
        size_t m_size = 4u;

    protected:
        TYPE m_data[4u];

    public:

        vec();
        vec( TYPE _e );

        template<typename TYPE_OTHER>
        vec( TYPE_OTHER _e );

        vec( TYPE _e0, TYPE _e1, TYPE _e2, TYPE _e3 );
        vec( const vec<TYPE, 4u>& _v0 );

        vec( const vec<TYPE, 2u>& _v0, TYPE _e1, TYPE _e2 );
        vec( const vec<TYPE, 3u>& _v0, TYPE _e1 );

        template<typename E0, typename E1, typename E2, typename E3>
        vec( E0 _e0, E1 _e1, E2 _e2, E3 _e3 );

        template<typename E0>
        vec( const vec<E0, 4u>& _v0 );

        template<typename E0, typename E1, typename E2>
        vec( const vec<E0, 2u>& _v0, E1 _e1, E2 _e2 );
 
        template<typename E0, typename E1>
        vec( const vec<E0, 3u>& _v0, E1 _e1 );


        [[nodiscard]] TYPE operator[](size_t _index) const;
        TYPE& operator[](size_t _index);


        template<typename E0>
		[[nodiscard]] vec<TYPE, 4u>& operator+=(E0 _other);
		template<typename E0>
		[[nodiscard]] vec<TYPE, 4u>& operator+=(const vec<E0, 4u> const& _other);

        template<typename E0>
		[[nodiscard]] vec<TYPE, 4u>& operator-=(E0 _other);
		template<typename E0>
		[[nodiscard]] vec<TYPE, 4u>& operator-=(const vec<E0, 4u> const& _other);
    };

    template<typename TYPE>
	vec<TYPE, 4u> operator-( const vec<TYPE, 4u>& _vec);


    template<typename TYPE>
	vec<TYPE, 4u> operator+( const vec<TYPE, 4u>& _lhs, TYPE _rhs);

    template<typename TYPE>
	vec<TYPE, 4u> operator+(TYPE _lhs, const vec<TYPE, 4u>& _rhs);

    template<typename TYPE>
	vec<TYPE, 4u> operator+(const vec<TYPE, 4u>& _lhs, const vec<TYPE, 4u>& _rhs);


    template<typename TYPE>
	vec<TYPE, 4u> operator-( const vec<TYPE, 4u>& _lhs, TYPE _rhs);

    template<typename TYPE>
	vec<TYPE, 4u> operator-(TYPE _lhs, const vec<TYPE, 4u>& _rhs);

    template<typename TYPE>
	vec<TYPE, 4u> operator-(const vec<TYPE, 4u>& _lhs, const vec<TYPE, 4u>& _rhs);

}

#include "vec4_scalar.hpp"

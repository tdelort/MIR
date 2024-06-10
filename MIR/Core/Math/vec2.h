#pragma once

#include "vec.h"

namespace mir
{
	using vec2u = vec<unsigned int, 2u>;
	using vec2i = vec<int, 2u>;
    using vec2f = vec<float, 2u>;

    template<typename TYPE>
    struct vec<TYPE, 2u>
    {
    public:
        using value_type = TYPE;
        using type = vec<TYPE, 2u>;
        size_t m_size = 2u;

    protected:
        TYPE m_data[2u];

    public: 
        vec();

        vec( TYPE _e );

        template<typename TYPE_OTHER>
        vec( TYPE_OTHER _e );

        vec( TYPE _e0, TYPE _e1 );

        vec( const vec<TYPE, 2u>& _v0 );

        template<typename E0, typename E1>
        vec( E0 _e0, E1 _e1 );

        template<typename TYPE_OTHER>
        vec( const vec<TYPE_OTHER, 2u>& _v0 );



        [[nodiscard]] TYPE operator[](size_t _index) const;
        TYPE& operator[](size_t _index);


        template<typename E0>
		[[nodiscard]] vec<TYPE, 2u>& operator+=(E0 _other);
		template<typename E0>
		[[nodiscard]] vec<TYPE, 2u>& operator+=(const vec<E0, 2u> const& _other);

        template<typename E0>
		[[nodiscard]] vec<TYPE, 2u>& operator-=(E0 _other);
		template<typename E0>
		[[nodiscard]] vec<TYPE, 2u>& operator-=(const vec<E0, 2u> const& _other);
    };

    template<typename TYPE>
	vec<TYPE, 2u> operator-( const vec<TYPE, 2u>& _vec);


    template<typename TYPE>
	vec<TYPE, 2u> operator+( const vec<TYPE, 2u>& _lhs, TYPE _rhs);

    template<typename TYPE>
	vec<TYPE, 2u> operator+(TYPE _lhs, const vec<TYPE, 2u>& _rhs);

    template<typename TYPE>
	vec<TYPE, 2u> operator+(const vec<TYPE, 2u>& _lhs, const vec<TYPE, 2u>& _rhs);


    template<typename TYPE>
	vec<TYPE, 2u> operator-( const vec<TYPE, 2u>& _lhs, TYPE _rhs);

    template<typename TYPE>
	vec<TYPE, 2u> operator-(TYPE _lhs, const vec<TYPE, 2u>& _rhs);

    template<typename TYPE>
	vec<TYPE, 2u> operator-(const vec<TYPE, 2u>& _lhs, const vec<TYPE, 2u>& _rhs);

}

#include "vec2_scalar.hpp"



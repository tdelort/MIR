#ifndef CORE_MATH_VEC_H_INCLUDED
#define CORE_MATH_VEC_H_INCLUDED

namespace mir
{
    template<typename TYPE, size_t ELEM_COUNT>
    struct vec
    {
    public:
        using value_type = TYPE;
        using type = vec<TYPE, ELEM_COUNT>;
        size_t m_size = ELEM_COUNT;

    protected:
        TYPE m_data[ELEM_COUNT];

    public:

        vec();
        ~vec();
        vec( TYPE _e );

        template<typename TYPE_OTHER>
        vec( TYPE_OTHER _e );

        [[nodiscard]] TYPE operator[](size_t _index) const;

        TYPE& operator[](size_t _index);
    };
}

#include "vec_scalar.hpp"

#endif // CORE_MATH_VEC_H_INCLUDED

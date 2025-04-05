#ifndef KK2_MATH_MONOID_MAX_HPP
#define KK2_MATH_MONOID_MAX_HPP 1

#include <functional>

#include "../../type_traits/io.hpp"

namespace kk2 {

namespace monoid {

template <class S, class Compare = std::less<S>>
struct Max {
    static constexpr bool commutative = true;

    S a;
    bool is_unit;

    Max() : a(S()), is_unit(true) {}

    Max(S a_) : a(a_), is_unit(false) {}

    operator S() const { return a; }

    inline static Max op(Max l, Max r) {
        if (l.is_unit or r.is_unit) return l.is_unit ? r : l;
        return Compare{}(l.a, r.a) ? r : l;
    }

    inline static Max unit() { return Max(); }

    template <class OStream, is_ostream_t<OStream> * = nullptr>
    friend OStream &operator<<(OStream &os, const Max &max) {
        if (max.is_unit) os << "-inf";
        else os << max.a;
        return os;
    }

    template <class IStream, is_istream_t<IStream> * = nullptr>
    friend IStream &operator>>(IStream &is, Max &max) {
        is >> max.a;
        max.is_unit = false;
        return is;
    }

    bool operator==(const Max &rhs) const {
        return is_unit == rhs.is_unit and (is_unit or a == rhs.a);
    }

    bool operator!=(const Max &rhs) const { return !(*this == rhs); }
};

} // namespace monoid

} // namespace kk2

#endif // MATH_MONOID_MAX_H

#ifndef KK2_MATH_GROUP_SUM_WITH_SIZE_HPP
#define KK2_MATH_GROUP_SUM_WITH_SIZE_HPP 1

#include "../../type_traits/io.hpp"

namespace kk2 {

namespace group {

template <class S, class T = S> struct SumWithSize {
    static constexpr bool commutative = true;
    using M = SumWithSize;

    S a;
    T size;

    SumWithSize() : a(S{}), size(0) {}

    SumWithSize(S a_, S size_ = T(1)) : a(a_), size(size_) {}

    operator S() const { return a; }

    inline static M op(M l, M r) { return M(l.a + r.a, l.size + r.size); }

    inline static M inv(M x) { return M(-x.a, -x.size); }

    inline static M unit() { return M(); }

    template <class OStream, is_ostream_t<OStream> * = nullptr>
    friend OStream &operator<<(OStream &os, const M &sum) {
        os << sum.a;
        return os;
    }

    template <class IStream, is_istream_t<IStream> * = nullptr>
    friend IStream &operator>>(IStream &is, M &sum) {
        is >> sum.a;
        sum.size = T(1);
        return is;
    }

    bool operator==(const M &rhs) const { return a == rhs.a and size == rhs.size; }

    bool operator!=(const M &rhs) const { return !(*this == rhs); }
};

} // namespace group

} // namespace kk2

#endif // KK2_MATH_GROUP_SUM_WITH_SIZE_HPP

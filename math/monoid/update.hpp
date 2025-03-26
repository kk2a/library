#ifndef KK2_MATH_MONOID_UPDATE_HPP
#define KK2_MATH_MONOID_UPDATE_HPP 1

#include "../../type_traits/type_traits.hpp"

namespace kk2 {

namespace monoid {

template <class S>
struct Update {
    static constexpr bool commutative = true;
    S a;
    bool is_unit;

    Update() : is_unit(true) {}

    Update(S a_) : a(a_), is_unit(false) {}

    operator S() const { return a; }

    inline static Update op(Update l, Update r) { return l.is_unit ? r : l; }

    inline static Update unit() { return Update(); }

    template <class OStream, is_ostream_t<OStream> * = nullptr>
    friend OStream &operator<<(OStream &os, const Update &update) {
        if (update.is_unit) os << "unit";
        else os << update.a;
        return os;
    }

    template <class IStream, is_istream_t<IStream> * = nullptr>
    friend IStream &operator>>(IStream &is, Update &update) {
        is >> update.a;
        update.is_unit = false;
        return is;
    }

    bool operator==(const Update &rhs) const {
        return is_unit == rhs.is_unit and (is_unit or a == rhs.a);
    }

    bool operator!=(const Update &rhs) const { return !(*this == rhs); }
};

} // namespace monoid

} // namespace kk2

#endif // KK2_MATH_MONOID_UPDATE_HPP

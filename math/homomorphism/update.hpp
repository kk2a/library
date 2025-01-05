#ifndef KK2_MATH_HOMOMORPHISM_UPDATE_HPP
#define KK2_MATH_HOMOMORPHISM_UPDATE_HPP 1

#include <iostream>

namespace kk2 {

namespace homomorphism {

template <class S> struct Update {
    S a;
    bool id;

    constexpr Update() : a(S()), id(true) {}

    constexpr Update(S a_, bool id_ = false) : a(a_), id(id_) {}

    operator S() const { return a; }

    template <class OStream> friend OStream &operator<<(OStream &os, const Update &update) {
        if (update.id) os << "id";
        else os << update.a;
        return os;
    }
};

template <class S, class T> constexpr T UpdateMap(Update<S> f, T x) {
    return f.id ? x : x.update(f.a);
}

template <class S> constexpr Update<S> UpdateComposition(Update<S> l, Update<S> r) {
    if (l.id) return r;
    return l;
}

template <class S> Update<S> UpdateUnit() {
    constexpr static Update<S> e = Update<S>();
    return e;
}

} // namespace homomorphism

} // namespace kk2

#endif // KK2_MATH_HOMOMORPHISM_UPDATE_HPP

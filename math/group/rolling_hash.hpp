#ifndef KK2_MATH_GROUP_ROLLING_HASH_HPP
#define KK2_MATH_GROUP_ROLLING_HASH_HPP 1

#include <vector>

#include "../../random/hash.hpp"
#include "../../type_traits/container_traits.hpp"
#include "../../type_traits/integral.hpp"

namespace kk2 {

namespace group {

template <int Num> struct RollingHash {
    static constexpr bool commutative = false;
    using mint = ModInt2_61m1;
    using M = RollingHash;
    using H = random::Hash<Num>;

    inline static H base = H::get_base(), inv_base = base.inv();

    H a, pw, ipw;
    RollingHash() : a(0), pw(1), ipw(1) {}
    RollingHash(H a_, H pw_, H ipw_) : a(a_), pw(pw_), ipw(ipw_) {}
    template <class T, is_integral_t<T> * = nullptr> RollingHash(T x)
        : a(x),
          pw(base),
          ipw(inv_base) {}

    // s[0] * base^0 + s[1] * base^1 + ... + s[n-1] * base^(n-1)
    template <class C, is_container_t<C> * = nullptr> RollingHash(const C &s)
        : a(0),
          pw(1),
          ipw(inv_base.pow(s.size())) {
        for (auto x : s) {
            a += pw * H(x);
            pw *= base;
        }
    }
    operator H() const { return a; }
    inline static M op(M l, M r) { return M(l.a + r.a * l.pw, l.pw * r.pw, l.ipw * r.ipw); }
    inline static M inv(M x) { return M(-x.ipw * x.a, x.ipw, x.pw); }
    inline static M unit() { return M(); }
    bool operator==(const M &rhs) const { return a == rhs.a and pw == rhs.pw and ipw == rhs.ipw; }
    bool operator!=(const M &rhs) const { return a != rhs.a or pw != rhs.pw or ipw != rhs.ipw; }

    template <class OStream, is_ostream_t<OStream> * = nullptr>
    void debug_output(OStream &os) const {
        os << "(" << a << ", " << pw << ", " << ipw << ")";
    }
};

} // namespace group

} // namespace kk2

#endif // KK2_MATH_GROUP_ROLLING_HASH_HPP

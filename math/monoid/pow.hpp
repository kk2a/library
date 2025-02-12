#ifndef KK2_MATH_MONOID_POW_HPP
#define KK2_MATH_MONOID_POW_HPP 1

namespace kk2 {

namespace monoid {

template <class M, M (*op)(M, M), M (*e)()>
M pow(M a, long long n) {
    M res = e();
    while (n > 0) {
        if (n & 1) res = op(res, a);
        if (n >>= 1) a = op(a, a);
    }
    return res;
}

} // namespace monoid


} // namespace kk2

#endif // KK2_MATH_MONOID_POW_HPP

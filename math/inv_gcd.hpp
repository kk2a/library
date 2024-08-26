#ifndef MATH_INV_GCD_HPP
#define MATH_INV_GCD_HPP 1

namespace kk2 {

pair<long long, long long> inv_gcd(long long a, long long b) {
    a = a % b;
    if (a == 0) return {b, 0};
    long long s = b, t = a;
    long long m0 = 0, m1 = 1;

    while (t) {
        long long u = s / t;
        swap(s -= t * u, t);
        swap(m0 -= u * m1, m1);
    }
    if (m0 < 0) m0 += b / s;
    return {s, m0};
}

} // namespace kk2

#endif // MATH_INV_GCD_HPP

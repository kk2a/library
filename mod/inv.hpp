#ifndef MOD_INV_HPP
#define MOD_INV_HPP 1

template <class T, class U>
constexpr long long mod_inversion(T a, U modulo) {
    long long s = modulo, t = a;
    long long m0 = 0, m1 = 1;
    while (t) {
        long long u = s / t;
        swap(s -= t * u, t);
        swap(m0 -= m1 * u, m1);
    }
    if (m0 < 0) m0 += modulo / s;
    return m0;
}

#endif // MOD_INV_HPP

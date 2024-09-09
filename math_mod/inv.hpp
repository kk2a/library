#ifndef MOD_INV_HPP
#define MOD_INV_HPP 1

#include <utility>

namespace kk2 {

// require: modulo >= 1
template <class T>
constexpr T mod_inversion(T a, T modulo) {
    a %= modulo;
    if (a < 0) a += modulo;
    T s = modulo, t = a;
    T m0 = 0, m1 = 1;
    while (t) {
        T u = s / t;
        std::swap(s -= t * u, t);
        std::swap(m0 -= m1 * u, m1);
    }
    if (m0 < 0) m0 += modulo;
    return m0;
}

} // namespace kk2

#endif // MOD_INV_HPP

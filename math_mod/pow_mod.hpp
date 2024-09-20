#ifndef MOD_POW_EXPR_HPP
#define MOD_POW_EXPR_HPP 1

namespace kk2 {

constexpr long long pow_mod(long long x, long long n, long long m) {
    if (m == 1) return 0;
    unsigned long long _m = (unsigned long long)(m);
    unsigned long long r = 1;
    unsigned long long y = (x % m + m) % m;
    while (n) {
        if (n & 1) r = (r * y) % _m;
        y = (y * y) % _m;
        n >>= 1;
    }
    return r;
}

} // namespace kk2

#endif // MOD_POW_EXPR_HPP

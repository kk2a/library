#ifndef MATH_PRIME_FACTRIZATION_HPP
#define MATH_PRIME_FACTRIZATION_HPP 1

#include <algorithm>
#include <map>
#include <numeric>
#include <utility>
#include <vector>

#include "../math_mod/pow_mod.hpp"
#include "../modint/mont_arb.hpp"
#include "../random/gen.hpp"
#include "is_prime.hpp"

namespace kk2 {

namespace number_theory {

using i64 = long long;
using u64 = unsigned long long;

template <class mint, class T> T pollard_rho(T n) {
    if (~n & 1) return 2;
    if (is_prime(n)) return n;
    if (mint::getmod() != n) mint::setmod(n);

    mint R, one = 1;
    auto f = [&](mint x) {
        return x * x + R;
    };
    auto _rng = [&]() {
        return kk2::random::rng(1, n);
    };
    while (true) {
        mint x, y, ys, q = one;
        R = _rng(), y = _rng();
        T g = 1;
        constexpr int m = 128;
        for (int r = 1; g == 1; r <<= 1) {
            x = y;
            for (int i = 0; i < r; i++) y = f(y);
            for (int k = 0; k < r && g == 1; k += m) {
                ys = y;
                for (int i = 0; i < std::min(m, r - k); i++) {
                    y = f(y);
                    q *= x - y;
                }
                g = std::gcd(q.val(), n);
            }
        }
        if (g == n) do {
                ys = f(ys);
                g = std::gcd((x - ys).val(), n);
            } while (g == 1);
        if (g != n) return g;
    }
    exit(1);
}

std::vector<i64> inner_factorize(i64 n) {
    using mint32 = ArbitraryLazyMontgomeryModInt<54355165>;
    using mint64 = ArbitraryLazyMontgomeryModInt64bit<54355165>;
    if (n == 1) return {};
    if (n < 0) n = -n;
    u64 p;
    if (n <= (1ll << 30)) {
        p = pollard_rho<mint32, unsigned int>(n);
    } else if (n <= (1ll << 62)) {
        p = pollard_rho<mint64, unsigned long long>(n);
    } else {
        exit(1);
    }
    if (p == n) return {i64(p)};
    auto l = inner_factorize(p);
    auto r = inner_factorize(n / p);
    std::copy(r.begin(), r.end(), std::back_inserter(l));
    return l;
}

std::vector<std::pair<i64, int>> factorize(i64 n) {
    auto tmp = inner_factorize(n);
    std::sort(tmp.begin(), tmp.end());
    std::vector<std::pair<i64, int>> res;
    for (int i = 0; i < tmp.size(); i++) {
        if (i == 0 or res.back().first != tmp[i]) {
            res.emplace_back(tmp[i], 1);
        } else {
            res.back().second++;
        }
    }
    return res;
}

std::map<i64, int> factorize_map(i64 n) {
    auto tmp = inner_factorize(n);
    std::map<i64, int> res;
    for (auto x : tmp) res[x]++;
    return res;
}

std::vector<i64> divisors(i64 n) {
    if (n == 0) return {};

    auto f = factorize(n);
    std::vector<i64> res = {1};
    for (auto [p, k] : f) {
        int sz = res.size();
        i64 x = 1;
        for (int i = 0; i < k; i++) {
            x *= p;
            for (int j = 0; j < sz; j++) { res.emplace_back(res[j] * x); }
        }
    }
    std::sort(res.begin(), res.end());
    return res;
}

} // namespace number_theory

using number_theory::divisors;
using number_theory::factorize;
using number_theory::factorize_map;

} // namespace kk2


#endif // MATH_PRIME_FACTRIZATION_HPP

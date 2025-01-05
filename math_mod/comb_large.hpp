#ifndef KK2_MATH_MOD_COMB_LARGE_HPP
#define KK2_MATH_MOD_COMB_LARGE_HPP 1

#include <algorithm>
#include <cassert>
#include <functional>
#include <vector>

#include "../fps/ntt_friendly.hpp"
#include "../fps/poly_sample_point_shift.hpp"
#include "../type_traits/type_traits.hpp"
#include "comb.hpp"

namespace kk2 {

template <class mint> struct CombLarge {
    using FPS = FormalPowerSeries<mint>;
    static constexpr int LOG_BLOCK_SIZE = 9;
    static constexpr int BLOCK_SIZE = 1 << LOG_BLOCK_SIZE;
    static constexpr int BLOCK_NUM = mint::getmod() >> LOG_BLOCK_SIZE;

    static inline int threshold = 2000000;

    CombLarge() = delete;

    static mint fact(int n) { return n <= threshold ? Comb<mint>::fact(n) : _large_fact(n); }

    static mint inv_fact(int n) {
        return n <= threshold ? Comb<mint>::ifact(n) : _large_fact(n).inv();
    }

    static mint binom(int n, int r) {
        if (r < 0 || r > n) return mint(0);
        return fact(n) * inv_fact(r) * inv_fact(n - r);
    }

    template <class T> static mint multinomial(std::vector<T> r) {
        static_assert(is_integral<T>::value, "T must be integral");
        long long n = 0;
        for (auto &x : r) {
            assert(x >= 0);
            n += x;
        }
        if (n >= mint::getmod()) return 0;
        mint res = fact(n);
        for (auto &x : r) res *= inv_fact(x);
        return res;
    }

    static mint permu(int n, int r) {
        if (r < 0 || r > n) return mint(0);
        return fact(n) * inv_fact(n - r);
    }

    static mint homo(int n, int r) {
        if (n < 0 || r < 0) return mint(0);
        return r == 0 ? 1 : binom(n + r - 1, r);
    }

  private:
    static inline std::vector<mint> _block_fact{};

    static void _build() {
        if (_block_fact.size()) return;
        std::vector<mint> f{1};
        f.reserve(BLOCK_SIZE);
        for (int i = 0; i < LOG_BLOCK_SIZE; i++) {
            std::vector<mint> g = SamplePointShift<FPS>(f, mint(1 << i), 3 << i);
            const auto get = [&](int j) {
                return j < (1 << i) ? f[j] : g[j - (1 << i)];
            };
            f.resize(2 << i);
            for (int j = 0; j < 2 << i; j++) {
                f[j] = get(2 * j) * get(2 * j + 1) * ((2 * j + 1) << i);
            }
        }

        if (BLOCK_NUM > BLOCK_SIZE) {
            std::vector<mint> g =
                SamplePointShift<FPS>(f, mint(BLOCK_SIZE), BLOCK_NUM - BLOCK_SIZE);
            std::move(std::begin(g), std::end(g), std::back_inserter(f));
        } else f.resize(BLOCK_NUM);
        for (int i = 0; i < BLOCK_NUM; i++) { f[i] *= mint(i + 1) * BLOCK_SIZE; }
        // f[i] = prod_{j = 1} ^ (BLOCK_SIZE) (i * BLOCK_SIZE + j)

        f.insert(std::begin(f), 1);
        for (int i = 1; i <= BLOCK_NUM; i++) { f[i] *= f[i - 1]; }
        _block_fact = std::move(f);
    }

    static mint _large_fact(int n) {
        _build();
        mint res;
        int q = n / BLOCK_SIZE, r = n % BLOCK_SIZE;
        if (2 * r <= BLOCK_SIZE) {
            res = _block_fact[q];
            for (int i = 0; i < r; i++) { res *= n - i; }
        } else if (q != BLOCK_NUM) {
            res = _block_fact[q + 1];
            mint den = 1;
            for (int i = 1; i <= BLOCK_SIZE - r; i++) { den *= n + i; }
            res /= den;
        } else {
            res = -1;
            mint den = 1;
            for (int i = mint::getmod() - 1; i > n; i++) { den *= i; }
            res /= den;
        }
        return res;
    }
};

} // namespace kk2

#endif // KK2_MATH_MOD_COMB_LARGE_HPP

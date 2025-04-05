#ifndef KK2_MATH_PRIME_TABLE_HPP
#define KK2_MATH_PRIME_TABLE_HPP 1

#include <algorithm>
#include <vector>

#include "sqrt_floor.hpp"

namespace kk2 {

struct PrimeTable {
  private:
    static inline int _n = 30;
    static inline std::vector<int> _primes{2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

  public:
    PrimeTable() = delete;

    // wheel sieve
    // reference: https://37zigen.com/wheel-sieve/
    static void set_upper(int m, int reserve_size = 26355867) {
        if (m <= _n) return;
        _n = std::max(m, 2 * _n);
        int sqrt_n = sqrt_floor(_n);
        int w = 1;
        std::vector<bool> iscoprime(sqrt_n, true);
        for (int i = 0; i < 9; i++) {
            if (w * _primes[i] > sqrt_n) break;
            w *= _primes[i];
            for (int j = _primes[i]; j < sqrt_n; j += _primes[i]) iscoprime[j] = false;
        }

        std::vector<int> idx_(w, -1);
        int s = 0;
        for (int i = 1; i < w; i++) {
            if (iscoprime[i]) idx_[i] = s++;
        }
        std::vector<int> coprimes(s);
        for (int i = 1; i < w; i++) {
            if (idx_[i] != -1) coprimes[idx_[i]] = i;
        }

        auto idx = [&](long long x) -> long long {
            if (idx_[x % w] == -1) return -1;
            return x / w * s + idx_[x % w];
        };

        auto val = [&](int i) {
            return i / s * w + coprimes[i % s];
        };

        int n = (_n + w - 1) / w * s;
        std::vector<int> _primes2;
        _primes2.reserve(reserve_size);
        std::vector<int> lpf(n, 0);
        for (int i = 1; i < n; i++) {
            int v = val(i);
            if (lpf[i] == 0) {
                lpf[i] = v;
                _primes2.push_back(lpf[i]);
            }

            for (const long long p : _primes2) {
                long long j = idx(p * v);
                if (j >= n) break;
                if (lpf[i] < p) break;
                lpf[j] = p;
            }
        }

        std::vector<int> tmp;
        tmp.reserve(_primes.size() + _primes2.size());
        std::set_union(_primes.begin(),
                       _primes.end(),
                       _primes2.begin(),
                       _primes2.end(),
                       std::back_inserter(tmp));
        _primes = std::move(tmp);
    }

    static const std::vector<int> &primes() { return _primes; }

    template <typename It> struct PrimeIt {
        It bg, ed;

        PrimeIt(It bg_, It ed_) : bg(bg_), ed(ed_) {}

        It begin() const { return bg; }

        It end() const { return ed; }

        int size() const { return ed - bg; }

        int operator[](int i) const { return bg[i]; }

        std::vector<int> to_vec() const { return std::vector<int>(bg, ed); }
    };

    static auto primes(int n) {
        if (n >= _n) set_upper(n);
        return PrimeIt(_primes.begin(), std::upper_bound(_primes.begin(), _primes.end(), n));
    }
};

} // namespace kk2

#endif // KK2_MATH_PRIME_TABLE_HPP

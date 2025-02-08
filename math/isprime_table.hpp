#ifndef KK2_MATH_ISPRIME_TABLE_HPP
#define KK2_MATH_ISPRIME_TABLE_HPP 1

#include <algorithm>
#include <cassert>
#include <vector>

namespace kk2 {

struct IsPrimeTable {
  private:
    static inline std::vector<int> _primes{};
    static inline std::vector<bool> _isprime{};

  public:
    IsPrimeTable() = delete;

    static void set_upper(int m, int reserve_size = 26355867) {
        if ((int)_isprime.size() == 0) _primes.reserve(reserve_size);
        if ((int)_isprime.size() > m) return;
        int start = std::max<int>(2, _isprime.size());

        _isprime.resize(m + 1, true);
        _isprime[0] = _isprime[1] = false;

        for (const int p : _primes) {
            if (p * p > m) break;
            for (int q = p * ((start + p - 1) / p); q <= m; q += p) _isprime[q] = false;
        }

        for (int p = start; p <= m; ++p) {
            if (!_isprime[p]) continue;
            _primes.push_back(p);
            if (1ll * p * p > m) continue;
            for (int q = p * p; q <= m; q += p) _isprime[q] = false;
        }
    }

    static const std::vector<int> &primes() { return _primes; }

    template <typename It>
    struct PrimeIt {
        It bg, ed;

        PrimeIt(It bg_, It ed_) : bg(bg_), ed(ed_) {}

        It begin() const { return bg; }

        It end() const { return ed; }

        int size() const { return ed - bg; }

        int operator[](int i) const { return bg[i]; }

        std::vector<int> to_vec() const { return std::vector<int>(bg, ed); }
    };

    static auto primes(int n) {
        if (n >= (int)_isprime.size()) set_upper(n);
        return PrimeIt(_primes.begin(), std::upper_bound(_primes.begin(), _primes.end(), n));
    }

    static bool isprime(int n) {
        assert(n < (int)_isprime.size() && n != 0);
        return _isprime[n];
    }
};

} // namespace kk2

#endif // KK2_MATH_ISPRIME_TABLE_HPP

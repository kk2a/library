#ifndef KK2_MATH_LPF_TABLE_HPP
#define KK2_MATH_LPF_TABLE_HPP 1

#include <algorithm>
#include <cassert>
#include <numeric>
#include <vector>

namespace kk2 {

struct LPFTable {
  private:
    static inline std::vector<int> _primes{2}, _lpf{};

  public:
    LPFTable() = delete;

    static void set_upper(int m, int reserve_size = 26355867) {
        if ((int)_lpf.size() == 0) _primes.reserve(reserve_size);
        if ((int)_lpf.size() > m) return;
        m = std::max<int>(2 * _lpf.size(), m);
        _lpf.resize(m + 1);
        iota(_lpf.begin(), _lpf.end(), 0);
        for (int i = 2; i <= m; i++) {
            if (_lpf[i] == i and _primes.back() < i) _primes.emplace_back(i);
            for (const long long p : _primes) {
                if (p * i > m) break;
                if (_lpf[i] < p) break;
                _lpf[p * i] = p;
            }
        }
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
        if (n >= (int)_lpf.size()) set_upper(n);
        return PrimeIt(_primes.begin(), std::upper_bound(_primes.begin(), _primes.end(), n));
    }

    static int lpf(int n) {
        assert(n > 1);
        if (n >= (int)_lpf.size()) set_upper(n);
        return _lpf[n];
    }

    static bool isprime(int n) {
        assert(n > 0);
        if (n >= (int)_lpf.size()) set_upper(n);
        return n != 1 and _lpf[n] == n;
    }
};

} // namespace kk2


#endif // KK2_MATH_LPF_TABLE_HPP

#ifndef KK2_MATH_LPF_TABLE_HPP
#define KK2_MATH_LPF_TABLE_HPP 1

#include <algorithm>
#include <cassert>
#include <numeric>
#include <vector>

namespace kk2 {

struct LPFTable {
  private:
    static inline std::vector<int> _primes{2}, _lpf{0, 1, 2}, _lpf_pow{0, 1, 2}, _v_lpf{0, 1, 1};

  public:
    LPFTable() = delete;

    static void set_upper(int m, int reserve_size = 26355867) {
        if ((int)_lpf.size() == 0) _primes.reserve(reserve_size);
        if ((int)_lpf.size() > m) return;
        m = std::max<int>(2 * _lpf.size(), m);
        _lpf_pow.resize(m + 1);
        _v_lpf.resize(m + 1);
        _lpf.resize(m + 1);
        iota(_lpf.begin(), _lpf.end(), 0);
        for (int i = 2; i <= m; i++) {
            if (_lpf[i] == i and i > (int)_primes.back())
                _primes.emplace_back(i), _lpf_pow[i] = i, _v_lpf[i] = 1;
            for (const long long p : _primes) {
                if (p * i > m) break;
                if (_lpf[i] < p) break;
                _lpf[p * i] = p;
                if (_lpf[i] == p) {
                    _v_lpf[p * i] = _v_lpf[i] + 1;
                    _lpf_pow[p * i] = _lpf_pow[i] * p;
                } else {
                    _v_lpf[p * i] = 1;
                    _lpf_pow[p * i] = p;
                }
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

    static int lpf_pow(int n) {
        assert(n > 1);
        if (n >= (int)_lpf_pow.size()) set_upper(n);
        return _lpf_pow[n];
    }

    static int v_lpf(int n) {
        assert(n > 1);
        if (n >= (int)_v_lpf.size()) set_upper(n);
        return _v_lpf[n];
    }
};

} // namespace kk2


#endif // KK2_MATH_LPF_TABLE_HPP

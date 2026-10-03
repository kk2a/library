#ifndef KK2_MATH_LPF_TABLE_HPP
#define KK2_MATH_LPF_TABLE_HPP 1

#include <algorithm>
#include <cassert>
#include <limits>
#include <vector>

#include "../common/type_alias.hpp"
#include "multiplicative_function/prime_counting.hpp"

namespace kk2 {

struct LPFTable {
  private:
    static inline std::vector<u32> _primes{2}, _lpf{0, 1, 2};

  public:
    LPFTable() = delete;

    static void set_upper(usize m) {
        if (_lpf.size() > m) return;
        m = std::max<usize>(2 * _lpf.size(), m);
        assert(m <= static_cast<usize>(std::numeric_limits<u32>::max()));
        usize reserve_target = static_cast<usize>(prime_counting(static_cast<i64>(m)));
        if (_primes.capacity() < reserve_target) _primes.reserve(reserve_target);
        _lpf.resize(m + 1);
        const u32 upper = static_cast<u32>(m);
        for (usize index = 2; index <= m; ++index) {
            const u32 i = static_cast<u32>(index);
            if (_lpf[index] == 0) {
                _lpf[index] = i;
                _primes.emplace_back(i);
            }
            for (const u32 p : _primes) {
                const u64 pi = static_cast<u64>(p) * i;
                if (pi > upper) break;
                const usize product = static_cast<usize>(pi);
                if (_lpf[index] < p) break;
                _lpf[product] = p;
            }
        }
    }

    static const std::vector<u32> &primes() { return _primes; }

    template <typename It> struct PrimeIt {
        It bg, ed;
        PrimeIt(It bg_, It ed_) : bg(bg_), ed(ed_) {}
        It begin() const { return bg; }
        It end() const { return ed; }
        usize size() const { return static_cast<usize>(ed - bg); }
        u32 operator[](usize i) const { return bg[i]; }
        std::vector<u32> to_vec() const { return std::vector<u32>(bg, ed); }
    };

    static auto primes(usize n) {
        if (n >= _lpf.size()) set_upper(n);
        const u32 upper = static_cast<u32>(n);
        return PrimeIt(_primes.begin(), std::upper_bound(_primes.begin(), _primes.end(), upper));
    }

    static u32 lpf(u32 n) {
        assert(n > 1);
        if (static_cast<usize>(n) >= _lpf.size()) set_upper(static_cast<usize>(n));
        return _lpf[n];
    }

    static bool isprime(u32 n) {
        assert(n > 0);
        if (static_cast<usize>(n) >= _lpf.size()) set_upper(static_cast<usize>(n));
        return n != 1 and _lpf[n] == n;
    }
};

} // namespace kk2


#endif // KK2_MATH_LPF_TABLE_HPP

#ifndef KK2_MATH_MULTIPLICATIVE_FUNCTION_PRIME_COUNTING_HPP
#define KK2_MATH_MULTIPLICATIVE_FUNCTION_PRIME_COUNTING_HPP 1

#include <vector>

#include "../../data_structure/my_bitset.hpp"
#include "../enumerate_quotients.hpp"

namespace kk2 {

namespace internal {

inline std::vector<int> prime_counting_base_primes(int n) {
    DynamicBitSet composite(n + 1);
    std::vector<int> primes;
    for (int p = 2; p <= n; ++p) {
        if (composite[p]) continue;
        primes.push_back(p);
        if (1LL * p * p <= n) {
            for (long long q = 1LL * p * p; q <= n; q += p) composite.set((int)q);
        }
    }
    return primes;
}

} // namespace internal

long long prime_counting(long long n) {
    if (n < 2) return 0;
    EnumerateQuotients<long long> eq(n);
    std::vector<int> primes = internal::prime_counting_base_primes(eq.sqrt_n);
    std::vector<long long> dp(eq.size());
    for (int i = 0; i < eq.size(); ++i) dp[i] = eq[i] - 1;
    for (const long long p : primes) {
        for (int i = eq.size() - 1;; --i) {
            if (eq[i] < p * p) break;
            dp[i] -= dp[eq.idx(eq[i] / p)] - dp[p - 2];
        }
    }
    return dp.back();
}

} // namespace kk2

#endif // KK2_MATH_MULTIPLICATIVE_FUNCTION_PRIME_COUNTING_HPP

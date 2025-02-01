#ifndef KK2_MATH_MULTIPLICATIVE_FUNCTION_PRIME_COUNTING_HPP
#define KK2_MATH_MULTIPLICATIVE_FUNCTION_PRIME_COUNTING_HPP 1

#include <vector>

#include "../Eratosthenes.hpp"
#include "../enumerate_quotients.hpp"

namespace kk2 {

long long prime_counting(long long n) {
    kk2::EnumerateQuotients<long long> eq(n);
    kk2::Erato::set_upper(eq.sqrt_n);
    std::vector<long long> dp(eq.size());
    for (int i = 0; i < eq.size(); ++i) dp[i] = eq[i] - 1;
    for (const long long p : kk2::Erato::primes()) {
        for (int i = eq.size() - 1;; --i) {
            if (eq[i] < p * p) break;
            dp[i] -= dp[eq.idx(eq[i] / p)] - dp[p - 2];
        }
    }
    return dp.back();
}

} // namespace kk2

#endif // KK2_MATH_MULTIPLICATIVE_FUNCTION_PRIME_COUNTING_HPP

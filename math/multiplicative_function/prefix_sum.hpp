#ifndef KK2_MATH_MULTIPLICATIVE_FUNCTION_PREFIX_SUM_HPP
#define KK2_MATH_MULTIPLICATIVE_FUNCTION_PREFIX_SUM_HPP 1

#include <algorithm>
#include <vector>

#include "../prime_table.hpp"
#include "../enumerate_quotients.hpp"

namespace kk2 {

template <class T>
struct PrefixSumOfMultiplicationFunction {
    long long n;
    EnumerateQuotients<long long> eq;
    std::vector<T> prefix_sum_only_prime;
    std::vector<T> prefix_sum;

    PrefixSumOfMultiplicationFunction(long long n)
        : n(n),
          eq(n),
          prefix_sum_only_prime(eq.size()),
          prefix_sum(eq.size()) {}

    int size() const { return eq.size(); }

    template <T (*f)(long long)>
    void LucyDP(std::vector<T> &dp, T a) {
        LucyDP([](long long x) { return f(x); }, dp);
    }

    // f is completely multiplicative function
    template <class F>
    void LucyDP(const F &f, std::vector<T> &dp) {
        assert((int)dp.size() == eq.size());
        PrimeTable::set_upper(eq.sqrt_n);
        for (const long long p : PrimeTable::primes()) {
            if (p > eq.sqrt_n) break;
            T fp = f(p);
            for (int i = eq.size() - 1;; --i) {
                if (eq[i] < p * p) break;
                dp[i] -= (dp[eq.idx(eq[i] / p)] - dp[p - 2]) * fp;
            }
        }
    }

    template <T (*f)(long long, long long)>
    void Min_25Sieve() {
        Min_25Sieve([](long long x, long long y) { return f(x, y); });
    }

    // f is multiplicative function
    template <class F>
    void Min_25Sieve(const F &f) {
        PrimeTable::set_upper(eq.sqrt_n);
        std::copy(prefix_sum_only_prime.begin(), prefix_sum_only_prime.end(), prefix_sum.begin());
        const auto &primes = PrimeTable::primes();
        std::vector<T> tmp(eq.size());
        for (int i = std::upper_bound(primes.begin(), primes.end(), eq.sqrt_n) - primes.begin() - 1;
             i >= 0;
             --i) {
            const long long p = primes[i];
            T pk = f(p, 1);
            T pk1;
            for (long long p_pw = p, k = 1; n / p >= p_pw; ++k, p_pw *= p) {
                T pk1 = f(p, k + 1);
                for (int j = eq.size() - 1;; --j) {
                    if (eq[j] < p_pw * p) break;
                    tmp[j] += pk * (prefix_sum[eq.idx(eq[j] / p_pw)] - prefix_sum_only_prime[p - 1])
                              + pk1;
                }
                pk = pk1;
            }
            for (int j = eq.size() - 1;; --j) {
                if (eq[j] < p * p) break;
                prefix_sum[j] += tmp[j];
                tmp[j] = T();
            }
        }
        for (int i = 0; i < eq.size(); ++i) ++prefix_sum[i];
    }
};

} // namespace kk2

#endif // KK2_MATH_MULTIPLICATIVE_FUNCTION_PREFIX_SUM_HPP

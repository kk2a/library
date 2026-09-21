#ifndef KK2_MATH_WHEEL_SIEVE_HPP
#define KK2_MATH_WHEEL_SIEVE_HPP 1

#include <algorithm>
#include <array>
#include <cstdint>
#include <vector>

#include "multiplicative_function/prime_counting.hpp"
#include "sqrt_floor.hpp"

namespace kk2 {

namespace number_theory {

inline std::vector<int> wheel_sieve(int n) {
    constexpr std::array<int, 10> seed_primes{2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
    if (n < 30) {
        return std::vector<int>(seed_primes.begin(),
                                std::upper_bound(seed_primes.begin(), seed_primes.end(), n));
    }

    int sqrt_n = sqrt_floor(n);
    int w = 1;
    std::vector<bool> iscoprime(sqrt_n, true);
    int wheel_prime_count = 0;
    while (wheel_prime_count < 9 && w * seed_primes[wheel_prime_count] <= sqrt_n) {
        w *= seed_primes[wheel_prime_count];
        for (int j = seed_primes[wheel_prime_count]; j < sqrt_n;
             j += seed_primes[wheel_prime_count]) {
            iscoprime[j] = false;
        }
        ++wheel_prime_count;
    }

    std::vector<int> idx_(w, -1);
    int s = 0;
    for (int i = 1; i < w; ++i) {
        if (iscoprime[i]) idx_[i] = s++;
    }
    std::vector<int> coprimes(s);
    for (int i = 1; i < w; ++i) {
        if (idx_[i] != -1) coprimes[idx_[i]] = i;
    }

    auto idx = [&](long long x) -> long long {
        if (idx_[x % w] == -1) return -1;
        return x / w * s + idx_[x % w];
    };
    auto val = [&](int i) {
        return i / s * w + coprimes[i % s];
    };

    int candidate_count = (n + w - 1) / w * s;
    while (candidate_count > 1 && val(candidate_count - 1) > n) --candidate_count;

    std::vector<int> primes;
    primes.reserve(prime_counting(n));
    for (int i = 0; i < wheel_prime_count; ++i) primes.push_back(seed_primes[i]);

    // A composite number not exceeding an int has a prime factor below 2^16.
    std::vector<std::uint16_t> lpf(candidate_count, 0);
    for (int i = 1; i < candidate_count; ++i) {
        int v = val(i);
        int least_prime = lpf[i] == 0 ? v : lpf[i];
        if (lpf[i] == 0) primes.push_back(v);

        for (int j = wheel_prime_count; j < (int)primes.size(); ++j) {
            int p = primes[j];
            long long index = idx(1LL * p * v);
            if (index >= candidate_count) break;
            if (least_prime < p) break;
            lpf[index] = static_cast<std::uint16_t>(p);
        }
    }
    return primes;
}

} // namespace number_theory

using number_theory::wheel_sieve;

} // namespace kk2

#endif // KK2_MATH_WHEEL_SIEVE_HPP

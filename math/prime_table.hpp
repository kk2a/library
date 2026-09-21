#ifndef KK2_MATH_PRIME_TABLE_HPP
#define KK2_MATH_PRIME_TABLE_HPP 1

#include "isprime_table.hpp"

namespace kk2 {

struct PrimeTable {
    PrimeTable() = delete;

    static void set_upper(int m) { IsPrimeTable::set_upper(m); }

    static auto primes() { return IsPrimeTable::primes(); }

    static auto primes(int n) { return IsPrimeTable::primes(n); }
};

} // namespace kk2

#endif // KK2_MATH_PRIME_TABLE_HPP

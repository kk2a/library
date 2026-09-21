// competitive-verifier: STANDALONE

#include "../../../math/wheel_sieve.hpp"

#include <cassert>
#include <vector>

#include "../../../math/prime_table.hpp"

int main() {
    std::vector<int> limits{0, 1, 2, 3, 29, 30, 31, 100, 1000, 100000, 1000000};
    for (int n : limits) {
        auto expected = kk2::PrimeTable::primes(n).to_vec();
        assert(kk2::wheel_sieve(n) == expected);
    }
    return 0;
}

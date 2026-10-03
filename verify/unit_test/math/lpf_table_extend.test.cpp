// competitive-verifier: STANDALONE

#include "../../../math/lpf_table.hpp"
#include "../../../math/multiplicative_function/prime_counting.hpp"
#include "../../../math/prime_factorize.hpp"
#include "../../../random/gen.hpp"
#include "../../../template/template.hpp"
using namespace std;

void test_basic_functionality() {
    // Test small primes
    assert(kk2::LPFTable::lpf(2) == 2);
    assert(kk2::LPFTable::lpf(3) == 3);
    assert(kk2::LPFTable::lpf(4) == 2);
    assert(kk2::LPFTable::lpf(5) == 5);
    assert(kk2::LPFTable::lpf(6) == 2);
    assert(kk2::LPFTable::lpf(7) == 7);
    assert(kk2::LPFTable::lpf(8) == 2);
    assert(kk2::LPFTable::lpf(9) == 3);
    assert(kk2::LPFTable::lpf(10) == 2);

    // Test isprime
    assert(kk2::LPFTable::isprime(2));
    assert(kk2::LPFTable::isprime(3));
    assert(!kk2::LPFTable::isprime(4));
    assert(kk2::LPFTable::isprime(5));
    assert(!kk2::LPFTable::isprime(6));
    assert(kk2::LPFTable::isprime(7));
    assert(!kk2::LPFTable::isprime(8));
    assert(!kk2::LPFTable::isprime(9));
    assert(!kk2::LPFTable::isprime(10));
    assert(!kk2::LPFTable::isprime(1));
}

void test_prime_generation() {
    // Test prime generation up to 100
    auto primes_100 = kk2::LPFTable::primes(100);
    vector<int> expected_primes = {2,  3,  5,  7,  11, 13, 17, 19, 23, 29, 31, 37, 41,
                                   43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
    assert(primes_100.size() == expected_primes.size());
    for (std::size_t i = 0; i < expected_primes.size(); i++) {
        assert(static_cast<int>(primes_100[i]) == expected_primes[i]);
    }

    // Test prime counting consistency
    assert((int)kk2::LPFTable::primes(10).size() == 4);  // 2, 3, 5, 7
    assert((int)kk2::LPFTable::primes(20).size() == 8);  // 2, 3, 5, 7, 11, 13, 17, 19
    assert((int)kk2::LPFTable::primes(30).size() == 10); // + 23, 29
}

void test_factorization_consistency() {
    // Test consistency with prime factorization
    for (int n = 2; n <= 1000; n++) {
        auto factors = kk2::factorize(n);
        assert(kk2::LPFTable::lpf(n) == factors[0].first);
    }
}

void test_large_numbers() {
    // Test with larger numbers
    int iter = 200;
    rep(iter) {
        int n = kk2::random::rng(2, 1000000);
        assert((int)kk2::LPFTable::primes(n).size() == kk2::prime_counting(n));
        assert(kk2::LPFTable::lpf(n) == kk2::factorize(n)[0].first);
    }
}

void test_edge_cases() {
    // Test large primes
    int large_prime = 1000003;
    assert(kk2::LPFTable::isprime(large_prime));
    assert(static_cast<int>(kk2::LPFTable::lpf(large_prime)) == large_prime);
}

int main() {
    test_basic_functionality();
    test_prime_generation();
    test_factorization_consistency();
    test_large_numbers();
    test_edge_cases();

    return 0;
}

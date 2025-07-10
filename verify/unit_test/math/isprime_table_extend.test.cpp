#define PROBLEM "https://judge.yosupo.jp/problem/aplusb" 

#include "../../../math/isprime_table.hpp"
#include "../../../math/multiplicative_function/prime_counting.hpp"
#include "../../../math/is_prime.hpp"
#include "../../../random/gen.hpp"
#include "../../../template/template.hpp"
using namespace std;

void test_basic_primality() {
    // Test small numbers
    assert(!kk2::IsPrimeTable::isprime(1));
    assert(kk2::IsPrimeTable::isprime(2));
    assert(kk2::IsPrimeTable::isprime(3));
    assert(!kk2::IsPrimeTable::isprime(4));
    assert(kk2::IsPrimeTable::isprime(5));
    assert(!kk2::IsPrimeTable::isprime(6));
    assert(kk2::IsPrimeTable::isprime(7));
    assert(!kk2::IsPrimeTable::isprime(8));
    assert(!kk2::IsPrimeTable::isprime(9));
    assert(!kk2::IsPrimeTable::isprime(10));
    
    // Test first 25 primes
    vector<int> first_primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
    for (int p : first_primes) {
        assert(kk2::IsPrimeTable::isprime(p));
    }
    
    // Test some composite numbers
    vector<int> composites = {4, 6, 8, 9, 10, 12, 14, 15, 16, 18, 20, 21, 22, 24, 25, 26, 27, 28, 30};
    for (int c : composites) {
        assert(!kk2::IsPrimeTable::isprime(c));
    }
}

void test_prime_generation() {
    // Test prime generation up to 100
    auto primes_100 = kk2::IsPrimeTable::primes(100);
    vector<int> expected_primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
    assert(primes_100.size() == expected_primes.size());
    for (int i = 0; i < (int)expected_primes.size(); i++) {
        assert(primes_100[i] == expected_primes[i]);
    }
    
    // Test prime counting for various ranges
    assert((int)kk2::IsPrimeTable::primes(10).size() == 4);   // 2, 3, 5, 7
    assert((int)kk2::IsPrimeTable::primes(20).size() == 8);   // + 11, 13, 17, 19
    assert((int)kk2::IsPrimeTable::primes(30).size() == 10);  // + 23, 29
    assert((int)kk2::IsPrimeTable::primes(50).size() == 15);  // + 31, 37, 41, 43, 47
    assert((int)kk2::IsPrimeTable::primes(100).size() == 25); // + 53, 59, 61, 67, 71, 73, 79, 83, 89, 97
}

void test_consistency_with_reference() {
    // Test consistency with reference is_prime function
    for (int n = 1; n <= 1000; n++) {
        assert(kk2::is_prime(n) == kk2::IsPrimeTable::isprime(n));
    }
}

void test_prime_counting_consistency() {
    // Test prime counting consistency
    for (int n = 2; n <= 10000; n += 100) {
        assert((int)kk2::IsPrimeTable::primes(n).size() == kk2::prime_counting(n));
    }
}

void test_large_primes() {
    // Test some known large primes
    vector<int> large_primes = {1009, 1013, 1019, 1021, 1031, 1033, 1039, 1049, 1051, 1061,
                               10007, 10009, 10037, 10039, 10061, 10067, 10069, 10079, 10091, 10093,
                               100003, 100019, 100043, 100049, 100057, 100069, 100103, 100109, 100129, 100151};
    
    for (int p : large_primes) {
        assert(kk2::IsPrimeTable::isprime(p));
        assert(kk2::is_prime(p)); // Double check with reference
    }
}

void test_large_composites() {
    // Test some large composite numbers
    vector<pair<int, string>> large_composites = {
        {1000, "2^3 * 5^3"},
        {10000, "2^4 * 5^4"},
        {100000, "2^5 * 5^5"},
        {999999, "3^3 * 7 * 11 * 13 * 37"},
        {1000000, "2^6 * 5^6"}
    };
    
    for (auto [n, desc] : large_composites) {
        assert(!kk2::IsPrimeTable::isprime(n));
        assert(!kk2::is_prime(n)); // Double check with reference
    }
}

void test_random_numbers() {
    // Test with random numbers
    int iter = 200;
    rep (iter) {
        int n = kk2::random::rng(1, 1000000);
        assert(kk2::is_prime(n) == kk2::IsPrimeTable::isprime(n));
    }
}

int main() {
    int a, b;
    kin >> a >> b;
    kout << a + b << kendl;

    test_basic_primality();
    test_prime_generation();
    test_consistency_with_reference();
    test_prime_counting_consistency();
    test_large_primes();
    test_large_composites();
    test_random_numbers();

    return 0;
}

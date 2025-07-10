#define PROBLEM "https://judge.yosupo.jp/problem/aplusb" 

#include "../../../math/prime_table.hpp"
#include "../../../math/multiplicative_function/prime_counting.hpp"
#include "../../../random/gen.hpp"
#include "../../../template/template.hpp"
using namespace std;

void test_basic_prime_generation() {
    // Test prime generation up to small limits
    auto primes_10 = kk2::PrimeTable::primes(10);
    vector<int> expected_10 = {2, 3, 5, 7};
    assert(primes_10.size() == expected_10.size());
    for (int i = 0; i < (int)expected_10.size(); i++) {
        assert(primes_10[i] == expected_10[i]);
    }
    
    auto primes_20 = kk2::PrimeTable::primes(20);
    vector<int> expected_20 = {2, 3, 5, 7, 11, 13, 17, 19};
    assert(primes_20.size() == expected_20.size());
    for (int i = 0; i < (int)expected_20.size(); i++) {
        assert(primes_20[i] == expected_20[i]);
    }
    
    auto primes_50 = kk2::PrimeTable::primes(50);
    vector<int> expected_50 = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
    assert(primes_50.size() == expected_50.size());
    for (int i = 0; i < (int)expected_50.size(); i++) {
        assert(primes_50[i] == expected_50[i]);
    }
}

void test_first_100_primes() {
    // Test first 100 primes up to 541
    auto primes_541 = kk2::PrimeTable::primes(541);
    vector<int> first_100_primes = {
        2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71,
        73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173,
        179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281,
        283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409,
        419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541
    };
    
    assert(primes_541.size() == 100);
    for (int i = 0; i < 100; i++) {
        assert(primes_541[i] == first_100_primes[i]);
    }
}

void test_prime_counting_properties() {
    // Test prime counting for various ranges
    assert((int)kk2::PrimeTable::primes(2).size() == 1);     // π(2) = 1
    assert((int)kk2::PrimeTable::primes(3).size() == 2);     // π(3) = 2
    assert((int)kk2::PrimeTable::primes(5).size() == 3);     // π(5) = 3
    assert((int)kk2::PrimeTable::primes(7).size() == 4);     // π(7) = 4
    assert((int)kk2::PrimeTable::primes(11).size() == 5);    // π(11) = 5
    assert((int)kk2::PrimeTable::primes(100).size() == 25);  // π(100) = 25
    assert((int)kk2::PrimeTable::primes(1000).size() == 168); // π(1000) = 168
}

void test_consistency_with_prime_counting() {
    // Test consistency with prime_counting function
    for (int n = 2; n <= 1000; n += 10) {
        assert((int)kk2::PrimeTable::primes(n).size() == kk2::prime_counting(n));
    }
    
    // Test some specific larger values
    vector<int> test_values = {1000, 2000, 5000, 10000, 20000, 50000, 100000};
    for (int n : test_values) {
        assert((int)kk2::PrimeTable::primes(n).size() == kk2::prime_counting(n));
    }
}

void test_monotonicity() {
    // Test that prime count is monotonically non-decreasing
    int prev_count = 0;
    for (int n = 2; n <= 1000; n++) {
        int curr_count = (int)kk2::PrimeTable::primes(n).size();
        assert(curr_count >= prev_count);
        prev_count = curr_count;
    }
}

void test_prime_properties() {
    // Test that all returned numbers are actually prime
    auto primes_1000 = kk2::PrimeTable::primes(1000);
    for (int i = 0; i < primes_1000.size(); i++) {
        int p = primes_1000[i];
        
        // Check basic primality (simple trial division for verification)
        bool is_prime = (p > 1);
        if (p > 2 && p % 2 == 0) is_prime = false;
        for (int d = 3; d * d <= p && is_prime; d += 2) {
            if (p % d == 0) is_prime = false;
        }
        assert(is_prime);
        
        // Check ordering (primes should be in ascending order)
        if (i > 0) {
            assert(primes_1000[i] > primes_1000[i-1]);
        }
    }
}

void test_edge_cases() {
    // Test edge cases
    auto primes_1 = kk2::PrimeTable::primes(1);
    assert(primes_1.size() == 0); // No primes ≤ 1
    
    auto primes_2 = kk2::PrimeTable::primes(2);
    assert(primes_2.size() == 1 && primes_2[0] == 2);
    
    // Test twin primes
    auto primes_100 = kk2::PrimeTable::primes(100);
    vector<pair<int, int>> twin_primes = {{3, 5}, {5, 7}, {11, 13}, {17, 19}, {29, 31}, {41, 43}, {59, 61}, {71, 73}};
    for (auto [p1, p2] : twin_primes) {
        bool found_p1 = false, found_p2 = false;
        for (int i = 0; i < primes_100.size(); i++) {
            if (primes_100[i] == p1) found_p1 = true;
            if (primes_100[i] == p2) found_p2 = true;
        }
        assert(found_p1 && found_p2);
    }
}

void test_random_large_numbers() {
    // Test with larger random numbers
    int iter = 100;
    rep (iter) {
        int n = kk2::random::rng(2, 1000000);
        assert((int)kk2::PrimeTable::primes(n).size() == kk2::prime_counting(n));
    }
}

int main() {
    int a, b;
    kin >> a >> b;
    kout << a + b << kendl;

    test_basic_prime_generation();
    test_first_100_primes();
    test_prime_counting_properties();
    test_consistency_with_prime_counting();
    test_monotonicity();
    test_prime_properties();
    test_edge_cases();
    test_random_large_numbers();

    return 0;
}

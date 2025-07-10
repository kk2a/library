#define PROBLEM "https://judge.yosupo.jp/problem/aplusb" 

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
    
    // Test lpf_pow
    assert(kk2::LPFTable::lpf_pow(2) == 2);
    assert(kk2::LPFTable::lpf_pow(3) == 3);
    assert(kk2::LPFTable::lpf_pow(4) == 4);  // 2^2
    assert(kk2::LPFTable::lpf_pow(5) == 5);
    assert(kk2::LPFTable::lpf_pow(6) == 2);  // 2*3
    assert(kk2::LPFTable::lpf_pow(7) == 7);
    assert(kk2::LPFTable::lpf_pow(8) == 8);  // 2^3
    assert(kk2::LPFTable::lpf_pow(9) == 9);  // 3^2
    assert(kk2::LPFTable::lpf_pow(12) == 4); // 2^2*3
    assert(kk2::LPFTable::lpf_pow(16) == 16); // 2^4
    assert(kk2::LPFTable::lpf_pow(18) == 2);  // 2*3^2
    assert(kk2::LPFTable::lpf_pow(27) == 27); // 3^3
    
    // Test v_lpf
    assert(kk2::LPFTable::v_lpf(2) == 1);
    assert(kk2::LPFTable::v_lpf(3) == 1);
    assert(kk2::LPFTable::v_lpf(4) == 2);  // 2^2
    assert(kk2::LPFTable::v_lpf(5) == 1);
    assert(kk2::LPFTable::v_lpf(6) == 1);  // 2*3
    assert(kk2::LPFTable::v_lpf(7) == 1);
    assert(kk2::LPFTable::v_lpf(8) == 3);  // 2^3
    assert(kk2::LPFTable::v_lpf(9) == 2);  // 3^2
    assert(kk2::LPFTable::v_lpf(12) == 2); // 2^2*3
    assert(kk2::LPFTable::v_lpf(16) == 4); // 2^4
    assert(kk2::LPFTable::v_lpf(18) == 1); // 2*3^2
    assert(kk2::LPFTable::v_lpf(27) == 3); // 3^3
}

void test_prime_generation() {
    // Test prime generation up to 100
    auto primes_100 = kk2::LPFTable::primes(100);
    vector<int> expected_primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
    assert(primes_100.size() == (int)expected_primes.size());
    for (int i = 0; i < (int)expected_primes.size(); i++) {
        assert(primes_100[i] == expected_primes[i]);
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
        
        // Check if lpf_pow and v_lpf are consistent
        int expected_lpf_pow = 1;
        int expected_v_lpf = 0;
        for (auto [p, e] : factors) {
            if (p == kk2::LPFTable::lpf(n)) {
                expected_v_lpf = e;
                for (int i = 0; i < e; i++) {
                    expected_lpf_pow *= p;
                }
                break;
            }
        }
        assert(kk2::LPFTable::lpf_pow(n) == expected_lpf_pow);
        assert(kk2::LPFTable::v_lpf(n) == expected_v_lpf);
    }
}

void test_large_numbers() {
    // Test with larger numbers
    int iter = 200;
    rep (iter) {
        int n = kk2::random::rng(2, 1000000);
        assert((int)kk2::LPFTable::primes(n).size() == kk2::prime_counting(n));
        assert(kk2::LPFTable::lpf(n) == kk2::factorize(n)[0].first);
        
        // Additional consistency checks
        auto factors = kk2::factorize(n);
        int lpf = kk2::LPFTable::lpf(n);
        int v_lpf = kk2::LPFTable::v_lpf(n);
        int lpf_pow = kk2::LPFTable::lpf_pow(n);
        
        // Check v_lpf
        int expected_v = 0;
        for (auto [p, e] : factors) {
            if (p == lpf) {
                expected_v = e;
                break;
            }
        }
        assert(v_lpf == expected_v);
        
        // Check lpf_pow
        int expected_pow = 1;
        for (int i = 0; i < v_lpf; i++) {
            expected_pow *= lpf;
        }
        assert(lpf_pow == expected_pow);
        
        // Check that n is divisible by lpf_pow
        assert(n % lpf_pow == 0);
        
        // Check that n/lpf_pow is not divisible by lpf
        if (n / lpf_pow > 1) {
            assert((n / lpf_pow) % lpf != 0);
        }
    }
}

void test_edge_cases() {
    // Test perfect powers
    assert(kk2::LPFTable::lpf_pow(32) == 32);  // 2^5
    assert(kk2::LPFTable::v_lpf(32) == 5);
    
    assert(kk2::LPFTable::lpf_pow(243) == 243); // 3^5
    assert(kk2::LPFTable::v_lpf(243) == 5);
    
    // Test products of different primes
    assert(kk2::LPFTable::lpf_pow(30) == 2);    // 2*3*5
    assert(kk2::LPFTable::v_lpf(30) == 1);
    
    assert(kk2::LPFTable::lpf_pow(210) == 2);   // 2*3*5*7
    assert(kk2::LPFTable::v_lpf(210) == 1);
    
    // Test large primes
    int large_prime = 1000003;
    assert(kk2::LPFTable::isprime(large_prime));
    assert(kk2::LPFTable::lpf(large_prime) == large_prime);
    assert(kk2::LPFTable::lpf_pow(large_prime) == large_prime);
    assert(kk2::LPFTable::v_lpf(large_prime) == 1);
}

int main() {
    int a, b;
    kin >> a >> b;
    kout << a + b << kendl;

    test_basic_functionality();
    test_prime_generation();
    test_factorization_consistency();
    test_large_numbers();
    test_edge_cases();

    return 0;
}

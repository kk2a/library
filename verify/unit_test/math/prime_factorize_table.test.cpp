#define PROBLEM "https://judge.yosupo.jp/problem/aplusb" 

#include "../../../math/prime_factorize_table.hpp"
#include "../../../math/prime_factorize.hpp"
#include "../../../random/gen.hpp"
#include "../../../template/template.hpp"
using namespace std;

void test_basic_factorization() {
    // Test small numbers
    auto f2 = kk2::FactorizeTable::factorize(2);
    assert(f2.size() == 1 && f2[0].first == 2 && f2[0].second == 1);
    
    auto f3 = kk2::FactorizeTable::factorize(3);
    assert(f3.size() == 1 && f3[0].first == 3 && f3[0].second == 1);
    
    auto f4 = kk2::FactorizeTable::factorize(4);
    assert(f4.size() == 1 && f4[0].first == 2 && f4[0].second == 2);
    
    auto f6 = kk2::FactorizeTable::factorize(6);
    assert(f6.size() == 2 && f6[0].first == 2 && f6[0].second == 1 && f6[1].first == 3 && f6[1].second == 1);
    
    auto f8 = kk2::FactorizeTable::factorize(8);
    assert(f8.size() == 1 && f8[0].first == 2 && f8[0].second == 3);
    
    auto f12 = kk2::FactorizeTable::factorize(12);
    assert(f12.size() == 2 && f12[0].first == 2 && f12[0].second == 2 && f12[1].first == 3 && f12[1].second == 1);
    
    auto f30 = kk2::FactorizeTable::factorize(30);
    assert(f30.size() == 3 && f30[0].first == 2 && f30[0].second == 1 && 
           f30[1].first == 3 && f30[1].second == 1 && f30[2].first == 5 && f30[2].second == 1);
}

void test_perfect_powers() {
    // Test perfect powers
    auto f16 = kk2::FactorizeTable::factorize(16); // 2^4
    assert(f16.size() == 1 && f16[0].first == 2 && f16[0].second == 4);
    
    auto f27 = kk2::FactorizeTable::factorize(27); // 3^3
    assert(f27.size() == 1 && f27[0].first == 3 && f27[0].second == 3);
    
    auto f125 = kk2::FactorizeTable::factorize(125); // 5^3
    assert(f125.size() == 1 && f125[0].first == 5 && f125[0].second == 3);
    
    auto f1024 = kk2::FactorizeTable::factorize(1024); // 2^10
    assert(f1024.size() == 1 && f1024[0].first == 2 && f1024[0].second == 10);
}

void test_prime_numbers() {
    // Test prime numbers
    vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
    for (int p : primes) {
        auto fp = kk2::FactorizeTable::factorize(p);
        assert(fp.size() == 1 && fp[0].first == p && fp[0].second == 1);
    }
}

void test_consistency_with_reference() {
    // Test consistency with reference implementation
    for (int n = 2; n <= 1000; n++) {
        auto f = kk2::factorize(n);
        auto f1 = kk2::FactorizeTable::factorize(n);
        assert(f.size() == f1.size());
        for (int i = 0; i < (int)f.size(); i++) {
            assert(f[i].first == f1[i].first);
            assert(f[i].second == f1[i].second);
        }
        
        // Verify that the factorization is correct
        long long product = 1;
        for (auto [p, e] : f1) {
            for (int i = 0; i < e; i++) {
                product *= p;
            }
        }
        assert(product == n);
    }
}

void test_large_numbers() {
    // Test with larger random numbers
    int iter = 200;
    rep (iter) {
        int n = kk2::random::rng(2, 1000000);
        auto f = kk2::factorize(n);
        auto f1 = kk2::FactorizeTable::factorize(n);
        assert(f.size() == f1.size());
        for (int i = 0; i < (int)f.size(); i++) {
            assert(f[i].first == f1[i].first);
            assert(f[i].second == f1[i].second);
        }
        
        // Verify correctness
        long long product = 1;
        for (auto [p, e] : f1) {
            for (int i = 0; i < e; i++) {
                product *= p;
                if (product > n) break; // Avoid overflow
            }
            if (product > n) break;
        }
        if (product <= n) assert(product == n);
    }
}

void test_edge_cases() {
    // Test highly composite numbers
    auto f60 = kk2::FactorizeTable::factorize(60); // 2^2 * 3 * 5
    assert(f60.size() == 3 && f60[0].first == 2 && f60[0].second == 2 && 
           f60[1].first == 3 && f60[1].second == 1 && f60[2].first == 5 && f60[2].second == 1);
    
    auto f120 = kk2::FactorizeTable::factorize(120); // 2^3 * 3 * 5
    assert(f120.size() == 3 && f120[0].first == 2 && f120[0].second == 3 && 
           f120[1].first == 3 && f120[1].second == 1 && f120[2].first == 5 && f120[2].second == 1);
    
    auto f210 = kk2::FactorizeTable::factorize(210); // 2 * 3 * 5 * 7
    assert(f210.size() == 4 && f210[0].first == 2 && f210[0].second == 1 && 
           f210[1].first == 3 && f210[1].second == 1 && f210[2].first == 5 && f210[2].second == 1 &&
           f210[3].first == 7 && f210[3].second == 1);
}

int main() {
    int a, b;
    kin >> a >> b;
    kout << a + b << kendl;

    test_basic_factorization();
    test_perfect_powers();
    test_prime_numbers();
    test_consistency_with_reference();
    test_large_numbers();
    test_edge_cases();

    return 0;
}

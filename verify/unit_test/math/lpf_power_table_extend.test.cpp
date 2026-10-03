// competitive-verifier: STANDALONE

#include "../../../math/lpf_power_table.hpp"
#include "../../../math/prime_factorize.hpp"
#include "../../../random/gen.hpp"
#include "../../../template/template.hpp"

using namespace std;

void test_basic_functionality() {
    assert(kk2::LPFPowerTable::lpf_pow(2) == 2);
    assert(kk2::LPFPowerTable::lpf_pow(3) == 3);
    assert(kk2::LPFPowerTable::lpf_pow(4) == 4);
    assert(kk2::LPFPowerTable::lpf_pow(6) == 2);
    assert(kk2::LPFPowerTable::lpf_pow(8) == 8);
    assert(kk2::LPFPowerTable::lpf_pow(9) == 9);
    assert(kk2::LPFPowerTable::lpf_pow(12) == 4);
    assert(kk2::LPFPowerTable::lpf_pow(18) == 2);
    assert(kk2::LPFPowerTable::lpf_pow(27) == 27);

    assert(kk2::LPFPowerTable::v_lpf(2) == 1);
    assert(kk2::LPFPowerTable::v_lpf(4) == 2);
    assert(kk2::LPFPowerTable::v_lpf(6) == 1);
    assert(kk2::LPFPowerTable::v_lpf(8) == 3);
    assert(kk2::LPFPowerTable::v_lpf(9) == 2);
    assert(kk2::LPFPowerTable::v_lpf(12) == 2);
    assert(kk2::LPFPowerTable::v_lpf(18) == 1);
    assert(kk2::LPFPowerTable::v_lpf(27) == 3);
}

void test_factorization_consistency() {
    int iter = 200;
    rep(iter) {
        int n = kk2::random::rng(2, 1000000);
        auto factors = kk2::factorize(n);
        int lpf = static_cast<int>(kk2::LPFTable::lpf(n));
        int v_lpf = static_cast<int>(kk2::LPFPowerTable::v_lpf(n));
        int lpf_pow = static_cast<int>(kk2::LPFPowerTable::lpf_pow(n));

        int expected_v = 0;
        for (auto [p, e] : factors) {
            if (p == lpf) {
                expected_v = e;
                break;
            }
        }
        assert(v_lpf == expected_v);

        int expected_pow = 1;
        for (int i = 0; i < v_lpf; i++) expected_pow *= lpf;
        assert(lpf_pow == expected_pow);
        assert(n % lpf_pow == 0);
        if (n / lpf_pow > 1) assert((n / lpf_pow) % lpf != 0);
    }
}

void test_edge_cases() {
    assert(kk2::LPFPowerTable::lpf_pow(32) == 32);
    assert(kk2::LPFPowerTable::v_lpf(32) == 5);
    assert(kk2::LPFPowerTable::lpf_pow(243) == 243);
    assert(kk2::LPFPowerTable::v_lpf(243) == 5);

    assert(kk2::LPFPowerTable::lpf_pow(30) == 2);
    assert(kk2::LPFPowerTable::v_lpf(30) == 1);
    assert(kk2::LPFPowerTable::lpf_pow(210) == 2);
    assert(kk2::LPFPowerTable::v_lpf(210) == 1);

    int large_prime = 1000003;
    assert(static_cast<int>(kk2::LPFPowerTable::lpf_pow(large_prime)) == large_prime);
    assert(kk2::LPFPowerTable::v_lpf(large_prime) == 1);
}

int main() {
    test_basic_functionality();
    test_factorization_consistency();
    test_edge_cases();
    return 0;
}

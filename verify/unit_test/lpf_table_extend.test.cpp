#define PROBLEM "https://judge.yosupo.jp/problem/aplusb" 

#include "../../math/lpf_table.hpp"
#include "../../math/multiplicative_function/prime_counting.hpp"
#include "../../math/prime_factorize.hpp"
#include "../../random/gen.hpp"
#include "../../template/template.hpp"
using namespace std;

int main() {
    int a, b;
    kin >> a >> b;
    kout << a << " " << b << kendl;

    int iter = 1000;
    rep (iter) {
        int n = kk2::random::rng(2, 10000000);
        assert((int)kk2::LPFTable::primes(n).size() == kk2::prime_counting(n));
    }

    rep (iter) {
        int n = kk2::random::rng(2, 10000000);
        assert(kk2::LPFTable::lpf(n) == kk2::factorize(n)[0].first);
    }

    return 0;
}

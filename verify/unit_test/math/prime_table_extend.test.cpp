#define PROBLEM "https://judge.yosupo.jp/problem/aplusb" 

#include "../../../math/prime_table.hpp"
#include "../../../math/multiplicative_function/prime_counting.hpp"
#include "../../../random/gen.hpp"
#include "../../../template/template.hpp"
using namespace std;

int main() {
    int a, b;
    kin >> a >> b;
    kout << a + b << kendl;

    int iter = 1000;
    rep (iter) {
        int n = kk2::random::rng(2, 10000000);
        assert((int)kk2::PrimeTable::primes(n).size() == kk2::prime_counting(n));
    }

    return 0;
}

#define PROBLEM "https://judge.yosupo.jp/problem/aplusb" 

#include "../../../../math/multiplicative_function/famous_function_table.hpp"
#include "../../../../math/multiplicative_function/mobius.hpp"
#include "../../../../math/multiplicative_function/sigma.hpp"
#include "../../../../math/multiplicative_function/euler_phi.hpp"
#include "../../../../random/gen.hpp"
#include "../../../../template/template.hpp"
using namespace std;

int main() {
    int a, b;
    kin >> a >> b;
    kout << a + b << kendl;

    int iter = 1000;
    rep (iter) {
        int n = kk2::random::rng(2, 1000000);
        assert(kk2::FamousFunctionTable::euler_phi(n) == kk2::euler_phi(n));
        assert(kk2::FamousFunctionTable::mobius(n) == kk2::mobius(n));
        assert(kk2::FamousFunctionTable::sigma0(n) == kk2::sigma0(n));
        assert(kk2::FamousFunctionTable::sigma1(n) == kk2::sigma1(n));
    }

    return 0;
}

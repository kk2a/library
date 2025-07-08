#define PROBLEM "https://judge.yosupo.jp/problem/aplusb" 

#include "../../../../math/multiplicative_function/famous_function_table.hpp"
#include "../../../../math/multiplicative_function/famous_function.hpp"
#include "../../../../math/multiplicative_function/arbitrary_table.hpp"
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

        assert((kk2::MultiplicativeFunctionTable<long long, kk2::mf::mobius>::val(n) == kk2::FamousFunctionTable::mobius(n)));
        assert((kk2::MultiplicativeFunctionTable<long long, kk2::mf::euler_phi>::val(n) == kk2::FamousFunctionTable::euler_phi(n)));
        assert((kk2::MultiplicativeFunctionTable<long long, kk2::mf::sigma0>::val(n) == kk2::FamousFunctionTable::sigma0(n)));
        assert((kk2::MultiplicativeFunctionTable<long long, kk2::mf::sigma1>::val(n) == kk2::FamousFunctionTable::sigma1(n)));
    }

    return 0;
}

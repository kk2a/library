#define PROBLEM "https://judge.yosupo.jp/problem/aplusb" 

#include "../../../math/prime_factorize_table.hpp"
#include "../../../math/prime_factorize.hpp"
#include "../../../random/gen.hpp"
#include "../../../template/template.hpp"
using namespace std;

int main() {
    int a, b;
    kin >> a >> b;
    kout << a + b << kendl;

    int iter = 1000;
    rep (iter) {
        int n = kk2::random::rng(2, 1000000);
        auto f = kk2::factorize(n);
        auto f1 = kk2::FactorizeTable::factorize(n);
        int s = f.size();
        rep (i, s) {
            assert(f[i].first == f1[i].first);
            assert(f[i].second == f1[i].second);
        }
    }

    return 0;
}

#define PROBLEM "https://judge.yosupo.jp/problem/binomial_coefficient_prime_mod" 

#include "../../math_mod/comb.hpp"
#include "../../modint/modint.hpp"
#include "../../template/template.hpp"
using namespace std;

using mint = kk2::ModInt<0>;

int main() {
    int t, m;
    kin >> t >> m;
    mint::setmod(m);
    kk2::Comb<mint>::set_upper(1e7);
    rep (t) {
        int n, k;
        kin >> n >> k;
        kout << kk2::Comb<mint>::binom(n, k) << "\n";
    }

    return 0;
}

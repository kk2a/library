#define PROBLEM "https://judge.yosupo.jp/problem/sum_of_multiplicative_function" 

#include "../../math/multiplicative_function/prefix_sum.hpp"
#include "../../modint/mont.hpp"
#include "../../template/template.hpp"
using namespace std;

using mint = kk2::Mont<469762049>;

int main() {
    int t;
    kin >> t;
    rep (t) {
        i64 n;
        mint a, b;
        kin >> n >> a >> b;
        auto f = [&](i64 p, i64 e) -> mint { return a * e + b * p; };
        auto g1 = [&](i64) -> mint { return 1; };
        auto g2 = [&](i64 p) -> mint { return p; };
        kk2::PrefixSumOfMultiplicationFunction<mint> ps(n);
        vc<mint> init1(ps.size()), init2(ps.size());
        const mint inv2 = mint(2).inv();
        rep (i, ps.size()) {
            init1[i] = ps.eq[i] - 1;
            init2[i] = mint(ps.eq[i]) * (ps.eq[i] + 1) * inv2 - 1;
        }
        ps.LucyDP(g1, init1);
        ps.LucyDP(g2, init2);
        rep (i, ps.size()) ps.prefix_sum_only_prime[i] = a * init1[i] + b * init2[i];
        ps.Min_25Sieve(f);
        kout << ps.prefix_sum.back() << "\n";
    }

    return 0;
}

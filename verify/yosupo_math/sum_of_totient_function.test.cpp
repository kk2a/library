// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/sum_of_totient_function

// #include "../../math/multiplicative_function/euler_phi.hpp"
#include "../../math/multiplicative_function/famous_function.hpp"
#include "../../math/multiplicative_function/prefix_sum.hpp"
#include "../../modint/mont.hpp"
#include "../../template/template.hpp"
using namespace std;

int main() {
    using mint = kk2::mont998;
    i64 n;
    kin >> n;
    kk2::PrefixSumOfMultiplicativeFunction<mint> ps(n);
    auto g1 = [](i64) -> mint {
        return 1;
    };
    auto g2 = [](i64 p) -> mint {
        return p;
    };
    vc<mint> init1(ps.size()), init2(ps.size());
    rep(i, ps.size()) {
        init1[i] = ps.eq[i];
        init2[i] = mint(ps.eq[i]) * (ps.eq[i] + 1) / 2;
    }
    ps.LucyDP(g1, init1);
    ps.LucyDP(g2, init2);
    rep(i, ps.size()) ps.prefix_sum_only_prime[i] = init2[i] - init1[i];
    ps.Min_25Sieve(kk2::mf::euler_phi);
    kout << ps.prefix_sum.back() << "\n";

    return 0;
}

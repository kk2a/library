// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/sum_of_exponential_times_polynomial

#include "../../math_mod/power_sum.hpp"
#include "../../modint/mont.hpp"
#include "../../template/template.hpp"

int main() {
    using mint = kk2::mont998;

    mint r;
    u64 d, n;
    kin >> r >> d >> n;
    kout << kk2::sum_of_geometric_monomial(r, n, d) << kendl;
    return 0;
}

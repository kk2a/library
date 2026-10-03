// competitive-verifier: PROBLEM
// https://judge.yosupo.jp/problem/sum_of_exponential_times_polynomial_limit

#include "../../math_mod/power_sum.hpp"
#include "../../modint/mont.hpp"
#include "../../template/template.hpp"

int main() {
    using mint = kk2::mont998;

    mint r;
    u64 d;
    kin >> r >> d;
    kout << kk2::sum_of_geometric_monomial(r, d) << kendl;
    return 0;
}

#define PROBLEM "https://judge.yosupo.jp/problem/system_of_linear_equations_mod_2"

#include "../../matrix/matrix_F2.hpp"
#include "../../template/template.hpp"
using namespace std;

int main() {
    int n, m;
    kin >> n >> m;
    kk2::MatrixF2 a(n, m), b(1, n);
    a.input(kin), b.input(kin);
    if (const auto res = a.solve(b.inplace_transpose())) {
        kout << res->get_h() - 1 << "\n";
        res->output(kout);
    } else {
        kout << -1 << "\n";
    }

    return 0;
}

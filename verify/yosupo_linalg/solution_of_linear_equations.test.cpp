#define PROBLEM "https://judge.yosupo.jp/problem/system_of_linear_equations"

#include "../../matrix/matrix_field.hpp"
#include "../../modint/mont.hpp"
#include "../../template/template.hpp"
using namespace std;

int main() {
    int n, m;
    kin >> n >> m;
    kk2::MatrixField<kk2::mont998> a(n, m), b(n, 1);
    a.input(kin), b.input(kin);
    if (const auto res = a.solve(b); !res.get_h()) kout << -1 << "\n";
    else {
        kout << res.get_h() - 1 << "\n";
        res.output(kout);
    }

    return 0;
}

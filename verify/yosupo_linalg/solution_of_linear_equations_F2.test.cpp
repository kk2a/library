#define PROBLEM "https://judge.yosupo.jp/problem/system_of_linear_equations_mod_2"

#include "../../matrix/matrix_F2.hpp"
#include "../../template/template.hpp"
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    kk2::MatrixF2 a(n, m);
    rep (i, n) cin >> a[i];
    kk2::MatrixF2 b(1, n);
    cin >> b[0];
    b.inplace_transpose();

    auto res = a.solve(b);
    if (!res.get_h()) cout << -1 << "\n";
    else {
        cout << res.get_h() - 1 << "\n";
        res.display();
    }

    return 0;
}

#define PROBLEM "https://judge.yosupo.jp/problem/system_of_linear_equations"

#include "../../matrix/matrix_field.hpp"
#include "../../modint/mont.hpp"
#include "../../template/template.hpp"
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    kk2::MatrixField<kk2::mont998> a(n, m);
    rep (i, n) rep (j, m) cin >> a[i][j];
    kk2::MatrixField<kk2::mont998> b(n, 1);
    rep (i, n) cin >> b[i][0];

    auto res = a.solve(b);
    if (!res._h) cout << -1 << "\n";
    else {
        cout << res._h - 1 << "\n";
        res.display();
    }

    return 0;
}
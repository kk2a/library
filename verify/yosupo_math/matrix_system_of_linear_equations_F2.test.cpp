#define PROBLEM "https://judge.yosupo.jp/problem/system_of_linear_equations_mod_2"

#include "../../matrix/matrix_F2.hpp"
#include "../../template/template.hpp"
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    kk2::MatrixF2 a(n, m);
    rep (i, n) {
        string s;
        cin >> s;
        a[i] = s;
    }
    kk2::MatrixF2 b(n, 1);
    {
        string s;
        cin >> s;
        rep (i, n) b[i][0] = s[i] - '0';
    }

    auto res = a.solve(b);
    if (!res._h) cout << -1 << "\n";
    else {
        cout << res._h - 1 << "\n";
        res.display();
    }

    return 0;
}

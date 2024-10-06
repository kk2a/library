#define PROBLEM "https://judge.yosupo.jp/problem/system_of_linear_equations_mod_2"

#include "../../matrix/matrix_F2.hpp"
#include "../../template/template.hpp"
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    kk2::MatrixF2 a(n, m), b(1, n);
    a.input(cin), b.input(cin);
    if (const auto res = a.solve(b.inplace_transpose()); !res.get_h())
        cout << -1 << "\n";
    else {
        cout << res.get_h() - 1 << "\n";
        res.output(cout);
    }

    return 0;
}

#define PROBLEM "https://judge.yosupo.jp/problem/system_of_linear_equations"

#include "../../matrix/matrix_field.hpp"
#include "../../modint/mont.hpp"
#include "../../template/template.hpp"
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    kk2::MatrixField<kk2::mont998> a(n, m), b(n, 1);
    if (const auto res = a.input(cin).solve(b.input(cin)); !res.get_h()) cout << -1 << "\n";
    else {
        cout << res.get_h() - 1 << "\n";
        res.output(cout);
    }

    return 0;
}

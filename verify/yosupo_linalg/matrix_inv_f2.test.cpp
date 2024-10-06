#define PROBLEM "https://judge.yosupo.jp/problem/inverse_matrix_mod_2" 

#include "../../matrix/matrix_F2.hpp"
#include "../../template/template.hpp"
using namespace std;

int main() {
    int n;
    cin >> n;
    kk2::MatrixF2 a(n, n);
    rep (i, n) cin >> a[i];
    if (auto const inv = a.inv()) inv->display();
    else cout << -1 << "\n";

    return 0;
}
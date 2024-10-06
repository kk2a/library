#define PROBLEM "https://judge.yosupo.jp/problem/matrix_det" 

#include "../../matrix/matrix_field.hpp"
#include "../../modint/mont.hpp"
#include "../../template/template.hpp"
using namespace std;

int main() {
    int n;
    cin >> n;
    kk2::MatrixField<kk2::mont998> a(n, n);
    rep (i, n) rep (j, n) cin >> a[i][j];
    cout << a.det() << "\n";

    return 0;
}
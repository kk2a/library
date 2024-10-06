#define PROBLEM "https://judge.yosupo.jp/problem/matrix_product_mod_2" 

#include "../matrix/matrix_f2.hpp"
#include "../../template/template.hpp"
using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    kk2::MatrixF2 a(n, m), b(m, k);
    rep (i, n) {
        string s;
        cin >> s;
        a[i] = s;
    }
    rep (i, m) {
        string s;
        cin >> s;
        b[i] = s;
    }
    (a * b).display(); 

    return 0;
}
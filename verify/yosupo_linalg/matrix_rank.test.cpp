#define PROBLEM "https://judge.yosupo.jp/problem/matrix_rank" 

#include "../../matrix/matrix_field.hpp"
#include "../../modint/mont.hpp"
#include "../../template/template.hpp"
using namespace std;

int main() {
    int n, m;
    kin >> n >> m;
    bool is_swap = false;
    if (n > m) {
        is_swap = true;
        swap(n, m);
    }
    kk2::MatrixField<kk2::mont998> a(n, m);
    if (is_swap) {
        rep (j, m) rep (i, n) kin >> a[i][j];
    } else {
        a.input(kin);
    }
    kout << a.rank() << kendl;

    return 0;
}

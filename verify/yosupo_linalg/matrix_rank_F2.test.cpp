#define PROBLEM "https://judge.yosupo.jp/problem/matrix_rank_mod_2" 

#include "../../matrix/matrix_F2.hpp"
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

    kk2::MatrixF2 a(n, m);
    if (is_swap) {
        rep (j, m) {
            string s;
            kin >> s;
            rep (i, n) a[i][j] = s[i] - '0';
        }
    } else {
        a.input(kin);
    }
    kout << a.rank() << kendl;

    return 0;
}

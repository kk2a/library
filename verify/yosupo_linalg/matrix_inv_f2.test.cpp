#define PROBLEM "https://judge.yosupo.jp/problem/inverse_matrix_mod_2"

#include "../../matrix/matrix_F2.hpp"
#include "../../template/template.hpp"
using namespace std;

int main() {
    int n;
    kin >> n;
    kk2::MatrixF2 a(n, n);
    if (auto const inv = a.input(kin).inv()) inv->output(kout);
    else kout << -1 << "\n";

    return 0;
}

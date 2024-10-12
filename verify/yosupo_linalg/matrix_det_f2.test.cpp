#define PROBLEM "https://judge.yosupo.jp/problem/matrix_det_mod_2"

#include "../../matrix/matrix_F2.hpp"
#include "../../template/template.hpp"
using namespace std;

int main() {
    int n;
    kin >> n;
    kk2::MatrixF2 a(n, n);
    kout << a.input(kin).det() << "\n";

    return 0;
}

#define PROBLEM "https://judge.yosupo.jp/problem/inverse_matrix"

#include "../../matrix/matrix_field.hpp"
#include "../../modint/mont.hpp"
#include "../../template/template.hpp"
using namespace std;

int main() {
    int n;
    kin >> n;
    kk2::MatrixField<kk2::mont998> a(n, n);
    if (auto const inv = a.input(kin).inv()) inv->output(kout);
    else kout << -1 << "\n";

    return 0;
}

#define PROBLEM "https://judge.yosupo.jp/problem/matrix_product_mod_2"

#include "../../matrix/matrix_F2.hpp"
#include "../../template/template.hpp"
using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    kk2::MatrixF2 a(n, m), b(m, k);
    a.input(cin), b.input(cin);
    (a * b).output(cout);

    return 0;
}

#define PROBLEM "https://judge.yosupo.jp/problem/matrix_product"

#include "../../matrix/matrix_field.hpp"
#include "../../modint/mont.hpp"
#include "../../template/template.hpp"
using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    kk2::MatrixField<kk2::mont998> a(n, m), b(m, k);
    (a.input(cin) * b.input(cin)).output(cout);

    return 0;
}

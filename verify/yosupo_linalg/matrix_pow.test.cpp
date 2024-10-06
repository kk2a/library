#define PROBLEM "https://judge.yosupo.jp/problem/pow_of_matrix"

#include "../../matrix/matrix_field.hpp"
#include "../../modint/mont.hpp"
#include "../../template/template.hpp"
using namespace std;

int main() {
    int n;
    i64 k;
    cin >> n >> k;
    kk2::MatrixField<kk2::mont998> a(n, n);
    a.input(cin).pow(k).output(cout);

    return 0;
}

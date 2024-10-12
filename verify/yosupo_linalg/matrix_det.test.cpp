#define PROBLEM "https://judge.yosupo.jp/problem/matrix_det"

#include "../../matrix/matrix_field.hpp"
#include "../../modint/mont.hpp"
#include "../../template/template.hpp"
using namespace std;

int main() {
    int n;
    kin >> n;
    kk2::MatrixField<kk2::mont998> a(n, n);
    kout << a.input(kin).det() << "\n";

    return 0;
}

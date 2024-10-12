#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod_1000000007"

#include "../../convolution/convolution_arb.hpp"
#include "../../modint/mont.hpp"
#include "../../template/template.hpp"
using namespace std;

int main() {
    int n, m;
    kin >> n >> m;
    vc<kk2::mont107> a(n), b(m);
    kin >> a >> b;
    kout << kk2::convolution_arb(a, b, modu) << endl;

    return 0;
}

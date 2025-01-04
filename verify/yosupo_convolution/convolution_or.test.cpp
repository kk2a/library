#define PROBLEM "https://judge.yosupo.jp/problem/bitwise_and_convolution"

#include "../../convolution/convolution_or.hpp"
#include "../../modint/mont.hpp"
#include "../../template/template.hpp"
using namespace std;

int main() {
    int n;
    kin >> n;
    vc<kk2::mont998> a(1 << n), b(1 << n);
    rep (i, 1 << n) kin >> a[~i & ((1 << n) - 1)];
    rep (i, 1 << n) kin >> b[~i & ((1 << n) - 1)];
    kk2::convolution_or(a, b);
    vc<kk2::mont998> c(1 << n);
    rep (i, 1 << n) c[~i & ((1 << n) - 1)] = a[i];
    kout << c << kendl;

    return 0;
}

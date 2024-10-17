#define PROBLEM "https://judge.yosupo.jp/problem/multivariate_convolution"

#include "../../convolution/multi_convolution_truncated.hpp"
#include "../../modint/mont.hpp"
#include "../../template/template.hpp"
using namespace std;

int main() {
    int k;
    kin >> k;
    vc<int> base(k);
    kin >> base;
    int n = 1;
    rep (i, k) n *= base[i];
    vc<kk2::mont998> a(n), b(n);
    kin >> a >> b;
    kout << kk2::multi_convolution_truncated(a, b, base) << kendl;

    return 0;
}

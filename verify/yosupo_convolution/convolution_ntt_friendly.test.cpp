#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod"

#include "../../convolution/convolution.hpp"
#include "../../modint/mont.hpp"
#include "../../template/template.hpp"
using namespace std;

int main() {
    int n, m;
    kin >> n >> m;
    vc<kk2::mont998> a(n), b(m);
    kin >> a >> b;
    kout << kk2::convolution(a, b) << kendl;

    return 0;
}

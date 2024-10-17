#define PROBLEM "https://judge.yosupo.jp/problem/bitwise_and_convolution"

#include "../../convolution/bitand1.hpp"
#include "../../modint/mont.hpp"
#include "../../template/template.hpp"
using namespace std;

int main() {
    int n;
    kin >> n;
    vc<kk2::mont998> a(1 << n), b(1 << n);
    kin >> a >> b;
    kout << kk2::convolution_and(a, b) << kendl;

    return 0;
}

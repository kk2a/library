#define PROBLEM "https://judge.yosupo.jp/problem/subset_convolution" 

#include "../../convolution/subset.hpp"
#include "../../modint/mont.hpp"
#include "../../template/template.hpp"
using namespace std;

int main() {
    int n;
    kin >> n;
    vc<kk2::mont998> a(1 << n), b(1 << n);
    kin >> a >> b;
    kout << kk2::convolution_subset(a, b) << endl;

    return 0;
}

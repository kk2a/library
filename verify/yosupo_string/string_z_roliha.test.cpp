#define PROBLEM "https://judge.yosupo.jp/problem/zalgorithm" 

#include "../../string/rolling_hash.hpp"
#include "../../template/template.hpp"
using namespace std;

int main() {
    string s;
    kin >> s;
    kk2::Roliha rs(s);

    int n = s.size();
    vc<int> z(n);
    rep (i, n) z[i] = kk2::Roliha::lcp(rs, 0, n, rs, i, n);
    kout << z << kendl;

    return 0;
}

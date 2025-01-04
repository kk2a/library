#define PROBLEM "https://judge.yosupo.jp/problem/longest_increasing_subsequence" 

#include "../../others/longest_increasing_subsequence.hpp"
#include "../../template/template.hpp"
using namespace std;

int main() {
    int n;
    kin >> n;
    vc<int> a(n);
    kin >> a;
    auto res = kk2::longest_increasing_subsequence(a);
    kout << res.size() << "\n";
    kout << res << "\n";

    return 0;
}

#define PROBLEM "https://judge.yosupo.jp/problem/cartesian_tree" 

#include "../../graph/tree/cartesian_tree.hpp"
#include "../../template/template.hpp"
using namespace std;

int main() {
    int n;
    kin >> n;
    vc<int> a(n);
    kin >> a;
    auto [root, par] = kk2::cartesian_tree(a);
    par[root] = root;
    kout << par << kendl;

    return 0;
}

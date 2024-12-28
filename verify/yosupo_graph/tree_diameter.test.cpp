#define PROBLEM "https://judge.yosupo.jp/problem/tree_diameter"

#include "../../graph/graph.hpp"
#include "../../graph/tree/diameter.hpp"
#include "../../template/template.hpp"
using namespace std;

int main() {
    int n;
    kin >> n;
    kk2::WAdjList<i64> g(n, n - 1);
    g.input(kin);
    auto [d, path] = kk2::tree_diameter(g);
    kout << d << " " << path.size() << kendl;
    kout << path << kendl;

    return 0;
}

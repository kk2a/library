#define PROBLEM "https://judge.yosupo.jp/problem/tree_diameter" 

#include "../../graph/graph.hpp"
#include "../../graph/tree/diameter.hpp"
#include "../../template/template.hpp"
using namespace std;

int main() {
    int n;
    cin >> n;
    kk2::WAdjList<i64> g(n, n - 1, false);
    g.input(cin);
    auto [d, path] = kk2::weighted_tree_diameter(g);
    cout << d << " " << path.size() << endl;
    cout << path << endl;

    return 0;
}

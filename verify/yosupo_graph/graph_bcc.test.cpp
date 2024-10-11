#define PROBLEM "https://judge.yosupo.jp/problem/biconnected_components"

#include "../../graph/bcc.hpp"
#include "../../graph/graph.hpp"
#include "../../template/template.hpp"
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    kk2::AdjList g(n, m, false);
    g.input(cin);
    kk2::BCC<kk2::AdjList> bcc(g);
    auto res = bcc.get_bcc_vertices();

    cout << res.size() << "\n";
    for (auto &v : res) { cout << v.size() << " " << v << "\n"; }

    return 0;
}

#define PROBLEM "https://judge.yosupo.jp/problem/rational_approximation" 

#include "../../math/stern_brocot_tree.hpp"
#include "../../template/template.hpp"
using namespace std;

void solve() {
    using sbt = kk2::SternBrocotTree<i64>;
    // using sbt_node = sbt::Node;

    int n, x, y;
    kin >> n >> x >> y;

    auto [lnum, lden, rnum, rden] = sbt::binary_search(n, [&](i64 num, i64 den) -> bool {
        return num * y <= den * x;
    });
    if (lnum * y == lden * x) rnum = lnum, rden = lden;
    kout << lnum << ' ' << lden << ' ' << rnum << ' ' << rden << '\n';
}

int main() {
    int t;
    kin >> t;

    rep (t) solve();

    return 0;
}

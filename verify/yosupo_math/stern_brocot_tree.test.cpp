#define PROBLEM "https://judge.yosupo.jp/problem/stern_brocot_tree" 

#include "../../math/stern_brocot_tree.hpp"
#include "../../template/template.hpp"
using namespace std;

int main() {
    using sbt = kk2::SternBrocotTree<i64>;
    using sbt_node = sbt::Node;

    int t;
    kin >> t;
    rep (t) {
        string type;
        kin >> type;
        if (type == "ENCODE_PATH") {
            int a, b;
            kin >> a >> b;
            sbt_node x(a, b);
            auto p = x.get_path();
            vc<pair<char, i64>> res;
            rep (i, p.size()) {
                if (p[i] == 0) continue;
                res.emplace_back(i & 1 ? 'L' : 'R', p[i]);
            }
            kout << res.size() << " " << res << "\n";
        } else if (type == "DECODE_PATH") {
            int k;
            kin >> k;
            vc<pair<char, i64>> p(k);
            kin >> p;
            sbt_node x(p);
            kout << x.val() << "\n";
        } else if (type == "LCA") {
            int a1, b1, a2, b2;
            kin >> a1 >> b1 >> a2 >> b2;
            sbt_node x1(a1, b1), x2(a2, b2);
            auto lca = sbt::lca(x1, x2);
            kout << lca.val() << "\n";
        } else if (type == "ANCESTOR") {
            int k, a, b;
            kin >> k >> a >> b;
            sbt_node x(a, b);
            if (x.go_up(x.get_depth() - k)) kout << x.val() << "\n";
            else kout << -1 << "\n";
        } else if (type == "RANGE") {
            int a, b;
            kin >> a >> b;
            sbt_node x(a, b);
            auto [lnum, lden, rnum, rden] = x.range();
            kout << lnum << " " << lden << " " << rnum << " " << rden << "\n";
        }
    }

    return 0;
}

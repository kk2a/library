#define PROBLEM "https://judge.yosupo.jp/problem/segment_add_get_min" 

#include "../../segment_tree/li_chao_tree.hpp"
#include "../../template/template.hpp"
using namespace std;

int main() {
    int n, q;
    kin >> n >> q;
    vc<array<i64, 4>> segs(n);
    kin >> segs;
    vc<array<i64, 5>> queries(q);
    vc<int> xs;
    rep (i, q) {
        kin >> queries[i][0];
        if (queries[i][0] == 0) {
            kin >> queries[i][1] >> queries[i][2] >> queries[i][3] >> queries[i][4];
        }
        if (queries[i][0] == 1) {
            kin >> queries[i][1];
            xs.push_back(queries[i][1]);
        }
    }
    kk2::LiChaoTree<int, i64, true> lct(xs);
    for (auto &[l, r, a, b] : segs) lct.add_seg(l, r, a, b);
    for (auto query : queries) {
        if (query[0] == 0) {
            auto [t, l, r, a, b] = query;
            lct.add_seg(l, r, a, b);
        } else if (query[0] == 1) {
            auto [t, p, tmp0, tmp1, tmp2] = query;
            auto res = lct.get(p);
            if (res) kout << *res << "\n";
            else kout << "INFINITY\n";
        }
    }

    return 0;
}

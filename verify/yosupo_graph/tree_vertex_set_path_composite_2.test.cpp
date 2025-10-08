#define PROBLEM "https://judge.yosupo.jp/problem/vertex_set_path_composite" 

#include "../../graph/tree/heavy_light_decomposition.hpp"
#include "../../graph/graph.hpp"
#include "../../modint/mont.hpp"
#include "../../math/monoid/affine.hpp"
#include "../../math/monoid/rev_op.hpp"
#include "../../segment_tree/seg.hpp"
#include "../../template/template.hpp"
using namespace std;

int main() {
    using mint = kk2::mont998;
    using M1 = kk2::monoid::ReverseOp<kk2::monoid::Affine<mint>>;
    using M2 = kk2::monoid::Affine<mint>;
    
    int n, q;
    kin >> n >> q;

    vc<M1> a(n);
    kin >> a;

    kk2::AdjList g(n, n - 1);
    g.input(kin);
    kk2::HeavyLightDecomposition hld(g);
    kk2::SegmentTreeS<M1> seg1(hld.id);
    kk2::SegmentTreeS<M2> seg2(hld.id);
    rep (i, n) {
        auto [l, r] = hld.get_node_idx(i);
        seg1.init_set(l, a[i]), seg2.init_set(l, a[i]);
    }
    seg1.build(), seg2.build();

    rep (q) {
        int type;
        kin >> type;
        if (type == 0) {
            int p;
            mint c, d;
            kin >> p >> c >> d;
            auto [l, r] = hld.get_node_idx(p);
            seg1.set(l, c, d), seg2.set(l, c, d);
        } else {
            int u, v;
            mint x;
            kin >> u >> v >> x;
            M1 f = M1::unit();
            hld.path_noncommutative_query(u, v, 1, [&](int l, int r) {
                if (l > r) f = M1::op(f, seg2.prod(r, l));
                else f = M1::op(f, seg1.prod(l, r));
            });
            kout << f.eval(x) << "\n";
        }
    }

    return 0;
}

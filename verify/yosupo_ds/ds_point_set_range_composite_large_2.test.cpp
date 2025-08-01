#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_composite_large_array" 

#include "../../segment_tree/seg.hpp"
#include "../../math/monoid/affine.hpp"
#include "../../math/monoid/rev_op.hpp"
#include "../../modint/modint.hpp"
#include "../../others/coordinate_compression.hpp"
#include "../../template/template.hpp"
using namespace std;

int main() {
    using mint = kk2::mint998;
    using S = kk2::monoid::ReverseOp<kk2::monoid::Affine<mint>>;
    int n, q;
    kin >> n >> q;
    vc<array<int, 4>> queries(q);
    kin >> queries;
    kk2::CC<int> cc;

    for (auto [t, p, c, d] : queries) {
        if (t == 0) cc.add(p);
    }
    cc.build();
    kk2::SegmentTreeS<S> seg(cc.size());
    seg.build();
    for (auto query : queries) {
        if (query[0] == 0) {
            int p = query[1];
            mint c = query[2], d = query[3];
            p = cc.get(p);
            seg.set(p, c, d);
        } else {
            int l = query[1], r = query[2];
            mint x = query[3];
            l = cc.lower(l);
            r = cc.lower(r);
            kout << seg.prod(l, r).eval(x) << "\n";
        }
    }

    return 0;
}

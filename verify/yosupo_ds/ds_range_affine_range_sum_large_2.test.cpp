#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum_large_array" 

#include "../../segment_tree/lazy.hpp"
#include "../../math/action/affine_sumwithsize.hpp"
#include "../../modint/modint.hpp"
#include "../../others/coordinate_compression.hpp"
#include "../../template/template.hpp"
using namespace std;

int main() {
    using mint = kk2::mint998;
    using A = kk2::action::AffineSumWithSize<mint, mint>;
    int n, q;
    kin >> n >> q;
    vc<array<int, 5>> queries(q);
    kk2::CC<int> cc;
    rep (i, q) {
        auto &x = queries[i];
        kin >> x[0];
        if (x[0] == 0) {
            kin >> x[1] >> x[2] >> x[3] >> x[4];
            cc.add(x[1]), cc.add(x[2]);
        } else if (x[0] == 1) {
            kin >> x[1] >> x[2];
            cc.add(x[1]), cc.add(x[2]);
        }
    }
    cc.build();
    rep (i, q) {
        auto &x = queries[i];
        if (x[0] == 0) {
            x[1] = cc.get(x[1]);
            x[2] = cc.get(x[2]);
        } else if (x[0] == 1) {
            x[1] = cc.get(x[1]);
            x[2] = cc.get(x[2]);
        }
    }
    kk2::LazySegmentTreeS<A> seg(cc.size());
    rep (i, cc.size() - 1) seg.init_set(i, 0, cc[i + 1] - cc[i]);
    seg.build();

    for (auto query : queries) {
        if (query[0] == 0) {
            auto [_, l, r, a, b] = query;
            seg.apply_range(l, r, a, b);
        } else {
            auto [_0, l, r, _1, _2] = query;
            kout << seg.prod(l, r).a << "\n";
        }
    }

    return 0;
}

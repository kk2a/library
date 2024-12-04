#define PROBLEM "https://judge.yosupo.jp/problem/unionfind_with_potential_non_commutative_group" 

#include "../../modint/modint.hpp"
#include "../../unionfind/potentialized.hpp"
#include "../../template/template.hpp"
using namespace std;

struct A {
    kk2::mint998 a00, a01, a10, a11;
    bool operator==(const A& r) const {
        return a00 == r.a00 && a01 == r.a01 && a10 == r.a10 && a11 == r.a11;
    }
};

A op(A l, A r) {
    return A{
        l.a00 * r.a00 + l.a01 * r.a10,
        l.a00 * r.a01 + l.a01 * r.a11,
        l.a10 * r.a00 + l.a11 * r.a10,
        l.a10 * r.a01 + l.a11 * r.a11
    };
}

A e() {
    return A{1, 0, 0, 1};
}

A inv(A a) {
    return A{a.a11, -a.a01, -a.a10, a.a00};
}

using Ab = kk2::EasyAbelianGroup<A, op, e, inv>;

int main() {
    int n, q;
    kin >> n >> q;
    kk2::PotentializedUnionFind<Ab, false> puf(n);

    rep (i, q) {
        int type;
        kin >> type;
        if (type == 0) {
            int u, v;
            kin >> u >> v;
            A x;
            kin >> x.a00 >> x.a01 >> x.a10 >> x.a11;
            if (puf.same(v, u)) {
                kout << (puf.diff(v, u).val == x) << "\n";
            } else {
                kout << "1\n";
                puf.unite(v, u, x);
            }
        } else {
            int u, v;
            kin >> u >> v;
            if (!puf.same(v, u)) {
                kout << "-1\n";
            } else {
                A x = puf.diff(v, u).val;
                kout << x.a00 << " " << x.a01 << " " << x.a10 << " " << x.a11 << "\n";
            }
        }
    }
    return 0;
}

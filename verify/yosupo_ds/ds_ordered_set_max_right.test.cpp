#define PROBLEM "https://judge.yosupo.jp/problem/ordered_set" 

#include "../../bbst/red_black_tree.hpp"
#include "../../math/monoid/hold.hpp"
#include "../../template/template.hpp"
using namespace std;

int main() {
    int n, q;
    kin >> n >> q;
    vc<kk2::monoid::Hold<int>> a(n);
    kin >> a;
    kk2::RedBlackTree<kk2::monoid::Hold<int>> rb(2 * (n + q));
    auto root = rb.build(a);
    rep (q) {
        int t, x;
        kin >> t >> x;
        if (t == 0) {
            auto [k, a, b] = rb.max_right(root, 0, [&](auto t) { return t.is_unit or t.a < x; });
            if (b and b->val.a == x) continue;
            rb.insert(root, k, x);
        } 
        if (t == 1) {
            auto [k, a, b] = rb.max_right(root, 0, [&](auto t) { return t.is_unit or t.a < x; });
            if (b and b->val.a == x) rb.erase(root, k);
        }
        if (t == 2) {
            --x;
            if (rb.size(root) <= x) kout << -1 << "\n";
            else kout << rb.get(root, x) << "\n";
        }
        if (t == 3) {
            kout << rb.max_right(root, 0, [&](auto t) { return t.is_unit or t.a <= x; }).s << "\n";
        }
        if (t == 4) {
            auto [k, a, b] = rb.max_right(root, 0, [&](auto t) { return t.is_unit or t.a <= x; });
            if (a.is_unit) kout << -1 << "\n";
            else kout << a << "\n";
        }
        if (t == 5) {
            auto [k, a, b] = rb.max_right(root, 0, [&](auto t) { return t.is_unit or t.a < x; });
            if (b) kout << b->val << "\n";
            else kout << -1 << "\n";
        }
    }

    return 0;
}

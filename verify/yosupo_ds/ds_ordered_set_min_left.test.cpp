#define PROBLEM "https://judge.yosupo.jp/problem/ordered_set" 

#include "../../bbst/red_black_tree.hpp"
#include "../../math/monoid/update.hpp"
#include "../../template/template.hpp"
using namespace std;

int main() {
    int n, q;
    kin >> n >> q;
    vc<kk2::monoid::Update<int>> a(n);
    kin >> a;
    kk2::RedBlackTreeS<kk2::monoid::Update<int>> rb(2 * (n + q));
    auto root = rb.build(a);
    rep (q) {
        int t, x;
        kin >> t >> x;
        if (t == 0) {
            auto [k, a, b] = rb.min_left(root, rb.size(root), [&](auto t) { return t.is_unit or x < t.a; });
            if (b and b->val.a == x) continue;
            rb.insert(root, k, x);
        }
        if (t == 1) {
            auto [k, a, b] = rb.min_left(root, rb.size(root), [&](auto t) { return t.is_unit or x < t.a; });
            if (b and b->val.a == x) rb.erase(root, k - 1);
        }
        if (t == 2) {
            --x;
            if (rb.size(root) <= x) kout << -1 << "\n";
            else kout << rb.get(root, x) << "\n";
        }
        if (t == 3) {
            kout << rb.min_left(root, rb.size(root), [&](auto t) { return t.is_unit or x < t.a; }).s << "\n";
        }
        if (t == 4) {
            auto [k, a, b] = rb.min_left(root, rb.size(root), [&](auto t) { return t.is_unit or x < t.a; });
            if (b) kout << b->val << "\n";
            else kout << -1 << "\n";
        }
        if (t == 5) {
            auto [k, a, b] = rb.min_left(root, rb.size(root), [&](auto t) { return t.is_unit or x <= t.a; });
            if (a.is_unit) kout << -1 << "\n";
            else kout << a << "\n";
        }
    }

    return 0;
}

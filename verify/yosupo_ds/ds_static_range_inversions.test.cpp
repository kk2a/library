#define PROBLEM "https://judge.yosupo.jp/problem/static_range_inversions_query" 

#include "../../others/coordinate_compression.hpp"
#include "../../data_structure/binary_indexed_tree.hpp"
#include "../../others/mo.hpp"
#include "../../template/template.hpp"
using namespace std;

int main() {
    int n, q;
    kin >> n >> q;
    vc<int> a(n);
    kin >> a;
    vc<pair<int, int>> queries(q);
    cin >> queries;

    kk2::CC cc(a);
    vc<int> b = cc(a);
    kk2::BinaryIndexedTree<int> bit(cc.size());
    kk2::Mo mo(n, queries);

    vc<i64> res(q);
    i64 now = 0;
    auto insert_left = [&](int i) {
        bit.add(b[i], 1);
        now += bit.sum(0, b[i]);
    };
    auto insert_right = [&](int i) {
        bit.add(b[i], 1);
        now += bit.sum(b[i] + 1, cc.size());
    };
    auto erase_left = [&](int i) {
        now -= bit.sum(0, b[i]);
        bit.add(b[i], -1);
    };
    auto erase_right = [&](int i) {
        now -= bit.sum(b[i] + 1, cc.size());
        bit.add(b[i], -1);
    };
    auto f = [&](int i) { res[i] = now; };

    mo.calculate(insert_left, insert_right, erase_left, erase_right, f);
    for (auto x : res) kout << x << "\n";

    return 0;
}

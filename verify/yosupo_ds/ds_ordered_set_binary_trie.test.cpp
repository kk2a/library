#define PROBLEM "https://judge.yosupo.jp/problem/ordered_set" 

#include "../../data_structure/binary_trie.hpp"
#include "../../template/template.hpp"
using namespace std;

int main() {
    int n, q;
    kin >> n >> q;
    vc<int> a(n);
    kin >> a;
    kk2::BinaryTrie<int, 30> bt(30 * q + 20 * n);
    rep (i, n) bt.insert(a[i]);

    rep (q) {
        int type, x;
        kin >> type >> x;
        if (type == 0) {
            if (!bt.count(x)) bt.insert(x);
        } else if (type == 1) {
            bt.erase(x);
        } else if (type == 2) {
            auto res = bt.get_kth(x - 1);
            if (res) kout << *res << "\n";
            else kout << -1 << "\n";
        } else if (type == 3) {
            kout << bt.count_not_greater(x) << "\n";
        } else if (type == 4) {
            auto res = bt.max_not_greater(x);
            if (res) kout << *res << "\n";
            else kout << -1 << "\n";
        } else {
            auto res = bt.min_not_less(x);
            if (res) kout << *res << "\n";
            else kout << -1 << "\n";
        }
    }

    return 0;
}

#define PROBLEM "https://judge.yosupo.jp/problem/set_xor_min" 

#include "../../data_structure/binary_trie.hpp"
#include "../../template/template.hpp"
using namespace std;

int main() {
    int q;
    kin >> q;
    kk2::BinaryTrie<int, 30> bt(30 * q);
    rep (q) {
        int type, x;
        kin >> type >> x;
        if (type == 0) {
            if (!bt.count(x)) bt.insert(x);
        } else if (type == 1) {
            bt.erase(x);
        } else {
            bt.operate_xor(x);
            kout << *bt.get_kth(0) << "\n";
            bt.operate_xor(x);
        }
    }

    return 0;
}

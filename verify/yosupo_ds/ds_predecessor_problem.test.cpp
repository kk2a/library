#define PROBLEM "https://judge.yosupo.jp/problem/predecessor_problem" 

#include "../../data_structure/w_ary_tree.hpp"
#include "../../template/template.hpp"
using namespace std;

int main() {
    int n, q;
    kin >> n >> q;
    string t;
    kin >> t;
    kk2::w_ary_tree wt(t);
    rep (q) {
        int type, x;
        kin >> type >> x;
        if (type == 0) {
            wt.insert(x);
        } else if (type == 1) {
            wt.erase(x);
        } else if (type == 2) {
            kout << wt.count(x) << "\n";
        } else if (type == 3) {
            if (auto res = wt.successor(x); res) {
                kout << *res << "\n";
            } else {
                kout << "-1\n";
            }
        } else {
            if (auto res = wt.predecessor(x); res) {
                kout << *res << "\n";
            } else {
                kout << "-1\n";
            }
        }
    }

    return 0;
}

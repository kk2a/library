#define PROBLEM "https://judge.yosupo.jp/problem/aplusb" 

#include "../../data_structure/bit_vector.hpp"
#include "../../random/gen.hpp"
#include "../../template/template.hpp"
using namespace std;

int main() {
    int a, b;
    kin >> a >> b;
    kout << a + b << kendl;

    int n = kk2::random::rng(1e4, 1e5);
    auto a = kk2::random::random_vector<int>(n, 0, 2);

    if (!kk2::random::rng(0, 10)) {
        a.assign(n, 0);
    }
    if (!kk2::random::rng(0, 10)) {
        a.assign(n, 1);
    }

    kk2::BitVector bv(n);
    rep (i, n) if (a[i] == 1) bv.set(i);
    bv.build();

    vc<int> zero, one;
    vc<int> zero_acc(n + 1), one_acc(n + 1);
    rep (i, n) {
        if (a[i] == 0) zero.push_back(i);
        else one.push_back(i);
        zero_acc[i + 1] = zero_acc[i] + (a[i] == 0);
        one_acc[i + 1] = one_acc[i] + (a[i] == 1);
    }

    int q = 1000;
    rep (q) {
        int i = kk2::random::rng(0, n);
        int naive_rank0 = zero_acc[i];
        int naive_rank1 = one_acc[i];
        int naive_select0 = -1;
        int naive_select1 = -1;
        if (i < (int)zero.size()) naive_select0 = zero[i];
        if (i < (int)one.size()) naive_select1 = one[i];
        if (naive_rank0 != bv.rank0(i)) {
            cerr << "rank0" << endl;
            exit(1);
        }
        if (naive_rank1 != bv.rank1(i)) {
            cerr << "rank1" << endl;
            exit(1);
        }
        if (naive_select0 != bv.select0(i)) {
            cerr << "select0" << endl;
            exit(1);
        }
        if (naive_select1 != bv.select1(i)) {
            cerr << "select1" << endl;
            exit(1);
        }
    }

    return 0;
}

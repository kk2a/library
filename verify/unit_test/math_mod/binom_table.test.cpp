#define PROBLEM "https://judge.yosupo.jp/problem/aplusb" 

#include "../../math_mod/binom_table.hpp"
#include "../../math_mod/comb.hpp"
#include "../../modint/modint.hpp"
#include "../../random/gen.hpp"
#include "../../template/template.hpp"
using namespace std;

int main() {
    int a, b;
    kin >> a >> b;
    kout << a + b << kendl;

    // aliasの定義
    using mint = kk2::mint998;
    using BTable = kk2::BinomTable<mint>;
    using Comb = kk2::Comb<mint>;

    // binom_tableのテスト
    rep (1000) {
        int max_n = kk2::random::rng(1, 1000);
        BTable::set_upper(max_n);
        
        rep (1000) {
            int n = kk2::random::rng(0, max_n + 1);
            int k = kk2::random::rng(-10, n + 10);
            
            auto table_result = BTable::binom(n, k);
            auto comb_result = Comb::binom(n, k);
            
            if (table_result != comb_result) {
                cerr << "binom mismatch: n=" << n << ", k=" << k << endl;
                cerr << "table: " << table_result << ", comb: " << comb_result << endl;
                exit(1);
            }
        }
        
        // エッジケースのテスト
        if (BTable::binom(0, 0) != 1) {
            cerr << "binom(0,0) should be 1" << endl;
            exit(1);
        }
        if (BTable::binom(max_n, 0) != 1) {
            cerr << "binom(n,0) should be 1" << endl;
            exit(1);
        }
        if (BTable::binom(max_n, max_n) != 1) {
            cerr << "binom(n,n) should be 1" << endl;
            exit(1);
        }
        if (BTable::binom(max_n, -1) != 0) {
            cerr << "binom(n,-1) should be 0" << endl;
            exit(1);
        }
        if (BTable::binom(max_n, max_n + 1) != 0) {
            cerr << "binom(n,n+1) should be 0" << endl;
            exit(1);
        }
    }

    return 0;
}

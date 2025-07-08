#define PROBLEM "https://judge.yosupo.jp/problem/aplusb" 

#include "../../../math_mod/inv_table.hpp"
#include "../../../modint/modint.hpp"
#include "../../../random/gen.hpp"
#include "../../../template/template.hpp"
using namespace std;

void test_inv_table() {
    using mint = kk2::mint998;
    using InvTab = kk2::InvTable<mint>;
    
    // 基本的な逆元のテスト
    {
        rep(100) {
            int i = kk2::random::rng(1, 1001);
            mint inv_i = InvTab::inv(i);
            assert(mint(i) * inv_i == mint(1));
        }
        cerr << "Basic inverse: 100 random tests passed!" << endl;
    }
    
    // 大きな値での自動拡張テスト
    {
        rep(1000) {
            int i = kk2::random::rng(1, 50001);
            mint inv_i = InvTab::inv(i);
            assert(mint(i) * inv_i == mint(1));
        }
        cerr << "Auto expansion: 1000 random tests passed!" << endl;
    }
    
    // 負の数のテスト
    {
        rep(1000) {
            int i = kk2::random::rng(1, 10001);
            mint inv_pos = InvTab::inv(i);
            mint inv_neg = InvTab::inv(-i);
            assert(inv_pos == -inv_neg);
            assert(mint(-i) * inv_neg == mint(1));
        }
        cerr << "Negative numbers: 1000 random tests passed!" << endl;
    }
    
    // set_upperの動作テスト
    {
        InvTab::set_upper(20000);
        rep(1000) {
            int i = kk2::random::rng(1, 20001);
            mint inv_i = InvTab::inv(i);
            assert(mint(i) * inv_i == mint(1));
        }
        cerr << "set_upper: 1000 random tests passed!" << endl;
    }
    
    // 一致性テスト（複数回呼び出しで同じ結果）
    {
        rep(100) {
            int i = kk2::random::rng(1, 10001);
            mint inv1 = InvTab::inv(i);
            mint inv2 = InvTab::inv(i);
            assert(inv1 == inv2);
        }
        cerr << "Consistency: 100 random tests passed!" << endl;
    }
}

void test() {
    test_inv_table();
    
    // 全テスト通過
    cerr << "All InvTable tests passed!" << endl;
}

int main() {
    int a, b;
    kin >> a >> b;
    kout << a + b << kendl;

    test();

    return 0;
}

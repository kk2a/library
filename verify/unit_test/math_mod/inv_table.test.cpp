// competitive-verifier: STANDALONE

#include "../../../math_mod/inv_table.hpp"

#include "../../../math_mod/comb.hpp"
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

void test_comb_shared_table() {
    using mint = kk2::mint998;
    using Comb = kk2::Comb<mint>;
    using InvTab = kk2::InvTable<mint>;

    Comb::set_upper(60000);
    for (int i = 1; i <= 60000; i += 137) {
        assert(Comb::inv(i) == InvTab::inv(i));
        assert(Comb::fact(i) * Comb::ifact(i) == 1);
    }

    InvTab::set_upper(70000);
    assert(Comb::inv(70000) == InvTab::inv(70000));

    Comb::set_upper(80000);
    assert(Comb::inv(80000) == InvTab::inv(80000));
    assert(Comb::fact(80000) * Comb::ifact(80000) == 1);
}

void test() {
    test_inv_table();
    test_comb_shared_table();

    // 全テスト通過
    cerr << "All InvTable tests passed!" << endl;
}

int main() {
    test();

    return 0;
}

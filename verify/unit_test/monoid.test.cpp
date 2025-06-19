#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "../../math/group/add.hpp"
#include "../../math/group/rolling_hash.hpp"
#include "../../math/group/sum_with_size.hpp"
#include "../../math/monoid/affine.hpp"
#include "../../math/monoid/hold.hpp"
#include "../../math/monoid/max.hpp"
#include "../../math/monoid/max_min_sumwithsize.hpp"
#include "../../math/monoid/min.hpp"
#include "../../math/monoid/update.hpp"
#include "../../random/gen.hpp"
#include "../../template/template.hpp"
using namespace std;

void test_monoid() {
    // Update monoid test
    {
        using M = kk2::monoid::Update<int>;
        M unit = M::unit();

        rep(10000) {
            int val1 = kk2::random::rng(1, 1001);
            int val2 = kk2::random::rng(1, 1001);
            M a(val1), b(val2);

            assert(M::op(unit, a) == a);
            assert(M::op(a, unit) == a);
            assert(M::op(a, b) == a); // 左側を保持
            assert(M::op(b, a) == b);
        }
        cerr << "Update: 10000 random tests passed!" << endl;
    }

    // Min monoid test
    {
        using M = kk2::monoid::Min<int>;
        M unit = M::unit();

        rep(10000) {
            int val1 = kk2::random::rng(1, 1001);
            int val2 = kk2::random::rng(1, 1001);
            int val3 = kk2::random::rng(1, 1001);
            M a(val1), b(val2), c(val3);

            assert(M::op(unit, a) == a);
            assert(M::op(a, unit) == a);

            // min演算の検証
            int min_ab = min(val1, val2);
            int min_bc = min(val2, val3);
            int min_ac = min(val1, val3);
            assert(M::op(a, b).a == min_ab);
            assert(M::op(b, c).a == min_bc);
            assert(M::op(a, c).a == min_ac);

            // 結合律の検証
            assert(M::op(M::op(a, b), c) == M::op(a, M::op(b, c)));
        }
        cerr << "Min: 10000 random tests passed!" << endl;
    }

    // Max monoid test
    {
        using M = kk2::monoid::Max<int>;
        M unit = M::unit();

        rep(10000) {
            int val1 = kk2::random::rng(1, 1001);
            int val2 = kk2::random::rng(1, 1001);
            int val3 = kk2::random::rng(1, 1001);
            M a(val1), b(val2), c(val3);

            assert(M::op(unit, a) == a);
            assert(M::op(a, unit) == a);

            // max演算の検証
            int max_ab = max(val1, val2);
            int max_bc = max(val2, val3);
            int max_ac = max(val1, val3);
            assert(M::op(a, b).a == max_ab);
            assert(M::op(b, c).a == max_bc);
            assert(M::op(a, c).a == max_ac);

            // 結合律の検証
            assert(M::op(M::op(a, b), c) == M::op(a, M::op(b, c)));
        }
        cerr << "Max: 10000 random tests passed!" << endl;
    }

    // MaxMinSumWithSize test
    {
        using M = kk2::monoid::MaxMinSumWithSize<int, int>;
        M unit = M::unit();

        rep(10000) {
            int val1 = kk2::random::rng(1, 1001);
            int val2 = kk2::random::rng(1, 1001);
            M a(val1), b(val2);

            assert(M::op(unit, a) == a);

            auto ab = M::op(a, b);
            assert(ab.max == max(val1, val2));
            assert(ab.min == min(val1, val2));
            assert(ab.sum == val1 + val2);
            assert(ab.size == 2);
        }
        cerr << "MaxMinSumWithSize: 10000 random tests passed!" << endl;
    }

    // Hold monoid test
    {
        using M = kk2::monoid::Hold<int>;
        M unit = M::unit();

        rep(10000) {
            int val1 = kk2::random::rng(1, 1001);
            int val2 = kk2::random::rng(1, 1001);
            M a(val1), b(val2);

            assert(M::op(unit, a) == a);
            assert(M::op(a, unit) == a);
            assert(M::op(a, b) == b); // 右側を保持
            assert(M::op(b, a) == a);
        }
        cerr << "Hold: 10000 random tests passed!" << endl;
    }

    // Affine monoid test
    {
        using M = kk2::monoid::Affine<int>;
        M unit = M::unit();

        rep(10000) {
            int a1 = kk2::random::rng(1, 11), b1 = kk2::random::rng(1, 11);
            int a2 = kk2::random::rng(1, 11), b2 = kk2::random::rng(1, 11);
            int x = kk2::random::rng(1, 101);

            M f(a1, b1), g(a2, b2);

            assert(M::op(unit, f) == f);
            assert(M::op(f, unit) == f);

            assert(f.eval(x) == a1 * x + b1);
            assert(g.eval(x) == a2 * x + b2);

            // 合成の検証 f(g(x)) = f(a2*x + b2) = a1*(a2*x + b2) + b1 = a1*a2*x + a1*b2 + b1
            auto fg = M::op(f, g);
            assert(fg.a == a1 * a2);
            assert(fg.b == a1 * b2 + b1);
            assert(fg.eval(x) == a1 * (a2 * x + b2) + b1);

            // 結合律の検証
            int a3 = kk2::random::rng(1, 11), b3 = kk2::random::rng(1, 11);
            M h(a3, b3);
            assert(M::op(M::op(f, g), h) == M::op(f, M::op(g, h)));
        }
        cerr << "Affine: 10000 random tests passed!" << endl;
    }
}

void test_group() {
    // Add group test
    {
        using G = kk2::group::Add<int>;
        G unit = G::unit();

        rep(10000) {
            int val1 = kk2::random::rng(-1000, 1001);
            int val2 = kk2::random::rng(-1000, 1001);
            G a(val1), b(val2);

            assert(G::op(unit, a) == a);
            assert(G::op(a, unit) == a);
            assert(G::op(a, b).a == val1 + val2);

            auto inv_a = G::inv(a);
            assert(inv_a.a == -val1);
            assert(G::op(a, inv_a) == unit);
            assert(G::op(inv_a, a) == unit);
        }
        cerr << "Add: 10000 random tests passed!" << endl;
    }

    // SumWithSize group test
    {
        using G = kk2::group::SumWithSize<int>;
        G unit = G::unit();

        rep(10000) {
            int val1 = kk2::random::rng(-1000, 1001);
            int val2 = kk2::random::rng(-1000, 1001);
            G a(val1), b(val2);

            auto ab = G::op(a, b);
            assert(ab.a == val1 + val2 && ab.size == 2);

            auto inv_a = G::inv(a);
            assert(inv_a.a == -val1 && inv_a.size == -1);

            auto cancel = G::op(a, inv_a);
            assert(cancel == unit);
        }
        cerr << "SumWithSize: 10000 random tests passed!" << endl;
    }

    // RollingHash group test
    {
        using RH = kk2::group::RollingHash<2>;
        RH unit = RH::unit();

        // 乱数を使った複数回テスト
        rep(10000) {
            // ランダムな整数でのテスト
            int val1 = kk2::random::rng(1, 1001);
            int val2 = kk2::random::rng(1, 1001);
            RH a(val1), b(val2);

            assert(RH::op(unit, a) == a);
            assert(RH::op(a, unit) == a);

            // 逆元のテスト
            auto inv_a = RH::inv(a);
            auto cancel = RH::op(a, inv_a);
            assert(cancel == unit);

            // ランダムな文字列でのテスト
            string s1, s2;
            int len1 = kk2::random::rng(1, 11);
            int len2 = kk2::random::rng(1, 11);

            rep(len1) { s1 += char('a' + kk2::random::rng(0, 26)); }
            rep(len2) { s2 += char('a' + kk2::random::rng(0, 26)); }

            RH h1(s1), h2(s2);
            RH h12 = RH::op(h1, h2); // s1 + s2
            RH h_concat(s1 + s2);
            assert(h12.a == h_concat.a);

            // 逆元での連結テスト
            auto inv_h2 = RH::inv(h2);
            auto result = RH::op(h12, inv_h2);
            assert(result.a == h1.a);

            // 結合律のテスト（3つの文字列）
            string s3;
            int len3 = kk2::random::rng(1, 11);
            rep(len3) { s3 += char('a' + kk2::random::rng(0, 26)); }
            RH h3(s3);

            RH h123_left = RH::op(RH::op(h1, h2), h3);
            RH h123_right = RH::op(h1, RH::op(h2, h3));
            RH h123_direct(s1 + s2 + s3);

            assert(h123_left.a == h123_right.a);
            assert(h123_left.a == h123_direct.a);
        }

        cerr << "RollingHash: 10000 random tests passed!" << endl;
    }
}

void test() {
    test_monoid();
    test_group();

    // 全テスト通過
    cerr << "All monoid and group tests passed!" << endl;
}

int main() {
    int a, b;
    kin >> a >> b;
    kout << a + b << kendl;

    test();

    return 0;
}

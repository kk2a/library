#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "../../../../math/group/add.hpp"
#include "../../../../math/group/rolling_hash.hpp"
#include "../../../../math/group/sum_with_size.hpp"
#include "../../../../random/gen.hpp"
#include "../../../../template/template.hpp"
using namespace std;

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
    test_group();
    
    // 全テスト通過
    cerr << "All group tests passed!" << endl;
}

int main() {
    int a, b;
    kin >> a >> b;
    kout << a + b << kendl;

    test();

    return 0;
}

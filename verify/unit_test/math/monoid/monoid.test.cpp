#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "../../../../math/monoid/affine.hpp"
#include "../../../../math/monoid/hold.hpp"
#include "../../../../math/monoid/max.hpp"
#include "../../../../math/monoid/max_min_sumwithsize.hpp"
#include "../../../../math/monoid/min.hpp"
#include "../../../../math/monoid/update.hpp"
#include "../../../../random/gen.hpp"
#include "../../../../template/template.hpp"
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



void test() {
    test_monoid();

    // 全テスト通過
    cerr << "All monoid tests passed!" << endl;
}

int main() {
    int a, b;
    kin >> a >> b;
    kout << a + b << kendl;

    test();

    return 0;
}

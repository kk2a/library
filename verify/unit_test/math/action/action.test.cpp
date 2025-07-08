#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "../../math/action/add_max.hpp"
#include "../../math/action/add_max_min_sumwithsize.hpp"
#include "../../math/action/add_min.hpp"
#include "../../math/action/add_sumwithsize.hpp"
#include "../../math/action/affine_sumwithsize.hpp"
#include "../../math/action/update_affine.hpp"
#include "../../math/action/update_max.hpp"
#include "../../math/action/update_max_min_sumwithsize.hpp"
#include "../../math/action/update_min.hpp"
#include "../../math/action/update_sumwithsize.hpp"
#include "../../random/gen.hpp"
#include "../../template/template.hpp"
using namespace std;

void test_action() {
    // UpdateSumWithSize action test
    {
        using Action = kk2::action::UpdateSumWithSize<int, int>;
        using A = Action::A;
        using S = Action::S;

        rep(10000) {
            int val = kk2::random::rng(1, 1001);
            int size = kk2::random::rng(1, 101);
            S x(kk2::random::rng(1, 1001), size);
            A f(val);

            auto result = Action::act(f, x);
            assert(result.a == val * size);
            assert(result.size == size);

            // unit actionのテスト
            A unit = A::unit();
            auto unit_result = Action::act(unit, x);
            assert(unit_result == x);
        }
        cerr << "UpdateSumWithSize: 10000 random tests passed!" << endl;
    }

    // UpdateMin action test
    {
        using Action = kk2::action::UpdateMin<int>;
        using A = Action::A;
        using S = Action::S;

        rep(10000) {
            int val = kk2::random::rng(1, 1001);
            S x(kk2::random::rng(1, 1001));
            A f{S(val)};
            A f2{S()};

            auto result = Action::act(f, x);
            assert(result.a == val);

            auto result2 = Action::act(f2, x);
            assert(result2.is_unit);

            // unit actionのテスト
            A unit = A::unit();
            auto unit_result = Action::act(unit, x);
            assert(unit_result == x);
        }
        cerr << "UpdateMin: 10000 random tests passed!" << endl;
    }

    // UpdateMax action test
    {
        using Action = kk2::action::UpdateMax<int>;
        using A = Action::A;
        using S = Action::S;

        rep(10000) {
            int val = kk2::random::rng(1, 1001);
            S x(kk2::random::rng(1, 1001));
            A f{S(val)};
            A f2{S()};

            auto result = Action::act(f, x);
            assert(result.a == val);

            auto result2 = Action::act(f2, x);
            assert(result2.is_unit);

            // unit actionのテスト
            A unit = A::unit();
            auto unit_result = Action::act(unit, x);
            assert(unit_result == x);
        }
        cerr << "UpdateMax: 10000 random tests passed!" << endl;
    }

    // UpdateMaxMinSumWithSize action test
    {
        using Action = kk2::action::UpdateMaxMinSumWithSize<int, int>;
        using A = Action::A;
        using S = Action::S;

        rep(10000) {
            int val = kk2::random::rng(1, 1001);
            int size = kk2::random::rng(1, 101);
            S x(kk2::random::rng(1, 1001),
                kk2::random::rng(1, 1001),
                kk2::random::rng(1, 1001),
                size);
            A f(val);

            auto result = Action::act(f, x);
            assert(result.max == val);
            assert(result.min == val);
            assert(result.sum == val * size);
            assert(result.size == size);

            // unit actionのテスト
            A unit = A::unit();
            auto unit_result = Action::act(unit, x);
            assert(unit_result == x);
        }
        cerr << "UpdateMaxMinSumWithSize: 10000 random tests passed!" << endl;
    }

    // UpdateAffine action test
    {
        using Action = kk2::action::UpdateAffine<int>;
        using A = Action::A;
        using S = Action::S;

        rep(10000) {
            int a1 = kk2::random::rng(1, 11);
            int b1 = kk2::random::rng(1, 11);
            int a2 = kk2::random::rng(1, 11);
            int b2 = kk2::random::rng(1, 11);

            S new_affine(a1, b1);
            S x(a2, b2);
            A f(new_affine);

            auto result = Action::act(f, x);
            assert(result.a == a1);
            assert(result.b == b1);

            // unit actionのテスト
            A unit = A::unit();
            auto unit_result = Action::act(unit, x);
            assert(unit_result == x);
        }
        cerr << "UpdateAffine: 10000 random tests passed!" << endl;
    }

    // AffineSumWithSize action test
    {
        using Action = kk2::action::AffineSumWithSize<int, int>;
        using A = Action::A;
        using S = Action::S;

        rep(10000) {
            int a = kk2::random::rng(1, 11);
            int b = kk2::random::rng(1, 11);
            int sum = kk2::random::rng(1, 1001);
            int size = kk2::random::rng(1, 101);

            A f(a, b);
            S x(sum, size);

            auto result = Action::act(f, x);
            assert(result.a == a * sum + b * size);
            assert(result.size == size);
        }
        cerr << "AffineSumWithSize: 10000 random tests passed!" << endl;
    }

    // AddSumWithSize action test
    {
        using Action = kk2::action::AddSumWithSize<int, int>;
        using A = Action::A;
        using S = Action::S;

        rep(10000) {
            int add_val = kk2::random::rng(-1000, 1001);
            int sum = kk2::random::rng(-1000, 1001);
            int size = kk2::random::rng(1, 101);

            A f(add_val);
            S x(sum, size);

            auto result = Action::act(f, x);
            assert(result.a == sum + add_val * size);
            assert(result.size == size);
        }
        cerr << "AddSumWithSize: 10000 random tests passed!" << endl;
    }

    // AddMin action test
    {
        using Action = kk2::action::AddMin<int>;
        using A = Action::A;
        using S = Action::S;

        rep(10000) {
            int add_val = kk2::random::rng(-1000, 1001);
            int min_val = kk2::random::rng(-1000, 1001);

            A f(add_val);
            S x(min_val);

            auto result = Action::act(f, x);
            assert(result.a == min_val + add_val);

            // unit値のテスト
            S unit_x = S::unit();
            auto unit_result = Action::act(f, unit_x);
            assert(unit_result == unit_x);
        }
        cerr << "AddMin: 10000 random tests passed!" << endl;
    }

    // AddMax action test
    {
        using Action = kk2::action::AddMax<int>;
        using A = Action::A;
        using S = Action::S;

        rep(10000) {
            int add_val = kk2::random::rng(-1000, 1001);
            int max_val = kk2::random::rng(-1000, 1001);

            A f(add_val);
            S x(max_val);

            auto result = Action::act(f, x);
            assert(result.a == max_val + add_val);

            // unit値のテスト
            S unit_x = S::unit();
            auto unit_result = Action::act(f, unit_x);
            assert(unit_result == unit_x);
        }
        cerr << "AddMax: 10000 random tests passed!" << endl;
    }

    // AddMaxMinSumWithSize action test
    {
        using Action = kk2::action::AddMaxMinSumWithSize<int, int>;
        using A = Action::A;
        using S = Action::S;

        rep(10000) {
            int add_val = kk2::random::rng(-1000, 1001);
            int max_val = kk2::random::rng(-1000, 1001);
            int min_val = kk2::random::rng(-1000, 1001);
            int sum = kk2::random::rng(-1000, 1001);
            int size = kk2::random::rng(1, 101);

            A f(add_val);
            S x(max_val, min_val, sum, size);

            auto result = Action::act(f, x);
            assert(result.max == max_val + add_val);
            assert(result.min == min_val + add_val);
            assert(result.sum == sum + add_val * size);
            assert(result.size == size);

            // unit値のテスト
            S unit_x = S::unit();
            auto unit_result = Action::act(f, unit_x);
            assert(unit_result == unit_x);
        }
        cerr << "AddMaxMinSumWithSize: 10000 random tests passed!" << endl;
    }

    cerr << "All action tests passed!" << endl;
}

int main() {
    int a, b;
    kin >> a >> b;
    kout << a + b << kendl;

    test_action();

    return 0;
}

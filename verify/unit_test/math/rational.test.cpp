#define PROBLEM "https://judge.yosupo.jp/problem/aplusb" 

#include "../../../math/rational.hpp"
#include "../../../random/gen.hpp"
#include "../../../template/template.hpp"
using namespace std;
using namespace kk2;

void test_constructor() {
    // デフォルトコンストラクタ
    RationalInt r1;
    assert(r1.a == 0 && r1.b == 1);
    
    // 整数からのコンストラクタ
    RationalInt r2(5);
    assert(r2.a == 5 && r2.b == 1);
    
    // 分数コンストラクタ（既約分数になることを確認）
    RationalInt r3(6, 9);
    assert(r3.a == 2 && r3.b == 3);
    
    // 負の数のテスト
    RationalInt r4(-6, 9);
    assert(r4.a == -2 && r4.b == 3);
    
    RationalInt r5(6, -9);
    assert(r5.a == -2 && r5.b == 3);
    
    RationalInt r6(-6, -9);
    assert(r6.a == 2 && r6.b == 3);
}

void test_arithmetic() {
    RationalInt r1(1, 2);  // 1/2
    RationalInt r2(1, 3);  // 1/3
    
    // 足し算
    auto sum = r1 + r2;
    assert(sum.a == 5 && sum.b == 6);  // 1/2 + 1/3 = 5/6
    
    // 引き算
    auto diff = r1 - r2;
    assert(diff.a == 1 && diff.b == 6);  // 1/2 - 1/3 = 1/6
    
    // 掛け算
    auto prod = r1 * r2;
    assert(prod.a == 1 && prod.b == 6);  // 1/2 * 1/3 = 1/6
    
    // 割り算
    auto div = r1 / r2;
    assert(div.a == 3 && div.b == 2);  // (1/2) / (1/3) = 3/2
    
    // 同じ分母の場合
    RationalInt r3(2, 7);  // 2/7
    RationalInt r4(3, 7);  // 3/7
    auto sum2 = r3 + r4;
    assert(sum2.a == 5 && sum2.b == 7);  // 2/7 + 3/7 = 5/7
}

void test_comparison() {
    RationalInt r1(1, 2);  // 1/2
    RationalInt r2(2, 4);  // 2/4 = 1/2
    RationalInt r3(1, 3);  // 1/3
    
    // 等価性
    assert(r1 == r2);
    assert(!(r1 != r2));
    
    // 大小比較
    assert(r1 > r3);
    assert(r3 < r1);
    assert(r1 >= r2);
    assert(r1 <= r2);
    assert(r3 <= r1);
    
    // 負の数の比較
    RationalInt r4(-1, 2);  // -1/2
    assert(r4 < r3);
    assert(r3 > r4);
}

void test_unary_operations() {
    RationalInt r1(3, 4);  // 3/4
    
    // 単項マイナス
    auto neg = -r1;
    assert(neg.a == -3 && neg.b == 4);
    
    // 単項プラス
    auto pos = +r1;
    assert(pos.a == 3 && pos.b == 4);
    
    // 逆数
    auto inv = r1.inv();
    assert(inv.a == 4 && inv.b == 3);
    
    // 負の数の逆数
    RationalInt r2(-3, 4);
    auto inv2 = r2.inv();
    assert(inv2.a == -4 && inv2.b == 3);
    
    // 絶対値
    auto abs1 = r1.abs();
    assert(abs1.a == 3 && abs1.b == 4);
    
    auto abs2 = r2.abs();
    assert(abs2.a == 3 && abs2.b == 4);
}

void test_assignment_operators() {
    RationalInt r1(1, 2);
    RationalInt r2(1, 3);
    
    // +=
    r1 += r2;
    assert(r1.a == 5 && r1.b == 6);  // 1/2 + 1/3 = 5/6
    
    // -=
    r1 -= r2;
    assert(r1.a == 1 && r1.b == 2);  // 5/6 - 1/3 = 1/2
    
    // *=
    r1 *= r2;
    assert(r1.a == 1 && r1.b == 6);  // 1/2 * 1/3 = 1/6
    
    // /=
    r1 /= r2;
    assert(r1.a == 1 && r1.b == 2);  // (1/6) / (1/3) = 1/2
}

void test_boolean_conversion() {
    RationalInt r1(0, 1);  // 0
    RationalInt r2(1, 2);  // 1/2
    
    assert(!r1);
    assert(r2);
}

void test_floating_point_conversion() {
    RationalInt r1(1, 2);  // 1/2
    RationalInt r2(1, 3);  // 1/3
    
    assert(abs(r1.to_double() - 0.5) < 1e-9);
    assert(abs(r2.to_double() - (1.0/3.0)) < 1e-9);
    
    assert(abs(r1.to_ldouble() - 0.5L) < 1e-15L);
    assert(abs(r2.to_ldouble() - (1.0L/3.0L)) < 1e-15L);
}

void test_edge_cases() {
    // 分母が1の場合
    RationalInt r1(5, 1);
    assert(r1.a == 5 && r1.b == 1);
    
    // 大きなGCDの場合
    RationalInt r2(1000, 2000);
    assert(r2.a == 1 && r2.b == 2);
    
    // 0の場合
    RationalInt r3(0, 5);
    assert(r3.a == 0 && r3.b == 1);
}

void test_precision_edge_cases() {
    // 非常に小さな分数
    RationalInt r1(1LL, 1000000000LL);
    assert(r1.a == 1LL && r1.b == 1000000000LL);
    
    // 分子が0のケース
    RationalInt r2(0, 12345);
    assert(r2.a == 0 && r2.b == 1);
    
    // 分子分母が同じ符号
    RationalInt r3(-100, -200);
    assert(r3.a == 1 && r3.b == 2);
}

void test_random_operations() {
    // ランダムな分数での基本演算テスト（1e6回）
    for (int i = 0; i < 1000000; i++) {
        int a1 = random::rng(-10000, 10001), b1 = random::rng(1, 10001);
        int a2 = random::rng(-10000, 10001), b2 = random::rng(1, 10001);
        
        RationalInt r1(a1, b1), r2(a2, b2);
        
        // 加法の逆元テスト: r + (-r) = 0
        assert((r1 + (-r1)).a == 0);
        
        // 乗法の逆元テスト: r * r.inv() = 1 (r != 0の場合)
        if (r1.a != 0) {
            auto prod = r1 * r1.inv();
            assert(prod.a == 1 && prod.b == 1);
        }
        
        // 交換律テスト: a + b = b + a, a * b = b * a
        assert(r1 + r2 == r2 + r1);
        assert(r1 * r2 == r2 * r1);
        
        // 除法の定義テスト: a / b = a * b.inv()
        if (r2.a != 0) {
            assert(r1 / r2 == r1 * r2.inv());
        }
    }
}

void test_comparison_consistency() {
    // 比較演算子の一貫性テスト（1e6回）
    for (int i = 0; i < 1000000; i++) {
        int a1 = random::rng(-10000, 10001), b1 = random::rng(1, 10001);
        int a2 = random::rng(-10000, 10001), b2 = random::rng(1, 10001);
        
        RationalInt r1(a1, b1), r2(a2, b2);
        
        // 三分律: r1 < r2, r1 == r2, r1 > r2 のうち exactly one が真
        int count = 0;
        if (r1 < r2) count++;
        if (r1 == r2) count++;
        if (r1 > r2) count++;
        assert(count == 1);
        
        // 推移律の一部: r1 <= r2 and r2 <= r1 => r1 == r2
        if (r1 <= r2 && r2 <= r1) {
            assert(r1 == r2);
        }
        
        // 反対称性: r1 < r2 <=> r2 > r1
        assert((r1 < r2) == (r2 > r1));
        assert((r1 <= r2) == (r2 >= r1));
    }
}

void test_overflow_safety() {
    // オーバーフローを避けるための境界値テスト
    const int SAFE_MAX = 10000;  // 安全な最大値
    
    RationalInt r1(SAFE_MAX, 1);
    RationalInt r2(1, SAFE_MAX);
    
    // 大きな数同士の演算
    auto sum = r1 + r2;  // SAFE_MAX + 1/SAFE_MAX
    assert(sum.a == SAFE_MAX * SAFE_MAX + 1);
    assert(sum.b == SAFE_MAX);
    
    // 約分が正しく行われることを確認
    RationalInt r3(SAFE_MAX * 2, SAFE_MAX * 4);
    assert(r3.a == 1 && r3.b == 2);
}

void test_double_conversion_accuracy() {
    // 浮動小数点変換の精度テスト（1e6回）
    for (int i = 0; i < 1000000; i++) {
        int a = random::rng(-1000, 1001);
        int b = random::rng(1, 1001);
        
        RationalInt r(a, b);
        double expected = (double)a / b;
        
        assert(abs(r.to_double() - expected) < 1e-12);
        
        // long double版も確認
        long double expected_ld = (long double)a / b;
        assert(abs(r.to_ldouble() - expected_ld) < 1e-15L);
    }
}

void test_stress_large_numbers() {
    // 大きな数でのストレステスト
    const long long BIG = 1000000007LL;
    
    RationalI64 r1(BIG, 1);
    RationalI64 r2(1, BIG);
    
    // 大きな数同士の演算
    auto sum = r1 + r2;
    assert(sum.a == BIG * BIG + 1);
    assert(sum.b == BIG);
    
    auto diff = r1 - r2;
    assert(diff.a == BIG * BIG - 1);
    assert(diff.b == BIG);
    
    auto prod = r1 * r2;
    assert(prod.a == 1 && prod.b == 1);
    
    auto div = r1 / r2;
    assert(div.a == BIG * BIG && div.b == 1);
}

void test_special_rational_values() {
    // 特殊な有理数値のテスト
    
    // 1/1 = 1
    RationalInt one(1, 1);
    assert(one.a == 1 && one.b == 1);
    
    // 任意の数に1を足す/引く
    RationalInt r(3, 7);
    auto plus_one = r + one;
    assert(plus_one.a == 10 && plus_one.b == 7);  // 3/7 + 1 = 10/7
    
    auto minus_one = r - one;
    assert(minus_one.a == -4 && minus_one.b == 7);  // 3/7 - 1 = -4/7
    
    // 1/2の累乗
    RationalInt half(1, 2);
    auto quarter = half * half;
    assert(quarter.a == 1 && quarter.b == 4);  // (1/2)^2 = 1/4
    
    auto eighth = quarter * half;
    assert(eighth.a == 1 && eighth.b == 8);  // (1/4) * (1/2) = 1/8
}

void test_chain_operations() {
    // 連続演算のテスト（1e6回）
    for (int i = 0; i < 1000000; i++) {
        RationalInt result(1, 1);  // 1から開始
        
        // 各テストケースで10回の連続演算
        for (int j = 0; j < 10; j++) {
            int op = random::rng(0, 4);  // 0:+, 1:-, 2:*, 3:/
            int a = random::rng(-10, 11);
            int b = random::rng(1, 11);
            
            RationalInt operand(a, b);
            
            switch (op) {
                case 0: result += operand; break;
                case 1: result -= operand; break;
                case 2: result *= operand; break;
                case 3:
                    if (operand.a != 0) {
                        result /= operand;
                    }
                    break;
            }
            
            // 結果が正規化されていることを確認
            assert(result.b > 0);
            assert(std::gcd(abs(result.a), result.b) == 1);
        }
    }
}

int main() {
    int a, b;
    kin >> a >> b;
    kout << a + b << kendl;

    cerr << "Starting comprehensive rational number tests..." << endl;

    // 基本テスト実行
    cerr << "Running basic functionality tests..." << endl;
    test_constructor();
    test_arithmetic();
    test_comparison();
    test_unary_operations();
    test_assignment_operators();
    test_boolean_conversion();
    test_floating_point_conversion();
    test_edge_cases();
    
    // 境界値・ランダムテスト実行
    cerr << "Running boundary value and random tests..." << endl;
    test_precision_edge_cases();
    test_random_operations();
    test_comparison_consistency();
    test_overflow_safety();
    test_double_conversion_accuracy();
    
    // 追加の厳密テスト
    cerr << "Running stress and edge case tests..." << endl;
    test_stress_large_numbers();
    test_special_rational_values();
    test_chain_operations();
    
    // すべてのテストが通った場合
    cerr << endl << "=== ALL RATIONAL TESTS PASSED ===" << endl;
    cerr << "All tests completed successfully!" << endl;

    return 0;
}

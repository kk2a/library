// competitive-verifier: STANDALONE

#include <algorithm>
#include <cassert>

#include "../../../fps/fps_arb.hpp"
#include "../../../fps/fps_ntt_friendly.hpp"
#include "../../../modint/mont.hpp"

namespace {

template <class FPS> void test_inverse_apis() {
    const FPS source{2, 0, 3, 0, 5, 0, 7};

    for (int deg : {0, 1, 7, 10}) {
        const FPS dense = source.dense_inv(deg);
        const FPS sparse = source.sparse_inv(deg);
        assert(dense == sparse);

        FPS inplace_dense = source;
        FPS &dense_reference = inplace_dense.inplace_dense_inv(deg);
        assert(&dense_reference == &inplace_dense);
        assert(inplace_dense == dense);

        FPS inplace_sparse = source;
        FPS &sparse_reference = inplace_sparse.inplace_sparse_inv(deg);
        assert(&sparse_reference == &inplace_sparse);
        assert(inplace_sparse == sparse);

        const FPS automatic = source.inv(deg);
        FPS inplace_automatic = source;
        FPS &automatic_reference = inplace_automatic.inplace_inv(deg);
        assert(&automatic_reference == &inplace_automatic);
        assert(inplace_automatic == automatic);
        assert(automatic == dense);
    }

    FPS default_degree = source;
    default_degree.inplace_inv();
    assert(default_degree == source.inv());
}

template <class FPS> void test_logarithm_apis() {
    const FPS source{1, 0, 3, 0, 5, 0, 7};

    for (int deg : {0, 1, 7, 10}) {
        const FPS dense = source.dense_log(deg);
        const FPS sparse = source.sparse_log(deg);
        assert(dense == sparse);

        FPS inplace_dense = source;
        FPS &dense_reference = inplace_dense.inplace_dense_log(deg);
        assert(&dense_reference == &inplace_dense);
        assert(inplace_dense == dense);

        FPS inplace_sparse = source;
        FPS &sparse_reference = inplace_sparse.inplace_sparse_log(deg);
        assert(&sparse_reference == &inplace_sparse);
        assert(inplace_sparse == sparse);

        const FPS automatic = source.log(deg);
        FPS inplace_automatic = source;
        FPS &automatic_reference = inplace_automatic.inplace_log(deg);
        assert(&automatic_reference == &inplace_automatic);
        assert(inplace_automatic == automatic);
        assert(automatic == dense);
    }

    FPS default_degree = source;
    default_degree.inplace_log();
    assert(default_degree == source.log());
}

template <class FPS> void test_exponential_apis() {
    const FPS source{0, 0, 3, 0, 5, 0, 7};

    for (int deg : {0, 1, 7, 10}) {
        const FPS dense = source.dense_exp(deg);
        const FPS sparse = source.sparse_exp(deg);
        assert(dense == sparse);

        FPS inplace_dense = source;
        FPS &dense_reference = inplace_dense.inplace_dense_exp(deg);
        assert(&dense_reference == &inplace_dense);
        assert(inplace_dense == dense);

        FPS inplace_sparse = source;
        FPS &sparse_reference = inplace_sparse.inplace_sparse_exp(deg);
        assert(&sparse_reference == &inplace_sparse);
        assert(inplace_sparse == sparse);

        const FPS automatic = source.exp(deg);
        FPS inplace_automatic = source;
        FPS &automatic_reference = inplace_automatic.inplace_exp(deg);
        assert(&automatic_reference == &inplace_automatic);
        assert(inplace_automatic == automatic);
        assert(automatic == dense);
    }

    FPS default_degree = source;
    default_degree.inplace_exp();
    assert(default_degree == source.exp());
}

template <class FPS> void test_power_apis() {
    for (const FPS &source : {
             FPS{2, 0, 3, 0, 5},
             FPS{0, 0, 2, 0, 3},
             FPS{0, 0, 0, 0}
    }) {
        for (long long exponent : {0, 1, 3}) {
            for (int deg : {0, 1, 7, 10}) {
                const FPS dense = source.dense_pow(exponent, deg);
                const FPS sparse = source.sparse_pow(exponent, deg);
                assert(dense == sparse);

                FPS inplace_dense = source;
                FPS &dense_reference = inplace_dense.inplace_dense_pow(exponent, deg);
                assert(&dense_reference == &inplace_dense);
                assert(inplace_dense == dense);

                FPS inplace_sparse = source;
                FPS &sparse_reference = inplace_sparse.inplace_sparse_pow(exponent, deg);
                assert(&sparse_reference == &inplace_sparse);
                assert(inplace_sparse == sparse);

                const FPS automatic = source.pow(exponent, deg);
                FPS inplace_automatic = source;
                FPS &automatic_reference = inplace_automatic.inplace_pow(exponent, deg);
                assert(&automatic_reference == &inplace_automatic);
                assert(inplace_automatic == automatic);
                assert(automatic == dense);
            }
        }
    }
}

template <class FPS> void test_square_root_apis() {
    const FPS root{2, 0, 3, 0, 5};
    const FPS source = root.dense_mul(root).pre(9);

    for (int deg : {0, 1, 7, 10}) {
        const FPS dense = source.dense_sqrt(deg);
        const FPS sparse = source.sparse_sqrt(deg);
        assert(dense == sparse);

        FPS inplace_dense = source;
        FPS &dense_reference = inplace_dense.inplace_dense_sqrt(deg);
        assert(&dense_reference == &inplace_dense);
        assert(inplace_dense == dense);

        FPS inplace_sparse = source;
        FPS &sparse_reference = inplace_sparse.inplace_sparse_sqrt(deg);
        assert(&sparse_reference == &inplace_sparse);
        assert(inplace_sparse == sparse);

        const FPS automatic = source.sqrt(deg);
        FPS inplace_automatic = source;
        FPS &automatic_reference = inplace_automatic.inplace_sqrt(deg);
        assert(&automatic_reference == &inplace_automatic);
        assert(inplace_automatic == automatic);
        assert(automatic == dense);
    }

    FPS no_square_root{3};
    no_square_root.inplace_sqrt();
    assert(no_square_root.empty());
}

template <class FPS> void test_multiplication_apis() {
    const FPS lhs{1, 0, 2, 0, 3};
    const FPS rhs{4, 0, 5};
    const FPS dense = lhs.dense_mul(rhs);
    const FPS sparse = lhs.sparse_mul(rhs);
    assert(dense == sparse);

    FPS inplace_dense = lhs;
    FPS &dense_reference = inplace_dense.inplace_dense_mul(rhs);
    assert(&dense_reference == &inplace_dense);
    assert(inplace_dense == dense);

    FPS inplace_sparse = lhs;
    FPS &sparse_reference = inplace_sparse.inplace_sparse_mul(rhs);
    assert(&sparse_reference == &inplace_sparse);
    assert(inplace_sparse == sparse);

    assert(lhs.mul(rhs) == dense);
    FPS inplace_automatic = lhs;
    FPS &automatic_reference = inplace_automatic.inplace_mul(rhs);
    assert(&automatic_reference == &inplace_automatic);
    assert(inplace_automatic == dense);
    assert(lhs * rhs == dense);

    const FPS square = lhs.dense_mul(lhs);
    for (auto operation : {&FPS::inplace_dense_mul, &FPS::inplace_sparse_mul, &FPS::inplace_mul}) {
        FPS alias = lhs;
        (alias.*operation)(alias, -1);
        assert(alias == square);
    }

    for (int deg : {0, 1, 4, 10}) {
        const int result_size = std::min(deg, static_cast<int>(dense.size()));
        const FPS expected(dense.begin(), dense.begin() + result_size);
        assert(lhs.dense_mul(rhs, deg) == expected);
        assert(lhs.sparse_mul(rhs, deg) == expected);
        assert(lhs.mul(rhs, deg) == expected);

        const int square_size = std::min(deg, static_cast<int>(square.size()));
        const FPS expected_square(square.begin(), square.begin() + square_size);
        for (auto operation :
             {&FPS::inplace_dense_mul, &FPS::inplace_sparse_mul, &FPS::inplace_mul}) {
            FPS alias = lhs;
            (alias.*operation)(alias, deg);
            assert(alias == expected_square);
        }
    }

    if constexpr (kk2::fps::NTTFriendlyFormalPowerSeries<FPS>) {
        assert(kk2::dense_convolution(lhs, rhs) == dense);
        assert(kk2::sparse_convolution(lhs, rhs) == dense);
        assert(kk2::convolution(lhs, rhs) == dense);

        FPS inplace = lhs;
        FPS &reference = kk2::inplace_convolution(inplace, rhs);
        assert(&reference == &inplace);
        assert(inplace == dense);
    } else {
        assert(kk2::dense_convolution_arb(lhs, rhs) == dense);
        assert(kk2::sparse_convolution_arb(lhs, rhs) == dense);
        assert(kk2::convolution_arb(lhs, rhs) == dense);

        FPS inplace = lhs;
        FPS &reference = kk2::inplace_convolution_arb(inplace, rhs);
        assert(&reference == &inplace);
        assert(inplace == dense);
    }
}

template <class FPS> void test_division_apis() {
    const FPS dividend{2, 0, 3, 0, 5};
    const FPS divisor{4, 0, 7};

    for (int deg : {0, 1, 7, 10}) {
        const FPS dense = dividend.dense_div(divisor, deg);
        const FPS sparse = dividend.sparse_div(divisor, deg);
        assert(dense == sparse);

        FPS inplace_dense = dividend;
        FPS &dense_reference = inplace_dense.inplace_dense_div(divisor, deg);
        assert(&dense_reference == &inplace_dense);
        assert(inplace_dense == dense);

        FPS inplace_sparse = dividend;
        FPS &sparse_reference = inplace_sparse.inplace_sparse_div(divisor, deg);
        assert(&sparse_reference == &inplace_sparse);
        assert(inplace_sparse == sparse);

        assert(dividend.div(divisor, deg) == dense);
        FPS inplace_automatic = dividend;
        FPS &automatic_reference = inplace_automatic.inplace_div(divisor, deg);
        assert(&automatic_reference == &inplace_automatic);
        assert(inplace_automatic == dense);

        FPS alias = divisor;
        alias.inplace_div(alias, deg);
        FPS identity(deg);
        if (deg > 0) identity[0] = 1;
        assert(alias == identity);
        assert(divisor.dense_div(divisor, deg) == identity);
        assert(divisor.sparse_div(divisor, deg) == identity);
        assert(divisor.div(divisor, deg) == identity);
    }
}

template <class FPS> void test_quotient_apis() {
    const FPS divisor{1, 0, 2, 3};
    const FPS quotient{4, 0, 5, 6, 7};
    const FPS dividend = divisor.dense_mul(quotient);
    const FPS dense = dividend.dense_quo(divisor);
    const FPS sparse = dividend.sparse_quo(divisor);
    assert(dense == quotient);
    assert(sparse == quotient);

    FPS inplace_dense = dividend;
    FPS &dense_reference = inplace_dense.inplace_dense_quo(divisor);
    assert(&dense_reference == &inplace_dense);
    assert(inplace_dense == quotient);

    FPS inplace_sparse = dividend;
    FPS &sparse_reference = inplace_sparse.inplace_sparse_quo(divisor);
    assert(&sparse_reference == &inplace_sparse);
    assert(inplace_sparse == quotient);

    assert(dividend.quo(divisor) == quotient);
    FPS inplace_automatic = dividend;
    FPS &automatic_reference = inplace_automatic.inplace_quo(divisor);
    assert(&automatic_reference == &inplace_automatic);
    assert(inplace_automatic == quotient);
    assert(dividend / divisor == quotient);

    for (auto operation : {&FPS::inplace_dense_quo, &FPS::inplace_sparse_quo, &FPS::inplace_quo}) {
        FPS alias = divisor;
        (alias.*operation)(alias);
        assert(alias == FPS{1});
    }
    assert(divisor.dense_quo(divisor) == FPS{1});
    assert(divisor.sparse_quo(divisor) == FPS{1});
    assert(divisor.quo(divisor) == FPS{1});

    const FPS with_remainder = dividend + FPS{2, 3};
    const FPS remainder{2, 3};
    assert(with_remainder.mod(divisor) == remainder);
    FPS inplace_remainder = with_remainder;
    FPS &remainder_reference = inplace_remainder.inplace_mod(divisor);
    assert(&remainder_reference == &inplace_remainder);
    assert(inplace_remainder == remainder);
    assert(with_remainder % divisor == remainder);

    FPS alias_remainder = divisor;
    alias_remainder.inplace_mod(alias_remainder);
    assert(alias_remainder.empty());
}

} // namespace

int main() {
    test_inverse_apis<kk2::FPSNTT<kk2::mont998>>();
    test_inverse_apis<kk2::FPSArb<kk2::mont998>>();
    test_logarithm_apis<kk2::FPSNTT<kk2::mont998>>();
    test_logarithm_apis<kk2::FPSArb<kk2::mont998>>();
    test_exponential_apis<kk2::FPSNTT<kk2::mont998>>();
    test_exponential_apis<kk2::FPSArb<kk2::mont998>>();
    test_power_apis<kk2::FPSNTT<kk2::mont998>>();
    test_power_apis<kk2::FPSArb<kk2::mont998>>();
    test_square_root_apis<kk2::FPSNTT<kk2::mont998>>();
    test_square_root_apis<kk2::FPSArb<kk2::mont998>>();
    test_multiplication_apis<kk2::FPSNTT<kk2::mont998>>();
    test_multiplication_apis<kk2::FPSArb<kk2::mont998>>();
    test_division_apis<kk2::FPSNTT<kk2::mont998>>();
    test_division_apis<kk2::FPSArb<kk2::mont998>>();
    test_quotient_apis<kk2::FPSNTT<kk2::mont998>>();
    test_quotient_apis<kk2::FPSArb<kk2::mont998>>();
}

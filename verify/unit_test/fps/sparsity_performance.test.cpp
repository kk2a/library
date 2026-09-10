// competitive-verifier: STANDALONE

#include <algorithm>
#include <cassert>
#include <iostream>
#include <limits>
#include <string_view>

#include "../../../fps/fps_ntt_friendly.hpp"
#include "../../../fps/fps_sqrt.hpp"
#include "../../../modint/mont.hpp"
#include "../../../others/timer.hpp"

using FPS = kk2::FPSNTT<kk2::mont998>;
using mint = kk2::mont998;

namespace {

volatile unsigned benchmark_sink = 0;

FPS make_series(int n, int support, mint constant) {
    FPS f(n);
    f[0] = constant;
    for (int i = 1; i < support; ++i) {
        int index = 1 + (long long)(i - 1) * (n - 1) / std::max(1, support - 1);
        f[index] = mint(1234567LL * i + 890123);
    }
    return f;
}

template <class F> double measure(F &&fn, int repetitions = 2) {
    double best = std::numeric_limits<double>::infinity();
    for (int trial = 0; trial < 2; ++trial) {
        kk2::Timer timer;
        for (int i = 0; i < repetitions; ++i) {
            auto result = fn();
            benchmark_sink = benchmark_sink ^ result.back().val();
        }
        best = std::min(best, timer.elapsed() / repetitions);
    }
    return best;
}

template <class Sparse, class Dense>
void check_choice(std::string_view name, bool selects_sparse, Sparse &&sparse, Dense &&dense) {
    sparse();
    dense();
    const double sparse_ms = measure(sparse);
    const double dense_ms = measure(dense);
    const double selected_ms = selects_sparse ? sparse_ms : dense_ms;
    const double best_ms = std::min(sparse_ms, dense_ms);
    if (selected_ms > 2.0 * best_ms + 0.01) {
        std::cerr << name << ": selected=" << selected_ms << "ms, sparse=" << sparse_ms
                  << "ms, dense=" << dense_ms << "ms\n";
        assert(false);
    }
}

void test_measured_choices() {
    for (int n : {512, 2048}) {
        for (int support : {16, n / 2}) {
            const FPS unit = make_series(n, support, 1);
            FPS exponential = unit;
            exponential[0] = 0;
            const FPS other = make_series(n, support, 2);

            check_choice(
                "convolution",
                kk2::is_sparse_operation(kk2::FPSOperation::CONVOLUTION, true, unit, other),
                [&] {
                    FPS result = unit;
                    return kk2::sparse_convolution(result, other);
                },
                [&] { return unit.dense_mul(other); });
            check_choice(
                "inverse",
                kk2::is_sparse_operation(kk2::FPSOperation::INVERSE, true, unit, FPS(), n),
                [&] { return unit.sparse_inv(n); },
                [&] { return unit.dense_inv(n); });
            check_choice(
                "log",
                kk2::is_sparse_operation(kk2::FPSOperation::LOG, true, unit, FPS(), n),
                [&] { return unit.sparse_log(n); },
                [&] { return unit.dense_log(n); });
            check_choice(
                "exp",
                kk2::is_sparse_operation(kk2::FPSOperation::EXP, true, exponential, FPS(), n),
                [&] { return exponential.sparse_exp(n); },
                [&] { return exponential.dense_exp(n); });
            check_choice(
                "pow",
                kk2::is_sparse_operation(kk2::FPSOperation::POWER, true, unit, FPS(), n),
                [&] { return unit.sparse_pow(7, n); },
                [&] { return unit.dense_pow(7, n); });
            check_choice(
                "division",
                kk2::is_sparse_operation(kk2::FPSOperation::DIVISION, true, other, unit, n),
                [&] { return other.sparse_div(unit, n); },
                [&] { return other.dense_mul(unit.dense_inv(n)).pre(n); });
            check_choice(
                "sqrt",
                kk2::is_sparse_operation(kk2::FPSOperation::SQRT, true, unit, FPS(), n),
                [&] { return kk2::sparse_sqrt(unit, n); },
                [&] { return kk2::dense_sqrt(unit, n); });

            FPS divisor = unit;
            divisor.back() = 1;
            const FPS dividend = other.dense_mul(divisor);
            check_choice(
                "polynomial division",
                kk2::is_sparse_operation(
                    kk2::FPSOperation::POLYNOMIAL_DIVISION, true, dividend, divisor, n),
                [&] { return dividend.sparse_quo(divisor); },
                [&] { return dividend.dense_quo(divisor); });
        }
    }
}

void test_large_selected_paths() {
    constexpr int n = 1 << 17;
    const FPS sparse_unit = make_series(n, 8, 1);
    FPS sparse_exp_input = sparse_unit;
    sparse_exp_input[0] = 0;
    const FPS dense_unit = make_series(n, n, 1);

    assert(kk2::is_sparse_operation(kk2::FPSOperation::EXP, true, sparse_exp_input, FPS(), n));
    assert(!kk2::is_sparse_operation(kk2::FPSOperation::INVERSE, true, dense_unit, FPS(), n));

    kk2::Timer timer;
    const FPS sparse_result = sparse_exp_input.exp(n);
    const FPS dense_result = dense_unit.inv(n);
    benchmark_sink = benchmark_sink ^ sparse_result.back().val() ^ dense_result.back().val();
    assert(timer.elapsed() < 1000.0);
}

} // namespace

int main() {
    test_measured_choices();
    test_large_selected_paths();
}

// competitive-verifier: STANDALONE

#include <algorithm>
#include <cassert>
#include <iostream>
#include <string_view>

#include "../../../fps/fps_ntt_friendly.hpp"
#include "../../../fps/fps_sqrt.hpp"
#include "../../../modint/mont.hpp"
#include "../../../others/timer.hpp"

using FPS = kk2::FPSNTT<kk2::mont998>;
using mint = kk2::mont998;

namespace {

constexpr int repetitions = 1000;
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

template <class F> double measure(F &&fn) {
    kk2::Timer timer;
    for (int i = 0; i < repetitions; ++i) {
        auto result = fn();
        benchmark_sink = benchmark_sink ^ result.back().val();
    }
    return timer.elapsed();
}

template <class Sparse, class Dense>
void check_choice(std::string_view name, bool selects_sparse, Sparse &&sparse, Dense &&dense) {
    sparse();
    dense();
    const double sparse_ms = measure(sparse);
    const double dense_ms = measure(dense);
    const double selected_ms = selects_sparse ? sparse_ms : dense_ms;
    const double best_ms = std::min(sparse_ms, dense_ms);
    if (selected_ms > 2.0 * best_ms + 0.1) {
        std::cerr << name << ": selected=" << selected_ms << "ms, sparse=" << sparse_ms
                  << "ms, dense=" << dense_ms << "ms\n";
        assert(false);
    }
}

void test_small_measured_choices() {
    for (int n : {16, 32}) {
        for (int support : {4, n / 2}) {
            const FPS unit = make_series(n, support, 1);
            const FPS other = make_series(n, support, 2);
            FPS exponential = unit;
            exponential[0] = 0;

            check_choice(
                "convolution",
                kk2::is_sparse_operation(kk2::FPSOperation::CONVOLUTION, true, unit, other),
                [&] { return kk2::sparse_convolution(unit, other); },
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

} // namespace

int main() { test_small_measured_choices(); }

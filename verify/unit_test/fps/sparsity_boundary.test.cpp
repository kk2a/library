// competitive-verifier: STANDALONE

#include <algorithm>
#include <cassert>

#include "../../../fps/fps_ntt_friendly.hpp"
#include "../../../modint/mont.hpp"

using FPS = kk2::FPSNTT<kk2::mont998>;
using mint = kk2::mont998;

FPS make_series(int n, int support, mint constant) {
    FPS f(n);
    f[0] = constant;
    for (int i = 1; i < support; ++i) {
        int index = 1 + (long long)(i - 1) * (n - 1) / std::max(1, support - 1);
        f[index] = mint(1234567LL * i + 890123);
    }
    return f;
}

int main() {
    const FPS pow_input{2, 3, 0, 5, 0, 0, 7, 0};
    for (long long exponent : {0LL, 1LL, 7LL, 998244353LL, 1000000000000000000LL})
        assert(pow_input.sparse_pow(exponent, 8) == pow_input.dense_pow(exponent, 8));

    constexpr int n = 1024;
    const FPS sparse = make_series(n, 32, 1);
    const FPS dense = make_series(n, 512, 1);
    FPS sparse_exp = sparse, dense_exp = dense;
    sparse_exp[0] = dense_exp[0] = 0;

    assert(kk2::is_sparse_operation(kk2::FPSOperation::CONVOLUTION, true, sparse, sparse));
    assert(!kk2::is_sparse_operation(kk2::FPSOperation::CONVOLUTION, true, dense, dense));
    assert(kk2::is_sparse_operation(kk2::FPSOperation::EXP, true, sparse_exp, FPS(), n));
    assert(!kk2::is_sparse_operation(kk2::FPSOperation::EXP, true, dense_exp, FPS(), n));

    FPS sparse_divisor = sparse, dense_divisor = dense;
    sparse_divisor.back() = dense_divisor.back() = 1;
    const FPS dividend = dense.dense_mul(dense_divisor);
    assert(kk2::is_sparse_operation(
        kk2::FPSOperation::POLYNOMIAL_DIVISION, true, dividend, sparse_divisor, n));
    assert(!kk2::is_sparse_operation(
        kk2::FPSOperation::POLYNOMIAL_DIVISION, true, dividend, dense_divisor, n));
}

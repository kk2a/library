// competitive-verifier: STANDALONE

#include <cassert>
#include <vector>

#include "../../../fps/fps_multivariate.hpp"
#include "../../../modint/mont.hpp"

template <class MFPS> void fill_dense(MFPS &f) {
    for (int i = 0; i < f.size(); ++i) f[i] = typename MFPS::value_type(i + 2);
}

template <class MFPS> void fill_unit(MFPS &f) {
    f[0] = 1;
    for (int i = 1; i < f.size(); ++i) f[i] = typename MFPS::value_type(i + 1);
}

template <class MFPS> void assert_product_is_one(const MFPS &f, const MFPS &inverse) {
    MFPS product = f.dense_mul(inverse);
    assert(product[0] == 1);
    for (int i = 1; i < product.size(); ++i) assert(product[i] == 0);
}

template <class MFPS> void test_multiplication_apis() {
    MFPS lhs(std::vector<int>{3, 4}), rhs(std::vector<int>{3, 4});
    fill_dense(lhs);
    fill_dense(rhs);

    const MFPS dense = lhs.dense_mul(rhs);
    MFPS inplace_dense = lhs;
    inplace_dense.inplace_dense_mul(rhs);
    assert(inplace_dense == dense);

    const MFPS sparse = lhs.sparse_mul(rhs);
    MFPS inplace_sparse = lhs;
    inplace_sparse.inplace_sparse_mul(rhs);
    assert(inplace_sparse == sparse);

    const MFPS automatic = lhs.mul(rhs);
    MFPS inplace_automatic = lhs;
    inplace_automatic.inplace_mul(rhs);
    assert(inplace_automatic == automatic);
    assert(automatic == dense);
}

template <class MFPS> void test_inverse_apis() {
    MFPS f(std::vector<int>{3, 4});
    fill_unit(f);

    const MFPS dense = f.dense_inv();
    MFPS inplace_dense = f;
    inplace_dense.inplace_dense_inv();
    assert(inplace_dense == dense);

    const MFPS sparse = f.sparse_inv();
    MFPS inplace_sparse = f;
    inplace_sparse.inplace_sparse_inv();
    assert(inplace_sparse == sparse);

    const MFPS automatic = f.inv();
    MFPS inplace_automatic = f;
    inplace_automatic.inplace_inv();
    assert(inplace_automatic == automatic);
    assert(automatic == dense);
    assert_product_is_one(f, dense);
    assert_product_is_one(f, sparse);
    assert_product_is_one(f, automatic);
}

template <class MFPS> void test_log_exp_pow_apis() {
    MFPS log_input(std::vector<int>{3, 4});
    fill_unit(log_input);
    const MFPS dense_log = log_input.dense_log();
    const MFPS sparse_log = log_input.sparse_log();
    const MFPS automatic_log = log_input.log();
    MFPS inplace_log = log_input;
    inplace_log.inplace_log();
    assert(dense_log == sparse_log);
    assert(automatic_log == dense_log);
    assert(inplace_log == automatic_log);

    MFPS exp_input(std::vector<int>{3, 4});
    exp_input[0] = 0;
    for (int i = 1; i < exp_input.size(); ++i) exp_input[i] = typename MFPS::value_type(i);
    const MFPS dense_exp = exp_input.dense_exp();
    const MFPS sparse_exp = exp_input.sparse_exp();
    const MFPS automatic_exp = exp_input.exp();
    MFPS inplace_exp = exp_input;
    inplace_exp.inplace_exp();
    assert(dense_exp == sparse_exp);
    assert(automatic_exp == dense_exp);
    assert(inplace_exp == automatic_exp);

    const MFPS dense_pow = log_input.dense_pow(3);
    const MFPS sparse_pow = log_input.sparse_pow(3);
    const MFPS automatic_pow = log_input.pow(3);
    MFPS inplace_pow = log_input;
    inplace_pow.inplace_pow(3);
    assert(dense_pow == sparse_pow);
    assert(automatic_pow == dense_pow);
    assert(inplace_pow == automatic_pow);
}

int main() {
    using NTTMFPS = kk2::MultivariateFormalPowerSeries<kk2::mont998>;
    using ArbMFPS = kk2::MultivariateFormalPowerSeriesArbitrary<kk2::mont107>;

    test_multiplication_apis<NTTMFPS>();
    test_multiplication_apis<ArbMFPS>();
    test_inverse_apis<NTTMFPS>();
    test_inverse_apis<ArbMFPS>();
    test_log_exp_pow_apis<NTTMFPS>();
    test_log_exp_pow_apis<ArbMFPS>();
}

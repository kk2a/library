// competitive-verifier: STANDALONE

#include <cassert>
#include <vector>

#include "../../../fps/fps_multivariate.hpp"
#include "../../../modint/mont.hpp"

template <class MFPS> MFPS naive_product(const MFPS &lhs, const MFPS &rhs) {
    assert(lhs.base == rhs.base);
    MFPS result(lhs.base);
    for (int i = 0; i < lhs.size(); ++i) {
        int x = i;
        std::vector<int> lhs_index(lhs.base.size());
        for (int d = 0; d < (int)lhs.base.size(); ++d) {
            lhs_index[d] = x % lhs.base[d];
            x /= lhs.base[d];
        }
        for (int j = 0; j < rhs.size(); ++j) {
            int y = j, index = 0, stride = 1;
            bool in_range = true;
            for (int d = 0; d < (int)rhs.base.size(); ++d) {
                const int coordinate = lhs_index[d] + y % rhs.base[d];
                y /= rhs.base[d];
                if (coordinate >= rhs.base[d]) in_range = false;
                index += coordinate * stride;
                stride *= rhs.base[d];
            }
            if (in_range) result[index] += lhs[i] * rhs[j];
        }
    }
    return result;
}

template <class MFPS> void fill_test_data(MFPS &f) {
    for (int i = 0; i < f.size(); ++i) f[i] = typename MFPS::value_type(i * 17 + 3);
}

void test_ntt_friendly_product() {
    using MFPS = kk2::MultivariateFormalPowerSeries<kk2::mont998>;
    MFPS lhs(std::vector<int>{4, 5}), rhs(std::vector<int>{4, 5});
    fill_test_data(lhs);
    fill_test_data(rhs);
    assert(lhs * rhs == naive_product(lhs, rhs));
}

void test_arbitrary_modulus_product() {
    using MFPS = kk2::MultivariateFormalPowerSeriesArbitrary<kk2::mont107>;
    MFPS lhs(std::vector<int>{4, 5}), rhs(std::vector<int>{4, 5});
    fill_test_data(lhs);
    fill_test_data(rhs);
    assert(lhs * rhs == naive_product(lhs, rhs));

    MFPS lhs_3d(std::vector<int>{3, 4, 2}), rhs_3d(std::vector<int>{3, 4, 2});
    fill_test_data(lhs_3d);
    fill_test_data(rhs_3d);
    assert(lhs_3d * rhs_3d == naive_product(lhs_3d, rhs_3d));

    MFPS lhs_1d(std::vector<int>{7}), rhs_1d(std::vector<int>{7});
    fill_test_data(lhs_1d);
    fill_test_data(rhs_1d);
    assert(lhs_1d * rhs_1d == naive_product(lhs_1d, rhs_1d));
}

void test_arbitrary_modulus_inverse() {
    using MFPS = kk2::MultivariateFormalPowerSeriesArbitrary<kk2::mont107>;
    MFPS f(std::vector<int>{3, 4});
    fill_test_data(f);
    f[0] = 3;
    MFPS product = f * f.inv();
    assert(product[0] == 1);
    for (int i = 1; i < product.size(); ++i) assert(product[i] == 0);
}

void test_sparse_inplace_alias() {
    using MFPS = kk2::MultivariateFormalPowerSeries<kk2::mont998>;
    MFPS f(std::vector<int>{4, 5});
    fill_test_data(f);
    const MFPS expected = naive_product(f, f);
    kk2::inplace_multi_convolution_truncated_sparse(f.f, f.f, f.base);
    assert(f == expected);
}

int main() {
    test_ntt_friendly_product();
    test_arbitrary_modulus_product();
    test_arbitrary_modulus_inverse();
    test_sparse_inplace_alias();
}

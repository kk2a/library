// competitive-verifier: STANDALONE

#include <cassert>
#include <vector>

#include "../../../convolution/convolution_int.hpp"

int main() {
    using Vector = std::vector<long long>;
    const Vector lhs{1, 0, 2, 0, 3};
    const Vector rhs{4, 0, 5};
    const Vector expected{4, 0, 13, 0, 22, 0, 15};

    assert(kk2::dense_convolution_int(lhs, rhs) == expected);
    assert(kk2::sparse_convolution_int(lhs, rhs) == expected);
    assert(kk2::convolution_int(lhs, rhs) == expected);
    assert(lhs == Vector({1, 0, 2, 0, 3}));

    Vector inplace_dense = lhs;
    Vector &dense_reference = kk2::inplace_dense_convolution_int(inplace_dense, rhs);
    assert(&dense_reference == &inplace_dense);
    assert(inplace_dense == expected);

    Vector inplace_sparse = lhs;
    Vector &sparse_reference = kk2::inplace_sparse_convolution_int(inplace_sparse, rhs);
    assert(&sparse_reference == &inplace_sparse);
    assert(inplace_sparse == expected);

    Vector inplace_automatic = lhs;
    Vector &automatic_reference = kk2::inplace_convolution_int(inplace_automatic, rhs);
    assert(&automatic_reference == &inplace_automatic);
    assert(inplace_automatic == expected);
}

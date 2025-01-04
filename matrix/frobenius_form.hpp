#ifndef KK2_MATRIX_FROBENIUS_FORM_HPP
#define KK2_MATRIX_FROBENIUS_FORM_HPP 1

#include <vector>

#include "basis.hpp"

namespace kk2 {

namespace linear_algebra {

template <class Matrix, class Poly, class Field>
struct FrobeniusForm_base {
    Matrix mat;
    std::vector<int> deg;
    std::vector<Poly> poly;

    // mat = P_inv frobenius P
    // P_inv = P^{-1}
    Matrix frobenius, P, P_inv;

    FrobeniusForm_base(const Matrix &mat_) : mat(mat_) {
        int n = mat.get_h();
        assert(n == mat.get_w());
        frobenius = P = Matrix(n, n);
        build();
    }

    void build() {
        int n = mat.get_h();
        Basis_base<Matrix, Field> basis;
        // 乱択で頑張る
    }
};

}

} // namespace kk2

#endif // KK2_MATRIX_FROBENIUS_FORM_HPP

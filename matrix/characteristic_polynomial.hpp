#ifndef KK2_MATRIX_CHARACTERISTIC_POLYNOMIAL_HPP
#define KK2_MATRIX_CHARACTERISTIC_POLYNOMIAL_HPP 1

#include <cassert>
#include <utility>
#include <vector>

namespace kk2 {

template <class Poly, class Matrix, class Field = typename Matrix::value_type>
Poly characteristic_polynomial(const Matrix &mat) {
    assert(mat.get_h() == mat.get_w());
    if (mat.get_h() == 0) return Poly{1};
    if (mat.get_h() == 1) return Poly{-mat[0][0], 1};
    int n = mat.get_h();
    Matrix tmp(mat);
    tmp.to_upper_Hessenberg();
    std::vector<Poly> p(n + 1);
    p[0] = Poly{1}, p[1] = Poly{-tmp[0][0], 1};
    for (int i = 2; i <= n; ++i) {
        p[i].resize(i + 1);
        p[i][i] = Field(1), p[i][0] = -tmp[i - 1][i - 1] * p[i - 1][0];
        for (int j = 1; j < i; ++j) p[i][j] = -p[i - 1][j] * tmp[i - 1][i - 1] + p[i - 1][j - 1];
        for (int j = i - 2; j >= 0; --j) {
            if (tmp[j + 1][j] == Field(0)) break;
            if (tmp[j][i - 1] == Field(0)) continue;
            p[i] -= p[j] * tmp[j][i - 1];
        }
    }
    return p[n];
}

} // namespace kk2

#endif // KK2_MATRIX_CHARACTERISTIC_POLYNOMIAL_HPP

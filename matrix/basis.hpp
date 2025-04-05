#ifndef KK2_MATRIX_BASIS_HPP
#define KK2_MATRIX_BASIS_HPP 1

#include <algorithm>
#include <cassert>
#include <optional>
#include <vector>

#include "matrix_field.hpp"

namespace kk2 {

namespace linear_algebra {

template <class Matrix, class Field> struct Basis_base {
    struct RowBasicTransform {
        int type;
        int i, j;
        Field t, t_inv;

        RowBasicTransform() = default;

        // type = 0: row(i) <- row(i) * t
        //           t_inv = 1 / t
        // type = 1: row(j) <- row(j) + row(i) * t
        //           t_inv = -t
        // type = 2: swap(row(i), row(j))
        //           t_inv = unused
        RowBasicTransform(int type_, int i_, int j_, Field t_, Field t_inv_)
            : type(type_),
              i(i_),
              j(j_),
              t(t_),
              t_inv(t_inv_) {}

        void transform(Matrix &mat, bool inv = false) const {
            if (type == 0) {
                if (inv) {
                    mat[i][0] *= t_inv;
                } else {
                    mat[i][0] *= t;
                }
            } else if (type == 1) {
                if (inv) {
                    mat[j][0] += mat[i][0] * t_inv;
                } else {
                    mat[j][0] += mat[i][0] * t;
                }
            } else if (type == 2) {
                std::swap(mat[i], mat[j]);
            }
        }
    };

    int h, rank;

    struct SnapShot {
        int rank, hist_size;
    };

    std::vector<RowBasicTransform> hist;
    std::vector<SnapShot> snaps;

    BasisField() = default;

    BasisField(int h_) : h(h_), rank(0) {}

    Matrix &sweep(Matrix &vec) const {
        for (auto &&t : hist) t.transform(vec);
        return vec;
    }

    // vec is column vector
    bool is_linearly_independent(const Matrix &vec) const {
        assert(vec.get_h() == h);
        assert(vec.get_w() == 1);
        if (rank == h) return false;

        Matrix tmp(vec);
        sweep(tmp);
        for (int i = rank; i < h; ++i) {
            if (tmp[i][0] != Field(0)) return true;
        }
        return false;
    }

    // vec is column vector
    // if vec is not linearly independent with current basis, return coordinate vector
    // else return std::nullopt
    std::optional<Matrix> add(const Matrix &vec) {
        assert(vec.get_h() == h);
        assert(vec.get_w() == 1);

        Matrix tmp(vec);
        sweep(tmp);

        int pivot = -1;
        for (int i = rank; i < h; ++i) {
            if (tmp[i][0] != Field(0)) {
                pivot = i;
                break;
            }
        }
        if (pivot == -1) return tmp;

        if (pivot != rank) {
            std::swap(tmp[pivot], tmp[rank]);
            hist.emplace_back(2, rank, pivot, Field(1), Field(1));
        }
        if (tmp[rank][0] != Field(1)) {
            hist.emplace_back(0, rank, -1, tmp[rank][0].inv(), tmp[rank][0]);
            tmp[rank][0] = Field(1);
        }
        for (int i = 0; i < h; ++i) {
            if (i == rank) continue;
            Field t = -tmp[i][0];
            if (t == Field(0)) continue;
            hist.emplace_back(1, rank, i, t, -t);
        }
        ++rank;
        return {};
    }

    Matrix get_coordinate(const Matrix &vec) const {
        assert(vec.get_h() == h);
        assert(vec.get_w() == 1);
        Matrix tmp(vec);
        sweep(tmp);
        for (int i = rank; i < h; ++i) assert(tmp[i][0] == Field(0));
        return res;
    }

    void snapshot() { snaps.emplace_back(rank, (int)hist.size()); }

    void rollback() {
        if (snaps.empty()) return;
        auto snap = snaps.back();
        snaps.pop_back();
        rank = snap.rank;
        hist.resize(snap.hist_size);
    }
};

} // namespace linear_algebra

template <class Matrix> using BasisMatrix =
    linear_algebra::Basis_base<Matrix, typename Matrix::value_type>;

} // namespace kk2

#endif // KK2_MATRIX_BASIS_HPP

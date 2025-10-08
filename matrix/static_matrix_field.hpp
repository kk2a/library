#ifndef KK2_MATRIX_STATIC_MATRIX_FIELD_HPP
#define KK2_MATRIX_STATIC_MATRIX_FIELD_HPP 1

#include <array>
#include <cassert>

#include "../type_traits/io.hpp"

namespace kk2 {


/**
 * @brief 形がコンパイル時に決まっている行列
 *
 *
 * @tparam H
 * @tparam W
 * @tparam Field invメンバが必要
 */
template <int _H, int _W, class Field> struct StaticMatrixFiled {
    using value_type = Field;
    using mat = StaticMatrixFiled;
    static constexpr int _h = _H, _w = _W;
    std::array<std::array<Field, _W>, _H> _mat;
    StaticMatrixFiled() { _mat.fill(std::array<Field, _W>()); }
    StaticMatrixFiled(const std::array<std::array<Field, _W>, _H> &mat_) : _mat(mat_) {}

    inline int get_h() const { return _h; }
    inline int get_w() const { return _w; }

    std::array<Field, _W> &operator[](int i) {
        assert(0 <= i && i < _h);
        return _mat[i];
    }
    const std::array<Field, _W> &operator[](int i) const {
        assert(0 <= i && i < _h);
        return _mat[i];
    }

    static mat unit() {
        static_assert(_h == _w, "unit matrix must be square");
        mat res;
        for (int i = 0; i < _h; i++) res[i][i] = Field(1);
        return res;
    }

    template <class IStream, is_istream_t<IStream> * = nullptr> mat &input(IStream &is) {
        for (int i = 0; i < _h; i++) {
            for (int j = 0; j < _w; j++) { is >> _mat[i][j]; }
        }
        return *this;
    }

    template <class OStream, is_ostream_t<OStream> * = nullptr> void output(OStream &os) const {
        for (int i = 0; i < _h; i++) {
            for (int j = 0; j < _w; j++) os << _mat[i][j] << " \n"[j + 1 == _w];
        }
    }

    template <class OStream, is_ostream_t<OStream> * = nullptr>
    void debug_output(OStream &os) const {
        os << "(h, w): " << "(" << _h << ", " << _w << "), [\n";
        for (int i = 0; i < _h; i++) {
            os << "  [ ";
            for (int j = 0; j < _w; j++) os << _mat[i][j] << " ";
            os << "]\n";
        }
        os << "]\n";
    }

    mat &operator+=(const mat &rhs) {
        for (int i = 0; i < _h; i++) {
            for (int j = 0; j < _w; j++) { _mat[i][j] += rhs._mat[i][j]; }
        }
        return *this;
    }

    mat &operator-=(const mat &rhs) {
        for (int i = 0; i < _h; i++) {
            for (int j = 0; j < _w; j++) { _mat[i][j] -= rhs._mat[i][j]; }
        }
        return *this;
    }

    mat &operator*=(const mat &rhs) {
        static_assert(_w == rhs._h, "matrix multiplication dimension mismatch");
        std::array<std::array<Field, rhs._w>, _h> res{};
        for (int i = 0; i < _h; i++) {
            for (int k = 0; k < _w; k++) {
                for (int j = 0; j < rhs._w; j++) { res[i][j] += _mat[i][k] * rhs._mat[k][j]; }
            }
        }
        *this = mat(res);
        return *this;
    }

    /**
     * @brief 掃き出し
     * @tparam RREF 行簡約化行列にするかどうか
     * @tparam EARLY_TERMINATE フルランクでないことが確定したときに即打ち切るかどうか
     * @param wr 列が[0, wr)の範囲だけで掃き出す．指定がないなら全体で掃き出す．
     * @return ランクと行列式を返す．
     */
    template <bool RREF = true, bool EARLY_TERMINATE = false>
    std::pair<int, Field> sweep(int wr = -1) {
        if (wr == -1) wr = _w;
        int r = 0;
        Field det = 1;
        for (int i = 0; i < wr; ++i) {
            if (r >= _h) break;
            int pivot = r;
            while (pivot < _h and _mat[pivot][i] == Field(0)) ++pivot;
            if (pivot == _h) {
                if constexpr (EARLY_TERMINATE) return {-1, Field(0)};
                det = 0;
                continue;
            }
            if (r != pivot) {
                det = -det;
                std::swap(_mat[r], _mat[pivot]);
            }
            det *= _mat[r][i];
            Field inv = _mat[r][i].inv();
            for (int j = i; j < wr; ++j) _mat[r][j] *= inv;
            for (int j = RREF ? 0 : r + 1; j < _h; ++j) {
                if (j == r) continue;
                Field a = _mat[j][i];
                if (a == Field(0)) continue;
                for (int k = i; k < wr; ++k) { _mat[j][k] -= _mat[r][k] * a; }
            }
            r++;
        }
        return {r, det};
    }

    friend mat operator+(const mat &lhs, const mat &rhs) { return mat(lhs) += rhs; }
    friend mat operator-(const mat &lhs, const mat &rhs) { return mat(lhs) -= rhs; }
    friend mat operator*(const mat &lhs, const mat &rhs) { return mat(lhs) *= rhs; }
    friend bool operator==(const mat &lhs, const mat &rhs) { return lhs._mat == rhs._mat; }
    friend bool operator!=(const mat &lhs, const mat &rhs) { return lhs._mat != rhs._mat; }
};

} // namespace kk2

#endif // KK2_MATRIX_STATIC_MATRIX_FIELD_HPP

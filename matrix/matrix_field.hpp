#ifndef KK2_MATRIX_MATRIX_FIELD_HPP
#define KK2_MATRIX_MATRIX_FIELD_HPP 1

#include <algorithm>
#include <cassert>
#include <iostream>
#include <optional>
#include <string>
#include <vector>

#include "../type_traits/io.hpp"

namespace kk2 {

/**
 * @brief 行列
 * 
 * @tparam Field invメンバが必要
 */
template <class Field> struct MatrixField {
    using value_type = Field;
    using mat = MatrixField;
    int _h, _w;
    std::vector<std::vector<Field>> _mat;

    MatrixField() : MatrixField(0) {}
    MatrixField(int n) : MatrixField(n, n) {}

    MatrixField(int h, int w) {
        if (h == 0) {
            _h = 0;
            _w = w;
        } else {
            _h = h;
            _w = w;
            _mat.resize(h, std::vector<Field>(w));
        }
    }

    MatrixField(const std::vector<std::vector<Field>> &mat_)
        : _h(mat_.size()),
          _w(mat_[0].size()),
          _mat(mat_) {}

    static mat unit(int n) {
        mat res(n, n);
        for (int i = 0; i < n; i++) res[i][i] = Field(1);
        return res;
    }

    inline int get_h() const { return _h; }

    inline int get_w() const { return _w; }

    std::vector<Field> &operator[](int i) {
        assert(0 <= i && i < _h);
        return _mat[i];
    }

    const std::vector<Field> &operator[](int i) const {
        assert(0 <= i && i < _h);
        return _mat[i];
    }

    template <class IStream, is_istream_t<IStream> * = nullptr> mat &input(IStream &is) {
        for (int i = 0; i < _h; i++) {
            for (int j = 0; j < _w; j++) { is >> _mat[i][j]; }
        }
        return *this;
    }

    template <class OStream, is_ostream_t<OStream> * = nullptr> void output(OStream &os) const {
        for (int i = 0; i < _h; i++) {
            for (int j = 0; j < _w; j++) os << _mat[i][j] << " \n"[j == _w - 1];
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
        assert(_h == rhs._h);
        assert(_w == rhs._w);
        for (int i = 0; i < _h; i++) {
            for (int j = 0; j < _w; j++) { _mat[i][j] += rhs._mat[i][j]; }
        }
        return *this;
    }

    mat &operator-=(const mat &rhs) {
        assert(_h == rhs._h);
        assert(_w == rhs._w);
        for (int i = 0; i < _h; i++) {
            for (int j = 0; j < _w; j++) { _mat[i][j] -= rhs._mat[i][j]; }
        }
        return *this;
    }

    mat &operator*=(const mat &rhs) {
        assert(_w == rhs._h);
        std::vector<std::vector<Field>> res(_h, std::vector<Field>(rhs._w, Field()));
        for (int i = 0; i < _h; i++) {
            for (int k = 0; k < _w; k++) {
                for (int j = 0; j < rhs._w; j++) { res[i][j] += _mat[i][k] * rhs._mat[k][j]; }
            }
        }
        _w = rhs._w;
        _mat = std::move(res);
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

    mat &to_upper_Hessenberg() {
        assert(_h == _w);
        int n = _h;
        for (int i = 0; i < n - 1; ++i) {
            int pivot = i + 1;
            while (pivot < n and _mat[pivot][i] == Field(0)) ++pivot;
            if (pivot == n) continue;
            if (pivot != i + 1) {
                std::swap(_mat[pivot], _mat[i + 1]);
                for (int j = 0; j < n; ++j) std::swap(_mat[j][i + 1], _mat[j][pivot]);
            }
            if (_mat[i + 1][i] != Field(1)) {
                Field a = _mat[i + 1][i], iv = a.inv();
                for (int j = i; j < n; ++j) _mat[i + 1][j] *= iv;
                for (int j = 0; j < n; ++j) _mat[j][i + 1] *= a;
            }
            for (int j = i + 2; j < n; ++j) {
                Field a = _mat[j][i];
                if (a == Field(0)) continue;
                for (int k = i; k < n; ++k) _mat[j][k] -= _mat[i + 1][k] * a;
                for (int k = 0; k < n; ++k) _mat[k][i + 1] += _mat[k][j] * a;
            }
        }
        return *this;
    }

    Field det() const {
        assert(_h == _w);
        return mat(*this).sweep<false, true>().second;
    }

    std::optional<mat> inv() const {
        assert(_h == _w);
        int n = _h;
        mat res(*this);
        res.inplace_combine_right(mat::unit(n));
        int r = res.sweep<true, true>().first;
        if (r != n) return std::nullopt;
        for (int i = 0; i < n; i++) res._mat[i].erase(res[i].begin(), res[i].begin() + n);
        res._w = n;
        return res;
    }

    int rank() const { return mat(*this).sweep<false, false>().first; }

    mat &shrink() {
        while (_h and _mat.back() == std::vector<Field>(_w, Field())) _mat.pop_back(), _h--;
        return *this;
    }

    template <class T> mat pow(T n) const {
        assert(_h == _w);
        assert(n >= 0);
        mat mul(_mat), res = mat::unit(_h);
        while (n) {
            if (n & 1) res *= mul;
            if (n >>= 1) mul *= mul;
        }
        return res;
    }

    std::optional<mat> solve(const mat &b) const {
        assert(_h == b._h);
        assert(b._w == 1);
        mat ab = combine_right(b);
        int r = ab.sweep<true, false>().first;
        if ([&]() {
                if (!r) return false;
                for (int i = 0; i < _w; i++)
                    if (ab[r - 1][i] != Field()) return false;
                return true;
            }()) {
            return std::nullopt;
        }
        mat res(1 + _w - r, _w);
        std::vector<int> idx(_w, -1), step(r, -1);
        for (int i = 0, j = 0, now = 0; j < _w; j++) {
            if (i == r or ab[i][j] == Field(0)) idx[j] = now, res[1 + now++][j] = 1;
            else res[0][j] = ab[i].back(), step[i++] = j;
        }
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < _w; j++) {
                if (idx[j] != -1) res[idx[j] + 1][step[i]] = -ab[i][j];
            }
        }
        return res;
    }

    mat &inplace_combine_top(const mat &rhs) {
        assert(_w == rhs._w);
        _mat.insert(_mat.begin(), rhs._mat.begin(), rhs._mat.end());
        _h += rhs._h;
        return *this;
    }

    mat &inplace_combine_bottom(const mat &rhs) {
        assert(_w == rhs._w);
        _mat.insert(_mat.end(), rhs._mat.begin(), rhs._mat.end());
        _h += rhs._h;
        return *this;
    }

    mat &inplace_combine_left(const mat &rhs) {
        assert(_h == rhs._h);
        for (int i = 0; i < _h; i++) _mat[i].insert(_mat[i].begin(), rhs[i].begin(), rhs[i].end());
        _w += rhs._w;
        return *this;
    }

    mat &inplace_combine_right(const mat &rhs) {
        assert(_h == rhs._h);
        for (int i = 0; i < _h; i++) _mat[i].insert(_mat[i].end(), rhs[i].begin(), rhs[i].end());
        _w += rhs._w;
        return *this;
    }

    mat transpose() const {
        mat res(_w, _h);
        for (int i = 0; i < _h; i++) {
            for (int j = 0; j < _w; j++) { res[j][i] = _mat[i][j]; }
        }
        return res;
    }

    mat combine_top(const mat &rhs) const { return mat(*this).inplace_combine_top(rhs); }
    mat combine_bottom(const mat &rhs) const { return mat(*this).inplace_combine_bottom(rhs); }
    mat combine_left(const mat &rhs) const { return mat(*this).inplace_combine_left(rhs); }
    mat combine_right(const mat &rhs) const { return mat(*this).inplace_combine_right(rhs); }
    mat &inplace_transpose() { return *this = transpose(); }
    friend mat operator+(const mat &lhs, const mat &rhs) { return mat(lhs) += rhs; }
    friend mat operator-(const mat &lhs, const mat &rhs) { return mat(lhs) -= rhs; }
    friend mat operator*(const mat &lhs, const mat &rhs) { return mat(lhs) *= rhs; }
    friend bool operator==(const mat &lhs, const mat &rhs) { return lhs._mat == rhs._mat; }
    friend bool operator!=(const mat &lhs, const mat &rhs) { return lhs._mat != rhs._mat; }
};

} // namespace kk2

#endif // KK2_MATRIX_MATRIX_FIELD_HPP

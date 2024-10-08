#ifndef MATRIX_MATRIX_FIELD_HPP
#define MATRIX_MATRIX_FIELD_HPP 1

#include <algorithm>
#include <cassert>
#include <iostream>
#include <optional>
#include <string>
#include <vector>

namespace kk2 {

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
            _mat.resize(h, std::vector<Field>(w, Field()));
        }
    }

    MatrixField(const std::vector<std::vector<Field>> &mat_)
        : _h(mat_.size()),
          _w(mat_[0].size()),
          _mat(mat_) {}

    int get_h() const { return _h; }

    int get_w() const { return _w; }

    Field &at(int i, int j) const {
        assert(0 <= i && i < _h);
        assert(0 <= j && j < _w);
        return _mat[i][j];
    }

    std::vector<Field> &operator[](int i) {
        assert(0 <= i && i < _h);
        return _mat[i];
    }

    void display() const {
        for (int i = 0; i < _h; i++) {
            for (int j = 0; j < _w; j++) std::cout << _mat[i][j] << " \n"[j == _w - 1];
        }
    }

    template <class IStream>
    mat &input(IStream &is) {
        for (int i = 0; i < _h; i++) {
            for (int j = 0; j < _w; j++) { is >> _mat[i][j]; }
        }
        return *this;
    }

    template <class OStream>
    void output(OStream &os) const {
        for (int i = 0; i < _h; i++) {
            for (int j = 0; j < _w; j++) os << _mat[i][j] << " \n"[j == _w - 1];
        }
    }

    void set(int i, int j, Field x) {
        assert(0 <= i && i < _h);
        assert(0 <= j && j < _w);
        _mat[i][j] = x;
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
            for (int j = 0; j < rhs._w; j++) {
                for (int k = 0; k < _w; k++) { res[i][j] += _mat[i][k] * rhs._mat[k][j]; }
            }
        }
        _w = rhs._w;
        _mat.swap(res);
        return *this;
    }

    Field det() const {
        assert(_h == _w);
        int n = _h;
        std::vector<std::vector<Field>> a(_mat);
        Field res = 1;
        for (int i = 0; i < n; i++) {
            int pivot = -1;
            for (int j = i; j < n; j++) {
                if (a[j][i] != Field(0)) {
                    pivot = j;
                    break;
                }
            }
            if (pivot == -1) return Field(0);
            if (i != pivot) {
                std::swap(a[i], a[pivot]);
                res = -res;
            }
            res *= a[i][i];
            Field inv = a[i][i].inv();
            for (int j = i + 1; j < n; j++) { a[i][j] *= inv; }
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                Field r = a[j][i];
                for (int k = i; k < n; k++) { a[j][k] -= a[i][k] * r; }
            }
        }
        return res;
    }

    std::optional<mat> inv() const {
        assert(_h == _w);
        int n = _h;
        std::vector<std::vector<Field>> res(n, std::vector<Field>(n, Field()));
        for (int i = 0; i < n; i++) res[i][i] = 1;
        mat a(_mat);
        for (int i = 0; i < n; i++) {
            int pivot = -1;
            for (int j = i; j < n; j++) {
                if (a._mat[j][i] != Field(0)) {
                    pivot = j;
                    break;
                }
            }
            if (pivot == -1) { return {}; }
            std::swap(a._mat[i], a._mat[pivot]);
            std::swap(res[i], res[pivot]);
            Field inv = a._mat[i][i].inv();
            for (int j = 0; j < n; j++) {
                a._mat[i][j] *= inv;
                res[i][j] *= inv;
            }
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                Field r = a._mat[j][i];
                for (int k = 0; k < n; k++) {
                    a._mat[j][k] -= a._mat[i][k] * r;
                    res[j][k] -= res[i][k] * r;
                }
            }
        }
        return mat(res);
    }

    int rank() const {
        int n = _h, m = _w;
        std::vector<std::vector<Field>> a(_mat);
        int res = 0;
        for (int i = 0; i < m; i++) {
            int pivot = -1;
            for (int j = res; j < n; j++) {
                if (a[j][i] != 0) {
                    pivot = j;
                    break;
                }
            }
            if (pivot == -1) continue;
            std::swap(a[res], a[pivot]);
            Field inv = a[res][i].inv();
            for (int j = i; j < m; j++) { a[res][j] *= inv; }
            for (int j = res + 1; j < n; j++) {
                Field r = a[j][i];
                for (int k = i; k < m; k++) { a[j][k] -= a[res][k] * r; }
            }
            res++;
        }
        return res;
    }

    // [0, wr)
    int sweep(int wr = -1) {
        if (wr == -1) wr = _w;
        int r = 0;
        for (int i = 0; i < wr; ++i) {
            int pivot = -1;
            for (int j = r; j < _h; ++j) {
                if (_mat[j][i] != Field(0)) {
                    pivot = j;
                    break;
                }
            }

            if (pivot == -1) continue;
            if (r != pivot) std::swap(_mat[r], _mat[pivot]);
            Field inv = _mat[r][i].inv();
            for (int j = 0; j < wr; ++j) { _mat[r][j] *= inv; }
            for (int j = 0; j < _h; ++j) {
                if (j == r) continue;
                Field a = _mat[j][i];
                if (a == Field(0)) continue;
                for (int k = 0; k < wr; ++k) { _mat[j][k] -= _mat[r][k] * a; }
            }
            r++;
        }
        return r;
    }

    mat &shrink() {
        while (_h and _mat.back() == std::vector<Field>(_w, Field())) {
            _mat.pop_back();
            _h--;
        }
        return *this;
    }

    template <class T> mat pow(T n) const {
        assert(_h == _w);
        mat mul(_mat);
        mat res(_h);
        for (int i = 0; i < _h; i++) res._mat[i][i] = 1;
        while (n) {
            if (n & 1) res *= mul;
            mul *= mul;
            n >>= 1;
        }
        return res;
    }

    mat solve(const mat &b) const {
        assert(_h == b._h);
        assert(b._w == 1);
        mat ab = combine_right(b);
        ab.sweep();
        ab.shrink();

        for (int i = 0; i < ab._h; ++i) {
            for (int j = 0; j < ab._w; ++j) {
                if (ab[i][j] != Field(0)) {
                    if (j == ab._w - 1) return mat();
                    break;
                }
            }
        }

        mat res(1 + _w - ab._h, _w);
        for (int i = 0; i < ab._h; ++i) {
            for (int j = 0; j < ab._w; ++j) {
                if (ab[i][j] != Field(0)) {
                    res[0][j] = ab[i][ab._w - 1];
                    break;
                }
            }
        }

        std::vector<int> step(ab._h);
        std::vector<bool> is_step(ab._w - 1, false);
        int nowj = 0;
        for (int i = 0; i < ab._h; i++) {
            while (ab[i][nowj] == Field(0)) nowj++;
            is_step[nowj] = true;
            step[i] = nowj;
        }
        int now = 1;
        nowj = 0;
        while (nowj < ab._w - 1) {
            if (is_step[nowj]) {
                nowj++;
                continue;
            }
            res[now][nowj] = 1;
            for (int i = 0; i < ab._h; i++)
                if (ab[i][nowj] != Field(0)) res[now][step[i]] = -ab[i][nowj];
            nowj++, now++;
        }
        return res;
    }

    mat &inplace_combine_top(const mat &rhs) {
        assert(_w == rhs._w);
        _mat.insert(_mat.begin(), rhs._mat.begin(), rhs._mat.end());
        _h += rhs._h;
        return *this;
    }

    mat combine_top(const mat &rhs) const { return mat(*this).inplace_combine_top(rhs); }

    mat &inplace_combine_bottom(const mat &rhs) {
        assert(_w == rhs._w);
        _mat.insert(_mat.end(), rhs._mat.begin(), rhs._mat.end());
        _h += rhs._h;
        return *this;
    }

    mat combine_bottom(const mat &rhs) const { return mat(*this).inplace_combine_bottom(rhs); }

    mat &inplace_combine_left(const mat &rhs) {
        assert(_h == rhs._h);
        for (int i = 0; i < _h; i++) {
            _mat[i].insert(_mat[i].begin(), rhs._mat[i].begin(), rhs._mat[i].end());
        }
        _w += rhs._w;
        return *this;
    }

    mat combine_left(const mat &rhs) const { return mat(*this).inplace_combine_left(rhs); }

    mat &inplace_combine_right(const mat &rhs) {
        assert(_h == rhs._h);
        for (int i = 0; i < _h; i++) {
            _mat[i].insert(_mat[i].end(), rhs._mat[i].begin(), rhs._mat[i].end());
        }
        _w += rhs._w;
        return *this;
    }

    mat combine_right(const mat &rhs) const { return mat(*this).inplace_combine_right(rhs); }

    mat &inplace_transpose() {
        std::vector<std::vector<Field>> res(_w, std::vector<Field>(_h));
        for (int i = 0; i < _h; i++) {
            for (int j = 0; j < _w; j++) { res[j][i] = _mat[i][j]; }
        }
        _mat.swap(res);
        std::swap(_h, _w);
        return *this;
    }

    mat transpose() const { return mat(*this).inplace_transpose(); }

    friend mat operator+(const mat &lhs, const mat &rhs) { return mat(lhs) += rhs; }

    friend mat operator-(const mat &lhs, const mat &rhs) { return mat(lhs) -= rhs; }

    friend mat operator*(const mat &lhs, const mat &rhs) { return mat(lhs) *= rhs; }

    friend bool operator==(const mat &lhs, const mat &rhs) { return lhs._mat == rhs._mat; }

    friend bool operator!=(const mat &lhs, const mat &rhs) { return lhs._mat != rhs._mat; }
};

} // namespace kk2

#endif // MATRIX_MATRIX_FIELD_HPP

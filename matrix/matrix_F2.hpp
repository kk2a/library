#ifndef KK2_MATRIX_MATRIX_F2_HPP
#define KK2_MATRIX_MATRIX_F2_HPP 1

#include <algorithm>
#include <cassert>
#include <iostream>
#include <optional>
#include <string>
#include <vector>

#include "../data_structure/my_bitset.hpp"
#include "../type_traits/type_traits.hpp"

namespace kk2 {

struct MatrixF2 {
    using mat = MatrixF2;
    int _h, _w;
    std::vector<DynamicBitSet> _mat;

    MatrixF2() : MatrixF2(0) {}

    MatrixF2(int n) : MatrixF2(n, n) {}

    MatrixF2(int h, int w) {
        if (h == 0) {
            _h = 0;
            _w = w;
        } else {
            _h = h;
            _w = w;
            _mat.resize(h, DynamicBitSet(w));
        }
    }

    MatrixF2(const std::vector<DynamicBitSet> &mat_)
        : _h(mat_.size()),
          _w(mat_[0].size()),
          _mat(mat_) {}

    int get_h() const { return _h; }

    int get_w() const { return _w; }

    bool at(int i, int j) {
        assert(0 <= i && i < _h);
        assert(0 <= j && j < _w);
        return _mat[i][j].val();
    }

    class Proxy {
        std::vector<DynamicBitSet> &bs;
        int i;

      public:
        Proxy(std::vector<DynamicBitSet> &bs_, int i_) : bs(bs_), i(i_) {}

        operator DynamicBitSet() const { return bs[i]; }

        template <class IStream, is_istream_t<IStream> * = nullptr>
        friend IStream &operator>>(IStream &is, Proxy p) {
            std::string s;
            is >> s;
            p = s;
            return is;
        }

        template <class OStream, is_ostream_t<OStream> * = nullptr>
        friend OStream &operator<<(OStream &os, Proxy p) {
            os << p.to_reversed_string();
            return os;
        }

        std::string to_string() const { return bs[i].to_string(); }

        std::string to_reversed_string() const { return bs[i].to_reversed_string(); }

        Proxy &operator=(const std::string &s) {
            bs[i].set_reversed(s);
            return *this;
        }

        Proxy &operator=(const DynamicBitSet &x) {
            bs[i] = x;
            return *this;
        }

        Proxy &operator=(const Proxy &x) {
            bs[i] = x.bs[x.i];
            return *this;
        }

        DynamicBitSet::BitReference operator[](int j) {
            assert(0 <= j && j < (int)bs[i].size());
            return bs[i][j];
        }

        Proxy &operator&=(const DynamicBitSet &x) {
            bs[i] &= x;
            return *this;
        }

        Proxy &operator&=(const Proxy &x) {
            bs[i] &= x.bs[x.i];
            return *this;
        }

        Proxy &operator|=(const DynamicBitSet &x) {
            bs[i] |= x;
            return *this;
        }

        Proxy &operator|=(const Proxy &x) {
            bs[i] |= x.bs[x.i];
            return *this;
        }

        Proxy &operator^=(const DynamicBitSet &x) {
            bs[i] ^= x;
            return *this;
        }

        Proxy &operator^=(const Proxy &x) {
            bs[i] ^= x.bs[x.i];
            return *this;
        }

        Proxy &flip() {
            bs[i].flip();
            return *this;
        }

        Proxy &operator~() {
            bs[i].flip();
            return *this;
        }
    };

    Proxy operator[](int i) {
        assert(0 <= i && i < _h);
        return Proxy(_mat, i);
    }

    template <class IStream, is_istream_t<IStream> * = nullptr> mat &input(IStream &is) {
        for (int i = 0; i < _h; i++) {
            std::string s;
            is >> s;
            _mat[i].set_reversed(s);
        }
        return *this;
    }

    template <class OStream, is_ostream_t<OStream> * = nullptr> void output(OStream &os) const {
        for (int i = 0; i < _h; i++) { os << _mat[i].to_reversed_string() << "\n"; }
    }

    void set(int i, int j, bool x) {
        assert(0 <= i && i < _h);
        assert(0 <= j && j < _w);
        _mat[i].set(j, x);
    }

    void set(int i, const std::string &s) {
        assert((int)s.size() == _w);
        _mat[i].set(s);
    }

    void set_reversed(int i, const std::string &s) {
        assert((int)s.size() == _w);
        _mat[i].set_reversed(s);
    }

    mat &operator+=(const mat &rhs) {
        assert(_h == rhs._h);
        assert(_w == rhs._w);
        for (int i = 0; i < _h; i++) { _mat[i] = _mat[i] ^ rhs._mat[i]; }
        return *this;
    }

    mat &operator-=(const mat &rhs) {
        assert(_h == rhs._h);
        assert(_w == rhs._w);
        for (int i = 0; i < _h; i++) { _mat[i] = _mat[i] ^ rhs._mat[i]; }
        return *this;
    }

    mat &operator^=(const mat &rhs) {
        assert(_h == rhs._h);
        assert(_w == rhs._w);
        for (int i = 0; i < _h; i++) { _mat[i] = _mat[i] ^ rhs._mat[i]; }
        return *this;
    }

    mat &operator|=(const mat &rhs) {
        assert(_h == rhs._h);
        assert(_w == rhs._w);
        for (int i = 0; i < _h; i++) { _mat[i] = _mat[i] | rhs._mat[i]; }
        return *this;
    }

    mat &operator&=(const mat &rhs) {
        assert(_h == rhs._h);
        assert(_w == rhs._w);
        for (int i = 0; i < _h; i++) { _mat[i] = _mat[i] & rhs._mat[i]; }
        return *this;
    }

    mat &operator*=(const mat &rhs) {
        assert(_w == rhs._h);
        std::vector<DynamicBitSet> res(_h, DynamicBitSet(rhs._w));
        for (int i = 0; i < _h; i++) {
            for (int j = 0; j < _w; j++) {
                if (_mat[i][j]) res[i] ^= rhs._mat[j];
                // cout << i << " " << j << " " << _mat[i][j] << " check" <<
                // endl; rep (i, 2) { cout << res[i] << endl; }
            }
        }
        _w = rhs._w;
        _mat = res;
        return *this;
    }

    friend mat operator+(const mat &lhs, const mat &rhs) { return mat(lhs) += rhs; }

    friend mat operator-(const mat &lhs, const mat &rhs) { return mat(lhs) -= rhs; }

    friend mat operator^(const mat &lhs, const mat &rhs) { return mat(lhs) ^= rhs; }

    friend mat operator|(const mat &lhs, const mat &rhs) { return mat(lhs) |= rhs; }

    friend mat operator&(const mat &lhs, const mat &rhs) { return mat(lhs) &= rhs; }

    friend mat operator*(const mat &lhs, const mat &rhs) { return mat(lhs) *= rhs; }

    friend bool operator==(const mat &lhs, const mat &rhs) {
        assert(lhs._h == rhs._h);
        assert(lhs._w == rhs._w);
        for (int i = 0; i < lhs._h; i++) {
            if (lhs._mat[i] != rhs._mat[i]) return false;
        }
        return true;
    }

    friend bool operator!=(const mat &lhs, const mat &rhs) { return !(lhs == rhs); }

    mat &inplace_combine_top(const mat &rhs) {
        assert(_w == rhs._w);
        _mat.insert(std::begin(_mat), std::begin(rhs._mat), std::end(rhs._mat));
        _h += rhs._h;
        return *this;
    }

    mat combine_top(const mat &rhs) const {
        assert(_w == rhs._w);
        return mat(_mat).inplace_combine_top(rhs);
    }

    mat &inplace_combine_bottom(const mat &rhs) {
        assert(_w == rhs._w);
        _mat.insert(std::end(_mat), std::begin(rhs._mat), std::end(rhs._mat));
        _h += rhs._h;
        return *this;
    }

    mat combine_bottom(const mat &rhs) const {
        assert(_w == rhs._w);
        return mat(_mat).inplace_combine_bottom(rhs);
    }

    mat &inplace_combine_right(const mat &rhs) {
        assert(_h == rhs._h);
        for (int i = 0; i < _h; i++) _mat[i].inplace_combine_top(rhs._mat[i]);
        _w += rhs._w;
        return *this;
    }

    mat combine_right(const mat &rhs) const {
        assert(_h == rhs._h);
        return mat(_mat).inplace_combine_right(rhs);
    }

    mat &inplace_combine_left(const mat &rhs) {
        assert(_h == rhs._h);
        for (int i = 0; i < _h; i++) _mat[i].inplace_combine_bottom(rhs._mat[i]);
        _w += rhs._w;
        return *this;
    }

    mat combine_left(const mat &rhs) const {
        assert(_h == rhs._h);
        return mat(_mat).inplace_combine_left(rhs);
    }

    // [0, wr)
    int sweep(int wr = -1) {
        if (wr == -1) wr = _w;
        int r = 0;
        for (int i = 0; i < wr; i++) {
            int pivot = -1;
            for (int j = r; j < _h; j++) {
                if (_mat[j][i]) {
                    pivot = j;
                    break;
                }
            }
            if (pivot == -1) continue;
            if (r != pivot) std::swap(_mat[r], _mat[pivot]);
            for (int j = 0; j < _h; j++) {
                if (j == r) continue;
                if (_mat[j][i]) _mat[j] ^= _mat[r];
            }
            r++;
        }
        return r;
    }

    mat &shrink() {
        while (_h && !(bool)_mat[_h - 1]) _mat.pop_back(), --_h;
        return *this;
    }

    // it must be already swept and shrunk before calling this function
    mat get_solution_base() const {
        mat res(_w - _h, _w);
        std::vector<int> step(_h);
        std::vector<bool> is_step(_w, false);
        int nowj = 0;
        for (int i = 0; i < _h; i++) {
            while (!_mat[i].is_pinned(nowj)) nowj++;
            is_step[nowj] = true;
            step[i] = nowj;
        }
        int now = 0;
        nowj = 0;
        while (nowj < _w) {
            if (is_step[nowj]) {
                nowj++;
                continue;
            }
            res[now][nowj] = 1;
            for (int i = 0; i < _h; i++)
                if (_mat[i].is_pinned(nowj)) res[now][step[i]] = 1;
            nowj++, now++;
        }
        return res;
    }

    std::optional<mat> solve(const mat &b) const {
        assert(_h == b._h);
        assert(b._w == 1);
        mat ab = combine_right(b);
        ab.sweep();
        ab.shrink();

        // ab.display();

        for (int i = 0; i < ab._h; i++) {
            for (int j = 0; j < ab._w; j++) {
                if (ab[i][j]) {
                    if (j == ab._w - 1) return {};
                    break;
                }
            }
        }

        mat res(1 + _w - ab._h, _w);
        for (int i = 0; i < ab._h; ++i) {
            for (int j = 0; j < ab._w; ++j) {
                if (ab[i][j]) {
                    res[0][j] = ab[i][ab._w - 1];
                    break;
                }
            }
        }

        std::vector<int> step(ab._h);
        std::vector<bool> is_step(ab._w - 1, false);
        int nowj = 0;
        for (int i = 0; i < ab._h; i++) {
            while (!ab[i][nowj]) nowj++;
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
                if (ab[i][nowj]) res[now][step[i]] = 1;
            nowj++, now++;
        }
        return res;
    }

    int rank() const { return mat(*this).sweep(); }

    bool det() const { return rank() == _h; }

    std::optional<mat> inv() const {
        assert(_h == _w);
        std::vector<DynamicBitSet> res(_h, _w);
        for (int i = 0; i < _h; i++) { res[i][i] = 1; }
        std::vector<DynamicBitSet> buf(_mat);
        for (int i = 0; i < _w; i++) {
            int pivot = -1;
            for (int j = i; j < _h; j++) {
                if (buf[j][i]) {
                    pivot = j;
                    break;
                }
            }
            if (pivot == -1) return {};
            std::swap(buf[i], buf[pivot]);
            std::swap(res[i], res[pivot]);
            for (int j = 0; j < _h; j++) {
                if (j == i) continue;
                if (buf[j][i]) {
                    buf[j] ^= buf[i];
                    res[j] ^= res[i];
                }
            }
        }
        return mat(res);
    }

    mat transpose() const {
        mat res(_w, _h);
        for (int i = 0; i < _h; i++) {
            for (int j = 0; j < _w; j++) { res[j][i] = _mat[i][j]; }
        }
        return res;
    }

    mat &inplace_transpose() { return *this = transpose(); }
};

} // namespace kk2

#endif // KK2_MATRIX_MATRIX_F2_HPP

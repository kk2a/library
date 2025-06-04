#ifndef KK2_MATRIX_MATRIX_F2_HPP
#define KK2_MATRIX_MATRIX_F2_HPP 1

#include <algorithm>
#include <cassert>
#include <iostream>
#include <optional>
#include <string>
#include <vector>

#include "../data_structure/my_bitset.hpp"
#include "../type_traits/io.hpp"

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

    static mat unit(int n) {
        mat res(n, n);
        for (int i = 0; i < n; i++) res[i][i] = 1;
        return res;
    }

    inline int get_h() const { return _h; }

    inline int get_w() const { return _w; }

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

    template <class OStream, is_ostream_t<OStream> * = nullptr>
    void debug_output(OStream &os) const {
        os << "(h, w): " << "(" << _h << ", " << _w << "), [\n";
        for (int i = 0; i < _h; i++) {
            os << "  [ ";
            for (int j = 0; j < _w; ++j) os << _mat[i].is_pinned(j) << " ";
            os << "]\n";
        }
        os << "]\n";
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
        for (int i = 0; i < _h; i++) _mat[i] ^= rhs._mat[i];
        return *this;
    }

    mat &operator-=(const mat &rhs) {
        assert(_h == rhs._h);
        assert(_w == rhs._w);
        for (int i = 0; i < _h; i++) _mat[i] ^= rhs._mat[i];
        return *this;
    }

    mat &operator|=(const mat &rhs) {
        assert(_h == rhs._h);
        assert(_w == rhs._w);
        for (int i = 0; i < _h; i++) _mat[i] |= rhs._mat[i];
        return *this;
    }

    mat &operator&=(const mat &rhs) {
        assert(_h == rhs._h);
        assert(_w == rhs._w);
        for (int i = 0; i < _h; i++) _mat[i] &= rhs._mat[i];
        return *this;
    }

    mat &operator*=(const mat &rhs) {
        assert(_w == rhs._h);
        std::vector<DynamicBitSet> res(_h, DynamicBitSet(rhs._w));
        for (int i = 0; i < _h; i++) {
            for (int j = 0; j < _w; j++) {
                if (_mat[i][j]) res[i] ^= rhs._mat[j];
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
     * @return int ランク．EARLY_TERMINATEがtrueのときに，フルランクでないことが確定したら-1を返す
     */
    template <bool RREF = true, bool EARLY_TERMINATE = false>
    int sweep(int wr = -1) {
        if (wr == -1) wr = _w;
        int r = 0;
        for (int i = 0; i < wr; i++) {
            if (r >= _h) break;
            int pivot = -1;
            for (int j = r; j < _h; j++) {
                if (_mat[j][i]) {
                    pivot = j;
                    break;
                }
            }
            if (pivot == -1) {
                if constexpr (EARLY_TERMINATE) return -1;
                continue;
            }
            if (r != pivot) std::swap(_mat[r], _mat[pivot]);
            for (int j = RREF ? 0 : r + 1; j < _h; j++) {
                if (j == r) continue;
                if (_mat[j][i]) _mat[j] ^= _mat[r];
            }
            r++;
        }
        return r;
    }

    mat &shrink() {
        while (_h && !bool(_mat.back())) _mat.pop_back(), --_h;
        return *this;
    }

    std::optional<mat> solve(const mat &b) const {
        assert(_h == b._h);
        assert(b._w == 1);
        mat ab = combine_right(b);
        int r = ab.sweep<true, false>();
        if (r and ab._mat[r - 1].ctz() == _w) return std::nullopt;
        mat res(1 + _w - r, _w);
        std::vector<int> idx(_w, -1), step(r, -1);
        for (int i = 0, j = 0, now = 0; j < _w; j++) {
            if (i == r or !bool(ab[i][j])) idx[j] = now, res[1 + now++][j] = 1;
            else res[0][j] = ab[i][_w], step[i++] = j;
        }
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < _w; j++) {
                if (idx[j] != -1) res[idx[j] + 1][step[i]] = ab[i][j];
            }
        }
        return res;
    }

    int rank() const { return mat(*this).sweep<false, false>(); }

    bool det() const {
        assert(_h == _w);
        return mat(*this).sweep<false, true>() != -1;
    }

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

    mat &inplace_combine_top(const mat &rhs) {
        assert(_w == rhs._w);
        _mat.insert(std::begin(_mat), std::begin(rhs._mat), std::end(rhs._mat));
        _h += rhs._h;
        return *this;
    }

    mat &inplace_combine_bottom(const mat &rhs) {
        assert(_w == rhs._w);
        _mat.insert(std::end(_mat), std::begin(rhs._mat), std::end(rhs._mat));
        _h += rhs._h;
        return *this;
    }

    mat &inplace_combine_right(const mat &rhs) {
        assert(_h == rhs._h);
        for (int i = 0; i < _h; i++) _mat[i].inplace_combine_top(rhs._mat[i]);
        _w += rhs._w;
        return *this;
    }

    mat &inplace_combine_left(const mat &rhs) {
        assert(_h == rhs._h);
        for (int i = 0; i < _h; i++) _mat[i].inplace_combine_bottom(rhs._mat[i]);
        _w += rhs._w;
        return *this;
    }

    mat transpose() {
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
    friend mat operator|(const mat &lhs, const mat &rhs) { return mat(lhs) |= rhs; }
    friend mat operator&(const mat &lhs, const mat &rhs) { return mat(lhs) &= rhs; }
    friend mat operator*(const mat &lhs, const mat &rhs) { return mat(lhs) *= rhs; }
    friend bool operator==(const mat &lhs, const mat &rhs) {
        if (lhs._h != rhs._h) return false;
        if (lhs._w != rhs._w) return false;
        for (int i = 0; i < lhs._h; i++) {
            if (lhs._mat[i] != rhs._mat[i]) return false;
        }
        return true;
    }
    friend bool operator!=(const mat &lhs, const mat &rhs) { return !(lhs == rhs); }
};

} // namespace kk2

#endif // KK2_MATRIX_MATRIX_F2_HPP

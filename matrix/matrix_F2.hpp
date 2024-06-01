#ifndef MATRIX_MATRIX_F2_HPP
#define MATRIX_MATRIX_F2_HPP 1

#include "../data_structure/my_bitset.hpp"

struct MatrixF2 {
    using mat = MatrixF2;
    int _h, _w;
    vector<DynamicBitSet> _mat;

    MatrixF2() : MatrixF2(0) {}
    MatrixF2(int n) : MatrixF2(n, n) {}
    MatrixF2(int h, int w) : MatrixF2(vector<DynamicBitSet>(h, DynamicBitSet(w))) {}
    MatrixF2(const vector<DynamicBitSet>& mat_) : _h(mat_.size()), _w(mat_[0].size()), _mat(mat_) {}
    
    int get_h() const { return _h; }
    int get_w() const { return _w; }
    
    bool at(int i, int j) {
        assert(0 <= i && i < _h);
        assert(0 <= j && j < _w);
        return _mat[i][j].val();
    }

    class Proxy {
        vector<DynamicBitSet>& bs;
        int i;
      public:
        Proxy(vector<DynamicBitSet>& bs_, int i_) : bs(bs_), i(i_) {}
        Proxy& operator=(string s) {
            bs[i] = s;
            return *this;
        }
        Proxy& operator=(DynamicBitSet x) {
            bs[i] = x;
            return *this;
        }
        Proxy& operator=(Proxy x) {
            bs[i] = x.bs[x.i];
            return *this;
        }

        DynamicBitSet::Proxy operator[](int j) {
            assert(0 <= j && j < (int)bs[i].size());
            return bs[i][j];
        }

        Proxy& operator&=(DynamicBitSet x) {
            bs[i] &= x;
            return *this;
        }
        Proxy& operator&=(Proxy x) {
            bs[i] &= x.bs[x.i];
            return *this;
        }

        Proxy& operator|=(DynamicBitSet x) {
            bs[i] |= x;
            return *this;
        }
        Proxy& operator|=(Proxy x) {
            bs[i] |= x.bs[x.i];
            return *this;
        }

        Proxy& operator^=(DynamicBitSet x) {
            bs[i] ^= x;
            return *this;
        }
        Proxy& operator^=(Proxy x) {
            bs[i] ^= x.bs[x.i];
            return *this;
        }

        Proxy& flip() {
            bs[i].flip();
            return *this;
        }
        Proxy& operator~() {
            bs[i].flip();
            return *this;
        }
        Proxy& operator!() {
            bs[i].flip();
            return *this;
        }
    };

    Proxy operator[](int i) {
        assert(0 <= i && i < _h);
        return Proxy(_mat, i);
    }

    void display() const {
        for (int i = 0; i < _h; i++) {
            cout << _mat[i] << "\n";
        }
    }

    void set(int i, int j, bool x) {
        assert(0 <= i && i < _h);
        assert(0 <= j && j < _w);
        _mat[i].set(j, x);
    }

    void set(int i, string s) {
        assert((int)s.size() == _w);
        _mat[i].set(s);
    }

    mat& operator+=(const mat& rhs) {
        assert(_h == rhs._h);
        assert(_w == rhs._w);
        for (int i = 0; i < _h; i++) {
            _mat[i] = _mat[i] ^ rhs._mat[i];
        }
        return *this;
    }

    mat& operator-=(const mat& rhs) {
        assert(_h == rhs._h);
        assert(_w == rhs._w);
        for (int i = 0; i < _h; i++) {
            _mat[i] = _mat[i] ^ rhs._mat[i];
        }
        return *this;
    }

    mat& operator^=(const mat& rhs) {
        assert(_h == rhs._h);
        assert(_w == rhs._w);
        for (int i = 0; i < _h; i++) {
            _mat[i] = _mat[i] ^ rhs._mat[i];
        }
        return *this;
    }

    mat& operator|=(const mat& rhs) {
        assert(_h == rhs._h);
        assert(_w == rhs._w);
        for (int i = 0; i < _h; i++) {
            _mat[i] = _mat[i] | rhs._mat[i];
        }
        return *this;
    }

    mat& operator&=(const mat& rhs) {
        assert(_h == rhs._h);
        assert(_w == rhs._w);
        for (int i = 0; i < _h; i++) {
            _mat[i] = _mat[i] & rhs._mat[i];
        }
        return *this;
    }

    mat& operator*=(const mat& rhs) {
        assert(_w == rhs._h);
        vector<DynamicBitSet> res(_h, DynamicBitSet(rhs._w));
        for (int i = 0; i < _h; i++) {
            for (int j = 0; j < _w; j++) {
                if (_mat[i][j]) res[i] ^= rhs._mat[j];
                // cout << i << " " << j << " " << _mat[i][j] << " check" << endl;
                // rep (i, 2) { cout << res[i] << endl; }
            }
        }
        _w = rhs._w;
        _mat = res;
        return *this;
    }

    friend mat operator+(const mat& lhs, const mat& rhs) { return mat(lhs) += rhs; }
    friend mat operator-(const mat& lhs, const mat& rhs) { return mat(lhs) -= rhs; }
    friend mat operator^(const mat& lhs, const mat& rhs) { return mat(lhs) ^= rhs; }
    friend mat operator|(const mat& lhs, const mat& rhs) { return mat(lhs) |= rhs; }
    friend mat operator&(const mat& lhs, const mat& rhs) { return mat(lhs) &= rhs; }
    friend mat operator*(const mat& lhs, const mat& rhs) { return mat(lhs) *= rhs; }
    friend bool operator==(const mat& lhs, const mat& rhs) {
        assert(lhs._h == rhs._h);
        assert(lhs._w == rhs._w);
        for (int i = 0; i < lhs._h; i++) {
            if (lhs._mat[i] != rhs._mat[i]) return false;
        }
        return true;
    }
    friend bool operator!=(const mat& lhs, const mat& rhs) {
        return !(lhs == rhs);
    }

    mat& inplace_combine_top(const mat& rhs) {
        assert(_w == rhs._w);
        _mat.insert(begin(_mat), begin(rhs._mat), end(rhs._mat));
        _h += rhs._h;
        return *this;
    }

    mat combine_top(const mat& rhs) const {
        assert(_w == rhs._w);
        mat res(_mat);
        return res.inplace_combine_top(rhs);
    }

    mat& inplace_combine_bottom(const mat& rhs) {
        assert(_w == rhs._w);
        _mat.insert(end(_mat), begin(rhs._mat), end(rhs._mat));
        _h += rhs._h;
        return *this;
    }

    mat combine_bottom(const mat& rhs) const {
        assert(_w == rhs._w);
        mat res(_mat);
        return res.inplace_combine_bottom(rhs);
    }

    int rank() const {
        vector<DynamicBitSet> buf(_mat);
        int res = 0;
        for (int i = 0; i < _w; i++) {
            int pivot = -1;
            for (int j = res; j < _h; j++) {
                if (buf[j][i]) {
                    pivot = j;
                    break;
                }
            }
            if (pivot == -1) continue;
            swap(buf[res], buf[pivot]);
            for (int j = 0; j < _h; j++) {
                if (j == res) continue;
                if (buf[j][i]) buf[j] ^= buf[res];
            }
            res++;
        }
        return res;
    }

    bool det() const {
        return rank() == _h;
    }

    mat inv() const {
        assert(_h == _w);
        vector<DynamicBitSet> res(_h, _w);
        for (int i = 0; i < _h; i++) {
            res[i][i] = 1;
        }
        vector<DynamicBitSet> buf(_mat);
        for (int i = 0; i < _w; i++) {
            int pivot = -1;
            for (int j = i; j < _h; j++) {
                if (buf[j][i]) {
                    pivot = j;
                    break;
                }
            }
            if (pivot == -1) continue;
            swap(buf[i], buf[pivot]);
            swap(res[i], res[pivot]);
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
};

#endif // MATRIX_MATRIX_F2_HPP

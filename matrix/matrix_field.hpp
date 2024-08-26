#ifndef MATRIX_HPP
#define MATRIX_HPP 1

namespace kk2 {

template <class Field>
struct MatrixField {
    using mat = MatrixField;
    MatrixField() : MatrixField(0) {}
    MatrixField(int n) : MatrixField(n, n) {}
    MatrixField(int h, int w) : MatrixField(vector<vector<Field>>(h, vector<Field>(w, Field()))) {}
    MatrixField(const vector<vector<Field>>& mat_) : _h(mat_.size()), _w(mat_[0].size()), _mat(mat_) {}
    
    int get_h() const { return _h; }
    int get_w() const { return _w; }

    Field at(int i, int j) const {
        assert(0 <= i && i < _h);
        assert(0 <= j && j < _w);
        return _mat[i][j];
    }

    vector<vector<Field>> get_mat() const {
        return _mat;
    }

    vector<Field>& operator[](int i) {
        assert(0 <= i && i < _h);
        return _mat[i];
    }

    void display() const {
        for (int i = 0; i < _h; i++) {
            for (int j = 0; j < _w; j++) cout << _mat[i][j] << " ";
            cout << "\n";
        }
    }

    void set(int i, int j, Field x) {
        assert(0 <= i && i < _h);
        assert(0 <= j && j < _w);
        _mat[i][j] = x;
    }

    mat& operator+=(const mat& rhs) {
        assert(_h == rhs._h);
        assert(_w == rhs._w);
        for (int i = 0; i < _h; i++) {
            for (int j = 0; j < _w; j++) {
                _mat[i][j] += rhs._mat[i][j];
            }
        }
        return *this;
    }
    mat& operator-=(const mat& rhs) {
        assert(_h == rhs._h);
        assert(_w == rhs._w);
        for (int i = 0; i < _h; i++) {
            for (int j = 0; j < _w; j++) {
                _mat[i][j] -= rhs._mat[i][j];
            }
        }
        return *this;
    }
    mat& operator*=(const mat& rhs) {
        assert(_w == rhs._h);
        vector<vector<Field>> res(_h, vector<Field>(rhs._w, Field()));
        for (int i = 0; i < _h; i++) {
            for (int j = 0; j < rhs._w; j++) {
                for (int k = 0; k < _w; k++) {
                    res[i][j] += _mat[i][k] * rhs._mat[k][j];
                }
            }
        }
        _w = rhs._w;
        _mat.swap(res);
        return *this;
    }

    Field det(Field product_e = Field(1)) const {
        assert(_h == _w);
        int n = _h;
        vector<vector<Field>> a(_mat);
        Field res = 1;
        for (int i = 0; i < n; i++) {
            int pivot = -1;
            for (int j = i; j < n; j++) {
                if (a[j][i] != 0) {
                    pivot = j;
                    break;
                }
            }
            if (pivot == -1) return Field(0);
            if (i != pivot) {
                swap(a[i], a[pivot]);
                res = -res;
            }
            res *= a[i][i];
            Field inv = product_e / a[i][i];
            for (int j = i + 1; j < n; j++) {
                a[i][j] *= inv;
            }
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                Field r = a[j][i];
                for (int k = i; k < n; k++) {
                    a[j][k] -= a[i][k] * r;
                }
            }
        }
        return res;
    }

    mat inv(Field product_e = Field(1)) const {
        assert(_h == _w);
        int n = _h;
        vector<vector<Field>> res(n, vector<Field>(n, Field()));
        for (int i = 0; i < n; i++) res[i][i] = 1;
        mat a(_mat);
        for (int i = 0; i < n; i++) {
            int pivot = -1;
            for (int j = i; j < n; j++) {
                if (a._mat[j][i] != 0) {
                    pivot = j;
                    break;
                }
            }
            if (pivot == -1) {
                return mat(n);
            }
            swap(a._mat[i], a._mat[pivot]);
            swap(res[i], res[pivot]);
            Field inv = product_e / a._mat[i][i];
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

    template <class T>
    mat pow(T n) const {
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

    int rank(Field product_e = Field(1)) const {
        int n = _h, m = _w;
        vector<vector<Field>> a(_mat);
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
            swap(a[res], a[pivot]);
            Field inv = product_e / a[res][i];
            for (int j = i; j < m; j++) {
                a[res][j] *= inv;
            }
            for (int j = res + 1; j < n; j++) {
                Field r = a[j][i];
                for (int k = i; k < m; k++) {
                    a[j][k] -= a[res][k] * r;
                }
            }
            res++;
        }
        return res;
    }

    mat& inplace_combine_top(const mat& rhs) {
        assert(_w == rhs._w);
        this->_mat.insert(begin(this->_mat),
            begin(rhs._mat), end(rhs._mat));
        this->_h += rhs._h;
        return *this;
    }

    mat combine_top(const mat& rhs) const {
        assert(_w == rhs._w);
        mat res(this->_mat);
        return res.inplace_combine_top(rhs);
    }

    mat& inplace_combine_bottom(const mat& rhs) {
        assert(_w == rhs._w);
        this->_mat.insert(end(this->_mat),
            begin(rhs._mat), end(rhs._mat));
        this->_h += rhs._h;
        return *this;
    }

    mat combine_bottom(const mat& rhs) const {
        assert(_w == rhs._w);
        mat res(this->_mat);
        return res.inplace_combine_bottom(rhs);
    }

    mat& inplace_combine_left(const mat& rhs) {
        assert(_h == rhs._h);
        for (int i = 0; i < _h; i++) {
            this->_mat[i].insert(begin(this->_mat[i]),
                begin(rhs._mat[i]), end(rhs._mat[i]));
        }
        this->_w += rhs._w;
        return *this;
    }

    mat combine_left(const mat& rhs) const {
        assert(_h == rhs._h);
        mat res(this->_mat);
        return res.inplace_combine_left(rhs);
    }

    mat& inplace_combine_right(const mat& rhs) {
        assert(_h == rhs._h);
        for (int i = 0; i < _h; i++) {
            this->_mat[i].insert(end(this->_mat[i]),
                begin(rhs._mat[i]), end(rhs._mat[i]));
        }
        this->_w += rhs._w;
        return *this;
    }

    mat combine_right(const mat& rhs) const {
        assert(_h == rhs._h);
        mat res(this->_mat);
        return res.inplace_combine_right(rhs);
    }

    friend mat operator+(const mat& lhs, const mat& rhs) {
        return mat(lhs) += rhs;
    }
    friend mat operator-(const mat& lhs, const mat& rhs) {
        return mat(lhs) -= rhs;
    }
    friend mat operator*(const mat& lhs, const mat& rhs) {
        return mat(lhs) *= rhs;
    }
    friend bool operator==(const mat& lhs, const mat& rhs) {
        return lhs._mat == rhs._mat;
    }
    friend bool operator!=(const mat& lhs, const mat& rhs) {
        return lhs._mat != rhs._mat;
    }


  private:
    int _h, _w;
    vector<vector<Field>> _mat;
};

} // namespace kk2

#endif // MATRIX_HPP

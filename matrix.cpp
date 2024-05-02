template <class Field>
struct matrix {
    using mat = matrix;
    matrix() : matrix(0) {}
    matrix(int n) : matrix(n, n) {}
    matrix(int h, int w) : matrix(vector<vector<Field>>(h, vector<Field>(w, Field()))) {}
    matrix(const vector<vector<Field>>& mat) : _h(mat.size()), _w(mat[0].size()), mat_(mat) {}
    
    int get_h() const { return _h; }
    int get_w() const { return _w; }

    Field at(int i, int j) const {
        assert(0 <= i && i < _h);
        assert(0 <= j && j < _w);
        return mat_[i][j];
    }

    void display() const {
        for (int i = 0; i < _h; i++) {
            for (int j = 0; j < _w; j++) cout << mat_[i][j] << " ";
            cout << endl;
        }
    }

    void set(int i, int j, Field x) {
        assert(0 <= i && i < _h);
        assert(0 <= j && j < _w);
        mat_[i][j] = x;
    }

    mat& operator+=(const mat& rhs) {
        assert(_h == rhs._h);
        assert(_w == rhs._w);
        for (int i = 0; i < _h; i++) {
            for (int j = 0; j < _w; j++) {
                mat_[i][j] += rhs.mat_[i][j];
            }
        }
        return *this;
    }
    mat& operator-=(const mat& rhs) {
        assert(_h == rhs._h);
        assert(_w == rhs._w);
        for (int i = 0; i < _h; i++) {
            for (int j = 0; j < _w; j++) {
                mat_[i][j] -= rhs.mat_[i][j];
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
                    res[i][j] += mat_[i][k] * rhs.mat_[k][j];
                }
            }
        }
        _w = rhs._w;
        mat_ = res;
        return *this;
    }

    Field det(Field product_e) const {
        assert(_h == _w);
        int n = _h;
        vector<vector<Field>> a(mat_);
        Field res = 1;
        for (int i = 0; i < n; i++) {
            int pivot = -1;
            for (int j = i; j < n; j++) {
                if (a[j][i] != 0) {
                    pivot = j;
                    break;
                }
            }
            if (pivot == -1) return Field();
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

    mat inv(Field product_e) const {
        assert(_h == _w);
        int n = _h;
        vector<vector<Field>> res(n, vector<Field>(n, Field()));
        for (int i = 0; i < n; i++) res[i][i] = 1;
        mat a(mat_);
        for (int i = 0; i < n; i++) {
            int pivot = -1;
            for (int j = i; j < n; j++) {
                if (a.mat_[j][i] != 0) {
                    pivot = j;
                    break;
                }
            }
            if (pivot == -1) {
                return mat(n);
            }
            swap(a.mat_[i], a.mat_[pivot]);
            swap(res[i], res[pivot]);
            Field inv = product_e / a.mat_[i][i];
            for (int j = 0; j < n; j++) {
                a.mat_[i][j] *= inv;
                res[i][j] *= inv;
            }
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                Field r = a.mat_[j][i];
                for (int k = 0; k < n; k++) {
                    a.mat_[j][k] -= a.mat_[i][k] * r;
                    res[j][k] -= res[i][k] * r;
                }
            }
        }
        return mat(res);
    }

    template <class T>
    mat pow(T n) const {
        assert(_h == _w);
        mat x(mat_);
        mat res(_h);
        for (int i = 0; i < _h; i++) res.mat_[i][i] = 1;
        for (int i = 1; i <= n; i <<= 1) {
            if (n & i) res *= x;
            x *= x;
        }
        return res;
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
        return lhs.mat_ == rhs.mat_;
    }
    friend bool operator!=(const mat& lhs, const mat& rhs) {
        return lhs.mat_ != rhs.mat_;
    }


  private:
    int _h, _w;
    vector<vector<Field>> mat_;
};

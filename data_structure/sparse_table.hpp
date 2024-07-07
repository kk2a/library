#ifndef DATA_STRUCTURE_SPARSE_TABLE_HPP
#define DATA_STRUCTURE_SPARSE_TABLE_HPP 1


// require: op(x, x) = x for all x
template <class S, S (*op)(S, S), S (*e)()>
struct SparseTable {
    SparseTable() : SparseTable(0) {}
    SparseTable(int n) : SparseTable(vector<S>(n, e())) {}
    SparseTable(const vector<S>& v) : _n(int(v.size())) {
        log = 1;
        while ((1u << log) <= (unsigned int)_n) log++;
        table.assign(log, vector<S>(_n));
        for (int i = 0; i < _n; i++) table[0][i] = v[i];
        for (int i = 1; i < log; i++) {
            for (int j = 0; j + (1 << i) <= _n; j++) {
                table[i][j] = op(table[i - 1][j], table[i - 1][j + (1 << (i - 1))]);
            }
        }
    }

    using Monoid = S;
    static S Op(S l, S r) { return op(l, r); }
    static S MonoidUnit() { return e(); }

    S prod(int l, int r) {
        assert(0 <= l && l <= r && r <= _n);
        int i = 31 - __builtin_clz(r - l);
        return op(table[i][l], table[i][r - (1 << i)]);
    }

  private:
    int _n, log;
    vector<vector<S>> table;
};

#endif // DATA_STRUCTURE_SPARSE_TABLE_HPP

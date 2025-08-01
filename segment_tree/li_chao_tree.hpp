#ifndef KK2_SEGMENT_TREE_LI_CHAO_TREE_HPP
#define KK2_SEGMENT_TREE_LI_CHAO_TREE_HPP 1

#include <algorithm>
#include <cassert>
#include <numeric>
#include <optional>
#include <vector>

#include "../type_traits/io.hpp"

namespace kk2 {

/**
 * @brief get min(max) クエリが先読みできる Li-Chao Tree
 *
 * @tparam X x座標の型
 * @tparam T 傾きと切片の型．掛け算ができないといけない．
 * @tparam IsMin クエリがminかmaxか
 */
template <class X, class T, bool isMin = true> struct LiChaoTree {
    struct Line {
        T a, b; // y = ax + b
        bool is_unit;
        Line() : a(0), b(0), is_unit(true) {}
        Line(T a_, T b_) : a(isMin ? a_ : -a_), b(isMin ? b_ : -b_), is_unit(false) {}
        auto eval(X x) const { return a * x + b; }
    };

    using value_type = decltype(std::declval<Line>().eval(std::declval<X>()));

    LiChaoTree(int n_) : n(n_) {
        if (n == 0) return;
        lg = 0;
        while ((1 << lg) < n) ++lg;
        siz = 1 << lg;
        xs.resize(siz);
        std::iota(xs.begin(), xs.end(), 0);
        d.resize(siz * 2, Line());
    }

    LiChaoTree(const std::vector<X> &xs_) : xs(xs_) {
        std::sort(xs.begin(), xs.end());
        xs.erase(std::unique(xs.begin(), xs.end()), xs.end());
        n = xs.size();
        if (n == 0) return;
        lg = 0;
        while ((1 << lg) < n) ++lg;
        siz = 1 << lg;
        xs.resize(siz);
        std::iota(xs.begin() + n, xs.end(), xs[n - 1] + 1);
        d.resize(siz * 2, Line());
    }

    void add_line(T a, T b) { inner_add(1, lg, Line(a, b)); }

    void add_seg(X l, X r, T a, T b) {
        int ll = std::lower_bound(xs.begin(), xs.end(), l) - xs.begin();
        int rr = std::lower_bound(xs.begin(), xs.end(), r) - xs.begin();
        assert(ll <= rr);

        ll += siz, rr += siz;
        Line line(a, b);
        for (int i = 0; i <= lg and ll < rr; ++i, ll >>= 1, rr >>= 1) {
            if (ll & 1) inner_add(ll, i, line), ++ll;
            if (rr & 1) --rr, inner_add(rr, i, line);
        }
    }

    std::optional<value_type> get(X x) const {
        int pos = std::lower_bound(xs.begin(), xs.end(), x) - xs.begin();
        assert(0 <= pos and pos < n);
        assert(xs[pos] == x);

        pos += siz;
        value_type res{};
        bool has_value = false;

        for (; pos; pos >>= 1) {
            if (d[pos].is_unit) continue;
            if (!has_value) has_value = true, res = d[pos].eval(x);
            else if (res > d[pos].eval(x)) res = d[pos].eval(x);
        }
        if (!isMin) res = -res;

        return has_value ? std::optional<value_type>(res) : std::nullopt;
    }

    template <class OStream, is_ostream_t<OStream> * = nullptr>
    void debug_output(OStream &os) const {
        os << "LiChaoTree: n = " << n << ", lg = " << lg << ", siz = " << siz << "\n";
        os << "Lines:";
        for (size_t i = 1; i < d.size(); ++i) {
            if ((i & -i) == i) os << "\n[";
            os << " ";
            if (d[i].is_unit) os << "unit";
            else if (isMin) os << d[i].a << "x+" << d[i].b << "";
            else os << -d[i].a << "x+" << -d[i].b << "";
            if (((i + 1) & (-i - 1)) == (i + 1)) os << " ]";

            else os << ", ";
        }
        os << "\nxs: [ ";
        for (const auto &x : xs) os << x << " ";

        os << "]\n";
    }

  private:
    int n, lg, siz;
    std::vector<Line> d;
    std::vector<X> xs;

    void inner_add(int k, int h, Line line) {
        if (n == 0) return;
        int l = (k << h) - siz, r = l + (1 << h);
        while (1) {
            if (d[k].is_unit) {
                d[k] = line;
                return;
            }

            int mid = (l + r) / 2;
            auto left_diff = d[k].eval(xs[l]) - line.eval(xs[l]);
            if (k >= siz) {
                if (left_diff > 0) d[k] = line;
                return;
            }
            auto right_diff = d[k].eval(xs[r - 1]) - line.eval(xs[r - 1]);
            if (left_diff == right_diff) {
                if (left_diff > 0) d[k] = line;
                return;
            }
            auto mid_diff = d[k].eval(xs[mid]) - line.eval(xs[mid]);
            if (mid_diff >= 0) std::swap(d[k], line);
            if ((left_diff >= 0) == (right_diff >= 0)) return;
            if ((left_diff >= 0) == (mid_diff >= 0)) k = k << 1 | 1, l = mid;
            else k = k << 1, r = mid;
        }
    }
};

} // namespace kk2

#endif // KK2_SEGMENT_TREE_LI_CHAO_TREE_HPP

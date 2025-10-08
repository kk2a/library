#ifndef KK2_MATH_STERN_BROCOT_TREE_HPP
#define KK2_MATH_STERN_BROCOT_TREE_HPP 1

#include <algorithm>

namespace kk2 {

template <class T> struct SternBrocotTreeNode {
    T lnum, lden;
    T rnum, rden;
    // even: right, odd: left
    std::vector<T> path;
    T dep;

    SternBrocotTreeNode() : lnum(0), lden(1), rnum(1), rden(0), path({0}), dep(0) {}
    SternBrocotTreeNode(T x, T y) : lnum(0), lden(1), rnum(1), rden(0), path({0}), dep(0) {
        assert(x > 0 and y > 0);
        bool left = false;
        for (; y; left = !left) {
            T q = x / y, r = x - q * y;
            go_down(left, q - (r == 0));
            x = y, y = r;
        }
    }
    SternBrocotTreeNode(const std::vector<T> &p) : lnum(0), lden(1), rnum(1), rden(0), path({0}) {
        for (auto d : p) go_down(path.size() & 1, d);
    }
    SternBrocotTreeNode(const std::vector<std::pair<char, T>> &p)
        : lnum(0),
          lden(1),
          rnum(1),
          rden(0),
          path({0}) {
        for (auto [c, d] : p) go_down(c == 'L', d);
    }

    void go_down(bool left, T d = 1) {
        assert(d >= 0);
        dep += d;
        if (left) rnum += d * lnum, rden += d * lden;
        else lnum += d * rnum, lden += d * rden;
        if ((path.size() & 1) == left) path.emplace_back(d);
        else path.back() += d;
    }

    bool go_up(T d = 1) {
        if (d < 0 or dep < d) return false;
        while (d) {
            T step = std::min(d, path.back());
            dep -= step, d -= step;
            if (path.size() & 1) lnum -= step * rnum, lden -= step * rden;
            else rnum -= step * lnum, rden -= step * lden;
            if (path.back() == step) path.pop_back();
            else path.back() -= step;
        }
        if (path.empty()) path.emplace_back(0);
        return true;
    }

    std::pair<T, T> val() const { return {lnum + rnum, lden + rden}; }
    std::tuple<T, T, T, T> range() const { return {lnum, lden, rnum, rden}; }
    const std::vector<T> &get_path() const { return path; }
    T get_depth() const { return dep; }
};

/**
 * @brief Stern-Brocot tree
 *
 * @tparam T 掛け算がオーバーフローしないように設定すること
 */
template <class T> struct SternBrocotTree {
    using Node = SternBrocotTreeNode<T>;
    inline static Node root = Node();

    static Node lca(const Node &u, const Node &v) {
        Node res = root;
        T len = std::min(u.path.size(), v.path.size());
        for (T i = 0; i < len; i++) {
            T d = std::min(u.path[i], v.path[i]);
            res.go_down(i & 1, d);
            if (u.path[i] != v.path[i]) break;
        }
        return res;
    }

    /**
     * @brief Stern-Brocot tree 上で二分探索をする
     *
     * @param f 判定関数`f(num, den)->bool`, 単調で`f(0, 1)=true, f(1, 0)=false`
     * @param N 分母と分子はともに`N`以下．`2N`がオーバーフローしないことを保証すること
     *
     * @return `std::tuple<T, T, T, T>`
     *
     * - `lnum/lden = max{x/y : f(x, y) = true, max(x, y) <= N}`
     *
     * - `rnum/rden = min{x/y : f(x, y) = false, max(x, y) <= N}`
     *
     * - `return {lnum, lden, rnum, rden}`
     */
    template <class F> static std::tuple<T, T, T, T> binary_search(T N, F f) {
        assert(N > 0);
        assert(f(0, 1) and !f(1, 0));

        T num1 = 0, den1 = 1, num2 = 1, den2 = 0;
        bool left = false;
        while (num1 + num2 <= N and den1 + den2 <= N) {
            for (int i = 0;; ++i) {
                T num = num1 + (num2 << i), den = den1 + (den2 << i);
                if (num > N or den > N or f(num, den) == left) {
                    while (i--) {
                        num = num1 + (num2 << i), den = den1 + (den2 << i);
                        if (num <= N and den <= N and f(num, den) != left) num1 = num, den1 = den;
                    }
                    break;
                }
            }
            std::swap(num1, num2), std::swap(den1, den2), left = !left;
        }
        if (left) std::swap(num1, num2), std::swap(den1, den2);
        return {num1, den1, num2, den2};
    }
};

} // namespace kk2

#endif // KK2_MATH_STERN_BROCOT_TREE_HPP

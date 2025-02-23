#ifndef KK2_DATA_STRUCTURE_SLOPE_TRICK_HPP
#define KK2_DATA_STRUCTURE_SLOPE_TRICK_HPP 1

#include <algorithm>
#include <queue>
#include <vector>

namespace kk2 {

template <class T, class U = T>
struct SlopeTrick {
  private:
    struct P {
        T pos;
        U count;

        P(T pos, U count) : pos(pos), count(count) {}

        bool operator<(const P &p) const { return pos < p.pos; }

        bool operator>(const P &p) const { return pos > p.pos; }
    };

    std::priority_queue<P> left;
    std::priority_queue<P, std::vector<P>, std::greater<P>> right;
    T _shift_left, _shift_right, min_y;

    void push_left(T pos, U count) { left.emplace(pos - _shift_left, count); }

    void push_right(T pos, U count) { right.emplace(pos - _shift_right, count); }

    P get_left() { return P(left.top().pos + _shift_left, left.top().count); }

    P get_right() { return P(right.top().pos + _shift_right, right.top().count); }

    void pop_left() { left.pop(); }

    void pop_right() { right.pop(); }

  public:
    SlopeTrick() : _shift_left(), _shift_right(), min_y() {}

    // add: max(0, x - a) * c
    void add_inc(T a, U c = 1) {
        U used = 0;
        while (used < c and !left.empty()) {
            auto [pos, count] = get_left();
            if (pos <= a) break;
            pop_left();
            U use = std::min(c - used, count);
            push_right(pos, use);
            if (count > use) push_left(pos, count - use);
            min_y += (pos - a) * use;
            used += use;
        }
        if (used) push_left(a, used);
        if (c - used) push_right(a, c - used);
    }

    // add: max(0, a - x) * c
    void add_dec(T a, U c = 1) {
        U used = 0;
        while (used < c and !right.empty()) {
            auto [pos, count] = get_right();
            if (pos >= a) break;
            pop_right();
            U use = std::min(c - used, count);
            push_left(pos, use);
            if (count > use) push_right(pos, count - use);
            min_y += (a - pos) * use;
            used += use;
        }
        if (used) push_right(a, used);
        if (c - used) push_left(a, c - used);
    }

    // add: abs(x - a) * c
    void add_abs(T a, U c = 1) { add_inc(a, c), add_dec(a, c); }

    struct T_inf {
        T a;
        bool inf;
    };

    struct T_minf {
        T a;
        bool minf;
    };

    struct get_min_result {
        T_inf a;
        T_minf b;
        T min_y;
    };

    /**
     * f(x) = min_y + sum(max(0, x - a) * c) + sum(max(0, a - x) * c)
     * f^-1(min_y) = [a, b]
     * return {a, b, min_y}
     */
    get_min_result get_min() {
        T_inf a{0, true};
        T_minf b{0, true};
        if (!left.empty()) {
            a.a = get_left().pos;
            a.inf = false;
        }
        if (!right.empty()) {
            b.a = get_right().pos;
            b.minf = false;
        }
        return {a, b, min_y};
    }

    // f \mapsto (x \mapsto min_(y <= x) f(y))
    void chmin_left() { decltype(left)().swap(left); }

    // f \mapsto (x \mapsto min_(y >= x) f(y))
    void chmin_right() { decltype(right)().swap(right); }

    void shift_left(T x) { _shift_left += x; }

    void shift_right(T x) { _shift_right += x; }

    // f \mapsto (t \mapsto f(t - x))
    void shift_x(T x) { _shift_left += x, _shift_right += x; }

    // f \mapsto f + x
    void shift_y(T x) { min_y += x; }
};

} // namespace kk2


#endif // KK2_DATA_STRUCTURE_SLOPE_TRICK_HPP

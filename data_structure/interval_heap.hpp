#ifndef KK2_DATA_STRUCTURE_INTERVAL_HEAP_HPP
#define KK2_DATA_STRUCTURE_INTERVAL_HEAP_HPP 1

#include <algorithm>
#include <cassert>
#include <functional>
#include <vector>

namespace kk2 {

template <class T, class Compare = std::less<T>>
struct IntervalHeap {
    std::vector<T> v;

    IntervalHeap() = default;
    IntervalHeap(const std::vector<T> &a) : v(a) {
        make_heap();
    }

    void make_heap() {
        
    }

  private:
    static bool op(T x, T y) {
        return Compare{}(x, y);
    }
};

} // namespace kk2

#endif // KK2_DATA_STRUCTURE_INTERVAL_HEAP_HPP

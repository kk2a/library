#ifndef KK2_OTHERS_TIMER_HPP
#define KK2_OTHERS_TIMER_HPP 1

#include <chrono>

namespace kk2 {

struct Timer {
    using clock = std::chrono::high_resolution_clock;
    using time_point = clock::time_point;

    clock::time_point start;

    Timer() : start(clock::now()) {}

    void reset() { start = clock::now(); }

    /**
     * @brief 時間を計測する
     * @return 経過時間 (ms)
     */
    double elapsed() const {
        auto end = clock::now();
        return std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() * 1e-6;
    }
};

} // namespace kk2

#endif // KK2_OTHERS_TIMER_HPP

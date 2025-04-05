#ifndef KK2_RANDOM_SEED_HPP
#define KK2_RANDOM_SEED_HPP 1

#include <chrono>

namespace kk2 {

namespace random {

using u64 = unsigned long long;

inline u64 non_deterministic_seed() {
    u64 seed = std::chrono::duration_cast<std::chrono::nanoseconds>(
                   std::chrono::high_resolution_clock::now().time_since_epoch())
                   .count();
    seed ^= reinterpret_cast<u64>(&seed);
    seed ^= seed << 5;
    seed ^= seed >> 41;
    seed ^= seed << 20;
    return seed;
}

inline u64 deterministic_seed() { return 5801799128519729247ull; }

inline u64 seed() {
#if defined(KK2_RANDOM_DETERMINISTIC)
    return deterministic_seed();
#else
    return non_deterministic_seed();
#endif
}

} // namespace random

} // namespace kk2

#endif // KK2_RANDOM_SEED_HPP

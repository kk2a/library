#ifndef KK2_MATH_ISPRIME_TABLE_HPP
#define KK2_MATH_ISPRIME_TABLE_HPP 1

#include <algorithm>
#include <array>
#include <bit>
#include <cassert>
#include <cstdint>
#include <iterator>
#include <vector>

#include "../data_structure/my_bitset.hpp"
#include "sqrt_floor.hpp"

namespace kk2 {

struct IsPrimeTable {
  private:
    static constexpr std::array<int, 9> _small_primes{2, 3, 5, 7, 11, 13, 17, 19, 23};
    static inline int _n = 1;
    static inline int _wheel = 1;
    static inline int _residue_count = 0;
    static inline int _wheel_prime_count = 0;
    static inline std::vector<int> _coprimes{};
    static inline std::vector<int> _residue_index{};
    static inline DynamicBitSet::RankSelect _prime_candidates{};

    template <int Wheel, int ResidueCount>
    static void set_offsets(int p,
                            const std::vector<int> &coprimes,
                            const std::vector<int> &residue_index,
                            int *offsets) {
        for (int r = 0; r < ResidueCount; ++r) {
            long long x = 1LL * p * coprimes[r];
            offsets[r] = x / Wheel * ResidueCount + residue_index[x % Wheel];
        }
    }

    static int candidate_value(int index) {
        return index / _residue_count * _wheel + _coprimes[index % _residue_count];
    }

    static int candidate_end(int n) {
        return n / _wheel * _residue_count
               + (int)(std::upper_bound(_coprimes.begin(), _coprimes.end(), n % _wheel)
                       - _coprimes.begin());
    }

    static int candidate_rank(int end) { return _prime_candidates.rank(end); }

  public:
    IsPrimeTable() = delete;

    static void set_upper(int m) {
        if (m <= _n && _residue_count != 0) return;
        int next_n = std::max({m, 2 * _n, 60});

        int sqrt_n = sqrt_floor(next_n);
        int wheel = 1;
        int wheel_prime_count = 0;
        // A moderately larger wheel pays off by reducing the number of sieve candidates.
        while (wheel_prime_count < (int)_small_primes.size()
               && 4LL * wheel * _small_primes[wheel_prime_count] <= 7LL * sqrt_n) {
            wheel *= _small_primes[wheel_prime_count];
            ++wheel_prime_count;
        }

        std::vector<bool> iscoprime(wheel, true);
        for (int i = 0; i < wheel_prime_count; ++i) {
            for (int j = _small_primes[i]; j < wheel; j += _small_primes[i]) iscoprime[j] = false;
        }
        std::vector<int> residue_index(wheel, -1);
        int residue_count = 0;
        for (int i = 1; i < wheel; ++i) {
            if (iscoprime[i]) residue_index[i] = residue_count++;
        }
        std::vector<int> coprimes(residue_count);
        for (int i = 1; i < wheel; ++i) {
            if (residue_index[i] != -1) coprimes[residue_index[i]] = i;
        }

        auto val = [&](int i) {
            return i / residue_count * wheel + coprimes[i % residue_count];
        };

        int candidate_count = (next_n + wheel - 1) / wheel * residue_count;
        while (candidate_count > 1 && val(candidate_count - 1) > next_n) --candidate_count;
        DynamicBitSet composite(candidate_count);
        std::uint64_t *composite_data = composite.data();
        auto set_composite = [&](long long i) {
            composite_data[i >> 6] |= std::uint64_t(1) << (i & 63);
        };
        {
            std::vector<bool> base_isprime(sqrt_n + 1, true);
            base_isprime[0] = base_isprime[1] = false;
            std::vector<int> base_primes;
            for (int p = 2; p <= sqrt_n; ++p) {
                if (!base_isprime[p]) continue;
                if (p > _small_primes[wheel_prime_count - 1]) base_primes.push_back(p);
                if (1LL * p * p <= sqrt_n) {
                    for (int q = p * p; q <= sqrt_n; q += p) base_isprime[q] = false;
                }
            }
            constexpr int dense_limit = 112;
            constexpr int dense_mask_bytes = 1 << 20;
            int dense_count = 0;
            if (wheel == 30030) {
                std::vector<int> offsets(residue_count);
                while (dense_count < (int)base_primes.size()
                       && base_primes[dense_count] <= dense_limit) {
                    ++dense_count;
                }
                for (int group_begin = 0; group_begin < dense_count;) {
                    int product = 1;
                    int group_end = group_begin;
                    while (group_end < dense_count
                           && 1LL * product * base_primes[group_end] * residue_count
                                  <= 8LL * dense_mask_bytes) {
                        product *= base_primes[group_end++];
                    }
                    if (group_end == group_begin) product = base_primes[group_end++];
                    int mask_word_count = product * residue_count / 64;
                    DynamicBitSet mask(mask_word_count * 64);
                    for (int k = group_begin; k < group_end; ++k) {
                        int p = base_primes[k];
                        set_offsets<30030, 5760>(p, coprimes, residue_index, offsets.data());
                        int period = p * residue_count;
                        for (int base = 0; base < product * residue_count; base += period) {
                            for (int offset : offsets) {
                                int index = base + offset;
                                mask.word(index >> 6) |= std::uint64_t(1) << (index & 63);
                            }
                        }
                    }
                    composite.inplace_or_repeated(mask);
                    for (int k = group_begin; k < group_end; ++k) {
                        int p = base_primes[k];
                        int index = p / wheel * residue_count + residue_index[p % wheel];
                        composite.word(index >> 6) &= ~(std::uint64_t(1) << (index & 63));
                    }
                    group_begin = group_end;
                }
            }
            int sparse_end = base_primes.size();
            while (sparse_end > dense_count && 1LL * base_primes[sparse_end - 1] * wheel > next_n) {
                int p = base_primes[--sparse_end];
                int begin = residue_index[p % wheel];
                int end = std::upper_bound(coprimes.begin(), coprimes.end(), next_n / p)
                          - coprimes.begin();
                for (int r = begin; r < end; ++r) {
                    long long x = 1LL * p * coprimes[r];
                    set_composite(x / wheel * residue_count + residue_index[x % wheel]);
                }
            }
            struct SieveState {
                int residue;
                long long base, step;
            };
            int batch_size = wheel == 30030 ? 384 : 128;
            constexpr int segment_size = 1 << 21;
            // Keep one candidate segment hot while marking it with a batch of primes.
            std::vector<int> all_offsets((std::size_t)batch_size * residue_count);
            std::vector<SieveState> states(batch_size);
            for (int batch_begin = dense_count; batch_begin < sparse_end;
                 batch_begin += batch_size) {
                int size = std::min(batch_size, sparse_end - batch_begin);
                for (int k = 0; k < size; ++k) {
                    int p = base_primes[batch_begin + k];
                    int *offsets = all_offsets.data() + (std::size_t)k * residue_count;
                    switch (wheel) {
                        case 6:
                            set_offsets<6, 2>(p, coprimes, residue_index, offsets);
                            break;
                        case 30:
                            set_offsets<30, 8>(p, coprimes, residue_index, offsets);
                            break;
                        case 210:
                            set_offsets<210, 48>(p, coprimes, residue_index, offsets);
                            break;
                        case 2310:
                            set_offsets<2310, 480>(p, coprimes, residue_index, offsets);
                            break;
                        case 30030:
                            set_offsets<30030, 5760>(p, coprimes, residue_index, offsets);
                            break;
                        default:
                            for (int r = 0; r < residue_count; ++r) {
                                long long x = 1LL * p * coprimes[r];
                                offsets[r] = x / wheel * residue_count + residue_index[x % wheel];
                            }
                    }
                    int i = p / wheel * residue_count + residue_index[p % wheel];
                    int block = i / residue_count;
                    states[k] = {i % residue_count,
                                 1LL * p * block * residue_count,
                                 1LL * p * residue_count};
                }
                for (int segment_begin = 0; segment_begin < candidate_count;
                     segment_begin += segment_size) {
                    int segment_end = std::min(candidate_count, segment_begin + segment_size);
                    for (int k = 0; k < size; ++k) {
                        SieveState &state = states[k];
                        int *offsets = all_offsets.data() + (std::size_t)k * residue_count;
                        while (state.base + offsets[residue_count - 1] < segment_end) {
                            int r = state.residue;
                            for (; r + 4 <= residue_count; r += 4) {
                                set_composite(state.base + offsets[r]);
                                set_composite(state.base + offsets[r + 1]);
                                set_composite(state.base + offsets[r + 2]);
                                set_composite(state.base + offsets[r + 3]);
                            }
                            for (; r < residue_count; ++r) {
                                set_composite(state.base + offsets[r]);
                            }
                            state.residue = 0;
                            state.base += state.step;
                        }
                        while (state.residue < residue_count
                               && state.base + offsets[state.residue] < segment_end) {
                            set_composite(state.base + offsets[state.residue]);
                            ++state.residue;
                        }
                        if (state.residue == residue_count) {
                            state.residue = 0;
                            state.base += state.step;
                        }
                    }
                }
            }
        }

        composite.set(0);
        _n = next_n;
        _wheel = wheel;
        _residue_count = residue_count;
        _wheel_prime_count = wheel_prime_count;
        _coprimes = std::move(coprimes);
        _residue_index = std::move(residue_index);
        _prime_candidates = DynamicBitSet::RankSelect(std::move(composite), false);
    }

  private:
    struct PrimeAccessor {
        struct MonotoneCursor {
          private:
            int _size, _prefix_count;
            int _last_rank = -1;
            DynamicBitSet::RankSelect::MonotoneCursor _cursor;

          public:
            MonotoneCursor(int size, int prefix_count)
                : _size(size),
                  _prefix_count(prefix_count),
                  _cursor(_prime_candidates.monotone_cursor()) {}

            int operator[](int rank) {
                assert(0 <= rank && _last_rank <= rank && rank < _size);
                _last_rank = rank;
                if (rank < _prefix_count) {
                    assert(rank < (int)_small_primes.size());
                    return _small_primes[rank];
                }

                return candidate_value(_cursor[rank - _prefix_count]);
            }
        };

        int _size, _prefix_count;

        int size() const { return _size; }

        int operator[](int rank) const {
            assert(0 <= rank && rank < _size);
            if (rank < _prefix_count) return _small_primes[rank];
            return candidate_value(_prime_candidates[rank - _prefix_count]);
        }

        MonotoneCursor monotone_cursor() const { return MonotoneCursor(_size, _prefix_count); }
    };

  public:
    static auto primes(int n) {
        using Range = MonotoneRankRange<PrimeAccessor>;
        if (n >= _n) set_upper(n);
        if (_residue_count == 0)
            return Range{
                PrimeAccessor{0, 0}
            };
        int prefix_count =
            (int)(std::upper_bound(
                      _small_primes.begin(), _small_primes.begin() + _wheel_prime_count, n)
                  - _small_primes.begin());
        int end = candidate_end(n);
        return Range{
            PrimeAccessor{prefix_count + candidate_rank(end), prefix_count}
        };
    }

    static auto primes() { return primes(_n); }

    static bool isprime(int n) {
        assert(n > 0);
        if (n >= _n) set_upper(n);
        for (int i = 0; i < _wheel_prime_count; ++i) {
            if (n == _small_primes[i]) return true;
        }
        int residue = _residue_index[n % _wheel];
        if (residue == -1) return false;
        int index = n / _wheel * _residue_count + residue;
        return _prime_candidates.contains(index);
    }
};

} // namespace kk2

#endif // KK2_MATH_ISPRIME_TABLE_HPP

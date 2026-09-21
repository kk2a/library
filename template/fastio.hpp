#ifndef KK2_TEMPLATE_FASTIO_HPP
#define KK2_TEMPLATE_FASTIO_HPP 1

#include <algorithm>
#include <array>
#include <bit>
#include <cerrno>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <limits>
#include <string>
#include <string_view>
#include <system_error>
#if defined(KK2_FASTIO_POSIX)
#include <unistd.h>
#endif

#include "../type_traits/integral.hpp"
#include "../type_traits/io.hpp"

namespace kk2 {

namespace fastio {

struct Scanner : type_traits::istream_tag {
  private:
    static constexpr size_t INPUT_BUF = 1 << 17;
    static constexpr size_t INPUT_LOOKAHEAD = 64;

    std::array<char, INPUT_BUF + INPUT_LOOKAHEAD> buf;
    char *ptr = buf.data();
    char *data_end = buf.data();
    FILE *fp;
#if defined(KK2_FASTIO_POSIX)
    int fd = -1;
#endif
    bool owns_file = false;
    bool is_eof = false;
    bool has_failed = false;

    static FILE *open_file(const char *file) {
        if (file == nullptr) throw std::system_error(EINVAL, std::generic_category(), "fopen");
        FILE *res = std::fopen(file, "rb");
        if (res == nullptr) throw std::system_error(errno, std::generic_category(), file);
        return res;
    }

    static FILE *check_file(FILE *file) {
        if (file == nullptr)
            throw std::system_error(EINVAL, std::generic_category(), "FILE pointer");
        return file;
    }

#if defined(KK2_FASTIO_POSIX)
    void setup_posix() {
        std::setvbuf(fp, nullptr, _IONBF, 0);
        fd = ::fileno(fp);
        if (fd < 0) has_failed = true;
    }

    ssize_t read_bytes(char *dst, size_t n) {
        while (true) {
            const ssize_t result = ::read(fd, dst, n);
            if (result >= 0) return result;
            if (errno != EINTR) return -1;
        }
    }


#endif

    bool refill() {
        if (is_eof or has_failed) [[unlikely]]
            return false;
#if defined(KK2_FASTIO_POSIX)
        const ssize_t count = read_bytes(buf.data(), INPUT_BUF);
        if (count < 0) {
            has_failed = true;
            return false;
        }
#else
        const size_t count = std::fread(buf.data(), 1, INPUT_BUF, fp);
#endif
        data_end = buf.data() + count;
        ptr = buf.data();
        *data_end = '!';
        if (ptr != data_end) [[likely]]
            return true;
        is_eof = true;
#if !defined(KK2_FASTIO_POSIX)
        if (!std::feof(fp)) {
            is_eof = false;
            has_failed = true;
        }
#endif
        return false;
    }

    bool prepare_fast_input() {
        const size_t remaining = static_cast<size_t>(data_end - ptr);
        if (remaining > INPUT_LOOKAHEAD) [[likely]]
            return true;

        if (remaining != 0) std::memmove(buf.data(), ptr, remaining);
#if defined(KK2_FASTIO_POSIX)
        const ssize_t count = read_bytes(buf.data() + remaining, INPUT_BUF - remaining);
        if (count < 0) {
            has_failed = true;
            return false;
        }
#else
        const size_t count = std::fread(buf.data() + remaining, 1, INPUT_BUF - remaining, fp);
#endif
        ptr = buf.data();
        data_end = buf.data() + remaining + count;
        std::fill_n(data_end, INPUT_LOOKAHEAD, '!');

        if (count == 0) {
#if defined(KK2_FASTIO_POSIX)
            is_eof = true;
#else
            if (std::feof(fp)) is_eof = true;
            else has_failed = true;
#endif
        }
        return ptr != data_end;
    }

    static constexpr bool is_space(int c) {
        const unsigned char value = static_cast<unsigned char>(c);
        return value == ' ' or (value >= '\t' and value <= '\r');
    }

    static constexpr bool is_digit(int c) {
        return static_cast<unsigned>(static_cast<unsigned char>(c)) - '0' <= 9;
    }

    bool skip_space_unchecked() {
        while (true) {
            while (static_cast<unsigned char>(*ptr) <= ' ') ++ptr;
            if (ptr != data_end) [[likely]]
                return true;
            if (!refill()) [[unlikely]]
                return false;
        }
    }

    template <UnsignedIntegral T> bool read_digits(T &x, T limit) {
        int c = now();
        if (!is_digit(c)) return false;

        T res = 0;
        const T cutoff = limit / 10;
        const T cutlim = limit % 10;
        bool overflow = false;
        do {
            const T digit = static_cast<T>(c - '0');
            if (res > cutoff or (res == cutoff and digit > cutlim)) overflow = true;
            else if (!overflow) res = static_cast<T>(res * 10 + digit);
            if (ptr != data_end) ++ptr;
            c = now();
        } while (is_digit(c));

        if (overflow) return false;
        x = res;
        return true;
    }

    template <UnsignedIntegral T>
    [[gnu::always_inline]]
    T read_digits_unchecked() {
        // Parse 8, 4, and 2 decimal digits at once on little-endian targets.
        if constexpr (std::endian::native == std::endian::little) {
            using Wide = std::conditional_t<(sizeof(T) < sizeof(uint64_t)), uint64_t, T>;
            Wide res = 0;
            const char *read_ptr = ptr;

            while (true) {
                uint64_t value;
                std::memcpy(&value, read_ptr, sizeof(value));
                value -= 0x3030303030303030ull;
                if (value & 0x8080808080808080ull) break;
                value = (value * 10 + (value >> 8)) & 0x00ff00ff00ff00ffull;
                value = (value * 100 + (value >> 16)) & 0x0000ffff0000ffffull;
                value = (value * 10000 + (value >> 32)) & 0x00000000ffffffffull;
                res = res * 100000000 + value;
                read_ptr += 8;
            }

            uint32_t value4;
            std::memcpy(&value4, read_ptr, sizeof(value4));
            value4 -= 0x30303030u;
            if (!(value4 & 0x80808080u)) {
                value4 = (value4 * 10 + (value4 >> 8)) & 0x00ff00ffu;
                value4 = (value4 * 100 + (value4 >> 16)) & 0x0000ffffu;
                res = res * 10000 + value4;
                read_ptr += 4;
            }

            uint16_t value2;
            std::memcpy(&value2, read_ptr, sizeof(value2));
            value2 = static_cast<uint16_t>(value2 - 0x3030u);
            if (!(value2 & 0x8080u)) {
                value2 = static_cast<uint16_t>((value2 * 10 + (value2 >> 8)) & 0x00ffu);
                res = res * 100 + value2;
                read_ptr += 2;
            }

            if (static_cast<unsigned char>(*read_ptr) >= '0') {
                res = res * 10 + static_cast<unsigned char>(*read_ptr++) - '0';
            }
            ptr = const_cast<char *>(read_ptr);
            ++ptr;
            return static_cast<T>(res);
        }

        T res = 0;
        int c = now();
        while (is_digit(c)) {
            res = static_cast<T>(res * 10 + static_cast<T>(c - '0'));
            ++ptr;
            c = now();
        }
        return res;
    }

    template <UnsignedIntegral T> bool read_unsigned_integral(T &x) {
        if (!skip_space()) return false;
        if (now() == '+') ++ptr;
        return read_digits(x, std::numeric_limits<T>::max());
    }

    template <SignedIntegral T> bool read_signed_integral(T &x) {
        using U = typename to_unsigned<T>::type;

        if (!skip_space()) return false;
        bool negative = false;
        if (now() == '-' or now() == '+') {
            negative = now() == '-';
            ++ptr;
        }

        constexpr U max = static_cast<U>(std::numeric_limits<T>::max());
        const U limit = negative ? max + U{1} : max;
        U magnitude;
        if (!read_digits(magnitude, limit)) return false;

        if (!negative) x = static_cast<T>(magnitude);
        else if (magnitude == max + U{1}) x = std::numeric_limits<T>::min();
        else x = static_cast<T>(-static_cast<T>(magnitude));
        return true;
    }

    template <class F> bool extract(F &&f) {
        if (has_failed) [[unlikely]]
            return false;
        if (f()) [[likely]]
            return true;
        has_failed = true;
        return false;
    }

  public:
    Scanner() : fp(stdin) {
#if defined(KK2_FASTIO_POSIX)
        setup_posix();
#elif defined(KK2_FASTIO_UNBUFFERED) || defined(KK2_FASTIO_UNBUFFERED_INPUT)
        // Avoid the second stdio buffer when this stream is exclusively used here.
        std::setvbuf(fp, nullptr, _IONBF, 0);
#endif
        refill();
    }

    explicit Scanner(const char *file) : fp(open_file(file)), owns_file(true) {
#if defined(KK2_FASTIO_POSIX)
        setup_posix();
#endif
        refill();
    }

    explicit Scanner(FILE *file, bool take_ownership = false)
        : fp(check_file(file)),
          owns_file(take_ownership) {
#if defined(KK2_FASTIO_POSIX)
        setup_posix();
#endif
        refill();
    }

    Scanner(const Scanner &) = delete;
    Scanner &operator=(const Scanner &) = delete;
    Scanner(Scanner &&) = delete;
    Scanner &operator=(Scanner &&) = delete;

    ~Scanner() {
        if (owns_file) std::fclose(fp);
    }

    int now() {
        if (ptr == data_end and !refill()) return EOF;
        return static_cast<unsigned char>(*ptr);
    }

    bool skip_space() {
        while (true) {
            while (ptr != data_end and is_space(static_cast<unsigned char>(*ptr))) ++ptr;
            if (ptr != data_end) [[likely]]
                return true;
            if (!refill()) [[unlikely]]
                return false;
        }
    }

    bool good() const { return !has_failed; }

    bool eof() const { return is_eof; }

    explicit operator bool() const { return good(); }

    // Checked extraction: detects EOF, malformed input, and integer overflow.
    template <UnsignedIntegral T> bool read(T &x) {
        return extract([&] { return read_unsigned_integral(x); });
    }

    template <SignedIntegral T> bool read(T &x) {
        return extract([&] { return read_signed_integral(x); });
    }

    bool read(char &x) {
        return extract([&] {
            if (!skip_space()) return false;
            x = static_cast<char>(now());
            ++ptr;
            return true;
        });
    }

    bool read(std::string &x) {
        return extract([&] {
            if (!skip_space()) return false;
            x.clear();
            while (true) {
                const char *first = ptr;
                while (ptr != data_end and !is_space(static_cast<unsigned char>(*ptr))) ++ptr;
                x.append(first, static_cast<size_t>(ptr - first));
                if (ptr != data_end or now() == EOF) break;
            }
            return true;
        });
    }

    // Fast extraction for trusted, in-range input.
    template <UnsignedIntegral T>
    [[gnu::always_inline]]
    T next_unsigned_integral() {
        if (!skip_space_unchecked()) {
            has_failed = true;
            return T{};
        }
        prepare_fast_input();
        return read_digits_unchecked<T>();
    }

    template <SignedIntegral T>
    [[gnu::always_inline]]
    T next_signed_integral() {
        using U = typename to_unsigned<T>::type;

        if (!skip_space_unchecked()) {
            has_failed = true;
            return T{};
        }
        prepare_fast_input();
        bool negative = false;
        if (*ptr == '-') {
            negative = true;
            ++ptr;
        }
        const U magnitude = read_digits_unchecked<U>();
        constexpr U max = static_cast<U>(std::numeric_limits<T>::max());
        if (!negative) {
            if (magnitude <= max) return static_cast<T>(magnitude);
            has_failed = true;
            return T{};
        }
        if (magnitude == max + U{1}) return std::numeric_limits<T>::min();
        if (magnitude <= max) return static_cast<T>(-static_cast<T>(magnitude));
        has_failed = true;
        return T{};
    }

    char next_char() {
        char res{};
        read(res);
        return res;
    }

    std::string next_string() {
        std::string res;
        read(res);
        return res;
    }

    template <UnsignedIntegral T>
    [[gnu::always_inline]]
    Scanner &operator>>(T &x) {
        x = next_unsigned_integral<T>();
        return *this;
    }

    template <SignedIntegral T>
    [[gnu::always_inline]]
    Scanner &operator>>(T &x) {
        x = next_signed_integral<T>();
        return *this;
    }

    Scanner &operator>>(char &x) {
        read(x);
        return *this;
    }

    Scanner &operator>>(std::string &x) {
        read(x);
        return *this;
    }
};

struct endl_struct_t {};

struct Printer : type_traits::ostream_tag {
  private:
    static constexpr size_t OUTPUT_BUF = 1 << 17;

    std::array<char, OUTPUT_BUF> buf;
    char *ptr = buf.data();
    char *const buf_end = buf.data() + OUTPUT_BUF;
    FILE *fp;
#if defined(KK2_FASTIO_POSIX)
    int fd = -1;
#endif
    bool owns_file = false;
    bool has_failed = false;

    static FILE *open_file(const char *file) {
        if (file == nullptr) throw std::system_error(EINVAL, std::generic_category(), "fopen");
        FILE *res = std::fopen(file, "wb");
        if (res == nullptr) throw std::system_error(errno, std::generic_category(), file);
        return res;
    }

    static FILE *check_file(FILE *file) {
        if (file == nullptr)
            throw std::system_error(EINVAL, std::generic_category(), "FILE pointer");
        return file;
    }

#if defined(KK2_FASTIO_POSIX)
    void setup_posix() {
        std::setvbuf(fp, nullptr, _IONBF, 0);
        fd = ::fileno(fp);
        if (fd < 0) has_failed = true;
    }

    bool write_bytes(const char *src, size_t n, size_t &written) {
        written = 0;
        while (written != n) {
            const ssize_t result = ::write(fd, src + written, n - written);
            if (result > 0) {
                written += static_cast<size_t>(result);
                continue;
            }
            if (result < 0 and errno == EINTR) continue;
            return false;
        }
        return true;
    }
#endif

    template <class T> static constexpr int DIGITS = std::numeric_limits<T>::digits10 + 1;

    template <class T>
    inline static constexpr auto POW10 = [] {
        std::array<T, DIGITS<T>> res{};
        res[0] = 1;
        for (size_t i = 1; i < res.size(); ++i) res[i] = 10 * res[i - 1];
        return res;
    }();

    inline static constexpr std::array<char, 40000> digit_blocks = [] {
        std::array<char, 40000> res{};
        char *ptr = res.data();
        for (int i = 0; i < 10000; ++i) {
            *ptr++ = static_cast<char>('0' + i / 1000);
            *ptr++ = static_cast<char>('0' + i / 100 % 10);
            *ptr++ = static_cast<char>('0' + i / 10 % 10);
            *ptr++ = static_cast<char>('0' + i % 10);
        }
        return res;
    }();


    bool write_buffer() {
        const size_t buffered = static_cast<size_t>(ptr - buf.data());
        size_t written = 0;
        while (written != buffered) {
#if defined(KK2_FASTIO_POSIX)
            size_t count = 0;
            if (write_bytes(buf.data() + written, buffered - written, count)) {
                written += count;
                continue;
            }
            written += count;
            const size_t n = 0;
#else
            const size_t n = std::fwrite(buf.data() + written, 1, buffered - written, fp);
#endif
            if (n == 0) [[unlikely]] {
                if (written != 0) {
                    std::memmove(buf.data(), buf.data() + written, buffered - written);
                    ptr = buf.data() + buffered - written;
                }
                has_failed = true;
                return false;
            }
            written += n;
        }
        ptr = buf.data();
        return true;
    }

    void put_bytes(const char *s, size_t n) {
        // Avoid an extra copy for large strings when the local buffer is empty.
        // On a short write, retain as much unwritten data as the buffer can hold.
        if (ptr == buf.data() and n >= buf.size()) {
#if defined(KK2_FASTIO_POSIX)
            size_t written = 0;
            if (write_bytes(s, n, written)) [[likely]]
                return;
#else
            const size_t written = std::fwrite(s, 1, n, fp);
            if (written == n) [[likely]]
                return;
#endif
            s += written;
            n -= written;
            const size_t retained = std::min(n, buf.size());
            std::memcpy(buf.data(), s, retained);
            ptr = buf.data() + retained;
            has_failed = true;
            return;
        }
        const size_t remaining = static_cast<size_t>(buf_end - ptr);
        if (n <= remaining) [[likely]] {
            std::memcpy(ptr, s, n);
            ptr += n;
            return;
        }
        while (n != 0) {
            if (ptr == buf_end and !write_buffer()) [[unlikely]]
                return;
            const size_t count = std::min(n, static_cast<size_t>(buf_end - ptr));
            std::memcpy(ptr, s, count);
            ptr += count;
            s += count;
            n -= count;
        }
    }

    bool ensure_capacity(size_t n) {
        if (n <= static_cast<size_t>(buf_end - ptr)) [[likely]]
            return true;
        return write_buffer();
    }

    template <int N = 4> void put_leading_block(uint64_t x) {
        if constexpr (N > 1) {
            if (x < POW10<uint64_t>[N - 1]) {
                put_leading_block<N - 1>(x);
                return;
            }
        }
        ptr = std::copy_n(digit_blocks.data() + x * 4 + 4 - N, N, ptr);
    }

    template <int N> static constexpr uint64_t div_pow10(uint64_t x) {
        // Exact reciprocal multiplication for the fixed powers of ten.
        if constexpr (N == 0) return x;
        else if constexpr (N == 4)
            return static_cast<uint64_t>((__uint128_t{x} * 3777893186295716171ull) >> 64) >> 11;
        else if constexpr (N == 8)
            return static_cast<uint64_t>((__uint128_t{x} * 12379400392853802749ull) >> 64) >> 26;
        else if constexpr (N == 12)
            return static_cast<uint64_t>((__uint128_t{x} * 2535301200456458803ull) >> 64) >> 37;
        else {
            static_assert(N == 16);
            return static_cast<uint64_t>((__uint128_t{x} * 4153837486827862103ull) >> 64) >> 51;
        }
    }

    template <int N> void put_padded_blocks(uint64_t x) {
        if constexpr (N > 0) {
            constexpr uint64_t divisor = POW10<uint64_t>[N - 4];
            const uint64_t quotient = div_pow10<N - 4>(x);
            ptr = std::copy_n(digit_blocks.data() + quotient * 4, 4, ptr);
            put_padded_blocks<N - 4>(x - quotient * divisor);
        }
    }

    template <int N> void put_u64_blocks(uint64_t x) {
        if constexpr (N < DIGITS<uint64_t>) {
            if (x >= POW10<uint64_t>[N]) {
                put_u64_blocks<N + 4>(x);
                return;
            }
        }
        constexpr uint64_t divisor = POW10<uint64_t>[N - 4];
        const uint64_t quotient = div_pow10<N - 4>(x);
        put_leading_block(quotient);
        put_padded_blocks<N - 4>(x - quotient * divisor);
    }

    template <UnsignedIntegral T> void put_unsigned_blocks(T x) {
        if constexpr (sizeof(T) <= sizeof(uint64_t)) {
            put_u64_blocks<4>(static_cast<uint64_t>(x));
        } else {
            if (x < POW10<__uint128_t>[16]) {
                put_u64_blocks<4>(static_cast<uint64_t>(x));
            } else if (x < POW10<__uint128_t>[32]) {
                put_u64_blocks<4>(static_cast<uint64_t>(x / POW10<__uint128_t>[16]));
                put_padded_blocks<16>(static_cast<uint64_t>(x % POW10<__uint128_t>[16]));
            } else {
                put_u64_blocks<4>(static_cast<uint64_t>(x / POW10<__uint128_t>[32]));
                x %= POW10<__uint128_t>[32];
                put_padded_blocks<16>(static_cast<uint64_t>(x / POW10<__uint128_t>[16]));
                put_padded_blocks<16>(static_cast<uint64_t>(x % POW10<__uint128_t>[16]));
            }
        }
    }

    template <UnsignedIntegral T> void put_unsigned(T x) {
        if (!ensure_capacity(std::numeric_limits<T>::digits10 + 1)) return;
        put_unsigned_blocks(x);
    }

    template <SignedIntegral T> void put_signed(T x) {
        using U = typename to_unsigned<T>::type;
        if (!ensure_capacity(std::numeric_limits<T>::digits10 + 2)) return;
        if (x < 0) {
            *ptr++ = '-';
            put_unsigned_blocks(static_cast<U>(U{0} - static_cast<U>(x)));
        } else put_unsigned_blocks(static_cast<U>(x));
    }

  public:
    Printer() : fp(stdout) {
#if defined(KK2_FASTIO_POSIX)
        setup_posix();
#elif defined(KK2_FASTIO_UNBUFFERED) || defined(KK2_FASTIO_UNBUFFERED_OUTPUT)
        // Avoid the second stdio buffer when this stream is exclusively used here.
        std::setvbuf(fp, nullptr, _IONBF, 0);
#endif
    }

    explicit Printer(const char *file) : fp(open_file(file)), owns_file(true) {
#if defined(KK2_FASTIO_POSIX)
        setup_posix();
#endif
    }

    explicit Printer(FILE *file, bool take_ownership = false)
        : fp(check_file(file)),
          owns_file(take_ownership) {
#if defined(KK2_FASTIO_POSIX)
        setup_posix();
#endif
    }

    Printer(const Printer &) = delete;
    Printer &operator=(const Printer &) = delete;
    Printer(Printer &&) = delete;
    Printer &operator=(Printer &&) = delete;

    ~Printer() {
        write_buffer();
        if (owns_file) std::fclose(fp);
    }

    bool write() { return write_buffer(); }

    bool flush() {
        if (!write_buffer()) return false;
        if (std::fflush(fp) == 0) return true;
        has_failed = true;
        return false;
    }

    bool good() const { return !has_failed; }

    explicit operator bool() const { return good(); }

    void put_char(char c) {
        if (ptr == buf_end and !write_buffer()) [[unlikely]]
            return;
        *ptr++ = c;
    }

    void put_cstr(const char *s) {
        if (s == nullptr) {
            has_failed = true;
            return;
        }
        put_bytes(s, std::strlen(s));
    }

    void put_u32(uint32_t x) { put_unsigned(x); }

    void put_i32(int32_t x) { put_signed(x); }

    void put_u64(uint64_t x) { put_unsigned(x); }

    void put_i64(int64_t x) { put_signed(x); }

    void put_u128(__uint128_t x) { put_unsigned(x); }

    void put_i128(__int128_t x) { put_signed(x); }

    template <UnsignedIntegral T> Printer &operator<<(T x) {
        put_unsigned(x);
        return *this;
    }

    template <SignedIntegral T> Printer &operator<<(T x) {
        put_signed(x);
        return *this;
    }

    Printer &operator<<(char x) {
        put_char(x);
        return *this;
    }

    Printer &operator<<(std::string_view x) {
        put_bytes(x.data(), x.size());
        return *this;
    }

    Printer &operator<<(const std::string &x) {
        put_bytes(x.data(), x.size());
        return *this;
    }

    Printer &operator<<(const char *x) {
        put_cstr(x);
        return *this;
    }

    template <size_t N> Printer &operator<<(const char (&x)[N]) {
        put_bytes(x, N - 1);
        return *this;
    }

    Printer &operator<<(endl_struct_t) {
        put_char('\n');
        flush();
        return *this;
    }
};

} // namespace fastio

#if defined(INTERACTIVE) || defined(USE_STDIO)
inline auto &kin = std::cin;
inline auto &kout = std::cout;
inline auto (*kendl)(std::ostream &) = std::endl<char, std::char_traits<char>>;
#else
inline fastio::Scanner kin;
inline fastio::Printer kout;
inline constexpr fastio::endl_struct_t kendl{};
#endif

} // namespace kk2

#endif // KK2_TEMPLATE_FASTIO_HPP

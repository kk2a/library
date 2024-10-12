#ifndef TEMPLATE_FASTIO_HPP
#define TEMPLATE_FASTIO_HPP 1

#include <cctype>
#include <cstdint>
#include <cstdio>
#include <fstream>
#include <string>

namespace kk2 {

namespace fastio {

#define INPUT_FILE "in.txt"
#define OUTPUT_FILE "out.txt"

struct Scanner {
  private:
    static constexpr size_t INPUT_BUF = 1 << 17;
    size_t pos = INPUT_BUF;
    static char buf[INPUT_BUF];
    FILE *fp;

  public:
    Scanner() : fp(stdin) {}

    Scanner(const char *file) : fp(fopen(file, "r")) {}

    ~Scanner() {
        if (fp != stdin) fclose(fp);
    }

    char now() {
        if (pos == INPUT_BUF) {
            size_t len = fread(buf, 1, INPUT_BUF, fp);
            if (len != INPUT_BUF) buf[len] = '\0';
            pos = 0;
        }
        return buf[pos];
    }

    void skip_space() {
        while (isspace(now())) ++pos;
    }

    uint32_t next_u32() {
        skip_space();
        uint32_t res = 0;
        while (isdigit(now())) {
            res = res * 10 + (now() - '0');
            ++pos;
        }
        return res;
    }

    int32_t next_i32() {
        skip_space();
        if (now() == '-') {
            ++pos;
            return (int32_t)(-next_u32());
        } else return (int32_t)next_u32();
    }

    uint64_t next_u64() {
        skip_space();
        uint64_t res = 0;
        while (isdigit(now())) {
            res = res * 10 + (now() - '0');
            ++pos;
        }
        return res;
    }

    int64_t next_i64() {
        skip_space();
        if (now() == '-') {
            ++pos;
            return (int64_t)(-next_u64());
        } else return (int64_t)next_u64();
    }

    __uint128_t next_u128() {
        skip_space();
        __uint128_t res = 0;
        while (isdigit(now())) {
            res = res * 10 + (now() - '0');
            ++pos;
        }
        return res;
    }

    __int128_t next_i128() {
        skip_space();
        if (now() == '-') {
            ++pos;
            return (__int128_t)(-next_u128());
        } else return (__int128_t)next_u128();
    }

    char next_char() {
        skip_space();
        auto res = now();
        ++pos;
        return res;
    }

    std::string next_string() {
        skip_space();
        std::string res;
        while (true) {
            char c = now();
            if (isspace(c) or c == '\0') break;
            res.push_back(now());
            ++pos;
        }
        return res;
    }

    Scanner &operator>>(int &x) {
        x = next_i32();
        return *this;
    }

    Scanner &operator>>(unsigned int &x) {
        x = next_u32();
        return *this;
    }

    Scanner &operator>>(long &x) {
        x = next_i64();
        return *this;
    }

    Scanner &operator>>(long long &x) {
        x = next_i64();
        return *this;
    }

    Scanner &operator>>(unsigned long &x) {
        x = next_u64();
        return *this;
    }

    Scanner &operator>>(unsigned long long &x) {
        x = next_u64();
        return *this;
    }

    Scanner &operator>>(__int128_t &x) {
        x = next_i128();
        return *this;
    }

    Scanner &operator>>(__uint128_t &x) {
        x = next_u128();
        return *this;
    }

    Scanner &operator>>(char &x) {
        x = next_char();
        return *this;
    }

    Scanner &operator>>(std::string &x) {
        x = next_string();
        return *this;
    }
};

struct Printer {
  private:
    static char helper[1000][4];
    static char leading_zero[1000][4];
    constexpr static size_t OUTPUT_BUF = 1 << 17;
    static char buf[OUTPUT_BUF];
    size_t pos = 0;
    FILE *fp;

    static constexpr uint32_t pow10_32(uint32_t n) { return n == 0 ? 1 : pow10_32(n - 1) * 10; }

    static constexpr uint64_t pow10_64(uint32_t n) { return n == 0 ? 1 : pow10_64(n - 1) * 10; }

    static constexpr __uint128_t pow10_128(uint32_t n) {
        return n == 0 ? 1 : pow10_128(n - 1) * 10;
    }

    template <class T, class U> static constexpr void div_mod(T &a, U &b, U mod) {
        a = b / mod;
        b -= a * mod;
    }

    static void init() {
        buf[0] = '\0';
        for (size_t i = 0; i < 1000; ++i) {
            leading_zero[i][0] = i / 100 + '0';
            leading_zero[i][1] = i / 10 % 10 + '0';
            leading_zero[i][2] = i % 10 + '0';
            leading_zero[i][3] = '\0';

            size_t j = 0;
            if (i >= 100) helper[i][j++] = i / 100 + '0';
            if (i >= 10) helper[i][j++] = i / 10 % 10 + '0';
            helper[i][j++] = i % 10 + '0';
            helper[i][j] = '\0';
        }
    }

  public:
    Printer() : fp(stdout) { init(); }

    Printer(const char *file) : fp(fopen(file, "w")) { init(); }

    ~Printer() {
        write();
        if (fp != stdout) fclose(fp);
    }

    void write() {
        fwrite(buf, 1, pos, fp);
        pos = 0;
    }

    void put_char(char c) {
        if (pos == OUTPUT_BUF) write();
        buf[pos++] = c;
    }

    void put_cstr(const char *s) {
        while (*s) put_char(*(s++));
    }

    void put_u32(uint32_t x) {
        uint32_t y;
        if (x >= pow10_32(9)) {
            div_mod(y, x, pow10_32(9));
            put_cstr(helper[y]);
            div_mod(y, x, pow10_32(6));
            put_cstr(leading_zero[y]);
            div_mod(y, x, pow10_32(3));
            put_cstr(leading_zero[y]);
            put_cstr(leading_zero[x]);
        } else if (x >= pow10_32(6)) {
            div_mod(y, x, pow10_32(6));
            put_cstr(helper[y]);
            div_mod(y, x, pow10_32(3));
            put_cstr(leading_zero[y]);
            put_cstr(leading_zero[x]);
        } else if (x >= pow10_32(3)) {
            div_mod(y, x, pow10_32(3));
            put_cstr(helper[y]);
            put_cstr(leading_zero[x]);
        } else put_cstr(helper[x]);
    }

    void put_i32(int32_t x) {
        if (x < 0) {
            put_char('-');
            put_u32(-x);
        } else put_u32(x);
    }

    void put_u64(uint64_t x) {
        uint64_t y;
        if (x >= pow10_64(18)) {
            div_mod(y, x, pow10_64(18));
            put_cstr(helper[y]);
            div_mod(y, x, pow10_64(15));
            put_cstr(leading_zero[y]);
            div_mod(y, x, pow10_64(12));
            put_cstr(leading_zero[y]);
            div_mod(y, x, pow10_64(9));
            put_cstr(leading_zero[y]);
            div_mod(y, x, pow10_64(6));
            put_cstr(leading_zero[y]);
            div_mod(y, x, pow10_64(3));
            put_cstr(leading_zero[y]);
            put_cstr(leading_zero[x]);
        } else if (x >= pow10_64(9)) {
            div_mod(y, x, pow10_64(9));
            put_u32(uint32_t(y));
            div_mod(y, x, pow10_64(6));
            put_cstr(leading_zero[y]);
            div_mod(y, x, pow10_64(3));
            put_cstr(leading_zero[y]);
            put_cstr(leading_zero[x]);
        } else put_u32(uint32_t(x));
    }

    void put_i64(int64_t x) {
        if (x < 0) {
            put_char('-');
            put_u64(-x);
        } else put_u64(x);
    }

    void put_u128(__uint128_t x) {
        __uint128_t y;
        if (x >= pow10_128(36)) {
            div_mod(y, x, pow10_128(36));
            put_cstr(helper[y]);
            div_mod(y, x, pow10_128(33));
            put_cstr(leading_zero[y]);
            div_mod(y, x, pow10_128(30));
            put_cstr(leading_zero[y]);
            div_mod(y, x, pow10_128(27));
            put_cstr(leading_zero[y]);
            div_mod(y, x, pow10_128(24));
            put_cstr(leading_zero[y]);
            div_mod(y, x, pow10_128(21));
            put_cstr(leading_zero[y]);
            div_mod(y, x, pow10_128(18));
            put_cstr(leading_zero[y]);
            div_mod(y, x, pow10_128(15));
            put_cstr(leading_zero[y]);
            div_mod(y, x, pow10_128(12));
            put_cstr(leading_zero[y]);
            div_mod(y, x, pow10_128(9));
            put_cstr(leading_zero[y]);
            div_mod(y, x, pow10_128(6));
            put_cstr(leading_zero[y]);
            div_mod(y, x, pow10_128(3));
            put_cstr(leading_zero[y]);
            put_cstr(leading_zero[x]);
        } else if (x >= pow10_128(18)) {
            div_mod(y, x, pow10_128(18));
            put_u64(uint64_t(y));
            div_mod(y, x, pow10_128(15));
            put_cstr(leading_zero[y]);
            div_mod(y, x, pow10_128(12));
            put_cstr(leading_zero[y]);
            div_mod(y, x, pow10_128(9));
            put_cstr(leading_zero[y]);
            div_mod(y, x, pow10_128(6));
            put_cstr(leading_zero[y]);
            div_mod(y, x, pow10_128(3));
            put_cstr(leading_zero[y]);
            put_cstr(leading_zero[x]);
        } else put_u64(uint64_t(x));
    }

    void put_i128(__int128_t x) {
        if (x < 0) {
            put_char('-');
            put_u128(-x);
        } else put_u128(x);
    }

    Printer &operator<<(int x) {
        put_i32(x);
        return *this;
    }

    Printer &operator<<(unsigned int x) {
        put_u32(x);
        return *this;
    }

    Printer &operator<<(long x) {
        put_i64(x);
        return *this;
    }

    Printer &operator<<(long long x) {
        put_i64(x);
        return *this;
    }

    Printer &operator<<(unsigned long x) {
        put_u64(x);
        return *this;
    }

    Printer &operator<<(unsigned long long x) {
        put_u64(x);
        return *this;
    }

    Printer &operator<<(__int128_t x) {
        put_i128(x);
        return *this;
    }

    Printer &operator<<(__uint128_t x) {
        put_u128(x);
        return *this;
    }

    Printer &operator<<(char x) {
        put_char(x);
        return *this;
    }

    Printer &operator<<(const std::string &x) {
        for (char c : x) put_char(c);
        return *this;
    }

    Printer &operator<<(const char *x) {
        put_cstr(x);
        return *this;
    }
};

char Scanner::buf[Scanner::INPUT_BUF];
char Printer::buf[Printer::OUTPUT_BUF];
char Printer::helper[1000][4];
char Printer::leading_zero[1000][4];

} // namespace fastio

} // namespace kk2

#if defined(INTERACTIVE) || defined(USE_STDIO)
struct IoSetUp {
    IoSetUp() {
        std::cin.tie(nullptr);
        std::ios::sync_with_stdio(false);
    }
} iosetup;
#define kin std::cin
#define kout std::cout
#elif defined(KK2)
kk2::fastio::Scanner kin(INPUT_FILE);
kk2::fastio::Printer kout(OUTPUT_FILE);
#define endl '\n'
#else
kk2::fastio::Scanner kin;
kk2::fastio::Printer kout;
#define endl '\n'
#endif

#endif // TEMPLATE_FASTIO_HPP

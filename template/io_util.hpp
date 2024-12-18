#ifndef TEMPLATE_IO_UTIL_HPP
#define TEMPLATE_IO_UTIL_HPP 1

#include <array>
#include <utility>
#include <vector>

#include "../type_traits/type_traits.hpp"

// なんかoj verifyはプロトタイプ宣言が落ちる

namespace impl {

struct read {
    template <class IStream, class T>
    static void all_read(IStream &is, T &x) {
        is >> x;
    }

    template <class IStream, class T, class U>
    static void all_read(IStream &is, std::pair<T, U> &p) {
        all_read(is, p.first);
        all_read(is, p.second);
    }

    template <class IStream, class T>
    static void all_read(IStream &is, std::vector<T> &v) {
        for (T &x : v) all_read(is, x);
    }

    template <class IStream, class T, size_t F>
    static void all_read(IStream &is, std::array<T, F> &a) {
        for (T &x : a) all_read(is, x);
    }
};

struct write {
    template <class OStream, class T>
    static void all_write(OStream &os, const T &x) {
        os << x;
    }

    template <class OStream, class T, class U>
    static void all_write(OStream &os, const std::pair<T, U> &p) {
        all_write(os, p.first);
        all_write(os, ' ');
        all_write(os, p.second);
    }

    template <class OStream, class T>
    static void all_write(OStream &os, const std::vector<T> &v) {
        for (int i = 0; i < (int)v.size(); ++i) {
            if (i) all_write(os, ' ');
            all_write(os, v[i]);
        }
    }

    template <class OStream, class T, size_t F>
    static void all_write(OStream &os, const std::array<T, F> &a) {
        for (int i = 0; i < (int)F; ++i) {
            if (i) all_write(os, ' ');
            all_write(os, a[i]);
        }
    }
};

} // namespace impl

template <class IStream, class T, kk2::is_istream_t<IStream> * = nullptr>
IStream &operator>>(IStream &is, T &x) {
    impl::read::all_read(is, x);
    return is;
}

template <class OStream, class T, kk2::is_ostream_t<OStream> * = nullptr>
OStream &operator<<(OStream &os, const T &x) {
    impl::write::all_write(os, x);
    return os;
}

#endif // TEMPLATE_IO_UTIL_HPP

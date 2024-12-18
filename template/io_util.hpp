#ifndef TEMPLATE_IO_UTIL_HPP
#define TEMPLATE_IO_UTIL_HPP 1

#include <array>
#include <utility>
#include <vector>

#include "../type_traits/type_traits.hpp"

// template <class IStream, class T, class U, kk2::is_istream_t<IStream> *>
// IStream &operator>>(IStream &is, std::pair<T, U> &p);

// template <class OStream, class T, class U, kk2::is_ostream_t<OStream> *>
// OStream &operator<<(OStream &os, const std::pair<T, U> &p);

// template <class IStream, class T, kk2::is_istream_t<IStream> *>
// IStream &operator>>(IStream &is, std::vector<T> &v);

// template <class OStream, class T, kk2::is_ostream_t<OStream> *>
// OStream &operator<<(OStream &os, const std::vector<T> &v);

// template <class IStream, class T, size_t F, kk2::is_istream_t<IStream> *>
// IStream &operator>>(IStream &is, std::array<T, F> &a);

// template <class OStream, class T, size_t F, kk2::is_ostream_t<OStream> *>
// OStream &operator<<(OStream &os, const std::array<T, F> &a);

template <class IStream, class T, class U, kk2::is_istream_t<IStream> * = nullptr>
IStream &operator>>(IStream &is, std::pair<T, U> &p) {
    is >> p.first >> p.second;
    return is;
}

template <class OStream, class T, class U, kk2::is_ostream_t<OStream> * = nullptr>
OStream &operator<<(OStream &os, const std::pair<T, U> &p) {
    os << p.first << ' ' << p.second;
    return os;
}

template <class IStream, class T, kk2::is_istream_t<IStream> * = nullptr>
IStream &operator>>(IStream &is, std::vector<T> &v) {
    for (T &x : v) is >> x;
    return is;
}

template <class OStream, class T, kk2::is_ostream_t<OStream> * = nullptr>
OStream &operator<<(OStream &os, const std::vector<T> &v) {
    for (int i = 0; i < (int)v.size(); i++) { os << v[i] << (i + 1 == (int)v.size() ? "" : " "); }
    return os;
}

template <class IStream, class T, size_t F, kk2::is_istream_t<IStream> * = nullptr>
IStream &operator>>(IStream &is, std::array<T, F> &a) {
    for (auto &x : a) is >> x;
    return is;
}

template <class OStream, class T, size_t F, kk2::is_ostream_t<OStream> * = nullptr>
OStream &operator<<(OStream &os, const std::array<T, F> &a) {
    for (int i = 0; i < (int)F; i++) { os << a[i] << (i + 1 == (int)F ? "" : " "); }
    return os;
}

#endif // TEMPLATE_IO_UTIL_HPP

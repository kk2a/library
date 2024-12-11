#ifndef TEMPLATE_DEBUG_HPP
#define TEMPLATE_DEBUG_HPP 1

#include <array>
#include <deque>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

#include "../type_traits/type_traits.hpp"

namespace kk2 {

namespace debug {

#ifdef KK2

template <class OStream, is_ostream_t<OStream> * = nullptr> void output(OStream &os) {
}

template <class OStream, class T, is_ostream_t<OStream> * = nullptr>
void output(OStream &os, const T &t) {
    os << t;
}

template <class OStream, class T, is_ostream_t<OStream> * = nullptr>
void output(OStream &os, const std::vector<T> &v) {
    os << "[";
    for (int i = 0; i < (int)v.size(); i++) {
        os << v[i];
        if (i + 1 != (int)v.size()) os << ", ";
    }
    os << "]";
}

template <class OStream, class T, size_t F, is_ostream_t<OStream> * = nullptr>
void output(OStream &os, const std::array<T, F> &a) {
    os << "[";
    for (int i = 0; i < (int)F; i++) {
        os << a[i];
        if (i + 1 != (int)F) os << ", ";
    }
    os << "]";
}
    
template <class OStream, class T, class U, is_ostream_t<OStream> * = nullptr>
void output(OStream &os, const std::pair<T, U> &p) {
    os << "(";
    os << p.first << ", " << p.second;
    os << ")";
}

template <class OStream, class T, is_ostream_t<OStream> * = nullptr>
void output(OStream &os, const std::queue<T> &q) {
    os << "[";
    std::queue<T> tmp = q;
    while (!tmp.empty()) {
        os << tmp.front();
        tmp.pop();
        if (!tmp.empty()) os << ", ";
    }
    os << "]";
}

template <class OStream, class T, class Container, class Compare, is_ostream_t<OStream> * = nullptr>
void output(OStream &os, const std::priority_queue<T, Container, Compare> &q) {
    os << "[";
    std::priority_queue<T, Container, Compare> tmp = q;
    while (!tmp.empty()) {
        os << tmp.top();
        tmp.pop();
        if (!tmp.empty()) os << ", ";
    }
    os << "]";
}

template <class OStream, class T, is_ostream_t<OStream> * = nullptr>
void output(OStream &os, const std::deque<T> &d) {
    os << "[";
    std::deque<T> tmp = d;
    while (!tmp.empty()) {
        os << tmp.front();
        tmp.pop_front();
        if (!tmp.empty()) os << ", ";
    }
    os << "]";
}

template <class OStream, class T, is_ostream_t<OStream> * = nullptr>
void output(OStream &os, const std::stack<T> &s) {
    os << "[";
    std::stack<T> tmp = s;
    std::vector<T> v;
    while (!tmp.empty()) {
        v.push_back(tmp.top());
        tmp.pop();
    }
    for (int i = (int)v.size() - 1; i >= 0; i--) {
        os << v[i];
        if (i != 0) os << ", ";
    }
    os << "]";
}

template <class OStream,
          class Key,
          class Compare,
          class Allocator,
          is_ostream_t<OStream> * = nullptr>
void output(OStream &os, const std::set<Key, Compare, Allocator> &s) {
    os << "{";
    std::set<Key, Compare, Allocator> tmp = s;
    for (auto it = tmp.begin(); it != tmp.end(); ++it) {
        os << *it;
        if (std::next(it) != tmp.end()) os << ", ";
    }
    os << "}";
}

template <class OStream,
          class Key,
          class Compare,
          class Allocator,
          is_ostream_t<OStream> * = nullptr>
void output(OStream &os, const std::multiset<Key, Compare, Allocator> &s) {
    os << "{";
    std::multiset<Key, Compare, Allocator> tmp = s;
    for (auto it = tmp.begin(); it != tmp.end(); ++it) {
        os << *it;
        if (std::next(it) != tmp.end()) os << ", ";
    }
    os << "}";
}

template <class OStream,
          class Key,
          class Hash,
          class KeyEqual,
          class Allocator,
          is_ostream_t<OStream> * = nullptr>
void output(OStream &os, const std::unordered_set<Key, Hash, KeyEqual, Allocator> &s) {
    os << "{";
    std::unordered_set<Key, Hash, KeyEqual, Allocator> tmp = s;
    for (auto it = tmp.begin(); it != tmp.end(); ++it) {
        os << *it;
        if (std::next(it) != tmp.end()) os << ", ";
    }
    os << "}";
}

template <class OStream,
          class Key,
          class Hash,
          class KeyEqual,
          class Allocator,
          is_ostream_t<OStream> * = nullptr>
void output(OStream &os, const std::unordered_multiset<Key, Hash, KeyEqual, Allocator> &s) {
    os << "{";
    std::unordered_multiset<Key, Hash, KeyEqual, Allocator> tmp = s;
    for (auto it = tmp.begin(); it != tmp.end(); ++it) {
        os << *it;
        if (std::next(it) != tmp.end()) os << ", ";
    }
    os << "}";
}

template <class OStream,
          class Key,
          class T,
          class Compare,
          class Allocator,
          is_ostream_t<OStream> * = nullptr>
void output(OStream &os, const std::map<Key, T, Compare, Allocator> &m) {
    os << "{";
    std::map<Key, T, Compare, Allocator> tmp = m;
    for (auto it = tmp.begin(); it != tmp.end(); ++it) {
        os << it->first << ": " << it->second;
        if (std::next(it) != tmp.end()) os << ", ";
    }
    os << "}";
}

template <class OStream,
          class Key,
          class T,
          class Hash,
          class KeyEqual,
          class Allocator,
          is_ostream_t<OStream> * = nullptr>
void output(OStream &os, const std::unordered_map<Key, T, Hash, KeyEqual, Allocator> &m) {
    os << "{";
    std::unordered_map<Key, T, Hash, KeyEqual, Allocator> tmp = m;
    for (auto it = tmp.begin(); it != tmp.end(); ++it) {
        os << it->first << ": " << it->second;
        if (std::next(it) != tmp.end()) os << ", ";
    }
    os << "}";
}

template <class OStream, class T, class... Args, is_ostream_t<OStream> * = nullptr>
void output(OStream &os, const T &t, const Args &...args) {
    output(os, t);
    os << ' ';
    output(os, args...);
}

template <class OStream, class... Args, is_ostream_t<OStream> * = nullptr>
void outputln(OStream &os, const Args &...args) {
    output(os, args...);
    os << '\n';
}

#else
template <class OStream, class... Args, is_ostream_t<OStream> * = nullptr>
void output(OStream &os, const Args &...args) {
}

template <class OStream, class... Args, is_ostream_t<OStream> * = nullptr>
void outputln(OStream &os, const Args &...args) {
}

#endif // KK2

} // namespace debug

} // namespace kk2

#endif // TEMPLATE_DEBUG_HPP

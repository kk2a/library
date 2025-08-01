#ifndef KK2_TEMPLATE_DEBUG_HPP
#define KK2_TEMPLATE_DEBUG_HPP 1

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

#include "../type_traits/io.hpp"
#include "../type_traits/member.hpp"

namespace kk2 {

namespace debug {

#ifdef KK2

template <class OStream, is_ostream_t<OStream> *> void output(OStream &os);
template <class OStream, class T, is_ostream_t<OStream> *> void output(OStream &os, const T &t);
template <class OStream, class T, is_ostream_t<OStream> *>
void output(OStream &os, const std::vector<T> &v);
template <class OStream, class T, is_ostream_t<OStream> *>
void output(OStream &os, const std::vector<std::vector<T>> &d);
template <class OStream, class T, size_t F, is_ostream_t<OStream> *>
void output(OStream &os, const std::array<T, F> &a);
template <class OStream, class T, class U, is_ostream_t<OStream> *>
void output(OStream &os, const std::pair<T, U> &p);
template <class OStream, class T, is_ostream_t<OStream> *>
void output(OStream &os, const std::queue<T> &q);
template <class OStream, class T, class Container, class Compare, is_ostream_t<OStream> *>
void output(OStream &os, const std::priority_queue<T, Container, Compare> &q);
template <class OStream, class T, is_ostream_t<OStream> *>
void output(OStream &os, const std::deque<T> &d);
template <class OStream, class T, is_ostream_t<OStream> *>
void output(OStream &os, const std::stack<T> &s);
template <class OStream, class Key, class Compare, class Allocator, is_ostream_t<OStream> *>
void output(OStream &os, const std::set<Key, Compare, Allocator> &s);
template <class OStream, class Key, class Compare, class Allocator, is_ostream_t<OStream> *>
void output(OStream &os, const std::multiset<Key, Compare, Allocator> &s);
template <class OStream,
          class Key,
          class Hash,
          class KeyEqual,
          class Allocator,
          is_ostream_t<OStream> *>
void output(OStream &os, const std::unordered_set<Key, Hash, KeyEqual, Allocator> &s);
template <class OStream,
          class Key,
          class Hash,
          class KeyEqual,
          class Allocator,
          is_ostream_t<OStream> *>
void output(OStream &os, const std::unordered_multiset<Key, Hash, KeyEqual, Allocator> &s);
template <class OStream,
          class Key,
          class T,
          class Compare,
          class Allocator,
          is_ostream_t<OStream> *>
void output(OStream &os, const std::map<Key, T, Compare, Allocator> &m);
template <class OStream,
          class Key,
          class T,
          class Hash,
          class KeyEqual,
          class Allocator,
          is_ostream_t<OStream> *>
void output(OStream &os, const std::unordered_map<Key, T, Hash, KeyEqual, Allocator> &m);
template <class OStream, is_ostream_t<OStream> * = nullptr> void output(OStream &) {}

template <class OStream, class T, is_ostream_t<OStream> * = nullptr>
void output(OStream &os, const T &t) {
    if constexpr (has_member_func_debug_output<T, OStream &>::value) {
        t.debug_output(os);
    } else {
        os << t;
    }
}

template <class OStream, class T, is_ostream_t<OStream> * = nullptr>
void output(OStream &os, const std::vector<T> &v) {
    os << "[";
    for (int i = 0; i < (int)v.size(); i++) {
        output(os, v[i]);
        if (i + 1 != (int)v.size()) os << ", ";
    }
    os << "]";
}

template <class OStream, class T, is_ostream_t<OStream> * = nullptr>
void output(OStream &os, const std::vector<std::vector<T>> &d) {
    os << "[\n";
    for (int i = 0; i < (int)d.size(); i++) {
        output(os, d[i]);
        output(os, "\n");
    }
    os << "]";
}

template <class OStream, class T, size_t F, is_ostream_t<OStream> * = nullptr>
void output(OStream &os, const std::array<T, F> &a) {
    os << "[";
    for (int i = 0; i < (int)F; i++) {
        output(os, a[i]);
        if (i + 1 != (int)F) os << ", ";
    }
    os << "]";
}

template <class OStream, class T, class U, is_ostream_t<OStream> * = nullptr>
void output(OStream &os, const std::pair<T, U> &p) {
    os << "(";
    output(os, p.first);
    os << ", ";
    output(os, p.second);
    os << ")";
}

template <class OStream, class T, is_ostream_t<OStream> * = nullptr>
void output(OStream &os, const std::queue<T> &q) {
    os << "[";
    std::queue<T> tmp = q;
    while (!tmp.empty()) {
        output(os, tmp.front());
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
        output(os, tmp.top());
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
        output(os, tmp.front());
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
        output(os, v[i]);
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
        output(os, *it);
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
        output(os, *it);
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
        output(os, *it);
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
        output(os, *it);
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
        output(os, it->first);
        os << ": ";
        output(os, it->second);
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
        output(os, it->first);
        os << ": ";
        output(os, it->second);
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

template <class OStream, is_ostream_t<OStream> * = nullptr> void outputln(OStream &os) {
    os << '\n';
    os.flush();
}

template <class OStream, class T, class... Args, is_ostream_t<OStream> * = nullptr>
void outputln(OStream &os, const T &t, const Args &...args) {
    output(os, t, args...);
    os << '\n';
    os.flush();
}

std::vector<std::string> sep(const char *s) {
    std::vector<std::string> res;
    std::string now;
    int dep = 0;
    while (true) {
        if (*s == '\0') {
            res.emplace_back(now);
            break;
        }
        if (*s == '(' or *s == '[' or *s == '{') dep++;
        if (*s == ')' or *s == ']' or *s == '}') dep--;
        if (dep == 0 and *s == ',') {
            res.emplace_back(now);
            now.clear();
        } else if (!isspace(*s)) {
            now += *s;
        }
        s++;
    }
    return res;
}

void show_vars(const std::vector<std::string> &, int) {}

template <class T, class... Args>
void show_vars(const std::vector<std::string> &name, int pos, const T &t, const Args &...args) {
    // assert(pos < (int)name.size());
    output(std::cerr, name[pos++] + ":", t);
    if (sizeof...(args) > 0) output(std::cerr, ", ");
    show_vars(name, pos, args...);
}

#define kdebug(...)                                                                                \
    std::cerr << "line:" << __LINE__ << ' ';                                                       \
    kk2::debug::show_vars(kk2::debug::sep(#__VA_ARGS__), 0, __VA_ARGS__);                          \
    std::cerr << std::endl;

#define kput(s)                                                                                    \
    std::cerr << "line:" << __LINE__ << ' ';                                                       \
    kk2::debug::outputln(std::cerr, s);

#else

template <class OStream, class... Args, is_ostream_t<OStream> * = nullptr>
void output(OStream &, const Args &...) {}

template <class OStream, class... Args, is_ostream_t<OStream> * = nullptr>
void outputln(OStream &, const Args &...) {}

template <class... Args> void fix_warn(const Args &...) {}

#define kdebug(...) kk2::debug::fix_warn(__VA_ARGS__);

#define kput(s) kk2::debug::fix_warn(s)

#endif // KK2

} // namespace debug

} // namespace kk2

#endif // KK2_TEMPLATE_DEBUG_HPP

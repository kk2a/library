---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"string/suffix_array.hpp\"\n\n\n\nnamespace kk2 {\n\nstruct\
    \ SuffixArray {\n    SuffixArray() = default;\n    SuffixArray(const string& s_)\
    \ :\n        _n((int)s_.size()), _s((int)s_.size()) {\n        for (int i = 0;\
    \ i < _n; ++i) _s[i] = s_[i];\n        _upper = 255;\n        init();\n    }\n\
    \    // all elements of s_ must be in [0, upper]\n    SuffixArray(const vector<int>&\
    \ s_, int upper_) :\n        _n((int)s_.size()), _s(s_), _upper(upper_) {\n  \
    \      init();\n    }\n    template <class T>\n    SuffixArray(const vector<T>&\
    \ s_) :\n        _n((int)s_.size()), _s((int)s_.size()) {\n        vector<int>\
    \ idx(_n);\n        iota(begin(idx), end(idx), 0);\n        sort(begin(idx), end(idx),\
    \ [&](int l, int r) { return s_[l] < s_[r]; });\n        _upper = 0;\n       \
    \ for (int i = 0; i < _n; ++i) {\n            if (i && s_[idx[i - 1]] != s_[idx[i]])\
    \ _upper++;\n            _s[idx[i]] = _upper;\n        }\n        init();\n  \
    \  }\n\n    vector<int> GetSA() const { return _sa; }\n\n    bool op(int i, const\
    \ string& t) const {\n        int off = _sa[i];\n        int m = min(_n - off,\
    \ (int)t.size());\n        for (int j = 0; j < m; ++j) {\n            if (_s[off\
    \ + j] != t[j]) return _s[off + j] < t[j];\n        }\n        return _n - off\
    \ < (int)t.size();\n    }\n\n    bool op(int i, const vector<int>& t) const {\n\
    \        int off = _sa[i];\n        int m = min(_n - off, (int)t.size());\n  \
    \      for (int j = 0; j < m; ++j) {\n            if (_s[off + j] != t[j]) return\
    \ _s[off + j] < t[j];\n        }\n        return _n - off < (int)t.size();\n \
    \   }\n\n    // return the smallest index i s.t. s[sa[i]:] >= t\n    int lower_bound(const\
    \ vector<int>& t) const {\n        int l = -1, r = _n;\n        while (r - l >\
    \ 1) {\n            int m = (l + r) / 2;\n            if (op(m, t)) l = m;\n \
    \           else r = m;\n        }\n        return r;\n    }\n\n    int lower_bound(const\
    \ string& t) const {\n        int l = -1, r = _n;\n        while (r - l > 1) {\n\
    \            int m = (l + r) / 2;\n            if (op(m, t)) l = m;\n        \
    \    else r = m;\n        }\n        return r;\n    }\n\n  private:\n    int _n,\
    \ _upper;\n    vector<int> _sa, _s;\n\n    vector<int> sa_naive(const vector<int>&\
    \ s) {\n        int n = (int)s.size();\n        vector<int> sa(n);\n        iota(begin(sa),\
    \ end(sa), 0);\n        sort(begin(sa), end(sa), [&](int l, int r) {\n       \
    \     if (l == r) return false;\n            while (l < n && r < n) {\n      \
    \          if (s[l] != s[r]) return s[l] < s[r];\n                l++;\n     \
    \           r++;\n            }\n            return l == n;\n        });\n   \
    \     return sa;\n    }\n\n    vector<int> sa_doubling(const vector<int>& s, int\
    \ upper) {\n        int n = (int)s.size();\n        vector<int> sa(n), cpy = s,\
    \ tmp(n);\n        iota(begin(sa), end(sa), 0);\n        for (int len = 1; len\
    \ < n; len <<= 1) {\n            auto Compare = [&](int x, int y) {\n        \
    \        if (cpy[x] != cpy[y]) return cpy[x] < cpy[y];\n                int rx\
    \ = x + len < n ? cpy[x + len] : -1;\n                int ry = y + len < n ? cpy[y\
    \ + len] : -1;\n                return rx < ry;\n            };\n            sort(begin(sa),\
    \ end(sa), Compare);\n            tmp[sa[0]] = 0;\n            for (int i = 1;\
    \ i < n; i++) {\n                tmp[sa[i]] = tmp[sa[i - 1]] + (Compare(sa[i -\
    \ 1], sa[i]) ? 1 : 0);\n            }\n            swap(cpy, tmp);\n        }\n\
    \        return sa;\n    }\n\n    template <int THRESHOLD_NAIVE=10, int THRESHOLD_DOUBLING=40>\n\
    \    vector<int> sa_is(const vector<int>& s, int upper) {\n        int n = (int)s.size();\n\
    \        if (n == 0) return {};\n        if (n == 1) return {0};\n        if (n\
    \ == 2) {\n            if (s[0] < s[1]) return {0, 1};\n            else return\
    \ {1, 0};\n        }\n        if (n < THRESHOLD_NAIVE) return sa_naive(s);\n \
    \       if (n < THRESHOLD_DOUBLING) return sa_doubling(s, upper);\n\n        vector<int>\
    \ sa(n);\n        vector<bool> ls(n);\n        for (int i = n - 2; i >= 0; i--)\
    \ {\n            ls[i] = (s[i] == s[i + 1]) ? ls[i + 1] : (s[i] < s[i + 1]);\n\
    \        }\n        vector<int> sum_l(upper + 1), sum_s(upper + 1);\n        for\
    \ (int i = 0; i < n; i++) {\n            if (!ls[i]) sum_s[s[i]]++;\n        \
    \    else sum_l[s[i] + 1]++;\n        }\n        for (int i = 0; i <= upper; i++)\
    \ {\n            sum_s[i] += sum_l[i];\n            if (i < upper) sum_l[i + 1]\
    \ += sum_s[i];\n        }\n\n        auto induce = [&](const vector<int>& lms)\
    \ {\n            fill(begin(sa), end(sa), -1);\n            vector<int> buf(upper\
    \ + 1);\n            copy(begin(sum_s), end(sum_s), begin(buf));\n           \
    \ for (auto d : lms) {\n                if (d == n) continue;\n              \
    \  sa[buf[s[d]]++] = d;\n            }\n            copy(begin(sum_l), end(sum_l),\
    \ begin(buf));\n            sa[buf[s[n - 1]]++] = n - 1;\n            for (int\
    \ i = 0; i < n; i++) {\n                int v = sa[i];\n                if (v\
    \ >= 1 && !ls[v - 1]) {\n                    sa[buf[s[v - 1]]++] = v - 1;\n  \
    \              }\n            }\n            copy(begin(sum_l), end(sum_l), begin(buf));\n\
    \            for (int i = n - 1; i >= 0; i--) {\n                int v = sa[i];\n\
    \                if (v >= 1 && ls[v - 1]) {\n                    sa[--buf[s[v\
    \ - 1] + 1]] = v - 1;\n                }\n            }\n        };\n\n      \
    \  vector<int> lms_map(n + 1, -1);\n        int m = 0;\n        for (int i = 1;\
    \ i < n; i++) {\n            if (!ls[i - 1] && ls[i]) lms_map[i] = m++;\n    \
    \    }\n        vector<int> lms;\n        lms.reserve(m);\n        for (int i\
    \ = 1; i < n; i++) {\n            if (!ls[i - 1] && ls[i]) {\n               \
    \ lms.push_back(i);\n            }\n        }\n\n        induce(lms);\n\n    \
    \    if (m) {\n            vector<int> sorted_lms;\n            sorted_lms.reserve(m);\n\
    \            for (int v : sa) {\n                if (lms_map[v] != -1) sorted_lms.push_back(v);\n\
    \            }\n            vector<int> rec_s(m);\n            int rec_upper =\
    \ 0;\n            rec_s[lms_map[sorted_lms[0]]] = 0;\n            for (int i =\
    \ 1; i < m; i++) {\n                int l = sorted_lms[i - 1], r = sorted_lms[i];\n\
    \                int end_l = (lms_map[l] + 1 < m) ? lms[lms_map[l] + 1] : n;\n\
    \                int end_r = (lms_map[r] + 1 < m) ? lms[lms_map[r] + 1] : n;\n\
    \                bool same = true;\n                if (end_l - l != end_r - r)\
    \ {\n                    same = false;\n                } else {\n           \
    \         while (l < end_l) {\n                        if (s[l] != s[r]) break;\n\
    \                        l++;\n                        r++;\n                \
    \    }\n                    if (l == n || s[l] != s[r]) same = false;\n      \
    \          }\n                if (!same) rec_upper++;\n                rec_s[lms_map[sorted_lms[i]]]\
    \ = rec_upper;\n            }\n\n            vector<int> rec_sa =\n          \
    \      sa_is<THRESHOLD_NAIVE, THRESHOLD_DOUBLING>(rec_s, rec_upper);\n\n     \
    \       for (int i = 0; i < m; i++) {\n                sorted_lms[i] = lms[rec_sa[i]];\n\
    \            }\n            induce(sorted_lms);\n        }\n        return sa;\n\
    \    }\n\n    void init() { _sa = sa_is(_s, _upper); }\n};\n\n} // namespace kk2\n\
    \n\n"
  code: "#ifndef STRING_SUFFIX_ARRAY_HPP\n#define STRING_SUFFIX_ARRAY_HPP 1\n\nnamespace\
    \ kk2 {\n\nstruct SuffixArray {\n    SuffixArray() = default;\n    SuffixArray(const\
    \ string& s_) :\n        _n((int)s_.size()), _s((int)s_.size()) {\n        for\
    \ (int i = 0; i < _n; ++i) _s[i] = s_[i];\n        _upper = 255;\n        init();\n\
    \    }\n    // all elements of s_ must be in [0, upper]\n    SuffixArray(const\
    \ vector<int>& s_, int upper_) :\n        _n((int)s_.size()), _s(s_), _upper(upper_)\
    \ {\n        init();\n    }\n    template <class T>\n    SuffixArray(const vector<T>&\
    \ s_) :\n        _n((int)s_.size()), _s((int)s_.size()) {\n        vector<int>\
    \ idx(_n);\n        iota(begin(idx), end(idx), 0);\n        sort(begin(idx), end(idx),\
    \ [&](int l, int r) { return s_[l] < s_[r]; });\n        _upper = 0;\n       \
    \ for (int i = 0; i < _n; ++i) {\n            if (i && s_[idx[i - 1]] != s_[idx[i]])\
    \ _upper++;\n            _s[idx[i]] = _upper;\n        }\n        init();\n  \
    \  }\n\n    vector<int> GetSA() const { return _sa; }\n\n    bool op(int i, const\
    \ string& t) const {\n        int off = _sa[i];\n        int m = min(_n - off,\
    \ (int)t.size());\n        for (int j = 0; j < m; ++j) {\n            if (_s[off\
    \ + j] != t[j]) return _s[off + j] < t[j];\n        }\n        return _n - off\
    \ < (int)t.size();\n    }\n\n    bool op(int i, const vector<int>& t) const {\n\
    \        int off = _sa[i];\n        int m = min(_n - off, (int)t.size());\n  \
    \      for (int j = 0; j < m; ++j) {\n            if (_s[off + j] != t[j]) return\
    \ _s[off + j] < t[j];\n        }\n        return _n - off < (int)t.size();\n \
    \   }\n\n    // return the smallest index i s.t. s[sa[i]:] >= t\n    int lower_bound(const\
    \ vector<int>& t) const {\n        int l = -1, r = _n;\n        while (r - l >\
    \ 1) {\n            int m = (l + r) / 2;\n            if (op(m, t)) l = m;\n \
    \           else r = m;\n        }\n        return r;\n    }\n\n    int lower_bound(const\
    \ string& t) const {\n        int l = -1, r = _n;\n        while (r - l > 1) {\n\
    \            int m = (l + r) / 2;\n            if (op(m, t)) l = m;\n        \
    \    else r = m;\n        }\n        return r;\n    }\n\n  private:\n    int _n,\
    \ _upper;\n    vector<int> _sa, _s;\n\n    vector<int> sa_naive(const vector<int>&\
    \ s) {\n        int n = (int)s.size();\n        vector<int> sa(n);\n        iota(begin(sa),\
    \ end(sa), 0);\n        sort(begin(sa), end(sa), [&](int l, int r) {\n       \
    \     if (l == r) return false;\n            while (l < n && r < n) {\n      \
    \          if (s[l] != s[r]) return s[l] < s[r];\n                l++;\n     \
    \           r++;\n            }\n            return l == n;\n        });\n   \
    \     return sa;\n    }\n\n    vector<int> sa_doubling(const vector<int>& s, int\
    \ upper) {\n        int n = (int)s.size();\n        vector<int> sa(n), cpy = s,\
    \ tmp(n);\n        iota(begin(sa), end(sa), 0);\n        for (int len = 1; len\
    \ < n; len <<= 1) {\n            auto Compare = [&](int x, int y) {\n        \
    \        if (cpy[x] != cpy[y]) return cpy[x] < cpy[y];\n                int rx\
    \ = x + len < n ? cpy[x + len] : -1;\n                int ry = y + len < n ? cpy[y\
    \ + len] : -1;\n                return rx < ry;\n            };\n            sort(begin(sa),\
    \ end(sa), Compare);\n            tmp[sa[0]] = 0;\n            for (int i = 1;\
    \ i < n; i++) {\n                tmp[sa[i]] = tmp[sa[i - 1]] + (Compare(sa[i -\
    \ 1], sa[i]) ? 1 : 0);\n            }\n            swap(cpy, tmp);\n        }\n\
    \        return sa;\n    }\n\n    template <int THRESHOLD_NAIVE=10, int THRESHOLD_DOUBLING=40>\n\
    \    vector<int> sa_is(const vector<int>& s, int upper) {\n        int n = (int)s.size();\n\
    \        if (n == 0) return {};\n        if (n == 1) return {0};\n        if (n\
    \ == 2) {\n            if (s[0] < s[1]) return {0, 1};\n            else return\
    \ {1, 0};\n        }\n        if (n < THRESHOLD_NAIVE) return sa_naive(s);\n \
    \       if (n < THRESHOLD_DOUBLING) return sa_doubling(s, upper);\n\n        vector<int>\
    \ sa(n);\n        vector<bool> ls(n);\n        for (int i = n - 2; i >= 0; i--)\
    \ {\n            ls[i] = (s[i] == s[i + 1]) ? ls[i + 1] : (s[i] < s[i + 1]);\n\
    \        }\n        vector<int> sum_l(upper + 1), sum_s(upper + 1);\n        for\
    \ (int i = 0; i < n; i++) {\n            if (!ls[i]) sum_s[s[i]]++;\n        \
    \    else sum_l[s[i] + 1]++;\n        }\n        for (int i = 0; i <= upper; i++)\
    \ {\n            sum_s[i] += sum_l[i];\n            if (i < upper) sum_l[i + 1]\
    \ += sum_s[i];\n        }\n\n        auto induce = [&](const vector<int>& lms)\
    \ {\n            fill(begin(sa), end(sa), -1);\n            vector<int> buf(upper\
    \ + 1);\n            copy(begin(sum_s), end(sum_s), begin(buf));\n           \
    \ for (auto d : lms) {\n                if (d == n) continue;\n              \
    \  sa[buf[s[d]]++] = d;\n            }\n            copy(begin(sum_l), end(sum_l),\
    \ begin(buf));\n            sa[buf[s[n - 1]]++] = n - 1;\n            for (int\
    \ i = 0; i < n; i++) {\n                int v = sa[i];\n                if (v\
    \ >= 1 && !ls[v - 1]) {\n                    sa[buf[s[v - 1]]++] = v - 1;\n  \
    \              }\n            }\n            copy(begin(sum_l), end(sum_l), begin(buf));\n\
    \            for (int i = n - 1; i >= 0; i--) {\n                int v = sa[i];\n\
    \                if (v >= 1 && ls[v - 1]) {\n                    sa[--buf[s[v\
    \ - 1] + 1]] = v - 1;\n                }\n            }\n        };\n\n      \
    \  vector<int> lms_map(n + 1, -1);\n        int m = 0;\n        for (int i = 1;\
    \ i < n; i++) {\n            if (!ls[i - 1] && ls[i]) lms_map[i] = m++;\n    \
    \    }\n        vector<int> lms;\n        lms.reserve(m);\n        for (int i\
    \ = 1; i < n; i++) {\n            if (!ls[i - 1] && ls[i]) {\n               \
    \ lms.push_back(i);\n            }\n        }\n\n        induce(lms);\n\n    \
    \    if (m) {\n            vector<int> sorted_lms;\n            sorted_lms.reserve(m);\n\
    \            for (int v : sa) {\n                if (lms_map[v] != -1) sorted_lms.push_back(v);\n\
    \            }\n            vector<int> rec_s(m);\n            int rec_upper =\
    \ 0;\n            rec_s[lms_map[sorted_lms[0]]] = 0;\n            for (int i =\
    \ 1; i < m; i++) {\n                int l = sorted_lms[i - 1], r = sorted_lms[i];\n\
    \                int end_l = (lms_map[l] + 1 < m) ? lms[lms_map[l] + 1] : n;\n\
    \                int end_r = (lms_map[r] + 1 < m) ? lms[lms_map[r] + 1] : n;\n\
    \                bool same = true;\n                if (end_l - l != end_r - r)\
    \ {\n                    same = false;\n                } else {\n           \
    \         while (l < end_l) {\n                        if (s[l] != s[r]) break;\n\
    \                        l++;\n                        r++;\n                \
    \    }\n                    if (l == n || s[l] != s[r]) same = false;\n      \
    \          }\n                if (!same) rec_upper++;\n                rec_s[lms_map[sorted_lms[i]]]\
    \ = rec_upper;\n            }\n\n            vector<int> rec_sa =\n          \
    \      sa_is<THRESHOLD_NAIVE, THRESHOLD_DOUBLING>(rec_s, rec_upper);\n\n     \
    \       for (int i = 0; i < m; i++) {\n                sorted_lms[i] = lms[rec_sa[i]];\n\
    \            }\n            induce(sorted_lms);\n        }\n        return sa;\n\
    \    }\n\n    void init() { _sa = sa_is(_s, _upper); }\n};\n\n} // namespace kk2\n\
    \n#endif // STRING_SUFFIX_ARRAY_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: string/suffix_array.hpp
  requiredBy: []
  timestamp: '2024-08-27 00:19:53+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/suffix_array.hpp
layout: document
redirect_from:
- /library/string/suffix_array.hpp
- /library/string/suffix_array.hpp.html
title: string/suffix_array.hpp
---

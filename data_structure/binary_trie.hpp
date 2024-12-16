#ifndef DATA_STRUCTURE_BINARY_TRIE_HPP
#define DATA_STRUCTURE_BINARY_TRIE_HPP 1

#include <cassert>
#include <optional>
#include <vector>

namespace kk2 {

template <typename T> struct BinaryTrieNode {
    int nxt[2];
    // ノードに対応するprefixをもつ要素の数
    // 自分自身も含む
    int count;

    BinaryTrieNode() : count(0) { nxt[0] = nxt[1] = -1; }

    template <typename U> friend U &operator<<(U &os, const BinaryTrieNode &node) {
        os << "count: " << node.count << " ";
        os << "nxt: ";
        for (int i = 0; i < 2; ++i) os << node.nxt[i] << " ";
        return os;
    }
};

template <typename T, int MAX_LOG> struct BinaryTrie {
    using Node = BinaryTrieNode<T>;

    T lazy;
    std::vector<Node> nodes;
    constexpr static int root = 0;

    BinaryTrie() : lazy(T()) { nodes.emplace_back(); }

    BinaryTrie(int Num) : lazy(T()) {
        nodes.reserve(Num);
        nodes.emplace_back();
    }

    int push_node() {
        nodes.emplace_back();
        return nodes.size() - 1;
    }

    template <bool isadd> void update_direct(int node) {
        if constexpr (isadd) ++nodes[node].count;
        else --nodes[node].count;
    }

    template <bool isadd> void update_child(int node) {
        if constexpr (isadd) ++nodes[node].count;
        else --nodes[node].count;
    }

    void insert(T x) {
        x ^= lazy;
        int now = root;
        for (int i = MAX_LOG - 1; i >= 0; --i) {
            const int d = (x >> i) & 1;
            if (nodes[now].nxt[d] == -1) nodes[now].nxt[d] = push_node();
            update_child<true>(now);
            now = nodes[now].nxt[d];
        }
        update_direct<true>(now);
    }

    void erase(T x) {
        x ^= lazy;
        int now = root;
        int st[MAX_LOG];
        for (int i = MAX_LOG - 1; i >= 0; --i) {
            const int d = (x >> i) & 1;
            if (nodes[now].nxt[d] == -1) return;
            st[i] = now;
            now = nodes[now].nxt[d];
        }
        update_direct<false>(now);
        for (int i = 0; i < MAX_LOG; ++i) {
            update_child<false>(st[i]);
            if (!nodes[now].count) nodes[st[i]].nxt[(x >> i) & 1] = -1;
            now = st[i];
        }
    }

    void operate_xor(T x) { lazy ^= x; }

    std::optional<T> get_kth(int k) const {
        if (k >= nodes[root].count) return std::nullopt;
        int now = root, less = 0;
        T res = 0;
        for (int i = MAX_LOG - 1; i >= 0; --i) {
            const int d = (lazy >> i) & 1;
            if (nodes[now].nxt[d] == -1 or less + nodes[nodes[now].nxt[d]].count <= k) {
                if (nodes[now].nxt[d] != -1) less += nodes[nodes[now].nxt[d]].count;
                res |= (T(1) << i);
                now = nodes[now].nxt[d ^ 1];
            } else {
                now = nodes[now].nxt[d];
            }
        }
        return res;
    }

    int count_not_greater(T x) const {
        x ^= lazy;
        int now = root, res = nodes[root].count;
        for (int i = MAX_LOG - 1; i >= 0; --i) {
            const int d = (x >> i) & 1;
            if (d == 0 and nodes[now].nxt[d ^ 1] != -1) res -= nodes[nodes[now].nxt[d ^ 1]].count;
            now = nodes[now].nxt[d];
            if (now == -1) break;
        }
        return res;
    }

    int count_not_less(T x) const {
        x ^= lazy;
        int now = root, res = nodes[root].count;
        for (int i = MAX_LOG - 1; i >= 0; --i) {
            const int d = (x >> i) & 1;
            if (d == 1 and nodes[now].nxt[d ^ 1] != -1) res -= nodes[nodes[now].nxt[d ^ 1]].count;
            now = nodes[now].nxt[d];
            if (now == -1) break;
        }
        return res;
    }

    int count(T x) const {
        x ^= lazy;
        int now = root;
        for (int i= MAX_LOG - 1; i >= 0; --i) {
            const int d = (x >> i) & 1;
            if (nodes[now].nxt[d] == -1) return 0;
            now = nodes[now].nxt[d];
        }
        return nodes[now].count;
    }

    std::optional<T> max_not_greater(T x) const {
        if (size() == 0) return std::nullopt;
        x ^= lazy;
        int now = root;
        T res = 0;
        bool same = true;
        int st[MAX_LOG];
        int i = MAX_LOG - 1;
        for (;; --i) {
            const int d = (x >> i) & 1;
            st[i] = now;
            if (same) {
                if (d == 0 and nodes[now].nxt[d] != -1) now = nodes[now].nxt[d];
                else if (d == 0 and nodes[now].nxt[d] == -1) break;
                else if (d == 1 and nodes[now].nxt[d] != -1) {
                    res |= (T(1) << i);
                    now = nodes[now].nxt[d];
                } else {
                    assert(nodes[now].nxt[d ^ 1] != -1);
                    now = nodes[now].nxt[d ^ 1];
                    same = false;
                }
            } else {
                if (nodes[now].nxt[1] != -1) {
                    res |= (T(1) << i);
                    now = nodes[now].nxt[1];
                } else {
                    now = nodes[now].nxt[0];
                }
            }
            if (i == 0) return res;
        }

        ++i;
        for (;; ++i) {
            if (i == MAX_LOG) return std::nullopt;
            const int d = (x >> i) & 1;
            res &= ~(T(1) << i);
            now = st[i];
            if (d == 1 and nodes[now].nxt[d ^ 1] != -1) {
                now = nodes[now].nxt[d ^ 1];
                break;
            }
        }

        --i;
        for (; i >= 0; --i) {
            if (nodes[now].nxt[1] != -1) {
                res |= (T(1) << i);
                now = nodes[now].nxt[1];
            } else {
                now = nodes[now].nxt[0];
            }
        }
        return res;
    }

    std::optional<T> min_not_less(T x) const {
        if (size() == 0) return std::nullopt;
        x ^= lazy;
        int now = root;
        T res = 0;
        bool same = true;
        int st[MAX_LOG];
        int i = MAX_LOG - 1;
        for (;; --i) {
            const int d = (x >> i) & 1;
            st[i] = now;
            if (same) {
                if (d == 1 and nodes[now].nxt[d] != -1) {
                    res |= (T(1) << i);
                    now = nodes[now].nxt[d];
                }
                else if (d == 1 and nodes[now].nxt[d] == -1) break;
                else if (d == 0 and nodes[now].nxt[d] != -1) now = nodes[now].nxt[d];
                else {
                    assert(nodes[now].nxt[d ^ 1] != -1);
                    res |= (T(1) << i);
                    now = nodes[now].nxt[d ^ 1];
                    same = false;
                }
            } else {
                if (nodes[now].nxt[0] != -1) {
                    now = nodes[now].nxt[0];
                } else {
                    res |= (T(1) << i);
                    now = nodes[now].nxt[1];
                }
            }
            if (i == 0) return res;
        }

        ++i;
        for (;; ++i) {
            if (i == MAX_LOG) return std::nullopt;
            const int d = (x >> i) & 1;
            res &= ~(T(1) << i);
            now = st[i];
            if (d == 0 and nodes[now].nxt[d ^ 1] != -1) {
                res |= (T(1) << i);
                now = nodes[now].nxt[d ^ 1];
                break;
            }
        }

        --i;
        for (; i >= 0; --i) {
            if (nodes[now].nxt[0] != -1) {
                now = nodes[now].nxt[0];
            } else {
                res |= (T(1) << i);
                now = nodes[now].nxt[1];
            }
        }
        return res;
    }

    int size() const { return nodes[root].count; }
};

} // namespace kk2

#endif

#ifndef DATA_STRUCTURE_TRIE_HPP
#define DATA_STRUCTURE_TRIE_HPP 1

#include <cstring>
#include <cassert>
#include <functional>
#include <string>
#include <vector>

namespace kk2 {

template <int char_size> struct TrieNode {
    int nxt[char_size];
    int exist;
    std::vector<int> accept;

    TrieNode() : exist(0) { memset(nxt, -1, sizeof(nxt)); }
};

template <int char_size, int margin> struct Trie {
    using Node = TrieNode<char_size>;

    std::vector<Node> nodes;
    constexpr static int root = 0;

    Trie() { nodes.emplace_back(); }

    int push_node() {
        nodes.emplace_back();
        return (int)nodes.size() - 1;
    }

    void update_direct(int node, int id) { nodes[node].accept.push_back(id); }

    void update_child(int node) { ++nodes[node].exist; }

    void add(const std::string &str) {
        assert(!str.empty());
        const int id = nodes[root].exist;
        auto rec = [&](auto self, int now, int idx) -> void {
            if (idx == (int)str.size()) {
                update_direct(now, id);
                return;
            }
            const int d = str[idx] - margin;
            if (nodes[now].nxt[d] == -1) nodes[now].nxt[d] = push_node();
            self(self, nodes[now].nxt[d], idx + 1);
            update_child(now);
        };
        rec(rec, root, 0);
    }

    template <void (*f)(int)> void query(const std::string &str) {
        query(str, [](int idx) { f(idx); });
    }

    template <class F> void query(const std::string &str, const F &f) {
        int now = root;
        for (char c : str) {
            for (int &idx : nodes[now].accept) f(idx);
            const int d = c - margin;
            now = nodes[now].nxt[d];
            if (now == -1) return;
        }
        for (int idx : nodes[now].accept) f(idx);
    }

    int count() const { return (int)nodes[0].exist; }

    int size() const { return (int)nodes.size(); }

    // return the number of strings which have the prefix
    // corresponding to the node_id
    int size(int node_idx) const {
        return (int)nodes[node_idx].accept.size() + nodes[node_idx].exist;
    }
};

} // namespace kk2

#endif // DATA_STRUCTURE_TRIE_HPP

#ifndef KK2_DATA_STRUCTURE_TRIE_HPP
#define KK2_DATA_STRUCTURE_TRIE_HPP 1

#include <cassert>
#include <cstring>
#include <functional>
#include <string>
#include <vector>

namespace kk2 {

template <int char_size> struct TrieNode {
    int nxt[char_size];
    // 通過した回数，終点は含まない
    int passing;
    // このノードが終点のidたち
    std::vector<int> accept;

    TrieNode() : passing(0) { std::fill(nxt, nxt + char_size, -1); }
};

template <int char_size, int margin> struct Trie {
    using Node = TrieNode<char_size>;

    std::vector<Node> nodes;
    constexpr static int root = 0;

    Trie() {
        nodes.emplace_back();
    }

    Trie(int Num) {
        nodes.reserve(Num);
        nodes.emplace_back();
    }

    int push_node() {
        nodes.emplace_back();
        return (int)nodes.size() - 1;
    }

    void update_direct(int node, int id) { nodes[node].accept.push_back(id); }

    void update_child(int node) { ++nodes[node].passing; }

    void add(const std::string &str) {
        assert(!str.empty());
        const int id = nodes[root].passing;
        int now = root;
        for (int i = 0; i < (int)str.size(); ++i) {
            const int d = str[i] - margin;
            if (nodes[now].nxt[d] == -1) nodes[now].nxt[d] = push_node();
            update_child(now);
            now = nodes[now].nxt[d];
        }
        update_direct(now, id);
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

    int count() const { return nodes[0].passing; }

    int size() const { return (int)nodes.size(); }

    // return the number of strings which have the prefix corresponding to the node_id
    int size(int node_idx) const {
        return (int)nodes[node_idx].accept.size() + nodes[node_idx].passing;
    }
};

} // namespace kk2

#endif // KK2_DATA_STRUCTURE_TRIE_HPP

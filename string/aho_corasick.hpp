#ifndef STRING_AHO_CORASICK_HPP
#define STRING_AHO_CORASICK_HPP 1

#include <algorithm>
#include <queue>
#include <string>
#include <type_traits>
#include <unordered_map>
#include <vector>

#include "../data_structure/trie.hpp"

namespace kk2 {

template <int char_size, int margin> struct AhoCorasick : Trie<char_size + 1, margin> {
    using Trie<char_size + 1, margin>::Trie;
    using Trie<char_size + 1, margin>::count;

    constexpr static int FAIL = char_size;
    std::vector<int> correct, perm;

    void build() {
        correct.resize(this->size());
        int now = 0;
        perm.resize(this->size());
        perm[now++] = this->root;
        for (int i = 0; i < (int)this->size(); ++i) {
            correct[i] = (int)this->nodes[i].accept.size();
        }
        std::queue<int> que;
        for (int i = 0; i <= char_size; ++i) {
            if (this->nodes[this->root].nxt[i] == -1) {
                this->nodes[this->root].nxt[i] = this->root;
            } else {
                this->nodes[this->nodes[this->root].nxt[i]].nxt[FAIL] = this->root;
                que.emplace(this->nodes[this->root].nxt[i]);
            }
        }
        while (!que.empty()) {
            perm[now++] = que.front();
            auto &now = this->nodes[que.front()];
            int fail = now.nxt[FAIL];
            correct[que.front()] += correct[fail];
            que.pop();
            for (int i = 0; i < char_size; ++i) {
                if (now.nxt[i] == -1) {
                    now.nxt[i] = this->nodes[fail].nxt[i];
                } else {
                    this->nodes[now.nxt[i]].nxt[FAIL] = this->nodes[fail].nxt[i];
                    que.emplace(now.nxt[i]);
                }
            }
        }
    }

    long long all_match(const std::string &str, int now_ = 0) {
        std::unordered_map<int, int> visit_cnt;
        for (char c : str) {
            now_ = this->nodes[now_].nxt[c - margin];
            visit_cnt[now_]++;
        }
        long long res{};
        for (auto &&[now, cnt] : visit_cnt) { res += (long long)correct[now] * cnt; }
        return res;
    }

    std::vector<long long> each_match(const std::string &str, int now_ = 0) {
        std::vector<int> visit_cnt(this->size());
        for (char c : str) {
            now_ = this->nodes[now_].nxt[c - margin];
            visit_cnt[now_]++;
        }
        std::vector<long long> res(this->count());
        for (int i = this->size() - 1; i > 0; --i) {
            int now = perm[i];
            visit_cnt[this->nodes[now].nxt[FAIL]] += visit_cnt[now];
            for (int idx : this->nodes[now].accept) { res[idx] += visit_cnt[now]; }
        }
        return res;
    }

    int move(int now, char c) { return this->nodes[now].nxt[c - margin]; }

    int count(int node) const { return correct[node]; }
};

} // namespace kk2

#endif // STRING_AHO_CORASICK_HPP

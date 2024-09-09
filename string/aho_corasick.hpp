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

template <int char_size, int margin, bool heavy = true>
struct AhoCorasick : Trie<char_size + 1, margin> {
    using Trie<char_size + 1, margin>::Trie;

    constexpr static int FAIL = char_size;
    std::vector<int> correct;

    void build() {
        correct.resize(this->size());
        for (int i = 0; i < (int)this->size(); ++i) {
            std::sort(std::begin(this->nodes[i].accept),
                      std::end(this->nodes[i].accept));
            correct[i] = (int)this->nodes[i].accept.size();
        }
        std::queue<int> que;
        for (int i = 0; i <= char_size; ++i) {
            if (this->nodes[this->root].nxt[i] == -1) {
                this->nodes[this->root].nxt[i] = this->root;
            } else {
                this->nodes[this->nodes[this->root].nxt[i]].nxt[FAIL] =
                    this->root;
                que.emplace(this->nodes[this->root].nxt[i]);
            }
        }
        while (!que.empty()) {
            auto &now = this->nodes[que.front()];
            int fail = now.nxt[FAIL];
            correct[que.front()] += correct[fail];
            que.pop();
            for (int i = 0; i < char_size; ++i) {
                if (now.nxt[i] == -1) {
                    now.nxt[i] = this->nodes[fail].nxt[i];
                } else {
                    this->nodes[now.nxt[i]].nxt[FAIL] =
                        this->nodes[fail].nxt[i];
                    if (heavy) {
                        auto &u = this->nodes[now.nxt[i]].accept;
                        auto &v = this->nodes[this->nodes[fail].nxt[i]].accept;
                        std::vector<int> accept;
                        std::set_union(std::begin(u),
                                       std::end(u),
                                       std::begin(v),
                                       std::end(v),
                                       std::back_inserter(accept));
                        u = accept;
                    }
                    que.emplace(now.nxt[i]);
                }
            }
        }
    }

    std::conditional_t<heavy, std::unordered_map<int, long long>, long long>
    match(const std::string &str, int now_ = 0) {
        std::unordered_map<int, int> visit_cnt;
        for (char c : str) {
            now_ = this->nodes[now_].nxt[c - margin];
            visit_cnt[now_]++;
        }
        std::conditional_t<heavy, std::unordered_map<int, long long>, long long>
            res{};
        for (auto &&[now, cnt] : visit_cnt) {
            if constexpr (heavy) {
                for (int idx : this->nodes[now].accept) res[idx] += cnt;
            } else {
                res += (long long)correct[now] * cnt;
            }
        }
        return res;
    }

    int move(int now, char c) { return this->nodes[now].nxt[c - margin]; }

    int count(int node) const { return correct[node]; }
};

} // namespace kk2

#endif // STRING_AHO_CORASICK_HPP

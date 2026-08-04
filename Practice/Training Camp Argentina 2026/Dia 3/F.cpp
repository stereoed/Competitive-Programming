#pragma GCC optimize("Ofast")

#if __has_include("stdc++.h")
    #include "stdc++.h"
#else
    #include <bits/stdc++.h>
#endif

#if __has_include("cpp-dump.hpp")
    #include "cpp-dump.hpp"
    #define dump(...) cpp_dump(__VA_ARGS__);
#else
    #define dump(...)
#endif

#define FastIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL)
#define el '\n'

class Eertree {
private:
    struct Node {
        std::map<char, int> link;
        int suffix_link;
        int len, idx, cnt;

        Node() = default;
        Node(int len, int idx, int cnt) : len(len), idx(idx), cnt(cnt) {}
    };

    std::vector<Node> nodes;
    int suffix;
    std::string str;

    int find_next_palindrome(int k) const {
        const int pos = (int)str.size() - 1;
        while (true) {
            int i = pos - 1 - nodes[k].len;
            if (i >= 0 && str[i] == str[pos]) break;
            k = nodes[k].suffix_link;
        }
        return k;
    }

public:
    Eertree() : nodes(2) {
        nodes[0] = Node(-1, -1, 0);
        nodes[1] = Node(0, -1, 0);
        nodes[1].suffix_link = 0;
        suffix = 0;
    }

    explicit Eertree(const std::string& s) : Eertree() {
        for (char c : s) add(c);
    }

    void add(char c) {
        str.push_back(c);

        int k = find_next_palindrome(suffix);

        if (nodes[k].link.count(c)) {
            ++nodes[nodes[k].link[c]].cnt;
            suffix = nodes[k].link[c];
            return;
        }

        nodes[k].link[c] = suffix = (int)nodes.size();
        nodes.emplace_back(nodes[k].len + 2,
                           (int)str.size() - nodes[k].len - 2,
                           1);

        if (nodes.back().len == 1) {
            nodes.back().suffix_link = 1;
        } else {
            const int n = find_next_palindrome(nodes[k].suffix_link);
            nodes.back().suffix_link = nodes[n].link[c];
        }
    }

    std::vector<std::tuple<int, int, int>> get_palindrome_frequencies() {
        std::vector<std::tuple<int, int, int>> ret;
        for (int i = (int)nodes.size() - 1; i >= 2; --i) {
            ret.emplace_back(nodes[i].len, nodes[i].idx, nodes[i].cnt);
            nodes[nodes[i].suffix_link].cnt += nodes[i].cnt;
        }
        return ret;
    }
};

void solve() {
    int n;
    std::string s;
    std::cin >> n >> s;

    Eertree ET(s);
    std::vector<std::tuple<int, int, int>> banana = ET.get_palindrome_frequencies();

    long long ans = 0;
    std::vector<long long> pref(n + 1);
    for (int i = 1; i < n + 1; i++){
        pref[i] = pref[i - 1] + (s[i - 1] - 'a' + 1);
    }

    dump(pref)
    for (const auto& [len, id, cnt] : banana) {
        ans += pref[id + len] - pref[id];
    }


    std::cout << ans << el;
}

int main() {
    FastIO;

    int t = 1;
    // std::cin >> t;

    while (t--) solve();
}

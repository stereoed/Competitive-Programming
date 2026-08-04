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

int n, m;
std::vector<std::vector<int>> adj(n);
std::vector<int> prev, len, roots, seen_local;
std::vector<bool> seen;

int dfs(int node){
    int max_depth_id = node;
    seen[node] = true;
    seen_local.push_back(node);

    for (const auto nxt : adj[node]){
        if (prev[nxt] != -1) continue;
        len[nxt] = len[node] + 1;
        prev[nxt] = node;

        int end = dfs(nxt);
        if (len[end] > len[max_depth_id]) max_depth_id = end;
    }

    return max_depth_id;
}

void solve() {
    // INPUT //

    std::cin >> n >> m;
    adj = std::vector<std::vector<int>>(n);
    prev.assign(n, -1);
    len.assign(n, 1);
    seen.assign(n, false);
    roots.clear();
    
    int root = -1, root_len = -1;

    for (int i = 0; i < m; i++){
        int a, b; std::cin >> a >> b; a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dump(adj);

    // FIND MIDPOINTS IN EACH SCC //
    for (int i = 0; i < n; i++){
        if (seen[i]) continue;
        prev[i] = i;

        int border = dfs(i);

        for (const int sl : seen_local){
            prev[sl] = -1;
            len[sl] = 1;
        }
        seen_local.clear();

        prev[border] = border;
        int furthest = dfs(border);
        
        int ptr = furthest;

        for (int i = 0; i < len[furthest] / 2; i++){
            ptr = prev[ptr];
        }

        dump(root, ptr, root_len, len[furthest]);
        if (root_len < len[furthest]){
            root = ptr;
            root_len = len[furthest];
        }

        for (const int sl : seen_local){
            prev[sl] = -1;
            len[sl] = 1;
        }
        seen_local.clear();

        roots.push_back(ptr);
    }

    // UPDATE ADJ LIST //
    std::vector<std::pair<int, int>> ans(roots.size() - 1);
    if (roots.size() > 1){
        dump(root, roots)
        for (auto& [a, b] : ans){
            a = root;
            b = roots.back();

            if (b == a) {
                roots.pop_back();
                b = roots.back();
            }

            adj[a].push_back(b);
            adj[b].push_back(a);

            roots.pop_back();
        }
    }
    
    dump(ans, adj);

    // DIAMETER //
    int border = dfs(0);

    for (const int sl : seen_local){
        prev[sl] = -1;
        len[sl] = 1;
    }
    seen_local.clear();

    prev[border] = border;
    int furthest = dfs(border); dump(border, furthest, prev, len)

    // OUTPUT //
    std::cout << len[furthest] - 1<< el;
    for (const auto& [a, b] : ans){
        std::cout << a + 1 << " " << b + 1 << el;
    }
}

int main() {
    FastIO;

    int t = 1;
    //std::cin >> t;

    while (t--) solve();
}

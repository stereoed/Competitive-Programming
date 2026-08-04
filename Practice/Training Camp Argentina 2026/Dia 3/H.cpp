#pragma GCC optimize("Ofast")
using namespace std;

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

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(v) v.begin(), v.end()
#define el '\n'

int n, m;

void solve() {
    cin >> n >> m;
    vector<vector<pair<char, int>>> adj(n);

    for (int i = 0; i < m; i++){
        int u, v; char c;
        cin >> u >> v >> c; v--; u--;

        adj[u].push_back({c, v});
        adj[v].push_back({c, u});
    }

    ////// BFS A //////
    vector<int> time(n, -2);
    queue<int> q;

    q.push(n - 1);
    time[n-1] = 0;

    while(!q.empty()){
        int u = q.front(); q.pop();
        for (const auto [c, v] : adj[u]){
            if (time[v] == -2) {
                q.push(v);
                time[v] = time[u] + 1;
            }
        }
    }

    ////// BFS B //////
    string s = "";
    s.reserve(time[0]);

    char best_letter = 'z';
    vector<int> level = {0}, level_2;
    level.reserve(n);
    level_2.reserve(n);

    vector<int> prev(n);
    vector<bool> seen(n);
    for (int t = 0; t < time[0]; t++){
        best_letter = 'z';

        for (const int u : level)
            for (const auto [c, v] : adj[u])
                if (time[v] == time[u] - 1)
                    best_letter = min(best_letter, c);

        vector<bool> seen(n, false);
        for (const int u : level)
            for (const auto [c, v] : adj[u])
                if (c == best_letter && time[v] == time[u] - 1 && !seen[v]) {
                    seen[v] = true;
                    level_2.push_back(v);
                    prev[v] = u;
                }

        s.push_back(best_letter);
        swap(level, level_2);
        level_2.clear();
    }

    level.clear();
    level_2.clear();

    ////// OUTPUT ///////
    dump(prev)
    vector<int> seq;

    int ptr = n - 1;
    while (ptr != 0){
        seq.push_back(ptr);
        ptr = prev[ptr];
    }
    seq.push_back(0);

    reverse(all(seq));
    cout << time[0] << el;
    for (const int a : seq) cout << a + 1 << " ";
    cout << el << s << el;

    return;
}

int main() {
    FastIO;
    int t = 1; // cin >> t;
    while (t--)
    solve();
}


#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

#if __has_include("cpp-dump.hpp")
    #include "cpp-dump.hpp"
    #define dump(...) cpp_dump(__VA_ARGS__);
#else
    #define dump(...)
#endif

void solve(){
    int n; cin >> n;
    vector<vector<pair<int, int>>> adj(n + 1);

    for (int i = 1; i < n; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
    }

    vector<int> dp(n + 1, 1e9); // Round, id
    queue<pair<int, int>> q;
    dp[0] = dp[1] = 1;
    q.push({1, -1});

    while (!q.empty()){
        auto [v, idv] = q.front(); q.pop();
        dump(dp);
        for (auto& [nv, idnv] : adj[v]){
            if (dp[nv] != 1e9) continue;
            dp[nv] = dp[v] + (idnv < idv);
            q.push(make_pair(nv, idnv));
        }
    }  
    
    cout << *max_element(dp.begin(), dp.end()) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; cin >> t;
    while (t--) solve();
}
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
    int N, M; cin >> N >> M;
    vector<vector<int>> adj(N + 1);
    vector<bool> seen(N + 1);
    set<int> nxt;

    for (int i = 0; i < M; i++){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int ptr = 0;
    vector<int> ans(N);
    seen[1] = true;
    nxt.insert(1);

    while (nxt.size()){
        ans[ptr] = *nxt.begin(); 
        nxt.erase(ans[ptr]);

        for (auto& x : adj[ans[ptr]]){
            if (seen[x]) continue;
            seen[x] = true;
            nxt.insert(x);
        }

        ptr++;
    }

    for (auto x : ans) cout << x << ' ';
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; //cin >> t;
    while (t--) solve();
}
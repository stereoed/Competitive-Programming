#pragma GCC optimize("Ofast")
using namespace std;
#include <bits/stdc++.h>

#if __has_include("cpp-dump.hpp")
    #include "cpp-dump.hpp"
    #define dump(...) cpp_dump(__VA_ARGS__);
#else
    #define dump(...)
#endif

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

long long n, k;
vector<vector<int>> adj;
vector<bool> seen;
long long A, B;

void dfs(int node, bool is_a){
    for (const auto nxt : adj[node]){
        if (seen[nxt]) continue;
        seen[node] = true;

        if (is_a) A++;
        else B++;

        dfs(nxt, !is_a);
    }
}

void solve() {
    cin >> n;
    adj = vector<vector<int>>(n + 1);
    seen = vector<bool>(n + 1);
    A = 1; B = 0;

    for (int i = 0; i < n - 1; i++){
        int a, b; cin >> a >> b; a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    dfs(0, false);

    cout << (A * B) - (n - 1) << '\n';
}

int main() {
    FastIO;
    int t = 1; //cin >> t;
    while (t--) solve();
}
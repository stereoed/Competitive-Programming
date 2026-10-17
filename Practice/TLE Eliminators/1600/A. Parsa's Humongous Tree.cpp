#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

#if __has_include("cpp-dump.hpp")
#include "cpp-dump.hpp"
#define dump(...) cpp_dump(__VA_ARGS__);
#else
#define dump(...)
#endif

const int MAXN = 1e5 + 5;
long long memo[2][MAXN]{}; // Best value if I chose L / R

vector<pair<int, int>> B;
vector<vector<int>> ADJ;

void dp(int node, int parent){
    for (auto next : ADJ[node]){
        if (next == parent) continue;
        dp(next, node);

        memo[0][node] += max(memo[0][next] + abs(B[node].first - B[next].first), memo[1][next] + abs(B[node].first - B[next].second));
        memo[1][node] += max(memo[0][next] + abs(B[node].second - B[next].first), memo[1][next] + abs(B[node].second - B[next].second));
    }
}

void solve(){
    int N; cin >> N;
    for (int i = 0; i <= N; i++) memo[0][i] = memo[1][i] = 0;

    B.resize(N);
    for (auto& [l, r] : B) cin >> l >> r;

    ADJ.assign(N, vector<int>());
    for (int i = 1; i < N; i++){
        int u, v; cin >> u >> v; u--; v--;
        ADJ[u].push_back(v);
        ADJ[v].push_back(u);
    }

    dp(0, -1);
    cout << max(memo[0][0], memo[1][0]) << '\n';
    dump(memo);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; cin >> t;
    while (t--) solve();
}
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

#if __has_include("cpp-dump.hpp")
#include "cpp-dump.hpp"
#define dump(...) cpp_dump(__VA_ARGS__);
#else
#define dump(...)
#endif

vector<vector<int>> ADJ;
vector<int> D, S, G;

int build(int node, int depth, int parent){
    D[node] = depth;

    S[node] = 1;
    for (auto nxt : ADJ[node]){
        if (nxt == parent) continue;
        S[node] += build(nxt, depth + 1, node);
    }

    return S[node];
}

void solve(){
    int N, K; cin >> N >> K;
    ADJ.resize(N + 1);
    G.resize(N);
    D.resize(N + 1);
    S.resize(N + 1);

    for (int i = 0; i + 1 < N; i++){
        int a, b; cin >> a >> b;
        ADJ[a].push_back(b);
        ADJ[b].push_back(a);
    }

    std::ignore = build(1, 1, 0);

    dump(D);
    dump(S);

    for (int i = 1; i <= N; i++) G[i - 1] = D[i] - S[i];

    dump(G);

    long long ans = 0;

    sort(G.rbegin(), G.rend());
    for (int i = 0; i < K; i++) ans += G[i];

    dump(G);
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; //cin >> t;
    while (t--) solve();
}
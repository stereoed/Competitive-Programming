#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

#if __has_include("cpp-dump.hpp")
    #include "cpp-dump.hpp"
    #define dump(...) cpp_dump(__VA_ARGS__);
#else
    #define dump(...)
#endif

const int MAXN = 1e4 + 2;
int N, M;

void solve(){
    cin >> N >> M; N++; M++;
    vector<bitset<MAXN>> ADJ_COLOR(N);
    vector<vector<int>> SAME_COLOR(M);
    bitset<MAXN> visited, nw, used;

    for (int i = 1; i < M; i++){
        int u, v, c; cin >> u >> v >> c;
        ADJ_COLOR[u].set(c);
        ADJ_COLOR[v].set(c);
        SAME_COLOR[c].push_back(u);
        SAME_COLOR[c].push_back(v);
    }

    int ans = 0;
    for (auto& PATH : SAME_COLOR){
        sort(PATH.begin(), PATH.end());
        PATH.erase(unique(PATH.begin(), PATH.end()), PATH.end());
    }

    for (int i = 0; i < M; i++){
        auto& PATH = SAME_COLOR[i];

        if (PATH.empty()) continue;
        visited.reset();
        used.reset();
        used.set(i);

        for (auto node : PATH){
            nw = ADJ_COLOR[node] & (~used) & visited;

            ans += nw.count();
            used |= nw;
            visited |= ADJ_COLOR[node];
        }
    }

    cout << ans / 2 << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; //cin >> t;
    while (t--) solve();
}
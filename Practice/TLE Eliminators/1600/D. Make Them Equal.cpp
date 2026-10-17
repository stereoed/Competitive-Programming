#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

#if __has_include("cpp-dump.hpp")
#include "cpp-dump.hpp"
#define dump(...) cpp_dump(__VA_ARGS__);
#else
#define dump(...)
#endif

const int MAXN = 1e3 + 5;
int cost[MAXN]{};

void solve(){
    int N, M; cin >> N >> M;
    vector<int> W(N), V(N);

    for (int i = 0; i < N; i++){
        int a; cin >> a;
        W[i] = cost[a];
    }
    for (int i = 0; i < N; i++){
        cin >> V[i];
    }

    dump(W);
    dump(V);

    M = min(12 * N, M);

    vector<int> dp(M + 1);
    for (int i = 0; i < N; i++){
        for (int j = M; j >= W[i]; j--){
            dp[j] = max(dp[j], dp[j - W[i]] + V[i]); 
        }
    }

    dump(dp);

    cout << dp[M] << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    for (auto& x : cost) x = 1e9;
    
    cost[1] = 0;
    for (int x = 0; x < MAXN; x++){
        for (int i = 1; i <= x; i++){
            const int next = x + (x/i);
            if (next < MAXN) cost[next] = min(cost[next], cost[x] + 1);
        }
    }

    dump(cost);

    int t = 1; cin >> t;
    while (t--) solve();
}
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

#if __has_include("cpp-dump.hpp")
    #include "cpp-dump.hpp"
    #define dump(...) cpp_dump(__VA_ARGS__);
#else
    #define dump(...)
#endif

const int MAXN = 2 * 1e5 + 5;
int V[MAXN]{};
int dp[2][MAXN]{};

void solve(){
    int N; cin >> N;
    for (int i = 1; i <= N; i++) cin >> V[i];    
    for (int i = 0; i < N + 5; i++) dp[0][i] = dp[1][i] = 1e9;
    dp[1][0] = 0;

    for (int i = 0; i < N; i++){
        dp[0][i + 1] = min(dp[0][i + 1], dp[1][i] + V[i + 1]);
        dp[0][i + 2] = min(dp[0][i + 2], dp[1][i] + V[i + 1] + V[i + 2]);
        dp[1][i + 1] = min(dp[1][i + 1], dp[0][i]);
        dp[1][i + 2] = min(dp[1][i + 2], dp[0][i]);
    }

    cout << min(dp[0][N], dp[1][N]) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; cin >> t;
    while (t--) solve();
}
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

#if __has_include("cpp-dump.hpp")
#include "cpp-dump.hpp"
#define dump(...) cpp_dump(__VA_ARGS__);
#else
#define dump(...)
#endif

int N, K;

const int MOD = 1e9 + 7;
const int MAXN = 1e3 + 5;
long long memo[MAXN][MAXN]{}; // Planes left, decay

void solve(){
    cin >> N >> K;
    for (int n = 0; n <= N; n++) memo[n][1] = 1;

    for (int k = 2; k <= K; k++){
        memo[0][k] = 1;
        for (int n = 1; n <= N; n++){
            memo[n][k] = (memo[n - 1][k] + memo[N - n][k - 1]) % MOD;
        }
    }
    
    cout << memo[N][K] << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; cin >> t;
    while (t--) solve();
}
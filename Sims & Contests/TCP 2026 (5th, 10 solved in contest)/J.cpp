#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

#if __has_include("cpp-dump.hpp")
    #include "cpp-dump.hpp"
    #define dump(...) cpp_dump(__VA_ARGS__);
#else
    #define dump(...)
#endif

int N;
const long long INF = 1e18;
vector<vector<long long>> coins;
vector<vector<long long>> memo;

inline long long get_total(int x1, int y1, int x2, int y2){
    return coins[x1 - 1][y1 - 1] + coins[x2][y2] - coins[x1 - 1][y2] - coins[x2][y1 - 1];
}

long long dp(int i, int j){
    if (i + j > N) return 0;
    if (memo[i][j] != -INF) return memo[i][j];

    long long base = get_total(i, i, N - j, N - j); 
    long long top_left = base - get_total(i + 1, i + 1, N - j, N - j);
    long long bottom_right = base - get_total(i, i, N - j - 1, N - j - 1); 

    long long opt1 = top_left + min(dp(i + 2, j), dp(i + 1, j + 1));
    long long opt2 = bottom_right + min(dp(i + 1, j + 1), dp(i, j + 2));

    return memo[i][j] = max(opt1, opt2);
}

void solve(){
    cin >> N;
    coins.assign(N + 1, vector<long long>(N + 1, 0));
    memo.assign(N + 1, vector<long long>(N + 1, -INF));

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> coins[i][j];
            coins[i][j] += coins[i][j - 1];
        }
    }

    for (int j = 1; j <= N; j++) {
        for (int i = 1; i <= N; i++) {
            coins[i][j] += coins[i - 1][j];
        }
    }

    cout << dp(1, 0) << '\n';    
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; //cin >> t;
    while (t--) solve();
}
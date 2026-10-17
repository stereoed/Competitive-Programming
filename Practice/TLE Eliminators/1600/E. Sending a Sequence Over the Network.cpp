#pragma GCC optimize("Ofast")
using namespace std;

#if __has_include("stdc++.h")
    #include "stdc++.h"
#else
    #include <bits/stdc++.h>
#endif

#if __has_include("cpp-dump.hpp")
    #include "cpp-dump.hpp"
    #define dump(...) cpp_dump(__VA_ARGS__);
#else
    #define dump(...)
#endif

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(v) v.begin(), v.end()
#define el '\n'

void solve() {
    int N; cin >> N;
    vector<int> V(N + 1);
    vector<bool> dp(N + 1);
    for (int i = 1; i <= N; i++) cin >> V[i];
    
    dp[0] = true;
    for (int i = 1; i <= N; i++){
        int prev = i - V[i] - 1;
        int next = i + V[i];

        if (prev >= 0) dp[i] = dp[i] || dp[prev];
        if (i > 0 && next <= N) dp[next] = dp[next] || dp[i - 1];
    }

    dump(dp);

    cout << (dp[N] ? "YES" : "NO") << '\n';
}

int main() {
    FastIO;

    int t = 1; cin >> t;
    while (t--) solve();
}
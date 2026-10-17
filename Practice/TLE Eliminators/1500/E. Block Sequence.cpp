#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

#if __has_include("cpp-dump.hpp")
    #include "cpp-dump.hpp"
    #define dump(...) cpp_dump(__VA_ARGS__);
#else
    #define dump(...)
#endif


typedef long long ll;
typedef pair<int, int> pii;

const int M = 1000000007;

void solve(){
    int n; cin >> n;
    vector<int> v(n), dp(n + 1);
    for (auto& x : v) cin >> x;

    for (int i = n - 1; i >= 0; i--){
        dp[i] = dp[i + 1] + 1;
        if (i + v[i] < n) dp[i] = min(dp[i], dp[i + v[i] + 1]); 
    }
    
    cout << dp[0] << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; cin >> t;
    while (t--) solve();
}
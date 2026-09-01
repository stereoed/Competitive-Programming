#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

#if __has_include("cpp-dump.hpp")
    #include "cpp-dump.hpp"
    #define dump(...) cpp_dump(__VA_ARGS__);
#else
    #define dump(...)
#endif


void solve() {
    long long n, d; cin >> n >> d;
    vector<long long> v(n);
    for (auto& x : v) cin >> x;

    int ans = 0;
    long long mn = 1e9, mx = 0;
    for (const auto x : v){
        mn = min(mn, x);
        mx = max(mx, x);
        if (mx - mn > 2 * d){
            mn = x;
            mx = x;
            ans++;
        }
    }

    cout << ans << '\n';
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; cin >> t;
    while (t--) solve();
}
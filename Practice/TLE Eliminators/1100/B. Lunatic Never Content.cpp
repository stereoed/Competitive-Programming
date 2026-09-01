#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

#if __has_include("cpp-dump.hpp")
    #include "cpp-dump.hpp"
    #define dump(...) cpp_dump(__VA_ARGS__);
#else
    #define dump(...)
#endif


void solve(){
    int n; cin >> n;
    vector<int> v(n);
    for (auto& x : v) cin >> x;

    int ans = 0;
    for (int l = 0; l < n / 2; l++){
        int r = n - 1 - l;
        if (r == l || v[l] == v[r]) continue;

        if (ans == 0) ans = abs(v[r] - v[l]);
        ans = gcd(ans, abs(v[r] - v[l]));
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; cin >> t;
    while (t--) solve();
}
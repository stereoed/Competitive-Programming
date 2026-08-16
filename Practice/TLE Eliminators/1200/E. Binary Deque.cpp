#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#if __has_include("cpp-dump.hpp")
    #include "cpp-dump.hpp"
    #define dump(...) cpp_dump(__VA_ARGS__)
#else
    #define dump(...)
#endif

long long n, s;

void solve(){
    cin >> n >> s;
    vector<int> v(n);
    for (auto& x : v) cin >> x;

    int ans = -1, r = 0, sum = 0;
    for (int l = 0; l < n; l++){
        while (r < n && ((sum < s) || (sum == s && v[r] == 0))) sum += v[r++];
        if (sum != s) break;

        int cand = n - r + l;
        if (ans == -1 || ans > cand) ans = cand;
        sum -= v[l];
    }
    
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; cin >> t;

    while (t--) {
        solve();
    }
}
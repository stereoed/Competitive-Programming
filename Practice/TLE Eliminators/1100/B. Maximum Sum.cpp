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
    int n, k; cin >> n >> k;
    vector<int> v(n);
    for (auto& x : v) cin >> x;
    sort(v.begin(), v.end()); dump(v);
    long long ans = 0, sum = 0;

    for (int i = 0; i < n - k; i++) sum += v[i];
    ans = sum;

    int l = 0, r = n - k;
    while (r < n){
        sum += v[r++];
        sum -= v[l++];
        sum -= v[l++];
        ans = max(ans, sum);
    }


    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; cin >> t;
    while (t--) solve();
}
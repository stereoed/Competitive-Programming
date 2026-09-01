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
    reverse(v.begin(), v.end());

    int ans = 0;
    for (int i = 1; i < n;){
        if (v[i] == v[i - 1]) {
            i++;
        } else {
            ans++;
            if (2*i - 1 < n) v[i*2 - 1] = v[i - 1];
            i *= 2;
        }        
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; cin >> t;
    while (t--) solve();
}
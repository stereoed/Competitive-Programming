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

    map<int, int> vti;
    long long sum = 0;
    for (int i = 0; i < n; i++){
        sum += v[i];
        vti[sum] = i + 1;
    }

    int ans = 0;
    sum = 0;

    for (int i = n-1; i >= 0; i--){
        sum += v[i];

        if (vti[sum] > 0){
            if (vti[sum] >= i + 1) break;
            ans = max(ans, vti[sum] + n - i);
        }
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; cin >> t;
    while (t--) solve();
}
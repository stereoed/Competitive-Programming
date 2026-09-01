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
    vector<int> v(1001);
    
    for (int i = 1; i <= n; i++){
        int a; cin >> a;
        v[a] = i;
    }

    int ans = -1;
    for (int i = 1; i <= 1000; i++){
        if (v[i] == 0) continue;
        for (int j = i; j <= 1000; j++){
            if (v[j] == 0) continue;

            if (gcd(i, j) == 1) ans = max(ans, v[i] + v[j]);
        }
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; cin >> t;
    while (t--) solve();
}
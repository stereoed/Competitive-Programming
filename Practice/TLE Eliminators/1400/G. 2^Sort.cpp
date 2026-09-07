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
    int cnt = 0;

    long long ans = 0;

    int prev = -1;
    for (int i = 0; i < n; i++){
        int a; cin >> a;

        if (prev >= 2 * a) cnt = 0;
        cnt++;

        if (cnt > k) ans++;

        prev = a;
    }
    

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; cin >> t;
    while (t--) solve();
}
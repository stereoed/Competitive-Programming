#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

#if __has_include("cpp-dump.hpp")
    #include "cpp-dump.hpp"
    #define dump(...) cpp_dump(__VA_ARGS__);
#else
    #define dump(...)
#endif

const int MOD = 1e9 + 7;

void solve(){
    int n; cin >> n;

    long long ans = 0;
    int cnt_neg = 0, min_elem = 1e9;
    
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;

        cnt_neg += (x < 0);
        ans += abs(x);
        min_elem = min(min_elem, abs(x));
    }
    
    cout << ans - (cnt_neg & 1 ? 2 * min_elem : 0) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; cin >> t;
    while (t--) solve();
}
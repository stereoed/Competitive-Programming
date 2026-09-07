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
    int n, m; cin >> n >> m;
    vector<int> bad(n + 1, 1e9);
    for (int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        if (a > b) swap(a, b);
        bad[a] = min(bad[a], b);
    }

    long long ans = 0;
    int l = n;
    for (int r = n; r > 0; r--){
        while (l > 0 && bad[l] > r) l--;
        ans += r - l;
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; cin >> t;
    while (t--) solve();
}
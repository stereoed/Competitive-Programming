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
    int w, h; cin >> w >> h;
    vector<vector<int>> sides(4);
    for (auto& x : sides) {
        int k, aux; cin >> k;
        x.resize(2);

        cin >> x[0];
        for (int i = 1; i < k - 1; i++) cin >> aux;
        cin >> x[1];
    }

    long long ans = 0;
    for (int i = 0; i < 4; i++){
        ans = max(ans, 1LL * (sides[i][1] - sides[i][0]) * (i > 1 ? w : h));
    }
    
    cout << ans << '\n';    
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; cin >> t;
    while (t--) solve();
}
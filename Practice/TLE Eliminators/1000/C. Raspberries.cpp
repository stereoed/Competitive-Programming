#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

#if __has_include("cpp-dump.hpp")
    #include "cpp-dump.hpp"
    #define dump(...) cpp_dump(__VA_ARGS__);
#else
    #define dump(...)
#endif

/*
void solve() {
    int n, k; cin >> n >> k;

    int ans = k;
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        ans = min(ans, (k - x%k)%k);
    }

    cout << ans << '\n';
}
*/

void solve() {
    int n, k; cin >> n >> k;
    vector<int> cnt(k + 1);

    int ans = k;
    for (int i = 0; i < n; i++){
        int x; cin >> x;

        cnt[x%k]++;
        ans = min(ans, (k - (x % k)) %k);
    }
    if (k == 4) ans = max(0, min(ans, 2 - cnt[2]));

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; cin >> t;
    while (t--) solve();
}
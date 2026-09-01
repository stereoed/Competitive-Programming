#pragma GCC optimize("Ofast")
using namespace std;
#include <bits/stdc++.h>

#if __has_include("cpp-dump.hpp")
    #include "cpp-dump.hpp"
    #define dump(...) cpp_dump(__VA_ARGS__);
#else
    #define dump(...)
#endif

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int n, W;

void solve() {
    cin >> n >> W;
    vector<int> cnt(31);
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        int r = 0; while ((1 << r) < x) r++;
        cnt[r]++;
    }

    dump(cnt);

    int ans = 0;

    while (n){
        int w = W;
        ans++;

        for (int i = 30; i >= 0; i--){
            if (cnt[i] == 0) continue;

            int needed = w / (1 << i);
            int used = min(needed, cnt[i]);

            w -= (1 << i) * used;
            cnt[i] -= used;
            n -= used;
        }
    }

    cout << ans << '\n';
}

int main() {
    FastIO;
    int t = 1; cin >> t;
    while (t--) solve();
}
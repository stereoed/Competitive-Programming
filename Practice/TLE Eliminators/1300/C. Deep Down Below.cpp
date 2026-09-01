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

int n;
void solve() {
    cin >> n;
    vector<pair<int, int>> dungeon(n);

    for (int i = 0; i < n; i++){
        int k; cin >> k;

        int min_power = -1;
        for (int i = 0; i < k; i++) {
            int x; cin >> x;
            min_power = max(min_power, x - i + 1);
        }

        dungeon[i] = {min_power, k};
    }

    sort(dungeon.begin(), dungeon.end());
    dump(dungeon);

    int ans = 0, c = 0;
    for (const auto& [mp, cnt] : dungeon) {
        if (ans + c < mp) ans = mp - c;
        c += cnt;
    }
    cout << ans << '\n';
}

int main() {
    FastIO;
    int t = 1; cin >> t;
    while (t--) solve();
}
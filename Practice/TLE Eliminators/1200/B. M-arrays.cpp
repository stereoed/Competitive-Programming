#pragma GCC optimize("Ofast")
using namespace std;

#if __has_include("stdc++.h")
    #include "stdc++.h"
#else
    #include <bits/stdc++.h>
#endif

#if __has_include("cpp-dump.hpp")
    #include "cpp-dump.hpp"
    #define dump(...) cpp_dump(__VA_ARGS__);
#else
    #define dump(...)
#endif

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(v) v.begin(), v.end()
#define el '\n'

int n, k;

void solve() {
    cin >> n >> k; dump(n, k);

    map<int, int> cnt;
    for (int i = 0; i < n; i++){
        int x; cin >> x; 
        cnt[x % k]++;
    }

    int ans = (cnt[0] > 0 ? 1 : 0);
    for (int r = 1; r <= k / 2; r++) {
        dump(r, k - r, cnt[r], cnt[k - r]);
        if (r == k - r) {
            ans += cnt[r] > 0;
        } else {
            int a = cnt[r], b = cnt[k - r];
            if (a == 0 || b == 0) ans += a + b;
            else ans += max(1, abs(a - b));
        }
        dump(ans);
    }

    cout << ans << '\n';    
}

int main() {
    FastIO;
    int t = 1; cin >> t;
    while (t--) solve();
}
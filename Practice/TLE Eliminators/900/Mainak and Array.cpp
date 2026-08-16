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

long long n, q;

void solve() {
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    int ans = 0, mx = 0, mn = 1e9;
    for (int i = 0; i < n; i++){
        mx = max(mx, v[i]);
        mn = min(mn, v[i]);

        int nxt = (i + n - 1) % n;
        ans = max(ans, v[nxt] - v[i]);
    }

    dump(ans, v[n-1] - mn, mx - v[0]);
    ans = max({ans, v[n-1] - mn, mx - v[0]});
    cout << ans << '\n';
}

int main() {
    FastIO;

    int t = 1; cin >> t;
    while (t--) solve();
}
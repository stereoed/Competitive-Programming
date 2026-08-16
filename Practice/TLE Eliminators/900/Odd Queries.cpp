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
    cin >> n >> q;
    vector<int> v(n + 1);

    for (int i = 1; i <= n; i++){
        cin >> v[i];
        v[i] += v[i-1];
        v[i] &= 1;
    }

    dump(v);
    for (int i = 0; i < q; i++){
        int l, r, k; cin >> l >> r >> k; k &= 1;
        dump(l, r, k, v[l - 1], ((r - l + 1)&k), v[n] - v[r]);

        bool ok = (v[l - 1] + ((r - l + 1)&k) + v[n] - v[r]) & 1;
        cout << (ok ? "YES\n" : "NO\n"); dump(ok);
    }
}

int main() {
    FastIO;

    int t = 1; cin >> t;
    while (t--) solve();
}
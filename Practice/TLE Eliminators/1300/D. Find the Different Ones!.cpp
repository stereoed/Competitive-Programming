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
#define all(v) v.begin(), v.end()

long long n, q;
void solve() {
    cin >> n;
    vector<int> v(n + 1);

    int prev = -1;
    for (int i = 1; i <= n; i++){
        int x; cin >> x;
        if (x == prev) v[i] = v[i-1] + 1;
        else v[i] = 1;
        prev = x;
    }
    dump(v);

    cin >> q;
    for (int i = 0; i < q; i++){
        int l, r; cin >> l >> r;
        if (v[r] >= r - l + 1) cout << "-1 -1\n";
        else cout << r - v[r] << " " << r << '\n';
    }
}

int main() {
    FastIO;
    int t = 1; cin >> t;
    while (t--) solve();
}
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

long long n;

void solve() {
    cin >> n;
    long long mx = -1e10;

    vector<long long> v(n);
    for (auto& x : v) cin >> x;
    for (auto& x : v) {
        long long y; cin >> y; x -= y;
        mx = max(x, mx);
    }

    dump(v, mx);

    vector<int> ans;
    for (int i = 0; i < n; i++) if (v[i] == mx) ans.push_back(i + 1);

    cout << ans.size() << '\n';
    for (const auto x : ans) cout << x << " ";
    cout << '\n';
}

int main() {
    FastIO;
    int t = 1; cin >> t;
    while (t--) solve();
}
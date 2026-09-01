#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

#if __has_include("cpp-dump.hpp")
    #include "cpp-dump.hpp"
    #define dump(...) cpp_dump(__VA_ARGS__);
#else
    #define dump(...)
#endif

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

void solve() {
    int n; cin >> n;

    vector<vector<int>> v(n);
    for (auto& a : v){
        int k; cin >> k; a.resize(k);
        for (auto& x : a) cin >> x;
        sort(a.begin(), a.end());
    }

    dump(v);
    long long ans = 0, super_min = 1e9, second_min = 1e9;
    for (const auto& a : v){
        ans += a[1];
        super_min = min<long long>(super_min, a[0]);
        second_min = min<long long>(second_min, a[1]);
    }

    cout << ans - second_min + super_min << '\n';
}

int main() {
    FastIO;
    int t = 1; cin >> t;
    while (t--) solve();
}
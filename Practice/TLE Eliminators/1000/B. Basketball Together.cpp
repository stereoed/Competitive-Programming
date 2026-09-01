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
    long long n, x; cin >> n >> x;
    vector<long long> v(n);
    for (auto& x : v) cin >> x;
    sort(v.begin(), v.end());

    long long l = 0, r = n - 1;

    long long ans = 0;
    while (l <= r){
        long long power = v[r];
        l += ((x + power) / power) - 1;
        if (l <= r--) ans++;
        dump(l, r + 1)
    }

    cout << ans << '\n';
}

int main() {
    FastIO;
    int t = 1; //cin >> t;
    while (t--) solve();
}
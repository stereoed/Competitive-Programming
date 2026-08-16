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

long long n, k;
void solve() {
    cin >> n >> k;
    vector<int> v(n*k);
    for (auto& x : v) cin >> x;

    long long ans = 0;
    int r = n*k - 1;

    for (int i = 0; i < k; i++){
        r -= n / 2;
        ans += v[r--];
    }

    cout << ans << '\n';
}

int main() {
    FastIO;
    int t = 1; cin >> t;
    while (t--) solve();
}
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

int n;
void solve() {
    cin >> n;
    vector<int> v(n);
    for (auto& x : v) cin >> x;
    sort(v.begin(), v.end());

    int max_count = 0, count = 1;
    for (int i = 1; i <= n; i++){
        if (i == n || v[i] != v[i-1]){
            max_count = max(max_count, count);
            count = 1;
        } else {
            count += 1;
        }
    }

    int ans = 0;
    while (max_count < n){
        ans += 1 + max_count; // Copy + transfer
        max_count *= 2;
    }

    ans -= max_count - n;
    cout << ans << '\n';
}

int main() {
    FastIO;
    int t = 1; cin >> t;
    while (t--) solve();
}
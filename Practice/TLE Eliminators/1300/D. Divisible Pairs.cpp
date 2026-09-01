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

long long n, x, y;
void solve() {
    cin >> n >> x >> y;
    long long ans = 0;

    map<pair<int, int>, int> cnt;
    for (int i = 0; i < n; i++){
        int k; cin >> k;
        ans += cnt[{(x - k%x)%x, k%y}];
        cnt[{k%x, k%y}]++;
    }
    cout << ans << '\n';
}

int main() {
    FastIO;
    int t = 1; cin >> t;
    while (t--) solve();
}
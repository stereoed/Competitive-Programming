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

    vector<int> cnt(2 * n + 1);

    int prev = 0, count = 0, ans = 0;
    for (int i = 0; i < n; i++){
        int a; cin >> a;
        if (a != prev) count = 0;
        cnt[a] = max(++count, cnt[a]);
        ans = max(ans, cnt[a]);
        prev = a;
    }

    count = 0;

    for (int i = 0; i < n; i++){
        int a; cin >> a;
        if (a != prev) count = 0;
        ans = max(ans, ++count + cnt[a]);
        prev = a;
    }

    cout << ans << '\n';
}

int main() {
    FastIO;
    int t = 1; cin >> t;
    while (t--) solve();
}
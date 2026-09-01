#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

#if __has_include("cpp-dump.hpp")
    #include "cpp-dump.hpp"
    #define dump(...) cpp_dump(__VA_ARGS__);
#else
    #define dump(...)
#endif

int n, k;
string s;

void solve() {
    cin >> n >> k >> s;

    int ans = k, cnt = 0, r = 0;
    for (int l = 0; l < n - k + 1; l++){
        while (r < l + k) cnt += s[r++] == 'W';
        ans = min(ans, cnt);
        cnt -= s[l] == 'W';
    }

    cout << ans << '\n';
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; cin >> t;
    while (t--) solve();
}
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

#if __has_include("cpp-dump.hpp")
    #include "cpp-dump.hpp"
    #define dump(...) cpp_dump(__VA_ARGS__);
#else
    #define dump(...)
#endif

void solve() {
    long long n, m, minimum = 1e18, cnt = 0;
    cin >> n >> m;

    long long ans = 0;
    for (int i = 0; i < n * m; i++){
        long long x; cin >> x; 
        minimum = min(minimum, abs(x));
        cnt += (x < 0);
        ans += abs(x);
    }

    cout << ans - (cnt & 1 ? 2 * minimum : 0) << '\n';
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; cin >> t;
    while (t--) solve();
}
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

#if __has_include("cpp-dump.hpp")
    #include "cpp-dump.hpp"
    #define dump(...) cpp_dump(__VA_ARGS__);
#else
    #define dump(...)
#endif

void solve(){
    long long n, a, b, ans = 1e18; cin >> n >> a >> b;
    vector<long long> v(n + 1), p(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        p[i] = p[i - 1] + v[i];
    }

    for (int i = 0; i <= n; i++){
        long long conquer_move = (a + b) * (v[i]);
        long long conquer = b * (p[n] - p[i] - (n - i) * v[i]);
        ans = min(ans, conquer_move + conquer);
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; cin >> t;
    while (t--) solve();
}
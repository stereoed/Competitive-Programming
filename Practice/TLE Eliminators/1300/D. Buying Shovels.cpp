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

long long n, k;

void solve() {
    cin >> n >> k;
    long long ans = (n <= k ? 1 : n);

    for (long long i = 2; i*i <= n; i++){
        if (n % i) continue;
        long long buy = n / i;

        if (buy <= k) ans = min(ans, i);
        if (i <= k) ans = min(ans, buy);
    }

    cout << ans << '\n';
}

int main() {
    FastIO;
    int t = 1; cin >> t;
    while (t--) solve();
}
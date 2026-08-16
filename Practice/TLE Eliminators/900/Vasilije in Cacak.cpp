#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#if __has_include("cpp-dump.hpp")
    #include "cpp-dump.hpp"
    #define dump(...) cpp_dump(__VA_ARGS__)
#else
    #define dump(...)
#endif

long long n, m, x, y;

void solve(){
    cin >> n >> m >> x;
    bool ok = true;

    ok &= m * (m + 1) / 2 <= x;
    ok &= ((n * (n + 1) / 2) - ((n-m) * (n-m+1) /2)) >= x;
   
    cout << (ok ? "YES\n" : "NO\n");
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; cin >> t;

    while (t--) {
        solve();
    }
}
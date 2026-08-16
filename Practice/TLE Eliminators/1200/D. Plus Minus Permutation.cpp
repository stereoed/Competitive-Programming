#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#if __has_include("cpp-dump.hpp")
    #include "cpp-dump.hpp"
    #define dump(...) cpp_dump(__VA_ARGS__)
#else
    #define dump(...)
#endif

long long n, x, y;
string s;

void solve(){
    cin >> n >> x >> y;
    long long m = lcm(x, y);
    long long LX = n/x - n/m, LY = n/y - n/m; dump(LX, LY);
    long long ans = n * (n+1) / 2; dump(ans); // SUM [1, N] 
    ans -= (LY + 1) * (LY) / 2; dump(ans); // - SUM [1, LY]
    ans -= (n - LX) * (n - LX + 1) / 2; dump(n - LX, n - LX - 1, ans); // SUM [1, N - LX]
    cout << ans << '\n'; // SUM [N - LX + 1, N] - SUM [1, LY];    
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; cin >> t;

    while (t--) {
        solve();
    }
}
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
    int a, b; cin >> a >> b;

    int rem = (a - 1) % 4;
    int x = (rem < 2 ? (rem == 0 ? a - 1 : 1) : (rem == 2 ? a : 0));

    if (x == b) cout << a << '\n';
    else if ((x ^ b) != a)cout << a + 1 << '\n';
    else cout << a + 2 << '\n';
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; cin >> t;
    while (t--) solve();
}
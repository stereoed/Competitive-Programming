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
    int n; cin >> n;
    int hb = 0; while (n > (1 << (hb + 1))) hb++;
    for (int i = n - 1; i >= (1 << hb); i--) cout << i << ' ';
    for (int i = 0; i < (1 << hb); i++) cout << i << ' ';
    cout << '\n';
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; cin >> t;
    while (t--) solve();
}
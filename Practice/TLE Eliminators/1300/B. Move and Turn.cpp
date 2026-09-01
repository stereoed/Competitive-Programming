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
    cout << (((n+1)/2)+1)*((n/2)+1) * (n&1 ? 2 : 1) << '\n';
}

int main() {
    FastIO;
    int t = 1; //cin >> t;
    while (t--) solve();
}
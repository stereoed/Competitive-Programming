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

long long n, m, x;

void solve() {
    cin >> n >> x >> m;

    int l = x, r = x;
    for (int i = 0; i < m; i++){
        int ff, ss; cin >> ff >> ss;
        if (ff <= r) r = max(r, ss);
        if (ss >= l) l = min(l, ff);
    }

    cout << r - l + 1 << '\n';
}

int main() {
    FastIO;
    int t = 1; cin >> t;
    while (t--) solve();
}
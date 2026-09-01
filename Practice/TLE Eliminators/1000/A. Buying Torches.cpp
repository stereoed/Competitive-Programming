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
    int x, y, k; cin >> x >> y >> k;
    long long coal = k; dump(coal);
    long long sticks = (1LL * (y + 1) * k + (x - 3)) / (x - 1); dump(sticks);

    cout << sticks + coal << '\n';
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; cin >> t;
    while (t--) solve();
}
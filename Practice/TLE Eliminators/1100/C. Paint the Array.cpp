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
    int n; cin >> n;
    vector<long long> v(n);
    for (auto& x : v) cin >> x;

    long long g1 = v[0], g2 = v[1];
    for (int i = 0; i < n; i += 2) g1 = gcd(g1, v[i]);

    for (int i = 1; i < n; i += 2) {
        g2 = gcd(g2, v[i]);
        if (g1 > 0 && v[i] % g1 == 0) g1 = 0;
    }

    for (int i = 0; i < n; i += 2){
        if (g2 > 0 && v[i] % g2 == 0) g2 = 0;
    }

    cout << max(g1, g2) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; cin >> t;
    while (t--) solve();
}
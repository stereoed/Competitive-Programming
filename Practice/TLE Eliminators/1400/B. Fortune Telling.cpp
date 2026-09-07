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
    long long n, x, y; cin >> n >> x >> y;
    long long X = y;
    for (int i = 0; i < n; i++) {
        int a; cin >> a; X ^= a;
    }

    dump(x, y, X);

    cout << ((X & 1) == (x & 1) ? "Alice\n" : "Bob\n");    
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; cin >> t;
    while (t--) solve();
}
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
    long long n, k, b, s; cin >> n >> k >> b >> s;
    dump(b * k, s, b * k + n * (k - 1));

    if (b * k > s || b * k + n * (k - 1) < s){
        cout << "-1\n";
        return;
    }

    long long base = b * k;
    s -= base;
    for (int i = 0; i < n; i++){
        cout << base + min(k - 1, s) << ' ';
        s -= min(k - 1, s);
        base = 0;
    }
    cout << '\n';    
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; cin >> t;
    while (t--) solve();
}
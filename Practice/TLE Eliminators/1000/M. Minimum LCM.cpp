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

    int a = 1, b = n - 1;
    for (int i = 2; i * i <= n; i++){
        if (n % i) continue;
        a = n / i;
        b = (i - 1) * (n / i); 
        break;
    }

    cout << a << ' ' << b << '\n';
}

int main() {
    FastIO;
    int t = 1; cin >> t;
    while (t--) solve();
}
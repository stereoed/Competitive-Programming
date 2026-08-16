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
#define all(v) v.begin(), v.end()

int a, b, c;
void solve() {
    cin >> a >> b >> c;
    int d1 = b - a, d2 = c - b, d3 = c - a; dump(a, d1, b, d2, c);

    if (b > -d1 && (b + d1)%c == 0){ // MOVEMOS C
        dump(b != -d1, (b + d1)%c == 0);
        cout << "YES\n";
        return;
    }

    if (b > d2 && (b - d2)%a == 0){ // MOVEMOS A
        dump(b != d2, (b - d2)%a == 0);
        cout << "YES\n";
        return;
    }

    if (d3 % 2 == 0 && ((c+a)/2)%b == 0){ // MOVEMOS B
        cout << "YES\n";
        return;
    }

    cout << "NO\n";
}

int main() {
    FastIO;
    int t = 1; cin >> t;
    while (t--) solve();
}
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

string s;
void solve() {
    cin >> s;

    int one = 0;
    for (const char c : s) one += c == '1';
    one = min(one, (int)s.size() - one);
    bool ok = one&1;
    cout << (ok ? "DA\n" : "NET\n");
}

int main() {
    FastIO;
    int t = 1; cin >> t;
    while (t--) solve();
}
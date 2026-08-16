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

int n;
string s;
void solve() {
    cin >> s;
    
    s.front() = s.back();

    cout << s << '\n';
}

int main() {
    FastIO;
    int t = 1; cin >> t;
    while (t--) solve();
}
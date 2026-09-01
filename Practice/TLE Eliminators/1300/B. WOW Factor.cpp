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

string s;

void solve() {
    cin >> s;
    int n = s.size();
    long long w = 0, wo = 0, ans = 0;
    for (int i = 1; i < n; i++){
        if (s[i] == 'o') wo += w;
        else if (s[i - 1] == 'v'){
            w++;
            ans += wo;
        }
    }
    cout << ans << '\n';
}

int main() {
    FastIO;
    int t = 1; // cin >> t;
    while (t--) solve();
}
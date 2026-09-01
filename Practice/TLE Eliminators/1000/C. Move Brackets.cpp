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
    int n; string s;
    cin >> n >> s;

    int ans = 0, open = 0;
    for (char c : s){
        if (c == '(') open++;
        else {
            if (open <= 0) ans++;
            else open--;
        }
    }

    cout << ans << '\n';
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; cin >> t;
    while (t--) solve();
}
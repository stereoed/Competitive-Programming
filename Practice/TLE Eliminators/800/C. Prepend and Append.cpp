#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#if __has_include("cpp-dump.hpp")
    #include "cpp-dump.hpp"
    #define dump(...) cpp_dump(__VA_ARGS__)
#else
    #define dump(...)
#endif


int n;
string s;

void solve(){
    cin >> n >> s;
    int l = 0, r = n-1, ans = 0;

    while (l < r){
        if (s[l] == s[r]) break;
        l++; r--; ans++;
    }

    cout << n - 2*ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; cin >> t;

    while (t--) {
        solve();
    }
}

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
    int n; cin >> n;
    string s; cin >> s;
    char c = 'a';
    for (int i = 0; i < n; i++){
        if (s[i] < c){
            cout << "YES\n" << i << ' ' << i + 1 << '\n';
            return;
        }
        c = s[i];
    }
    cout << "NO\n";
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; //cin >> t;
    while (t--) solve();
}
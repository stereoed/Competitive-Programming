#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#if __has_include("cpp-dump.hpp")
    #include "cpp-dump.hpp"
    #define dump(...) cpp_dump(__VA_ARGS__)
#else
    #define dump(...)
#endif

int n, k;
string s;
void solve(){
    cin >> n >> s;

    int cnt = 1, ans = 0;

    for (int i = 1; i < n; i++){
        if (s[i] != s[i-1]) {
            ans = max(ans, cnt);
            cnt = 1;
        }
        
        else{
            cnt++;
        }
    }

    ans = max(ans, cnt);
    cout << ans + 1 << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; cin >> t;

    while (t--) {
        solve();
    }
}
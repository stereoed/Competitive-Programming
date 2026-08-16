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
    vector<bool> off(n, false);

    long long ans = 0;

    for (int i = 0; i < n; i++){   
        if (s[i] == '1') continue;  

        int nxt = i;
        while (nxt < n && s[nxt] == '0'){
            if (!off[nxt]) ans += i + 1;
            off[nxt] = true;
            nxt += i + 1;
        }
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; cin >> t;

    while (t--) {
        solve();
    }
}
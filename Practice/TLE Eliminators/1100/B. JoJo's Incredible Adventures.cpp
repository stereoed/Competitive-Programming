#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

#if __has_include("cpp-dump.hpp")
    #include "cpp-dump.hpp"
    #define dump(...) cpp_dump(__VA_ARGS__);
#else
    #define dump(...)
#endif

const int MOD = 1e9 + 7;

void solve(){
    string s; cin >> s;
    int n = s.size();

    s += s;
    int max_cnt = 0, cnt = 0;
    for (auto c : s){
        if (c == '0') cnt = 0;
        else cnt++;
        
        max_cnt = min(max(max_cnt, cnt), n);
    }

    if (max_cnt == n){
        cout << 1LL * n * n << '\n';
        return;
    }

    long long ans = 0;
    for (int i = 0; i < max_cnt; i++){
        ans = max(ans, 1LL * (max_cnt - i) * (i + 1));
    }  
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; cin >> t;
    while (t--) solve();
}
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
    string S; cin >> S;
    vector<int> cnt;

    int local = 0;
    for (auto c : S){
        if (c == 'a') {
            local++;
        }
        if (c == 'b') {
            if (local > 0) cnt.push_back(local);
            local = 0;
        }
    }
    cnt.push_back(local);
    dump(cnt);

    long long ans = 1;
    for (auto x : cnt) ans = (ans * (x + 1)) % MOD;
    cout << ans - 1 << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; //cin >> t;
    while (t--) solve();
}
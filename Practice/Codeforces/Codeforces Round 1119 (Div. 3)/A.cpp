#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

#if __has_include("cpp-dump.hpp")
    #include "cpp-dump.hpp"
    #define dump(...) cpp_dump(__VA_ARGS__);
#else
    #define dump(...)
#endif

void solve(){
    int n, k; cin >> n >> k;
    int ans = 0;

    string s; cin >> s;
    for (int i = 0; i < n / k; i++){
        bool flag = true;
        for (int j = 0; j < k; j++){
            if (s[k * i + j] == '0'){
                flag = false;
                break;
            }
        }
        ans += flag;
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; cin >> t;
    while (t--) solve();
}
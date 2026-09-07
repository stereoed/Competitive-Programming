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
    int n; cin >> n;
    vector<int> ans(n);

    int last_1 = -1, last_m1 = -1;
    for (int i = 0; i < n; i++){
        cin >> ans[i];

        if (ans[i] == 1) last_1 = i;

        if (ans[i] == -1){
            if (last_1 == -1) {
                ans[i] = 1;
                last_1 = i;
            } else {
                ans[i] = 0;
            }
            last_m1 = i;
        }
    }
    if (last_m1 > last_1) ans[last_m1] = 1;

    for (auto x : ans) cout << x << ' ';
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; cin >> t;
    while (t--) solve();
}
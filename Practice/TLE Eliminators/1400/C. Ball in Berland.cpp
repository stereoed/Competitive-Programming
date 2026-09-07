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
    int a, b, k; cin >> a >> b >> k;
    long long ans = 0;

    vector<int> v(k);
    vector<vector<int>> boys(a + 1), girls(b + 1);
    for (auto& x : v) cin >> x;
    for (int i = 0; i < k; i++){
        int x; cin >> x;
        boys[v[i]].push_back(x);
        girls[x].push_back(v[i]);
    }

    for (int i = 1; i <= a; i++){
        for (auto x : boys[i]){
            ans += k + 1 - boys[i].size() - girls[x].size();
        }
    }

    cout << ans / 2 << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; cin >> t;
    while (t--) solve();
}
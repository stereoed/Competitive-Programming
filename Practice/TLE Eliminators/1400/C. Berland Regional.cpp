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
    vector<int> uni(n + 1);
    for (int i = 0; i < n; i++) cin >> uni[i];

    vector<vector<long long>> unis(n + 1);
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        unis[uni[i]].push_back(x);
    }
    
    vector<long long> ans(n + 1);
    for (auto& u : unis){
        sort(u.rbegin(), u.rend());

        int un = u.size();
        for (int i = 1; i < un; i++) u[i] += u[i-1];
        for (int i = 1; i <= un; i++){
            long long players = un - (un % i) - 1;
            ans[i] += u[players];
        }
    }

    for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; cin >> t;
    while (t--) solve();
}
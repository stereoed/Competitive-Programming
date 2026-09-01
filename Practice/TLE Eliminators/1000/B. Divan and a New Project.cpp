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
    vector<pair<int, int>> v(n); 
    for (int i = 0; i < n; i++){
        cin >> v[i].first;
        v[i].second = i + 1; 
    }
    sort(v.rbegin(), v.rend()); dump(v);

    int next = 1;
    vector<int> ans(n + 1);
    long long total = 0;

    ans[0] = 0;
    for (const auto& [ff, ss] : v){
        total += 1LL * ff * abs(next) * 2;
        ans[ss] = next;

        next *= -1;
        if (next > 0) next++;
    }

    cout << total << '\n';
    for (const auto x : ans) cout << x << ' ';
    cout << '\n';
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; cin >> t;
    while (t--) solve();
}
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
    vector<pair<pair<long long, long long>, int>> v(n + 1);
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        v[i] = {{x, x}, i};
    }

    sort(v.begin(), v.end()); 
    for (int i = 1; i <= n; i++) v[i].first.second += v[i - 1].first.second;
    dump(v);

    vector<int> ans(n);
    for (int i = 1; i <= n; i++){
        int idx = i;

        long long prev = 0, cur = v[i].first.second;
        while (prev != cur){
            int r = n;

            while (idx < r){
                int mid = idx + (r - idx + 1) / 2;
                if (cur >= v[mid].first.first) idx = mid;
                else r = mid - 1;
            }

            prev = cur;
            cur = v[idx].first.second;
        }

        ans[v[i].second - 1] = idx - 1;
    }

    for (const auto x : ans) cout << x << ' ';
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; cin >> t;
    while (t--) solve();
}
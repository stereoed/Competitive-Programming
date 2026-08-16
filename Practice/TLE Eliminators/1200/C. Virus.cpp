#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#if __has_include("cpp-dump.hpp")
    #include "cpp-dump.hpp"
    #define dump(...) cpp_dump(__VA_ARGS__)
#else
    #define dump(...)
#endif

int n, m;
void solve(){
    cin >> n >> m;
    vector<int> v(m);
    for (int& x : v) cin >> x;
    sort(v.begin(), v.end());

    int ans = n;
    vector<long long> dist;

    dist.push_back(v[0] + n - v[m-1] - 1);
    for (int i = 1; i < m; i++) dist.push_back(v[i] - v[i - 1] - 1);
    sort(dist.rbegin(), dist.rend());

    long long time = 0;
    for (const auto d : dist){
        long long delta = d - 2 * time;
        delta -= (delta > 1);
        if (delta < 0) continue;
        ans -= delta;
        time += 1 + (delta > 1);
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
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

#if __has_include("cpp-dump.hpp")
    #include "cpp-dump.hpp"
    #define dump(...) cpp_dump(__VA_ARGS__);
#else
    #define dump(...)
#endif

vector<pair<long long, long long>> cities;
long long dist(int a, int b){
    return llabs(cities[a].first - cities[b].first) + llabs(cities[a].second - cities[b].second);
}

void solve(){
    int n, k, s, e; cin >> n >> k >> s >> e; s--; e--;
    cities = vector<pair<long long, long long>>(n);
    for (auto& [ff, ss] : cities) cin >> ff >> ss;

    long long ans = dist(s, e);
    long long maj1 = 1e18, maj2 = 1e18;

    for (int i = 0; i < k; i++){
        maj1 = min(maj1, dist(s, i));
        maj2 = min(maj2, dist(i, e));
    }

    ans = min(ans, maj1 + maj2);
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; cin >> t;
    while (t--) solve();
}
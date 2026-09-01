#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

#if __has_include("cpp-dump.hpp")
    #include "cpp-dump.hpp"
    #define dump(...) cpp_dump(__VA_ARGS__);
#else
    #define dump(...)
#endif

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

void solve() {
    int n, p; cin >> n >> p;
    vector<pair<int, int>> v(n);
    for (auto& [ff, ss] : v) cin >> ss;
    for (auto& [ff, ss] : v) cin >> ff;
    sort(v.begin(), v.end()); dump(v);

    long long ans = 0;
    queue<pair<int, int>> q;

    for (const auto& x : v){
        if (q.empty() || q.front().first >= p){
            ans += p;
            q.push(x);
            continue;
        }

        ans += q.front().first;
        if (--q.front().second == 0) q.pop();
        q.push(x);
    }

    cout << ans << '\n';
}

int main() {
    FastIO;
    int t = 1; cin >> t;
    while (t--) solve();
}
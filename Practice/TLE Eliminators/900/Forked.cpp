#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#if __has_include("cpp-dump.hpp")
    #include "cpp-dump.hpp"
    #define dump(...) cpp_dump(__VA_ARGS__)
#else
    #define dump(...)
#endif

int n, m, x, y;
const int MOD = 1e8;

void solve(){
    long long a, b; cin >> a >> b;
    vector<pair<int, int>> delta = {{a, b}, {-a, b}, {a, -b}, {-a, -b}, {b, a}, {b, -a}, {-b, a}, {-b, -a}};
    long long xk, yk, xq, yq; cin >> xk >> yk >> xq >> yq;

    dump(delta);

    int ans = 0;
    queue<pair<int, int>> q;
    for (const auto& [dx, dy] : delta){
        q.push({xk + dx, yk + dy});
    }

    while (!q.empty()){
        const auto [sx, sy] = q.front(); q.pop();
        for (const auto& [dx, dy] : delta){
            ans += ((sx + dx == xq) && (sy + dy == yq));
        }
    }

    cout << ans / (a == b ? 4 : 1) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; cin >> t;

    while (t--) {
        solve();
    }
}
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#if __has_include("cpp-dump.hpp")
    #include "cpp-dump.hpp"
    #define dump(...) cpp_dump(__VA_ARGS__)
#else
    #define dump(...)
#endif

long long n, m;
string s;

void solve(){
    cin >> n >> m;
    vector<vector<int>> mat(n, vector<int>(m));
    for (auto& player : mat) for (auto& bet : player) cin >> bet;

    long long ans = 0;
    vector<long long> bets(n);
    for (int round = 0; round < m; round++){
        for (int player = 0; player < n; player++){
            bets[player] = mat[player][round];
        }

        sort(bets.begin(), bets.end());
        long long sum = 0;
        for (int player = 0; player < n; player++){
            ans += bets[player] * player - sum;
            sum += bets[player];
        }
    }

    dump(mat);
    cout << ans << '\n';    
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; cin >> t;

    while (t--) {
        solve();
    }
}
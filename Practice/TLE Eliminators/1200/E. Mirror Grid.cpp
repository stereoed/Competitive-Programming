#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#if __has_include("cpp-dump.hpp")
    #include "cpp-dump.hpp"
    #define dump(...) cpp_dump(__VA_ARGS__)
#else
    #define dump(...)
#endif

long long n, s;



void solve(){
    cin >> n;
    vector<vector<int>> grid(n, vector<int>(n));
    for (auto& line : grid) for (auto& val : line) {
        char c; cin >> c; val = c - '0';
    }

    dump(grid);

    if (n == 1){
        cout << "0\n";
        return;
    }

    int ans = 0;

    for (int i = 0; i < (n + 1)/2; i++){
        for (int j = i; j < n - i - 1; j++){
            auto xxx = vector<pair<int, int>>{{i, j}, {n - i - 1, n - 1 - j}, {n - 1 - j, i}, {j, n - i - 1}};
            int cnt = 0;

            for (auto [x, y] : xxx){
                cnt += grid[x][y] == 1;
            }

            ans += min(cnt, 4 - cnt);
        }
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
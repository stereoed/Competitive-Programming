#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

#if __has_include("cpp-dump.hpp")
    #include "cpp-dump.hpp"
    #define dump(...) cpp_dump(__VA_ARGS__);
#else
    #define dump(...)
#endif

const int MOD = 1e9 + 7;

void solve(){
    int n, k; cin >> n >> k;
    vector<vector<int>> mat(n, vector<int>(n));
    for (auto& line : mat) for (auto& x : line) cin >> x;


    long long cnt = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n ; j++){
            cnt += (mat[i][j] != mat[n - i - 1][n - j - 1]);
        }
    }
    cnt /= 2; dump(cnt);

    bool flag = cnt <= k && ((k - cnt) % 2 == 0 || n & 1);
    cout << (flag ? "YES\n" : "NO\n");
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; cin >> t;
    while (t--) solve();
}
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
    int n, m; cin >> n >> m;
    vector<vector<int>> mat(n, vector<int>(m));
    for (auto& l : mat) for (auto& x : l) cin >> x;
    dump(mat);

    map<int, int> cnt;
    map<int, long long> sum_x, sum_y;

    long long ans = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            int a = mat[i][j];
            ans += 1LL * cnt[a]++ * i - sum_x[a];
            sum_x[a] += i;
        }
    }

    cnt.clear();

    for (int j = 0; j < m; j++){
        for (int i = 0; i < n; i++){
            int a = mat[i][j];
            ans += 1LL * cnt[a]++ * j - sum_y[a];
            sum_y[a] += j;
        }
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; //cin >> t;
    while (t--) solve();
}
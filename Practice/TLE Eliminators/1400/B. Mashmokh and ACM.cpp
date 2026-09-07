#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

#if __has_include("cpp-dump.hpp")
    #include "cpp-dump.hpp"
    #define dump(...) cpp_dump(__VA_ARGS__);
#else
    #define dump(...)
#endif

const int M = 1000000007;

void solve(){
    int n, k; cin >> n >> k;
    long long ans = 0;

    vector<vector<long long>> mat(k + 1, vector<long long>(n + 1, 0));
    for (int i = 1; i <= n; i++){
        mat[1][i] = 1;
    }

    for (int i = 1; i < k; i++){
        for (int j = 1; j <= n; j++){
            for (int x = j; x <= n; x += j){
                mat[i + 1][x] = (mat[i + 1][x] + mat[i][j]) % M;
            }
        }
    }

    for (int i = 1; i <= n; i++) ans = (ans + mat[k][i]) % M;

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; //cin >> t;
    while (t--) solve();
}
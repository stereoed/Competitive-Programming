#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
 
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repb(i, n) for (int i = (int)n-1; i >= 0; i--)
#define repx(i, a, n) for (int i = (int)a; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define el "\n"
const int MOD = 1e9 + 7;
const int INF = 1e9;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n;
    cin >> n;
 
    vector<vector<int>> ans(n, vector<int>(n, 0));
    char c;
    rep(i, n) rep(j, n){
            cin >> c;
            if (c == '*') ans[i][j] = -1;
    }
    
    if (ans[0][0] == -1 || ans[n-1][n-1] == -1){
        cout << 0 << el;
        return 0;
    }
    
    ans[0][0] = 1;
    rep(i, n) {
        rep(j, n){
            if (ans[i][j] == -1) continue;
            if (i + 1 < n && ans[i + 1][j] != -1) { ans[i + 1][j] += ans[i][j]; ans[i + 1][j] %= MOD; } 
            if (j + 1 < n && ans[i][j + 1] != -1) { ans[i][j + 1] += ans[i][j]; ans[i][j + 1] %= MOD; } 
        }
    }
    cout << ans[n-1][n-1] << el;
}
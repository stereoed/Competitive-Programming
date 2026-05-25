#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
 
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repx(i, a, n) for (int i = (int)a; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
 
const int MOD = 1e9 + 7;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n, x;
    cin >> n >> x;
 
    vi c(n);
    rep(i, n) cin >> c[i];
    sort(all(c));
 
    vi dp(x + 1, 0);
    dp[0] = 1;
 
    rep(i, n) {
        int coin = c[i];
        repx(s, coin, x + 1) {
            dp[s] += dp[s - coin];
            dp[s] %= MOD;
        }
    }
 
    cout << dp[x] << "\n";
}
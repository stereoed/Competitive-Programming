#pragma GCC optimize("Ofast")
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <set>
#include <cmath>
#include <string.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
 
#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define el '\n'
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repx(i, a, n) for (int i = (int)a; i < (int)(n); i++)
#define repb(i, n) for (int i = n - 1; i >= 0; i--)
#define pb push_back
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define ms(arr, val) memset(arr, val, sizeof(arr))
 
const int MAXN = 1e6 + 5;
const int MOD = 1e9 + 7;
 
void solve(){
    vector<vector<ll>> dp(MAXN, vector<ll>(2));
 
    dp[1][0] = 1; dp[1][1] = 1;
    repx(i, 2, MAXN){
        dp[i][0] = (dp[i - 1][0] * 4 + dp[i - 1][1]) % MOD;
        dp[i][1] = (dp[i - 1][0] + dp[i - 1][1] * 2) % MOD;
    }
 
 
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        cout << (dp[n][0] + dp[n][1]) % MOD << el; 
    }
}
 
int main() {
    FastIO;
    solve();
    return 0;
}
 
 
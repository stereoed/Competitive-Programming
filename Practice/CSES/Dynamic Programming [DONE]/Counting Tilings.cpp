#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;
 
#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define el '\n'
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repx(i, a, n) for (int i = (int)a; i < (int)(n); i++)
#define repb(i, n) for (int i = (int)n - 1; i >= 0; i--)
#define pb push_back
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define ms(arr, val) memset(arr, val, sizeof(arr))
 
const int MOD = 1e9 + 7;
const ll INF = 1e18;
 
int n, m, states;
vvi dp;
 
void gen(int row, int mask, int next_mask, int col){
    // Si reviso toda la columna, entonces rdy
    if(row == n){
        dp[col + 1][next_mask] += dp[col][mask];
        dp[col + 1][next_mask] %= MOD;
        return;
    }
    
    // Esta ocupada la casilla, paso a la sig
    if (mask & (1 << row)){
        gen(row + 1, mask, next_mask, col);
        return;
    }
    
    // Agrego una vertical
    if(row + 1 < n && !(mask & (1 << (row + 1))))
        gen(row + 2, mask, next_mask, col);
    
    // Agrego una horizontal
    gen(row + 1, mask, next_mask | (1 << row), col);
}
 
void solve() {
	cin >> n >> m;
	states = 1 << n;
	dp = vvi(m + 1, vi(states, 0));
	
	dp[0][0] = 1;
	
	rep(col, m){
	    rep(mask, states){
	        if(dp[col][mask] == 0) continue;
	        gen(0, mask, 0, col);
	    }
	}
	
	cout << dp[m][0] << el;
}
 
int main() {
    FastIO;
    int t = 1;
    while (t--) solve();
    return 0;
}
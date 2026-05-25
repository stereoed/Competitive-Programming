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
int n, x;
 
void solve() {
	cin >> n >> x;
	vi w(n); rep(i, n) cin >> w[i];
	
	ll all = 1 << n;
	vii dp(all, {INF, INF});
	dp[0] = {1, 0};
	
	rep(state, all){
		rep(i, n){
		    int old_state = state ^ (1 << i);
		    if (!state & (1 << i)) continue; // Osea, si no lo tiene, skip
		    
			auto [r, ww] = dp[old_state];
			if (w[i] + ww > x){
				ww = w[i];
				r++;
			}
			else ww += w[i];
			
			dp[state] = min(dp[state], {r, ww});
		}
	}
	
	cout << dp[all - 1].first << el;
}
 
int main() {
    FastIO;
    int t = 1;
    while (t--) solve();
    return 0;
}
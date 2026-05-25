#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
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
int n;
 
void solve() {
	cin >> n;
	ll ans = 0;
	vector<tuple<int, int, int>> v(n); for (auto& [a, b, p] : v) cin >> a >> b >> p;
	sort(all(v));
	
	set<int> end_times;
	map<int, ll> dp;
	
	repb(i, n){
		auto& [a, b, p] = v[i];
		auto it = end_times.lower_bound(b + 1);
		ll nxt = (it == end_times.end() ? 0 : dp[*it]);
		
		it = end_times.lower_bound(a);
		ll biggest = (it == end_times.end() ? 0 : dp[*it]);
 
		dp[a] = max({nxt + p, biggest}); 
		end_times.insert(a);
 
		ans = max(dp[a], ans);
	}
	//cout << dp[97] << el;
	cout << ans << el;
}
 
int main() {
    FastIO;
    int t = 1;
    while (t--) solve();
    return 0;
}
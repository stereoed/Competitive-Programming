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
const int INF = 1e9;
 
struct ST {
	int n;
	vector<ll> st;
	
	ST(int _n) {
		n = 1;
		while(n < _n) n <<= 1;
		st = vector<ll>(2 * n, 0);
	}
	
	void update(int i, ll v) {
		i += n;
		st[i] += v;
		st[i] %= MOD;
		for(i >>= 1; i; i >>= 1) {
			st[i] = st[i << 1] + st[i << 1 | 1];
			st[i] %= MOD;
		}
	}
	
	ll query(int l, int r) {
		if(l > r) return 0;
		ll ans = 0;
		for(l += n, r += n; l <= r; l >>= 1, r >>= 1) {
			if(l & 1) {
				ans += st[l++];
				ans %= MOD;
			}
			if(!(r & 1)) {
				ans += st[r--];
				ans %= MOD;
			}
		}
		return ans;
	}
};
 
void solve() {
	int n; cin >> n;
	vi a(n), vals;
	
	rep(i, n) {
		cin >> a[i];
		vals.pb(a[i]);
	}
	
	// Remove duplicates
	sort(all(vals));
	vals.erase(unique(all(vals)), vals.end());
	
	ST st((int)vals.size());
	ll total = 0;
	
	rep(i, n) {
		int pos = lower_bound(all(vals), a[i]) - vals.begin();
		ll dp = 1 + st.query(0, pos - 1);
		dp %= MOD;
		
		st.update(pos, dp);
		
		total += dp;
		total %= MOD;
	}
	
	cout << total << el;
}
 
int main() {
	FastIO;
	int t = 1;
	while (t--) solve();
	return 0;
}
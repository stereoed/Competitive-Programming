#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef vector<bool> vb;
typedef vector<vb> vvb;
 
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
 
int n, m;
 
void solve() {
	cin >> n >> m;
	vvi adj(n);
	vii ans;
	vb seen(n);
	queue<int> q;
	
	rep(i, m){
	    int a, b; cin >> a >> b; a--; b--;
	    adj[a].pb(b);
	    adj[b].pb(a);
	}
	
	rep(i, n){
		if (seen[i]) continue;
		if (i != 0) ans.pb({1, i + 1});
		
 
		q.push(i);
		seen[i] = 1;
		while (!q.empty()){
			auto x = q.front(); q.pop();
			for (auto& nxt : adj[x]){
				if (seen[nxt]) continue;
			    seen[nxt] = 1;
				q.push(nxt);
			}
		}
	}
	
	cout << ans.size() << el;
	for (auto& [a, b] : ans) cout << a << " " << b << el;
}
 
int main() {
	FastIO;
	int t = 1;
	while (t--) solve();
	return 0;
}
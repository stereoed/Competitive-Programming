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
	vi prev(n, -1);
	vi ans;
	queue<int> q;
	
	rep(i, m){
	    int a, b; cin >> a >> b; a--; b--;
	    adj[a].pb(b);
	    adj[b].pb(a);
	}
	
	q.push(0);
	prev[0] = 0;
	while (!q.empty()){
	    auto x = q.front(); q.pop();
    	for (auto& nxt : adj[x]){
    		if (prev[nxt] != -1) continue;
    	    prev[nxt] = x;
    		q.push(nxt);
    	}
	}
	
	if (prev[n-1] == -1){
	    cout << "IMPOSSIBLE" << el;
	    return;
	}
	
	int pos = n-1;
	rep(i, n) cerr << prev[i] << " ";
	while (pos != 0){
	    ans.pb(pos + 1);
	    pos = prev[pos];
	}
	
	cerr << "A";
	
	ans.pb(1);
	
	reverse(all(ans));
	cout << ans.size() << el;
	for (auto& a : ans) cout << a << " ";
}
 
int main() {
	FastIO;
	int t = 1;
	while (t--) solve();
	return 0;
}
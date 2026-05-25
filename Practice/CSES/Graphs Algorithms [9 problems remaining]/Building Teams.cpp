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
	vi team(n, -1);
	queue<int> q;
	
	rep(i, m){
	    int a, b; cin >> a >> b; a--; b--;
	    adj[a].pb(b);
	    adj[b].pb(a);
	}
	
	rep (i, n){
	    if (team[i] != -1) continue;
        
        team[i] = 0;
        q.push(i);
	    
    	while (!q.empty()){
    	    auto x = q.front(); q.pop();
    	    int prev = team[x];
    	    
        	for (auto& nxt : adj[x]){
        		if (team[nxt] != -1) continue;
        	    team[nxt] = 1 - prev;
        		q.push(nxt);
        	}
    	}
	}
	
	for (auto& a : team) cerr << a + 1 << " ";
	
	rep (i, n){
	    for (auto& f : adj[i]){
    		if (team[f] != team[i]) continue;
    	    cout << "IMPOSSIBLE" << el;
    	    return;
    	}
	}
	
	for (auto& a : team) cout << a + 1 << " ";
}
 
int main() {
	FastIO;
	int t = 1;
	while (t--) solve();
	return 0;
}
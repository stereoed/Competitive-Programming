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
 
/*
 
Byteland has n cities and m roads between them. Your task is to design a round trip that begins in a city, goes through two or more other cities, and finally returns to the starting city. Every intermediate city on the route has to be distinct.
 
Input
The first input line has two integers n and m: the number of cities and roads. The cities are numbered 1,2,\dots,n.
Then, there are m lines describing the roads. Each line has two integers a and b: there is a road between those cities.
Every road is between two different cities, and there is at most one road between any two cities.
 
Output
First print an integer k: the number of cities on the route. Then print k cities in the order they will be visited. You can print any valid solution.
If there are no solutions, print "IMPOSSIBLE".
 
*/
int n, m, last = -1;
vvi adj;
vb seen; vi ans, st;
 
bool dfs(int x, int p){
    cerr << "DFS CALLED WITH X - P: " << x << " " << p << el;
    seen[x] = 1;
    
    for (auto& nxt : adj[x]){
        if (nxt == p) continue;
        if (seen[nxt]) {
            ans.pb(nxt);
            
            last = nxt;
            return 1;
        }
        
        ans.pb(nxt);
        if (dfs(nxt, x)) return 1;
        ans.pop_back();
    }
    
    return 0;
}
 
void solve() {
    // Input + Lista de adyacencia
	cin >> n >> m;
    adj = vvi(n);
	seen = vb(n);
 
	rep(i, m){
	    int a, b; cin >> a >> b; a--; b--;
	    adj[a].pb(b);
	    adj[b].pb(a);
	}
	
	// Loop + DFS
	rep(i, n){
	    if (seen[i]) continue;
	    
	    ans.pb(i);
	    if (dfs(i, -1)) break;
	    ans.pop_back();
	}
	
	// Output
	if (!ans.empty()){
        int start = 0;
        for (; ans[start] != last; ++start);
    
        cout << ans.size() - start << el;
        for (; start < ans.size(); ++start) cout << ans[start] + 1 << " ";
        return;
    }
    
    cout << "IMPOSSIBLE" << el;
       
    
	
}
 
int main() {
	FastIO;
	int t = 1;
	while (t--) solve();
	return 0;
}
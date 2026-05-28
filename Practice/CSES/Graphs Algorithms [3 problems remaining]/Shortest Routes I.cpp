#pragma GCC optimize("Ofast")
 
#if __has_include("stdc++.h")
#include "stdc++.h"
#else
#include <bits/stdc++.h>
#endif
 
#ifdef LOCAL
    #if __has_include("cpp-dump.hpp")
    #include "cpp-dump.hpp"
    #define dump(...) cpp_dump(__VA_ARGS__)
    #else
    #define dump(...)
    #endif
#else
    #define dump(...)
#endif
 
using namespace std;
 
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;
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
 
const int MOD = 998244353;
const int INF = 1e9;
 
struct delta{
	int x, y;
	char dir;
};
 
delta D[] = {{0, 1, 'R'}, {0, -1, 'L'}, {1, 0, 'D'}, {-1, 0, 'U'}};
 
ll n, m;
bool flag;
vvi adj;
vvb seen;
vi ans;
 
/*
	PROBLEMA ACTUAL (NO EN CONTEST).
	Shortest Routes I - Dijkstra
*/
 
void solve() {
	cin >> n >> m;
	vector<vii> adj_list(n);
	
	rep(i, m){
		int a, b, d; cin >> a >> b >> d; a--; b--;
		adj_list[a].pb({b, d});
	}
	//dump(adj_list);
	
	priority_queue<pii> q;
	ans = vi(n, 1e18);
	ans[0] = 0;
	
	q.push({0, 0});
	while(!q.empty()){
		//dump(q);
		auto [d, a] = q.top(); q.pop();
		d *= -1;
		
		if (d != ans[a]) continue;
		for (auto& [nxt, dist] : adj_list[a]){
			ll nd = d + dist;
			if (ans[nxt] <= nd) continue;
			
			ans[nxt] = nd;
			q.push({-nd, nxt});
		}
	}
	
	rep(i, n) cout << ans[i] << " ";
}
 
int main() {
	FastIO;
 
#ifdef LOCAL
	auto start = chrono::high_resolution_clock::now();
#endif
 
	int t = 1;
	//cin >> t;
	
	while (t--) {
		solve();
	}
 
#ifdef LOCAL
	auto end = chrono::high_resolution_clock::now();
	chrono::duration<double, milli> elapsed = end - start;
	cerr << "\n[Time] " << fixed << setprecision(6) << elapsed.count() << " ms\n";
#endif
 
	return 0;
}
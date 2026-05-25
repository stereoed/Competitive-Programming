#pragma GCC optimize("Ofast")
 
#if __has_include("stdc++.h")
#include "stdc++.h"
#else
#include <bits/stdc++.h>
#endif
 
#ifdef LOCAL
    #if __has_include("cpp-dump.hpp")
    #include "cpp-dump.hpp"
    #define dump(...) cpp_dump(__VA_ARGS__);
    #else
    #define dump(...)
    #endif
#else
    #define dump(...)
#endif
 
// ORDERED TREE
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace __gnu_pbds;
 
#define ordered_set tree<pair<ll, int>, null_type,less<pair<ll, int>>, rb_tree_tag,tree_order_statistics_node_update>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
typedef tuple<ll, ll, ll> tiii;
 
template<class T> using pq = priority_queue<T>;
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
 
#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define el '\n'
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repx(i, a, n) for (int i = (int)a; i < (int)(n); i++)
#define repb(i, n) for (int i = (int)n - 1; i >= 0; i--)
#define pb push_back
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define ms(arr, val) memset(arr, val, sizeof(arr))
#define imp "IMPOSSIBLE"
 
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
const int INF = 1e9;
const ll INFL = 1e17;
 
ll gcd(ll a,ll b) { if (b==0) return a; return gcd(b, a%b); }
ll lcm(ll a,ll b) { return a/gcd(a,b)*b; }
ll floor(ll a, ll b) { return a / b - (a % b < 0); }
ll ceil(ll a, ll b) { return a / b + (a % b > 0); }
 
template<typename T>
istream& operator>>(istream& in, vector<T> &vec){
    for(auto &x : vec){
        in >> x;
    }
    return in;
}
 
struct delta{
	int x, y;
	char dir;
};
 
struct edge{
	int a, b;
	ll w;
};
 
delta D[] = {{0, 1, 'R'}, {0, -1, 'L'}, {1, 0, 'D'}, {-1, 0, 'U'}};
 
/*
* Investigation
*
* what is the minimum price of such a route?
* how many minimum-price routes are there? (modulo 10^9+7)
* what is the minimum number of flights in a minimum-price route?
* what is the maximum number of flights in a minimum-price route?
*/
 
int n, m, a, b;
ll c;
vvii adj;
 
void solve() {
	cin >> n >> m;
	adj = vvii(n);
	
	rep(i, m){
		cin >> a >> b >> c; a--; b--;
		adj[a].pb({b, c});
	}
 
	vi dist(n, INFL);
	vi ways(n, 0);
	vi mn(n, INFL);
	vi mx(n, -INFL);
 
	pqg<pii> pq;
 
	dist[0] = 0;
	ways[0] = 1;
	mn[0] = 0;
	mx[0] = 0;
 
	pq.push({0, 0});
 
	while (!pq.empty()){
		auto [d, u] = pq.top();
		pq.pop();
 
		if (d != dist[u]) continue;
 
		for (auto [v, w] : adj[u]){
			ll nd = d + w;
 
			if (nd < dist[v]){
				dist[v] = nd;
				ways[v] = ways[u];
				mn[v] = mn[u] + 1;
				mx[v] = mx[u] + 1;
 
				pq.push({nd, v});
			}
			else if (nd == dist[v]){
				ways[v] = (ways[v] + ways[u]) % MOD;
				mn[v] = min(mn[v], mn[u] + 1);
				mx[v] = max(mx[v], mx[u] + 1);
			}
		}
	}
 
	cout << dist[n - 1] << " "
	     << ways[n - 1] << " "
	     << mn[n - 1] << " "
	     << mx[n - 1] << el;
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
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
 
const int MOD = 998244353;
const double EPS = 1e-9;
const int INF = 1e9;
const ll INFL = 4e18;
 
ll gcd(ll a,ll b) { if (b==0) return a; return gcd(b, a%b); }
ll lcm(ll a,ll b) { return a/gcd(a,b)*b; }
ll floor(ll a, ll b) { return a / b - (a % b < 0); }
ll ceil(ll a, ll b) { return a / b + (a % b > 0); }
 
template<typename T>
istream& operator>>(istream& in, vector<T> &vec){
    for(auto &x : vec){
        in>>x;
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
	Hidh Score - Bellman Ford algorithm, although now we are searching for a positive cicle.
	
	Your task is to find a minimum-price flight route from 1 to n. You have one discount coupon, using which you can halve the price of any single flight during the route. However, you can only use the coupon once.
	
	When you use the discount coupon for a flight whose price is x, its price becomes floor x/2
	
	
	n -> 1e5. Meaning either n or n + n log m.
	So dijkstra?
	
	Can it be done greedy? to halve the thing after the best path has been found
	NO!
	
	take:
	1 2 10
	2 7 2 (so 12 total)
	
	1 3 2
	3 4 2
	4 5 2
	5 6 2
	6 7 2 (so 10 total)
	
	if we take the shortest path before applying the half, we end up with the second, half 1 3, get 9 total. However, half 1 2 and we can reach 7 in just 7 score!.
	
	Is it the bigger then?
	of course no duffus.
	
	So what then?
	dp then?
	
*/
 
ll n, m, query;
vvii adj;
vvi ans;
 
void solve() {
	cin >> n >> m;
	adj = vvii(n);
	rep(i, m){
		int a, b, c;
		cin >> a >> b >> c; a--; b--;
		adj[a].pb({b, c});
	}
	
	dump(adj);
	
	pqg<tiii> q;
	ans = vvi(n, vi(2, 1e18));
	ans[0][0] = 0;
	
	q.push({0, 0, 0});
	while(!q.empty()){
		auto [d, a, used] = q.top(); q.pop();
		dump(d, a, used);
		if (d != ans[a][used]) continue;
		
		for (auto& [nxt, dist] : adj[a]){
			ll nd = d + dist, nd_used = d + dist/2;
			if (!used){
				if (ans[nxt][0] > nd){
					ans[nxt][0] = nd;
					q.push({nd, nxt, 0});
				}
 
				if (ans[nxt][1] > nd_used){
					ans[nxt][1] = nd_used;
					q.push({nd_used, nxt, 1});
				}
			} else if (ans[nxt][1] > nd){
				ans[nxt][1] = nd;
				q.push({nd, nxt, 1});
			}
		}
	}
	
	dump(ans);
	cout << ans[n-1][1] << " ";	
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
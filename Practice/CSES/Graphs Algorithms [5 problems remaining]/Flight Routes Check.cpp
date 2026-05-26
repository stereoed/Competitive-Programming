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
#define cyes cout << "YES" << el
#define cno cout << "NO" << el
 
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
* Flight Routes Check
*/
 
int n, m;
 
void dfs(int u, vvi& g, vb& vis){
    vis[u] = true;
    for (int v : g[u])
        if (!vis[v]) dfs(v, g, vis);
}
 
void solve(){
    cin >> n >> m;
    vvi adj(n), radj(n);
        
    rep(i, m){
        int a, b;
        cin >> a >> b;
        a--; b--;
        
        adj[a].pb(b);
        radj[b].pb(a);
    }
    
    vb seen(n);
    dfs(0, adj, seen);
    
    rep(i, n){
        if (seen[i] == 0){
            cno;
            cout << 1 << " " << i+1 << el;
            return;
        }
    }
    
    seen = vb(n);
    dfs(0, radj, seen);
    
    rep(i, n){
        if (seen[i] == 0){
            cno;
            cout <<  i+1 << " " << 1 << el;
            return;
        }
    }
    
    cyes;
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
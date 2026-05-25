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
* Planets and Kingdoms
* Kojaru
*/
 
int n, m;
int top1 = 0, top2 = 0;
const int MAXN = 1e5 + 5;
int st[MAXN], st2[MAXN];
 
void dfs(int u, vvi& g, vb& vis){
    vis[u] = true;
 
    for (int v : g[u])
        if (!vis[v]) dfs(v, g, vis);
 
    st[top1++] = u;
}
 
void solve(){
    cin >> n >> m;
    vvi adj(n), radj(n);
    int ans = 0;
    vi kingdom(n, -1);
        
    rep(i, m){
        int a, b;
        cin >> a >> b;
        a--; b--;
        
        adj[a].pb(b);
        radj[b].pb(a);
    }
    
    vb seen(n);
    rep(i, n){
        if (!seen[i]) dfs(i, adj, seen);
    }
    
    while (top1 > 0){
        int idx = st[--top1];
        if (kingdom[idx] != -1) continue;
        
        top2 = 0;
        int king = ++ans;
        kingdom[idx] = king;
        
        st2[top2++] = idx;
        while (top2 > 0){
            int u = st2[--top2];
            
            for (int v : radj[u]){
                if (kingdom[v] != -1) continue;
                kingdom[v] = king;
                st2[top2++] = v;
            }
        }
    }
    
    cout << ans << el;
    rep(i, n){
        cout << kingdom[i] << " ";
    }
    
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
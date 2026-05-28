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
 
const int MOD = 998244353;
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
 
int n, m, last = -1;
vvi adj;
vb seen, seen2; vi ans, st;
 
bool dfs(int x){
    seen[x] = 1;
	seen2[x] = 1;
	//dump(x, seen2);
    
    for (auto& nxt : adj[x]){
        if (seen2[nxt]) {
			//dump(nxt);
            ans.pb(nxt);
            
            last = nxt;
            return 1;
        }
		
		
		if (seen[nxt]) continue; // important
        
        ans.pb(nxt);
        if (dfs(nxt)) return 1;
        ans.pop_back();
    }
    
	seen2[x] = 0;
    return 0;
}
 
void solve() {
    // Input + Lista de adyacencia
	cin >> n >> m;
    adj = vvi(n);
	seen = vb(n);
	seen2 = vb(n);
 
	rep(i, m){
	    int a, b; cin >> a >> b; a--; b--;
	    adj[a].pb(b);
	}
	
	// Loop + DFS
	rep(i, n){
	    if (seen[i]) continue;
	    
	    ans.pb(i);
	    if (dfs(i) && !ans.empty()){
			//dump(ans, last);
			int start = 0;
			for (; ans[start] != last; ++start);
		
			if (ans.size() - start > 1){
				cout << ans.size() - start << el;
				for (; start < ans.size(); ++start) cout << ans[start] + 1 << " ";
				return;
			}
		}
	    ans.pop_back();
	}
	
	// Output
    cout << "IMPOSSIBLE" << el;
    
	
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
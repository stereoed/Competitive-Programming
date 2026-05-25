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
* Road reparation
*
* Idea 1: Dijstra, tomando guardando las edges mas baratas
* Idea 2: Agarrar la mas barata, luego conectar las mas barata entre una que esta conectada y otra que no
*
*/
 
int n, m;
 
void solve() {
    cin >> n >> m;
    vvii E(n);
    vb D(n);
    
    ll ans = 0;
    bool done = 1;
    
    edge first = {0, 0, INFL};
    rep(i, m){
        int a, b, c; cin >> a >> b >> c; a--; b--;
        E[a].pb({c, b});
        E[b].pb({c, a});
        
        if (c < first.w) first = {a, b, c};
    }
    
    D[first.a] = 1;
    D[first.b] = 1;
    ans += first.w;
    
    pqg<pii> q;
    for (auto& p : E[first.a]) q.push(p);
    for (auto& p : E[first.b]) q.push(p);
    
    while (!q.empty()){
        auto [c, id] = q.top(); q.pop();
        if (D[id]) continue;
        
        ans += c;
        D[id] = 1;
        
        for (auto& p : E[id]) if (!D[p.second]) q.push(p);
    }
    
    rep(i, n) done &= D[i];
    if (done) cout << ans << el;
    else cout << imp << el;
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
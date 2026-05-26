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
* Planets Cycles
*/
 
const int MAXN = 200000 + 5;
const int LOG = 31;
 
int adj[MAXN][LOG];
 
int distance_to_cycle[MAXN];
int component[MAXN];
 
vector<int> cycle_size;
 
int n, q;
 
int binary_lifting(int s, int k) {
	dump("bl", s, k)
    int x = 0;
 
    while (k) {
        if (k & 1) s = adj[s][x];
        x++;
        k >>= 1;
    }
	
	dump("got", s)
    return s;
}
 
void calc_distance(int start) {
    if (distance_to_cycle[start] != INF) return;
 
    vector<int> path;
    int u = start;
 
    while (distance_to_cycle[u] == INF) {
        path.pb(u);
        u = adj[u][0];
    }
 
    reverse(all(path));
 
    for (int x : path) {
        int nxt = adj[x][0];
 
        distance_to_cycle[x] = distance_to_cycle[nxt] + 1;
        component[x] = component[nxt];
    }
}
 
int ans(int a) {
    int da = distance_to_cycle[a];
    return da + cycle_size[component[a]];
}
 
void solve() {
    cin >> n;
 
    cycle_size.clear();
 
    rep(i, n) {
        distance_to_cycle[i] = INF;
        component[i] = -1;
    }
 
    rep(i, n) {
        cin >> adj[i][0];
        adj[i][0]--;
    }
 
    repx(j, 1, LOG) {
        rep(i, n) {
            adj[i][j] = adj[adj[i][j - 1]][j - 1];
        }
    }
	
    dump("Find and mark every cycle.")
    rep(i, n) {
        int ptr = binary_lifting(i, n); // guaranteed inside cycle
 
        if (component[ptr] != -1) continue;
 
        int comp = cycle_size.size();
        int cur = ptr;
        int idx = 0;
 
        do {
			dump(cur, ptr)
            component[cur] = comp;
            distance_to_cycle[cur] = 0;
            idx++;
 
            cur = adj[cur][0];
        } while (cur != ptr);
 
        cycle_size.pb(idx);
    }
 
    dump("Fill trees")
    rep(i, n) {
        calc_distance(i);
    }
	
	dump(distance_to_cycle, component);
 
    rep(i, n) {
        cout << ans(i) << " ";
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